/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:42 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/07 18:58:19 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	// printf("paSSOU AQUI\n");
	mlx_destroy_window(game->mlx, game->window->win_ptr);
	game->window->win_ptr = NULL;
	game_close(game);
	exit(0);
}

int	detect_keystroke(int keycode, t_game *game)
{
	if (keycode == XK_Left || keycode == XK_a)
		move_left(game);
	if (keycode == XK_Up || keycode == XK_w)
		move_up(game);
	if (keycode == XK_Right || keycode == XK_d)
		move_right(game);
	if (keycode == XK_Down || keycode == XK_s)
		move_down(game);
	if (keycode == XK_Escape)
		close_window(game);
	return (0);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->window->win_ptr,
		DestroyNotify, NoEventMask, &close_window, game);
	mlx_hook(game->window->win_ptr,
		KeyPress, KeyPressMask, &detect_keystroke, game);
	mlx_loop_hook(game->mlx, &render_window, game);
	return ;
}
