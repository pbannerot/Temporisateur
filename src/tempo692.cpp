/*
 * tempo692.cpp
 *
 *  Created on: 16 oct. 2022
 *      Author: pascal
 */

#include <iostream>

#include "temporisateur.h"
#include "tempo692.h"
#include "ibutton.h"

using namespace std;

Tempo692::Tempo692(enum gamme version) {
	setVersion(version);
	getCounter().setMaxValue(99);
	getCounter().setCurrentValue(99);
	getCounter().startCounter();

//		ButtonStart b = new ButtonStart();

}

std::string Tempo692::displayModel() const {
	return "Tempo692";
}

void Tempo692::readButtonsState()
 {
	start.readButtonValue();
	stop.readButtonValue();
	buttonDigit0.readButtonValue();
	buttonDigit1.readButtonValue();
}

void Tempo692::displayDigits() {
	int currentValue = getCounter().getCurrentValue();

	int digit1 = currentValue / 10;
	int digit0 = currentValue % 10;

	cout << digit1 << digit0 << endl;
}

void Tempo692::triggerAlarm() const {
	cout << "Trigger alarm" << endl;
}

