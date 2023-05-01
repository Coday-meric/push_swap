INCMYLIB=./lib/
INCCORE=./core/
INCCHECK=./checker_core/

NAME = push_swap
NAME_P = checker

SRC = main.c $(INCCORE)treat_input.c $(INCCORE)check_input.c $(INCCORE)algo.c $(INCCORE)utils_algo.c $(INCCORE)replace_index.c $(INCCORE)five_algo.c $(INCCORE)instructions.c $(INCCORE)instructions2.c $(INCCORE)instructions3.c $(INCMYLIB)ft_putchar_fd.c $(INCMYLIB)ft_atoi.c $(INCMYLIB)ft_isdigit.c $(INCMYLIB)ft_putnbr_fd.c $(INCMYLIB)ft_putstr_fd.c $(INCMYLIB)ft_bzero.c $(INCMYLIB)ft_calloc.c $(INCMYLIB)ft_strlcpy.c $(INCMYLIB)ft_strlen.c $(INCMYLIB)ft_strdup.c $(INCMYLIB)ft_strlcat.c $(INCMYLIB)ft_strjoin.c $(INCMYLIB)ft_split.c

SRC_P = $(INCCHECK)main_bonus.c $(INCCHECK)check_bonus.c $(INCCORE)treat_input.c $(INCCORE)check_input.c  $(INCCORE)utils_algo.c $(INCCORE)replace_index.c $(INCCORE)instructions.c $(INCCORE)instructions2.c $(INCCORE)instructions3.c $(INCMYLIB)gnl/get_next_line.c $(INCMYLIB)gnl/get_next_line_utils.c $(INCMYLIB)ft_putchar_fd.c $(INCMYLIB)ft_atoi.c $(INCMYLIB)ft_isdigit.c $(INCMYLIB)ft_putnbr_fd.c $(INCMYLIB)ft_putstr_fd.c $(INCMYLIB)ft_bzero.c $(INCMYLIB)ft_calloc.c $(INCMYLIB)ft_strlcpy.c $(INCMYLIB)ft_strlen.c $(INCMYLIB)ft_strdup.c $(INCMYLIB)ft_strlcat.c $(INCMYLIB)ft_strjoin.c $(INCMYLIB)ft_split.c

FLAG = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

OBJ_P = $(SRC_P:%.c=%.o)

all: $(NAME) bonus

$(NAME):	$(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ)

bonus:	$(OBJ_P)
		gcc $(FLAG) -o $(NAME_P) $(OBJ_P)

clean:
	rm -rf *.o
	rm -rf $(INCMYLIB)*.o
	rm -rf $(INCMYLIB)gnl/*.o
	rm -rf $(INCCORE)*.o
	rm -rf $(INCCHECK)*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_P)

re: clean all
