/*---------------------------------------------+
|                                              |
| Name: src/hal/preg8.cpp                      |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-03                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/



#include "hal/pgpopin.h"

PGpoPin::PGpoPin(volatile uint8_t &port, const uint8_t pin, bool offState):PORT(port),DDR(*(&port-1)),PINmask(1<<pin),os(offState)
{
    activate(true);
}



void PGpoPin::activate(const bool enable)
{
    if(enable)
        DDR|=(PINmask);
    else
        DDR&=~(PINmask);
}
