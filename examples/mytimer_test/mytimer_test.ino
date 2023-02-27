/*
	MyTimer Test

	Simple example that shows a non-blocking timer working

	Created 20131012
	By willygroup
	Modified 20230227
	By willygroup

*/

#include <MyTimer.h>

MyTimer t1(1000);

void setup()
{
	Serial.begin(9600);
	t1.setAlarm();
}

void loop()
{
	if (t1.checkAlarm(true))
	{
		Serial.print(millis());
		Serial.print(" :: ");
		Serial.println("Expired");
	}
}
