/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:56:28 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/14 03:54:28 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_int_len(int n)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
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

	nbr = n;
	if (nbr == 0)
		return (handle_zero());
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
