/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:35:27 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 13:31:23 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_base_fd(unsigned int nb, char *base, int fd)
{
	int	len;

	len = 0;
	if (nb >= ft_strlen(base))
		len += ft_putnbr_base_fd(nb / ft_strlen(base), base, fd);
	len += ft_putchar_fd(base[nb % ft_strlen(base)], fd);
	return (len);
}
