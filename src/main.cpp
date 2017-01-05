/*
 * main.cpp
 * Runs main code for Chess
 * Created by Andrew Davis
 * Created on 1/4/2017
 * Open source (GPL license)
 */

//includes
#include <curses.h>

//main function
int main(int argc, char* argv[]) {
	initscr(); //start curses
	printw("This program is under construction.\n"); //print first message
	printw("Check back for more updates."); //print second message
	refresh(); //render the messages
	getch(); //wait for input
	endwin(); //exit curses
	return 0; //and return with no errors
}
