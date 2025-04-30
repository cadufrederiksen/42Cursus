FROM debian:buster

RUN apt update -y && apt upgrade -y \
    && apt install nginx vim openssl curl -y 

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout inception.key -out inception.crt \
    -subj "/C=ES/ST=Malaga/L=Malaga/O=42/CN=carmarqu.42.fr"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

#RUN chmod 755 /var/www/wordpress
#RUN chown -R www-data:www-data /var/www/wordpress

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;"]
