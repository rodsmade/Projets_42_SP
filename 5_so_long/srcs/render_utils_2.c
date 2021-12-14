/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/10 20:09:50 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_collectibles_img(t_game *game)
{
	game->collectible->img = mlx_xpm_file_to_image(game->mlx,
			game->collectible->sprite_path,
			&game->collectible->width,
			&game->collectible->height);
	if (game->map->wall_img == NULL)
		flush("MLX_ERROR while creating collectibles image", 0, game);
	return ;
}

void	generate_exit_img(t_game *game)
{
	game->map->exit_img = mlx_xpm_file_to_image(game->mlx,
			game->map->exit_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->exit_img == NULL)
		flush("MLX_ERROR while creating exit image", 0, game);
	return ;
}

void	generate_floor_img(t_game *game)
{
	game->map->floor_img = mlx_xpm_file_to_image(game->mlx,
			game->map->floor_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->floor_img == NULL)
		flush("MLX_ERROR while creating floor image", 0, game);
	return ;
}

void	generate_player_img(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->player->img[i] = mlx_xpm_file_to_image(game->mlx,
				game->player->sprite_path[i],
				&game->player->width, &game->player->height);
		if (game->player->img[i] == NULL)
			flush("MLX_ERROR while creating player images", 0, game);
	}
	return ;
}

void	generate_wall_img(t_game *game)
{
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx,
			game->map->wall_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->wall_img == NULL)
		flush("MLX_ERROR while creating wall image", 0, game);
	return ;
}
