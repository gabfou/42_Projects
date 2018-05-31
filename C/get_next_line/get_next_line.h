/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:54:29 by gfournie          #+#    #+#             */
/*   Updated: 2015/01/15 19:31:32 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 10000

typedef	struct	s_btree
{
	struct s_btree	*right;
	char			*item;
	int				n;
	int				fd;
}				t_btree;

int				get_next_line(int const fd, char **line);

#endif
