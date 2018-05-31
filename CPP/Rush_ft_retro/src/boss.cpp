// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   boss.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:51 by gfournie          #+#    #+#             //
/*   Updated: 2015/11/08 21:49:39 by jdelmar          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "boss.hpp"

boss::boss()
{
	setDirectionX(0);
	setDirectionY(0);
	setPosX(0);
	setPosY((L / 2) -10);
	setSizeX(2);
	setSizeY(20);
	setSpeed(120000);
	setS((char*)"b");
	setS2((char*)" ");
}

int		boss::move(void)
{
	int t = rand() % 3;
	if (t == 0)
		setDirectionY(1);
	if (t == 1)
		setDirectionY(0);
	if (t == 2)
		setDirectionY(-1);
	if (rand() % 5  == 0)
	{
		t = rand();
		t = t % 3;
		if (t == 0)
			newlaser(1, 1, getPosX() + 3, getPosY() + (rand() % 20));
		if (t == 1)
			newlaser(1, 0, getPosX() + 3, getPosY() + (rand() % 20));
		if (t == 2)
			newlaser(1, -1, getPosX() + 3, getPosY() + (rand() % 20));
	}
	this->MovingStuff::move();
	return (0);
}

boss::~boss()
{

}
