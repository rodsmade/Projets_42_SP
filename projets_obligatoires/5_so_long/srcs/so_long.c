/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:11:48 by roaraujo          #+#    #+#             */
/*   Updated: 2021/11/17 21:13:38 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

static int	valid_input(char *map);

static int	valid_input(char *map)
{
	/*
	◦ The map must be composed of only 5 possible characters: 0 for an empty
		space, 1 for a wall, C for a collectible, E for map exit and P for the player’s
		starting position.
	◦ The map must be closed/surrounded by walls, if not the program must return an error.
	◦ Map must have at least one exit, one collectible, and one starting position.
	◦ You don’t need to check if there’s a valid path in the map.
	◦ The map must be rectangular.
	◦ You must be able to parse any kind of map, as long as it respects the rules of the map.
	*/
	int fd;
	char *linha_lida;
	// char *resources_path;

	// resources_path = "../resources/maps/";
	// resources_path = ft_strjoin(resources_path, map);
	// printf("Resources path depois do join: %s\n", resources_path);
	fd = open(map, O_RDONLY);
	printf("Linha lida: %s\n", linha_lida = ft_get_next_line(fd));
	// read_one_by_one{
	// 	if 'E' then exit_count++;
	// 	if 'P' then start_pos++;
	// 	if 'C' then collect_count++;
	// }
	// if (exit_count < 1 || collect_count < 1 || start_pos != 1)
	// {
	// 	printf("Error\n");
	// 	if (exit_count < 1)
	// 		printf("Map has no exits!\n");
	// 	if (collect_count < 1)
	// 		printf("Map has no collectibles!\n");
	// 	if (start_pos != 1)
	// 		printf("Map has more than one starting position!\n");
	// 	return (-1);
	// }
	if (linha_lida == NULL)
		return(0);
	return (1);
}

// int	so_long(int argc, char *argv[])
int		so_long(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x, y;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments (pass only one).\n");
		return (-1);
	}
	if (!valid_input(argv[1]))
	{
		printf("Mapa invalido!\n");
		return (-1);
	}
	printf("Mapa válido! aeeee\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1255, 600, "ma fenetre");
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