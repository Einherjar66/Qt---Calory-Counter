#include "person.h"

person::person()
{
	Weight = 0.0;
}

void person::SetWeight(double weight)
{
	if (this->Weight != weight)
	{
		this->Weight = weight;
		emit WeightChanges();
	}

}
