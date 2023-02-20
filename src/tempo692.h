/*
 * tempo692.h
 *
 *  Created on: 15 oct. 2022
 *      Author: pascal
 */

#ifndef TEMPO692_H_
#define TEMPO692_H_

#include <iostream>

#include "temporisateur.h"
#include "ibutton.h"

using namespace std;

class Tempo692: public ITemporisateur {
private:
	ButtonIncDigit buttonDigit0;
	ButtonIncDigit buttonDigit1;

public:
	Tempo692(enum gamme version);
	std::string displayModel() const override;
	void readButtonsState() override;
	void displayDigits() override;
	void triggerAlarm() const override;
};

#endif /* TEMPO692_H_ */
