#include "widget.h"
#include <QApplication>
#include "ui_widget.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Widget w;
    w.resize(400, 600);
    w.setWindowTitle("Convertor");

    /*
    QPushButton button_convert("CONVERT");
    button_convert.resize(100, 50);
    button_convert.show();
    */




    w.show();


    return a.exec();
}
