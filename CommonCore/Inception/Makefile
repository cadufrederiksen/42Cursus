# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 10:40:03 by carmarqu          #+#    #+#              #
#    Updated: 2025/04/28 11:51:18 by carmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=inception
DOCKER_COMPOSE=docker-compose -f ./srcs/docker-compose.yml
DOCKER=docker

all: up

up:
	$(DOCKER_COMPOSE) up -d --build

down:
	$(DOCKER_COMPOSE) down
	
fclean: down
	-$(DOCKER) volume rm $(shell $(DOCKER) volume ls -q)
	-$(DOCKER) network rm src_incpetion || true

re: fclean up 	

		