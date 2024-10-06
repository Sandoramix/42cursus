SHELL := /bin/bash

ENV_FILE := srcs/.env
COMPOSE_FILE := srcs/docker-compose.yml

ifneq (,$(wildcard ${ENV_FILE}))
include ${ENV_FILE}
else
$(error ${ENV_FILE} does not exist)
endif

export $(shell sed 's/=.*//' ${ENV_FILE})

ifeq ($(wildcard ${COMPOSE_FILE}),)
$(error ${COMPOSE_FILE} does not exist)
endif

VOLUME_PATHS := ${MARIADB_VOLUME_PATH} ${WORDPRESS_VOLUME_PATH}

DOCKER_COMPOSE := docker-compose -f ${COMPOSE_FILE}

all: up

setup:
	mkdir -p $(VOLUME_PATHS)
build: setup
	${DOCKER_COMPOSE} build --no-cache

up: setup
	${DOCKER_COMPOSE} up -d
down:
	${DOCKER_COMPOSE} down
stop:
	${DOCKER_COMPOSE} stop

up-interactive: setup
	${DOCKER_COMPOSE} up

down-clean:
	@echo "Removing all containers, volumes, images, and networks..."
	${DOCKER_COMPOSE} down --volumes --remove-orphans --rmi all

ps:
	${DOCKER_COMPOSE} ps
logs:
	${DOCKER_COMPOSE} logs

clean: down-clean

fclean: down-clean
	@sudo rm -rf ${VOLUME_PATHS} || echo "An error occurred while deleting the volumes. You might not have enough permissions"
#	~/sasharm
#${DOCKER_COMPOSE} exec wordpress rm -rf /var/www/html
#@rm -rf ${VOLUME_PATHS} || echo "Encountered issues removing directories. Please check permissions."

re: clean setup build up
re-interactive: clean setup build up-interactive

re-force: fclean setup build up
re-force-interactive: fclean setup build up-interactive

.PHONY: all setup build up down up-interactive down-clean ps clean fclean re re-interactive re-force re-force-interactive
.SILENT: clean setup