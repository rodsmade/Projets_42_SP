#include "so_long.h"

void	move_left(t_game *game){
	if (game->player->x_position - 50 >= 0)
		game->player->x_position -= 50;
	return ;
}

void	move_up(t_game *game){
	if (game->player->y_position - 50 >= 0)
		game->player->y_position -= 50;
	return ;
}

void	move_right(t_game *game){
	if (game->player->x_position + 50 <= game->window->width - 50)
		game->player->x_position += 50;
	return ;
}

void	move_down(t_game *game){
	if (game->player->y_position + 50 <= game->window->height - 50)
		game->player->y_position += 50;
	return ;
}
