#include "so_long.h"

// TODO: mudar o nome do arquivo kakakaka pois flush
int		game_init(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->player = ft_calloc(1, sizeof(t_player));
	if (game->map == NULL || game->window == NULL || game->player == NULL)
		flush("Something wrong happened while allocating memory, closing game. . .", game);
	game->map->C_count = 0;
	game->map->E_count = 0;
	game->map->P_count = 0;
	game->map->rows = 0;
	game->map->tile_width = 50;
	game->map->tile_height = 50;
	return (1);
}

void	flush(char *err_msg, t_game *game)
{
	printf("Error\n%s\n", err_msg);
	if (game->map != NULL)
		free(game->map);
	if (game->window != NULL)
		free(game->window);
	if (game->player != NULL)
		free(game->player);
	exit(0);
}