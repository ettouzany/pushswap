/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:55:49 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/21 00:57:29 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_s(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		ft_putstr("\033[31m");
		ft_putnbr(tmp->value);
		ft_putstr(" p ");
		ft_putnbr(tmp->position);
		ft_putstr(" s ");
		ft_putnbr(tmp->size);
		ft_putstr(" f ");
		ft_putnbr(tmp->flag);
		ft_putstr(" i ");
		ft_putnbr(tmp->index);
		ft_putstr(" su ");
		ft_putnbr(tmp->sub_index);
		ft_putstr(" in ");
		ft_putnbr(tmp->insts);
		ft_putstr("\n");
		ft_putstr("\033[0m");
		tmp = tmp->next;
	}
	ft_putstr("--------\n");
}

void print_instruction(char **instruction, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(instruction[i]);
		ft_putchar('\n');
		i++;
	}
}

void print_ints(int *ints, int size, char *message)
{
	int i;

	i = 0;
	ft_putstr(message);
	while (i < size)
	{
		ft_putstr("\033[31m");
		ft_putnbr(ints[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	ft_putstr("\033[0m");
}
int *LIS_algo_array_int(int *numbers, int *size)
{
	//find the largest increasing subsequence in numbers array of size size and return an array of that subsequence
	int *subsequence;
	int *lenght;
	subsequence = (int *)malloc(sizeof(int) * *size);
	lenght = (int *)malloc(sizeof(int) * *size);
	int max_size = 0;
	int i;
	int j;
	i = 0;
	j = 0;

	while (i < *size)
	{
		lenght[i] = 1;
		i++;
	}

	i = 0;
	while (i < *size)
	{
		j = 0;
		while (j < i)
		{
			if (numbers[i] > numbers[j] && lenght[i] < lenght[j] + 1)
			{
				lenght[i] = lenght[j] + 1;
				subsequence[i] = j;
			}
			j++;
		}
		if (lenght[i] > max_size)
			max_size = lenght[i];
		i++;
	}
	i = 0;
	while (i < *size)
	{
		if (lenght[i] == max_size)
			break ;
		i++;
	}
	int *result;
	result = (int *)malloc(sizeof(int) * max_size);
	int k = 0;
	while (k < max_size)
	{
		result[k] = numbers[i];
		i = subsequence[i];
		k++;
	}
	free(subsequence);
	free(lenght);
	*size = max_size;
	return (result);
}

void	flag_stack(t_stack *stack)
{
	int *poses;
	int *subsequence;
	int subsequence_size;
	int i;
	int j;
	t_stack *tmp;

	subsequence_size = stack->size;
	poses = (int*)malloc(sizeof(int) * stack->size);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		poses[i] = tmp->position;
		tmp = tmp->next;
		i++;
	}
	subsequence = LIS_algo_array_int(poses, &subsequence_size);
	printf("subsequence : ");

	j = 0;
	while (j < subsequence_size)
	{
		tmp = stack;
		while (tmp->position != subsequence[j])
			{tmp = tmp->next;}
		tmp->flag = 1;
		j++;
	}
	i = 0;
	while (i < subsequence_size)
	{
		printf("%d ", subsequence[i]);
		i++;
	}
	free(poses);
	free(subsequence);
}

void	LIS_algo_t_stack(t_stack *stack)
{
	//find the largest increasing subsequence in stack and set the flag of each node to 1
	int subsequence_size = stack->size;
	int *positions;
	positions = (int *)malloc(sizeof(int) * stack->size);
	int i;
	i = 0;
	t_stack *tmp = stack;
	while (tmp != NULL)
	{
		positions[i] = tmp->position;
		tmp = tmp->next;
		i++;
	}
	
	int *subsequence = LIS_algo_array_int(positions, &subsequence_size);
	i = 0;
	while (i < subsequence_size)
	{
		printf("%d \n", subsequence[i]);
		i++;
	}
	
	int j;

	j = 0;
	while (j < subsequence_size)
	{
		tmp = stack;
		while (tmp->position != subsequence[j])
			tmp = tmp->next;
		tmp->flag = 1;
		j++;
	}
			
}
int	check_stack_from_flags(t_stack *stack)
{
	t_stack *tmp = stack;
	while (tmp)
	{
		if (tmp->flag == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack *get_reverse_stack(t_stack *stack)
{
	//reverse the stack don't use prev
	t_stack *tmp = stack;
	int i;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	t_stack *result = (t_stack *)malloc(sizeof(t_stack));
	result->position = tmp->position;
	result->flag = tmp->flag;
	result->next = NULL;
	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->position = tmp->position;
		new_node->flag = tmp->flag;
		new_node->next = result;
		result = new_node;
	}
	return (result);
	
}
int needed_rev(t_stack **a, int pos)
{
	//start from the end of the stack
	int i;
	i = 0;
	t_stack *tmp = get_reverse_stack(*a);
	while (tmp)
	{
		if (tmp->position == pos+1 || tmp->position == pos-1)
			{if(tmp->position == pos-1)
				return (i);
			else
				return (i+1);}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int needed_ins(t_stack **a, int pos)
{
	//if 
	int i;
	i = 0;
	t_stack *tmp = *a;
	while (tmp)
	{
		if (tmp->position == pos+1 || tmp->position == pos-1)
			{if(tmp->position == pos+1)
				return (i);
			else
				return (i+1);}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	*needed(t_stack **a, t_stack **b,int **rev_rotate_or_rotate,
	int **needed_instructions_on_b
)
{
	int *needed_instructions;
	int i;
	i = 0;
	int	rev = 0;
	int	nex	= 0; 
	needed_instructions = (int *)malloc(sizeof(int) * (*b)->size);
	*rev_rotate_or_rotate = (int *)malloc(sizeof(int) * (*b)->size);
	*needed_instructions_on_b = (int *)malloc(sizeof(int) * (*b)->size);
	t_stack *tmp = *b;
	while (tmp)
	{
		rev	= needed_rev(a, tmp->position);
		nex = needed_ins(a, tmp->position);
		if ((nex <= rev || rev == -1) && nex != -1)
		{
			
			needed_instructions[i] = nex;
			(*rev_rotate_or_rotate)[i] = 0;
			(*needed_instructions_on_b)[i] = i;
		}
		else if (rev != -1)
		{
			needed_instructions[i] = rev;
			(*rev_rotate_or_rotate)[i] = 1;
			(*needed_instructions_on_b)[i] = i;
		}
		else
			needed_instructions[i] = -1;
		tmp = tmp->next;
		i++;
	}
	return (needed_instructions);
}

void	send_b_to_a(t_stack **a, t_stack **b)
{
	int *rev_rotate_or_rotate;
	int *needed_instructions_on_b;
	int *needed_instructions_to_sort = needed(a, b, 
	&rev_rotate_or_rotate,
	&needed_instructions_on_b);
	int i;
	i = 0;
	
	// print
	while (i < (*b)->size)
	{
		printf("**%d \n", needed_instructions_to_sort[i]);
		printf("**%d \n", needed_instructions_on_b[i]);
		i++;
	}

	// get the smallest value
	int smallest_value;
	int smallest_index;
	i = 0;
	//intualize the smallest value
	while (i < (*b)->size)
	{
		if (needed_instructions_to_sort[i] != -1)
		{
			smallest_value = needed_instructions_to_sort[i];
			smallest_index = i;
			break;
		}
		i++;
	}
	//find the smallest value
	while (i < (*b)->size)
	{
		if (needed_instructions_to_sort[i] != -1 &&
			needed_instructions_to_sort[i] < smallest_value)
		{
			smallest_value = needed_instructions_to_sort[i];
			smallest_index = i;
		}
		i++;
	}
	printf("smallest_index = %d \n", smallest_index);
		printf("+++%d \n", (*a)->value);

	i = 0;
	while (i < needed_instructions_on_b[smallest_index])
	{
		ft_r(a, b, 'b');
		i++;
	}
	i = 0;
	printf("+++++%d \n", (*a)->value);

	while (i < needed_instructions_to_sort[smallest_index])
	{
		if(rev_rotate_or_rotate[smallest_index] == 0)
			ft_r(a, b, 'a');
		else
			ft_rv(a, b, 'a');
		i++;
	}
	printf("%d \n", (*a)->value);

	ft_p(a, b, 'b');

	t_stack *tmp = *a;
	//print
	while (tmp)
	{
		printf("--- %d \n", tmp->value);
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp)
	{
		printf("^^^ %d \n", tmp->value);
		tmp = tmp->next;
	}


	free(needed_instructions_to_sort);
	free(rev_rotate_or_rotate);
	free(needed_instructions_on_b);
	

	
	// printf("%d \n", (*b)->value);
	// printf("%d \n", (*a)->value);
}
void fix_stack(t_stack **stack)
{
	while ((*stack)->position != 0)
	{
		ft_r(stack, NULL, 'a');
	}
}
void	print_stack(t_stack *stack)
{
	int i = 0;
	LIS_algo_t_stack(stack);
	ft_putstr("\n\n\n");
	i = 0;
	t_stack *tmp = stack;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->position);
		ft_putchar(' ');
		ft_putnbr(tmp->size);
		ft_putchar(' ');
		ft_putnbr(tmp->flag);
		ft_putchar('\n');
		tmp = tmp->next;
		i++;
	}
	t_stack *b = stack;
	//push the elements with flag 0 to the stack
	// ft_p(t_stack **a, t_stack **b, char b_a);
	
	//intiliaze the stack
	b = NULL;

	i = 0;
	while (check_stack_from_flags(stack) == 0)
	{
		if (stack->flag == 0)
		{
			ft_p(&stack, &b, 'a');
			printf("pa\n");
		}
		else
		{
			ft_r(&stack, &b, 'a');
			printf("ra\n");
		}
		i++;
	}
	ft_putstr("\n\n\n");

	tmp = stack;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->position);
		ft_putchar(' ');
		ft_putnbr(tmp->size);
		ft_putchar(' ');
		ft_putnbr(tmp->flag);
		ft_putchar('\n');
		tmp = tmp->next;
	}

	tmp = b;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->position);
		ft_putchar(' ');
		ft_putnbr(tmp->size);
		ft_putchar(' ');
		ft_putnbr(tmp->flag);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	
	while (b)
	{
		send_b_to_a(&stack, &b);
	}
	fix_stack(&stack);
	ft_putstr("\n\n\n");
		tmp = stack;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->position);
		ft_putchar(' ');
		ft_putnbr(tmp->size);
		ft_putchar(' ');
		ft_putnbr(tmp->flag);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putstr("\n\n\n");

	tmp = b;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->position);
		ft_putchar(' ');
		ft_putnbr(tmp->size);
		ft_putchar(' ');
		ft_putnbr(tmp->flag);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

int	*needed2(t_stack **a, t_stack **b,
	int **rev_rotate_or_rotate,
	int **rev_rotate_or_rotate_b,
	int **needed_instructions_on_b
)
{
	int *needed_instructions;
	int i;
	i = 0;
	int	rev = 0;
	int	nex	= 0; 
	needed_instructions = (int *)malloc(sizeof(int) * (*b)->size);
	*rev_rotate_or_rotate = (int *)malloc(sizeof(int) * (*b)->size);
	*needed_instructions_on_b = (int *)malloc(sizeof(int) * (*b)->size);
	*rev_rotate_or_rotate_b = (int *)malloc(sizeof(int) * (*b)->size);
	t_stack *tmp = *b;
	while (tmp)
	{
		rev	= needed_rev(a, tmp->position);
		nex = needed_ins(a, tmp->position);
		if ((nex <= rev || rev == -1) && nex != -1)
		{
			needed_instructions[i] = nex;
			(*rev_rotate_or_rotate)[i] = 0;
			
		}
		else if (rev != -1)
		{
			needed_instructions[i] = rev;
			(*rev_rotate_or_rotate)[i] = 1;
			
		}
		else
			needed_instructions[i] = -1;
		if(i < (*b)->size/2)
		{
			(*rev_rotate_or_rotate_b)[i] = 0;
			(*needed_instructions_on_b)[i] = i;
		}
		else
		{
			(*rev_rotate_or_rotate_b)[i] = 1;
			(*needed_instructions_on_b)[i] = (*b)->size - i;
		}
		tmp = tmp->next;
		i++;
	}
	return (needed_instructions);
}




void	send_b_a(t_stack **a, t_stack **b, char ***instructions, int *ins_size)
{
	int *rev_rotate_or_rotate;
	int *rev_rotate_or_rotate_b;
	int *needed_instructions_on_b;
	int *needed_instructions_to_sort = needed2(a, b, 
	&rev_rotate_or_rotate,
	&rev_rotate_or_rotate_b,
	&needed_instructions_on_b);
	int i;
	i = 0;

	// print_ints(needed_instructions_to_sort, (*b)->size, "needed_instructions_to_sort: ");
	// print_ints(rev_rotate_or_rotate, (*b)->size, "rev_rotate_or_rotate: ");
	// print_ints(rev_rotate_or_rotate_b, (*b)->size, "rev_rotate_or_rotate_b: ");
	// print_ints(needed_instructions_on_b, (*b)->size, "needed_instructions_on_b: ");
	



	// get the smallest value
	int smallest_value;
	int smallest_index;
	i = 0;
	//intualize the smallest value
	while (i < (*b)->size)
	{
		if (needed_instructions_to_sort[i] != -1)
		{
			smallest_value = needed_instructions_to_sort[i];
			smallest_index = i;
			break;
		}
		i++;
	}
	//find the smallest value
	while (i < (*b)->size)
	{
		if (needed_instructions_to_sort[i] != -1 &&
			needed_instructions_to_sort[i] < smallest_value)
		{
			smallest_value = needed_instructions_to_sort[i];
			smallest_index = i;
		}
		i++;
	}
	// printf("smallest_index: %d\n", smallest_index);

	i = 0;
	
	int	rrr = 0;
	if(needed_instructions_to_sort[smallest_index] > needed_instructions_on_b[smallest_index] && rev_rotate_or_rotate[smallest_index] == 0 && rev_rotate_or_rotate_b[smallest_index] == 0)
		rrr = needed_instructions_on_b[smallest_index];
	else if (rev_rotate_or_rotate[smallest_index] == 0 && rev_rotate_or_rotate_b[smallest_index] == 0)
		rrr = needed_instructions_to_sort[smallest_index];
	

	int	rrv = 0;
	if(needed_instructions_to_sort[smallest_index] > needed_instructions_on_b[smallest_index] && rev_rotate_or_rotate[smallest_index] == 1 && rev_rotate_or_rotate_b[smallest_index] == 1)
		rrv = needed_instructions_on_b[smallest_index];
	else if (rev_rotate_or_rotate[smallest_index] == 1 && rev_rotate_or_rotate_b[smallest_index] == 1)
		rrv = needed_instructions_to_sort[smallest_index];
	// printf("rrr: %d\n", rrr);
	// printf("rrv: %d\n", rrv);

	while (rrr || rrv)
	{
		if (rrr)
		{
			rrr--;
			ft_rr(a, b);
			*ins_size += 1;
			*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
			(*instructions)[*ins_size-1] = ft_strdup("rr");
			needed_instructions_to_sort[smallest_index]--;
			needed_instructions_on_b[smallest_index]--;
		}
		if (rrv)
		{
			rrv--;
			ft_rrv(a, b);
			*ins_size += 1;
			*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
			(*instructions)[*ins_size-1] = ft_strdup("rrr");
			needed_instructions_to_sort[smallest_index]--;
			needed_instructions_on_b[smallest_index]--;
		}
	}

	i = 0;
	while (i < needed_instructions_to_sort[smallest_index])
	{
		if(rev_rotate_or_rotate[smallest_index] == 0)
		{
			ft_r(a, b, 'a');
			*ins_size += 1;
			*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
			(*instructions)[*ins_size - 1] = ft_strdup("ra");
		}
		else
		{
			ft_rv(a, b, 'a');
			*ins_size += 1;
			*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
			(*instructions)[*ins_size - 1] = ft_strdup("rra");
		}
		i++;
	}

	i = 0;
	while (i < needed_instructions_on_b[smallest_index])
	{
		if(rev_rotate_or_rotate_b[smallest_index] == 0)
		{
			ft_r(a, b, 'b');
			*ins_size += 1;
			*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
			(*instructions)[*ins_size - 1] = ft_strdup("rb");
		}
		else
		{
			ft_rv(a, b, 'b');
			*ins_size += 1;
			*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
			(*instructions)[*ins_size - 1] = ft_strdup("rrb");
		}
		i++;
	}

	
	ft_p(a, b, 'b');
	*ins_size += 1;
	*instructions = ft_realloc(*instructions, sizeof(char *) * *ins_size);
	(*instructions)[*ins_size - 1] = ft_strdup("pa");
	// print_s((*a));
	// print_s((*b));
	// *ins_size += 1;
	// instructions = ft_realloc(instructions, sizeof(char *) * *ins_size);
	// instructions[*ins_size - 1] = ft_strdup("pb");

	free(needed_instructions_to_sort);
	free(rev_rotate_or_rotate);
	free(needed_instructions_on_b);
}

void fix_stack2(t_stack **stack, char ***instructions, int *instructions_size)
{
	while ((*stack)->position != 0)
	{
		ft_r(stack, NULL, 'a');
		*instructions_size += 1;
		*instructions = ft_realloc(*instructions, sizeof(char *) * *instructions_size);
		(*instructions)[*instructions_size - 1] = ft_strdup("ra");
	}
}

char	**flag_0_to_b(t_stack **stack, t_stack **b, int *instructions_size)
{
	char **instructions;
	int i = 0;
	instructions = (char **)malloc(sizeof(char *));
	while (check_stack_from_flags(*stack) == 0)
	{
		if((*stack)->flag == 0)
		{
			
			ft_p(stack, b, 'a');
			*instructions_size += 1;
			if(*instructions_size > 1)
				instructions = ft_realloc(instructions, sizeof(char *) * *instructions_size);
			instructions[*instructions_size - 1] = ft_strdup("pb");
		}
		else
		{
			ft_r(stack, NULL, 'a');
			*instructions_size += 1;
			if(*instructions_size > 1)
				instructions = ft_realloc(instructions, sizeof(char *) * *instructions_size);
			instructions[*instructions_size - 1] = ft_strdup("ra");
		}
		i = 0;
		while (i < *instructions_size)
		{
			i++;
		}
	}
	
	return (instructions);
}
t_stack *get_stack_at_pos(t_stack *stack, int pos)
{
	t_stack *tmp;
	tmp = stack;
	while (tmp)
	{
		if (tmp->position == pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void flag(t_stack *stack)
{
	int size = stack->size;
	int *arr = (int *)malloc(sizeof(int) * size);
	int *LIS = (int *)malloc(sizeof(int) * size);
    int i, j, max = 0;
	i = 0;
	j = 0;
	t_stack *tmp = stack;
	while (tmp)
	{
		arr[i++] = tmp->position;
		tmp = tmp->next;
	}
	while (j < size)
		LIS[j++] = 1;
	i = 0;
	j = 0;
	while (i <size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j] + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (LIS[i] > max)
		{
			max = LIS[i];
			j = i;
		}
		i++;
	}
	i = j;
	while (i >= 0)
	{
		if(LIS[i] == LIS[j] - 1 || LIS[i] == max)
		{
			get_stack_at_pos(stack, arr[i])->flag = 1;
			j = i;
		}
		i--;
	}
	free(LIS);
	free(arr);
}

void indexing(t_stack *stack)
{
	int i = 0;
	t_stack *tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}
void middle(t_stack *stack)
{
	t_stack *tmp = stack;
	int i = 0;
	while (tmp)
	{
		tmp->middle = 0;
		if(i > tmp->size / 2)
			tmp->middle = 1;
		i++;
		tmp = tmp->next;
	}
}

void insts(t_stack *stack)
{
	t_stack *tmp = stack;
	int i = 0;
	while (tmp)
	{
		if(tmp->middle == 1)
			tmp->insts = tmp->size - i;
		else
			tmp->insts = tmp->index;
		i++;
		tmp = tmp->next;
	}
}

t_stack	*least_insts(t_stack *stack)
{
	t_stack *tmp = stack;
	t_stack *min = NULL;
	while (tmp)
	{
		if((!min && tmp->flag == 0) || (tmp->flag == 0 && tmp->insts < min->insts))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
void add_instruction(char **instructions, int *instructions_size, char *instruction)
{
	*instructions_size += 1;
	if(*instructions_size > 1)
		instructions = ft_realloc(instructions, sizeof(char *) * *instructions_size);
	instructions[*instructions_size - 1] = ft_strdup(instruction);
}
char	**send_to_b(t_stack **stack, t_stack **b, int *instructions_size)
{
	char **instructions;
	int i = 0;
	instructions = (char **)malloc(sizeof(char *));
	t_stack *needed_insts = least_insts(*stack);
	while (needed_insts)
	{
		if(needed_insts->insts == 0 && needed_insts->middle == 0)
		{
			ft_p(stack, b, 'a');
			add_instruction(instructions, instructions_size, "pb");
			
		}
		else if(needed_insts->middle == 1)
		{
			ft_rv(stack, NULL, 'a');
			add_instruction(instructions, instructions_size, "rra");
		} 
		else
		{
			ft_r(stack, NULL, 'a');
			add_instruction(instructions, instructions_size, "ra");
		}
		indexing(*stack);
		middle(*stack);
		insts(*stack);
		needed_insts = least_insts(*stack);
		i++;
	}
	*instructions_size = i;
	return (instructions);
}


void	send_to_a(t_stack **a, t_stack **b, char ***instructions, int *instruction_size)
{
	
}

void sub_indexing(t_stack *a, t_stack *b)
{
	t_stack *tmp_b = b;
	t_stack *tmp_a = a;
	while (tmp_b)
	{
		tmp_a = a;
		while (tmp_a)
		{
			// ////maybe -1 and +1 are not good
			if(tmp_b->position == tmp_a->position - 1 || tmp_b->position == tmp_a->position + 1)
			{
				tmp_b->sub_index = tmp_a->index;
				break;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void set_least_instruction(t_stack *a, t_stack *b)
{
	//set least insts for b elements to be in their sub_index position in a
	t_stack *tmp_b = b;
	t_stack	*tmp_a = a;
	int i = 0;
	int j = 0;
	while (tmp_b)
	{
		tmp_a = a;
		while (tmp_a)
		{
			if(tmp_b->sub_index == tmp_a->index)
			{
				tmp_b->insts = tmp_a->insts + tmp_b->insts;
				break;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}


char	**sort(t_stack *stack)
{
	char **instructions;
	int instruction_size = 0;
	int i = 0;
	flag(stack);
	indexing(stack);
	middle(stack);
	insts(stack);

	t_stack *b = stack;
	b = NULL;
	instructions = send_to_b(&stack, &b, &instruction_size);
	// while (b)
	// {
		indexing(stack);
		middle(stack);
		insts(stack);
		indexing(b);
		middle(b);
		insts(b);
		sub_indexing(stack,b);
		set_least_instruction(stack, b);
		// send_to_a(&stack, &b, &instructions, &instruction_size);
	// }
	print_s(b);
	print_s(stack);
	// while (b)
		// send_to_a(&stack, &b, &instructions, &instruction_size);
	// fix_stack2(&stack, &instructions, &instruction_size);
	// printf("instruction_size------------: %d\n", instruction_size);
	// print_s(stack);
	// print_instruction(instructions, instruction_size);
	return (instructions);
}



char	**sort2(t_stack *stack)
{
	char **instructions;
	int instruction_size = 0;
	int i = 0;
	flag(stack);
	indexing(stack);
	middle(stack);
	

	t_stack *b = stack;
	b = NULL;
	instructions = flag_0_to_b(&stack, &b, &instruction_size);
	// print_s(b);
	// print_s(stack);
	// printf("instruction_size------------: %d\n", instruction_size);
	while (b)
	{
		send_b_a(&stack, &b, &instructions, &instruction_size);
		// printf("instruction_size------------: %d\n", instruction_size);

	}
		// printf("instruction_size------------: %d\n", instruction_size);

	fix_stack2(&stack, &instructions, &instruction_size);
	printf("instruction_size------------: %d\n", instruction_size);
	// print_s(stack);
	// print_instruction(instructions, instruction_size);
	return (instructions);
}
