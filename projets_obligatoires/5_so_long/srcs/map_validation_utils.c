/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:47 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/10 20:08:38 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_validation(char *map_str, t_game *game)
{
	while (*map_str)
	{
		if (*map_str == 'C')
			game->map->c_count++;
		if (*map_str == 'E')
			game->map->e_count++;
		if (*map_str == 'P')
			game->map->p_count++;
		if (*map_str != '\n' && !ft_strchr(VALID_MAP_CHARS, *map_str))
			flush("Invalid char found, only EPC10MJ allowed", 1, game);
		map_str++;
	}
	if (game->map->c_count < 1)
		flush("Map has no collectibles", 1, game);
	if (game->map->e_count < 1)
		flush("Map has no exit", 1, game);
	if (game->map->e_count > 1)
		flush("Map must have only one exit", 1, game);
	if (game->map->p_count < 1)
		flush("Map has no player", 1, game);
	if (game->map->p_count > 1)
		flush("Map must have only one player", 1, game);
	return ;
}

static void	copy_map(char *linear_map, t_game *game)
{
	int		fd;
	int		read_count;
	char	*buffer;

	fd = open(game->map->map_path, O_RDONLY);
	if (fd < 0)
		flush("Error while opening file", 1, game);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		flush("Error while allocating memory for map", 1, game);
	buffer[BUFFER_SIZE] = '\0';
	ft_bzero(linear_map, 500);
	read_count = read(fd, buffer, BUFFER_SIZE);
	while (read_count > 0)
	{
		buffer[read_count] = '\0';
		ft_strlcat(linear_map, buffer, 500);
		read_count = read(fd, buffer, BUFFER_SIZE);
	}
	if (!*linear_map)
		flush("Map is e m p t y !", 1, game);
	if (close(fd) == -1)
		flush("Error while closing fd", 1, game);
	free(buffer);
	return ;
}

static int	is_rectangular(t_game *game)
{
	int	i;

	game->map->cols = ft_strlen(game->map->grid[0]);
	i = -1;
	while (game->map->grid[++i])
	{
		if (ft_strlen(game->map->grid[i]) != game->map->cols)
			return (0);
		game->map->rows++;
	}
	if (game->map->cols > 20 || game->map->rows > 11)
		flush("Map too big! (max 11 rows x 20 cols)", 1, game);
	return (1);
}

static int	surrounded_by_walls(t_game *game)
{
	size_t	i;

	i = -1;
	while (game->map->grid[++i])
	{
		if (game->map->grid[i][0] != '1'
			|| game->map->grid[i][game->map->cols - 1] != '1')
			return (0);
	}
	i = -1;
	while (++i < game->map->cols)
	{
		if (game->map->grid[0][i] != '1'
			|| game->map->grid[game->map->rows - 1][i] != '1')
			return (0);
	}
	return (1);
}

void	map_validation(t_game *game)
{
	char	linear_map[500];

	copy_map(linear_map, game);
	char_validation(linear_map, game);
	ft_free_ptr((void *)&game->map->grid);
	game->map->grid = ft_split(linear_map, '\n');
	if (game->map->grid == NULL)
		flush("Error while allocating memory for map", 1, game);
	if (!is_rectangular(game))
		flush("Map must be square/rectangular", 1, game);
	if (!surrounded_by_walls(game))
		flush("Map must be surrounded by walls", 1, game);
	return ;
}
