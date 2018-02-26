/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:46:08 by fpasquer          #+#    #+#             */
/*   Updated: 2016/05/02 10:09:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							sa(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;37msa\033[0m", ft_strlen("\033[0;37msa\033[0m"), 0);
	else
		nb_loop("sa", 2, 0);
	return (fonc_s(&ps->a));
}

int							sb(t_push_swap *ps)
{
	nb_loop("sb", 2, 0);
	return (fonc_s(&ps->b));
}

int							ss(t_push_swap *ps)
{
	int						ret;

	nb_loop("ss", 2, 0);
	if ((ret = fonc_s(&ps->a)) < 0)
		return (ret);
	if ((ret = fonc_s(&ps->b)) < 0)
		return (ret);
	return (1);
}

int							pa(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;35mpa\033[0m", ft_strlen("\033[0;35mpa\033[0m"), 0);
	else
		nb_loop("pa", 2, 0);
	if (ps->b != NULL)
	{
		ps->len_b--;
		ps->len_a++;
	}
	return (fonc_p(&ps->a, &ps->b));
}

int							pb(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;32mpb\033[0m", ft_strlen("\033[0;32mpb\033[0m"), 0);
	else
		nb_loop("pb", 2, 0);
	if (ps->a != NULL)
	{
		ps->len_b++;
		ps->len_a--;
	}
	return (fonc_p(&ps->b, &ps->a));
}
