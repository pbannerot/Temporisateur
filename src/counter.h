/*
 * counter.h
 *
 *  Created on: 16 oct. 2022
 *      Author: pascal
 */

#ifndef COUNTER_H_
#define COUNTER_H_

using namespace std;

class Counter {
private:
	int currentValue = 0;
	int maxValue = 0;
	bool counterIsAlive = false;
public:
	void startCounter();
	void stopCounter();

	bool isAlive() const;

	int getCurrentValue() const;
	void setCurrentValue(int currentValue);

	int getMaxValue() const;
	void setMaxValue(int maxValue = 0);

	void setCounterIsAlive(bool counterIsAlive = false);
};

#endif /* COUNTER_H_ */
