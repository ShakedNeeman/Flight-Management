#pragma once
#pragma once
#include "Flight.h"
#include "AirportManager.h"
#include "generalStrings.h"

typedef enum
{
	eSortbyDate, eSortbyHoure, eSortbyOriginAirportCode, eSortbyDestAirportCode, eNotSorted, eSizeOfOption
}eSortBy;
const char* sortedBy[eSizeOfOption];

typedef struct
{
	char* name;
	int	  flightCount;
	Flight** flightArr;

}AirLine;

void	initAirLine(AirLine* pAir);
int		addFlight(AirLine* pAir, const AirportManager* pManager);
void	doPrintFlightsWithPlaneCode(AirLine* pAir ,char*  planeCode);
void	doPrintFlightsWithPlaneType(AirLine* pAir, PlaneType pType);
void	doCountFlightsFromName(AirLine* pAir, char* namePort);
void	printAirLine(const AirLine* pAir);
void    printFlightArr(const AirLine* pFlight);
void	freeFlightArr(Flight** arr, int size);
void	freeAirLine(AirLine* pAir);
void	generalArrayFunction(void* arr, int numOfElements, int sizeOfType, void(*f)(void* element)); // the method that request

