/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:28:19 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/21 13:10:23 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							get_pivot(t_pile *a)
{
	int						min;
	int						max;
	long long int			loop;

	if (a == NULL)
		return (INT_MIN);
	min = a->nb;
	max = a->nb;
	loop = 0;
	while (a != NULL)
	{
		min = (a->nb < min) ? a->nb : min;
		max = (a->nb > max) ? a->nb : max;
		a = a->next;
		loop++;
	}
	if (loop < 10)
		return ((min + max) / 2 + 1);
	return (min + (loop * 0.1));
}

t_pile						*del_pile(t_pile **pile)
{
	t_pile					*tmp;

	if (pile == NULL || *pile == NULL)
		return (NULL);
	while (*pile != NULL)
	{
		tmp = (*pile)->next;
		ft_memdel((void**)pile);
		*pile = tmp;
	}
	return (NULL);
}

int							add_one_link(t_pile **pile, int nb)
{
	int						ret;
	t_pile					*new;
	t_pile					*curs;

	ret = 1;
	if (pile == NULL || (new = ft_memalloc(sizeof(t_pile))) == NULL)
		return (-1);
	new->nb = nb;
	if ((curs = *pile) == NULL)
		*pile = new;
	else
	{
		while (curs->next != NULL)
		{
			if (curs->nb == new->nb)
				ret = 0;
			curs = curs->next;
		}
		if (curs->nb == new->nb)
			ret = 0;
		curs->next = new;
		new->prev = curs;
	}
	return (ret);
}

t_push_swap					*init_struct(char **argv)
{
	long long int			nb;
	unsigned int			y;
	t_push_swap				*ps;

	if ((ps = ft_memalloc(sizeof(t_push_swap))) == NULL)
		return (NULL);
	y = 0;
	ps->flags = get_flags(&argv);
	if ((ps->flags & MAN) != 0)
		print_man();
	while (argv[y] != NULL)
	{
		if (ft_is_number(argv[y]) == 0)
			return (del_struct(&ps));
		nb = ft_atoi(argv[y++]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (del_struct(&ps));
		if (add_one_link(&ps->a, nb) <= 0)
			return (del_struct(&ps));
	}
	ps->len_a = y;
	return (ps);
}

t_push_swap					*del_struct(t_push_swap **ps)
{
	del_pile(&(*ps)->a);
	del_pile(&(*ps)->b);
	del_pile(&(*ps)->sort);
	ft_memdel((void**)ps);
	return (NULL);
}
