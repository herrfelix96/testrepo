/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:35:57 by fharutyu          #+#    #+#             */
/*   Updated: 2025/08/31 13:22:03 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAXVALUE 100

void	ft_to_zero(void);
int	ft_sqrt(int nb);
void	ft_prime_factors(int nb);
int	FACTORS[MAXVALUE];
int	UNIQUE_FACTORS[MAXVALUE];
/*
int main(int argv, char *argc[])
{
	if (argv != 2)
		return (1);

	int num = atoi(argc[1]);
	printf("%i\n", ft_sqrt(num));
	return 0;
}*/

int	ft_sqrt(int nb)
{
	int	result;
	int	i;
	int	u;

	result = 1;
	u = 0;
	i = 0;
	ft_prime_factors(nb);
	if (FACTORS[i] != FACTORS[i + 1] || nb <= 0)
		return (0);

	while (FACTORS[i] == FACTORS[i + 1] && FACTORS[i] != 0)
	{
		UNIQUE_FACTORS[u] = FACTORS[i];
		i = i + 2;
		u++;
	}
	if (FACTORS[i] != 0)
                return (0);
	u = 0;
	while (UNIQUE_FACTORS[u] != 0)
	{
		result = result * UNIQUE_FACTORS[u];
		u++;
	}
	return (result);
}

void	ft_prime_factors(int nb)
{
	int	f;
	int	c;
	int	nb_copy;
	
	ft_to_zero();
	nb_copy = nb;
	c = 0;
	f = 2;
	while (nb > 0)
	{
		if (f  > nb_copy)
			return;
		if (nb % f == 0)
		{
			FACTORS[c] = f;
			c++;
			nb = nb / f;
			//printf("%i\n", f);
			f = 1;
		}
		f++;
	}
}

void	ft_to_zero(void)
{
	int	i;

	i = 0;
        while (i < MAXVALUE)
        {
                FACTORS[i] = 0;
                i++;
        }
	i = 0;
	while (i < MAXVALUE)
	{
		UNIQUE_FACTORS[i] = 0;
		i++;
	}
}

