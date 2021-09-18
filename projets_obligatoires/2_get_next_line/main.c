/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:13:16 by roaraujo          #+#    #+#             */
/*   Updated: 2021/09/18 10:14:09 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// FILE, fopen()
#include <stdio.h> // printf()
#include <stdlib.h> // free()

char	*g_file_name = "./only_skin";
FILE	*g_fp;

char	*get_next_line(int fd);

int main()
/*
*	- Function main() opens a file in a file descriptor (fd / _fileno).
*	- This file contains text meant to be read one line at a time by means
*	of function get_next_line().
*	- Each call must return a string of chars ended tied up with a '\n', so long
*	as there is one. Empty lines are returned all the same (one single '\n' per call).
*	- main() proceeds to print the resulting line read by get_next_line(),
*	looping throughout the file.
*	- Once EOF is reached, get_next_line() returns NULL and stops execution;
*	main() closes the file, and the program comes to a halt.
**/
{
	char	*linha;
	int		i = 0;

	g_fp = fopen(g_file_name, "r");
	
	while((linha = get_next_line(g_fp->_fileno)) != NULL)
	{
		printf("Line %i >>> %s", i++, linha);
		free(linha);
	}
	
	fclose(g_fp);
	return (0);
}
