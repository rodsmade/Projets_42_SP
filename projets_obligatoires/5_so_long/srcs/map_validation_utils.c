#include "so_long.h"

void		input_validation(int argc, char *map_path, t_game *game)
{
	// passou qtd certa de argumentos?
	if (argc != 2)
		flush("Invalid number of arguments (only one accepted)", game);
	// extensão do mapa é .ber?
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		flush("Map format invalid (only .ber allowed)", game);
	game->map->map_path = ft_strdup(map_path);
	return ;
}

static void	char_validation(char *map_str, t_game *game)
{
	while(*map_str)
	{
		if (*map_str == 'C')
			game->map->C_count++;
		if (*map_str == 'E')
			game->map->E_count++;
		if (*map_str == 'P')
			game->map->P_count++;
		if (*map_str != '\n' && !ft_strchr(VALID_MAP_CHARS, *map_str))
			flush("Invalid char found, only EPC10 allowed", game);
		map_str++;
	}
	if (game->map->C_count < 1)
		flush("Map has no collectibles", game);
	if (game->map->E_count < 1)
		flush("Map has no exit", game);
	if (game->map->P_count != 1)
		flush("Map must have no more and no less than one player", game);
	return ;
}

static int	surrounded_by_walls(t_game *game)
{
	size_t	i;

	i = -1;
	// checa paredes laterais
	while (game->map->map_2D[++i])
	{
		if (game->map->map_2D[i][0] != '1'
			|| game->map->map_2D[i][game->map->cols - 1] != '1')
			return (0);
	}
	i = -1;
	// checa paredes de cima e de baixo
	while (++i < game->map->cols)
	{
		if (game->map->map_2D[0][i] != '1'
			|| game->map->map_2D[game->map->rows - 1][i] != '1')
			return (0);
	}
	return (1);
}

static int	is_rectangular(t_game *game)
{
	int i;

	game->map->cols = ft_strlen(game->map->map_2D[0]);
	i = -1;
	while(game->map->map_2D[++i])
	{
		if (ft_strlen(game->map->map_2D[i]) != game->map->cols)
			return (0);
		game->map->rows++;
	}
	return (1);
}

void	map_validation(t_game *game)
{
	int		fd;
	char 	*buffer;
	char	*buffer_join;

	fd = open(game->map->map_path, O_RDONLY);
	if (fd < 0)
		flush("nError while opening file", game);
	buffer_join = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer_join == NULL || buffer == NULL)
		flush("Error while allocating memory for map", game);
	buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
	while(buffer[0] > 0)
	{
		buffer_join = ft_strjoin(buffer_join, buffer);
		buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
	}
	if (!*buffer_join)
		flush("Map is e m p t y !", game);
	char_validation(buffer_join, game);
	// monta o MAPA
	game->map->map_2D = ft_split(buffer_join, '\n');
	if (game->map->map_2D == NULL)
		flush("Error while allocating memory for map", game);
	// valida linha por linha
	if (!is_rectangular(game))
		flush("Map must be square/rectangular", game);
	if (!surrounded_by_walls(game))
		flush("Map must be surrounded by walls", game);
	if (close(fd) == -1)
		flush("Error while closing fd", game);
	return ;
}
