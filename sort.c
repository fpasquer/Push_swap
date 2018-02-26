/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 11:28:52 by fpasquer          #+#    #+#             */
/*   Updated: 2016/03/31 16:20:21 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define TYPE t_pile

static TYPE					*separer_lst(TYPE *liste)
{
	TYPE		*aux;

	if (liste == NULL)
		return (NULL);
	else if (liste->next == NULL)
		return (NULL);
	else
	{
		aux = liste->next;
		liste->next = aux->next;
		aux->next = separer_lst(aux->next);
		return (aux);
	}
}

static TYPE					*fusion_lst(TYPE **lg, TYPE **ld,
		int (fonc_tri)(void *, void*))
{
	if ((*lg) == NULL)
		return (*ld);
	else if ((*ld) == NULL)
		return ((*lg));
	else if (fonc_tri(lg, ld))
	{
		(*lg)->next = fusion_lst(&(*lg)->next, ld, fonc_tri);
		return ((*lg));
	}
	else
	{
		(*ld)->next = fusion_lst(lg, &(*ld)->next, fonc_tri);
		return ((*ld));
	}
}

void						sort_list(TYPE **liste,
				int (fonc_tri)(void *, void *))
{
	TYPE			*aux;

	if ((*liste) != NULL)
		if ((*liste)->next != NULL)
		{
			aux = separer_lst(*liste);
			sort_list(liste, fonc_tri);
			sort_list(&aux, fonc_tri);
			(*liste) = fusion_lst(liste, &aux, fonc_tri);
		}
}
