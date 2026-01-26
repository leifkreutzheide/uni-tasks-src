#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int kbhit()
{
    termios oldt, newt;
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

int main()
{
    int x = 1, dx = 1;
    int delay = 80000;
    char c;

    std::cout << "\033[44;97m";   // blue background, white text
    std::cout << "\033[2J";       // clear screen

    while (true) {
        std::cout << "\033[H";
        for (int i = 0; i < x; ++i) std::cout << " ";
        std::cout << "o" << std::flush;

        x += dx;
        if (x <= 0 || x >= 60) dx = -dx;

        usleep(delay);

        if (kbhit()) {
            c = getchar();
            if (c == 27) break;          // ESC
            if (c == '+') delay /= 2;
            if (c == '-') delay *= 2;
        }
    }

    std::cout << "\033[0m" << std::endl;
    return 0;
}
