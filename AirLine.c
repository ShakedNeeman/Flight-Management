#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirLine.h"
#include "Airport.h"
#include "Flight.h"
#include "AirportManager.h"
#include "generalStrings.h"

void	initAirLine(AirLine* pAir)
{
	printf("-----------  Init Airline\n");
	pAir->name = getStrExactName("Enter Airline name:\n");
	pAir->flightArr = NULL;
	pAir->flightCount = 0;
}

int	addFlight(AirLine* pAir, const AirportManager* pManager)
{
	if (pManager->count < 2)
	{
		printf("There are not enoght airport to set a flight(less than 2 airports)\n");
		return 0;
	}
	pAir->flightArr = (Flight**)realloc(pAir->flightArr, (pAir->flightCount + 1) * sizeof(Flight*));
	if (pAir->flightArr == NULL)
	{
		printf("Allocation Failled\n");
		return 0;
	}
	pAir->flightArr[pAir->flightCount] = (Flight*)calloc(1, sizeof(Flight));
	if (!pAir->flightArr[pAir->flightCount])
		return 0;
	initFlight(pAir->flightArr[pAir->flightCount], pManager);
	pAir->flightCount++;
	return 1;
}

void	doPrintFlightsWithPlaneCode(AirLine* pAir, char*  planeCode)
{	
		printf("All flights with plane code %s:\n", planeCode);
		for (int i = 0; i < pAir->flightCount; i++) {
			if (isPlaneCodeInFlight(pAir->flightArr[i], planeCode) == 1) {
				printf("Flight From %s To %s  \n Plane type: %s , code: %s \n", pAir->flightArr[i]->OrginName,
					pAir->flightArr[i]->destName, PlaneTypeStr[pAir->flightArr[i]->plane.type], pAir->flightArr[i]->plane.planeCode);
			}
		}
		
	}

void doPrintFlightsWithPlaneType(AirLine* pAir, PlaneType pType)
{
	printf("All flights with plane type %s:\n ", PlaneTypeStr[pType]);
	for (int i = 0; i < pAir->flightCount; i++) {
		if (isPlaneTypeInFlight(pAir->flightArr[i],pType) == 1) {
			printf("Flight From %s To %s  \n Plane type: %s , code: %s \n", pAir->flightArr[i]->OrginName,
				pAir->flightArr[i]->destName, PlaneTypeStr[pAir->flightArr[i]->plane.type], pAir->flightArr[i]->plane.planeCode);
		}

	}
}


void	doCountFlightsFromName(AirLine* pAir ,char* namePort)
{ 
	int count = 0;
	for (int i = 0; i < pAir->flightCount; i++) {
		if (isFlightFromSourceName(pAir->flightArr[i], namePort) == 1)
		{
			count++;
		}
	}
	if (count == 0)
	{
		printf("There are No flights from this airport\n");
	}
	else 
		printf("There are %d flights from this airport\n", count);	
}

void addAirLine(AirLine* pAir) 
{
	printf("Enter Airline name\n");
	scanf("%c" , &(pAir->name));
	cleanBuffer();
}

void printAirLine(const AirLine* pAir)
{
	printf("Airline: %s\n", pAir->name);
	printf("Has %d flights\n", pAir->flightCount);
	if(pAir->flightCount > 0)
	printFlightArr(pAir);

}


void printFlightArr(const AirLine* pAir)
{
	for (int i = 0; i < pAir->flightCount; i++) {
		printf("Flight From %s To %s\t Date: %2d%$$%2d$$%4d \n Plane type: %s , code: %s \n", pAir->flightArr[i]->OrginName,
				pAir->flightArr[i]->destName, pAir->flightArr[i]->date.day, pAir->flightArr[i]->date.month, pAir->flightArr[i]->date.year,
			PlaneTypeStr[pAir->flightArr[i]->plane.type], pAir->flightArr[i]->plane.planeCode);
		}
	}


void	freeFlightArr(Flight** arr, int size)
{
	generalArrayFunction(arr, size, sizeof(Flight*), freeFlight);
}

void	freeAirLine(AirLine* pComp)
{
	freeFlightArr(pComp->flightArr, pComp->flightCount);
	free(pComp->flightArr);
	free(pComp->name);
}

void	generalArrayFunction(void* arr, int numOfElements, int sizeOfType, void(*f)(void* element))
{
	for (int i = 0; i < numOfElements; i++)
	{
		f((char*)arr + i * sizeOfType);
	}
}
