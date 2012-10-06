/*---------------------------------------------+
|                                              |
| Name: src/hal/pled.cpp                       |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-10-06                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#include "sys/pled.h"

void PLed::blink(uint8_t n)
{
	for(uint8_t i=0;i<n;i++)
	{
		on();
		_delay_ms(10);
		off();
		_delay_ms(90);
	}
}


void PLed::setPercent(uint8_t percent)
{
	setLevel(percent*lim/100);
}


void PLed::poll()
{
	if(counter==0)
	{
		on();
	}
	if(counter==lv)
	{
		off();
	}
	++counter%=lim;
}
