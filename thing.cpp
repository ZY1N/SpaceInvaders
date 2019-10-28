/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:30:40 by yinzhang          #+#    #+#             */
/*   Updated: 2019/10/27 15:39:25 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int main(int argc, char **argv)
{
	//inits screen
	//sets up memory and clears screen
	initscr();


	//moves the cursor to location
	//move(y, x);
	int x, y;
	y = x = 10;

	move(y, x);

	//prints a string(const char *) to a window
	printw("Hello World");

	//refersh screen to match memory
	refresh();

	//waits for user input return int value of that key
	int c = getch();

	clear();
	move(0, 0);
	printw("%d", c);

	//mvprintw(0, 0, "%d", c);
	getch();

	//clears screen
	//clear();

	endwin();
	//deallocates memory and ends ncurses
}
