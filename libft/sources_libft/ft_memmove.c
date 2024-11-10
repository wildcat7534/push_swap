/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:57:49 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/01 11:24:10 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if ((!dst && !src) || (dst == NULL && src == NULL))
		return (dst);
	if (ptr_dst < ptr_src)
	{
		while (n--)
		{
			*ptr_dst++ = *ptr_src++;
		}
	}
	else
	{
		ptr_dst += n;
		ptr_src += n;
		while (n--)
		{
			*--ptr_dst = *--ptr_src;
		}
	}
	return (dst);
}
