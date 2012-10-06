/*---------------------------------------------+
|                                              |
| Name: include/hal/pgpopin.h                  |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-03                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/


#ifndef PGPOPIN_H
#define PGPOPIN_H
#include "hal/preg8.h"

/**
 * Klasa General Purpose Output Pin. Kontroler jednego pinu ogólnego przeznaczenia jako wyjściowego.
 */
class PGpoPin
{
public:
    /**
     * Konstruktor.
     * Tworzymy nowy obiekt ściśle powiązany z rejestrami sprzętowymi
     * @param port jest portem do którego podłączone jest urządzenie, np PORTB, PORTC
     * @param pin to numer pinu danego portu do którego podłączone jest urządzenie zewnętrzne (wartości 0-7)
     * @param offState domyślny stan wyłączony. Jeśli false to po wywołaniu off() zostanie na wyjściu ustawiony stan niski (działanie w trybie wyjścia jako SINK). Jeśli true to po wywołaniu off() zostanie ustawiony stan wysoki (działanie w wyjścia jako SOURCE).
     */
    PGpoPin(volatile uint8_t &port, const uint8_t pin, bool offState=LO);

    /**
     * Setter. Ustawia wyjście na on/off w zależności od value. Uwzglęnia offState. Nie ustawia wyjścia na poziom wysoki/niski tylko na logiczną wartość włączony/wyłączony. Wartości logiczne zostają ustalone automatycznie.
     * @param value to wartoś ustawiana na wyjściu: true->ON, false->OFF.
     */
    void setOn(bool value);

    /**
     * Zwraca informację o tym czy wyjście jest załączone czy nie.
     */
    bool isOn();

    /**
     * Załącza wyjście.
     */
    void on();

    /**
     * Wyłącza wyjście.
     */
    void off();

    /**
     * Zmienia stan wyjścia na przeciwny.
     */
    void toggle();

    /**
     * Aktywacja wyjścia.
     * @param enable. Jeśli enable==true to wyjście zostanie aktywowane. Jeśli false to wyjście zostanie ustawione w stan wysokiej impedancji.
     */
    void activate(const bool enable=true);

    /**
     * Dektywacja wyjścia. Działa odwrotnie niż activate(true)
     * @see activate
     */
    void deactivate();

private:
    volatile uint8_t &PORT;
    volatile uint8_t &DDR;
    uint8_t PINmask;
    bool os;
};


inline PGpoPin::PGpoPin(volatile uint8_t &port, const uint8_t pin, bool offState):PORT(port),DDR(*(&port-1)),PINmask(1<<pin),os(offState)
{
    activate(true);
}



inline void PGpoPin::toggle()
{
    PORT^=PINmask;
}

inline void PGpoPin::deactivate()
{
	activate(false);
}




#endif // PGPOPIN_H
