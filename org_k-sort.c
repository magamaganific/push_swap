/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_k-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:49:49 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/25 13:49:53 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;
	size_t			p;

	p = 0;
	dst = (unsigned char *) dest;
	sc = (unsigned char *) src;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (p < n)
	{
		dst[p] = sc[p];
		p++;
	}
	return ((void *)dst);
}

void	ft_1stsorter(t_stack **a, t_stack **b)
{
	t_stack	*index;

	index = NULL;
	ft_stkcpy(index, *a, ft_countnums(*a));
	ft_printstack(index);
	ft_printstack(*b);
	ft_freestack(index);
}
