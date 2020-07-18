/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:14:15 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/18 15:55:57 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_char(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	if (c == '-')
		return (-1);
	if (c == '+')
		return (-2);
	if ('0' <= c && c <= '9')
		return (2);
	return (0);
}

int		ft_atoi(char *str)
{
	int	idx;
	int	cnt;
	int	result;

	idx = 0;
	while (check_char(str[idx]) == 1)
		idx++;
	cnt = 0;
	while (check_char(str[idx]) < 0)
	{
		if (check_char(str[idx]) == -1)
			cnt++;
		idx++;
	}
	if (str[idx] < '0' || str[idx] > '9')
		return (0);
	result = str[idx++] - '0';
	while (check_char(str[idx]) == 2)
		result = result * 10 + str[idx++] - '0';
	if (cnt % 2 == 1)
		result *= -1;
	return (result);
}
