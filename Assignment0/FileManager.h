//
// Created by NewCentury99 on 2023-03-06.
//
#pragma once
#include <string>
#include <fstream>

using namespace std;


class FileManager {
private:
    // Fields
    static FileManager *instance;
    ifstream fileInputStream;
    ofstream fileOutputStream;
    string path;
    int fileSize;
    string contents;

    // Feature
    void readContents();

public:
    // Constructor
    static FileManager *getInstance();

    // Getter
    string getContents();

    // Setter

    // Feature
    bool openFile(string pathStr);
    bool updateCurrentFile(string target, string replacement);
    bool deleteCurrentFile(string target);
    bool insertCurrentFile(string contents);
    void closeFile();
};
