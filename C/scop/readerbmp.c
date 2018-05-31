/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 05:58:23 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/11 05:58:28 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

void			reader(int fd_img, t_header *fh)
{
	if (read(fd_img, &(fh->file_marker1), sizeof(unsigned char)) < 1
		|| read(fd_img, &(fh->file_marker2), sizeof(unsigned char)) < 1
		|| read(fd_img, &(fh->bf_size), sizeof(unsigned int)) < 1
		|| read(fd_img, &(fh->unused1), sizeof(short)) < 1
		|| read(fd_img, &(fh->unused2), sizeof(short)) < 1
		|| read(fd_img, &(fh->image_data_offset), sizeof(unsigned int)) < 1
		|| read(fd_img, &(fh->bi_size), sizeof(unsigned int)) < 1
		|| read(fd_img, &(fh->width), sizeof(int)) < 1
		|| read(fd_img, &(fh->height), sizeof(int)) < 1
		|| read(fd_img, &(fh->planes), sizeof(short)) < 1
		|| read(fd_img, &(fh->bit_pix), sizeof(short)) < 1
		|| read(fd_img, &(fh->bi_compression), sizeof(unsigned int)) < 1
		|| read(fd_img, &(fh->bi_size_image), sizeof(unsigned int)) < 1
		|| read(fd_img, &(fh->bi_xpels_per_meter), sizeof(int)) < 1
		|| read(fd_img, &(fh->bi_ypels_per_meter), sizeof(int)) < 1
		|| read(fd_img, &(fh->bi_clrused), sizeof(unsigned int)) < 1
		|| read(fd_img, &(fh->bi_clr_important), sizeof(unsigned int)) < 1)
		ft_error("bmp header problem 1");
}

int				bmp_to_tex(t_header *fh, int fd)
{
	static unsigned char	*img = NULL;
	unsigned char			tmp;
	int						i;
	GLuint					tex;

	reader(fd, fh);
	if (img != NULL)
	{
		free(img);
		img = NULL;
	}
	if (fh->bit_pix != 24)
		ft_error("not a 24bit bmp file");
	img = (unsigned char*)malloc(sizeof(char) * fh->bf_size);
	i = -1;
	while (read(fd, &tmp, sizeof(unsigned char)) > 0)
		img[++i] = tmp;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, fh->width, fh->height,
		0, GL_BGR, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return (tex);
}

int				loadtex(char *name)
{
	int			i;
	int			fd;
	t_header	fh;

	i = 0;
	while (name[i] != 0)
		i++;
	if (!(i - 3 > 0
		&& name[i - 3] == 'b' && name[i - 2] == 'm' && name[i - 1] == 'p'))
		ft_error("pas un .bmp");
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error("fail ouverture de fichier 3436");
	return (bmp_to_tex(&fh, fd));
}
