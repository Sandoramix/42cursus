FROM alpine:3.17

RUN apk add --no-cache mariadb mariadb-client
COPY ./my.cnf /etc/mysql/my.cnf

RUN mkdir -p /var/lib/mysql /var/run/mysqld \
	&& chown -R mysql:mysql /var/lib/mysql /var/run/mysqld

COPY ./entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["entrypoint.sh"]
CMD ["mysqld"]