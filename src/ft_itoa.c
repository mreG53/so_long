/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:56:28 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/04 01:43:05 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_int_len(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*handle_zero(void)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	if (n == 0)
		return (handle_zero());
	nbr = n;
	len = ft_int_len(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
