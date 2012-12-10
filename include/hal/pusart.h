#ifndef PUSART_H
#define PUSART_H


class PUsart
{
	public:
		PUsart();
		void txByte(uint8_t value);
		uint8_t rxByte();
	protected:
	private:

};

#endif // PUSART_H
