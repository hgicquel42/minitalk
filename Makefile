COMMON = \
	client.c \
	server.c \
	utils.c \

BONUS = \

OCOMMON = ${COMMON:.c=.o}

OBONUS = ${BONUS:.c=.o}

all: server client

bonus: server client

.c.o:
	gcc -Wall -Wextra -Werror -I . -c $< -o ${<:.c=.o}

server: server.o utils.o
	$(CC) -o $@ $^

client: client.o utils.o
	$(CC) -o $@ $^

clean:
	rm -f ${OCOMMON} ${OBONUS}

fclean:	clean
	rm -f server client

re:		fclean all