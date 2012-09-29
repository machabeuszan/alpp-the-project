/*---------------------------------------------+
|                                              |
| Name: include/utils/simulSerial.cpp          |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#include "utils/simulSerial.h"


#ifdef SIM
    void sim_puts(const char * str)
    {
        const char *c;
        for(c=str;*c;c++)
        {
            FAKE_OUT=*c;
        }
    }
#endif
