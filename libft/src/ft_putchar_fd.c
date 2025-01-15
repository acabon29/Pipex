/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:49:50 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 13:17:50 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

// int main()
// {
// 	int fd;
// 	fd = open("file_test", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	ft_putchar_fd('e', fd);
// 	close(fd);
// 	return 0;
// }
