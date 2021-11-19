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

static int	valid_input(int argc, char *map);

static int	valid_input(int argc, char *map)
{
	int		fd;
	int		count_EPC[3] = {0, 0, 0};
	char	*linha_lida;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments (only one accepted).\n");
		return (0);
	}
	fd = open(map, O_RDONLY);
	while ((linha_lida = ft_get_next_line(fd)) != NULL)
	{
		while (*linha_lida != '\0' && *linha_lida != '\n')
		{
			if (!ft_strchr(VALID_MAP_CHARS, *linha_lida))
			{
				printf("Error\nMap contains invalid characters (._.)\n");
				return (0);
			}
			if (*linha_lida == 'E')
				count_EPC[0]++;
			if (*linha_lida == 'P')
				count_EPC[1]++;
			if (*linha_lida == 'C')
				count_EPC[2]++;
			linha_lida++;
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

// int	so_long(int argc, char *argv[])
int		so_long(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x, y;

	if (!valid_input(argc, argv[1]))
		return (-1);
	printf("Mapa válido! aeeee\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 250, 250, "ma fenetre");
	x=0;
	while (x++ < 50)
	{
		y=0;
		while (y++ < 50)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
	}
	mlx_loop(mlx_ptr);
	return 0;
}