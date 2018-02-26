/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_standard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:06:56 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/21 10:31:36 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile				*end_pile(t_pile **pile)
{
	t_pile					*end;
	t_pile					*curs;

	end = NULL;
	if (pile == NULL)
		return (NULL);
	curs = *pile;
	while (curs != NULL)
	{
		end = curs;
		curs = curs->next;
	}
	return (end);
}

int							fonc_s(t_pile **pile)
{
	int						tmp;

	if (pile == NULL)
		return (-1);
	if (*pile == NULL || (*pile)->next == NULL)
		return (0);
	tmp = (*pile)->next->nb;
	(*pile)->next->nb = (*pile)->nb;
	(*pile)->nb = tmp;
	return (1);
}

int							fonc_p(t_pile **dest, t_pile **src)
{
	t_pile					*tmp;

	if (src == NULL || dest == NULL)
		return (-1);
	if (*src == NULL)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	if ((*src) != NULL)
		(*src)->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = tmp;
	tmp->next = *dest;
	*dest = tmp;
	return (1);
}

int							fonc_r(t_pile **pile)
{
	t_pile					*end;

	if (pile == NULL)
		return (-1);
	if (*pile == NULL || (*pile)->next == NULL)
		return (0);
	if ((end = end_pile(pile)) == NULL)
		return (-1);
	end->prev->next = NULL;
	end->next = *pile;
	*pile = end;
	return (1);
}

int							fonc_rev(t_pile **pile)
{
	t_pile					*end;
	t_pile					*tmp;

	if (pile == NULL)
		return (-1);
	if (*pile == NULL || (*pile)->next == NULL)
		return (0);
	if ((end = end_pile(pile)) == NULL)
		return (-1);
	tmp = (*pile)->next;
	tmp->prev = NULL;
	end->next = *pile;
	(*pile)->prev = end;
	(*pile)->next = NULL;
	*pile = tmp;
	return (1);
}
