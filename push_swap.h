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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# ifndef PA
#  define PA 1
# endif
# ifndef PB
#  define PB 2
# endif
# ifndef SA
#  define SA 3
# endif
# ifndef SB
#  define SB 4
# endif
# ifndef SS
#  define SS 5
# endif
# ifndef RA
#  define RA 6
# endif
# ifndef RB
#  define RB 7
# endif
# ifndef RR
#  define RR 8
# endif
# ifndef RRA
#  define RRA 9
# endif
# ifndef RRB
#  define RRB 10
# endif
# ifndef RRR
#  define RRR 11
# endif
# ifndef HEAD
#  define HEAD 'h'
# endif
# ifndef NEXT
#  define NEXT 'n'
# endif
# ifndef SLAST
#  define SLAST 's'
# endif
# ifndef LAST
#  define LAST 'l'
# endif

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

long		ft_atol(const char *nptr);
//Freers
void		ft_freer(char **arr);
void		ft_freestack(t_stack *head);
//Stack admins
t_stack		*ft_addval(int num);
void		ft_addlast(t_stack **head, t_stack *newnum);
void		ft_stacknum(t_stack **head, int num);
void		ft_stackfront(t_stack **head, int num);

void		ft_printstack(t_stack *head);

void		ft_swap(t_stack **stck);
size_t		ft_countnums(t_stack *head);
void		ft_rotate(t_stack *head);
void		ft_revrotate(t_stack *head);
void		ft_push(t_stack **src, t_stack **dst);
void		ft_ssab(int move, t_stack **a, t_stack **b);
void		ft_pab(int move, t_stack **a, t_stack **b);
void		ft_r2ab(int move, t_stack **a, t_stack **b);
void		ft_r3ab(int move, t_stack **a, t_stack **b);

int			ft_stkissorted(t_stack *head);
int			ft_bissorted(t_stack *head);

void		ft_sort3(t_stack **a);
void		ft_sort4(t_stack **a, t_stack **b);
void		ft_sort5(t_stack **a, t_stack **b);

void		ft_index(int size, t_stack	**a, int *nums);
int			ft_strisnum(char *arg);
size_t		ft_countargs(char **args);
int			ft_dupedints(t_stack *a);
int			*ft_check_args(char **args);
int			*ft_stackargs(char **args, t_stack **a);
char		**ft_args_to_stack(int ac, char **av);
void		ft_sorter(t_stack **a, t_stack **b);
void		k_sort(t_stack **a, t_stack **b);
int			ft_pos_id(t_stack *head, int pos);
void		ft_moveadmin(int move, t_stack **a, t_stack **b);
int			ft_max_node(t_stack **a);

#endif