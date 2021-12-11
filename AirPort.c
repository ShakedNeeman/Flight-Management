#include "AirPort.h"
#include "generalStrings.h"

int	isSameAirport(const Airport* pPort1, const Airport* pPort2)
{
	if (!pPort1 || !pPort2)
		return 0;
	if (strcmp(pPort1->name, pPort2->name) == 0)
		return 1;

	return 0;
}

int	isAirportName(const Airport* pPort1,  char* name)
{
	if (!pPort1 || !name)
		return 0;
	if (strcmp(pPort1->name,name) == 0)
		return 1;

	return 0;
}

void	freeAirPort(Airport* pAirPort) {
	free(pAirPort->address);
}