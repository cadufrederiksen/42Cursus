FROM debian:buster

RUN apt update -y && apt upgrade -y \
    && apt install nginx vim openssl curl -y 

RUN mkdir -p /etc/nginx/ssl


RUN openssl req -x509 -nodes -out /etc/nginx/ssl/nginx.crt \
-keyout /etc/nginx/ssl/nginx.key \
-subj "/C=MA/L=MA/O=42/OU=student/CN=carmarqu"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

CMD [ "nginx", "-g", "daemon off;" ]
