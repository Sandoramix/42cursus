FROM alpine:3.17

ARG MYSQL_ROOT_PASSWORD=toor
ARG MYSQL_USER=user
ARG MYSQL_PASSWORD=password
ARG MYSQL_DATABASE=default_database
ARG WORDPRESS_DB_NAME=wp
ARG WORDPRESS_DB_USER=wpusr
ARG WORDPRESS_DB_PASSWORD=wppass

RUN apk add --no-cache mariadb mariadb-client
COPY --chmod=0644 ./conf/my.cnf /etc/mysql/my.cnf

RUN mkdir -p /var/lib/mysql /var/run/mysqld \
	&& chown -R mysql:mysql /var/lib/mysql /var/run/mysqld \
	&& chmod -R 755 /var/lib/mysql /var/run/mysqld

COPY ./tools/populate_db.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/populate_db.sh

RUN /usr/local/bin/populate_db.sh

CMD ["mysqld"]