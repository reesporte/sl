// make a steam locomotive go across the screen
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void indexToEnd(const char* str, char* dst, size_t start) {
    size_t j = 0;
    for (size_t i = start; i <= strlen(str); ++i) {
        dst[j++] = str[i];
    }
    dst[j] = 0;
}

int main() {
    initscr();
    clear();
    noecho();
    curs_set(0);
    char top[] = "                *''`'`'`'`''''`'`'`          ";
    char md1[] = "               ||__  _______ _______         ";
    char md2[] = "             c/____|-|_____|-|_____|         ";
    char btm[] = "                                             ";
    char dst[] = "                                             ";
    for (int i = 0; i < strlen(top); i++) {
        indexToEnd(top, dst, i);
        mvprintw(0, 0, dst);
        indexToEnd(md1, dst, i);
        mvprintw(1, 0, dst);
        indexToEnd(md2, dst, i);
        mvprintw(2, 0, dst);
        indexToEnd(btm, dst, i);
        mvprintw(3, 0, dst);
        usleep(15000);  // wait a second
        refresh();
    }
    endwin();
    return 0;
}
