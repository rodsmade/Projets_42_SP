/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:11:48 by roaraujo          #+#    #+#             */
/*   Updated: 2021/11/18 22:01:56 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int args_check(int argc)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments (only one accepted).\n");
		return (0);
	}
	return(1);
}

static int	is_ber(char *map_path)
{
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
	{
		printf("Error\nMap format invalid (only .ber allowed)\n");
		return (0);
	}
	return (1);
}

static int	input_validation(int argc, char *map_path, t_game *game)
{
	// passou qtd certa de argumentos?
	if (!args_check(argc))
		return (0);
	// extensão do mapa é .ber?
	if (!is_ber(map_path))
		return (0);
	game->map->map_path = ft_strdup(map_path);
	return (1);
}

int		surrounded_by_walls(t_game *game)
{
	size_t	i;

	i = -1;
	// checa paredes laterais
	while (game->map->map_2D[++i])
	{
		if (game->map->map_2D[i][0] != '1'
			|| game->map->map_2D[i][game->map->cols - 1] != '1')
			return (0);
	}
	i = -1;
	// checa paredes de cima e de baixo
	while (++i < game->map->cols)
	{
		if (game->map->map_2D[0][i] != '1'
			|| game->map->map_2D[game->map->rows - 1][i] != '1')
			return (0);
	}
	return (1);
}

void	char_validation(char *map_str, t_game *game)
{
	while(*map_str)
	{
		if (*map_str == 'C')
			game->map->C_count++;
		if (*map_str == 'E')
			game->map->E_count++;
		if (*map_str == 'P')
			game->map->P_count++;
		if (*map_str != '\n' && !ft_strchr(VALID_MAP_CHARS, *map_str))
			flush("Invalid char found, only EPC10 allowed", game);
		map_str++;
	}
	if (game->map->C_count < 1)
		flush("Map has no collectibles", game);
	if (game->map->E_count < 1)
		flush("Map has no exit", game);
	if (game->map->P_count != 1)
		flush("Map must have no more and no less than one player", game);
	return ;
}

int		is_rectangular(t_game *game)
{
	int i;

	game->map->cols = ft_strlen(game->map->map_2D[0]);
	i = -1;
	while(game->map->map_2D[++i])
	{
		if (ft_strlen(game->map->map_2D[i]) != game->map->cols)
			return (0);
		game->map->rows++;
	}
	return (1);
}

void	map_validation(t_game *game)
{
	int		fd;
	char 	*buffer;
	char	*buffer_join;

	fd = open(game->map->map_path, O_RDONLY);
	if (fd < 0)
		flush("nError while opening file", game);
	buffer_join = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer_join == NULL || buffer == NULL)
		flush("Error while allocating memory for map", game);
	buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
	while(buffer[0] > 0)
	{
		buffer_join = ft_strjoin(buffer_join, buffer);
		buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
	}
	if (!*buffer_join)
		flush("Map is e m p t y !", game);
	char_validation(buffer_join, game);
	// monta o MAPA
	game->map->map_2D = ft_split(buffer_join, '\n');
	if (game->map->map_2D == NULL)
		flush("Error while allocating memory for map", game);
	// valida linha por linha
	if (!is_rectangular(game))
		flush("Map must be square/rectangular", game);
	if (!surrounded_by_walls(game))
		flush("Map must be surrounded by walls", game);
	if (close(fd) == -1)
		flush("Error while closing fd", game);
	return ;
}

void	open_window(t_game *game)
{
	game->window->width = game->map->tile_width * game->map->cols;
	game->window->height = game->map->tile_height * game->map->rows;
	game->window->win_ptr = mlx_new_window(game->mlx,
							game->window->width,
							game->window->height,
							"ma fenetre");
	if (game->window->win_ptr == NULL)
		flush("MLX_ERROR while opening new window", game);
	return ;
}

void	so_long(int argc, char *argv[])
{
	t_game		game;

	// TODO: refatorar tirando todos os IFs porque eles provavelmente são inúteis dps q implementei o exit(), checar caso a caso
	// INICIALIZA STRUCT DO JOGO
	printf("DEBUG: 0 - INICIALIZA STRUCT DO JOGO - entrou\n");
	game_init(&game);
	printf("DEBUG: 0 - INICIALIZA STRUCT DO JOGO - saiu\n");

	// VALIDA INPUT
	printf("DEBUG: 1 - VALIDA INPUT - entrou\n");
	input_validation(argc, argv[1], &game);
	printf("DEBUG: 1 - VALIDA INPUT - saiu\n");

	// VALIDA MAPA
	printf("DEBUG: 2 - VALIDA MAPA - entrou\n");
	map_validation(&game);
	printf("DEBUG: 2 - VALIDA MAPA - saiu\n");

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
	mlx_hook(game.window->win_ptr, DESTROY_NOTIFY, NO_EVENT_MASK, &close_window, &game);
	// hook para capturar tecla apertada e decidir se move, se fecha
	mlx_hook(game.window->win_ptr, KEY_PRESS, KEY_PRESS_MASK, &detect_keystroke, &game);
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