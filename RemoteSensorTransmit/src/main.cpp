#include <Arduino.h>
#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

int led = 3;//LED pin
int sensor = 2; //sensor pin
int val; //numeric variable
#define SwitchPin 2 

int SentMessage[1] = {000}; 
RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup()
{
  pinMode(led, OUTPUT); //set LED pin as output
	pinMode(sensor, INPUT); //set sensor pin as input
  Serial.begin (9600);
  pinMode(SwitchPin, INPUT_PULLUP); 
  digitalWrite(SwitchPin,HIGH); 
  
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
  Serial.println("Radio On");
}

void loop()
{
  {
	val = digitalRead(sensor); //Read the sensor
	if(val == LOW) //when magnetic field is detected, turn led on
	{
		digitalWrite(led, HIGH);
	}
	else
	{
		digitalWrite(led, LOW);
	}
  
  
  if (digitalRead(SwitchPin) == LOW)    // If switch is pressed
  { 
      SentMessage[0] = 111;
      radio.write(SentMessage, 1);      // Send pressed data to NRF24L01
      Serial.println("Switch Closed");
  }
  else 
  {
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);      // Send idle data to NRF24L01
      Serial.println("idle");
  }
  }
  }
  