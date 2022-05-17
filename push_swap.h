/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:37:58 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/17 16:24:28 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				flag;
	int				position;
	int				size;
	struct s_stack	*next;
}					t_stack;

//parser & checker
t_stack	*ft_checker_multi(int argc, char **argv);
t_stack	*ft_checker_line(char *line);
t_stack	*parser(int argc, char **argv);

//debug
void	print_stack(t_stack *stack);

//instructions
void	ft_s(t_stack **s);
void    ft_ss(t_stack **a, t_stack **b);
void	ft_p(t_stack **a, t_stack **b, char b_a);
void	ft_pp(t_stack **a, t_stack **b);
void	ft_r(t_stack **a, t_stack **b, char b_a);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rv(t_stack **a, t_stack **b, char b_a);
void	ft_rrv(t_stack **a, t_stack **b);
char	**sort(t_stack *stack);

//sort

#endif