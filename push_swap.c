/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:36:27 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/17 17:47:33 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	//parser
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL)
		return (0);
	// print_stack(stack_a);
	sort(stack_a);

	//sort
	// sort(stack_a, stack_b);
		
		
	//variables
	//checker
	//sorter
	//print
	return (0);
}