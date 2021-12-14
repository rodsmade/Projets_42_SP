/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/12 23:28:31 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_game *game)
{
	game->window->width = TILE_SIZE * game->map->cols;
	game->window->height = TILE_SIZE * game->map->rows;
	game->window->win_ptr = mlx_new_window(game->mlx,
			game->window->width,
			game->window->height,
			"Pokemon Yellow-ish");
	if (game->window->win_ptr == NULL)
		flush("MLX_ERROR while opening new window", 0, game);
	return ;
}

static void	render_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map->grid[++i])
	{
		j = -1;
		while (game->map->grid[i][++j])
		{
			if (game->map->grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window->win_ptr,
					game->map->wall_img, TILE_SIZE * j,
					TILE_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx, game->window->win_ptr,
					game->map->floor_img, TILE_SIZE * j,
					TILE_SIZE * i);
		}
	}
	return ;
}

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window->win_ptr,
		game->player->img[game->player->direction - 'i'],
		TILE_SIZE * game->player->pos->y,
		TILE_SIZE * game->player->pos->x);
	return ;
}

int	render_window(t_game *game)
{
	int		i;
	int		j;

	if (game->window->win_ptr != NULL)
	{
		render_map(game);
		i = -1;
		while (game->map->grid[++i])
		{
			j = -1;
			while (game->map->grid[i][++j])
			{
				render_ectj(i, j, game);
			}
		}
		render_player(game);
		print_moves_count(game);
	}
	return (0);
}

void	render_you_won(t_game *game)
{
	close_window(game);
	return ;
}
