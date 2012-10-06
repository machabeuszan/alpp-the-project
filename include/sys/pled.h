/*---------------------------------------------+
|                                              |
| Name: src/hal/pled.h                         |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-06                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/


#ifndef PLED_H
#define PLED_H
#include "hal/pgpopin.h"
#include <util/delay.h>


/**
 * Kontroler diody świecącej.
 * Oprócz prostego załącz/wyłącz pozwala na miganie diodą, albo też świecenie z zadaną jasnością (bitbang PWM). Jeśli nie potrzeba tak dużego narzutu programu, to lepiej użyć klasy PGpoPin.
 */
class PLed:public PGpoPin
{
	public:
		/**
		 * Tworzymy nowy obiekt ściśle powiązany z rejestrami sprzętowymi
		 * @param port jest portem do którego podłączone jest urządzenie, np PORTB, PORTC
		 * @param pin to numer pinu danego portu do którego podłączone jest urządzenie zewnętrzne (wartości 0-7)
		 * @param offState domyślny stan wyłączony. Jeśli false to po wywołaniu off() zostanie na wyjściu ustawiony stan niski (działanie w trybie wyjścia jako SINK). Jeśli true to po wywołaniu off() zostanie ustawiony stan wysoki (działanie w wyjścia jako SOURCE).
		 * @param limit skraca obieg zliczania przy wykonywaniu świecenia na ustalonym poziomie (bitbang PWM). Wartość 0-255.
		 * @see poll()
		 * @see PGpoPin()
		*/
		PLed(volatile uint8_t &port, const uint8_t pin, bool offState, uint8_t limit=0xff);

		/**
		 * Tworzymy nowy obiekt oparty na istniejącym pinie wyjściowym.
		 * @param pgpopin obiekt PGpoPin - kontroler pinu wyjściowego.
		 * @see PGpoPin
		 */
		PLed(PGpoPin &pgpopin, uint8_t limit=0xff);

		/**
		 * Miga diodą. Wykonuje n impulsów diodą (impuls składa się z sekwencji on()->delay 10ms->off()->delay 90ms. Cały okres jednego pulsu to ok 100ms
		 */
		void blink(uint8_t n=1);

		/**
		 * Ustawia poziom jasności świecenia diody (bitbang PWM). Koliduje z funkcjami on, off, blink
		 * @param level to poziom jasności diody od 0 (zgaszona) do 255 (świeci w pełni);
		 */
		void setLevel(uint8_t level);
		/**
		 * Ustawia procentowy poziom jasności świecenia diody (bitbang PWM). Koliduje z funkcjami on, off, blink
		 * @param percent to procent jasności diody od 0% (zgaszona) do 100% (świeci w pełni);
		 */
		void setPercent(uint8_t percent);

		/**
		 * Aktualna wartość poziomu jasności świecenia.
		 */
		uint8_t level();

		/**
		 * Główna funkcja która realizuje świecenie diody na zadanym poziomie.
		 * Musi być wykonywana co określony czas. Aby świecenie było stałe na danym poziomie nie należy używać opóźnień pętli tylko należy wywoływać tą funkcję np w reakcji na przerwanie sprzętowego (lub systemowego) timera.
		 */
		void poll();

	protected:
	private:
		uint8_t lv;
		uint8_t counter;
		uint8_t lim;

};



inline PLed::PLed(PGpoPin &pgpopin, uint8_t limit) :
	PGpoPin(pgpopin),
	counter(0),
	lim(limit)
{
	;
}

inline PLed::PLed(volatile uint8_t &port, uint8_t pin, bool offState, uint8_t limit) :
	PGpoPin(port,pin,offState),
	counter(0),
	lim(limit)
{
	;
}

inline void PLed::setLevel(uint8_t level) { lv=(level<=lim)?level:lim; }

inline uint8_t PLed::level() { return lv; }



#endif // PLED_H
