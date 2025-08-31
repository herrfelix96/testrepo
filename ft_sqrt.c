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

int		ft_sqrt(int nb);
void	ft_prime_factors(int nb);
char	FACTORS[10];
int main(void)
{
	int num = 6545;
	ft_prime_factors(num);
	//printf("%s\n", FACTORS);
	return 0;
}

void	ft_prime_factors(int nb)
{
	int		f;
	int		c;
	int		nb_copy;

	nb_copy = nb;
	c = 0;
	f = 2;
	while (nb > 0)
	{
		if (f  > nb_copy / 2)
			return;
		if (nb % f == 0)
		{
			FACTORS[c] = f + '0';
			c++;
			nb = nb / f;
			printf("%i\n", f);
			f = 1;
		}
		f++;
	}
}
