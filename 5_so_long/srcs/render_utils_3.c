/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/12 23:25:55 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_moves_img(t_game *game)
{
	int	x;
	int	y;

	game->draw->img = mlx_new_image(game->mlx, 56, 30);
	if (game->draw->img == NULL)
		flush("MLX_ERROR while creating moves image", 0, game);
	game->draw->addr = mlx_get_data_addr(game->draw->img,
			&game->draw->bits_per_pixel, &game->draw->line_width,
			&game->draw->endian);
	x = -1;
	while (++x < 56)
	{
		y = -1;
		while (++y < 30)
		{
			my_mlx_pixel_put(game->draw, x, y, 0xffffff);
			if (x < 4 || x > 51 || y < 4 || y > 25)
				my_mlx_pixel_put(game->draw, x, y, 0x000000);
		}
	}
	return ;
}

void	generate_trainer_img(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		game->map->trainer_img[i] = mlx_xpm_file_to_image(game->mlx,
				game->map->trainer_path[i],
				&game->map->tile->x,
				&game->map->tile->y);
		if (game->map->trainer_img[i] == NULL)
			flush("MLX_ERROR while creating trainer image", 0, game);
	}
	return ;
}

void	my_mlx_pixel_put(t_draw *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_width + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
	return ;
}

void	print_moves_count(t_game *game)
{
	char	*i_to_a;
	char	*boilerplate;
	char	*joint;

	mlx_put_image_to_window(game->mlx, game->window->win_ptr,
		game->draw->img, 68, 20);
	boilerplate = ft_strdup("");
	i_to_a = ft_itoa(game->player->moves_count);
	joint = ft_strjoin(boilerplate, i_to_a);
	mlx_string_put(game->mlx, game->window->win_ptr, 92, 40, 0x5abdff, joint);
	ft_free_ptr((void *)&i_to_a);
	ft_free_ptr((void *)&boilerplate);
	ft_free_ptr((void *)&joint);
	return ;
}

void	render_ectj(int i, int j, t_game *game)
{
	if (game->map->grid[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->exit_img, TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->collectible->img, TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'T')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->trainer_img[0], TILE_SIZE * j,
			TILE_SIZE * i);
	if (game->map->grid[i][j] == 'J')
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->trainer_img[1], TILE_SIZE * j,
			TILE_SIZE * i);
	return ;
}
