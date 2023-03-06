//
// Created by NewCentury99 on 2023-03-06.
//

#include <string>
#include <iostream>
#include "ConsoleUI.h"
#include "FileManager.h"

using namespace std;

ConsoleUI::ConsoleUI() {
    this->fileManager = new FileManager();
}

void ConsoleUI::runMenuLoop() {
    int selection;

    while(true) {
        cout << "==========데이터 베이스 1주차 과제==========" << endl;
        cout << "1. File Open (파일 열기)" << endl;
        cout << "2. File Print (파일 내용 출력)" << endl;
        cout << "3. File Update (파일 내용 변경)" << endl;
        cout << "4. File Delete (파일 내용 삭제)" << endl;
        cout << "5. File Insert (파일 내용 추가)" << endl;
        cout << "6. Exit (프로그램 종료)" << endl;
        cout << "========================================" << endl;
        cout << "실행할 메뉴 번호를 입력 하세요 : ";
        cin >> selection;
        cin.ignore();

        this->clearConsole();
        switch (selection) {
            case 1:
                this->executeFileOpen();
                this->clearConsole();
                break;
            case 2:
                this->executeFilePrint();
                this->clearConsole();
                break;
            case 3:
                this->executeFileUpdate();
                this->clearConsole();
                break;
            case 4:
                this->executeFileDelete();
                this->clearConsole();
                break;
            case 5:
                this->executeFileInsert();
                this->clearConsole();
                break;
            case 6:
                return;
            default:
                cout << "==========데이터 베이스 1주차 과제==========" << endl;
                cout << "잘못된 메뉴 선택입니다." << endl;
                cout << "========================================" << endl;
                cout << "아무 키나 눌러서 메뉴로 복귀 합니다" << endl;
                cin.get();
        }
    }
}

void ConsoleUI::executeFileOpen() {
    string path;

    cout << "==========데이터 베이스 1주차 과제==========" << endl;
    cout << "File Open (파일 열기)" << endl;
    cout << "열려는 파일의 절대 경로를 입력 하세요" << endl;
    cout << "========================================" << endl;
    cout << "경로 : ";
    getline(cin, path, '\n');

    if (this->fileManager->openFile(path)) {
        cout << "==========데이터 베이스 1주차 과제==========" << endl;
        cout << "File Open (파일 열기)" << endl;
        cout << "파일 열기에 성공 했습니다" << endl;
        cout << "========================================" << endl;
        cout << "아무 키나 눌러서 메뉴로 복귀 합니다" << endl;
        cin.get();
    } else {
        cout << "==========데이터 베이스 1주차 과제==========" << endl;
        cout << "File Open (파일 열기)" << endl;
        cout << "파일 열기에 실패 했습니다" << endl;
        cout << "파일 경로 및 텍스트 모드로 오픈 가능한 파일 인지 확인 바랍니다" << endl;
        cout << "========================================" << endl;
        cout << "아무 키나 눌러서 메뉴로 복귀 합니다" << endl;
        cin.get();
    }
}

void ConsoleUI::executeFilePrint() {
    string contents = this->fileManager->getContents();
    if (contents.size() == 0) {
        cout << "==========데이터 베이스 1주차 과제==========" << endl;
        cout << "File Print (파일 내용 출력)" << endl;
        cout << "열린 파일이 없거나, 파일 내용을 읽는 데 실패 했습니다" << endl;
        cout << "========================================" << endl;
        cout << "아무 키나 눌러서 메뉴로 복귀 합니다" << endl;
        cin.get();
    } else {
        cout << "==========데이터 베이스 1주차 과제==========" << endl;
        cout << "File Print (파일 내용 출력)" << endl;
        cout << "아래는 열린 파일의 내용 입니다. (텍스트 모드로 읽음)" << endl;
        cout << "========================================" << endl;
        cout << contents << endl;
        cout << "========================================" << endl;
        cout << "아무 키나 눌러서 메뉴로 복귀 합니다" << endl;
        cin.get();
    }
}

void ConsoleUI::executeFileUpdate() {

}

void ConsoleUI::executeFileDelete() {

}

void ConsoleUI::executeFileInsert() {

}

void ConsoleUI::clearConsole() {
#ifdef _WIN32 \
    // For Microsoft Windows
    system("cls");
#else
    // For Linux or Mac OS
    system("clear");
#endif
    return;
}
