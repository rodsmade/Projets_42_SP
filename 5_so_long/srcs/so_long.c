/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:11:48 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/10 15:41:27 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game;

	allocate_memory(&game);
	initialise_values(&game);
	input_validation(argc, argv[1], &game);
	map_validation(&game);
	load_sprites(&game);
	initialise_minilibx(&game);
	generate_images(&game);
	open_window(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
