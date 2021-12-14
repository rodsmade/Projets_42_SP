/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:15:15 by roaraujo          #+#    #+#             */
/*   Updated: 2021/10/11 21:13:26 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define FORMATS	"cspdiuxX%"
# define FLAGS		"#0+- ."

typedef struct flags
{
	int	hash;
	int	zero;
	int	plus;
	int	dash;
	int	blank;
	int	precision;
	int	field_width;
}	t_flags;

int				ft_printf(const char *formatString, ...);
unsigned int	print_char(int arg);
unsigned int	print_percent_sign(void);
unsigned int	print_pointer(unsigned long int arg);
unsigned int	print_string(char *arg);
unsigned int	print_signed_decimal(int arg);
unsigned int	print_unsigned_decimal(unsigned int arg);
unsigned int	print_unsigned_hex(unsigned int arg, char xcase, t_flags flags);

#endif