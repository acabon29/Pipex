/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:01:40 by acabon            #+#    #+#             */
/*   Updated: 2025/01/07 15:17:04 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

#include "../libft.h"

int	is_spe_char(char c)
{
	int		i;
	char	type[10];

	ft_strlcpy(type, "cspdiuxX%", 11);
	i = 0;
	while (type[i])
	{
		if (c == type[i])
			return (i + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

// void put_arg(void *c, void *(*f)(void *))
// essayer de mettre les fonctions dans un tableau
// "cspdiuxX%"

int	put_arg(va_list args, char type)
{
	int	len;

	len = 0;
	if (type == '%')
		len = ft_putchar('%');
	else if (type == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (type == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (type == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (type == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (type == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		len = ft_putexapt_pf((long)va_arg(args, char *), "0123456789abcdef");
	return (len);
}

int	put_print(char c, int is_spe)
{
	int	len;

	len = 0;
	if (is_spe == 1 && is_spe_char(c) == 0)
		len += ft_putchar('%');
	len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		is_spe;
	int		len;

	va_start(args, format);
	len = 0;
	i = -1;
	is_spe = 0;
	while (format[++i])
	{
		if (format[i] == '%' && is_spe == 0)
			is_spe = 1;
		else if (is_spe_char(format[i]) && is_spe == 1)
		{
			len += put_arg(args, format[i]);
			is_spe = 0;
		}
		else if (format[i] != ' ' || is_spe == 0)
		{
			len += put_print(format[i], is_spe);
			is_spe = 0;
		}
	}
	return (va_end(args), len);
}
