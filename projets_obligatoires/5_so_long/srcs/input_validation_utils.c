/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:38 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/09 16:03:36 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_validation(int argc, char *map_path, t_game *game)
{
	if (argc != 2)
		flush("Invalid number of arguments (only one accepted)", 1, game);
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		flush("Map format invalid (only .ber allowed)", 1, game);
	game->map->map_path = ft_strdup(map_path);
	return ;
}
