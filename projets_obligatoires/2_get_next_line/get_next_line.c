#include "get_next_line.h"

static int has_nl_char(char *string)
{
	int i;

	if (!string)
		return (0);
	i = 0;
	while(string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

//	saves_the_rest(read_output, read_return, wheres_the_newline);
static char	*saves_the_rest(char *string, int buff_size)
{
	char	*rest;
	int		i;

	rest = malloc((buff_size + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	i = -1;
	while (++i < buff_size)
		rest[i] = string[i];
	rest[i] = '\0';
	return (rest);
}

// talvez passar o gnl como argumento pq no caso do rest, se achar nl, tem q appendar no gnl_retorno
// no caso do read_output, tem que appendar no gnl_retorno também
char	*appends_to_gnlret(char *gnl_return, char *string, int size)
{
	char *copia;

	copia = malloc(size + 1);
	if (copia == NULL)
		return (NULL);
	ft_strlcpy(copia, string, size);
	if(gnl_return == NULL)
	{
		gnl_return = malloc(sizeof(char));
		if(gnl_return == NULL)
			return (NULL);
		gnl_return = '\0';
	}
	gnl_return = ft_strjoin(gnl_return, copia);
	free(copia);
	return (gnl_return);
}

char *get_next_line(int fd)
{
	char		*gnl_return;	// vou definitivamente precisar de um malloc pq de início eu ñ faço ideia do tamanho desse string !!!! então além de ter q inicializá-lo com malloc (e deps '\0'), vou precisar de uma função que aloca memória conforme necessário !!!11!11!1!   
	char		read_output[BUFFER_SIZE + 1];	// eu ACHO que aqui ñ precisa de malloc pq desse jeito ele já declara um endereço do ponteiro na stack anyways, e o conteúdo eh garbage.
	int			read_return;
	int			wheres_the_newline;
	static char	*rest = NULL;	// esse com ctz precisa de malloc porque tb é imprevisível quanto vai caber nele. ou não? sempre vai ter no máximo BUFFER_SIZE chars?
				// eu posso usar malloc com uma var estática? o ponteiro apontando pra lugar x da Heap vai ficar guardado, mas na próxima execução da função, esse endereço da heap vai ter o que eu preciso q tenha?
				// a resposta é que eu vou tentar fazer sim com o malloc e se der ruim pedir apoio da comunidade

	gnl_return = NULL;
	if((wheres_the_newline = has_nl_char(rest)))
	{
		gnl_return = appends_to_gnlret(gnl_return, rest, wheres_the_newline);
		rest += wheres_the_newline;
		return (gnl_return);
	}

	// ATENÇÃO: AQUI o rest OU é NULL, OU não tem um return dentro !!!111!11!!
	while((read_return = read(fd, read_output, BUFFER_SIZE)) > 0)
	{
		read_output[read_return] = '\0';
		if ((wheres_the_newline = has_nl_char(read_output)))
		{
			// Important: You should always return the line that has been read followed by a ’\n’
			// unless you have reached end of file and there is no ’\n’.
			gnl_return = appends_to_gnlret(gnl_return, read_output, wheres_the_newline);
			rest = saves_the_rest(read_output + wheres_the_newline + 1, read_return - wheres_the_newline);
			return (gnl_return);
		}
		gnl_return = appends_to_gnlret(gnl_return, read_output, BUFFER_SIZE);
	}
	// se saiu do while eh pq atingiu EOF. ainda tem algo a ser lido em read_output?
	// EOF: read_return == 0
	if (read_return != 0)
	// deu algum ruim
		return (NULL);
	read_output[read_return] = '\0';
	if ((wheres_the_newline = has_nl_char(read_output)))
		appends_to_gnlret(gnl_return, read_output, wheres_the_newline);
		// append read_output to gnl_return
	return (gnl_return);
}