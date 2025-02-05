/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexapt_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:21 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 13:25:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putexapt_pf(long long mem, char *base, int fd)
{
	int	len;

	len = 0;
	if (mem == 0)
	{
		len += ft_putstr_fd("(nil)", fd);
		return (len);
	}
	if (mem == LONG_MIN)
		len += ft_putstr_fd("0x8000000000000000", fd);
	else if (mem == (long long)ULONG_MAX)
		len += ft_putstr_fd("0xffffffffffffffff", fd);
	else
	{
		if (mem >= 16)
			len += ft_putexapt_pf(mem / 16, base, fd);
		else
			len += ft_putstr_fd("0x", fd);
		len += ft_putchar_fd(base[mem % 16], fd);
	}
	return (len);
}
