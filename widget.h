#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebFrame>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void populateJavaScriptWindowObject();
    void onBtnCallJSClicked();
    void onCallfromJs(QString str, QString str1, QString str2);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
