/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:15:15 by roaraujo          #+#    #+#             */
/*   Updated: 2021/11/18 21:58:34 by roaraujo         ###   ########.fr       */
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


// ------------------------- DEFINES (constants) ----------------------------- |
# define VALID_MAP_CHARS	"EPC10"
# define MLX_ERROR			1
# define TILE				50

// ------------------------- TYPEDEFS (structs) ----------------------------- |
typedef struct	s_player{
	char	*sprite_path;
	void	*img;
	int		x_position;
	int		y_position;
	int		width;
	int		height;
}				t_player;

// acho q essa t_img na vdd só precisa se for usar aquela função de pixel put otimizada my_pixel_put
// typedef struct	s_img{
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_width;
// 	int		endian;
// }				t_img;

typedef struct	s_window{
	void	*win_ptr;
	int		width;
	int		height;
}				t_window;

typedef struct	s_map{
	char	*map_path; //ñ sei se é útil mas vai que
	void	*img;
	int		cols;
	int		rows;
	int		sprite_width;
	int		sprite_height;
	char	*floor_path;
	char	*wall_path;
	char	*collectible_path;
	char	*exit_path;
}				t_map;

typedef struct	s_game{
	void		*mlx;
	t_window	*window;
	t_player	*player;
	t_map		*map;
}				t_game;

// --------------------------- PROTOTYPES ------------------------------------ |
int	so_long(int argc, char *argv[]);

// movement_utils
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);

// render_utils
int		render_everything(t_game *game);

// other_utils_sort_later
int		close_window(t_game *game);
int		detect_keystroke(int keycode, t_game *game);

#endif