#include "widget.h"
#include "ui_widget.h"
#include <QUrl>
#include "CustomStyle.h"
#include <QWebView>
#include <QLineEdit>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);    
    QWebSettings *settings = QWebSettings::globalSettings();
    settings->setAttribute(QWebSettings::PluginsEnabled, true);//允许插件
    settings->setAttribute(QWebSettings::JavascriptEnabled, true);//JavaScript
    settings->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);//
    settings->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    settings->setFontFamily(QWebSettings::FixedFont,"幼圆");

    ui->webView->setStyle(new CustomStyle());
    ui->webView->load(QUrl("file:///D:/BigData/Qt-Tools/Demo/testwebview/map.html"));
//    ui->webView->load(QUrl("http://www.yicai.com/video/"));
    connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(populateJavaScriptWindowObject()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    onBtnCallJSClicked();
}
void Widget::populateJavaScriptWindowObject()
{
   ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("Mywebkit", this);
}
void Widget::onBtnCallJSClicked()
{
    QString allStr  = QDateTime::currentDateTime().toString();
    QStringList xylst = ui->lineEdit_2->text().split(",");
    QString strVal = QString("callfromqt(\"%1\",\"%2\",\"%3\",\"%4\");").arg(ui->lineEdit_3->text()).arg(ui->lineEdit->text()).arg(xylst.at(0)).arg(xylst.at(1));
    qDebug()<<"onBtnCallJSClicked  "<<strVal;
    ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
}
void Widget::onCallfromJs(QString str,QString str1,QString str2)
{
    qDebug()<<"onCallfromJs"<< str<<"\n"<<str1<<"\n"<<str2;
}

void Widget::on_pushButton_clicked()
{
    onBtnCallJSClicked();
}

void Widget::on_pushButton_2_clicked()
{
    onBtnCallJSClicked();
}
