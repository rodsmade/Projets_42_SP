/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:38 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 21:06:57 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_validation(int argc, char *map_path, t_game *game)
{
	if (argc != 2)
		flush("Invalid number of arguments (only one accepted)", game);
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		flush("Map format invalid (only .ber allowed)", game);
	game->map->map_path = ft_strdup(map_path);
	return ;
}

t_coords	find_position(char obj, t_game *game)
{
	static t_coords	coords = (t_coords){.x = 0, .y = -1};

	coords.y++;
	while (game->map->grid[coords.x])
	{
		while (game->map->grid[coords.x][coords.y])
		{
			if (game->map->grid[coords.x][coords.y] == obj)
				return (coords);
			coords.y++;
		}
		coords.y = 0;
		coords.x++;
	}
	coords.x = 0;
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
