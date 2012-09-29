/*---------------------------------------------+
|                                              |
| Name: include/hal/preg16.h                    |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#ifndef PREG16_H
#define PREG16_H

#include "hal/pregcommon.h"

#define PREG16TYPE uint16_t

/**
* Klasa będąca 16 bitową wariacją klasy podstawowej PRegCommon. Służy do obsługi rejestrów 16 bitowych.
*/
class PReg16:public PRegCommon<PREG16TYPE>
{
    public:
	/**
	 * Konstruktor.
	 * Potrzebny żeby wywołać konstruktora klasy bazowej.
	 * @param reg to rejestr na którym będzie działać klasa. PREG8TYPE to typ zdefiniowany jako uint16_t.
	 * @see PRegCommon
	 */
        PReg16(volatile PREG16TYPE& reg);
};

#endif // PREG16_H
