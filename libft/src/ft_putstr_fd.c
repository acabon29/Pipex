/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:12:28 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 13:22:40 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

// int main()
// {
// 	int fd;
// 	fd = open("file_test", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	ft_putstr_fd("test", fd);
// 	close(fd);
// 	return 0;
// }
