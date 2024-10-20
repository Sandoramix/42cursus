FROM alpine:3.17

ARG DOMAIN=login.42.fr
ARG PORT=443

RUN apk add --no-cache nginx openssl openssl-dev
RUN mkdir -p /var/www/html
RUN chown -R nobody:nogroup /var/www/html

RUN mkdir -p /etc/ssl/certs

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/certs/${DOMAIN}.key \
	-out /etc/ssl/certs/${DOMAIN}.crt \
	-subj "/C=FR/ST=/L=/O=/OU=42/CN=${DOMAIN}"

COPY --chown=root:root --chmod=0744 ./conf/nginx.conf /etc/nginx/http.d/default.conf

RUN sed -i "s/\${DOMAIN}/${DOMAIN}/g" /etc/nginx/http.d/default.conf && \
	sed -i "s/\${PORT}/${PORT}/g" /etc/nginx/http.d/default.conf

WORKDIR /var/www/html

CMD ["nginx", "-g", "daemon off;"]