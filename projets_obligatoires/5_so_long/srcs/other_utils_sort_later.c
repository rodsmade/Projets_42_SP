#include "so_long.h"

int	close_window(t_game *game){
	mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
}