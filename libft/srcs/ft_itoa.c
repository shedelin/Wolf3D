/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:56:10 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/05 19:25:36 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	char	*c;
	int		i;
	long	sign;

	sign = (long int)n;
	s = ft_strnew(11);
	c = ft_strnew(11);
	i = 0;
	if (sign < 0)
		sign *= -1;
	if (sign == 0)
		s[0] = '0';
	while (sign > 0)
	{
		s[i++] = sign % 10 + '0';
		sign /= 10;
	}
	if (n < 0)
		s[i] = '-';
	sign = ft_strlen(s) - 1;
	i = 0;
	while (sign > -1)
		c[i++] = s[sign--];
	return (c);
}
