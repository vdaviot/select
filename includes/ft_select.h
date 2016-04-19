/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:05:16 by vdaviot           #+#    #+#             */
/*   Updated: 2016/01/06 16:05:17 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# define SPACE 32
# define ESC 27
# define ENTER 10
# define ARROW 91
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

typedef	struct  s_select
{
	struct s_select *next;
	struct s_select	*prev;
	int			choosed;
	int			begin;
	size_t			size;
	void		*word;
}				t_select;

typedef	struct	s_bind
{
	char	key[3];
}				t_bind;

typedef struct  s_display
{
	int			maxsize;
	int			nb;
}				t_display;

t_bind			get_key(void);
t_select		*ft_choose_word_clist(t_select *list);
t_select		*ft_select_init_clist(void);
int				set_term_cannon(void);
void			ft_add_before_root_clist(t_select *circ, char *str);
void			ft_add_after_root_clist(t_select *circ, char *str);
void			ft_hide_elem_clist(t_select *list);
void			ft_show_elem_clist(t_select *list);
t_select		*fill_return_list(t_select *list);
void			ft_destroy_clist_elem(t_select *list);
void			ft_destroy_clist(t_select *to_destruct);
t_list			*ft_list_create(void *data);
t_list			*ft_list_addend(t_list *list, void *data);
void			print_list(t_select *list);

#endif
