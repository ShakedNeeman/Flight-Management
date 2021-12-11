
#ifndef _AIRLINE_H_
#define _AIRLINE_H_
#include "generalStrings.h"

typedef struct
{
	char name[MAX_LENGTH+1];
	char* address;

}Airport;
 
int		isSameAirport(const Airport* pPort1, const Airport* pPort2);
int		isAirportName(const Airport* pPort1, char* name);
void	freeAirPort(Airport* pAirPort);






#endif