/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:35:03 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/01/14 13:35:28 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ft_strlen
- Purpose: Calculate the length of a string until a '\0' is found
- From: libft42 (mine)
*/
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

/*
ft_str_bzero
- Purpose: Loop through all bytes of str and set them to '\0'
- From: libft42 - ft_bzero (mine)
*/
void	ft_str_bzero(char *str)
{
    while (*str)
        *str++ = '\0';
}

/*
ft_memmove
- Purpose: Move a block of memory from one location to another (allowing overlaps)
- From: libft42 (mine)
*/
void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char			*dst_cpy;
	const unsigned char		*src_cpy;
	size_t					i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst == src)
		return (dst);
	dst_cpy = dst;
	src_cpy = src;
	if (src_cpy < dst_cpy)
		while (++i <= size)
			dst_cpy[size - i] = src_cpy[size - i];
	else
		while (size--)
			*dst_cpy++ = *src_cpy++;
	return (dst);
}

/*
ft_strlcpy
- Purpose: Copy string src to dst up to n-1 bytes, and add a '\0' character after it
- From: libft42 (mine)
*/
size_t	ft_strlcpy(char *dst, char const *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (!dst || !src || n == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
ft_strdup
- Purpose: Allocate a string and forward str into it.
- From: libft42 (mine)
*/
char	*ft_strdup(char const *str)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen((char *)str);
	ptr = malloc((str_len + 1) * sizeof(char));
	if (!ptr)
		return ((char *)0);
	i = 0;
	while (i < str_len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
