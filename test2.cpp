/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:48:07 by yinzhang          #+#    #+#             */
/*   Updated: 2019/10/27 16:02:03 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "player.h"

int main(int argc, char **argv)
{
	initscr();
	noecho();
	curs_set(0);
	//cbreak();
	timeout(-1);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	
	//just shows the boarder with title
	mvprintw( 1, 50, "FT_SPACE_INVADERS");
	refresh();

	//create window and box and refreshes it
	WINDOW * playwin = newwin(25, 100, 5, 10);
	box(playwin, 0, 0);
	wrefresh(playwin);


	//press anykey to start
	mvprintw(15, 50, "Press Any Key to Start");
	wrefresh(playwin);
	getch();
	wclear(playwin);
	box(playwin, 0, 0);
	wrefresh(playwin);


	//creating new player obj
	Player *p = new Player(playwin, 23, 50, 'A');
	
	do {
		p->display();
		wrefresh(playwin);
	} while(p->getmv() != 'x');

	//now need too to always go
	int i = 0;

	do {
		p->display();
		mvwaddch(playwin, -5, 5, 'O');
		wrefresh(playwin);
		i++;
	} while(1);


//	getch();
	endwin();
}
