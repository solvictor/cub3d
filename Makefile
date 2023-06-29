NAME			= cub3d
FTSRCS			= .c
DIRSRCS 		= srcs/program/
SRCS 			=	$(addsuffix .c,				\
					$(addprefix srcs/parsing/,	\
						parsing					\
						textures				\
						map_size				\
						map_correct				\
						map_creation			\
						map_formater			\
						count_islands			\
					)							\
					$(addprefix srcs/cleaning/,	\
						errors					\
						clean_memory			\
					)							\
					$(addprefix srcs/display/,	\
						display					\
						destroy					\
						listeners				\
						line_drawing			\
					)							\
					$(addprefix srcs/caster/,	\
						new_caster				\
					)							\
					$(addprefix srcs/utils/,	\
						comparaisons			\
						line_functions			\
						trigonometry			\
						vectors					\
						points					\
					)							\
					$(addprefix srcs/tests/,	\
						show_info				\
						2d_map					\
						2d_movements			\
						2d_collisions			\
					)							\
						srcs/cub3d				\
					)
BONUSOBJS		= ${BONUS:.c=.o}
PATH_INCLUDES	= includes
HEADER			= ${PATH_INCLUDES}
LIBFTDIR		= libft
LIBFTLIB		= -lft
CC				= cc
MLXDIR			= minilibx-linux
MLXLIB			= -lmlx
XLIBS			= -lX11 -lXext
FLAGS			= -Wall -Wextra 
#=====================================TODO ADD WERROR
OBJS			= ${SRCS:.c=.o}
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ -I${HEADER}

all: ${NAME}
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${NAME}: ${OBJS} ${LIBFTDIR}/libft.a ${MLXDIR}/libmlx.a
	@${CC} ${FLAGS} ${OBJS} -I${HEADER} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o $@ -g3

sanitize: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} -I${HEADER} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o cub3d -g3 -fsanitize=address

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

${MLXDIR}/libmlx.a:
	@make -C ${MLXDIR}

bonus: ${BONUSOBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${BONUSOBJS} ${HEADER} -L${LIBFTDIR} ${LIBFTLIB} -o cub3d -g3

norm:
	norminette srcs
	norminette includes
	norminette libft

#----------------------------CUB3D

clean:
	@echo "${CYAN}Cleaned ${NAME}${NC}"
	@${RM} ${OBJS}
fclean:		clean
	@echo "${CYAN}FCleaned ${NAME}${NC}"
	@${RM} ${NAME}

re: fclean all

bonus_clean:
	@${RM} ${BONUSOBJS}

bonus_fclean: bonus_clean
	@${RM} checker

bonus_re: bonus_fclean bonus

#----------------------------LIBFT

libft_all:
	@make -C ${LIBFTDIR} all

libft_clean:
	@make -C ${LIBFTDIR} clean

libft_fclean:
	@make -C ${LIBFTDIR} fclean


libft_re:
	@make -C ${LIBFTDIR} re

#----------------------------MLX

mlx_re:
	@make -C ${MLXDIR} re

mlx_clean:
	@make -C ${MLXDIR} clean

mlx_all:
	@make -C ${MLXDIR} all


#----------------------------ALL

all_clean: clean libft_clean bonus_clean mlx_clean

all_fclean: fclean libft_fclean bonus_fclean mlx_clean

all_re: libft_re mlx_re re
	@echo "${CYAN}Re-ed ${NAME}${NC}"


.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean all_clean all_fclean bonus bonus_clean bonus_fclean bonus_re
