#!/bin/sh

service mysql start
mysql -e "CREATE DATABASE IF NOT EXISTS '$SQL_DATABASE';" 
mysql -e "CREATE USER IF NOT EXSITS '$SQL_USER@'localhost' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGIES ON '$SQL_DATABASE'.* TO '$SQL_USER'@''%';"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD';"
mysql -e "FLUSH PRIVILEGIES"
