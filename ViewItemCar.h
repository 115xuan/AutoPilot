#pragma once
#include "qgraphicsitem.h"
/*С���ĳ�����*/
class ViewItemCar : public QGraphicsPixmapItem
{
private:
	QPoint pos;
public:
	void init(QPoint pos);
};

