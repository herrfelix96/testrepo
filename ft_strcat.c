#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main(void)
{
	char *text2 = "text";
	char text1[11] = "sample";
	char *txt2 = text2;
	ft_strcat(text1, txt2);
	printf("%s", text1);
	return 0;
}


char *ft_strcat(char *dest, char *src)
{	
	//Find the end of the dest
	
	char *newdest = dest;
	while(*newdest != '\0')
	{
		newdest++;
	}

	// Copy from src to dest
	
	while (*src != '\0')
	{
		*newdest = *src;
		newdest++;
		src++;
	}

	// Add NUL termination
	
	*newdest = '\0';

	return (dest);
}
