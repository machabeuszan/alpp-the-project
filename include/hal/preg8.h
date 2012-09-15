#ifndef PREG8_H
#define PREG8_H

#include <avr/io.h>

#include "hal/pregcommon.h"

#define PREG8TYPE uint8_t


class PReg8:public PRegCommon<PREG8TYPE>
{
    public:
        PReg8(volatile PREG8TYPE& reg);
};

#endif // PREG8_H
