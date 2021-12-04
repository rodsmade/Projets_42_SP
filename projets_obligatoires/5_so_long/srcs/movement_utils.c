/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:54 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/05 00:51:57 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	game->player->direction = 'j';
	game->player->pos->y--;
	// if (game->map->map_2D[game->player->pos->y][game->player->pos->y - 1] != '1')
	// 	game->player->pos->y--;
	// if (game->player->pos->x - game->map->tile_width >= 0)
	// 	game->player->pos->x -= game->map->tile_width;
	return ;
}

void	move_up(t_game *game)
{
	game->player->direction = 'i';
	game->player->pos->x--;
	// if (game->player->pos->y - game->map->tile_height >= 0)
	// 	game->player->pos->y -= game->map->tile_height;
	return ;
}

void	move_right(t_game *game)
{
	game->player->direction = 'l';
	game->player->pos->y++;
	// if (game->player->pos->x + game->map->tile_width <= game->window->width - game->map->tile_width)
	// 	game->player->pos->x += game->map->tile_width;
	return ;
}

void	move_down(t_game *game)
{
	game->player->direction = 'k';
	game->player->pos->x++;
	// if (game->player->pos->y + game->map->tile_height <= game->window->height - game->map->tile_height)
	// 	game->player->pos->y += game->map->tile_height;
	return ;
}
