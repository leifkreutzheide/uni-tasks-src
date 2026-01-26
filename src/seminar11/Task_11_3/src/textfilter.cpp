#include <iostream>

int main()
{
    char c;
    bool last_was_ctrl = false;

    while (std::cin.get(c)) {
        if ((c < 32 && c != '\n' && c != '\t') || c == 127) {
            if (!last_was_ctrl) {
                std::cout << ' ';
                last_was_ctrl = true;
            }
        } else {
            std::cout << c;
            last_was_ctrl = false;
        }
    }
    return 0;
}
