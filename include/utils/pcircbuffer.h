#ifndef PCIRCBUFFER_H
#define PCIRCBUFFER_H


template <class T, uint8_t Capacity>
class PCircBuffer
{
	public:
		PCircBuffer();
		void clear();
		bool isFull();
		bool isEmpty();
		uint8_t size();
		uint8_t capacity();
	protected:
	private:
		T container[Capacity];
		uint8_t tail;
		uint8_t head;
		uint8_t len;
		uint8_t cap;

};

template <class T, uint8_t Capacity>
PCircBuffer<T>::PCircBuffer() :
	tail(0)
	,head(0)
	,len(0)
	,cap(Capacity)
{
}

#endif // PCIRCBUFFER_H
