/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:14:48 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/23 00:14:48 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_pile *pile)
{
	int	i;

	i = 0;
	if (pile->len_b != 0)
		return (0);
	while (i < pile->len_a - 1)
	{
		if (pile->a[i] > pile->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
