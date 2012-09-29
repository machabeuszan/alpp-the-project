#ifndef PREG16_H
#define PREG16_H

#include "hal/pregcommon.h"

#define PREG16TYPE uint16_t

class PReg16:public PRegCommon<PREG16TYPE>
{
    public:
        PReg16(volatile PREG16TYPE& reg);
};

#endif // PREG16_H
