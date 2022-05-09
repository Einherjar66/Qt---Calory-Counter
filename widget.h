#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"person.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();

private slots:
	void CalculateCalories();
	void WeightChanged(double Amount);
	void TimeChanged(double Amount);
	void SpeedChanged(double Amount);

signals:
	void CaloryCountChanged();

private:
	Ui::Widget *ui;

	person User;
	double Time;
	double Speed;
	double CaloryCount;
};
#endif // WIDGET_H
