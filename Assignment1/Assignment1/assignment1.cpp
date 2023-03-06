#include "assignment1.h"

// Contstructor
Assignment1::Assignment1(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);
    this->fileManager = new FileManager();
    this->setupBtnListener();
}

// Destructor
Assignment1::~Assignment1() {
    this->fileManager->closeFile();
}

// UI Setup Methods
void Assignment1::setupBtnListener() {
    connect(this->ui.mainMenuBtn1, &QPushButton::clicked, this, &Assignment1::executeFileOpen);
    connect(this->ui.mainMenuBtn2, &QPushButton::clicked, this, &Assignment1::executeFilePrint);
    connect(this->ui.mainMenuBtn3, &QPushButton::clicked, this, &Assignment1::executeFileUpdate);
    connect(this->ui.mainMenuBtn4, &QPushButton::clicked, this, &Assignment1::executeFileDelete);
    connect(this->ui.mainMenuBtn5, &QPushButton::clicked, this, &Assignment1::executeFileInsert);
    connect(this->ui.mainMenuBtn6, &QPushButton::clicked, this, &Assignment1::exitProgram);
}

// UI Feature Methods
void Assignment1::executeFileOpen() {
    bool confirmed;
    QMessageBox msgBox;
    QString path = QInputDialog::getText(
        this, tr("1. File Open"), tr("Input File Path:"), QLineEdit::Normal, tr("C:\\"), &confirmed
    );

    if (confirmed) {
        int errorcode = this->fileManager->openFile(path.toStdString());
        if (errorcode == 0) {
            msgBox.setWindowTitle("1. File Open 성공");
            msgBox.setText("파일 열기에 성공했습니다.");
        } else {
            msgBox.setWindowTitle("1. File Open 실패");
            msgBox.setText(strerror(errorcode));
        }
    } else {
        msgBox.setWindowTitle("1. File Open 취소됨");
        msgBox.setText("파일 열기를 취소했습니다.");
    }

    msgBox.exec();
}

void Assignment1::executeFilePrint() {
}

void Assignment1::executeFileUpdate() {
}

void Assignment1::executeFileDelete() {
}

void Assignment1::executeFileInsert() {
}

void Assignment1::exitProgram() {
    QApplication::exit();
}
