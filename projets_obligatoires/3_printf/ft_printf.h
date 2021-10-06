#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"

int	ft_printf(const char *formatString, ...);

#endif