ENV_FILE = srcs/.env
COMPOSE_FILE = srcs/docker-compose.yml

ifneq (,$(wildcard ${ENV_FILE}))
include ${ENV_FILE}
else
$(error ${ENV_FILE} does not exist)
endif

export $(shell sed 's/=.*//' ${ENV_FILE})

ifeq ($(wildcard ${COMPOSE_FILE}),)
$(error ${COMPOSE_FILE} does not exist)
endif


VOLUME_PATHS = ${MARIADB_VOLUME_PATH} ${WORDPRESS_VOLUME_PATH}

DOCKER_COMPOSE = docker-compose -f ${COMPOSE_FILE}

all: up

setup:
	mkdir -p $(VOLUME_PATHS)

up: setup
	${DOCKER_COMPOSE} up -d

up-interactive: setup
	${DOCKER_COMPOSE} up --build

down:
	${DOCKER_COMPOSE} down
down-clean:
	@echo "Removing all containers, volumes, images, and networks..."
	${DOCKER_COMPOSE} down --volumes --remove-orphans --rmi all

build: setup
	${DOCKER_COMPOSE} build --no-cache


clean: down-clean

fclean: down-clean
#	~/sasharm
#${DOCKER_COMPOSE} exec wordpress rm -rf /var/www/html
#@rm -rf ${VOLUME_PATHS} || echo "Encountered issues removing directories. Please check permissions."

ps:
	${DOCKER_COMPOSE} ps

re: fclean setup build up

.PHONY: all setup up down clean re up-build
.SILENT: ps clean setup