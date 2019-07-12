# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 22:20:08 by gjuste            #+#    #+#              #
#    Updated: 2019/06/24 16:52:26 by gjuste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[0;31m
BRED =		\033[1;31m
GREEN =		\033[0;32m
BGREE =		\033[1;32m
YELLOW =	\033[0;33m
BLUE =		\033[0;34m
PINK =		\033[0;35m
CYAN =		\033[0;36m
RESET =		\033[0m
WHITE =		\033[1m

NAME =	libft.a

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

HEADER =		libft.h
HEADER_PRINTF =	ft_printf.h

SRC =	get_next_line.c				\
		ft_memset.c					\
		ft_strcmp.c					\
		ft_strdup.c					\
		ft_strlen.c					\
		ft_strncmp.c				\
		ft_bzero.c					\
		ft_memcpy.c					\
		ft_memccpy.c				\
		ft_memmove.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_strcpy.c					\
		ft_strncpy.c				\
		ft_strcat.c					\
		ft_strncat.c				\
		ft_strlcat.c				\
		ft_strchr.c					\
		ft_strrchr.c				\
		ft_strstr.c					\
		ft_strnstr.c				\
		ft_atoi.c					\
		ft_isalpha.c				\
		ft_isdigit.c				\
		ft_isalnum.c				\
		ft_isascii.c				\
		ft_isprint.c				\
		ft_toupper.c				\
		ft_tolower.c				\
		ft_memalloc.c				\
		ft_memdel.c					\
		ft_strnew.c					\
		ft_strdel.c					\
		ft_strclr.c					\
		ft_striter.c				\
		ft_striteri.c				\
		ft_strmap.c					\
		ft_strmapi.c				\
		ft_strequ.c					\
		ft_strnequ.c				\
		ft_strsub.c					\
		ft_strjoin.c				\
		ft_strcrev.c				\
		ft_strtrim.c				\
		ft_iswap.c					\
		ft_strsplit.c				\
		ft_itoa.c					\
		ft_intlen.c					\
		ft_mesure_wor.c				\
		ft_mesure_let.c				\
		ft_do_it.c					\
		ft_putchar.c				\
		ft_putstr.c					\
		ft_putendl.c				\
		ft_putnbr.c					\
		ft_putchar_fd.c				\
		ft_putstr_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\
		ft_lstnew.c					\
		ft_lstdelone.c				\
		ft_lstdel.c					\
		ft_lstadd.c					\
		ft_lstiter.c				\
		ft_lstmap.c					\
		ft_putnbr_base.c			\
		ft_unsigned_nblen.c			\
		ft_putnbr_unsigned_base.c	\
		ft_power.c					\
		ft_strjoinfree.c			\
		ft_strndup.c				\
		ft_printf.c					\
		ptf_parser.c				\
		ptf_misc_ptf.c				\
		ptf_find_fct.c				\
		ptf_alph.c					\
		ptf_num1.c					\
		ptf_misc_num1.c				\
		ptf_num2.c					\
		ptf_misc_num2.c				\
		ptf_misc_calc.c				\
		ft_tabdel.c					\
		ft_abs.c					\
		ft_tabint.c
SRCS =			$(sort $(SRC))
OBJS_DIR =		objs
OBJS_FILES =	$(SRCS:.c=.o)
OBJS =			$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
NB =			$(words $(SRCS))
INDEX =			0

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(GREEN)[ 100%% ]   Compiling   $(BGREE)%-16s$(RESET) %10s\n\n$(RESET)" $(NAME) "done ---"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.c $(HEADER) $(HEADER_PRINTF)
	@$(eval PERCENT = $(shell echo $$(($(INDEX) * 100 / $(NB)))))
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)
	@printf "$(YELLOW)[ %3d%% ]   %s\t%-25s\r$(RESET)" $(PERCENT) $(NAME) $<
	@$(eval INDEX = $(shell echo $$(($(INDEX) + 1))))

clean:
	@if [ -d $(OBJS_DIR) ]; then printf "$(RED)%-10s %-10s $(BRED)%-19s$(RED) %s\n$(RESET)" "DELETE" $@ ./libft/$(OBJS_DIR) "done ---"; rm -Rf $(OBJS_DIR); fi

fclean: clean
	@if [ -e $(NAME) ]; then printf "$(RED)%-10s %-10s $(BRED)%-19s$(RED) %s\n$(RESET)" "DELETE" $@ $(NAME) "done ---"; rm -f $(NAME); fi

re: fclean all
