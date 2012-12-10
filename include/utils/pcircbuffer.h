#ifndef PCIRCBUFFER_H
#define PCIRCBUFFER_H

#include <avr/io.h>
#include "utils/simulSerial.h"

template <class T, uint8_t Capacity>
class PCircBuffer
{
	public:
		enum ERRS {
			ERROR_NO	= 0,
			ERROR_OVERFL	= _BV(1),
			ERROR_NOMORE	= _BV(2),
			ERROR_NOSPACE	= _BV(3)
		};
		PCircBuffer();
		void clear();
		void enqueue(T val);
		//int8_t enqueue(T &rVal);
		T dequeue();
		//int8_t dequeue(T &rVal);
		bool isFull();
		bool isEmpty();
		uint8_t size();
		uint8_t capacity();
		int8_t errors();
		void fill(uint8_t numOfElement, T &value);
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
uint8_t PCircBuffer<T,C>::size()
{
	return len;
}

template <class T, uint8_t C>
uint8_t PCircBuffer<T,C>::capacity()
{
	return cap;
}

template <class T, uint8_t C>
bool PCircBuffer<T,C>::isEmpty()
{
	return (len==0);
}

template <class T, uint8_t C>
bool PCircBuffer<T,C>::isFull()
{
	return (len==cap);
}

template <class T, uint8_t C>
void PCircBuffer<T,C>::next(uint8_t &val)
{
	val = (val + 1) % cap;
}


template <class T, uint8_t C>
void PCircBuffer<T,C>::enqueue(T val)
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
T PCircBuffer<T,C>::dequeue()
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


#endif // PCIRCBUFFER_H
