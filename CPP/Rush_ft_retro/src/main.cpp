/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <bciss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 23:36:20 by bciss             #+#    #+#             */
/*   Updated: 2015/11/08 22:24:58 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <iostream>
#include "le.hpp"

MovingStuff		*tab[666];

int     time_left(time_t end)
{
	time_t  cur;

	cur = clock();
	return ((int)(end - cur));
}

void	infos(time_t end)
{
	int		time;

	wmove(stdscr, 56, 5);
	printw("Z : Super shoot | X : Bomb");
	wmove(stdscr, 57, 5);
	printw("ESC : Quit");
	wmove(stdscr, 56, 90);
	printw("TIME_LEFT  %d", (time = time_left(end) / 1000000));
	if (time <= 0)
	{
		clear();
		printw("TIME OUT !!");
		refresh();
		exit(0);
	}
	return ;
}

void	boxer() 
{
	int x;
	int y;
	int o;
	static int m = 3;

	x = 1;
	o = 0;

	while (x < 55)
	{
		y = 1;
		wmove(stdscr, x, y);
		if ((o + m) % 3 == 0)
			printw("*");
		while (y < 105)
		{
			if (x == 1 || x == 54)
			{
				wmove(stdscr, x, y);
				printw("-");
			}
			y++;
		}
		wmove(stdscr, x, y);
		x++;
		if ((o + m) % 3 == 0)
			printw("*");
		o++;
	}
	if (m > 0)
		m--;
	else
		m = 3;
	return ;
}

void newlaser(int x, int y, int x2, int y2)
{
	int i = -1;
	while(++i < 666)
	{
		if (!tab[i])
		{
			tab[i] = new asteroide(x, y, x2, y2);
			break ;
		}
	}
}

void newasteroide(void)
{
	int i = -1;

	while(++i < 666)
	{
		if (!tab[i])
		{
			tab[i] = new asteroide;
			break ;
		}
	}
}

void newniark(void)
{
	int i = -1;

	while(++i < 666)
	{
		if (!tab[i])
		{
			tab[i] = new niark;
			break ;
		}
	}
}

int     menu(void)
{
	int     key;
	int     choice;

	choice = -1;
	key = 0;
	while (choice == -1) {
		clear();
		printw("\n\n");
		printw("        Menu\n\n");
		printw("        1. Music on\n");
		printw("        2. Music off\n");
		printw("        Q. Quit\n\n");
		printw("        > ");
		refresh();
		key = (int)getch();
		switch (key) {
			case '1':
				choice = 1;
				break ;
			case '2':
				choice = 2;
				break ;
			case 27:
				choice = 3;
				break ;
			case 'q':
				choice = 3;
				break ;
			case 'Q':
				choice = 3;
				break ;
		}
	}
	return (choice);
}

int	main()
{
	static clock_t	last_aster_spawn = 0;
	static clock_t	last_enemy_spawn = 0;
	int	menu_choice;
	int				i;
	std::string		s;
	int j;
	int k;
	int p = 1;
	int b = 0;
	time_t  end;


	initscr();
	menu_choice = menu();
	switch (menu_choice) {
	case 1:
		{
			system("afplay content/Ricky.mp3 &");
			break ;
		}
	case 2:
		break ;
	case 3:
		return 0;
	}
	curs_set(0);
	srand(time(NULL));
	end = clock() + 1000000 * 100;
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	tab[0] = new space;
	noecho();
	j = 0;
	while (p)
	{
		j++;
		i = -1;
		if (j % 500 == 0)
		{
			clear();
			boxer();
			infos(end);
		}
	if (((clock() >= last_aster_spawn)) && b == 0) {
			last_aster_spawn = clock() + 1000000 * .35;
			newasteroide();
		}
		if ((clock() >= last_enemy_spawn) && b == 0) {
			last_enemy_spawn = clock() + 1000000 * .5;
			newniark();
		}
		if ((clock() >= 1000000 * 30 && b == 0))
		{
			system("killall afplay");
			system("afplay content/Nyan.mp3 &");
			tab[1] = new boss;
			b = 1;
		}
		p = ((space *)(tab[0]))->getation();
		while(++i < 666)
		{
			if (tab[i])
			{
				if (tab[i]->move())
				{
					delete tab[i];
					tab[i] = NULL;
				}
				k = -1;
				while (tab[i] && ++k < 666)
				{
					if (tab[k] && i != k && tab[i]->getPosX() >= tab[k]->getPosX()
							&& tab[i]->getPosX() <= tab[k]->getPosX() + (tab[k]->getSizeX() - 1)
							&& tab[i]->getPosY() >= tab[k]->getPosY()
							&& tab[i]->getPosY() <= tab[k]->getPosY() + (tab[k]->getSizeY() - 1))
					{
						delete tab[i];
						delete tab[k];
						tab[i] = NULL;
						tab[k] = NULL;
					}
					if (!tab[0])
						p = 0;
				}
			}
			if (!tab[0])
				p = 0;
		}
		refresh();

	}
	endwin();
	system("killall afplay &");
	return 0;
}
