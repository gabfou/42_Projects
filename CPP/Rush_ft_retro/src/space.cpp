// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   space.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:51 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:52 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "space.hpp"

space::space()
{
	setDirectionX(0);
	setDirectionY(0);
	setPosX(50);
	setPosY(100);
	setSizeX(2);
	setSizeY(3);
	setSpeed(1);
	this->mana = 50;
}

int space::getation(void)
{
	int ch = getch();
	if (ch == KEY_UP)
	{
		if (getPosX() > 3)
			setDirectionX(-1);
	}
	else if (ch == KEY_DOWN)
	{
		if (getPosX() < H - getSizeX() - 1)
			setDirectionX(1);
	}
	else if (ch == 27)
	{
		return (0);
	}
	else if (ch == KEY_LEFT)
	{
		if (getPosY() > 4)
			setDirectionY(-1);
	}
	else if (ch == KEY_RIGHT)
	{
		if (getPosY() < L - 4)
			setDirectionY(1);
	}
	else if (ch == ' ')
	{
		newlaser(-1, 0, getPosX() -2, getPosY());
	}
	else if (ch == 'z' && this->mana > 0)
	{
		this->mana -=  1;
		newlaser(-1, 0, getPosX() -2, getPosY());//dsad
		newlaser(-1, 0, getPosX() -2, getPosY() + 1);
		newlaser(-1, 0, getPosX() -2, getPosY() - 1);
		newlaser(-1, 0, getPosX() -2, getPosY() + 2);
		newlaser(-1, 0, getPosX() -2, getPosY()- 2);
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
		// newlaser(-1, 0, getPosX() -2, getPosY());
	}
	else if (ch == 'x' && this->mana > 9)
	{
		this->mana -=  10;
		newlaser(-1, 0, H / 2     , L / 2 + 1);//dsad
		newlaser(-1, 0, H / 2 + 1 , L / 2 + 1);
		newlaser(-1, 1, H / 2 + 2 , L / 2 + 1);
		newlaser(1, 0, H / 2 + 2 , L / 2);
		newlaser(1, 0, H / 2 + 2 , L / 2 - 1);
		newlaser(1, 1, H / 2 + 2 , L / 2 - 2);
		newlaser(1, 0, H / 2 + 1 , L / 2 - 2);
		newlaser(1, 0, H / 2     , L / 2 - 2);
		newlaser(1, -1, H / 2 - 1 , L / 2 - 2);
		newlaser(-1, 0, H / 2 - 1 , L / 2 - 1);
		newlaser(0, -1, H / 2 - 1 , L / 2);
		newlaser(1, 0, H / 2 - 1 , L / 2 + 1);

		newlaser(-1, 0, 20 + H / 2     , L / 2 + 1);//dsad
		newlaser(-1, 0, 20 + H / 2 + 1 , L / 2 + 1);
		newlaser(-1, 1, 20 + H / 2 + 2 , L / 2 + 1);
		newlaser(1, 0, 20 + H / 2 + 2 , L / 2);
		newlaser(1, 0, 20 + H / 2 + 2 , L / 2 - 1);
		newlaser(1, 1, 20 + H / 2 + 2 , L / 2 - 2);
		newlaser(1, 0, 20 + H / 2 + 1 , L / 2 - 2);
		newlaser(1, 0, 20 + H / 2     , L / 2 - 2);
		newlaser(1, -1, 20 + H / 2 - 1 , L / 2 - 2);
		newlaser(-1, 0, 20 + H / 2 - 1 , L / 2 - 1);
		newlaser(-1, 0, 20 + H / 2 - 1 , L / 2);
		newlaser(1, 0, 20 + H / 2 - 1 , L / 2 + 1);

		newlaser(-1, 0, H / 2 - 20     , L / 2 + 1);//dsad
		newlaser(-1, 0, H / 2 - 20 + 1 , L / 2 + 1);
		newlaser(-1, 1, H / 2 - 20 + 2 , L / 2 + 1);
		newlaser(1, 0, H / 2 - 20 + 2 , L / 2);
		newlaser(1, 0, H / 2 - 20 + 2 , L / 2 - 1);
		newlaser(1, 1, H / 2 - 20 + 2 , L / 2 - 2);
		newlaser(1, 0, H / 2 - 20 + 1 , L / 2 - 2);
		newlaser(1, 0, H / 2 - 20     , L / 2 - 2);
		newlaser(1, -1, H / 2 - 20 - 1 , L / 2 - 2);
		newlaser(-1, 0, H / 2 - 20 - 1 , L / 2 - 1);
		newlaser(-1, 0, H / 2 - 20 - 1 , L / 2);
		newlaser(1, 0, H / 2 - 20 - 1 , L / 2 + 1);

		newlaser(-1, 0, H / 2     , L / 2 + 20 + 1);//dsad
		newlaser(-1, 0, H / 2 + 1 , L / 2 + 20 + 1);
		newlaser(-1, 1, H / 2 + 2 , L / 2 + 20 + 1);
		newlaser(1, 0, H / 2 + 2 , L / 2 + 20);
		newlaser(1, 0, H / 2 + 2 , L / 2 + 20 - 1);
		newlaser(1, 1, H / 2 + 2 , L / 2 + 20 - 2);
		newlaser(1, 0, H / 2 + 1 , L / 2 + 20 - 2);
		newlaser(1, 0, H / 2     , L / 2 + 20 - 2);
		newlaser(1, -1, H / 2 - 1 , L / 2 + 20 - 2);
		newlaser(-1, 0, H / 2 - 1 , L / 2 + 20 - 1);
		newlaser(-1, 0, H / 2 - 1 , L / 2 + 20);
		newlaser(1, 0, H / 2 - 1 , L / 2 + 20 + 1);

		newlaser(-1, 0, H / 2     , L / 2 - 20 + 1);//dsad
		newlaser(-1, 0, H / 2 + 1 , L / 2 - 20 + 1);
		newlaser(-1, 1, H / 2 + 2 , L / 2 - 20 + 1);
		newlaser(1, 0, H / 2 + 2 , L / 2 - 20);
		newlaser(1, 0, H / 2 + 2 , L / 2 - 20 - 1);
		newlaser(1, 1, H / 2 + 2 , L / 2 - 20 - 2);
		newlaser(1, 0, H / 2 + 1 , L / 2 - 20 - 2);
		newlaser(1, 0, H / 2     , L / 2 - 20 - 2);
		newlaser(1, -1, H / 2 - 1 , L / 2 - 20 - 2);
		newlaser(-1, 0, H / 2 - 1 , L / 2 - 20 - 1);
		newlaser(-1, 0, H / 2 - 1 , L / 2 - 20);
		newlaser(1, 0, H / 2 - 1 , L / 2 - 20 + 1);
		// newlaser(-1, 0, getPosX() -2, getPosY());
	}
	else {
	 	setDirectionY(0);
	 	setDirectionX(0);
	}
	return (1);
}

int		space::move(void)
{
	mvprintw(getPosX(), getPosY(), (const char*)" ");
	//clock_t tmp = clock();
	setPosY(getPosY() + getDirectionY() * 3);
	setPosX(getPosX() + getDirectionX());
	mvprintw(getPosX(), getPosY(), (const char*)"/ \\");
	wmove(stdscr, getPosX() + 1, getPosY());
	printw("---");
	return (0);
}

space::~space()
{

}