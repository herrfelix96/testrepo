#include <stdio.h>
#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int main()
{
	char text[] = "Hello\nHow are you?";
	char* ptr = text;
	ft_putstr_non_printable(ptr);
	return (0);
}


void	ft_putstr_non_printable(char *str)
{
	char *ptr = str;
	char hex[2];
	char digits[] = "0123456789abcdef";

	while(*ptr)
	{
		if(!((*ptr >= 0x00 && *ptr <= 0x1F) || *ptr == 0x7F))
				{
				write(1, ptr, 1);
				}
		else
		{	
			hex[0] = digits[*ptr / 16];
			hex[1] = digits[*ptr % 16];

			write(1, "\\", 1);
			write(1, hex, 2);

		}
		ptr++;
	}
				
}
