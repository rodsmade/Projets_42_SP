/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:15:15 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/02 21:54:26 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ----------------------------- INCLUDES ------------------------------------ |
// minilibx
#include <mlx.h>

// Xlib keycode - keysymbol mapping
# include <X11/keysym.h>

// libft
# include "libft.h"

// includes da função open()
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// include do printf()
# include <stdio.h>

// include do read() e close()
#include <unistd.h>

// ------------------------- DEFINES (constants) ----------------------------- |
# define VALID_MAP_CHARS	"EPC10"
# define MLX_ERROR			1
# define TILE				50
# define DESTROY_NOTIFY		17
# define KEY_PRESS			2
# define NO_EVENT_MASK		0
# define KEY_PRESS_MASK		1L<<0

// ------------------------- TYPEDEFS (structs) ------------------------------ |
typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct	s_player
{
	char		**sprite_path;
	void		**img;
	int			direction;
	int			top_tile;
	int			bottom_tile;
	int			left_tile;
	int			right_tile;
	int			width;
	int			height;
	int			collec_count;
	t_coords	*pos;
}				t_player;

typedef struct	s_collectible
{
	int		width;
	int		height;
	char	*sprite_path;
	void	*img;
}				t_collectible;

// acho q essa t_img_draw na vdd só precisa se for usar aquela função de pixel put otimizada my_pixel_put
// typedef struct	s_img_draw{
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_width;
// 	int		endian;
// }				t_img_draw;

typedef struct	s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}				t_window;

typedef struct	s_map
{
	size_t		cols;
	size_t		rows;
	int			tile_width;
	int			tile_height;
	int			C_count;
	int			E_count;
	int			P_count;
	char		*map_path; //ñ sei se é útil mas vai que
	char		*exit_path;
	void		*exit_img;
	char		*floor_path;
	void		*floor_img;
	char		*wall_path;
	void		*wall_img;
	char		**map_2D;
	t_coords	*tile;
	t_list		*rows_list;
}				t_map;

typedef struct	s_game
{
	void			*mlx;
	t_window		*window;
	t_player		*player;
	t_collectible	*collectible;
	t_map			*map;
}				t_game;

// --------------------------- PROTOTYPES ------------------------------------ |
void	so_long(int argc, char *argv[]);

// initialise_utils
void	initialise_values(t_game *game);
void	allocate_memory(t_game *game);
void	load_sprites(t_game *game);
void	game_close(t_game *game);
void	flush(char *err_msg, t_game *game);

// map_validation_utils
void	map_validation(t_game *game);
void	input_validation(int argc, char *map_path, t_game *game);

// movement_utils
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);

// render_utils
void	generate_collectibles_img(t_game *game);
void	generate_floor_img(t_game *game);
void	generate_player_img(t_game *game);
void	generate_wall_img(t_game *game);
void	generate_exit_img(t_game *game);
int		render_window(t_game *game);

// hooks_utils
int		close_window(t_game *game);
int		detect_keystroke(int keycode, t_game *game);

// other_utils
t_coords	find_position(char obj, t_game *game);
void		open_window(t_game *game);

#endif