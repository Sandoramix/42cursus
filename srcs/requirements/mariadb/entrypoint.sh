#!/bin/sh

# EXIT ON ERROR
set -e


init_db() {
	echo "Initializing MariaDB database..."
	mysql_install_db --user=mysql --datadir=/var/lib/mysql
	echo "Database initialized."

	mysqld --user=mysql --datadir=/var/lib/mysql --pid-file=/var/run/mysqld/mysqld.pid --skip-networking &
	pid="$!"

	sleep 5

	mysql -u root <<-EOSQL
		-- Disable binary logging for initialization
		SET @@SESSION.SQL_LOG_BIN=0;

		-- Set root password for localhost
		CREATE USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
		GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;

		-- Ensure root can access from any host
		CREATE USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
		GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

		-- General cleanup
		FLUSH PRIVILEGES;
		DELETE FROM mysql.user WHERE User='';
		DROP DATABASE IF EXISTS test;

		-- Create application database and user
		CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
		CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
		FLUSH PRIVILEGES;
	EOSQL

	kill "$pid"

	wait "$pid"
}

if [ ! -d /var/lib/mysql/mysql ]; then
	init_db
fi

exec "$@"