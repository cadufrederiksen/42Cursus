FROM debian:buster

ARG PHP_VERSION = 7.3
ARG WP_VERSION = 6.0
ENV WP_HOME = /var/www/wordpress
ENV WP_SITEURL = https://${DOMAIN_NAME}
ENV WP_USER = carmarqu
ENV WP_PASSWORD = password
ENV WP_EMAIL = carmarqu@gmail.com

RUN apt-get update && apt-get upgrade -y
RUN apt-get -y install wget php${PHP_VERSION}-fpm php${PHP_VERSION}-mysql mariadb-client
RUN wget https://fr.wordpress.org/wordpress-${WP_VERSION}-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-&{WP_VERSION}-fr_FR.tar.gz && rm wordpress-&{WP_VERSION}-fr_FR

RUN mkdir -p /etc/php/${PHP_VERSION}/fpm/pool.d
COPY requirements/wordpress/config/php-fpm/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
RUN chown -R www-data:www-data /var/www/wordpress

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

COPY requirements/wordpress/tools/entrypoint.sh /usr/local/bin/docker-entrypoint.sh
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/docker-entrypoint.sh+"]

CMD ["php-fpm${PHP_VERSION}", "-F"]