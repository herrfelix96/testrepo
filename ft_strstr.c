#include <stdio.h>

char *ft_strstr(char *str, char *to_find);



int main(void)
{
	char *text1 = "find the text here, also here, and ifnotsearch_here";
	char *textToFind = "text";

	char *newposition = ft_strstr(text1, textToFind);

	printf("%s", newposition);
	return 0;
}

char *ft_strstr(char *str, char *to_find)
{	
	int i;
        i = 0;	
	char *str_copy;
        str_copy = str;
	char *found;
	char *new_to_find;
	while(*str != '\0')
	{
		found = str;
		new_to_find = to_find;
		while(*new_to_find - *str == 0)
		{
			if (*(new_to_find+1) == '\0')
				return (found);
			new_to_find++;
			str++;
		}
		i++;
		str = str_copy + 1+i;
	}
	return NULL;
}
