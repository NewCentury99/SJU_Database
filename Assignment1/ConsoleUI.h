//
// Created by NewCentury99 on 2023-03-06.
//

#pragma once
#include <string>
#include <iostream>
#include "FileManager.h"


class ConsoleUI {
private:
    FileManager fileManager;
public:
    void runMenuLoop();
    void executeFileOpen();
    void executeFilePrint();
    void executeFileUpdate();
    void executeFileDelete();
    void executeFileInsert();
};
