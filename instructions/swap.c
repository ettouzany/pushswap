/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:57:06 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/17 00:35:49 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_s(t_stack **s)
{
    if ((*s)->size == 0)
        return ;
    if ((*s)->size == 1)
        return ;
    t_stack *tmp = (*s)->next;
    (*s)->next = tmp->next;
    tmp->next = (*s);
    return ;
}

void    ft_ss(t_stack **a, t_stack **b)
{
    ft_s(a);
    ft_s(b);
    return ;
}

//push

void    ft_p(t_stack **a, t_stack **b , char b_a)
{
    t_stack *tmp;
    int new_size_b;
    int new_size_a;
    if (b_a == 'a')
    {
        if ((*a)->size == 0)
            return ;
        if(!(*b))
        {
            (*b) = (*a);
            (*a) = (*a)->next;
            (*b)->next = NULL;
            (*b)->size = 1;
            (*a)->size = (*a)->size - 1;
            tmp = (*a);
            while (tmp->next)
            {
                tmp = tmp->next;
                tmp->size = tmp->size - 1;
            }
            return ;
        }
        else
        {
            new_size_b = (*b)->size + 1;
            new_size_a = (*a)->size - 1;
            tmp = (*b);
            (*b) = (*a);
            (*a) = (*a)->next;
            (*b)->next = tmp;
            (*b)->size = new_size_b;
            tmp = (*b);
            while (tmp->next)
            {
                tmp = tmp->next;
                tmp->size = tmp->size + 1;
            }
            if(!(*a))
                return ;
            (*a)->size = new_size_a;
            tmp = (*a);
            while (tmp->next)
            {
                tmp = tmp->next;
                tmp->size = tmp->size - 1;
            }
            return;
            // tmp->next = (*a);
            // (*a) = (*a)->next;
            // tmp->next->next = NULL;
            // int new_size = (*b)->size + 1;
            // (*b)->size = new_size;
            // (*a)->size = (*a)->size - 1;
            // tmp = (*a);
            // while (tmp->next)
            // {
            //     tmp = tmp->next;
            //     tmp->size = tmp->size - 1;
            // }
            // tmp = (*b);
            // while (tmp)
            // {
            //     tmp->size = new_size;
            //     tmp = tmp->next;
            // }
            // return ;
        }
        return ;
    }
    if (b_a == 'b')
    {
        if ((*b)->size == 0)
            return ;
        if(!(*a))
        {
            (*a) = (*b);
            (*b) = (*b)->next;
            (*a)->next = NULL;
            (*a)->size = 1;
            (*b)->size = (*b)->size - 1;
            tmp = (*b);
            while (tmp->next)
            {
                tmp = tmp->next;
                tmp->size = tmp->size - 1;
            }
            return ;
        }
        else
        {
            new_size_b = (*b)->size - 1;
            new_size_a = (*a)->size + 1;
            tmp = (*a);
            (*a) = (*b);
            (*b) = (*b)->next;
            (*a)->next = tmp;
            (*a)->size = new_size_a;
            tmp = (*a);
            while (tmp->next)
            {
                tmp = tmp->next;
                tmp->size = tmp->size + 1;
            }
            if(!(*b))
                return ;
            (*b)->size = new_size_b;
            tmp = (*b);
            while (tmp->next)
            {
                tmp = tmp->next;
                tmp->size = tmp->size - 1;
            }
            return ;
            
            // tmp->next = (*b);
            // (*b) = (*b)->next;
            // tmp->next->next = NULL;
            // int new_size = (*a)->size + 1;
            // (*a)->size = new_size;
            // (*b)->size = (*b)->size - 1;
            // tmp = (*b);
            // while (tmp)
            // {
            //     tmp->size = new_size;
            //     tmp = tmp->next;
            // }
            // return ;
        }
        return ;
    }
    return ;
}

void    ft_pp(t_stack **a, t_stack **b)
{
    ft_p(a, b, 'a');
    ft_p(a, b, 'b');
    return ;
}

//rotate
void    ft_r(t_stack **a, t_stack **b, char b_a)
{
    t_stack *tmp;
    t_stack *head;
    if (b_a == 'a')
    {

        if ((*a)->size == 0)
            return ;
        if ((*a)->size == 1)
            return ;
        tmp = (*a);
        head = (*a)->next;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = (*a);
        tmp->next->next = NULL;
        (*a) = head;
        return ;
    }
    if (b_a == 'b')
    {
        if ((*b)->size == 0)
            return ;
        if ((*b)->size == 1)
            return ;
        tmp = (*b);
        head = (*b)->next;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = (*b);
        tmp->next->next = NULL;
        (*b) = head;
        return ;
    }
}

void    ft_rr(t_stack **a, t_stack **b)
{
    ft_r(a, b, 'a');
    ft_r(a, b, 'b');
    return ;
}

void    ft_rv(t_stack **a, t_stack **b, char b_a)
{
    //rotate reverse
    t_stack *tmp;
    t_stack *head;
    if (b_a == 'a')
    {
        if ((*a)->size == 0)
            return ;
        if ((*a)->size == 1)
            return ;
        head = (*a);
        while (head->next->next)
        {
            head = head->next;
        }
        tmp = head->next;
        head->next = NULL;
        tmp->next = (*a);
        (*a) = tmp;
        return ;
    }
    if (b_a == 'b')
    {
        if ((*b)->size == 0)
            return ;
        if ((*b)->size == 1)
            return ;
        head = (*b);
        while (head->next->next)
        {
            head = head->next;
        }
        tmp = head->next;
        head->next = NULL;
        tmp->next = (*b);
        (*b) = tmp;
        return ;
    }
}
