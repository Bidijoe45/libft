#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char src[5] = "Hola";
	char dest1[10] = "";
	char dest2[10] = "";
	
	printf("%lu\n", strlcpy(dest1, src, 0));
	printf("%zu\n", ft_strlcpy(dest2, src, 0));

	printf("%s\n", dest1);
	printf("%s\n", dest2);
	
	return (0);
}
