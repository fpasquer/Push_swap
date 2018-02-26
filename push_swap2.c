/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:21:58 by fpasquer          #+#    #+#             */
/*   Updated: 2016/05/02 10:10:27 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							len_is_3(t_push_swap *ps)
{
	if (ps->a->nb > ps->a->next->nb && ps->a->next->nb > ps->a->next->next->nb)
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->a->nb < ps->a->next->nb && ps->a->next->next->nb > ps->a->nb)
	{
		ra(ps);
		sa(ps);
	}
	else if (ps->a->nb > ps->a->next->nb && ps->a->next->next->nb > ps->a->nb)
		sa(ps);
	else if (ps->a->nb < ps->a->next->nb && ps->a->next->next->nb < ps->a->nb)
		ra(ps);
	else if (ps->a->nb > ps->a->next->nb && ps->a->next->nb <
		ps->a->next->next->nb)
		rra(ps);
	return (1);
}

int							sort_until_the_last_one(t_pile *a)
{
	int						nb_prev;

	nb_prev = a->nb;
	while (a != NULL)
	{
		if (a->nb < nb_prev)
			break ;
		nb_prev = a->nb;
		a = a->next;
	}
	return ((a->next == NULL) ? 1 : 0);
}

int							sort_without_the_first(t_pile *a)
{
	int						nb_prev;

	if (a->nb > a->next->nb)
	{
		a = a->next;
		nb_prev = a->nb;
		while (a != NULL)
		{
			if (a->nb < nb_prev)
				return (0);
			nb_prev = a->nb;
			a = a->next;
		}
		return (1);
	}
	else
		return (0);
}

int							exeption(t_push_swap *ps)
{
	if (check_crois(ps->a) == 0)
		return (1);
	if (ps->len_a == 3)
		return (len_is_3(ps));
	if (sort_until_the_last_one(ps->a) == 1)
	{
		ra(ps);
		ra(ps);
		sa(ps);
		rra(ps);
		rra(ps);
		return (1);
	}
	if (sort_without_the_first(ps->a) == 1)
	{
		sa(ps);
		return (1);
	}
	return (0);
}
