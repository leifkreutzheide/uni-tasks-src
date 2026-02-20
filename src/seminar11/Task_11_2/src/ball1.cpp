#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#ifdef _WIN32
#include <conio.h>   // for _kbhit() and _getch() on Windows
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// POSIX replacements for _kbhit() and _getch()
int _kbhit() {
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

int _getch() {
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
#endif

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[H";
}

void moveCursor(int y, int x) {
    cout << "\033[" << y << ";" << x << "H";
}

int main() {
    const int width = 79;
    const int height = 25;

    int x = 2, y = 3;
    int dx = 1;
    int velocity = 0;
    const int gravity = 1;
    const int floorY = height - 1;

    string floor(width, '-');
    int delay_ms = 80; // initial speed

    // Set entire screen background to blue
    cout << "\033[44m";   // Blue background for everything
    clearScreen();

    cout << "\033[97;44m**** BOUNCING BALL **** (ESC = quit, +/- = speed)\033[0m\n";
    cout << "\033[44m"; // Keep blue background active

    bool running = true;
    while (running) {
        // Draw floor (still blue background)
        moveCursor(floorY, 1);
        cout << "\033[97;44m" << floor;

        // Draw the ball (white on blue)
        moveCursor(y, x);
        cout << "\033[97;44m" << "o" << flush;

        // Delay according to speed
        this_thread::sleep_for(chrono::milliseconds(delay_ms));

        // Erase ball
        moveCursor(y, x);
        cout << "\033[44m " << flush; // blue background + space

        // Handle keyboard input (non-blocking)
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 27) { // ESC key
                running = false;
            } else if (ch == '+') {
                if (delay_ms > 10) delay_ms -= 10; // speed up
            } else if (ch == '-') {
                delay_ms += 10; // slow down
            }
        }

        // Bounce off walls
        if (x <= 1 || x >= width)
            dx = -dx;

        // Bounce off floor
        if (y >= floorY - 1) {
            velocity = -velocity;
            if (velocity == 0)
                velocity = -7; // kick upward
        }

        // Apply gravity
        velocity += gravity;

        // Update position
        x += dx;
        y += velocity;

        // Prevent going off top
        if (y < 1)
            y = 1;
    }

    // Reset colors and clear
    cout << "\033[0m";
    clearScreen();
    cout << "Program ended. Goodbye!\n";
    return 0;
}