#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define FLAGS		"#"

// typedef struct
// {
// 	int	hash;
// 	int	zero;
// 	int	plus;
// 	int	dash;
// 	int	blank;
// 	int	precision;
// 	int	field_width;
// } flags; 

int	ft_printf(const char *formatString, ...);

#endif