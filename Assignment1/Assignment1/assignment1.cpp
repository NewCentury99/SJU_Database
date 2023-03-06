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
    QMessageBox msgBox;
    QString content = this->fileManager->getContents().c_str();

    msgBox.setWindowTitle("2. File Print 파일 내용");
    msgBox.setText(content);
    msgBox.exec();
}

void Assignment1::executeFileUpdate() {
    bool targetConfirmed;
    bool replConfirmed;
    QMessageBox msgBox;
    QString target = QInputDialog::getText(
        this, tr("3. File Update"), tr("변경하고자 하는 단어 또는 구문 (Target)"), QLineEdit::Normal, tr(""), &targetConfirmed
    );
    QString replacement;
    if (targetConfirmed) {
        replacement = QInputDialog::getText(
            this, tr("3. File Update"), tr("변경할 단어 또는 구문 (Replacement)"), QLineEdit::Normal, tr(""), &replConfirmed
        );
        if (replConfirmed) {
            if (this->fileManager->updateCurrentFile(target.toStdString(), replacement.toStdString())) {
                msgBox.setWindowTitle("3. File Update 성공");
                msgBox.setText("파일 업데이트에 성공했습니다.");
            } else {
                msgBox.setWindowTitle("3. File Update 실패");
                msgBox.setText("파일 업데이트에 실패했습니다.");
            }
            msgBox.exec();
        }
    }
}

void Assignment1::executeFileDelete() {
    bool targetConfirmed;
    QMessageBox msgBox;
    QString target = QInputDialog::getText(
        this, tr("4. File Delete"), tr("삭제하고자 하는 단어 또는 구문 (Target)"), QLineEdit::Normal, tr(""), &targetConfirmed
    );
    if (targetConfirmed) {
        if (this->fileManager->deleteCurrentFile(target.toStdString())) {
            msgBox.setWindowTitle("3. File Delete 성공");
            msgBox.setText("파일 내용 삭제에 성공했습니다.");
        } else {
            msgBox.setWindowTitle("3. File Delete 실패");
            msgBox.setText("파일 내용 삭제에 실패했습니다.");
        }
        msgBox.exec();
    }
}

void Assignment1::executeFileInsert() {
    bool confirmed;
    QMessageBox msgBox;
    QString target = QInputDialog::getText(
        this, tr("5. File Insert"), tr("삽입하고자 하는 단어 또는 구문 (Target)"), QLineEdit::Normal, tr(""), &confirmed
    );
    if (confirmed) {
        if (this->fileManager->insertCurrentFile(target.toStdString())) {
            msgBox.setWindowTitle("5. File Insert 성공");
            msgBox.setText("파일 내용 삽입에 성공했습니다.");
        } else {
            msgBox.setWindowTitle("5. File Insert 실패");
            msgBox.setText("파일 내용 삽입에 실패했습니다.");
        }
        msgBox.exec();
    }
}

void Assignment1::exitProgram() {
    QApplication::exit();
}
