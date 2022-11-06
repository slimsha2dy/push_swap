/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:50:34 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/06 16:20:34 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_num
{
	int				content;
	struct s_num	*next;
	struct s_num	*prev;
}	t_num;

typedef struct s_info
{
	int				*arr;
	int				size_a;
	struct s_num	*top_a;
	struct s_num	*bot_a;
	int				size_b;
	struct s_num	*top_b;
	struct s_num	*bot_b;
}	t_info;

int		print_err(int err_type);
t_info	*ft_info_new(void);
t_num	*ft_stack_new(void);

int		get_str_size(int ac, char **av);
int		*ft_av_to_arr(int ac, char **av, int size);
void	ft_arr_to_stack(t_info *info, int *arr, int size);
void	ft_check_arr_sort(int *arr, int size, int i);

int		get_size_spl_str(char **spl_str);
void	ft_free_str(char **str);
int		ft_atoll(const char *str);
void	set_str_to_arr(int *arr, int *arr_i, char **str);

void	ft_ra(t_info *info);
void	ra(t_info *info);
void	ft_rb(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	ft_rra(t_info *info);
void	ft_rrb(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

void	sa(t_info *info);
void	sb(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);

void	ft_sort(t_info *info);
void	ft_sort_three_case(t_info *info);
void	ft_sort_rest(t_info *info);

int		set_a_location(int num, t_info *info);
void	ft_rotate_same(t_info *info, int *a, int *b);
void	ft_rotate_a(t_info *info, int a);
void	ft_rotate_b(t_info *info, int b);

int		get_stack_min(t_num *stack);
int		get_stack_max(t_num *stack);
int		set_a_location_min(t_info *info);
int		set_a_location_max(t_info *info);
int		set_a_location_mid(int num, t_info *info);

void	ft_sort_3div(t_info *info);
void	ft_sort_3div_instruct(t_info *info, int pv1, int pv2);
void	get_min_rotate(t_info *info, int *a, int *b);
int		ft_get_faster(int a, int b, int a_loc, int b_loc);
void	ft_sort_last(t_info *info);

#endif
