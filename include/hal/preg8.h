/*---------------------------------------------+
|                                              |
| Name: include/hal/preg8.h                    |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#ifndef PREG8_H
#define PREG8_H

#include <avr/io.h>

#include "hal/pregcommon.h"

#define PREG8TYPE uint8_t

/**
* Ośmiobitowa wariacja klasy PRegCommon.
* Klasa będąca 8 bitową wariacją klasy podstawowej PRegCommon. Służy do obsługi rejestrów 8 bitowych.
*/
class PReg8:public PRegCommon<PREG8TYPE>
{
public:
    /**
     * Konstruktor.
     * Potrzebny żeby wywołać konstruktora klasy bazowej.
     * @param reg to rejestr na którym będzie działać klasa. PREG8TYPE to typ zdefiniowany jako uint8_t.
     * @see PRegCommon
     */
    PReg8(volatile PREG8TYPE& reg);
};

#endif // PREG8_H
