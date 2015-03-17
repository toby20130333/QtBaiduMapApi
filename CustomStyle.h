#ifndef CUSTOMSTYLE_H
#define CUSTOMSTYLE_H
#include <QProxyStyle>
#include <QStyleOption>
class CustomStyle : public QProxyStyle
{
void drawControl(ControlElement element, const QStyleOption* option, QPainter* painter, const QWidget* widget = 0) const
{
    if (element == QStyle::CE_CheckBox ||
        element == QStyle::CE_RadioButton) {
//        option->styleObject->setProperty("_q_no_animation", true);
    }
    QProxyStyle::drawControl(element, option, painter, widget);
}
};
#endif // CUSTOMSTYLE_H
