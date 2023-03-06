//
// Created by NewCentury99 on 2023-03-06.
//
#include <string>
#include <fstream>
#include "FileManager.h"

using namespace std;

FileManager *FileManager::instance = nullptr;

FileManager *FileManager::getInstance() {
    if (instance == nullptr) {
        instance = new FileManager();
    }
    return instance;
}

bool FileManager::openFile(string pathStr) {
    // Set file path
    this->path = pathStr;

    // Open input file stream
    fileInputStream.open(this->path);
    if (fileInputStream.fail()) {
        return false;
    }
    this->readContents();
    return true;
}

void FileManager::readContents() {
    // Move file pointer to eof
    fileInputStream.seekg(0, std::ios::end);

    // read file size (string length)
    this->fileSize = fileInputStream.tellg();
    this->contents.resize(fileSize);

    // Move file pointer to the beginning of file
    fileInputStream.seekg(0, std::ios::beg);

    // Load whole file contents to the memory
    fileInputStream.read(&contents[0], fileSize);
}

string FileManager::getContents() {
    // Return contents string to UI class or etc.
    return contents;
}

bool FileManager::updateCurrentFile(string target, string replacement) {
    // Open output file stream (with overwrite mode)
    fileOutputStream.open(path, std::ios::trunc);
    if (fileOutputStream.fail()) {
        return false;
    }

    // Replace target strings from contents
    string updatedStr = contents.replace(contents.find(target), target.length(), replacement);

    // Write changes to the file
    fileOutputStream << updatedStr << endl;

    // Close output file stream
    fileOutputStream.close();
    return true;
}

bool FileManager::deleteCurrentFile(string target) {
    // Replace target strings of contents to the empty string
    return this->updateCurrentFile(target, "");
}

bool FileManager::insertCurrentFile(string input) {
    // Open output file stream (with append mode)
    fileOutputStream.open(path, std::ios::app);
    if (fileOutputStream.fail()) {
        return false;
    }

    // Insert input to the contents loaded on memory
    contents.append("\n");
    contents.append(input);

    // Write changes to the file
    fileOutputStream << endl;
    fileOutputStream << input << endl;

    // Close output file stream
    fileOutputStream.close();
    return true;
}

void FileManager::closeFile() {
    // Close input file stream
    fileInputStream.close();
}
