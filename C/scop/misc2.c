/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 02:26:42 by gfournie          #+#    #+#             */
/*   Updated: 2017/08/25 02:26:43 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

static void	cpby3(float *i, float *j)
{
	i[0] = j[0];
	i[1] = j[1];
	i[2] = j[2];
}

char		*newvertexintr(char *line, t_read *r, int j)
{
	int		i;

	while (ISWHITESPACE)
		line++;
	if ((i = ft_fatoi(line)) > 0 && i < LIMIT)
		cpby3(&(r->r[j]), &(r->v[i * 3]));
	else if (i < 0 && r->i + i * 3 + 0 > 0)
		cpby3(&(r->r[j]), &(r->v[r->i + i * 3 + 0]));
	while (!(ISWHITESPACE || *line == '\0' || *line == '/'))
		line++;
	if (*line == '/' && ((i = ft_fatoi(++line)) > 0 && i < LIMIT))
		cpby3(&(r->r[j + 3]), &(r->vt[i * 3]));
	else if (i < 0 && r->k + i * 3 + 0 > 0)
		cpby3(&(r->r[j + 3]), &(r->vt[r->k + i * 3 + 0]));
	while (!(ISWHITESPACE || *line == '\0' || *line == '/'))
		line++;
	if (*line == '/' && ((i = ft_fatoi(++line)) > 0 && i < LIMIT))
		cpby3(&(r->r[j + 6]), &(r->vn[i * 3]));
	else if (i < 0 && r->j + i * 3 + 0 > 0)
		cpby3(&(r->r[j + 6]), &(r->vn[r->j + i * 3 + 0]));
	while (!(ISWHITESPACE || *line == '\0'))
		line++;
	return (line);
}

void		recalcnorm(float *tr)
{
	float tmp[6];

	tmp[0] = tr[9] - tr[0];
	tmp[1] = tr[10] - tr[1];
	tmp[2] = tr[11] - tr[2];
	tmp[3] = tr[18] - tr[0];
	tmp[4] = tr[19] - tr[1];
	tmp[5] = tr[20] - tr[2];
	tr[6] = tmp[1] * tmp[5] - tmp[2] * tmp[4];
	tr[7] = tmp[2] * tmp[3] - tmp[0] * tmp[5];
	tr[8] = tmp[0] * tmp[4] - tmp[1] * tmp[3];
	tr[15] = tr[6];
	tr[16] = tr[7];
	tr[17] = tr[8];
	tr[24] = tr[6];
	tr[25] = tr[7];
	tr[26] = tr[8];
}

void		newtriangleobj(char *line, t_read *r, int *j)
{
	char *line2;
	char *line3;

	line2 = line;
	line = newvertexintr(line, r, (*j) * 27);
	line = newvertexintr(line, r, (*j) * 27 + 9);
	line3 = line;
	line = newvertexintr(line, r, (*j) * 27 + 18);
	if (r->r[(*j) * 27 + 6] == 0 && r->r[(*j) * 27 + 7] == 0
		&& r->r[(*j) * 27 + 8] == 0)
		recalcnorm(&(r->r[(*j) * 27]));
	(*j)++;
	while (ISWHITESPACE)
		line++;
	if (*line != '\0')
	{
		newvertexintr(line2, r, (*j) * 27);
		newvertexintr(line3, r, (*j) * 27 + 9);
		newvertexintr(line, r, (*j) * 27 + 18);
		recalcnorm(&(r->r[(*j) * 27]));
		(*j)++;
	}
}
