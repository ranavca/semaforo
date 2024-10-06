#include <Led.h>
#include <Arduino.h>

void Led::init()
{
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, HIGH);
}

void Led::on()
{
    digitalWrite(this->pin, LOW);
}

void Led::off()
{
    digitalWrite(this->pin, HIGH);
}