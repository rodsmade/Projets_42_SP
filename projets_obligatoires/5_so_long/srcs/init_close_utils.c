/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_close_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:44 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 19:33:21 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_memory(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->pos = ft_calloc(1, sizeof(t_coords));
	game->collectible = ft_calloc(1, sizeof(t_collectible));
	game->map->tile = ft_calloc(1, sizeof(t_collectible));
	if (game->map == NULL || game->window == NULL || game->player == NULL
		|| game->collectible == NULL || game->player->pos == NULL
		|| game->map->tile == NULL)
		flush("Something wrong happened while allocating memory, closing game. . .", game);
	return ;
}

void	initialise_values(t_game *game)
{
	game->map->C_count = 0;
	game->map->E_count = 0;
	game->map->P_count = 0;
	game->map->rows = 0;
	game->map->tile_width = 64;
	game->map->tile_height = 64;
	game->player->direction = 'l';
	game->player->moves_count = 0;
	return ;
}

void	load_sprites(t_game *game)
{
	game->player->sprite_path = ft_calloc(4, sizeof(char *));
	if (game->player->sprite_path == NULL)
		flush("Error allocating memory for player sprite paths", game);
	game->player->sprite_path[0] = "./resources/images/pikachu_u1_64.xpm";
	game->player->sprite_path[1] = "./resources/images/pikachu_l1_64.xpm";
	game->player->sprite_path[2] = "./resources/images/pikachu_d1_64.xpm";
	game->player->sprite_path[3] = "./resources/images/pikachu_r1_64.xpm";
	game->map->floor_path = "./resources/images/floor_64.xpm";
	game->map->wall_path = "./resources/images/stone_64.xpm";
	game->map->exit_path = "./resources/images/exit_64.xpm";
	game->collectible->sprite_path = "./resources/images/pokeball_64.xpm";
	*(game->player->pos) = find_position('P', game);
	return ;
}

void	game_close(t_game *game)
{
	int		i;

	i = -1;
	while(game->map->grid[++i])
		free(game->map->grid[i]);
	free(game->map->grid);
	free(game->map->map_path);
	free(game->map->tile);
	mlx_destroy_image(game->mlx, game->map->floor_img);
	mlx_destroy_image(game->mlx, game->map->wall_img);
	mlx_destroy_image(game->mlx, game->map->exit_img);
	mlx_destroy_image(game->mlx, game->collectible->img);
	i = -1;
	while(++i < 4)
	{
		mlx_destroy_image(game->mlx, game->player->img[i]);
	}
	free(game->player->img);
	free(game->player->pos);
	free(game->player->sprite_path);
	free(game->player);
	free(game->collectible);
	free(game->map);
	free(game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	printf("----> passou\n");
	return ;
}

void	flush(char *err_msg, t_game *game)
{
	// TODO: rever isso do flush, se ñ tá esquecendo de dar free em coisa q era pra dar !!!
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