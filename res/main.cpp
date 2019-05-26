#include<time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <iostream>

using namespace std;


int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}


void update_screen(char q[][22], int level, int length) {
    system("clear");
    int i, j;
    cout << endl;
    for (i = 0; i < 22; i++) {
        cout << "\t";
        for (j = 0; j < 22; j++)
            cout << q[i][j] << " ";
        if (i == 0) cout << "\t";
        if (i == 2) cout << "\t";
        if (i == 4) cout << "\tGAME LEVEL: " << level;
        if (i == 6) cout << "\tGAME SCORE: " << length * 10 - 40;
        if (i == 8) cout << "\tNOTE: ";
        if (i == 10) cout << "\tW: UP   S: DOWN";
        if (i == 12) cout << "\tA: LEFT D: RIGHT";
        if (i == 14) cout << "\tREMINDER: ";
        if (i == 16) cout << "\tMOVING BACK WILL";
        if (i == 18) cout << "\tEND TEH GAME, SO";
        if (i == 20) cout << "\tNEVER DO THAT.";
        if (i == 22) {
            if (level >= 1 && level <= 3) {
                cout << " PRIMARY LEVEL! COME ON！";
            }
            if (level >= 4 && level <= 6) {
                cout << "YOU ARE EXCELLENT!";
            }
            if (level >= 7 && level <= 9) {
                cout << "YOU ARE VERY STRONG!";
            }
            if (level > 9) {
                cout << " YOU ARE MARVELOUS！";
            }
        }
        cout << endl;
    }
}


char get_input() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}


