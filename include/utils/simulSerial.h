/*---------------------------------------------+
|                                              |
| Name: include/utils/simulSerial.h            |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#ifndef SIMULSERIAL_H_INCLUDED
#define SIMULSERIAL_H_INCLUDED

#define SIM true

#ifdef SIM
    #include <stdio.h>
    #define FAKE_OUT (*((volatile char *)0x20))
    #define FAKE_IN  (*((volatile char *)0x22))

    void sim_puts(const char * str);

#endif

#endif // SIMULSERIAL_H_INCLUDED
