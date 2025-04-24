#!/bin/sh

WP_PATH=/var/www/html
cd "$WP_PATH"

if ! wp core is-installed 2>/dev/null; then
	wp core download --allow-root --force

	if [ ! -e "$WP_PATH/wp-config.php" ]; then
		wp config create --allow-root --dbname="${WORDPRESS_DB_NAME}" --dbuser="${WORDPRESS_DB_USER}" --dbpass="${WORDPRESS_DB_PASSWORD}" --dbhost="${WORDPRESS_DB_HOST}"
	fi

	if ! wp db check; then
		wp db create --allow-root
	fi

	WORDPRESS_SITE_URL=${WORDPRESS_SITE_PROTOCOL}${WORDPRESS_SITE_DOMAIN}$([ "${WORDPRESS_SITE_PORT}" != "443" ] && echo ":${WORDPRESS_SITE_PORT}")

	wp core install --allow-root --url="${WORDPRESS_SITE_URL}" --title="${WORDPRESS_SITE_TITLE}" --admin_user="${WORDPRESS_ADMIN_USER}" --admin_password="${WORDPRESS_ADMIN_PASSWORD}" --admin_email="${WORDPRESS_ADMIN_EMAIL}"

	wp user create --allow-root "${WORDPRESS_SECONDARY_USER}" "${WORDPRESS_SECONDARY_USER_EMAIL}" --user_pass="${WORDPRESS_SECONDARY_USER_PASSWORD}" --role=author
else
	echo "WordPress is already installed."
fi

"$@"
