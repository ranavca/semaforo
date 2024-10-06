class Led
{
public:
    int pin;
    Led(int selectedPin)
    {
        pin = selectedPin;
    };
    void init();
    void on();
    void off();
};