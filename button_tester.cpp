//
// Created by Phillip on 17.10.2025.
//

#define Button1 10
#define Button2 11
#define Button3 12
#include <esp32-hal-gpio.h>
#include <HardwareSerial.h>

int button1_state;
int button2_state;
int button3_state;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(Button1, INPUT);
    pinMode(Button2, INPUT);
    pinMode(Button3, INPUT);
}

void loop() {
    button1_state = !digitalRead(Button1);
    button2_state = !digitalRead(Button2);
    button3_state = !digitalRead(Button3);

    delay(10);
    Serial.print("Button 1 :");Serial.println(button1_state);
    Serial.print("Button 2 :");Serial.println(button2_state);
    Serial.print("Button 3 :");Serial.println(button3_state);
    delay(100);
}
