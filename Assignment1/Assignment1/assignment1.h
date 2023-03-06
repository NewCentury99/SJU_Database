#pragma once
#include <QtWidgets/QDialog>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>
#include <filesystem>
#include "ui_assignment1.h"
#include "fileManager.h"

class Assignment1 : public QDialog {
    Q_OBJECT

private:
    Ui::Assignment1Class ui;
    FileManager* fileManager;

public:
    Assignment1(QWidget *parent = nullptr);
    ~Assignment1();

    // UI Setup Methods
    void setupBtnListener();

    // UI Feature Methods
    void executeFileOpen();
    void executeFilePrint();
    void executeFileUpdate();
    void executeFileDelete();
    void executeFileInsert();
    void exitProgram();
};
