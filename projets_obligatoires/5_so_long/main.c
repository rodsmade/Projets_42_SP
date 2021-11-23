#include "so_long.h"

/*
#include "so_long.h"

int main(int argc, char *argv[])
{
	so_long(argc, argv);
	return (0);
}
*/

/*
// CÓDIGO QUE ABRE UMA JANELA E FAZ PUT PIXEL OTIMIZADO:
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_width;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_width + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x, y;

	mlx = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, 250, 250, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return(MLX_ERROR);
	}
	img.img = mlx_new_image(mlx, 250, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_width,
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

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
*/

/*
// IMPLEMENTANDO minilibx_key_hook, que faz com que qualquer tecla dispare a função que vc passar. essa funçao recebe um ponteiro pra uma janela onde ficará escutando o evento, e um parãmetro genérico (void *param) que é um ponteiro para algum parãmetro que você queira passar para dentro da sua funçao arbitrária
// a função arbitrária tem que receber como parâmetro um int que é o código da tecla q foi apertada.
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
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return(MLX_ERROR);
	}
	// captura toda e qualquer tecla na janela aberta, e chama a função key_hook
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
*/

/*
// IMPLEMENTANDO minilibx_mouse_hook, que faz com que o clique dos botões do mouse dispare a função arbitrária que vc passar.
// os cliques possíveis são: botão esquerdo, direito, botão do meio, rolar pra cima e rolar pra baixo (ver cheatsheet)
// a função arbitrária tem que receber como parâmetro um in que é o código do botão q foi apertada, e x e y que são a posição do mouse em pixels na hr q o botão foi clicado.
#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	mouse_hook(int button,int x,int y,void *param)
{
	printf("Mouse button clicked: %i\n", button);
	printf("Mouse position when clicked: (x: %i; y: %i)\n", x, y);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return(MLX_ERROR);
	}
	// captura toda e qualquer tecla na janela aberta, e chama a função key_hook
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
*/


// IMPLEMENTANDO um hook de uma tecla específica para fechar a janela:
#include <mlx.h>
#include <stdio.h>

int RAINBOW[8] = {0xDFFF00, 0xFFBF00, 0xFF7F50, 0xDE3163, 0x8E44AD, 0x6495ED, 0x40E0D0, 0x9FE2BF};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_width;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	t_data	*img_data;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color){
	char	*dst;

	dst = data->addr + (y * data->line_width + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	detect_keystroke(int keycode, t_vars *vars){
	if (keycode == 65361 || keycode == 97)
		printf("Movimento detectado para esquerda!\n");
	if (keycode == 65362 || keycode == 119)
		printf("Movimento detectado para cima!\n");
	if (keycode == 65363 || keycode == 100)
		printf("Movimento detectado para direita!\n");
	if (keycode == 65364 || keycode == 115)
		printf("Movimento detectado para baixo!\n");
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	return (0);
}

int	close_window(t_vars *vars){
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
}

int	resize(int keycode, t_vars *vars){
	printf("Resize request captured; keycode: %i\n", keycode);
}

int	focus_in(t_vars *vars){
	printf("Focus in capturado\n");
}

int	focus_out(t_vars *vars){
	printf("Focus out capturado\n");
}

int	enter_notf(t_vars *vars){
	printf("mouse entrou na janela\n");
}

int	leave_notf(t_vars *vars){
	printf("mouse saiu da janela\n");
}

#include <unistd.h>
int render_everyfin(t_vars *vars){
	int x, y;
	static int i = 0;

	// printa a imagem que eu montei na tela
	x=0;
	while (x++ < vars->win_width)
	{
		y=0;
		while (y++ < vars->win_height)
			my_mlx_pixel_put(vars->img_data, x, y, RAINBOW[i]);
	}
	// i++;
	if (i > 7)
		i = 0;
	if (vars->win != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_data->img, 0, 0);
	// sleep(1);
	return (0);
}

int	expose_hook(t_vars *vars)
{
	static int i=0;
	printf("entrou e agr %i\n", i++);
	render_everyfin(vars);
}

int	main(void){
	t_vars	vars;
	t_data	img;
	int		x, y;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win_height = 250;
	vars.win_width = 250;
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "Ma fenetre");
	if (vars.win == NULL)
	{
		free(vars.win);
		return(MLX_ERROR);
	}
	img.img = mlx_new_image(vars.mlx, vars.win_width, vars.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_width, &img.endian);
	vars.img_data = &img;

	// THEM TENDER HOOKS - CAPTURA DE EVENTOS
	// hook para capturar tecla apertada e decidir se move, se fecha
	mlx_hook(vars.win, 2, 1L<<0, &detect_keystroke, &vars);
	// hook para capturar resize da janela e printar
	// era pra printar coisa no resize mas n consegui fazer isso acontecer ????
	mlx_hook(vars.win, 25, 1L<<18, &resize, &vars);
	// hook para capturar foco in/out da janela
	mlx_hook(vars.win, 9, 1L<<21, &focus_in, &vars);
	mlx_hook(vars.win, 10, 1L<<21, &focus_out, &vars);
	// hook para capturar mouse entrando na janela
	mlx_hook(vars.win, 7, 1L<<4, &enter_notf, &vars);
	// hook para capturar mouse saindo da janela
	mlx_hook(vars.win, 8, 1L<<5, &leave_notf, &vars);
	// hook para fechar janela no x
	mlx_hook(vars.win, 17, 0, &close_window, &vars);

	// expose hook wtf
	mlx_expose_hook (vars.win, &expose_hook, &vars);

	// CAPTURA DO NÃO-EVENTO
	// hook pra executar enquanto nenhum outro hook estiver sendo executado
	mlx_loop_hook(vars.mlx, &render_everyfin, &vars);

	mlx_loop(vars.mlx);

	// // só chega aqui depois do loop se a funçõ mlx_loop_hook estiver implementada !!!!!! se não o loop eh infinito.
	// // ou seja, enquanto tiver uma janela aberta o loop fica rodando; assim que a última janela for fechada, o loop encerra, e o pgm segue rodando dps do loop até o fim.
	// printf("saiu do loop\n");
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

/*
// COMO RENDERIZAR UMA IMAGEM SOCORR
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "../resources/images/Chanut-Role-Playing-Elf.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	win = mlx_new_window(mlx, img_width, img_height, "Ma fenetre");
	if (win == NULL)
	{
		free(win);
		return(MLX_ERROR);
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_loop(mlx);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
*/