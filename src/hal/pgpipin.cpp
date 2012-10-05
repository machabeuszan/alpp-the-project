/*---------------------------------------------+
|                                              |
| Name: src/hal/preg8.cpp                      |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-06                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/
#include "hal/pgpipin.h"



bool PGpiPin::isOn()
{
    return ((bool)(PIN&PINmask))^os;
}

void PGpiPin::activate(const bool enable)
{
    if(enable)
        PORT|=(PINmask);
    else
        PORT&=~(PINmask);
}
