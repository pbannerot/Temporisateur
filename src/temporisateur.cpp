//============================================================================
// Name        : Temporisateur.cpp
// Author      : pascal
// Version     :
// Copyright   : Your copyright notice
// Description : Timer in C++, Ansi-style
//============================================================================

#include <iostream>

#include "temporisateur.h"
#include "counter.h"
#include "tempo692.h"
#include "tempo693.h"
#include "tempo694.h"

#define NOP __asm__("nop\n\t")

using namespace std;

string displayGamme(enum gamme version) {
	switch(version) {
	case HH_MM:
		return "HH_MM";
	case MM_SS:
		return "MM_SS";
	default:
		return "Unknown version configuration";
	}
}

void ITemporisateur::decreaseCounter() {
	int currentValue = counter.getCurrentValue();
	currentValue -= 1;
	if (currentValue < 0) {
		currentValue = 0;

		counter.stopCounter();
		triggerAlarm();
	}

	counter.setCurrentValue(currentValue);
}

string ITemporisateur::displayVersion() const {
	return displayGamme(getVersion());
}

enum gamme ITemporisateur::getVersion() const {
	return version;
}

void ITemporisateur::setVersion(enum gamme version) {
	this->version = version;
}

Counter& ITemporisateur::getCounter() {
	return counter;
}

ITemporisateur *iTimer = NULL;

void setup() {
	cout << "setup()" << endl;
	enum gamme pb6 = MM_SS;

	iTimer = new Tempo694(pb6);
	cout << iTimer->displayModel() << " " << iTimer->displayVersion() << endl;
}

void loop(int iteration) {
//	cout << "loop(" << iteration << ")" << endl;

	iTimer->readButtonsState();

	if (iTimer->getCounter().isAlive()) {
		iTimer->decreaseCounter();
	}

//	if (iteration == 10) {
//		iTimer->start.buttonAction();
//	}
//
//	if (iteration == 20) {
//		iTimer->stop.buttonAction();
//	}

	iTimer->displayDigits();
}

int main() {
	cout << "start main" << endl;

	setup();

	for (int i = 0; i < 120; i++) {
		loop(i);
	}

	delete iTimer;

	cout << "end main" << endl;

	return 0;
}
