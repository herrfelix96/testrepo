#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	int	s;
	int	total_len;
	total_len = 0;
	s = size;
	if (size == 0)
		return (malloc(0));
	while (s > 0)
	{
		total_len = total_len + ft_strlen(strs[s-1]);
		s--;
	}
	printf("%i\n", total_len);

	malloc(total_len + size)
	return NULL;

	
}

int	ft_strlen(char *str)
{
	int	len;
	
	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int main(void)
{
	char *texts[2];
	int size = 2;
	texts[0] = "hello";
	texts[1] = "world";
	char sep = "/";
	char *result = ft_strjoin(size, texts, &sep);
	//printf("%s\n", result);
	return 0;
}
