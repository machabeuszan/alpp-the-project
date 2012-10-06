/*---------------------------------------------+
|                                              |
| Name: src/hal/pgpipin.cpp                    |
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
    return (state())^os;
}

void PGpiPin::activate(const bool enable)
{
    if(enable)
        PORT|=(PINmask);
    else
        PORT&=~(PINmask);
}
