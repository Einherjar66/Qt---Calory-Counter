#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class person : public QObject
{
	Q_OBJECT
public:
	person();

	double GetWeight()const {return Weight;}
	void SetWeight(double weight);

signals:
	void WeightChanges();

private:

	double Weight;
};

#endif // PERSON_H
