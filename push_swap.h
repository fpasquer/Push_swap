/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:21:06 by fpasquer          #+#    #+#             */
/*   Updated: 2016/05/02 10:24:08 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

/*
**	NONE affiche juste les operations
**	VERB affiche les piles a chaques operations
**	COLOR s'utilise avec VERB, place la derniere operations en rouge
**	NB_COUP affiche le nombre de coup pour trier les valeurs
**	PRINT_END affiche les piles triees une fois les operations finies
**	MAN affiche les options possibles
*/

# define NONE 0
# define VERB 1
# define COLOR 2
# define NB_COUP 4
# define PRINT_END 8
# define MAN 16

typedef struct				s_pile
{
	int						nb;
	struct s_pile			*next;
	struct s_pile			*prev;
}							t_pile;

typedef struct				s_push_swap
{
	t_pile					*a;
	t_pile					*b;
	t_pile					*sort;
	int						pivot;
	unsigned int			len_a;
	unsigned int			len_b;
	unsigned int			flags;
}							t_push_swap;

t_push_swap					*init_struct(char **argv);
int							add_one_link(t_pile **pile, int nb);
int							print_pile(t_pile *pile);
t_push_swap					*del_struct(t_push_swap **ps);
void						print_pile_a_b(t_push_swap *ps);
void						push_swap(t_push_swap *ps);
long long int				nb_loop(char *str, size_t len, int print);
unsigned int				get_flags(char ***argv);
t_pile						*del_pile(t_pile **pile);
int							check_crois(t_pile *pile);
int							exeption(t_push_swap *ps);

void						print_man(void);

int							sa(t_push_swap *ps);
int							sb(t_push_swap *ps);
int							ss(t_push_swap *ps);
int							pa(t_push_swap *ps);
int							pb(t_push_swap *ps);
int							ra(t_push_swap *ps);
int							rb(t_push_swap *ps);
int							rr(t_push_swap *ps);
int							rra(t_push_swap *ps);
int							rrb(t_push_swap *ps);
int							rrr(t_push_swap *ps);

void						print_pile_a_b(t_push_swap *ps);

int							fonc_s(t_pile **pile);
int							fonc_p(t_pile **dest, t_pile **src);
int							fonc_r(t_pile **pile);
int							fonc_rev(t_pile **pile);

int							crois(void *a, void *b);
void						sort_list(t_pile **liste,
				int (fonc_tri)(void *, void *));
int							get_pivot(t_pile *a);
void						sort_b(t_push_swap *ps);

#endif
