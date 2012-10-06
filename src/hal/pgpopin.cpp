/*---------------------------------------------+
|                                              |
| Name: src/hal/pgpopin.cpp                    |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-03                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/



#include "hal/pgpopin.h"

void PGpoPin::setOn(bool value)
{
    value^=os;
    PReg8::set(PORT,0xff*value,PINmask);
}

void PGpoPin::on()
{
    setOn(true);
}

void PGpoPin::off()
{
    setOn(false);
}

bool PGpoPin::isOn()
{
    return ((bool)(PORT&PINmask))^os;
}

void PGpoPin::activate(const bool enable)
{
    if(enable)
        DDR|=(PINmask);
    else
        DDR&=~(PINmask);
}
