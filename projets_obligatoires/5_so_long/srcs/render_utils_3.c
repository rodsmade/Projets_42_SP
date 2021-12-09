/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/09 22:59:04 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_trainer_img(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		game->map->trainer_img[i] = mlx_xpm_file_to_image(game->mlx,
				game->map->trainer_path[i],
				&game->map->tile->x,
				&game->map->tile->y);
		if (game->map->trainer_img[i] == NULL)
			flush("MLX_ERROR while creating trainer image", 0, game);
	}
	return ;
}

void	render_ectj(int i, int j, t_game *game)
{
	if (game->map->grid[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->exit_img, TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->collectible->img, TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'T')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->trainer_img[0], TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'J')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->trainer_img[1], TILE_SIZE * j,
			TILE_SIZE * i);
}

void	print_moves_count(t_game *game)
{
	char	*string;

	string = ft_itoa(game->player->moves_count);
	mlx_string_put(game->mlx, game->window->win_ptr, 50, 50, 0xFFFFFF, string);
	ft_free_ptr((void *)&string);
}
