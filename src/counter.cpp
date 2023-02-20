/*
 * counter.cpp
 *
 *  Created on: 16 oct. 2022
 *      Author: pascal
 */

#include <iostream>
#include "counter.h"

using namespace std;

void Counter::startCounter() {
	cout << "start counter" << endl;
	setCounterIsAlive(true);
}
void Counter::stopCounter() {
	cout << "stop counter" << endl;
	setCounterIsAlive(false);
}

bool Counter::isAlive() const {
	return counterIsAlive;
}

int Counter::getCurrentValue() const {
	return currentValue;
}

void Counter::setCurrentValue(int currentValue) {
	this->currentValue = currentValue;
}

int Counter::getMaxValue() const {
	return maxValue;
}

void Counter::setMaxValue(int maxValue) {
	this->maxValue = maxValue;
}

void Counter::setCounterIsAlive(bool counterIsAlive) {
	this->counterIsAlive = counterIsAlive;
}

