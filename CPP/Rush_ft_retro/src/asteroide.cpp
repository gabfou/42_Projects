// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   asteroide.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:51 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:52 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "asteroide.hpp"

asteroide::asteroide()
{
	// int i = time(NULL) % 2;

	// if (i == 0)
	{
		setDirectionX(1);
		setDirectionY(0);
		setPosX(0);
		setPosY((int)clock() % L);
		setSizeX(1);
		setSizeY(1);
		setSpeed(20000);
		setS((char*)"o");
		setS2((char*)" ");
	}
	// if (i == 1)
	// {
	// 	setDirectionX(1);
	// 	setDirectionY(0);
	// 	setPosX(0);
	// 	setPosY((int)clock() % L);
	// 	setSizeX(2);
	// 	setSizeY(2);
	// 	setSpeed(100000);
	// 	setS((char*)"o");
	// 	setS2((char*)" ");
	// }
	// if (i == 2)
	// {
	// 	setDirectionX(1);
	// 	setDirectionY(0);
	// 	setPosX(0);
	// 	setPosY((int)clock() % L);
	// 	setSizeX(3);
	// 	setSizeY(3);
	// 	setSpeed(100000);
	// 	setS((char*)"o");
	// 	setS2((char*)" ");
	// }
}

// asteroide::asteroide(int x, int y, int x2, int y2, int s)
// {

// }

asteroide::asteroide(int x, int y, int x2, int y2)
{
	setDirectionX(x);
	setDirectionY(y);
	setPosX(x2);
	setPosY(y2);
	setSizeX(1);
	setSizeY(1);
	setSpeed(30000);
	setS((char*)"*");
	setS2((char*)" ");
}

asteroide::~asteroide()
{

}