#include <esp32-hal-gpio.h>
#include <HardwareSerial.h>

#define LED 13

void setup() {
    // put your setup code here, to run once:
    pinMode(LED,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(LED,HIGH);
    Serial.println("LED HIGH");
    delay(500);
    digitalWrite(LED,LOW);
    Serial.println("LED LOW");
    delay(500);
}
