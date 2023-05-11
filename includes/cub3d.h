#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

# define SPACES " \f\n\r\t\v"
# define PLAYER "NSEW"
# define CSET_END_LINES " 1\n"
# define FREE "0NSEW"
# define COLLIDE "1"

/*
	The map contains the '\n' at the end of the lines
*/
typedef struct s_map
{
	unsigned char	ceiling_color[3];
	unsigned char	floor_color[3];
	char			*path_north;
	char			*path_south;
	char			*path_east;
	char			*path_west;
	int				param_number;
	int				param_lines[6];
	int				heigth;
	int				length;
	int				first_line;
	int				start_coords[2];
	char			start_direction;
	char			**map;
}					t_map;

typedef struct s_vars
{
	char			**file_content;
	t_map			*map;
}					t_vars;

/******************************************************************************/
/*                                                                            */
/*                                 Parsing                                    */
/*                                                                            */
/******************************************************************************/
bool	parsing(char *file_name, t_vars *vars, t_map *map);
bool	get_textures_info(t_vars *vars, t_map *map);
bool	map_size(t_vars *vars, t_map *map);
bool	map_correct(t_map *map);
bool	create_map(t_vars *vars, t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                 Cleaning                                   */
/*                                                                            */
/******************************************************************************/
void	error_str(char *str);
void	clean_memory(t_vars *vars);

#endif
