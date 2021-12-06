/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:54 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/07 00:07:50 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	printf("Moves count: %i\n", game->player->moves_count);
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
	printf("Moves count: %i\n", game->player->moves_count);
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
	printf("Moves count: %i\n", game->player->moves_count);
	return ;
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
	printf("Moves count: %i\n", game->player->moves_count);
	return ;
}
