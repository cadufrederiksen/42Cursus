FROM debia:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt-get install mariadb-server -y

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN service mysql start;
RUN mysql -e "CREATE DATABASE IF NOT EXISTS \${SQL_DATABASE}]';'"
RUN mysql -e "CREATE USER IF NOT EXISTS \${SQL_USER}"