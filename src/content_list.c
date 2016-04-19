/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:05:43 by vdaviot           #+#    #+#             */
/*   Updated: 2016/01/06 16:05:46 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_select				*ft_choose_word_clist(t_select *list)
{
	t_bind				key;
	t_select			*tmp;
	int					direction;

	tmp = list;
	while (42)
	{
		
		key = get_key();
		if (list->word)
			ft_putendl_db("Current", list->word);
		else
			list = (direction == 1) ? list->prev : list->next; 
		if (key.key[0] == 27 && key.key[2] == 68)
		{
			direction = 1;
			list = list->prev;
			while (list->choosed == 1)
				list = list->prev;
		}
		if (key.key[0] == 27 && key.key[2] == 67)
		{
			direction = 2;
			list = list->next;
			while (list->choosed == 1)
				list = list->next;
		}
		if (key.key[0] == SPACE && list->choosed == 0)
		{
			list->choosed = 1;
			ft_putendl_db("Choosed", list->word);
			while (list->choosed == 1)
				list = (direction == 1) ? list->prev : list->next; 
			direction = 0;
		}
		if (key.key[0] == SPACE && list->choosed == 1)
		{
			list->choosed = 0;
			ft_putendl_db("Unchoosed", list->word);
		}
		if (key.key[0] == 27 && !key.key[1] && !key.key[2])
			exit(0);
		if (key.key[0] == ESC && key.key[1] == 91 && key.key[2] == 51)
		{
			ft_putendl_db("Deleted", list->word);
			ft_hide_elem_clist(list);
		}
		if (key.key[0] == ENTER)
			break ;
	}
	return (tmp->next);
}

void				ft_destroy_clist_elem(t_select *list)
{
	list->prev->next = list->next;
	list->prev->prev = list->prev;
	free(list);
}

t_select	*ft_select_init_clist(void)
{
	t_select	*list;

	if (!(list = (t_select*)malloc(sizeof(t_select))))
		return (NULL);
	list->begin = 1;
	list->next = list;
	list->prev = list;
	return (list);
}

void		ft_hide_elem_clist(t_select *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
	list = list->next;
}

void		ft_show_elem_clist(t_select *list)
{
	list->prev->next = list;
	list->next->prev = list;
}

void		ft_add_before_root_clist(t_select *circ, char *str)
{
	t_select *tmp;

	if (!(tmp = (t_select*)malloc(sizeof(t_select))))
		return ;
	tmp->word = ft_strdup(str);
	tmp->size = ft_strlen(tmp->word);
	tmp->begin = 0;
	tmp->choosed = 0;
	tmp->prev = circ->prev;
	tmp->next = circ;
	circ->prev->next = tmp;
	circ->prev = tmp;
}

void		ft_add_after_root_clist(t_select *circ, char *str)
{
	t_select *tmp;

	if (!(tmp = (t_select*)malloc(sizeof(t_select))))
		return ;
	tmp->word = ft_strdup(str);
	tmp->size = ft_strlen(tmp->word);
	tmp->begin = 0;
	tmp->choosed = 0;
	tmp->prev = circ;
	tmp->next = circ->next;
	circ->next->prev = tmp;
	circ->next = tmp;
}
