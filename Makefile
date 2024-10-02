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

all: up

setup:
	mkdir -p $(VOLUME_PATHS)

up:
	@$(MAKE) setup
	docker-compose -f ${COMPOSE_FILE} up -d

down:
	docker-compose -f ${COMPOSE_FILE} down
down-clean:
	@echo "Removing all containers, volumes, images, and networks..."
	docker-compose -f ${COMPOSE_FILE} down --volumes --remove-orphans --rmi all

up-build:
	docker-compose -f ${COMPOSE_FILE} up -d --build

clean: down-clean

fclean:
	@echo "Removing volume folders..."
	@rm -rf ${VOLUME_PATHS} || echo "Encountered issues removing directories. Please check permissions."

ps:
	docker-compose -f ${COMPOSE_FILE} ps

re: clean setup up-build

.PHONY: all setup up down clean re up-build
.SILENT: ps clean setup