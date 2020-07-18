/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:52:41 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/18 16:05:01 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		sub_putnbr(int n)
{
	char	temp;

	temp = n % 10 + '0';
	if (n >= 10)
		sub_putnbr(n / 10);
	write(1, &temp, 1);
}

void		ft_putnbr(int nb)
{
	char	temp;

	if (nb < 0)
	{
		write(1, "-", 1);
		temp = (nb % 10) * (-1) + '0';
		nb /= -10;
		if (nb > 10)
			sub_putnbr(nb);
		write(1, &temp, 1);
	}
	else
		sub_putnbr(nb);
}
