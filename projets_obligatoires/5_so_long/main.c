#include "so_long.h"

char	pesca_char(t_list *list_head, int linha, int coluna)
{
	int i = 0; //quero ir até quarta linha, seria elemento [3]
	int j = 0; //quero ir até sétimo char, seria elemento [6]
	
	while (i++ < linha)
		list_head = list_head->next;
	return (ft_strdup((char *) (list_head->content))[coluna]);
}

//testando linked lists com get next line
int main(){
	int fd;
	char *map_path = "resources/maps/map1.ber";
	char *linha;
	t_list *list_head;
	int list_size;


// 	new item: cria um elemento a partir de um conteúdo
//	add back: attaches um elemento pronto no final de uma lista
	fd = open(map_path, O_RDONLY);
	linha = ft_get_next_line(fd);
	if (linha != NULL)
		list_head = ft_lstnew(linha);
	list_size = ft_lstsize(list_head);
	printf("list size: %i\n", list_size);
	printf("map columns: %li\n", ft_strlen(list_head->content));
	printf("elemento lido: %s\n", (char *) list_head->content);
	while (linha != NULL)
	{
		linha = ft_get_next_line(fd);
		if (linha == NULL)
			break ;
		ft_lstadd_back(&list_head, ft_lstnew(linha));
	}
	// while(list_head)
	// {
	// 	printf("%s\n", (char *) list_head->content);
	// 	list_head = list_head->next;
	// }
	printf("pesquei um: %c\n", pesca_char(list_head, 3, 1));
	
	return (0);
}