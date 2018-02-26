/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:17:29 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/22 13:27:48 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define SIZE_TAB 100000

long long int				nb_loop(char *str, size_t len, int print)
{
	static char				tab[SIZE_TAB];
	static long long int	loop;
	static unsigned int		i;
	size_t					j;

	if (print == 1 || i + len + 1 > SIZE_TAB)
	{
		write(1, tab, i);
		i = 0;
	}
	if (print != 1)
	{
		j = 0;
		if (loop++ > 0)
			tab[i++] = ' ';
		while (j < len)
			tab[i++] = str[j++];
	}
	return (loop);
}

int							print_pile(t_pile *pile)
{
	int						i;

	i = -1;
	while (pile != NULL)
	{
		i = 1;
		ft_putnbr(pile->nb);
		if ((pile = pile->next) != NULL)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (i);
}

int							error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

void						print_pile_a_b(t_push_swap *ps)
{
	ft_putstr("\npile a : ");
	print_pile(ps->a);
	ft_putstr("pile b : ");
	print_pile(ps->b);
}

int							main(int argc, char **argv)
{
	long long int			loop;
	t_push_swap				*ps;

	if (argc < 2)
		return (error());
	if ((ps = init_struct(&argv[1])) == NULL)
		return (error());
	if (exeption(ps) == 0)
		push_swap(ps);
	loop = nb_loop("", 0, 1);
	ft_putchar('\n');
	if ((ps->flags & NB_COUP) != 0)
	{
		ft_putstr("Nombre d'opperation(s) : ");
		ft_putnbr(loop);
		ft_putchar('\n');
	}
	if ((ps->flags & PRINT_END) != 0)
		print_pile_a_b(ps);
	del_struct(&ps);
	return (0);
}
