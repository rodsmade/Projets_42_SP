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

int		detect_keystroke(int keycode, t_game *game){
	if (keycode == 65361 || keycode == 97)
			move_left(game);
	if (keycode == 65362 || keycode == 119)
			move_up(game);
	if (keycode == 65363 || keycode == 100)
			move_right(game);
	if (keycode == 65364 || keycode == 115)
			move_down(game);
	if (keycode == XK_Escape)
		close_window(game);
	else
		mlx_clear_window(game->mlx, game->window->win_ptr);
	return (0);
}
