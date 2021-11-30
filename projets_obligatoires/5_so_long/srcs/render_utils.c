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
// 	// vixe travei aqui na implementação. segue o bone.
// 	xpmfile to image pra cada sprite; posiciona de acordo com o índice do char EPC10
//  faz direto put image to window na hora de montar o Mapa, n precisa montar imagem do mapa
// 	return ;
// }

void	generate_player_img(t_game *game)
{
	game->player->sprite_path = "./resources/images/vampire.xpm";
	game->player->x_position = game->window->width / 2;
	game->player->y_position = game->window->height / 2;
	game->player->img = mlx_xpm_file_to_image(game->mlx,
								game->player->sprite_path,
								&game->player->width,
								&game->player->height);
	return ;
}

void	generate_coins_img(t_game *game)
{
	game->collectible->sprite_path = "./resources/images/flask_1.xpm";
// 	"./resources/images/flask_2.xpm"
// 	"./resources/images/flask_3.xpm"
// 	"./resources/images/flask_4.xpm"
	// game->collectible->x_position = 0;
	// game->collectible->y_position = 0;
	game->collectible->img = mlx_xpm_file_to_image(game->mlx,
								game->collectible->sprite_path,
								&game->collectible->width,
								&game->collectible->height);
	return ;
}

// void	render_map(t_game *game)
// {

// 	return ;
// }

int		render_everything(t_game *game){
	if (game->window->win_ptr != NULL)
	{
		// render_map(game);
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
								game->player->img,
								game->player->x_position,
								game->player->y_position);
		// mlx_put_image_to_window(game->mlx, game->window->win_ptr,
		// 						game->collectible->img,
		// 						10,
		// 						10);
	}
	return (0);
}
