/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:48:31 by fpasquer          #+#    #+#             */
/*   Updated: 2016/05/02 10:20:41 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define FUCK_NORM pb(*ps); return (1);

static int					upper_pivot(int pivot, t_pile *pile)
{
	int						ret;

	ret = 0;
	if (pile == NULL)
		return (-1);
	while (pile != NULL)
	{
		if (pile->nb < pivot)
			return (1);
		pile = pile->next;
	}
	return (0);
}

static int					is_smaller(int a, t_pile *b)
{
	while (b != NULL)
	{
		if (b->nb < a)
			return (0);
		b = b->next;
	}
	return (1);
}

static int					insert_in_b_2(t_push_swap **ps)
{
	t_pile					*cpy;

	if (is_smaller((*ps)->a->nb, (*ps)->b) == 1 && (*ps)->b->next != NULL)
	{
		while ((*ps)->b->nb > (*ps)->a->nb && (*ps)->b->next->nb < (*ps)->b->nb)
			rrb(*ps);
		if ((*ps)->b->next->nb > (*ps)->b->nb)
			rrb(*ps);
		FUCK_NORM;
	}
	if ((*ps)->b->nb > (*ps)->a->nb && (*ps)->b->next != NULL)
		while ((*ps)->b->nb > (*ps)->a->nb)
			rrb(*ps);
	else
	{
		cpy = (*ps)->b;
		while (cpy->next != NULL)
			cpy = cpy->next;
		while (cpy->nb < (*ps)->a->nb && cpy->nb > (*ps)->b->nb)
		{
			cpy = cpy->prev;
			rb(*ps);
		}
	}
	return (0);
}

static int					insert_in_b(t_push_swap **ps)
{
	if ((*ps)->b == NULL)
		return (0);
	if ((*ps)->b->next == NULL && (*ps)->a->nb > (*ps)->b->nb)
	{
		pb(*ps);
		if ((*ps)->b->nb < (*ps)->b->next->nb)
			rrb(*ps);
		return (1);
	}
	else
		return (insert_in_b_2(ps));
}

void						push_swap(t_push_swap *ps)
{
	while (ps->len_a > 1)
	{
		ps->pivot = get_pivot(ps->a);
		while (upper_pivot(ps->pivot, ps->a) != 0 && ps->len_a > 1)
		{
			if (ps->a->nb < ps->pivot)
			{
				if (insert_in_b(&ps) == 0)
					pb(ps);
			}
			else
				rra(ps);
			if ((ps->flags & VERB) != 0)
				print_pile_a_b(ps);
		}
	}
	if (ps->len_b > 1 && ps->b->nb < ps->b->next->nb)
		rrb(ps);
	sort_b(ps);
	while (ps->b != NULL)
	{
		pa(ps);
		if ((ps->flags & VERB) != 0)
			print_pile_a_b(ps);
	}
}
