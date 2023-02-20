/*
 * tempo693.h
 *
 *  Created on: 15 oct. 2022
 *      Author: pascal
 */

#ifndef TEMPO693_H_
#define TEMPO693_H_

using namespace std;

#include "temporisateur.h"

class Tempo693: public ITemporisateur {
private:
	ButtonIncDigit buttonDigit0;
	ButtonIncDigit buttonDigit1;
	ButtonIncDigit buttonDigit3;
public:
	Tempo693(enum gamme version) {
		setVersion(version);
		getCounter().setMaxValue(599);
		getCounter().setCurrentValue(599);
		getCounter().startCounter();
	}
	std::string displayModel() const override {
		return "Tempo693";
	}
	void readButtonsState() override {
//		start.readButtonValue();
		stop.readButtonValue();
		buttonDigit0.readButtonValue();
		buttonDigit1.readButtonValue();
		buttonDigit3.readButtonValue();
	}

	void displayDigits() override {
		float currentValue = getCounter().getCurrentValue();

		int minutes = floor(currentValue / 60);
		int secondes = currentValue - (minutes * 60);

		int digit2 = minutes % 10;

		int digit1 = secondes / 10;
		int digit0 = secondes % 10;

		cout << digit2 << ":" << digit1<< digit0 << endl;
	}
	void triggerAlarm() const override {
		cout << "Trigger alarm" << endl;
	}

};

#endif /* TEMPO693_H_ */
