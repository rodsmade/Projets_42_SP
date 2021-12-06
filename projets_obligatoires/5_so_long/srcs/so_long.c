/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:11:48 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 21:49:13 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int argc, char *argv[])
{
	t_game		game;

	allocate_memory(&game);
	initialise_values(&game);
	input_validation(argc, argv[1], &game);
	map_validation(&game);
	load_sprites(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		flush("MLX_ERROR while initialising mlx", &game);
	open_window(&game);
	generate_images(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	game_close(&game);
	return ;
}
