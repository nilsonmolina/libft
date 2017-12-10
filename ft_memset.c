/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:50:02 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/07 22:11:10 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		index;
	char	*ptr;

	index = 0;
	ptr = b;
	while (len--)
		ptr[index++] = (unsigned char)c;
	return (b);
}
