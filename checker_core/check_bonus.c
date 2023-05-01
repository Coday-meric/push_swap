/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:22:11 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/23 18:22:11 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../lib/gnl/get_next_line.h"

static int	exec_inst(char *res, t_pile *pile)
{
	if (res[0] == 's' && res[1] == 'a' && res[2] == '\n')
		inst_sa(pile, 1);
	else if (res[0] == 's' && res[1] == 'b' && res[2] == '\n')
		inst_sb(pile, 1);
	else if (res[0] == 's' && res[1] == 's' && res[2] == '\n')
		inst_ss(pile, 1);
	else if (res[0] == 'p' && res[1] == 'a' && res[2] == '\n')
		inst_pa(pile, 1);
	else if (res[0] == 'p' && res[1] == 'b' && res[2] == '\n')
		inst_pb(pile, 1);
	else if (res[0] == 'r' && res[1] == 'a' && res[2] == '\n')
		inst_ra(pile, 1);
	else if (res[0] == 'r' && res[1] == 'b' && res[2] == '\n')
		inst_rb(pile, 1);
	else if (res[0] == 'r' && res[1] == 'r' && res[2] == '\n')
		inst_rr(pile, 1);
	else if (res[0] == 'r' && res[1] == 'r' && res[2] == 'a' && res[3] == '\n')
		inst_rra(pile, 1);
	else if (res[0] == 'r' && res[1] == 'r' && res[2] == 'b' && res[3] == '\n')
		inst_rrb(pile, 1);
	else if (res[0] == 'r' && res[1] == 'r' && res[2] == 'r' && res[3] == '\n')
		inst_rrr(pile, 1);
	else
		return (0);
	return (1);
}

int	get_inst(t_pile *pile)
{
	char	*res;

	res = get_next_line(0);
	while (res != NULL)
	{
		if (exec_inst(res, pile) == 0)
		{
			free(res);
			return (0);
		}
		free(res);
		res = get_next_line(0);
	}
	return (1);
}
