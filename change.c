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