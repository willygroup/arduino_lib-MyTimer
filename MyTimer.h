#ifndef _MYTIMER_H
#define _MYTIMER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

enum
{
	MSEC,
	SEC,
};


/**
 * Simple timer based on millis()
 */
class MyTimer {
	
	public:
		MyTimer();
		MyTimer(unsigned long time);
		MyTimer(unsigned long time, int _timeUnit);
		void begin();
		void setAlarm();
		void setAlarm(unsigned long time);
		void setAlarmTime(unsigned long time);
		boolean checkAlarm(boolean setagain);
		void cancel();
		boolean isSetted();
		void setMeasureUnit(int type);
		
	private:
		unsigned long alarmTime;
		unsigned long initTime;
		int timeUnit;
		
		boolean setted;
		void resetAlarm();
};

#endif
