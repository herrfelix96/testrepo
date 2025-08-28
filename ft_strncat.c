#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{	
	char text1[11] = "sample";
	char *text2 = "text";
	unsigned int nb = 2;
	ft_strncat(text1, text2, nb);
	printf("%s", text1);
	return 0;
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	//Find the end of dest
	char *newdest = dest;
	while (*newdest != '\0')
	{
		newdest++;
	}

	// Copy n bytes
	while (*src != '\0' && nb > 0)
	{
		*newdest = *src;
		newdest++;
		src++;
		nb--;
	}

	//Write NUL termination
	*newdest = '\0';
	return dest;
}
