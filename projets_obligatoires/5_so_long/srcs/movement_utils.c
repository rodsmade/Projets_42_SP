#include "so_long.h"

void	move_left(t_game *game)
{
	game->player->direction = 'j';
	if (game->player->x_position - game->map->tile_width >= 0)
		game->player->x_position -= game->map->tile_width;
	return ;
}

void	move_up(t_game *game)
{
	game->player->direction = 'i';
	if (game->player->y_position - game->map->tile_height >= 0)
		game->player->y_position -= game->map->tile_height;
	return ;
}

void	move_right(t_game *game)
{
	game->player->direction = 'l';
	if (game->player->x_position + game->map->tile_width <= game->window->width - game->map->tile_width)
		game->player->x_position += game->map->tile_width;
	return ;
}

void	move_down(t_game *game)
{
	game->player->direction = 'k';
	if (game->player->y_position + game->map->tile_height <= game->window->height - game->map->tile_height)
		game->player->y_position += game->map->tile_height;
	return ;
}
