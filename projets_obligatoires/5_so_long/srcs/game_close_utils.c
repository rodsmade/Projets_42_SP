/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:44 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 20:56:57 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	int		i;

	mlx_destroy_image(game->mlx, game->map->floor_img);
	mlx_destroy_image(game->mlx, game->map->wall_img);
	mlx_destroy_image(game->mlx, game->map->exit_img);
	mlx_destroy_image(game->mlx, game->collectible->img);
	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(game->mlx, game->player->img[i]);
	}
	return ;
}

void	game_close(t_game *game)
{
	int		i;

	destroy_images(game);
	i = -1;
	while (game->map->grid[++i])
		free(game->map->grid[i]);
	free(game->map->grid);
	free(game->map->map_path);
	free(game->map->tile);
	free(game->player->img);
	free(game->player->pos);
	free(game->player->sprite_path);
	free(game->player);
	free(game->collectible);
	free(game->map);
	free(game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return ;
}

void	flush(char *err_msg, t_game *game)
{
	printf("Error\n%s\n", err_msg);
	if (game->map != NULL)
		free(game->map);
	if (game->window != NULL)
		free(game->window);
	if (game->player != NULL)
		free(game->player);
	if (game->collectible != NULL)
		free(game->collectible);
	exit(0);
}
