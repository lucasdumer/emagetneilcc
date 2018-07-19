#include <ncurses.h>

int main(int argc, char* argv[])
{
    initscr();
    getch();
    endwin();

    return 0;
}

