#!/bin/sh

WP_PATH=/var/www/html

if ! wp core is-installed 2>/dev/null --path=${WP_PATH}; then
	wp core download --path="$WP_PATH"

	if [ ! -e "$WP_PATH/wp-config.php" ]; then
		wp config create --dbname="${WORDPRESS_DB_NAME}" --dbuser="${WORDPRESS_DB_USER}" --dbpass="${WORDPRESS_DB_PASSWORD}" --dbhost="${WORDPRESS_DB_HOST}" --path="$WP_PATH"
	fi

	if ! wp db check --path="$WP_PATH"; then
		wp db create --path="$WP_PATH"
	fi

	export WORDPRESS_SITE_URL=${WORDPRESS_PROTOCOL}${WORDPRESS_DOMAIN_NAME}$([ "${WORDPRESS_SERVER_PORT}" != "443" ] && echo ":${WORDPRESS_SERVER_PORT}")

	wp core install --url="${WORDPRESS_SITE_URL}" --title="${WORDPRESS_SITE_TITLE}" --admin_user="${WORDPRESS_ADMIN_USER}" --admin_password="${WORDPRESS_ADMIN_PASSWORD}" --admin_email="${WORDPRESS_ADMIN_EMAIL}" --path="$WP_PATH"

	wp user create "${WORDPRESS_SECONDARY_USER}" "${WORDPRESS_SECONDARY_USER_EMAIL}" --user_pass="${WORDPRESS_SECONDARY_USER_PASSWORD}" --role=author --path="$WP_PATH"
else
	echo "WordPress is already installed."
fi

"$@"
