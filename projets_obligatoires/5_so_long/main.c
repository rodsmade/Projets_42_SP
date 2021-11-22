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


// // IMPLEMENTANDO minilibx_key_hook, que faz com que qualquer tecla dispare a função que vc passar. essa funçao recebe um ponteiro pra uma janela onde ficará escutando o evento, e um parãmetro genérico (void *param) que é um ponteiro para algum parãmetro que você queira passar para dentro da sua funçao arbitrária
// // a função arbitrária tem que receber como parâmetro um int que é o código da tecla q foi apertada.
// #include <mlx.h>
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Pressed key code: %i\n", keycode);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	// captura toda e qualquer tecla na janela aberta, e chama a função key_hook
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

// // IMPLEMENTANDO minilibx_mouse_hook, que faz com que o clique dos botões do mouse dispare a função arbitrária que vc passar.
// // os cliques possíveis são: botão esquerdo, direito, botão do meio, rolar pra cima e rolar pra baixo (ver cheatsheet)
// // a função arbitrária tem que receber como parâmetro um in que é o código do botão q foi apertada, e x e y que são a posição do mouse em pixels na hr q o botão foi clicado.
// #include <mlx.h>
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	mouse_hook(int button,int x,int y,void *param)
// {
// 	printf("Mouse button clicked: %i\n", button);
// 	printf("Mouse position when clicked: (x: %i; y: %i)\n", x, y);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	// captura toda e qualquer tecla na janela aberta, e chama a função key_hook
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

// IMPLEMENTANDO um hook de uma tecla específica para fechar a janela:
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		x, y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 250, 250, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 250, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	x=0;
	while (x++ < 50)
	{
		y=0;
		while (y++ < 50)
			my_mlx_pixel_put(&img, x, y, 0xFFFF00);
	}
	x=100;
	while (x++ < 150)
	{
		y=100;
		while (y++ < 150)
			my_mlx_pixel_put(&img, x, y, 0xFFA500);
	}

	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}