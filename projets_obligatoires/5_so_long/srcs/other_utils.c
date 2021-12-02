#include "so_long.h"

t_coords	find_position(char obj, t_game *game)
{
	// leak maybe ???
	// rodar com debugger
	static size_t	i = -1;
	static size_t	j = -1;
	t_coords		coords;

	while (game->map->map_2D[++i])
	{
		while(game->map->map_2D[i][++j])
		{
			if (game->map->map_2D[i][j] == obj)
			{
				coords.x = i;
				coords.y = j;
			}
		}
	}
	if (i == game->map->rows && j == game->map->cols)
	{
		i = -1;
		j = -1;
		return (find_position(obj, game));
	}
	else
	{
		printf("cade n entrou? x: %i, y: %i\n", coords.x, coords.y);
		return (coords);
	}
}

void	open_window(t_game *game)
{
	game->window->width = game->map->tile_width * game->map->cols;
	game->window->height = game->map->tile_height * game->map->rows;
	game->window->win_ptr = mlx_new_window(game->mlx,
							game->window->width,
							game->window->height,
							"ma fenetre");
	if (game->window->win_ptr == NULL)
		flush("MLX_ERROR while opening new window", game);
	return ;
}
