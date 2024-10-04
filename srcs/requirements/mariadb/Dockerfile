FROM alpine:3.17

ARG MYSQL_ROOT_PASSWORD=toor
ARG MYSQL_USER=user
ARG MYSQL_PASSWORD=password
ARG MYSQL_DATABASE=default_database

RUN apk add --no-cache mariadb mariadb-client
COPY ./conf/my.cnf /etc/mysql/my.cnf

RUN mkdir -p /var/lib/mysql /var/run/mysqld \
	&& chown -R mysql:mysql /var/lib/mysql /var/run/mysqld

COPY ./tools/populate_db.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/populate_db.sh

RUN /usr/local/bin/populate_db.sh

CMD ["mysqld"]