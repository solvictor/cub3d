SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_printer_c.c ft_printer_d.c ft_printer_i.c ft_printer_p.c ft_printer_s.c ft_printer_u.c ft_printer_upperx.c ft_printer_x.c ft_printf.c ft_putnbr_int.c ft_putnbr_ui_hexa_low.c ft_putnbr_ui_hexa_up.c ft_putnbr_ui.c ft_putnbr_ul_hexa.c ft_len_nb_hexa.c ft_strstr.c ft_free_strs.c ft_cset_in_str.c ft_print_int_tab.c ft_sort_int_tab.c ft_is_int_tab_sorted.c ft_rev_int_tab.c ft_free_ints.c ft_ints.c ft_free_lst.c ft_c_in_str.c ft_strsdup.c
BSRCS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
NAME 		= libft.a
RM 			= rm -rf
OBJS		= ${SRCS:.c=.o}
BOBJS		= ${BSRCS:.c=.o}
FLAGS		= -Wall -Wextra -Werror
CC			= gcc

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

${NAME}:	${BOBJS} ${OBJS}
			ar rcs ${NAME} ${OBJS} ${BOBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

norminette:
	norminette ${SRCS} ${BSRCS}

.PHONY:		all clean fclean re
