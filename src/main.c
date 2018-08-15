#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include <ncurses.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    struct sockaddr_in server;
    int ch;

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    // teste socket
    int sock;
    char message[1000] , server_reply[2000];
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(22);
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected");

    /*
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);
    }
     
    //close(sock);
    return 0;
*/
    // teste socket

    int ia = 0;
    int ia2 = 0;
    while (true) {

        if (ch = getch()) {

            clear();
            printw("a %s -> %d -> %d", server_reply, ia, ia2);
       
            switch (ch) {
                case 65:
                    printw("UP\n");ia += 1;
                    send(sock, "up", strlen("up"), 0);
                    recv(sock , server_reply , 2000 , 0);
                    break;
                case 66:
                    printw("DOWN\n");ia += 2;
                    send(sock, "down", strlen("down"), 0);
                    recv(sock , server_reply , 2000 , 0);
                    break;
                case 67:
                    printw("RIGHT\n");ia += 3;
                    send(sock, "right", strlen("right"), 0);
                    recv(sock , server_reply , 2000 , 0);
                    break;
                case 68:
                    printw("LEFT\n");ia+= 4;
                    send(sock, "left", strlen("left"), 0);
                    recv(sock , server_reply , 2000 , 0);
                    break;
            }
        }

        ia2++;
    }

    endwin();

    return 0;
}

