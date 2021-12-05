/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:54 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/05 01:01:25 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	game->player->direction = 'j';
	if (game->map->map_2D[game->player->pos->x][game->player->pos->y - 1] != '1')
		game->player->pos->y--;
	return ;
}

void	move_up(t_game *game)
{
	game->player->direction = 'i';
	if (game->map->map_2D[game->player->pos->x - 1][game->player->pos->y] != '1')
		game->player->pos->x--;
	return ;
}

void	move_right(t_game *game)
{
	game->player->direction = 'l';
	if (game->map->map_2D[game->player->pos->x][game->player->pos->y + 1] != '1')
		game->player->pos->y++;
	return ;
}

void	move_down(t_game *game)
{
	game->player->direction = 'k';
	if (game->map->map_2D[game->player->pos->x + 1][game->player->pos->y] != '1')
		game->player->pos->x++;
	return ;
}
