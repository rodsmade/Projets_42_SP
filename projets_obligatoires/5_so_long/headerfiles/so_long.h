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

# define VALID_MAP_CHARS	"EPC10"
# define MLX_ERROR			1


// TYPEDEFS:
typedef struct	s_mlxptrs {
	void	*mlx;
	void	*window;
}				t_mlxptrs;

int	so_long(int argc, char *argv[]);

#endif