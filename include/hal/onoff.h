/*---------------------------------------------+
|                                              |
| Name: include/hal/onoff.h                    |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#ifndef ONOFF_H_INCLUDED
#define ONOFF_H_INCLUDED

/**
* Enum which defines values for ON and OFF statesments.
*/
enum POnOff {
    ON=~0,
    OFF=0
};

enum PHighLo {
	HI=~0,
	LO=0
};

#endif // ONOFF_H_INCLUDED
