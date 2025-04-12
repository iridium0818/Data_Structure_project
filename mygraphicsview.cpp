#include "mygraphicsview.h"
#include <QWheelEvent>
#include <QPoint>
//#include <QDebug>
//构造函数
MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    m_scalingOffset=1; // 初始放缩比例为1
}
//析构函数
MyGraphicsView::~MyGraphicsView()
{

}
//上界判断
void MyGraphicsView::magnify()
{
    if(m_scalingOffset>=5) // 上界为10
    {m_scalingOffset=5; return;}

    m_scalingOffset+=1;
    scaling(1.6); // 视图放大1.6倍
}
//下界判断
void MyGraphicsView::shrink()
{
    if(m_scalingOffset<=1)
    {m_scalingOffset=1; return;}

    m_scalingOffset-=1;
    scaling(0.625); // 视图缩小到0.625倍
}
//根据传入的放缩比例放缩
void MyGraphicsView::scaling(qreal scaleFactor)
{
    scale(scaleFactor,scaleFactor); // 水平垂直方向各放缩scaleFator
}
//鼠标滚轮启动上下界判断然后放缩
void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPoint sroll=event->angleDelta(); // 获取鼠标滚轮的方向
    sroll.y()>0?magnify():shrink(); // 向上放大，向下缩小

}
//鼠标点击函数，获取初始坐标
void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)return;
    QGraphicsView::mousePressEvent(event);
    if(this->scene() == nullptr)
    {
        return;
    }
    // centerAnchor = 场景坐标原点 + 视图中心点
    // mapToScene(event->pos())转换为场景坐标
    // mapToScene(event->pos()) - event->pos() 视图原点在场景中的坐标
    // QPointF(width() / 2, height() / 2) 视图中心相对于视图原点的坐标
    centerAnchor = mapToScene(event->pos()) - event->pos() + QPointF(width() / 2, height() / 2); //中心位置坐标
    posAnchor = event->pos(); // 鼠标相对于视图的位置
    isMousePressed = true; // 鼠标已经按下
}
//鼠标移动函数，用于放缩
void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QPointF offsetPos = event->pos() - posAnchor; // 鼠标偏移量
    if(isMousePressed){
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse); // 设置变换锚点为鼠标位置
        centerOn(centerAnchor - offsetPos); // 根据偏移量调整视图的中心位置，实现拖动效果
    }
}
//鼠标释放函数
void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)return;
    QGraphicsView::mouseReleaseEvent(event);
    isMousePressed = false;
}

