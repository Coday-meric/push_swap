/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:19:56 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/21 23:48:15 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inst_ra(t_pile *pile, int conf)
{
	int	i;
	int	tmp;

	if (conf == 0)
		ft_putstr_fd("ra\n", 1);
	if (pile->len_a == 0)
		return ;
	i = 0;
	tmp = pile->a[0];
	while (i < pile->len_a)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->a[i - 1] = tmp;
}

void	inst_rb(t_pile *pile, int conf)
{
	int	i;
	int	tmp;

	if (conf == 0)
		ft_putstr_fd("rb\n", 1);
	if (pile->len_b == 0)
		return ;
	i = 0;
	tmp = pile->b[0];
	while (i < pile->len_b)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->b[i - 1] = tmp;
}

void	inst_rr(t_pile *pile, int conf)
{
	if (conf == 0)
		ft_putstr_fd("rr\n", 1);
	inst_ra(pile, conf);
	inst_rb(pile, conf);
}
