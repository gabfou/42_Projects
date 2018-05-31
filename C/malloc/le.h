/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:45:10 by gfournie          #+#    #+#             */
/*   Updated: 2017/07/22 17:45:13 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_H
# define LE_H

# include <unistd.h>

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			*reallocf(void *ptr, size_t size);
void			free(void *ptr);
void			*calloc(size_t count, size_t size);
void			*valloc(size_t size);
void			show_alloc_mem();

#endif
