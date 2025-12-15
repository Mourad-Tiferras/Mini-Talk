CC = cc
CFLAG = -Wall -Wextra -Werror
SERVER = helper_func.c server.c
CLIENT = helper_func.c client.c
EXEC_SERVER = server
EXEC_CLIENT = client
PRINTF_ARCHIVE = ft_printf/libftprintf.a

all: $(EXEC_CLIENT) $(EXEC_SERVER)

$(EXEC_CLIENT): $(CLEXEC_CLIENT) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAG) $(CLIENT) $(PRINTF_ARCHIVE) -o $(EXEC_CLIENT)

$(EXEC_SERVER): $(SERVER) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAG) $(SERVER) $(PRINTF_ARCHIVE) -o $(EXEC_SERVER)

$(PRINTF_ARCHIVE):
	make -C ft_printf

clean:
	make -C ft_printf clean

fclean:
	make -C ft_printf fclean
	rm $(EXEC_CLIENT) $(EXEC_SERVER)