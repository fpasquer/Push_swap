/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:26:46 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/21 13:27:50 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int				get_flags(char ***argv)
{
	unsigned int			flags;

	flags = NONE;
	if (argv == NULL || *argv == NULL)
		return (flags);
	while (**argv != NULL && ***argv == '-')
	{
		if (ft_strcmp(**argv, "-v") == 0)
			flags = (flags == NONE) ? VERB : flags | VERB;
		else if (ft_strcmp(**argv, "-c") == 0)
			flags = (flags == NONE) ? COLOR : flags | COLOR;
		else if (ft_strcmp(**argv, "-nb") == 0)
			flags = (flags == NONE) ? NB_COUP : flags | NB_COUP;
		else if (ft_strcmp(**argv, "-end") == 0)
			flags = (flags == NONE) ? PRINT_END : flags | PRINT_END;
		else if (ft_strcmp(**argv, "-man") == 0)
			flags = (flags == NONE) ? MAN : flags | MAN;
		else
			break ;
		(*argv)++;
	}
	return (flags);
}
