NAME			= cub3d
SRCS 			=	$(addsuffix .c,				\
					$(addprefix srcs/parsing/,	\
						parsing					\
						rgb						\
						textures				\
						map_size				\
						map_correct				\
						map_creation			\
						map_formater			\
					)							\
					$(addprefix srcs/cleaning/,	\
						errors					\
						clean_memory			\
					)							\
					$(addprefix srcs/display/,	\
						display					\
						destroy					\
						listeners				\
						textures				\
					)							\
					$(addprefix srcs/caster/,	\
						caster					\
						movements				\
						textures				\
						walls					\
						arrows					\
					)							\
					$(addprefix srcs/utils/,	\
						line_functions			\
						vectors					\
					)							\
						srcs/cub3d				\
					)
DEPS_SRCS		= $(SRCS:.c=.d)
BONUS			= $(addsuffix .c,				\
					$(addprefix bonus/parsing/,	\
						parsing					\
						rgb						\
						textures				\
						map_size				\
						map_correct				\
						map_creation			\
						map_formater			\
					)							\
					$(addprefix bonus/cleaning/,\
						errors					\
						clean_memory			\
						map						\
						mlx						\
					)							\
					$(addprefix bonus/display/,	\
						display					\
						destroy					\
						listeners				\
						textures				\
						minimap					\
					)							\
					$(addprefix bonus/caster/,	\
						caster					\
						movements				\
						textures				\
						walls					\
						doors					\
						arrows					\
					)							\
					$(addprefix bonus/utils/,	\
						line_functions			\
						vectors					\
						ft_atof_bool			\
					)							\
					$(addprefix bonus/init/,	\
						display					\
						camera					\
						map						\
					)							\
						bonus/cub3d				\
					)
DEPS_BONUS		= $(BONUS:.c=.d)
BONUSOBJS		= ${BONUS:.c=.o}
PATH_INCLUDES	= includes
HEADER			= ${PATH_INCLUDES}
LIBFTDIR		= libft
LIBFTLIB		= -lft
CC				= cc
MLXDIR			= minilibx-linux
MLXLIB			= -lmlx
XLIBS			= -lX11 -lXext
FLAGS			= -Wall -Wextra -Werror
OBJS			= ${SRCS:.c=.o}
MLXDIR			= minilibx-linux
MLXGIT			= https://github.com/42Paris/minilibx-linux.git
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

-include $(DEPS_SRCS) $(DEPS_BONUS)

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -MMD -o $@ -c $< -I${HEADER}

all: ${NAME}
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${NAME}: ${MLXDIR}/libmlx.a ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} -I${HEADER} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o $@ -g3

sanitize: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} -I${HEADER} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o cub3d -g3 -fsanitize=address

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

bonus: ${MLXDIR}/libmlx.a ${BONUSOBJS} ${LIBFTDIR}/libft.a 
	@${CC} ${FLAGS} ${BONUSOBJS} -I${HEADER} ${XLIBS} -L${MLXDIR} ${MLXLIB} -L${LIBFTDIR} ${LIBFTLIB} -lm -o cub3d_bonus -g3
	@echo "${LGREEN}Successfully created${NC}${CYAN} cub3d_bonus${NC}${LGREEN}!${NC}"

norm:
	norminette srcs
	norminette includes
	norminette libft

${MLXDIR}/libmlx.a:
	@if [ ! -d "${MLXDIR}" ] ; then \
		echo "${CYAN}MLX not found. Cloning repository...${NC}"; \
		git clone ${MLXGIT} ${MLXDIR}; \
	fi
	@make -C ${MLXDIR}

#----------------------------CUB3D

clean:
	@echo "${CYAN}Cleaned ${NAME}${NC}"
	@${RM} ${OBJS} $(DEPS_SRCS)
fclean:		clean
	@echo "${CYAN}FCleaned ${NAME}${NC}"
	@${RM} ${NAME}

re: fclean all

bonus_clean:
	@${RM} ${BONUSOBJS} $(DEPS_BONUS)

bonus_fclean: bonus_clean
	@${RM} cub3d_bonus

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

.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean all_clean all_fclean bonus bonus_clean bonus_fclean bonus_re