int main() {


//**********************************************************************
//                            welcome
//**********************************************************************

    long start;
    int i, j;


    for (i = 3; i >= 0; i--) {
        start = clock();
        while (clock() - start <= 500000);
        system("clear");
        if (i > 0) {
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "             ■■■■■■  ■■■    ■■■       ■■■■       ■■   ■■■■  ■■■■■■  " << endl;
            cout << "             ■■■■■■  ■■■     ■■       ■■■■       ■■    ■■   ■■■■■■  " << endl;
            cout << "             ■■      ■■■■    ■■      ■■  ■■      ■■   ■■    ■■      " << endl;
            cout << "             ■■      ■■■■    ■■      ■■  ■■      ■■  ■■     ■■      " << endl;
            cout << "             ■■      ■■ ■■   ■■     ■■    ■■     ■■ ■■      ■■      " << endl;
            cout << "             ■■■■■■  ■■  ■■  ■■     ■■■■■■■■     ■■■■       ■■■■■■  " << endl;
            cout << "             ■■■■■■  ■■  ■■  ■■    ■■■■■■■■■■    ■■■■       ■■■■■■  " << endl;
            cout << "                 ■■  ■■   ■■ ■■    ■■      ■■    ■■ ■■      ■■      " << endl;
            cout << "                 ■■  ■■    ■■■■    ■■      ■■    ■■  ■■     ■■      " << endl;
            cout << "                 ■■  ■■    ■■■■   ■■        ■■   ■■   ■■    ■■      " << endl;
            cout << "             ■■■■■■  ■■     ■■■  ■■■        ■■■  ■■    ■■   ■■■■■■  " << endl;
            cout << "             ■■■■■■  ■■■    ■■■  ■■■        ■■■  ■■   ■■■■  ■■■■■■  " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                      ZHEXIONG LIU  " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;
//            cout << "                                                      COUNTDOWN: "<<i << endl;
            cout << "                                                                    " << endl;
            cout << "                                                                    " << endl;


        }
    }
    for (i = 1; i >= 0; i--) {
        start = clock();
        while (clock() - start <= 10000);

        if (i > 0) {
            system("clear");
//            cout << "  \n              INTRODUCTION:                                        " << endl;
//            cout << "  \n              COUNTDOWN: " << i                                      << endl;
            cout << "  \n              GAME NAME: SNAKE                                     " << endl;
            cout << "  \n              DEVELOPER: ZHEXIONG LIU                              " << endl;
            cout << "  \n              RULE:      PLEASE PRESS W, S, A, OR D TO CONTROL UP, " << endl;
            cout << "  \n                         DOWN, LEFT, OR RIGHT MOVEMENTS. THE SNAKE " << endl;
            cout << "  \n                         WILL GROW UP AFTER EATING A SHOWING FOOD. " << endl;
            cout << "  \n                         THE SNAKE WILL ACCELERATE WHILE EATING UP " << endl;
            cout << "  \n                         TO TEN FOODS. IF CONTROL THE SNAKE TO HIT " << endl;
            cout << "  \n                         ON A WALL OR BODY OR MOVE BACK, GAME OVER." << endl;
        } else {
            cout << "  \n              PLEASE PRESS ANY KEY TO START GAME.\n               " << endl;
            get_input();
        }

    }

//**********************************************************************
//                            game
//**********************************************************************

    int level = 1, length = 4;
    int game_speed = 300000;
    int timeover;
    int direction = 'D';
    int x, y;

    //  the layout of the game screen
    char snake_matrix[22][22];

    for (i = 1; i <= 20; i++)
        for (j = 1; j <= 20; j++)
            snake_matrix[i][j] = ' ';
    //  upper and lower boundary
    for (i = 0; i <= 21; i++)
        snake_matrix[0][i] = snake_matrix[21][i] = '*';
    //  left and right boundary
    for (i = 1; i <= 20; i++)
        snake_matrix[i][0] = snake_matrix[i][21] = '*';
    int snake_axis[50][100];
    for (i = 0; i < 4; i++) {
        snake_axis[0][i] = 1;
        snake_axis[1][i] = i + 1;
    }
    int head = 3, tail = 0;
    //  snake body
    for (i = 1; i <= 3; i++)
        snake_matrix[1][i] = '#';
    // snake head
    snake_matrix[1][4] = '@';
    // food
    int x1, y1;
    srand(time(0));
    do {
        x1 = rand() % 20 + 1;
        y1 = rand() % 20 + 1;
    } while (snake_matrix[x1][y1] != ' ');
    snake_matrix[x1][y1] = '*';


    while (1) {
        timeover = 1;
        start = clock();
        while ((timeover = (clock() - start <= game_speed)) && !kbhit());
        if (timeover) {
            direction = get_input();
        }
        switch (direction) {
            case 'W': // up
            case 'w':
                x = snake_axis[0][head] - 1;
                y = snake_axis[1][head];
                break;
            case 'S': // down
            case 's':
                x = snake_axis[0][head] + 1;
                y = snake_axis[1][head];
                break;
            case 'A': // left
            case 'a':
                x = snake_axis[0][head];
                y = snake_axis[1][head] - 1;
                break;
            case 'D': // right
            case 'd':
                x = snake_axis[0][head];
                y = snake_axis[1][head] + 1;
                break;
            default: // right
                x = snake_axis[0][head];
                y = snake_axis[1][head] + 1;
                break;
        }
        //  hit the wall
        if (x == 0 || x == 21 || y == 0 || y == 21) {
            cout << "\n\n\n\n\n\t\tGAME OVER!    YOUR SCORE: " << length * 10 - 40 << "\n\n\n\n" << endl;
            return 0;
        }
        // hit the body
        if (snake_matrix[x][y] != ' ' && !(x == x1 && y == y1)) {
            cout << "\n\n\n\n\n\t\tGAME OVER!    YOUR SCORE: " << length * 10 - 40 << "\n\n\n\n" << endl;
            return 0;
        }
        // eat food
        if (x == x1 && y == y1) {
            length++;
            if (length <= 22 && length >= 14) {
                level = 2;
                game_speed = 250000;
            }
            if (length >= 23 && length <= 31) {
                level = 3;
                game_speed = 200000;
            }
            if (length >= 32 && length <= 38) {
                level = 4;
                game_speed = 150000;
            }
            if (length >= 39 && length <= 44) {
                level = 5;
                game_speed = 100000;
            }
            if (length >= 45 && length <= 50) {
                level = 6;
                game_speed = 90000;
            }
            if (length >= 51 && length <= 55) {
                level = 7;
                game_speed = 80000;
            }
            if (length >= 56 && length <= 60) {
                level = 8;
                game_speed = 70000;
            }
            if (length >= 61 && length <= 64) {
                level = 9;
                game_speed = 60000;
            }
            if (length >= 65) {
                level = 10;
                game_speed = 50000;
            }
            snake_matrix[x][y] = '@';

            snake_matrix[snake_axis[0][head]][snake_axis[1][head]] = '*';
            head = (head + 1) % 100;
            snake_axis[0][head] = x;
            snake_axis[1][head] = y;

            do {
                x1 = rand() % 20 + 1;
                y1 = rand() % 20 + 1;
            } while (snake_matrix[x1][y1] != ' ');

            snake_matrix[x1][y1] = '*';
            update_screen(snake_matrix, level, length);
        } else {
            snake_matrix[snake_axis[0][tail]][snake_axis[1][tail]] = ' ';
            tail = (tail + 1) % 100;
            snake_matrix[snake_axis[0][head]][snake_axis[1][head]] = '#';
            head = (head + 1) % 100;
            snake_axis[0][head] = x;
            snake_axis[1][head] = y;
            snake_matrix[snake_axis[0][head]][snake_axis[1][head]] = '@';
            update_screen(snake_matrix, level, length);
        }
    }
    return 0;
}

