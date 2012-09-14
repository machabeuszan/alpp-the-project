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
