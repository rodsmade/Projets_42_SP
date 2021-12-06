/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 21:33:15 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_player_img(t_game *game)
{
	game->player->img = ft_calloc(4, sizeof(void *));
	if (game->player->img == NULL)
		flush("Error allocating memory for player images", game);
	game->player->img[0] = mlx_xpm_file_to_image(game->mlx,
			game->player->sprite_path[0],
			&game->player->width,
			&game->player->height);
	game->player->img[1] = mlx_xpm_file_to_image(game->mlx,
			game->player->sprite_path[1],
			&game->player->width,
			&game->player->height);
	game->player->img[2] = mlx_xpm_file_to_image(game->mlx,
			game->player->sprite_path[2],
			&game->player->width,
			&game->player->height);
	game->player->img[3] = mlx_xpm_file_to_image(game->mlx,
			game->player->sprite_path[3],
			&game->player->width,
			&game->player->height);
	if (game->player->img[0] == NULL
		|| game->player->img[1] == NULL
		|| game->player->img[2] == NULL
		|| game->player->img[3] == NULL)
		flush("MLX_ERROR while creating player images", game);
	return ;
}

void	generate_floor_img(t_game *game)
{
	game->map->floor_img = mlx_xpm_file_to_image(game->mlx,
			game->map->floor_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->floor_img == NULL)
		flush("MLX_ERROR while creating floor image", game);
	return ;
}

void	generate_wall_img(t_game *game)
{
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx,
			game->map->wall_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->wall_img == NULL)
		flush("MLX_ERROR while creating wall image", game);
	return ;
}

void	generate_exit_img(t_game *game)
{
	game->map->exit_img = mlx_xpm_file_to_image(game->mlx,
			game->map->exit_path,
			&game->map->tile->x,
			&game->map->tile->y);
	if (game->map->exit_img == NULL)
		flush("MLX_ERROR while creating exit image", game);
	return ;
}

void	generate_collectibles_img(t_game *game)
{
	game->collectible->img = mlx_xpm_file_to_image(game->mlx,
			game->collectible->sprite_path,
			&game->collectible->width,
			&game->collectible->height);
	if (game->map->wall_img == NULL)
		flush("MLX_ERROR while creating collectibles image", game);
	return ;
}
