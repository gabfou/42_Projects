/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:45:10 by gfournie          #+#    #+#             */
/*   Updated: 2017/07/22 17:45:13 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include "libft/libft.h"
# include <pthread.h>
# include <malloc/malloc.h>
# include <dlfcn.h>

# define NBC 2048
# define NO	8192
# define NT NO + sizeof(t_p)
# define N NO / 512
# define NC NO / NBC
# define MO 1048576
# define MT MO + sizeof(t_p)
# define M MO / 512
# define MC MO / NBC

typedef struct	s_p
{
	void			*begin;
	size_t			size;
	size_t			size_chunk;
	size_t			sizereal;
	char			chunk[NBC];
	struct s_p		*next;
}				t_p;

typedef struct	s_bloc
{
	size_t				size;
	void				*begin;
	void				*end;
	struct s_bloc		*next;
}				t_bloc;

typedef struct	s_b
{
	void			*begin;
	size_t			size;
	size_t			sizereal;
	struct s_b		*next;
}				t_b;

typedef	struct	s_g
{
	t_p		*tiny;
	t_p		*small;
	t_b		*large;
}				t_g;

extern t_g				g_g;
extern pthread_mutex_t	g_mutex;

void			ft_error(char *s);
int				ft_freelittlefound(void *ptr, t_p *p, t_p *before, t_p **begin);
void			*returnmutexsafe(void *s);
void			ft_remplitjusqua(char *s, char c, char end, char limit);
void			*realloctrytofit(void *ptr, t_p *found, size_t size);
void			ft_putptr(void *src);
void			ft_addbigp(size_t size, void *ptr, void *addr, size_t sizereal);
void			*ft_malloc(size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			*ft_reallocf(void *ptr, size_t size);
void			ft_free(void *ptr);
void			*ft_calloc(size_t count, size_t size);
void			*ft_valloc(size_t size);

#endif
