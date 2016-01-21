#include <ncurses.h>
#include <unistd.h>

int main()
{
	int x = 0, y = 0;
	int xdir = 1, ydir = 1;
	int max_x, max_y;

	initscr();			/* Start curses mode 		  */
	noecho();
	curs_set(FALSE);

	// Get the bounds of the console
	getmaxyx(stdscr, max_y, max_x);

	while (1) {
		clear();

		mvprintw(y, x, ".");
		refresh();
		

		x += xdir;
		y += ydir;

		if (x < 0 || x > max_x-1) {
			xdir = -xdir;
		}
		if (y < 0 || y > max_y-1) {
			ydir = -ydir;
		}
		
		usleep(30000);
	}

	endwin();
}