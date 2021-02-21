#include <Arduino.h>
#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

int led = 3;//LED pin
int sensor0 = A0; //sensor pin
int sensor1 = A1; //sensor pin
int sensor2 = A2; //sensor pin
int sensor3 = A3; //sensor pin
int sensor4 = A4; //sensor pin
int sensor5 = A5; //sensor pin


int val0; //numeric variable
int val1; //numeric variable
int val2; //numeric variable
int val3; //numeric variable
int val4; //numeric variable
int val5; //numeric variable


int val; //numeric variable
#define SwitchPin A0

int SentMessage[1] = {000}; 
RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup()
{
  //pinMode(led, OUTPUT); //set LED pin as output
//	pinMode(sensor, INPUT); //set sensor pin as input
  pinMode(led, OUTPUT); //set LED pin as output
  pinMode(sensor0, INPUT); //set sensor pin as input
  pinMode(sensor1, INPUT); //set sensor pin as input
  pinMode(sensor2, INPUT); //set sensor pin as input
  pinMode(sensor3, INPUT); //set sensor pin as input
  pinMode(sensor4, INPUT); //set sensor pin as input
  pinMode(sensor5, INPUT); //set sensor pin as input
  Serial.begin (9600);
  pinMode(SwitchPin, INPUT_PULLUP); 
  digitalWrite(SwitchPin,HIGH); 
  
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
  Serial.println("Radio On");
}

void loop()
{
  val0 = digitalRead(sensor0); //Read the sensor
  val1 = digitalRead(sensor1); //Read the sensor
  val2 = digitalRead(sensor2); //Read the sensor
  val3 = digitalRead(sensor3); //Read the sensor 
  val4 = digitalRead(sensor4); //Read the sensor
  val5 = digitalRead(sensor5); //Read the sensor  
 //if(val0 == LOW){ //when magnetic field is detected, turn led on 
 // if (val0 == LOW || val1 == LOW || val2 == LOW || val3 == LOW|| val4 == LOW|| val5 == LOW) {
 if (val0 == LOW || val1 == LOW) {
		digitalWrite(led, HIGH);
      SentMessage[0] = 111;
      radio.write(SentMessage, 1);      // Send pressed data to NRF24L01
      Serial.println("Switch Closed");



	}
	else
	{
		digitalWrite(led, LOW);
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);      // Send idle data to NRF24L01
      Serial.println("idle");

	}
 

  }
  
  
