/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:59:25 by acabon            #+#    #+#             */
/*   Updated: 2024/11/01 17:59:25 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	update_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n' && i <= BUFFER_SIZE)
		i++;
	i += buffer[i] == '\n';
	j = 0;
	while (buffer[i + j] && (i + j) <= BUFFER_SIZE)
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	while (j <= BUFFER_SIZE)
	{
		buffer[j] = 0;
		j++;
	}
}

void	*reset_var(char *str1, char *str2, char *buffer)
{
	ft_bzero(buffer, BUFFER_SIZE);
	free(str1);
	free(str2);
	return (NULL);
}

char	*cat_buffer_str(char *buffer, char *str)
{
	size_t	len_str;
	size_t	len_buffer;
	char	*temp_str;

	len_str = ft_strlen(str);
	len_buffer = 0;
	while (buffer[len_buffer] && buffer[len_buffer] != '\n')
		len_buffer++;
	len_buffer += buffer[len_buffer] == '\n';
	temp_str = (char *)malloc((len_buffer + len_str + 1) * sizeof(char));
	if ((len_buffer == 0 && len_str == 0) || !temp_str)
		return (reset_var(temp_str, str, buffer));
	temp_str[0] = 0;
	ft_strlcat(temp_str, str, len_str + 1);
	ft_strlcat(temp_str, buffer, len_str + len_buffer + 1);
	free(str);
	if (ft_strchr(buffer, '\n') == NULL)
		ft_bzero(buffer, BUFFER_SIZE);
	else
		update_buffer(buffer);
	return (temp_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1] = {0};
	long		res_read;
	char		*res_str;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 0)
		return (NULL);
	res_str = ft_strdup("");
	res_read = 1;
	while (ft_strchr(res_str, '\n') == NULL && res_read != 0)
	{
		if (buffer[fd][0] == 0)
			res_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (res_read < 0)
			return (reset_var(res_str, NULL, buffer[fd]));
		res_str = cat_buffer_str(buffer[fd], res_str);
		if (!res_str)
			return (NULL);
	}
	return (res_str);
}

// int main()
// {
// 	int fd;
// 	char *res;
// 	// fd = open("file_test", O_RDWR);
// 	fd = open("file_test", O_RDWR);
// 	// res = get_next_line(fd);
// 	// printf("res = %s\n", res);
// 	// free(res);

//   // res = get_next_line(fd);
// 	// printf("res = %s\n", res);
// 	// free(res);
//   char test[BUFFER_SIZE] = "\n\n\n";
// 	printf("res = <%s>\n", test);
//   machin((char *)test);
// 	printf("res = <%s>\n", test);
//   machin((char *)test);
// 	printf("res = <%s>\n", test);
//   machin((char *)test);
// 	printf("res = <%s>\n", test);

//   close(fd);
// }
