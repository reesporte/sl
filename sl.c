// make a steam locomotive go across the screen
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void indexToEnd(const char * str, char * dst, size_t start) {
    size_t j = 0;
    for ( size_t i = start; i <= strlen(str); ++i ) {
        dst[j++] = str[i];
    }
    dst[j] = 0;
}

int main() {
	initscr();
	clear();
	noecho();
	curs_set(0);
	char top[] =    "                *''`'`'`'`''''`'`'`          ";	
	char middle[] = "               ||__  _______ _______         ";	
	char bottom[] = "             c/____|-|_____|-|_____|         ";	
	char dst[] =    "                                             ";
	for (int i = 0; i < strlen(top); i++) {
		indexToEnd(top, dst, i);
		mvprintw(0,0, dst);
		indexToEnd(middle, dst, i);
		mvprintw(1,0, dst);
		indexToEnd(bottom, dst, i);
		mvprintw(2,0, dst);
		usleep(12500); // wait a second
		refresh();
	}
	endwin();
	return 0;
}
