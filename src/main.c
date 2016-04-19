/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:05:23 by vdaviot           #+#    #+#             */
/*   Updated: 2016/01/06 16:05:25 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"


void				ft_display_selection(t_select *selection)
{
	int				maxsize;
	int				tmp;
	int				nb;

	maxsize = 0;
	nb = 0;
	selection = selection->next;
	while (selection)
	{
		if (selection->choosed == 1)
			nb++;
		if ((int)selection->size > maxsize)
			maxsize = selection->size;
		if (selection->begin == 1)
			break ;
		selection = selection->next;
	}
	maxsize += 2;
	selection = selection->next;
	ft_putendl("Choices :\n");
	while (selection->begin != 1)
	{
		tmp = maxsize;
		while (selection->choosed == 0)
			selection = selection->next;
		if (selection->choosed == 1 && nb != 0)
		{
			ft_putstr(selection->word);
			nb--;
		}
		while (tmp-- > (int)selection->size && tmp >= 0 && nb)
			ft_putchar(' ');
		selection = selection->next;
	}
	// ft_termcaps_str(selection->next, maxsize);
}

t_bind				get_key(void)
{
	t_bind			key;

	read(0, key.key, 3);
	return (key);
}

int		main(int ac, char **av)
{
	int				i;
	t_select		*circ;

	i = 0;
	if (ac > 1)
	{
		set_term_cannon();
		circ = ft_select_init_clist();
		while (av[++i])
		{
			ft_add_after_root_clist(circ, av[i]);
			circ = circ->next;
		}
		ft_display_selection(ft_choose_word_clist(circ));
	}
	return (0);
}
