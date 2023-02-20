/*
 * button.h
 *
 *  Created on: 15 oct. 2022
 *      Author: pascal
 */

#ifndef IBUTTON_H_
#define IBUTTON_H_

#include <time.h>

#include "counter.h"
#include "temporisateur.h"

using namespace std;

#define HIGH 0x1
#define LOW  0x0

class IButton {
private:
	unsigned const long debounceDelay = 50L;
	unsigned long lastDebounceTime = 0L;
	int buttonState, lastButtonState = HIGH;

	unsigned long millis() {
		time_t seconds;
		time(&seconds);

		return seconds;
	}

	Counter counter;
	virtual void buttonAction() = 0;

public:
	virtual ~IButton() {
	}

	void readButtonValue() {
		int readingValue = LOW;			// digitalRead(BTN_START);

		// Debounce
		if (readingValue != lastButtonState) {
			lastDebounceTime = millis();
		}
		if (millis() - lastDebounceTime > debounceDelay) {
			if (buttonState != readingValue) {
				buttonState = readingValue;
			}
			if (buttonState == HIGH) {		// Trigger action only on HIGH
				buttonAction();
			}
		}
		lastButtonState = readingValue;
	}

	Counter& getCounter() {
		return counter;
	}

	void setCounter(const Counter &counter) {
		this->counter = counter;
	}
};

class ButtonStart: public IButton {
public:
	ButtonStart(const Counter &counter) {
		setCounter(counter);
	}

	void buttonAction() override {
		cout << "Action start timer" << endl;
		getCounter().startCounter();
	}
};

class ButtonStop: public IButton {
public:
	ButtonStop(const Counter &counter) {
		setCounter(counter);
	}
	void buttonAction() override {
		cout << "Action stop timer" << endl;
		getCounter().stopCounter();
	}
};

class ButtonIncDigit: public IButton {
public:
	void buttonAction() override {
		cout << "Action increment digit" << endl;
	}
};

#endif /* IBUTTON_H_ */
