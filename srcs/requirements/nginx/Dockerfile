FROM alpine:3.17

ARG LOGIN=login

ENV LOGIN=${LOGIN}

RUN apk add --no-cache nginx openssl openssl-dev
RUN mkdir -p /var/www/html
RUN chown -R nobody:nogroup /var/www/html

RUN mkdir -p /etc/ssl/certs

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/certs/${LOGIN}.42.fr.key -out /etc/ssl/certs/${LOGIN}.42.fr.crt -subj "/C=FR/ST=/L=/O=${LOGIN}/OU=42/CN=${LOGIN}.42.fr"

COPY --chown=root:root --chmod=0744 ./conf/nginx.conf /etc/nginx/http.d/inception.conf
RUN sed -i "s/\${LOGIN}/${LOGIN}/g" /etc/nginx/http.d/inception.conf

WORKDIR /var/www/html

CMD ["nginx", "-g", "daemon off;"]