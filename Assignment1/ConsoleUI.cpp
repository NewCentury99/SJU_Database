//
// Created by NewCentury99 on 2023-03-06.
//

#include <string>
#include <iostream>
#include "ConsoleUI.h"
#include "FileManager.h"

using namespace std;


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

        switch (selection) {
            case 1:
                this->executeFileOpen();
                break;
            case 2:
                this->executeFilePrint();
                break;
            case 3:
                this->executeFileUpdate();
                break;
            case 4:
                this->executeFileDelete();
                break;
            case 5:
                this->executeFileInsert();
                break;
            case 6:
                return;
        }
    }
}

void ConsoleUI::executeFileOpen() {

}

void ConsoleUI::executeFilePrint() {

}

void ConsoleUI::executeFileUpdate() {

}

void ConsoleUI::executeFileDelete() {

}

void ConsoleUI::executeFileInsert() {

}
