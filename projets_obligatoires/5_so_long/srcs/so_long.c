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

static int	valid_input(int argc, char *map_path);

static int	valid_input(int argc, char *map_path)
{
	int			fd;
	int 		i;
	int			count_EPC[3] = {0, 0, 0};
	char		*line_read;
	char		*backup;
	size_t		row_length;

	// passou qtd certa de argumentos?
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments (only one accepted).\n");
		return (0);
	}

	// extensão fo mapa é .ber?
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
	{
		printf("Error\nMap format invalid (only .ber allowed)\n");
		return (0);
	}

	// abre o mapa e conta o tamanho da primeia linha
	fd = open(map_path, O_RDONLY);
	line_read = ft_get_next_line(fd);
	if (line_read == NULL)
	{
		printf("Error\nMap is empty ! ! !\n");
		return (0);
	}
	printf("retorno primeiro gnl: %s\n", line_read);
	backup = line_read;
	line_read = ft_strtrim(line_read, "\n");
	printf("teste\n");
	row_length = ft_strlen(line_read);

	// se primeiro e último chars são = 1
	if (*line_read != '1' || *(line_read + row_length - 1) != '1')
	{
		printf("Error\nMap must be surrounded by walls. 1\n");
		return (0);
	}
	i = -1;
	while (line_read[++i])
	{
		if (line_read[i] != '1')
		{
			printf("Error\nMap must be surrounded by walls. 2\n");
			return (0);
		}
	}
	
	while (line_read != NULL)
	{
		// printf("Entrou no while\n");
		if (ft_strlen(line_read) != row_length)
		{
			printf("Error\nMap must be rectangular!\n");
			return (0);
		}
		i = -1;
		while (line_read[++i] != '\0')
		{
			if (!ft_strchr(VALID_MAP_CHARS, line_read[i]))
			{
				printf("Error\nMap contains invalid characters (._.)\n");
				return (0);
			}
			if (line_read[i] == 'E')
				count_EPC[0]++;
			if (line_read[i] == 'P')
				count_EPC[1]++;
			if (line_read[i] == 'C')
				count_EPC[2]++;
		}
		backup = line_read;
		line_read = ft_get_next_line(fd);
		if (line_read == NULL)
		{
			i = -1;
			while (backup[++i])
			{
				if (backup[i] != '1')
				{
					printf("Error\nMap must be surrounded by walls. 2\n");
					return (0);
				}
			}
		}

		line_read = ft_strtrim(line_read, "\n");
		if (line_read != NULL && (*line_read != '1' || *(line_read + row_length - 1) != '1'))
		{
			printf("Error\nMap must be surrounded by walls 3\n");
			return (0);
		}
	}
	if (count_EPC[0] < 1 || count_EPC[1] != 1 || count_EPC[2] < 1)
	{
		printf("Error\n");
		if (count_EPC[0] < 1)
			printf("Map has no exits!\n");
		if (count_EPC[1] != 1)
			printf("Map has more than one starting position!\n");
		if (count_EPC[2] < 1)
			printf("Map has no collectibles!\n");
		return (0);
	}
	return (1);
}

int	game_close(t_mlxptrs *mlx_ptrs)
{
	printf("1\n");
	mlx_destroy_window(mlx_ptrs->mlx, mlx_ptrs->window);
	printf("2\n");
	exit (0);
}

int		so_long(int argc, char *argv[])
{
	t_mlxptrs	mlx_ptrs;
	int		x, y;
	void *window2;

	if (!valid_input(argc, argv[1]))
		return (-1);
	printf("Mapa válido! aeeee\n");
	mlx_ptrs.mlx = mlx_init();
	mlx_ptrs.window = mlx_new_window(mlx_ptrs.mlx, 250, 250, "ma fenetre");
	// TODO: check if mlx_ptrs.window == NULL
	window2 = mlx_new_window(mlx_ptrs.mlx, 250, 250, "ma fenetre 2");
	// TODO: check if window2 == NULL
	
	//desenha quadrado amarelo na tela só de zoas
	x=0;
	while (x++ < 50)
	{
		y=0;
		while (y++ < 50)
			mlx_pixel_put(mlx_ptrs.mlx, mlx_ptrs.window, x, y, 0xFFFF00);
	}
	x=0;
	while (x++ < 50)
	{
		y=0;
		while (y++ < 50)
			mlx_pixel_put(mlx_ptrs.mlx, window2, x, y, 0xFFA500);
	}

	// hook um toque do mouse (evento 4 mask 1L<<2) fechar a janela (BAD BAD NOT GOOD)
	mlx_hook(mlx_ptrs.window, 17, 1L<<5, game_close, &mlx_ptrs);

	// loop que captura os eventos
	mlx_loop(mlx_ptrs.mlx);
	mlx_destroy_display(mlx_ptrs.mlx);
	free(mlx_ptrs.mlx);
	return 0;
}