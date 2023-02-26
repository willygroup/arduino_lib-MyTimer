#include <MyTimer.h>

MyTimer t1(1000);

void setup() {
	Serial.begin(9600);
	t1.setAlarm();
}

void loop() {
	if(t1.checkAlarm(true))
	{
		Serial.print(millis());
		Serial.print(" :: ");
		Serial.println("Expired");
	}
}
