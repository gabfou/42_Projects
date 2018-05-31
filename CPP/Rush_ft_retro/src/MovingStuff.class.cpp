/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MovingStuff.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmar <jdelmar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 03:00:18 by jdelmar           #+#    #+#             */
/*   Updated: 2015/11/08 03:49:11 by jdelmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MovingStuff.class.hpp"


MovingStuff::MovingStuff(void)
{
	this->c = clock();
}

MovingStuff::MovingStuff(MovingStuff const & src)
{
	*this = src;
}

MovingStuff::~MovingStuff(void)
{
}

int		MovingStuff::move(void)
{
	int x = -1;
	int y = -1;
	clock_t tmp = clock();

	if (tmp - this->c > this->_speed)
	{
		while(++x < this->getSizeX())
		{
			y = -1;
			while (++y < this->getSizeY())
			{
				mvprintw(this->_posX + x,  this->_posY + y, (const char*)(this->s2));
			}
		}
		this->_posX += this->_directionX;
		this->_posY += this->_directionY;
		this->c += this->_speed;
	}
	if (this->_posX + this->getSizeX() > H || this->_posY + this->getSizeY() > L || this->_posX + this->getSizeX() < 0 || this->_posY + this->getSizeY() < 0)
		return (1);
	x = -1;
	while(++x < this->getSizeX())
	{
		y = -1;
		while (++y < this->getSizeY())
		{
			mvprintw(this->_posX + x,  this->_posY + y, (const char*)(this->s));
		}
	}
	return (0);
}

bool		MovingStuff::checkColision(MovingStuff const & mov)
{
	if ((this->_posX >= mov.getPosX() && this->_posX <= mov.getPosX() + 1) && (this->_posY >= mov.getPosY() && this->_posY <= mov.getPosY() + 1))
		return (1);
	return 0;
}


MovingStuff &	MovingStuff::operator=(MovingStuff const & src)
{
//	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->_posX = src.getPosX();
		this->_posY = src.getPosY(); 
		this->_speed = src.getSpeed();
		this->_sizeX = src.getSizeX();
		this->_sizeY = src.getSizeY();
		this->_directionX = src.getDirectionX();
		this->_directionY = src.getDirectionY();
	}
	return (*this);
}

int		MovingStuff::getPosX(void) const { return (this->_posX); }
void		MovingStuff::setPosX(int tmp) { this->_posX = tmp; }

int		MovingStuff::getPosY(void) const { return (this->_posY); }
void		MovingStuff::setPosY(int tmp) { this->_posY = tmp; }

unsigned int		MovingStuff::getSpeed(void) const { return (this->_speed); }
void		MovingStuff::setSpeed(unsigned int tmp) { this->_speed = tmp; }

int		MovingStuff::getSizeX(void) const { return (this->_sizeX); }
void		MovingStuff::setSizeX(int tmp) { this->_sizeX = tmp; }

int		MovingStuff::getSizeY(void) const { return (this->_sizeY); }
void		MovingStuff::setSizeY(int tmp) { this->_sizeY = tmp; }

int		MovingStuff::getDirectionX(void) const { return (this->_directionX); }
void		MovingStuff::setDirectionX(int tmp) { this->_directionX = tmp; }

int		MovingStuff::getDirectionY(void) const { return (this->_directionY); }
void		MovingStuff::setDirectionY(int tmp) { this->_directionY = tmp; }

char *		MovingStuff::getS(void) const { return (this->s); }
void		MovingStuff::setS(char * tmp) { this->s = tmp; }

char *		MovingStuff::getS2(void) const { return (this->s2); }
void		MovingStuff::setS2(char * tmp) { this->s2 = tmp; }

std::ostream &	operator<<(std::ostream & o, MovingStuff const & r)
{
	o << "tostring of the class" << std::endl;
	(void)r;
	return (o);
}
