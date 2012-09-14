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
