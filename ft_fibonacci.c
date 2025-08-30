#include <stdio.h>

int	ft_fibonacci(int index);

int main(void)
{
	int fib_index = 0;
	printf("%i\n", ft_fibonacci(fib_index));
	return 0;
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 1)
		return (1);
	if (index > 1)
	{
	index = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}
	return (index);
}
