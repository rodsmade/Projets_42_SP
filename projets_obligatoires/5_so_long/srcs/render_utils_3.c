/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/09 17:12:45 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_mewtwo_img(t_game *game)
{
	game->map->mewtwo_img = mlx_xpm_file_to_image(game->mlx,
			game->map->mewtwo_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->mewtwo_img == NULL)
		flush("MLX_ERROR while creating Mewtwo image", 0, game);
	return ;
}

void	render_ecm(int i, int j, t_game *game)
{
	if (game->map->grid[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->exit_img, TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->collectible->img, TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'M')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->mewtwo_img, TILE_SIZE * j,
			TILE_SIZE * i);
}
