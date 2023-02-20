/*
 * tempo694.h
 *
 *  Created on: 15 oct. 2022
 *      Author: pascal
 */

#ifndef TEMPO694_H_
#define TEMPO694_H_

using namespace std;

# include "temporisateur.h"

class Tempo694: public ITemporisateur {
private:
	ButtonIncDigit buttonDigit0;
	ButtonIncDigit buttonDigit1;
	ButtonIncDigit buttonDigit2;
	ButtonIncDigit buttonDigit3;
public:
	Tempo694(enum gamme version) {
		setVersion(version);
		getCounter().setMaxValue(5999);
		getCounter().setCurrentValue(3600);
		getCounter().startCounter();
	}
	std::string displayModel() const override {
		return "Tempo694";
	}
	void readButtonsState() override {
		start.readButtonValue();
		stop.readButtonValue();
		buttonDigit0.readButtonValue();
		buttonDigit1.readButtonValue();
		buttonDigit2.readButtonValue();
		buttonDigit3.readButtonValue();
	}

	void displayDigits() override {
		float currentValue = getCounter().getCurrentValue();

		int minutes = floor(currentValue / 60);
		int secondes = currentValue - (minutes * 60);

		int digit3 = minutes / 10;
		int digit2 = minutes % 10;

		int digit1 = secondes / 10;
		int digit0 = secondes % 10;

		cout << digit3<< digit2 << ":" << digit1<< digit0 << endl;
	}

	void triggerAlarm() const override {
		cout <<"Trigger alarm" <<endl;
	}
};

#endif /* TEMPO694_H_ */
