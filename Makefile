NAME	= push_swap
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m
RM		= rm -f

FUNC	= srcs/push srcs/rotate srcs/push_swap srcs/reverse_rotate\
		  srcs/swap srcs/utils srcs/utils2 srcs/sortage\
		  libft/ft_strncmp libft/ft_strlen libft/ft_split libft/ft_strlcpy\

SRC		= $(addsuffix .c, $(FUNC))
OBJ		= $(addsuffix .o, $(FUNC))

.c.o	: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $^

$(NAME)	: 	$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "$(GREEN).o were created$(RESET)"
	@echo "$(GREEN)$(NAME) was created$(RESET)"

all		:	$(NAME)

clean	:
	@$(RM) srcs/*.o
	@$(RM) libft/*.o
	@echo "$(RED)clean done$(RESET)"

fclean	: clean
	@$(RM) $(NAME)
	@echo "$(RED)fclean done$(RESET)"

re		: fclean all

.PHONY	: all clean fclean re

