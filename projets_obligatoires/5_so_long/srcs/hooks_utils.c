/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:42 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/04 23:14:43 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// hooks_utils.c maybe?

#include "so_long.h"

int	close_window(t_game *game){
	mlx_destroy_window(game->mlx, game->window->win_ptr);
	game->window->win_ptr = NULL;
	return (0);
}

int		detect_keystroke(int keycode, t_game *game){
	if (keycode == 65361 || keycode == 97)
		move_left(game);
	if (keycode == 65362 || keycode == 119)
		move_up(game);
	if (keycode == 65363 || keycode == 100)
		move_right(game);
	if (keycode == 65364 || keycode == 115)
		move_down(game);
	if (keycode == XK_Escape)
		close_window(game);
	else
		mlx_clear_window(game->mlx, game->window->win_ptr);
	return (0);
}
