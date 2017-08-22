// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include "AFMotor.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

AF_DCMotor motor_1(1);
AF_DCMotor motor_2(2);
AF_DCMotor motor_3(3);
AF_DCMotor motor_4(4);

void loop() {
  delay(100);
}

void go() {
  motor_1.run(FORWARD);
  motor_2.run(FORWARD);
  motor_3.run(FORWARD);
  motor_4.run(FORWARD);
}

void back() {
  motor_1.run(BACKWARD);
  motor_2.run(BACKWARD);
  motor_3.run(BACKWARD);
  motor_4.run(BACKWARD);
}

void left() {
  motor_1.run(FORWARD);
  motor_2.run(BACKWARD);
  motor_3.run(BACKWARD);
  motor_4.run(FORWARD);
}

void right() {
  motor_1.run(BACKWARD);
  motor_2.run(FORWARD);
  motor_3.run(FORWARD);
  motor_4.run(BACKWARD);
}

void stop() {
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);
}

// callback for received data
void receiveData(int byteCount) {

  while (Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);

    switch (number) {
      case 1:
        go();
        break;
      case 2:
        back();
        break;
      case 3:
        left();
        break;
      case 4:
        right();
        break;
      default:
        stop();
        break;
    }
  }
}

// callback for sending data
void sendData() {
  Wire.write(number);
}

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Ready!");
  Serial.println("Motor test!");

  // turn on motor
  motor_1.setSpeed(255);
  motor_2.setSpeed(255);
  motor_3.setSpeed(255);
  motor_4.setSpeed(255);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);
}

