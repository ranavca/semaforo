class Mic
{
private:
    int sampleWindow = 50;
    unsigned int sample;

public:
    int pin;
    Mic(int selectedPin)
    {
        pin = selectedPin;
    }
    double listen();
};