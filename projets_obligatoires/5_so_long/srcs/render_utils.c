#include "so_long.h"

// void	make_map_image(t_game *game){
// 	// char*	sprite_path;
// 	// 1. pega o arquivo do mapa (guardou na ram? acho que sim)
// 	//		> tipo uma matriz [i, j]
// 	// 2. lê linha por linha [while i++ < game->map->rows]
// 	// 3. lê byte por byte [while j++ < game->map->cols]
// 	// se for 1 busca sprite de wall; sprite_path = game->map->wall_path;
// 	// se for 0 busca sprite de floor; sprite_path = game->map->floor_path;
// 	// se for E busca sprite de exit; sprite_path = game->map->exit_path;
// 	// se for P busca sprite de player; sprite_path = game->map->player_path;
// 	// se for C busca sprite de collectible; sprite_path = game->map->collectible_path;
// 	// game->map->img = mlx_xpm_file_to_image(game->mlx, sprite_path, widthgenerica, heightgenerica);
// 	// vixe travei aqui na implementação. segue o bone.
// 	return ;
// }

int		render_window(t_game *game){
	if (game->window->win_ptr != NULL)
	{
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
								game->map->img, 0, 0);
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
								game->player->img,
								game->player->x_position,
								game->player->y_position);
	}
	return (0);
}

int		render_everything(t_game *game){
	if (game->window->win_ptr != NULL){
		mlx_put_image_to_window(game->mlx, game->window->win_ptr, game->player->img,
								game->player->x_position, game->player->y_position);
	}
	return (0);
}
