/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:44 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/12 23:21:16 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_memory(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->player = ft_calloc(1, sizeof(t_player));
	game->collectible = ft_calloc(1, sizeof(t_collectible));
	game->draw = ft_calloc(1, sizeof(t_draw));
	game->player->pos = ft_calloc(1, sizeof(t_coords));
	game->player->img = ft_calloc(4, sizeof(void *));
	game->map->trainer_img = ft_calloc(2, sizeof(void *));
	game->map->grid = ft_calloc(1, sizeof(char **));
	game->map->tile = ft_calloc(1, sizeof(t_collectible));
	if (!game->map || !game->window || !game->player || !game->collectible
		|| !game->player->pos || !game->map->tile || !game->player->img
		|| !game->map->grid || !game->map->trainer_img || !game->draw)
		flush("Memory allocation failed, closing game. . .", 0, game);
	return ;
}

void	generate_images(t_game *game)
{
	generate_player_img(game);
	generate_floor_img(game);
	generate_trainer_img(game);
	generate_wall_img(game);
	generate_exit_img(game);
	generate_collectibles_img(game);
	generate_moves_img(game);
	return ;
}

void	initialise_minilibx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		flush("MLX_ERROR while initialising mlx", 1, game);
	return ;
}

void	initialise_values(t_game *game)
{
	game->map->c_count = 0;
	game->map->e_count = 0;
	game->map->p_count = 0;
	game->map->rows = 0;
	game->player->direction = 'l';
	game->player->moves_count = 0;
	game->player->img[0] = NULL;
	game->player->img[1] = NULL;
	game->player->img[2] = NULL;
	game->player->img[3] = NULL;
	game->map->trainer_img[0] = NULL;
	game->map->trainer_img[1] = NULL;
	return ;
}

void	load_sprites(t_game *game)
{
	game->player->sprite_path = ft_calloc(4, sizeof(char *));
	if (game->player->sprite_path == NULL)
		flush("Error allocating memory for player sprite paths", 1, game);
	game->map->trainer_path = ft_calloc(2, sizeof(char *));
	if (game->map->trainer_img == NULL)
		flush("Error allocating memory for trainers sprite paths", 1, game);
	game->player->sprite_path[0] = "./resources/images/pikachu_u1_64.xpm";
	game->player->sprite_path[1] = "./resources/images/pikachu_l1_64.xpm";
	game->player->sprite_path[2] = "./resources/images/pikachu_d1_64.xpm";
	game->player->sprite_path[3] = "./resources/images/pikachu_r1_64.xpm";
	game->map->trainer_path[0] = "./resources/images/jessie_l_64.xpm";
	game->map->trainer_path[1] = "./resources/images/james_64.xpm";
	game->map->floor_path = "./resources/images/floor_64.xpm";
	game->map->wall_path = "./resources/images/stone_64.xpm";
	game->map->exit_path = "./resources/images/stair_64.xpm";
	game->collectible->sprite_path = "./resources/images/pokeball_64.xpm";
	*(game->player->pos) = find_position('P', game);
	return ;
}
