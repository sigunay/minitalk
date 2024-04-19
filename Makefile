CLIENT = client
SERVER = server
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRC = client.c server.c utils.c
OBJ = $(SRC:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): client.o utils.o
	$(CC) $(CFLAGS) -o $(CLIENT) client.o utils.o

$(SERVER): server.o utils.o
	$(CC) $(CFLAGS) -o $(SERVER) server.o utils.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

c: clean
clean:
	$(RM) $(OBJ)

f: fclean
fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re f c