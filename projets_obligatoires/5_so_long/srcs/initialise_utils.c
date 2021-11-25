#include "so_long.h"

int		game_init(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->player = ft_calloc(1, sizeof(t_player));
	if (game->map == NULL || game->window == NULL || game->player == NULL)
	{
		printf("Error\nSomething wrong happened while allocating memory, aborting game. . .");
		return (0);
	}
	game->map->tile_width = 50;
	game->map->tile_height = 50;
	printf("TESTE\n");
	game->window->width = game->map->tile_width * ft_strlen((char *) game->map->rows_list->content);
	game->window->height = game->map->tile_height * ft_lstsize(game->map->rows_list);
	return (1);
}