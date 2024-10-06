#include <Arduino.h>
#include <Mic.h>

double Mic::listen()
{
    unsigned long startMillis = millis();
    unsigned int peakToPeak = 0;

    unsigned int signalMax = 0;
    unsigned int signalMin = 1024;

    while (millis() - startMillis < sampleWindow)
    {
        sample = analogRead(this->pin);

        if (sample > 1024)
            return;

        if (sample > signalMax)
        {
            signalMax = sample;
        }
        else if (sample < signalMin)
        {
            signalMin = sample;
        }
    }

    peakToPeak = signalMax - signalMin;
    double volts = (peakToPeak * 5.0) / 1024;
    return volts;
}