#include "FileManager.h"

using namespace std;

FileManager* FileManager::instance = nullptr;

FileManager* FileManager::getInstance() {
    if (instance == nullptr) {
        instance = new FileManager();
    }
    return instance;
}

int FileManager::openFile(string pathStr) {
    // Set file path
    this->path = pathStr;
    if (fin.is_open()) {
        fin.close();
    }
    fin.open(pathStr);

    // Open input file stream
    if (!fin.is_open()) {
        return errno;
    }
    this->readContents();
    fin.close();
    return 0;
}

// TODO: check (마지막 개행 이슈)
void FileManager::readContents() {
    // Move file pointer to eof
    fin.seekg(0, std::ios::end);

    // read file size (string length)
    this->fileSize = fin.tellg();
    this->contents.erase();
    this->contents.resize(fileSize);

    // Move file pointer to the beginning of file
    fin.seekg(0, std::ios::beg);

    // Load whole file contents to the memory
    fin.read(&contents[0], fileSize);
}

string FileManager::getContents() {
    // Return contents string to UI class or etc.
    return contents;
}

bool FileManager::updateCurrentFile(string target, string replacement) {
    // Open output file stream (with overwrite mode)
    fout.open(path, std::ios::trunc);
    if (!fout) {
        return false;
    }

    // Replace target strings from contents
    size_t position = contents.find(target);
    string updatedStr;
    while (position != string::npos && target != replacement) {
        updatedStr = contents.replace(position, target.length(), replacement);
        position = contents.find(target);
    }

    // Write changes to the file
    fout << updatedStr << endl;

    // Close output file stream
    fout.close();
    return true;
}

bool FileManager::deleteCurrentFile(string target) {
    // Replace target strings of contents to the empty string
    return this->updateCurrentFile(target, "");
}

bool FileManager::insertCurrentFile(string input) {
    // Open output file stream (with append mode)
    fout.open(path, std::ios::app);
    if (!fout) {
        return false;
    }

    // Write changes to the file
    fout << "\n" << input;

    // Close output file stream
    fout.close();

    // Re-open inserted file
    this->openFile(path);
    return true;
}

void FileManager::closeFile() {
    // Close file stream
    fin.close();
    fout.close();
}
