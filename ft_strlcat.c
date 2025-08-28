#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
	char *text2 = "newtext another text";
	char text1[20] = "sample";
	char *txt2 = text2;
	unsigned int size = (unsigned int)sizeof(text1);
	unsigned int length = ft_strlcat(text1, txt2, size);
	printf("%u\n%s", length, text1);
	printf("\n%i", text1[6]);
	return 0;
}


unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{	
	//Dest length
	unsigned int count;
	count = 0;
	//Src length
	char *src_copy;
	src_copy = src;
	unsigned int srccount;
	srccount = 0;
	while (*src_copy != '\0')
	{
		srccount++;
		src_copy++;
	}

	//Find the end of the dest
	
	char *newdest = dest;
	while(*newdest != '\0')
	{
		newdest++;
		count++;
	}
	unsigned int destcount = count;
	if (count >= size)
		return (srccount+1);

	// Copy from src to dest
	
	while (*src != '\0' && (size-count-1) > 0)
	{
		*newdest = *src;
		newdest++;
		src++;
		count++;
	}

	// Add NUL termination
	*newdest = '\0';

	return (srccount+destcount);
}
