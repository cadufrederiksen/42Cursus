#!/bin/bash

service mysql start

if [ ! -d "var/lib/mysql/$SQL_DATABASE" ]; then
	echo "Initializing database..."

	mysql -e "CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;"
	mysql -e "CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';"
	mysql -e "GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_USER'@'%';"

	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD';"
	mysql -e "FLUSH PRIVILEGES"

	echo "Database initialized successfully" 
else
	echo "Database already initialized"
fi

service mysql stop

exec mysqld