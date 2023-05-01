/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:08:14 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/21 16:08:14 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./lib/libft.h"

typedef struct s_pile
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
}	t_pile;

int		get_inst(t_pile *pile);
int		check_sort(t_pile *pile);
int		treat_argv(t_pile *pile, int argc, char **argv);
int		check_input(char *data);
int		check_double(t_pile *pile);
void	inst_sa(t_pile *pile, int conf);
void	inst_sb(t_pile *pile, int conf);
void	inst_ss(t_pile *pile, int conf);
void	inst_pa(t_pile *pile, int conf);
void	inst_pb(t_pile *pile, int conf);
void	inst_ra(t_pile *pile, int conf);
void	inst_rb(t_pile *pile, int conf);
void	inst_rr(t_pile *pile, int conf);
void	inst_rra(t_pile *pile, int conf);
void	inst_rrb(t_pile *pile, int conf);
void	inst_rrr(t_pile *pile, int conf);
void	radix_sort(t_pile *pile);
void	three_sort(t_pile *pile);
void	five_sort(t_pile *pile);
void	replace_pile(t_pile *pile);

#endif //PUSH_SWAP_H
