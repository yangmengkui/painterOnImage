#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_rectWidth = 0;
    m_rectHeight = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    m_rectWidth = mouseEvent->pos().rx() - m_startX;
    m_rectHeight = mouseEvent->pos().ry() - m_startY;
    update();
}

void Widget::mousePressEvent(QMouseEvent *pressEvent)
{
    if(pressEvent->button()== Qt::LeftButton)
    {
        m_startX = pressEvent->pos().rx();
        m_startY = pressEvent->pos().ry();
        m_rectWidth = pressEvent->pos().rx() - m_startX;
        m_rectHeight = pressEvent->pos().ry() - m_startY;
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *)
{

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.save();
    QImage image(":/new/prefix1/wait.png");
    painter.drawImage(QRect(0,0,800,480), image);
    painter.restore();
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(255,0,0));
    painter.setPen(pen);
    painter.drawRect(m_startX,m_startY,m_rectWidth,m_rectHeight);
}
