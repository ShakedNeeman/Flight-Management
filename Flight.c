#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirportManager.h"
#include "AirPort.h"
#include "Date.h"
#include "AirLine.h"
#include "generalStrings.h"
#include "Plane.h"
#include "Flight.h"


void	initFlight(Flight* pFlight, const AirportManager* pManager)
{
	
	Airport* pPortOrg = setAiportToFlight(pManager, "Enter name of origin airport:\n");
	pFlight->OrginName = (char*)malloc(strlen(pPortOrg->name) + 1);
	strcpy(pFlight->OrginName, pPortOrg->name);
	int same;
	Airport* pPortDes;
	do {
		pPortDes = setAiportToFlight(pManager, "Enter name of destination airport:\n");

		same = isSameAirport(pPortOrg, pPortDes);
		if (same)
			printf("Same origin and destination airport\n");
	} while (same);
	pFlight->destName = (char*)malloc(strlen(pPortDes->name) + 1);
	strcpy(pFlight->destName, pPortDes->name);

	int pType;
	do {
		printf("Please enter one of the following types\n0 for Commercial\n1 for Cargo\n2 for Military\n");
		scanf("%d", &pType);
		if (pType >= eNofPlane || pType < 0)
			printf("worng option try again!");
	} while (pType >= eNofPlane || pType < 0);
	pFlight->plane.type = (PlaneType)pType;
	
	char* code = checkCode("Enter plane code - 4 UPPER CASE letters\n");
	strcpy(pFlight->plane.planeCode , code );
	free(code);

	getCorrectDate(&pFlight->date);
	
}
int isFlightFromSourceName(const Flight* pFlight, const char* orName)
{
	if ((strcmp(pFlight->OrginName, orName) == 0)) {
		return 1;
	}
	return 0;
}

int isFlightToDestName(const Flight * pFlight, const char* dstName)
{
	if ((strcmp(pFlight->destName, dstName) == 0))
		return 1;
	return 0;
}
int isPlaneCodeInFlight(const Flight* pFlight, const char* pCode)
{
	if ((strcmp(pFlight->plane.planeCode, pCode) == 0))
		return 1;
	return 0;
}
int isPlaneTypeInFlight(const Flight* pFlight, PlaneType pType)
{
	if (strcmp(PlaneTypeStr[pFlight->plane.type], PlaneTypeStr[pType])==0)
		return 1;
	return 0;
}

void	freeFlight(void* pFlight)
{
	Flight* flight = *(Flight**)pFlight;
	free(flight);
}

Airport* setAiportToFlight(const AirportManager* pManager, const char* msg)
{
	char org[MAX_LENGTH];
	Airport* port;
	do
	{
		printf("%s", msg);
		myGets(org, MAX_LENGTH);
		port = findAirportByName(pManager, org);
		if (port == NULL)
			printf("The airport does not exist!Change destination!\n");
	} while (port == NULL);

	return port;

}

