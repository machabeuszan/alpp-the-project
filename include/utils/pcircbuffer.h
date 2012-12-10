/*---------------------------------------------+
|                                              |
| Name: include/hal/pcircbuffer.h              |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-12-10                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: GNU LGPL v3 (see COPYING)          |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#ifndef PCIRCBUFFER_H
#define PCIRCBUFFER_H

#include <avr/io.h>
//#include "utils/simulSerial.h"


/**
 * Szablon klasy będącej jednym z kontenerów: jest to bufor cykliczny. Jego zadaniem jest buforowanie obiektów typu T.
 * @param T jest typem który będzie przechowywany w buforze. Jeśli T jest klasą, musi mieć ona zaimplementowany operator =()
 * @param Capacity określa pojemność bufora
 * Bufor jest zaimplementowany tak, że przy skończniu się pojemności bufora najstarsze elementy będą nadpisywane
 */
template <class T, uint8_t Capacity>
class PCircBuffer
{
	public:
		/**
		 * Publiczna definicja możliwych błędów
		 */
		enum ERRS {
			/// brak błędu
			ERROR_NO	= 0,
			/// błąd nadpisania najstarszej danej
			ERROR_OVERFL	= _BV(1),
			/// błąd przy odczycie - brak danych do odczytu
			ERROR_NOMORE	= _BV(2),
			/// błąd oznaczający odmowę dopisania do bufora, gdyż jest pełny. Obecnie nie używany
			ERROR_NOSPACE	= _BV(3)
		};
		/**
		 * Konstruktor. Nie przyjmuje obecnie żadnych parametrów ale jest niezbędny do poprawnej inicjalizacji klasy
		 */
		PCircBuffer();
		/**
		 * Dodaje element do bufora.
		 * @param val jest elementem który zostanie skopiowany do pamięci bufora.
		 * Obecnie, jeśli zabraknie miejsca, najstarsze dane zostają nadpisane.
		 */
		void append(T val);
		//int8_t append(T &rVal);
		/**
		 * Wyciąga najstarszy element z bufora i zwalnia miejsce na nowe elementy. Jako że to jest bufor cykliczny, żadne czyszczenie pamięci, ani wywoływanie destruktorów nie następuje. Zwolnione miejsce zostanie po prostu nadpisana prędej przy później przy wywołaniu append().
		 * @return kopia najstarszego elementu z bufora.
		 */
		T take();
		//int8_t take(T &rVal);
		/**
		 * Sprawdza czy bufor jest pełen, tj czy wszystkie miejsca są zapełnione.
		 * @return true jeśli bufor jest pełen.
		 */
		bool isFull() { return (len==cap); }
		/**
		 * Sprawdza czy bufor jest pusty, tj nie ma w nim żadnego elementu. Uwaga !isEmpty to nie to samo co isFull().
		 * @return true jeśli bufor jest pusty.
		 */
		bool isEmpty() { return (len==0); }
		/**
		 * Informuje ile obecnie jest elementów w buforze.
		 * @return liczba elementów w buforze
		 */
		uint8_t size() { return len; }

		/**
		 * Informuje ile zostało w buforze wolnego miejsca.
		 * @return ilość wolnego miejsca.
		 */
		uint8_t space() { return cap-len; }

		/**
		 * Informuje jaka jest całkowita pojemność bufora.
		 * @return całkowita pojemność buora;
		 */
		uint8_t capacity() { return cap; }

		/**
		 * Pozwala sprawdzić czy operacje dopisania/odczytania powiodły się
		 * @return kod błędu w postaci wartości z enum ERRS.
		 * @see ERRS
		 */
		int8_t errors();

		/**
		 * Wypełnia cały bufor domyślną warotścią value
		 * @param value wartość jaka ma się znaleźć w komórkach
		 */
		void fill(T &value);
	protected:
	private:
		T container[Capacity];
		uint8_t tail;
		uint8_t head;
		volatile uint8_t len;
		const uint8_t cap;
		T emptyRet;
		int8_t error_occured;

		void next(uint8_t &val);
};



template <class T, uint8_t Capacity>
PCircBuffer<T,Capacity>::PCircBuffer() :
	tail(1)
	,head(0)
	,len(0)
	,cap(Capacity)
{
}





template <class T, uint8_t C>
void PCircBuffer<T,C>::next(uint8_t &val)
{
	val = (val + 1) % cap;
}


template <class T, uint8_t C>
void PCircBuffer<T,C>::append(T val)
{
	next(head);
	if(isFull())
	{
		error_occured |= ERROR_OVERFL;
		next(tail);
	} else {
		len++;
	}
	container[head]=val;
}


#ifdef SIM
	char txtbuff[100];
	void someDelay(uint8_t loops = 5)
	{
		for(uint8_t i=0;i<=loops;i++)
		{
			_delay_ms(10);
			sprintf(txtbuff,"r");
			sim_puts(txtbuff);
		}
	}
#endif

template <class T, uint8_t C>
T PCircBuffer<T,C>::take()
{
	T ret;
	if(!isEmpty())
	{
		ret = container[tail];
	#ifdef SIM
		someDelay(10);
	#endif
		next(tail);
		len--;
	} else {
		ret = emptyRet;
		error_occured |= ERROR_NOMORE;
	}

	return ret;
}

template <class T, uint8_t C>
int8_t PCircBuffer<T,C>::errors()
{
	int8_t err = error_occured;
	error_occured = ERROR_NO;
	return err;
}

template <class T, uint8_t C>
void PCircBuffer<T,C>::fill(T &value)
{
	for(uint8_t i=0; i<cap;i++)
		container[i]=value;
}


#endif // PCIRCBUFFER_H
