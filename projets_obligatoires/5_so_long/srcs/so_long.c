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

static int	input_is_valid(int argc, char *map_path, t_game *game)
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

int		surrounded_by_walls(char* str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1')
		{
			if (*str != '1' || str[ft_strlen(str - 1)] != '1')
			// TODO: com a nova implementação de flush isso aqui perde o sentido, revisitar
				printf("Error\nMap must be surrounded by walls (1's)\n");
			return (0);
		}
	}
	return (1);
}

int		valid_map(t_game *game)
// ideia: usar a função exit() dentro de uma função tipo flush("String de erro") que vai printar a string de erro, desalocar tudo que tiver de memória, e dar exit() -- it's a system call not a C language keyword.
{
	int		fd;
	int		bytes_read;
	char 	*buffer;
	char	*map_file;

	fd = open(game->map->map_path, O_RDONLY);
	if (fd < 0)
		flush("nError while opening file", game);
	map_file = ft_strdup("");
	if (map_file == NULL)
		flush("Error while allocating memory for map", game);
	while(bytes_read > 0)
	{
		map_read = ft_strjoin(map_read, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (!*map_read)
		flush("Map is e m p t y !", game);
	if (!surrounded_by_walls(map_read))
		flush("Map must be surrounded by walls");

	// game->map->cols = ft_strlen(ft_strtrim(map_read, "\n"));
	if (!close(fd))
		flush("Error while closing fd", game);
	while ()

}

int		so_long(int argc, char *argv[])
{
	t_game		game;

	// INICIALIZA STRUCT DO JOGO
	printf("DEBUG: 0 - INICIALIZA STRUCT DO JOGO - entrou\n");
	// TODO: com a nova implementação de flush(), isso aqui teria que ser passo 0, e no init bota tudo como NULL, que no flush testa e se != null, dá free.
	if (!game_init(&game))
		return (-1);
	printf("DEBUG: 0 - INICIALIZA STRUCT DO JOGO - saiu\n");


	// VALIDA INPUT
	printf("DEBUG: 1 - VALIDA INPUT - entrou\n");
	if (!input_is_valid(argc, argv[1], &game))
		return (-1);
	printf("DEBUG: 1 - VALIDA INPUT - saiu\n");

	// VALIDA MAPA
	printf("DEBUG: 2 - VALIDA MAPA - entrou\n");
	if (!valid_map(&game))
		return(0);
	printf("DEBUG: 2 - VALIDA MAPA - saiu\n");

	// INICIALIZA MLX
	printf("DEBUG: 3 - INICIALIZA MLX - entrou\n");
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (MLX_ERROR);
	printf("DEBUG: 3 - INICIALIZA MLX - saiu\n");
	
	// INICIALIZA WINDOW
	printf("DEBUG: 4 - INICIALIZA WINDOW - entrou\n");
	game.window->win_ptr = mlx_new_window(game.mlx,
							game.window->width,
							game.window->height,
							"ma fenetre");
	if (game.window->win_ptr == NULL)
	{
		free(game.window->win_ptr);
		return(MLX_ERROR);
	}
	printf("DEBUG: 4 - INICIALIZA WINDOW - saiu\n");
	
	// INICIALIZA PLAYER
	printf("DEBUG: 5 - INICIALIZA PLAYER - entrou\n");
	game.player->sprite_path = "./resources/images/lucca_sprites_1.xpm";
	game.player->x_position = game.window->width / 2;
	game.player->y_position = game.window->height / 2;
	game.player->img = mlx_xpm_file_to_image(game.mlx,
								game.player->sprite_path,
								&game.player->width,
								&game.player->height);
	printf("DEBUG: 5 - INICIALIZA PLAYER - saiu\n");

	// HOOKS
	printf("DEBUG: 6 - HOOKS - entrou\n");
	// hook para fechar janela no x
	mlx_hook(game.window->win_ptr, 17, 0, &close_window, &game);
	// hook para capturar tecla apertada e decidir se move, se fecha
	mlx_hook(game.window->win_ptr, 2, 1L<<0, &detect_keystroke, &game);
	// CAPTURA DO NÃO-EVENTO
	// hook pra executar enquanto nenhum outro hook estiver sendo executado
	mlx_loop_hook(game.mlx, &render_everything, &game);
	printf("DEBUG: 6 - HOOKS - saiu\n");

	// FAZ O LOOP
	printf("DEBUG: 7 - FAZ O LOOP - entrou\n");
	mlx_loop(game.mlx);
	printf("DEBUG: 7 - FAZ O LOOP - saiu\n");

	// FINALIZA EXECUÇÃO - destroi tudo, libera memória, xauxau
	printf("DEBUG: 8 - FINALIZA EXECUÇÃO - entrou\n");
	// TODO: destroy all images! a janela já foi. e o display logo em seguida
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	printf("DEBUG: 8 - FINALIZA EXECUÇÃO - saiu\n");

	return 0;
}