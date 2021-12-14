/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:15:15 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/10 19:59:46 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ----------------------------- INCLUDES ------------------------------------ |
// minilibx
# include <mlx.h>

// Xlib keycode - keysymbol mapping + events and masks
# include <X11/keysym.h>
# include <X11/X.h>

// libft
# include "libft.h"

// includes da função open()
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// include do printf()
# include <stdio.h>

// include do read() e close()
# include <unistd.h>

// ------------------------- DEFINES (constants) ----------------------------- |
# define VALID_MAP_CHARS	"EPC10TJ"
# define TILE_SIZE			64

// ------------------------- TYPEDEFS (structs) ------------------------------ |
typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_player
{
	char		**sprite_path;
	void		**img;
	int			direction;
	int			width;
	int			height;
	int			collec_count;
	int			moves_count;
	t_coords	*pos;
}				t_player;

typedef struct s_collectible
{
	int		width;
	int		height;
	char	*sprite_path;
	void	*img;
}				t_collectible;

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}				t_window;

typedef struct s_map
{
	size_t		cols;
	size_t		rows;
	int			tile_width;
	int			tile_height;
	int			c_count;
	int			e_count;
	int			p_count;
	char		*map_path;
	char		*exit_path;
	void		*exit_img;
	char		*floor_path;
	void		*floor_img;
	char		*wall_path;
	void		*wall_img;
	char		**trainer_path;
	void		**trainer_img;
	char		**grid;
	t_coords	*tile;
	t_list		*rows_list;
}				t_map;

typedef struct s_draw{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_width;
	int		endian;
}				t_draw;

typedef struct s_game
{
	void			*mlx;
	t_window		*window;
	t_player		*player;
	t_collectible	*collectible;
	t_draw			*draw;
	t_map			*map;
}				t_game;

// --------------------------- PROTOTYPES ------------------------------------ |

// hooks_utils
int			close_window(t_game *game);
int			detect_keystroke(int keycode, t_game *game);
void		set_hooks(t_game *game);

// game_init_utils
void		allocate_memory(t_game *game);
void		generate_images(t_game *game);
void		initialise_minilibx(t_game *game);
void		initialise_values(t_game *game);
void		load_sprites(t_game *game);

// game_close_utils
void		destroy_images(t_game *game);
void		flush(char *err_msg, int breakpoint, t_game *game);
void		free_grid(t_game *game);
void		game_close(int breakpoint, t_game *game);

// map_validation_utils
void		map_validation(t_game *game);

// movement_utils
t_coords	find_position(char obj, t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);

// other_utils
void		input_validation(int argc, char *map_path, t_game *game);

// render_utils
void		open_window(t_game *game);
int			render_window(t_game *game);
void		render_you_won(t_game *game);

// render_utils_2
void		generate_collectibles_img(t_game *game);
void		generate_exit_img(t_game *game);
void		generate_floor_img(t_game *game);
void		generate_player_img(t_game *game);
void		generate_wall_img(t_game *game);

// render_utils_3
void		generate_moves_img(t_game *game);
void		generate_trainer_img(t_game *game);
void		my_mlx_pixel_put(t_draw *data, int x, int y, int color);
void		print_moves_count(t_game *game);
void		render_ectj(int i, int j, t_game *game);

#endif