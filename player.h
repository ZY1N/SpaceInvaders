/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:48:36 by yinzhang          #+#    #+#             */
/*   Updated: 2019/10/27 15:58:13 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABC_H
#define ABC_H
#include <ncurses.h>
#include <iostream>

class Player
{
	public:
		Player(WINDOW *win, int y, int x, char c);
		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		int getmv();
		void display();
		void fire();

	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
		WINDOW *curwin;
};

Player::Player(WINDOW *win, int y, int x, char c)
{
	curwin = win;
	yLoc = y;
	xLoc = x;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
	curs_set(0);
}

void Player::mvup()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	yLoc--;
	if (yLoc < 1)
		yLoc = 1;
}

void Player::mvdown()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	yLoc++;
	if (yLoc > yMax-2)
		yLoc = yMax-2;
}

void Player::mvleft()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc--;
	if(xLoc < 1)
		xLoc= 1;
}

void Player::mvright()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc++;
	if(xLoc > xMax-2)
		xLoc = xMax-2;
}

void Player::fire()
{
	mvwaddch(curwin, yLoc-1, xLoc, '0');
}

int Player::getmv()
{
	int choice = wgetch(curwin);
	switch(choice)
	{
		case KEY_UP:
			//mvup();
			break;
		case KEY_DOWN: 
			//mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		case ' ':
			fire();
			break;
		default: 
			break;
	}
	return choice;
}

void Player::display()
{
	mvwaddch(curwin, yLoc, xLoc, character);
}

#endif
