#!/bin/sh

# EXIT ON ERROR
set -e

echo "Initializing MariaDB database..."
mysql_install_db --user=mysql --datadir=/var/lib/mysql
echo "Database initialized."

mysqld --user=mysql --datadir=/var/lib/mysql --pid-file=/var/run/mysqld/mysqld.pid --skip-networking &
pid="$!"

sleep 5

echo "Populating database..."

#echo "RootPassword: ${MYSQL_ROOT_PASSWORD}"
#echo "User: ${MYSQL_USER}"
#echo "Password: ${MYSQL_PASSWORD}"
#echo "Database: ${MYSQL_DATABASE}"

mysql -u root <<-EOSQL
	-- Disable binary logging for initialization
	SET @@SESSION.SQL_LOG_BIN=0;

	-- Create users and set root password for localhost + %
	CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
	ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
	CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
	ALTER USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

	-- Grant privileges
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost';
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'%';

	-- General cleanup
	FLUSH PRIVILEGES;
	DELETE FROM mysql.user WHERE User='';
	DROP DATABASE IF EXISTS test;

	-- Create application database and user
	CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
	CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
	GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
	FLUSH PRIVILEGES;
EOSQL

echo "Database populated."

kill "$pid"

wait "$pid"

