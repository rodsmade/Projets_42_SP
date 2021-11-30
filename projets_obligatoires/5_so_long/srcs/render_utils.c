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
	game->player->sprite_path = "./resources/images/pikachu64.xpm";
	game->player->x_position = game->map->tile_width;
	game->player->y_position = game->map->tile_height;
	game->player->img = mlx_xpm_file_to_image(game->mlx,
								game->player->sprite_path,
								&game->player->width,
								&game->player->height);
	if (game->player->img == NULL)
		flush("MLX_ERROR while creating player image", game);
	return ;
}

void	generate_floor_img(t_game *game)
{
	game->map->floor_path = "./resources/images/floor64.xpm";
	game->map->floor_img = mlx_xpm_file_to_image(game->mlx,
								game->map->floor_path,
								&game->map->tile_x,
								&game->map->tile_y);
	if (game->map->floor_img == NULL)
		flush("MLX_ERROR while creating wall image", game);
	return ;
}

void	generate_wall_img(t_game *game)
{
	game->map->wall_path = "./resources/images/stone64.xpm";
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx,
								game->map->wall_path,
								&game->map->tile_x,
								&game->map->tile_y);
	if (game->map->wall_img == NULL)
		flush("MLX_ERROR while creating wall image", game);
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

void	render_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map->map_2D[i])
	{
		j = 0;
		while(game->map->map_2D[i][j])
		{
			if (game->map->map_2D[i][j] == '1')
				mlx_put_image_to_window(game->mlx,
						game->window->win_ptr,
						game->map->wall_img,
						game->map->tile_width * j,
						game->map->tile_height * i);
			else
				mlx_put_image_to_window(game->mlx,
						game->window->win_ptr,
						game->map->floor_img,
						game->map->tile_width * j,
						game->map->tile_height * i);
			j++;
		}
		i++;
	}
	return ;
}

int		render_everything(t_game *game){
	if (game->window->win_ptr != NULL)
	{
		render_map(game);
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
