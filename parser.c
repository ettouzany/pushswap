/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:56:16 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/16 09:36:44 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack    *ft_create_node(char *value, int size, int position)
{
    t_stack    *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->value = ft_atoi(value);
    new->index = size;
    new->flag = 0;
    new->position = position;
    new->size = size;
    new->next = NULL;
    return (new);
}

t_stack *ft_checker_multi(int argc, char **argv)
{
    //variables
    t_stack *stack;
    t_stack *tmp;
    int i;
    int j;
    int k;
    int size;
    int *position;
    

    size = argc - 1;
    position = (int *)malloc(sizeof(int) * size);
    i = 1;
    while (i < argc)
    {
        if (ft_strlen(argv[i]) > 10)
        {
            ft_putstr("Error\n");
            return (NULL);
        }
        //check if the value is a number
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
            {
                ft_putstr("Error\n");
                return (NULL);
            }
            j++;
        }
        //check if the value is unique
        k = 0;
        while (k < i)
        {
            if (ft_strcmp(argv[i], argv[k]) == 0)
            {
                ft_putstr("Error\n");
                return (NULL);
            }
            k++;
        }
        //set sorted position
        j = 1;
        position[i - 1] = 0;
        while (j <= size)
        {
            if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
                position[i - 1]++;
            j++;
        }
        i++;
    }

    
    
    //create stack
    stack = ft_create_node(argv[1], size, position[0]);
    tmp = stack;
    i = 2;
    while (i < argc)
    {
        tmp->next = ft_create_node(argv[i], size, position[i - 1]);
        tmp = tmp->next;
        i++;
    }

    //free
    free(position);

    // set_indexes(stack);
    return (stack);
}



t_stack *ft_checker_line(char *line)
{

    //variables
    t_stack *stack;
    char **split;
    int i;
    int j;
    int k;

    //split line
    split = ft_strsplit(line, ' ');
    i = 0;
    j = 0;
    k = 0;
    //send to atoi
    while (split[i])
    {
        j = ft_atoi(split[i]);
        if (j > 2147483647 || j < -2147483648)
            return (NULL);
        i++;
    }
    //check if valid
    i = 0;
    while (split[i])
    {
        j = ft_atoi(split[i]);
        k = i + 1;
        while (split[k])
        {
            if (j == ft_atoi(split[k]))
                return (NULL);
            k++;
        }
        i++;
    }

    //if valid, create node
    i = 0;
    while (split[i])
    {
        stack->next = ft_create_node(split[i], i, i);
        stack = stack->next;
        i++;
    }
    

    //return node
    return (stack);
}

// ft_checker_multi(argc, argv)

t_stack *parser(int argc, char **argv)
{
    if(argc == 1)
    {
        return(NULL);
    } else if (argc == 2)
    {
        return(ft_checker_line(argv[1]));
    } else
        return(ft_checker_multi(argc, argv));
}
    