/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:15:11 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/04 22:13:36 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a->content;
	info->top_a->content = info->top_a->next->content;
	info->top_a->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b->content;
	info->top_b->content = info->top_b->next->content;
	info->top_b->content = tmp;
	write(1, "sb\n", 3);
}

void	pa(t_info *info)
{
	t_num	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->top_b;
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->top_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		tmp->next = NULL;
		info->top_a = tmp;
		info->bot_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a->prev = tmp;
		info->top_a = tmp;
	}
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	t_num	*tmp;

	if (info->size_a < 1)
		return ;
	tmp = info->top_a;
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->next;
		info->top_a->prev = NULL;
	}
	if (info->size_b == 0)
	{
		tmp->next = NULL;
		info->top_b->prev = tmp;
		info->top_b = tmp;
	}
	info->size_a -= 1;
	info->size_b += 1;
	write(1, "pb\n", 3);
}
