#include <MyTimer.h>

MyTimer oneSecond(1000);
MyTimer oneSecondAndAnHalf(1500);

void setup() {
	Serial.begin(9600);
	oneSecond.setAlarm();
	oneSecondAndAnHalf.setAlarm();
}

void loop() {
	if(oneSecond.checkAlarm(true))
	{
		Serial.print(millis());
		Serial.print(" :: ");
		Serial.println("oneSecond Expired");
	}
	if(oneSecondAndAnHalf .checkAlarm(true))
	{
		Serial.print(millis());
		Serial.print(" :: ");
		Serial.println("oneSecondAndAnHalf Expired");
	}
}
