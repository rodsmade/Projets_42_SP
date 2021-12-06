/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:54 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 19:48:44 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	// TODO: investigar pq que segurando uma tecla, o move seguinte ñ é computado !!!!
	game->player->direction = 'j';
	if (game->map->grid[game->player->pos->x][game->player->pos->y - 1] == 'E'
		&& game->player->collec_count == game->map->C_count)
	{
		game->player->pos->y--;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (game->map->grid[game->player->pos->x][game->player->pos->y - 1] != '1'
		&& game->map->grid[game->player->pos->x][game->player->pos->y - 1] != 'E')
	{
		game->player->pos->y--;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	printf("Moves count: %i\n", game->player->moves_count);
	return ;
}

void	move_up(t_game *game)
{
	game->player->direction = 'i';
	if (game->map->grid[game->player->pos->x - 1][game->player->pos->y] == 'E'
			&& game->player->collec_count == game->map->C_count)
	{
		game->player->pos->x--;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (game->map->grid[game->player->pos->x - 1][game->player->pos->y] != '1'
		&& game->map->grid[game->player->pos->x - 1][game->player->pos->y] != 'E')
	{
		game->player->pos->x--;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	printf("Moves count: %i\n", game->player->moves_count);
	return ;
}

void	move_right(t_game *game)
{
	game->player->direction = 'l';
	if (game->map->grid[game->player->pos->x][game->player->pos->y + 1] == 'E'
			&& game->player->collec_count == game->map->C_count)
	{
		game->player->pos->y++;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (game->map->grid[game->player->pos->x][game->player->pos->y + 1] != '1'
		&& game->map->grid[game->player->pos->x][game->player->pos->y + 1] != 'E')
	{
		game->player->pos->y++;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	printf("Moves count: %i\n", game->player->moves_count);
	return ;
}

void	move_down(t_game *game)
{
	game->player->direction = 'k';
	if (game->map->grid[game->player->pos->x + 1][game->player->pos->y] == 'E'
			&& game->player->collec_count == game->map->C_count)
	{
		game->player->pos->x++;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (game->map->grid[game->player->pos->x + 1][game->player->pos->y] != '1'
		&& game->map->grid[game->player->pos->x + 1][game->player->pos->y] != 'E')
	{
		game->player->pos->x++;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	printf("Moves count: %i\n", game->player->moves_count);
	return ;
}
