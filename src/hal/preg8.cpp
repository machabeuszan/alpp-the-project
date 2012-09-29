/*---------------------------------------------+
|                                              |
| Name: src/hal/preg8.cpp                      |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#include "hal/preg8.h"

PReg8::PReg8(volatile  PREG8TYPE & reg):PRegCommon(reg)
{
}
