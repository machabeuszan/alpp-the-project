/*---------------------------------------------+
|                                              |
| Name: include/hal/pgpipin.h                  |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-06                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/


#ifndef PGpiPin_H
#define PGpiPin_H
#include "hal/preg8.h"

/**
 * Klasa General Purpose Output Pin - kontroler jednego pinu ogólnego przeznaczenia jako wejściowego.
 */
class PGpiPin
{
public:
    /**
     * Konstruktor.
     * Tworzymy nowy obiekt ściśle powiązany z rejestrami sprzętowymi
     * @param port jest portem do którego podłączone jest urządzenie, np PORTB, PORTC
     * @param pin to numer pinu danego portu do którego podłączone jest urządzenie zewnętrzne (wartości 0-7)
     * @param offState domyślny stan wyłączony. Jeśli false to domyslnym stanem wyłączonym urządzenia (pinu) (off) jest stan niski, jeżeli true to domyślnym stanem off jest stan wysoki.
     */
    PGpiPin(volatile uint8_t &port, const uint8_t pin, bool offState);


    /**
     * Surowa inforamacja o stanie pinu - wysoki/niski (true/false).
     */
    bool state();


    /**
     * Zwraca informację o tym wejście zostało uruchomione czy nie - czyli czy zewnętrzne urządzenie jest załączone czy nie.
     */
    bool isOn();



    /**
     * Aktywacja wejścia.
     * @param enable. Jeśli enable==true to zostanie załączony rezystor podciągający do plusa zasilania (pull-up resistor).
     */
    void activate(const bool enable=true);

    /**
     * Dektywacja wejścia. Działa odwrotnie niż activate(true)
     * @see activate
     */
    void deactivate();

private:
    volatile uint8_t &PORT;
    volatile uint8_t &DDR;
    volatile uint8_t &PIN;
    uint8_t PINmask;
    bool os;
};


inline PGpiPin::PGpiPin(volatile uint8_t &port, const uint8_t pin, bool offState):
	PORT(port),			// Przechwytuję wskazany port przez referencję
	DDR(*(&port-1)),	// Wułuskuję adres portu, zmniejszam o 1, następnie dokonuje dereferencji tak powstałego wskaźnika. Taki obiekt może zostać przejęty przez
	PIN(*(&port-2)),
	PINmask(1<<pin),
	os(offState)
{
	DDR|=(PINmask);
    activate(true);
}



inline void PGpiPin::deactivate()
{
	activate(false);
}

inline bool PGpiPin::state()
{
	return ((bool)(PIN&PINmask));
}


#endif // PGpiPin_H
