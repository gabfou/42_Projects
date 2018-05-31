// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   niark.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:51 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:52 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "niark.hpp"

niark::niark()
{
	setDirectionX(1);
	setDirectionY(0);
	setPosX(0);
	setPosY((int)clock() % L);
	setSizeX(3);
	setSizeY(3);
	setSpeed(120000);
	setS((char*)"m");
	setS2((char*)" ");
}

int		niark::move(void)
{
	int t = rand() % 3;
	if (t == 0)
		setDirectionY(1);
	if (t == 1)
		setDirectionY(0);
	if (t == 2)
		setDirectionY(-1);
	if (rand() % 300)
		newlaser(1, 0, getPosX() + 5, getPosY());
	this->MovingStuff::move();
	return (0);
}

niark::~niark()
{

}