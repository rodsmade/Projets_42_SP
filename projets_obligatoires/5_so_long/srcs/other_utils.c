/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:38 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/04 23:14:40 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coords	find_position(char obj, t_game *game)
{
	static t_coords	coords = (t_coords){.x = -1, .y = -1};

	while (game->map->map_2D[++coords.x])
	{
		coords.y = -1;
		while (game->map->map_2D[coords.x][++coords.y])
		{
			if (game->map->map_2D[coords.x][coords.y] == obj)
				return (coords);
		}
	}
	coords.x = -1;
	coords.y = -1;
	return (coords);
}

void	open_window(t_game *game)
{
	game->window->width = game->map->tile_width * game->map->cols;
	game->window->height = game->map->tile_height * game->map->rows;
	game->window->win_ptr = mlx_new_window(game->mlx,
			game->window->width,
			game->window->height,
			"ma fenetre");
	if (game->window->win_ptr == NULL)
		flush("MLX_ERROR while opening new window", game);
	return ;
}
