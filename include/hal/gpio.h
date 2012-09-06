#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

class GPIO
{
    public:
        GPIO(volatile uint8_t &port,const uint8_t direction,const uint8_t initValue);
        void setValue(const uint8_t value);
        //uint8_t getValue();
    protected:
    private:
        volatile uint8_t &PORT;
        //volatile uint8_t &PIN;
        //const uint8_t DirectionMask;

};

inline GPIO::GPIO(volatile uint8_t &port,const uint8_t direction,const uint8_t initValue):PORT(port)
{
    volatile uint8_t &DDR(*(&PORT-1));

    DDR=direction;
    PORT=initValue;
}


inline void GPIO::setValue(const uint8_t value)
{
    PORT=value;
}


#endif // GPIO_H
