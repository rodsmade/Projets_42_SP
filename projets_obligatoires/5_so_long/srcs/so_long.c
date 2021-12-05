/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:11:48 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/05 15:43:17 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int argc, char *argv[])
{
	t_game		game;

	// INICIALIZA STRUCT DO JOGO
	printf("DEBUG: 0 - INICIALIZA STRUCT DO JOGO - entrou\n");
	allocate_memory(&game);
	initialise_values(&game);
	printf("DEBUG: 0 - INICIALIZA STRUCT DO JOGO - saiu\n");

	// VALIDA INPUT
	// printf("TESTE - E: %i, P: %i, C: %i\n", game.map->E_count, game.map->P_count, game.map->C_count);
	printf("DEBUG: 1 - VALIDA INPUT - entrou\n");
	input_validation(argc, argv[1], &game);
	printf("DEBUG: 1 - VALIDA INPUT - saiu\n");

	// VALIDA MAPA
	printf("DEBUG: 2 - VALIDA MAPA - entrou\n");
	map_validation(&game);
	printf("DEBUG: 2 - VALIDA MAPA - saiu\n");
	
	// LOAD SPRITES
	printf("DEBUG: 2.5 - LOAD SPRITES - entrou\n");
	load_sprites(&game);
	printf("DEBUG: 2.5 - LOAD SPRITES - saiu\n");
	
	// INICIALIZA MLX
	printf("DEBUG: 3 - INICIALIZA MLX - entrou\n");
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		flush("MLX_ERROR while initialising mlx", &game);
	printf("DEBUG: 3 - INICIALIZA MLX - saiu\n");
	
	// INICIALIZA WINDOW
	printf("DEBUG: 4 - ABRE A JANELA - entrou\n");
	open_window(&game);
	printf("DEBUG: 4 - ABRE A JANELA - saiu\n");
	
	// INICIALIZA IMAGENS
	printf("DEBUG: 5 - CARREGA IMAGENS - entrou\n");
	generate_player_img(&game);
	generate_floor_img(&game);
	generate_wall_img(&game);
	generate_exit_img(&game);
	generate_collectibles_img(&game);
	printf("DEBUG: 5 - CARREGA IMAGENS - saiu\n");

	// HOOKS
	printf("DEBUG: 6 - HOOKS - entrou\n");
	// hook para fechar janela no x
	mlx_hook(game.window->win_ptr, DestroyNotify, NoEventMask, &close_window, &game);
	// hook para capturar tecla apertada e decidir se move, se fecha
	mlx_hook(game.window->win_ptr, KeyPress, KeyPressMask, &detect_keystroke, &game);
	// CAPTURA DO NÃO-EVENTO
	// hook pra executar enquanto nenhum outro hook estiver sendo executado
	mlx_loop_hook(game.mlx, &render_window, &game);
	printf("DEBUG: 6 - HOOKS - saiu\n");

	// FAZ O LOOP
	printf("DEBUG: 7 - FAZ O LOOP - entrou\n");
	mlx_loop(game.mlx);
	printf("DEBUG: 7 - FAZ O LOOP - saiu\n");

	// FINALIZA EXECUÇÃO - destroi tudo, libera memória, xauxau
	printf("DEBUG: 8 - FINALIZA EXECUÇÃO - entrou\n");
	// TODO: destroy all images! a janela já foi. e o display logo em seguida
	game_close(&game);
	printf("DEBUG: 8 - FINALIZA EXECUÇÃO - saiu\n");

	return ;
}