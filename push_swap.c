/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:36:27 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/20 22:39:01 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// typedef struct s_stack
// {
// 	int				value;
// 	int				index;
// 	int				flag;
// 	int				position;
// 	int				size;
// 	struct s_stack	*next;
// 	int				rev;
// 	int				sub_index;
// 	int				insts;
// }					t_stack;

// void print_s(t_stack *stack)
// {
// 	t_stack *tmp;

// 	tmp = stack;
// 	while (tmp)
// 	{
// 		ft_putstr("\033[31m");
// 		ft_putnbr(tmp->value);
// 		ft_putchar(' ');
// 		ft_putnbr(tmp->position);
// 		ft_putchar(' ');
// 		ft_putnbr(tmp->size);
// 		ft_putchar(' ');
// 		ft_putnbr(tmp->flag);
// 		ft_putchar('\n');
// 		ft_putstr("\033[0m");
// 		tmp = tmp->next;
// 	}
// 	ft_putstr("--------\n");
// }

// t_stack *get_stack_at_pos(t_stack *stack, int pos)
// {
// 	t_stack *tmp;
// 	tmp = stack;
// 	while (tmp)
// 	{
// 		if (tmp->position == pos)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

// void s(t_stack *stack)
// {
// 	int size = stack->size;
// 	int *arr = (int *)malloc(sizeof(int) * size);
// 	int *LIS = (int *)malloc(sizeof(int) * size);
//     int i, j, max = 0;
// 	i = 0;
// 	j = 0;
// 	t_stack *tmp = stack;
// 	while (tmp)
// 	{
// 		arr[i++] = tmp->position;
// 		tmp = tmp->next;
// 	}
// 	while (j < size)
// 		LIS[j++] = 1;
// 	i = 0;
// 	j = 0;
// 	while (i <size)
// 	{
// 		j = 0;
// 		while (j < i)
// 		{
// 			if (arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
// 				LIS[i] = LIS[j] + 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	//print LIS
// 	for (i = 0; i < size; i++)
// 	{
// 		printf("%d ", LIS[i]);
// 	}
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (LIS[i] > max)
// 		{
// 			max = LIS[i];
// 			j = i;
// 		}
// 		i++;
// 	}
// 	i = j;
// 	while (i > 0)
// 	{
// 		printf("%d --\n", arr[i]);
// 		if(LIS[i] == LIS[j] - 1 || LIS[i] == max)
// 		{
			
// 			get_stack_at_pos(stack, arr[i])->flag = 1;
// 			j = i;
// 		}
// 		i--;
// 	}
// 	free(LIS);
// 	free(arr);
// }
int	main(int argc, char **argv)
{
	//parser
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL)
		return (0);
	sort(stack_a);
	// print_s(stack_a);

	//sort
	// sort(stack_a, stack_b);
		
		
	//variables
	//checker
	//sorter
	//print
	return (0);
}