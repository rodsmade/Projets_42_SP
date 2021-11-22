// #include "so_long.h"

// int main(int argc, char *argv[])
// {
// 	so_long(argc, argv);
// 	return (0);
// }


// // CÓDIGO QUE ABRE UMA JANELA E FAZ PUT PIXEL OTIMIZADO:
// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		x, y;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 250, 250, "Hello world!");
// 	img.img = mlx_new_image(mlx, 250, 250);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
	
// 	x=0;
// 	while (x++ < 50)
// 	{
// 		y=0;
// 		while (y++ < 50)
// 			my_mlx_pixel_put(&img, x, y, 0xFFFF00);
// 	}
// 	x=100;
// 	while (x++ < 150)
// 	{
// 		y=100;
// 		while (y++ < 150)
// 			my_mlx_pixel_put(&img, x, y, 0xFFA500);
// 	}

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }


// IMPLEMENTANDO minilibx_key_hook, que faz com que qualquer tecla dispare a função que vc passar.
// a função tem que receber como parâmetro um in que é o código da tecla q foi apertada.
#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Pressed key code: %i\n", keycode);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// captura toda e qualquer tecla na janela aberta, e chama a função key_hook
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}