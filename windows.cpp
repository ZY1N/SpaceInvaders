/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:39:42 by yinzhang          #+#    #+#             */
/*   Updated: 2019/10/27 15:48:02 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int main(int argc, char **argv)
{
	initscr();
	//cbreak exists out of program
	//cbreak();
	//doesnt take anything
	//raw();
	////whatever input user takes doesnt show up on screen
	//noecho();



	int height, width, start_y, start_x;
	height = 10;
	width= 20;
	start_y = start_x = 10;

	WINDOW *win = newwin(height, width, start_y, start_x);

	refresh();
	//wprintw(win, 0, 0);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "this is a box");
	//wrefresh the window that
	wrefresh(win);

	int c = getch();

	endwin();

}
