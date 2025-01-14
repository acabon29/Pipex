/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexapt_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:21 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putexapt_pf(long long mem, char *base)
{
	int	len;

	len = 0;
	if (mem == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	if (mem == LONG_MIN)
		len += ft_putstr("0x8000000000000000");
	else if (mem == (long long)ULONG_MAX)
		len += ft_putstr("0xffffffffffffffff");
	else
	{
		if (mem >= 16)
			len += ft_putexapt_pf(mem / 16, base);
		else
			len += ft_putstr("0x");
		len += ft_putchar(base[mem % 16]);
	}
	return (len);
}
