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


class PLed:public PGpoPin
{
	public:
		PLed(volatile uint8_t &port, const uint8_t pin, bool offState);
		PLed(PGpoPin &pgpopin);
	protected:
	private:
};


inline PLed::PLed(PGpoPin &pgpopin):PGpoPin(pgpopin)
{
	;
}

inline PLed::PLed(volatile uint8_t &port, const uint8_t pin, bool offState):PGpoPin(port,pin,offState)
{
	;
}


#endif // PLED_H
