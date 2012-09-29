/*---------------------------------------------+
|                                              |
| Name: src/hal/preg16.cpp                     |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#include "hal/preg16.h"

PReg16::PReg16(volatile PREG16TYPE& reg):PRegCommon(reg)
{
}
