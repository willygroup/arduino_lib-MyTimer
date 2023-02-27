/*
 * MyTimer.cpp - Simple timer based on millis()
 * MyTimer 20230227 by willygroup
 */

#include "MyTimer.h"

/**
 * @brief Initialize the timer
 */
MyTimer::MyTimer()
{
	timeUnit = MSECS;
}

/**
 * @brief Initialize the timer with value
 */
MyTimer::MyTimer(unsigned long time)
{
	timeUnit = MSECS;
	alarmTime = time;
	setted = false;
}

/**
 * @brief Initialize the timer with value and time unit
 */
MyTimer::MyTimer(unsigned long time, int _timeUnit)
{
	alarmTime = time;
	timeUnit = _timeUnit;
	setted = false;
}

/**
 * @brief Initialize the class setting the alarm time in ms milliseconds
 * without set the alarm
 */
void MyTimer::begin()
{
	setted = false;
}

/**
 * @brief Set time unit
 * @param SEC or MSEC
 */
void MyTimer::setMeasureUnit(int _timeUnit)
{
	timeUnit = _timeUnit;
}

/**
 * Reset the timer
 */
void MyTimer::cancel()
{
	if (timeUnit == SECS)
	{
		initTime = millis() / 1000;
	}
	else
	{
		initTime = millis();
	}
	setted = false;
}

/**
 * Set the alarm time in ms milliseconds without set the alarm
 */
void MyTimer::setAlarmTime(unsigned long time)
{
	alarmTime = time;
}

/**
 * Set the alarm in ms milliseconds
 */
void MyTimer::setAlarm(unsigned long time)
{
	if (timeUnit == SECS)
	{
		initTime = millis() / 1000;
	}
	else
	{
		initTime = millis();
	}
	alarmTime = time;
	setted = true;
}
/**
 * Set the alarm using the previous value
 */
void MyTimer::setAlarm()
{
	resetAlarm();
}

/**
 * Set Again the alarm
 */
void MyTimer::resetAlarm()
{
	if (timeUnit == SECS)
	{
		initTime = millis() / 1000;
	}
	else
	{
		initTime = millis();
	}
	setted = true;
}

/**
 * Check if the alarm is expired
 */
boolean MyTimer::checkAlarm(boolean setagain)
{
	if (setted)
	{
		if (((timeUnit == MSECS) && (millis() >= initTime + alarmTime)) ||
			((timeUnit == SECS) && ((millis() / 1000) >= initTime + alarmTime)))
		{
			if (setagain) // Set the alarm again
			{
				resetAlarm();
			}
			else
			{
				setted = false;
			}
			return true;
		}
	}
	return false;
}
/**
 * Check if the alarm is setted
 */
boolean MyTimer::isSetted()
{
	if (setted)
	{
		return true;
	}
	return false;
}
