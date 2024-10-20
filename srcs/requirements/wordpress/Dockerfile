FROM alpine:3.17

ENV WORDPRESS_DB_HOST=mariadb
ENV WORDPRESS_DB_NAME=wp
ENV WORDPRESS_DB_USER=wpusr
ENV WORDPRESS_DB_PASSWORD=wppass

ENV WORDPRESS_SITE_TITLE=WordPress
ENV WORDPRESS_SITE_PROTOCOL=https://
ENV WORDPRESS_SITE_DOMAIN=login.42.fr
ENV WORDPRESS_SITE_PORT=443

ENV WORDPRESS_ADMIN_USER=superuser
ENV WORDPRESS_ADMIN_PASSWORD=superpass
ENV WORDPRESS_ADMIN_EMAIL=superuser@example.com

ENV WORDPRESS_SECONDARY_USER=member
ENV WORDPRESS_SECONDARY_USER_EMAIL=member@example.com
ENV WORDPRESS_SECONDARY_USER_PASSWORD=memberpass

ARG PHP_MAJOR_VERSION=8
ARG PHP_MINOR_VERSION=1
ENV PHP_VER=${PHP_MAJOR_VERSION}${PHP_MINOR_VERSION}

RUN apk add --no-cache curl \
	mariadb-client \
    php${PHP_VER} \
    php${PHP_VER}-fpm \
    php${PHP_VER}-phar \
    php${PHP_VER}-mysqli \
    php${PHP_VER}-mbstring \
    php${PHP_VER}-iconv \
    php${PHP_VER}-session

RUN sed -i 's/^listen = .*/listen = 9000/' /etc/php${PHP_VER}/php-fpm.d/www.conf

RUN mkdir -p /var/www/html
RUN chown -R nobody:nogroup /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

COPY --chown=root:root --chmod=0700 ./tools/entrypoint.sh /usr/local/bin/

WORKDIR /var/www/html

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
CMD ["sh", "-c", "exec php-fpm${PHP_VER} -F"]
