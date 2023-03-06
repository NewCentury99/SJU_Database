#pragma once
#include <string>
#include <fstream>

using namespace std;


class FileManager {
private:
    // Fields
    static FileManager* instance;
    ifstream fin;
    ofstream fout;
    string path;
    int fileSize = 0;
    string contents;

    // Feature
    void readContents();

public:
    // Constructor
    static FileManager* getInstance();

    // Getter
    string getContents();

    // Setter

    // Feature
    int openFile(string pathStr);
    bool updateCurrentFile(string target, string replacement);
    bool deleteCurrentFile(string target);
    bool insertCurrentFile(string contents);
    void closeFile();
};
