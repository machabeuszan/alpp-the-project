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
