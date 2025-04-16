FROM debian:buster

RUN apt update -y && apt upgrade -y && \ 
	apt-get install mariadb-server -y

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/init.sql /docker-entrypoint-initdb.d/

RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld

EXPOSE 3306

CMD ["mysqld"]