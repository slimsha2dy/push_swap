/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:15:20 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/07 16:25:43 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_info *info)
{
	t_num	*tmp;

	tmp = info->bot_a;
	info->bot_a = info->bot_a->prev;
	info->bot_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
}

void	rra(t_info *info)
{
	if (info->size_a < 2)
		return ;
	ft_rra(info);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_info *info)
{
	t_num	*tmp;

	tmp = info->bot_b;
	info->bot_b = info->bot_b->prev;
	info->bot_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
}

void	rrb(t_info *info)
{
	if (info->size_b < 2)
		return ;
	ft_rrb(info);
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	if (info->size_a < 2 || info->size_b < 2)
		return ;
	ft_rra(info);
	ft_rrb(info);
	write(1, "rrr\n", 4);
}
