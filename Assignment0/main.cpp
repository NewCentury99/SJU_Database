#include <iostream>
#include "ConsoleUI.h"

int main() {
    ConsoleUI* consoleUI = new ConsoleUI();
    consoleUI->runMenuLoop();
    return 0;
}
