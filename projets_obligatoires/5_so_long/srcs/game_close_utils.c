/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:44 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/10 20:06:36 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	int		i;

	if (game->map->floor_img != NULL)
		mlx_destroy_image(game->mlx, game->map->floor_img);
	if (game->map->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->map->wall_img);
	if (game->map->exit_img != NULL)
		mlx_destroy_image(game->mlx, game->map->exit_img);
	if (game->map->trainer_img[0] != NULL)
		mlx_destroy_image(game->mlx, game->map->trainer_img[0]);
	if (game->map->trainer_img[1] != NULL)
		mlx_destroy_image(game->mlx, game->map->trainer_img[1]);
	if (game->collectible->img != NULL)
		mlx_destroy_image(game->mlx, game->collectible->img);
	if (game->draw->img != NULL)
		mlx_destroy_image(game->mlx, game->draw->img);
	i = -1;
	while (++i < 4)
	{
		if (game->player->img[i] != NULL)
			mlx_destroy_image(game->mlx, game->player->img[i]);
	}
	return ;
}

void	flush(char *err_msg, int breakpoint, t_game *game)
{
	printf("Error\n%s\n", err_msg);
	game_close(breakpoint, game);
	exit(0);
}

void	free_grid(t_game *game)
{
	int	i;

	i = -1;
	while (game->map->grid[++i])
		ft_free_ptr((void *)&game->map->grid[i]);
	ft_free_ptr((void *)&game->map->grid);
	return ;
}

void	game_close(int breakpoint, t_game *game)
{
	destroy_images(game);
	free_grid(game);
	ft_free_ptr((void *)&game->player->img);
	ft_free_ptr((void *)&game->player->pos);
	ft_free_ptr((void *)&game->player->sprite_path);
	ft_free_ptr((void *)&game->player);
	ft_free_ptr((void *)&game->collectible);
	ft_free_ptr((void *)&game->draw);
	ft_free_ptr((void *)&game->map->map_path);
	ft_free_ptr((void *)&game->map->tile);
	ft_free_ptr((void *)&game->map->trainer_img);
	ft_free_ptr((void *)&game->map->trainer_path);
	ft_free_ptr((void *)&game->map);
	ft_free_ptr((void *)&game->window);
	if (breakpoint != 1)
	{
		mlx_destroy_display(game->mlx);
		ft_free_ptr((void *)&game->mlx);
	}
	return ;
}
