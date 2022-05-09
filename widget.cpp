#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);

	// Init member
	User .SetWeight(ui->WeightSpinBox->value());
	Time = ui->TimeSpinBox->value();
	Speed = ui->TimeSpinBox->value();

	// Connect ui components
	connect(ui->WeightSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::WeightChanged);
	connect(ui->TimeSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::TimeChanged);
	connect(ui->SpeedSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::SpeedChanged);

	//Display & Update the calory count when necessary
	connect(this, &Widget::CaloryCountChanged,[=]()
	{
		ui->lblCaloryCount->setText(QString::number(CaloryCount));
	});

	CalculateCalories();
}

Widget::~Widget()
{
	delete ui;
}

void Widget::CalculateCalories()
{
	CaloryCount = ( (0.0213 * ( Speed * Speed * Speed ) ) - ( 0.1765 * (Speed * Speed)) + ( 0.8710 * Speed ) + 1.4577 ) * User.GetWeight() * Time;
	emit CaloryCountChanged();
}

void Widget::WeightChanged(double Amount)
{
	User.SetWeight(Amount);
	CalculateCalories();
}

void Widget::TimeChanged(double Amount)
{
	Time = Amount;
	CalculateCalories();
}

void Widget::SpeedChanged(double Amount)
{
	Speed = Amount;
	CalculateCalories();
}

