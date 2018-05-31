/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MovingStuff.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmar <jdelmar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 03:00:12 by jdelmar           #+#    #+#             */
/*   Updated: 2015/11/08 03:38:28 by jdelmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVINGSTUFF_HPP
#define MOVINGSTUFF_HPP
# include <iostream>
# include <string>
#include <curses.h>

#define L 105
#define H 55

class		MovingStuff
{
	private:
		int	_posX;
		int	_posY;
		unsigned int	_speed;
		int	_sizeX;
		int	_sizeY;
		int	_directionX;
		int	_directionY;
		clock_t c;
		char *s;
		char *s2;

	public:
		MovingStuff();
		MovingStuff(const MovingStuff&);
		virtual ~MovingStuff(void);

		MovingStuff &	operator=(MovingStuff const & src);

		virtual int	move(void);

		bool	checkColision(MovingStuff const & mov);

		int	getPosX(void) const;
		void	setPosX(int tmp);

		int	getPosY(void) const;
		void	setPosY(int tmp);

		unsigned int	getSpeed(void) const;
		void	setSpeed(unsigned int tmp);

		int	getSizeX(void) const;
		void	setSizeX(int tmp);

		int	getSizeY(void) const;
		void	setSizeY(int tmp);

		int	getDirectionX(void) const;
		void	setDirectionX(int tmp);

		int	getDirectionY(void) const;
		void	setDirectionY(int tmp);

		char *	getS(void) const;
		void	setS(char * tmp);

		char *	getS2(void) const;
		void	setS2(char * tmp);
};

std::ostream &	operator<<(std::ostream & o, MovingStuff const & r);

#endif
