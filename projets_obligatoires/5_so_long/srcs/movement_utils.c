/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:54 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/10 20:09:15 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coords	find_position(char obj, t_game *game)
{
	static t_coords	coords = (t_coords){.x = 0, .y = -1};

	coords.y++;
	while (game->map->grid[coords.x])
	{
		while (game->map->grid[coords.x][coords.y])
		{
			if (game->map->grid[coords.x][coords.y] == obj)
				return (coords);
			coords.y++;
		}
		coords.y = 0;
		coords.x++;
	}
	coords.x = 0;
	coords.y = -1;
	return (coords);
}

void	move_down(t_game *game)
{
	char	next_pos;

	next_pos = game->map->grid[game->player->pos->x + 1][game->player->pos->y];
	game->player->direction = 'k';
	if (next_pos == 'E' && game->player->collec_count == game->map->c_count)
	{
		game->player->pos->x++;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (next_pos == 'T' || next_pos == 'J')
		close_window(game);
	if (next_pos != '1' && next_pos != 'E')
	{
		game->player->pos->x++;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	return ;
}

void	move_left(t_game *game)
{
	char	next_pos;

	next_pos = game->map->grid[game->player->pos->x][game->player->pos->y - 1];
	game->player->direction = 'j';
	if (next_pos == 'E' && game->player->collec_count == game->map->c_count)
	{
		game->player->pos->y--;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (next_pos == 'T' || next_pos == 'J')
		close_window(game);
	if (next_pos != '1' && next_pos != 'E')
	{
		game->player->pos->y--;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	return ;
}

void	move_right(t_game *game)
{
	char	next_pos;

	next_pos = game->map->grid[game->player->pos->x][game->player->pos->y + 1];
	game->player->direction = 'l';
	if (next_pos == 'E' && game->player->collec_count == game->map->c_count)
	{
		game->player->pos->y++;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (next_pos == 'T' || next_pos == 'J')
		close_window(game);
	if (next_pos != '1' && next_pos != 'E')
	{
		game->player->pos->y++;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	return ;
}

void	move_up(t_game *game)
{
	char	next_pos;

	next_pos = game->map->grid[game->player->pos->x - 1][game->player->pos->y];
	game->player->direction = 'i';
	if (next_pos == 'E' && game->player->collec_count == game->map->c_count)
	{
		game->player->pos->x--;
		game->player->moves_count++;
		render_you_won(game);
	}
	if (next_pos == 'T' || next_pos == 'J')
		close_window(game);
	if (next_pos != '1' && next_pos != 'E')
	{
		game->player->pos->x--;
		game->player->moves_count++;
		if (game->map->grid[game->player->pos->x][game->player->pos->y] == 'C')
		{
			game->map->grid[game->player->pos->x][game->player->pos->y] = '0';
			game->player->collec_count++;
		}
	}
	return ;
}
