#include "widget.h"
#include <QApplication>
#include "CustomStyle.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new CustomStyle());
    Widget w;
//    playAudioFile("C:/Users/Administrator/Downloads/小苹果.mp3");
    w.show();

    return a.exec();
}
