/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:12:59 by fharutyu          #+#    #+#             */
/*   Updated: 2025/08/31 13:59:49 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_negative(char *str);
int	ft_atoi(char *str);
int	ft_length(char *str);
int	ft_power(int base, int power);
/*
int main(void)
{
	char *number = "abc123";

	printf("%i\n", ft_atoi(number));
	return 0;
}
*/

int	ft_atoi(char *str)
{
	int		length;
	int		number;
	char	*strcopy;

	number = 0;
	strcopy = str;
	length = ft_length(str);
	while (!(*strcopy >= '0' && *strcopy <= '9'))
	{
		//if (*strcopy != '-' || *strcopy != '+')
		//	return (0);
		strcopy++;
	}
	while (length > 0)
	{
		number = number + (((int)*strcopy - 48) * ft_power(10, length - 1));
		length--;
		strcopy++;
	}
	if (ft_is_negative(str) == 0)
	{
		number = -number;
	}
	return (number);
}

int	ft_power(int base, int power)
{
	if (power == 0)
		return (1);
	base = base * ft_power(base, power - 1);
	return (base);
}

int	ft_length(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
			{
				length++;
				str++;
			}
			return (length);
		}
		str++;
	}
	return (length);
}

int	ft_is_negative(char *str)
{
	int	negative_count;

	negative_count = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative_count++;
		str++;
	}
	if ((negative_count % 2) == 1)
		return (0);
	else
		return (1);
}
