/*
 * temporisateur.h
 *
 *  Created on: 15 oct. 2022
 *      Author: pascal
 */

#ifndef TEMPORISATEUR_H_
#define TEMPORISATEUR_H_



#include <math.h>

#include "counter.h"
#include "ibutton.h"

using namespace std;

enum gamme {HH_MM = 0, MM_SS = 1};

class ITemporisateur {
private:
	enum gamme version;
	Counter counter;
protected:
public:
	ButtonStart start = ButtonStart(getCounter());
	ButtonStop stop = ButtonStop(getCounter());

	virtual ~ITemporisateur() {
	}

	virtual std::string displayModel() const = 0;

	virtual void readButtonsState() = 0;
	virtual void displayDigits() = 0;
	virtual void triggerAlarm() const = 0;

	void decreaseCounter();
	string displayVersion() const;
	enum gamme getVersion() const;
	void setVersion(enum gamme version);
	Counter& getCounter();
};

#endif /* TEMPORISATEUR_H_ */
