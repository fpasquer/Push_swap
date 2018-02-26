/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:47:14 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/22 13:37:03 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							ra(t_push_swap *ps)
{
	if ((ps->flags & COLOR) != 0)
		nb_loop("\033[0;36mra\033[0m", ft_strlen("\033[0;36mrb\033[0m"), 0);
	else
		nb_loop("ra", 2, 0);
	return (fonc_r(&ps->a));
}

void						print_man(void)
{
	ft_putstr("*********************************\n          Push swap man\n");
	ft_putstr("*********************************\n\n-v : Verbose mode :\n");
	ft_putstr("\tprint pile a and b at every loop\n-c : Color mode :\n");
	ft_putstr("\teach operations have a own color\n-nb : operation numb");
	ft_putstr("er :\n\tprint the number of operation(s)\n-end : print en");
	ft_putstr("d :\n\tprint pile a and b one time sort\n-man : man : \n");
	ft_putstr("\tprint push swap man \n\nExemple :\n\t./push_swap -v -c +nb\n");
}
