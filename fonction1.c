/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 10:16:08 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/21 17:42:57 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							rb(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;34mrb\033[0m", ft_strlen("\033[0;34mrb\033[0m"), 0);
	else
		nb_loop("rb", 2, 0);
	return (fonc_r(&ps->b));
}

int							rr(t_push_swap *ps)
{
	int						ret;

	nb_loop("rr", 2, 0);
	if ((ret = fonc_r(&ps->a)) < 0)
		return (ret);
	if ((ret = fonc_r(&ps->b)) < 0)
		return (ret);
	return (1);
}

int							rra(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;31mrra\033[0m", ft_strlen("\033[0;31mrra\033[0m"), 0);
	else
		nb_loop("rra", 3, 0);
	return (fonc_rev(&ps->a));
}

int							rrb(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;33mrrb\033[0m", ft_strlen("\033[0;33mrrb\033[0m"), 0);
	else
		nb_loop("rrb", 3, 0);
	return (fonc_rev(&ps->b));
}

int							rrr(t_push_swap *ps)
{
	int						ret;

	nb_loop("rrr", 3, 0);
	if ((ret = fonc_rev(&ps->a)) < 0)
		return (ret);
	if ((ret = fonc_rev(&ps->b)) < 0)
		return (ret);
	return (1);
}
