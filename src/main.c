#include <ncurses.h>
#include <sys/socket.h> 

int main(int argc, char* argv[])
{
    int ch;

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    int socket_id = socket("127.0.0.1:22", SOCK_STREAM, 0);

    printw(" AAA -> %d\n", socket_id);

    while (true) {

        ch = getch();
        
        switch (ch) {
            case 65:
                printw("UP\n");
                break;
            case 66:
                printw("DOWN\n");
                break;
            case 67:
                printw("RIGHT\n");
                break;
            case 68:
                printw("LEFT\n");
                break;
        }
    }

    endwin();

    return 0;
}

