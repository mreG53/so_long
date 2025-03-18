/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <emgumus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:02:30 by emgumus           #+#    #+#             */
/*   Updated: 2024/12/26 14:48:04 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	result;

	i = 0;
	if (n == 0)
		return (ft_putstr("0"));
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		result = ft_putnbr(n / 10);
		if (result == -1)
			return (-1);
		i += result;
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (i + 1);
}

int	ft_uint(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putstr("0"));
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (i + 1);
}

int	ft_puthex(unsigned long n, char *hex, int mode)
{
	int	i;
	int	result;

	i = 0;
	if (mode)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		i += 2;
		mode = 0;
	}
	if (n >= 16)
	{
		result = ft_puthex(n / 16, hex, mode);
		if (result == -1)
			return (-1);
		i += result;
	}
	if (ft_putchar(hex[n % 16]) == -1)
		return (-1);
	return (i + 1);
}
