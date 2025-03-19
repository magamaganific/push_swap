/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:08:11 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/11 09:08:15 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int				*val;
	struct s_stack	*next;
}	t_stack;

void	ft_freer(char **arr);
void	ft_freestack(t_stack *head);
t_stack	*ft_addval(int *num);
void	ft_addlast(t_stack **head, t_stack *newnum);
void	ft_stacknum(t_stack **head, int *num);
void	ft_stackfront(t_stack **head, int *num);
void	ft_printstack(t_stack *head);
void	ft_swap(t_stack **stck);
size_t	ft_countnums(t_stack *head);
int		*ft_savevals(t_stack *head, size_t size);
void	ft_saverot(t_stack *head, int *vals, size_t size);
void	ft_rotate(t_stack *head);
void	ft_revrotate(t_stack *head);
void	ft_push(t_stack **src, t_stack **dst);
void	ft_ssab(int move, t_stack **a, t_stack **b);
void	ft_pab(int move, t_stack **a, t_stack **b);
void	ft_r2ab(int move, t_stack **a, t_stack **b);
void	ft_r3ab(int move, t_stack **a, t_stack **b);
//void	ft_moveadmin(int move, int who, t_stack **a, t_stack **b);
int		ft_stkissorted(t_stack *head);
void	ft_sort3(t_stack **a);
void	ft_push_swap(t_stack **a, t_stack **b);
int		ft_strisnum(char *arg);
size_t	ft_countargs(char **args);
int		ft_dupedints(t_stack *a);
int		*ft_check_args(char **args);
int		*ft_stackargs(char **args, t_stack **a);
char	**ft_args_to_stack(int ac, char **av);