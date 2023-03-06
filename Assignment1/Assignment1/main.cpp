#include "assignment1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Assignment1 mainMenuDialog;
    mainMenuDialog.show();
    return app.exec();
}
