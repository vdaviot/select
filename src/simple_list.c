/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:39:08 by vdaviot           #+#    #+#             */
/*   Updated: 2016/01/11 17:39:11 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_list			*ft_list_addend(t_list *list, void *data)
{
	t_list		*tmp;
	t_list		*plist;

	plist = ft_list_create(data);
	if (!list)
		return (plist);
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = plist;
	}
	return (list);
}

void		print_list(t_select *list)
{
	ft_putendl("\nYou choosed: ");
	while (42)
	{
		if (list->choosed == 1)
		{
			printf("%s de taille %zu.\n",list->word, list->size);
		}
		list = list->next;
		if (list->begin == 1)
			break ;
	}
}

void		ft_destroy_clist(t_select *to_destruct)
{
	t_select	*tmp;

	tmp = to_destruct;
	to_destruct = to_destruct->next;
	while (to_destruct->begin != 1)
	{
		free(tmp);
		tmp = to_destruct;
		if (to_destruct->next->begin != 1)
			to_destruct = to_destruct->next;
	}
}

t_list			*ft_list_create(void *data)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}