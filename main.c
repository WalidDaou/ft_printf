#include <stdarg.h>
#include <stdio.h>


int	sum(int count, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, count);
	total = 0;
	i = 0;
	while (i < count)
	{
		total += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (total);
}


void	show(const char *types, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, types);
	i = 0;
	while (types[i])
	{
		if (types[i] == 'd')
			printf("arg %d (int)    = %d\n", i, va_arg(ap, int));
		else if (types[i] == 's')
			printf("arg %d (string) = %s\n", i, va_arg(ap, char *));
		else if (types[i] == 'c')
			printf("arg %d (char)   = %c\n", i, va_arg(ap, int));
		i++;
	}
	va_end(ap);
}


void	twice(int count, ...)
{
	va_list	ap;
	va_list	copy;
	int		i;

	va_start(ap, count);
	va_copy(copy, ap);
	i = 0;
	while (i < count)
		printf("first pass:  %d\n", va_arg(ap, int)), i++;
	i = 0;
	while (i < count)
		printf("second pass: %d\n", va_arg(copy, int)), i++;
	va_end(ap);
	va_end(copy);
}

int	main(void)
{
	printf("sum = %d\n\n", sum(4, 10, 20, 30, 40));
	show("dsc", 42, "hello", 'x');
	printf("\n");
	twice(3, 1, 2, 3);
	return (0);
}