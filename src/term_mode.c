/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:53:19 by vdaviot           #+#    #+#             */
/*   Updated: 2016/01/08 20:53:20 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				set_term_cannon(void)
{
	char			*term_name;
	struct termios 	term;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (!(tgetent(NULL, term_name)))
		return (-1);
	if ((tcgetattr(0, &term)) == -1)
		return (-1);
	term.c_lflag &= (unsigned long)~(ICANON);
	term.c_lflag &= (unsigned long)~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, &term)) == -1)
		return (-1);
	return (0);
}

// void			ft_termcaps_str(t_select *selection)
// {
// 	 us = start underlining ue = end underlining 
// }
// #include <time.h>
// int			ft_is_timeout(unsigned long begin_time, unsigned long sec)
// {
// 	return ((sec >=(unsigned long)clock() - begin_time) / CLOCKS_PER_SEC));
// }

// void			ft_timer(unsigned long sec)
// {
// 	unsigned long start;
// 	unsigned long ttime;

// 	start = clock();
// 	ttime = ft_is_timeout(start, sec);
// 	if (!ttime)
// 		printf("Your % sec timer is out.", sec);
// 	else
// 		printf("You made it in %lsec !.", ttime);
// }
