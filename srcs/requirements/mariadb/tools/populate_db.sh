#!/bin/sh

# EXIT ON ERROR
set -e

FIRST_TIME=1

echo "Trying to initialize MariaDB database..."
if [ ! -d /var/lib/mysql/mysql ]; then
	echo "MariaDB database not found. Initializing..."
	mysql_install_db --user=mysql --datadir=/var/lib/mysql
	echo "MariaDB database initialized."
else
	echo "MariaDB database upgraded."
	FIRST_TIME=0
fi

mysqld --user=mysql --datadir=/var/lib/mysql --pid-file=/var/run/mysqld/mysqld.pid --skip-networking &
pid="$!"

echo "Waiting for server to start..."
until mysqladmin ping --silent; do
	sleep 1
done

echo "Updating MariaDB database..."

DB_PASS="-p${MYSQL_ROOT_PASSWORD}"

if [ "${FIRST_TIME}" = "1" ]; then
	DB_PASS=""
fi

mysql -u root "${DB_PASS}" <<EOSQL
	-- Disable binary logging for initialization
	SET @@SESSION.SQL_LOG_BIN=0;

	-- Create users and set root password for localhost + %
	CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
	ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
	CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
	ALTER USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

	-- Grant privileges
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
	FLUSH PRIVILEGES;

	-- General cleanup
	DELETE FROM mysql.user WHERE User='';
	DROP DATABASE IF EXISTS test;

	-- Create application databases
	CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
	CREATE DATABASE IF NOT EXISTS \`${WORDPRESS_DB_NAME}\`;

	-- Create application users
	CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
	GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
	FLUSH PRIVILEGES;

	CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';
	GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'localhost';
	FLUSH PRIVILEGES;

	CREATE USER IF NOT EXISTS '${WORDPRESS_DB_USER}'@'%' IDENTIFIED BY '${WORDPRESS_DB_PASSWORD}';
	GRANT ALL PRIVILEGES ON \`${WORDPRESS_DB_NAME}\`.* TO '${WORDPRESS_DB_USER}'@'%';
	FLUSH PRIVILEGES;
EOSQL

echo "MariaDB database updated."

kill "$pid"

wait "$pid"

"$@"
