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

#include "mlx.h"

int	valid_input(int argc, char *map)
{
	open()
}

int	so_long(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (!valid_input(argc, argv[1]))
		return (-1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 600, "ma fenetre");
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFF00);
	mlx_loop(mlx_ptr);
	return 0;
}