FROM alpine:3.17

ARG MYSQL_ROOT_PASSWORD=toor
ARG MYSQL_USER=user
ARG MYSQL_PASSWORD=password
ARG MYSQL_DATABASE=default_database
ARG WORDPRESS_DB_NAME=wp
ARG WORDPRESS_DB_USER=wpusr
ARG WORDPRESS_DB_PASSWORD=wppass

ENV MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
ENV MYSQL_USER=${MYSQL_USER}
ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}
ENV MYSQL_DATABASE=${MYSQL_DATABASE}
ENV WORDPRESS_DB_NAME=${WORDPRESS_DB_NAME}
ENV WORDPRESS_DB_USER=${WORDPRESS_DB_USER}
ENV WORDPRESS_DB_PASSWORD=${WORDPRESS_DB_PASSWORD}

RUN apk add --no-cache mariadb mariadb-client
COPY --chmod=0644 ./conf/my.cnf /etc/mysql/my.cnf

RUN mkdir -p /var/lib/mysql /var/run/mysqld \
	&& chown -R mysql:mysql /var/lib/mysql /var/run/mysqld \
	&& chmod -R 755 /var/lib/mysql /var/run/mysqld

COPY --chmod=0762 ./tools/populate_db.sh /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
CMD ["mysqld"]