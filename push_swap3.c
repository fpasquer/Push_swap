/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 10:18:04 by fpasquer          #+#    #+#             */
/*   Updated: 2016/05/02 10:20:31 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							check_crois(t_pile *pile)
{
	int						nb_curent;
	int						nb_prev;
	int						ret;

	if (pile == NULL)
		return (-1);
	if (pile->next == NULL)
		return (0);
	nb_prev = pile->nb;
	pile = pile->next;
	ret = 0;
	while (pile != NULL)
	{
		nb_curent = pile->nb;
		if (nb_curent < nb_prev)
			ret++;
		nb_prev = nb_curent;
		pile = pile->next;
	}
	return (ret);
}

void						sort_b(t_push_swap *ps)
{
	t_pile					*cpy_b;

	if (ps->b == NULL || ps->b->next == NULL)
		return ;
	cpy_b = ps->b;
	while (cpy_b->next != NULL)
		cpy_b = cpy_b->next;
	while (cpy_b->nb > ps->b->nb)
	{
		cpy_b = cpy_b->prev;
		rb(ps);
	}
}
