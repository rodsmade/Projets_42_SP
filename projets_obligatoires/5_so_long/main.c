#include "so_long.h"


int main(int argc, char *argv[])
{
	so_long(argc, argv);
	return (0);
}



// // CÓDIGO QUE ABRE UMA JANELA E FAZ PUT PIXEL OTIMIZADO:
// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_width;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_width + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		x, y;

// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 		return (MLX_ERROR);
// 	mlx_win = mlx_new_window(mlx, 250, 250, "Hello world!");
// 	if (mlx_win == NULL)
// 	{
// 		free(mlx_win);
// 		return(MLX_ERROR);
// 	}
// 	img.img = mlx_new_image(mlx, 250, 250);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_width,
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
// 	mlx_destroy_display(mlx);
// 	free(mlx);
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
// 	if (vars.mlx == NULL)
// 		return (MLX_ERROR);
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	if (vars.win == NULL)
// 	{
// 		free(vars.win);
// 		return(MLX_ERROR);
// 	}
// 	// captura toda e qualquer tecla na janela aberta, e chama a função key_hook
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

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

/*
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
		close_window(vars);
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
*/

/*
// COMO RENDERIZAR UMA IMAGEM SOCORR
#include <mlx.h>

typedef struct	s_player{
	char	*sprite_path;
	void	*img;
	int		x_position;
	int		y_position;
	int		width;
	int		height;
}				t_player;

// acho q essa t_img na vdd só precisa se for usar aquela função de pixel put otimizada my_pixel_put
// typedef struct	s_img{
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_width;
// 	int		endian;
// }				t_img;

typedef struct	s_win{
	void	*win_ptr;
	int		width;
	int		height;
}				t_win;

typedef struct	s_vars{
	void		*mlx;
	t_win		*win;
	t_player	*player;
}				t_vars;

// TODO: criar struct do mapa que guarda a qtd de linhas e colunas pra caluclar altura e largura da janela 
typedef struct	s_map{
	int		cols;
	int		rows;
	char	*floor_path;
	char	*wall_path;
	char	*collectible_path;
	char	*exit_path;
}				t_map;

static int	close_window(t_vars *global){
	mlx_destroy_window(global->mlx, global->win->win_ptr);
	global->win->win_ptr = NULL;
}

static void move_left(t_vars *global)
{
	if (global->player->x_position - 50 >= 0)
		global->player->x_position -= 50;
	return ;
}

static void move_up(t_vars *global)
{
	if (global->player->y_position - 50 >= 0)
		global->player->y_position -= 50;
	return ;
}

static void move_right(t_vars *global)
{
	if (global->player->x_position + 50 <= global->win->width - 50)
		global->player->x_position += 50;
	return ;
}

static void move_down(t_vars *global)
{
	if (global->player->y_position + 50 <= global->win->height - 50)
		global->player->y_position += 50;
	return ;
}

int	detect_keystroke(int keycode, t_vars *global){
	if (keycode == 65361 || keycode == 97)
			move_left(global);
	if (keycode == 65362 || keycode == 119)
			move_up(global);
	if (keycode == 65363 || keycode == 100)
			move_right(global);
	if (keycode == 65364 || keycode == 115)
			move_down(global);
	if (keycode == XK_Escape)
		close_window(global);
	else
		mlx_clear_window(global->mlx, global->win->win_ptr);
	return (0);
}

int render_everything(t_vars *global){
	if (global->win->win_ptr != NULL)
		mlx_put_image_to_window(global->mlx, global->win->win_ptr, global->player->img,
								global->player->x_position, global->player->y_position);
	// sleep(1);
	return (0);
}

int	main(void)
{
	t_player	player;
	t_win	win;
	t_vars	global;

	// startando a struct
	// TODO: criar uma função "initialize" que malloca as structs dependentes e também inicializa tudo (calloc!!!!)
	global.win = &win;
	global.player = &player;

	// init mlx
	global.mlx = mlx_init();
	if (global.mlx == NULL)
		return (MLX_ERROR);

	// init window
	global.win->win_ptr = mlx_new_window(global.mlx, 500,
										500, "Ma fenetre");
	if (global.win->win_ptr == NULL)
	{
		free(global.win->win_ptr);
		return(MLX_ERROR);
	}
	global.win->width = 500;
	global.win->height = 500;

	// init player
	global.player->sprite_path = "./resources/images/lucca_sprites_1.xpm";
	global.player->x_position = global.win->width / 2;
	global.player->y_position = global.win->height / 2;
	global.player->img = mlx_xpm_file_to_image(global.mlx, global.player->sprite_path,
								&global.player->width, &global.player->height);

	// printf("teste\n");
	// HOOKS
	// hook para fechar janela no x
	mlx_hook(global.win->win_ptr, 17, 0, &close_window, &global);
	// hook para capturar tecla apertada e decidir se move, se fecha
	mlx_hook(global.win->win_ptr, 2, 1L<<0, &detect_keystroke, &global);
	// CAPTURA DO NÃO-EVENTO
	// hook pra executar enquanto nenhum outro hook estiver sendo executado
	mlx_loop_hook(global.mlx, &render_everything, &global);

	mlx_loop(global.mlx);

	mlx_destroy_display(global.mlx);
	free(global.mlx);
}
*/

// // TESTANDO GRAVAR O MAPA COM LINKED rows_list#include "so_long.h"
// char	catch_char(t_list *list_head, int linha, int coluna)
// {
// 	int i = 0; //quero ir até quarta linha, seria elemento [3]
// 	int j = 0; //quero ir até sétimo char, seria elemento [6]
	
// 	while (i++ < linha)
// 		list_head = list_head->next;
// 	return (ft_strdup((char *) (list_head->content))[coluna]);
// }

// //testando linked lists com get next line
// int main(){
// 	int fd;
// 	char *map_path = "resources/maps/map1.ber";
// 	char *linha;
// 	t_list *list_head;
// 	int list_size;


// // 	new item: cria um elemento a partir de um conteúdo
// //	add back: attaches um elemento pronto no final de uma lista
// 	fd = open(map_path, O_RDONLY);
// 	linha = ft_get_next_line(fd);
// 	if (linha != NULL)
// 		list_head = ft_lstnew(linha);
// 	printf("elemento lido: %s\n", (char *) list_head->content);
// 	while (linha != NULL)
// 	{
// 		linha = ft_get_next_line(fd);
// 		if (linha == NULL)
// 			break ;
// 		ft_lstadd_back(&list_head, ft_lstnew(linha));
// 	}
// 	// while(list_head)
// 	// {
// 	// 	printf("%s\n", (char *) list_head->content);
// 	// 	list_head = list_head->next;
// 	// }
// 	list_size = ft_lstsize(list_head);
// 	printf("list size: %i\n", list_size);
// 	printf("map columns: %li\n", ft_strlen(list_head->content));
// 	printf("pesquei um: %c\n", catch_char(list_head, 3, 6));
	
// 	return (0);
// }