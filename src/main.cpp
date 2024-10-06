#include <Arduino.h>
#include <Led.h>
#include <Mic.h>

int const RED_LIGHT_PIN = 11;
int const YELLOW_LIGHT_PIN = 12;
int const GREEN_LIGHT_PIN = 13;
int const AMP_PIN = A0;

const int VOLTAGE_THRESHOLD_HIGH = 0;
const int VOLTAGE_THRESHOLD_MEDIUM = 0;
const int VOLTAGE_THRESHOLD_LOW = 0;

Led redLed = Led(RED_LIGHT_PIN);
Led greenLed = Led(GREEN_LIGHT_PIN);
Led yellowLed = Led(YELLOW_LIGHT_PIN);

Mic mic = Mic(AMP_PIN);

void allOff() {
   redLed.off();
  greenLed.off();
  yellowLed.off();
}

void setup()
{
  Serial.begin(9600);
  redLed.init();
  greenLed.init();
  yellowLed.init();
}

void loop()
{
  double voltage = mic.listen();
  Serial.println(voltage);
  double spl = (log10(voltage/0.00631)*20) + 25;
  allOff();
  if(spl > 60) {
    yellowLed.on();
    return;
  }  
  if(spl > 80) {
    redLed.on();
    return;
  }  
  greenLed.on();
}