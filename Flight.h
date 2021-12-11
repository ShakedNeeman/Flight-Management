#pragma once
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

typedef struct 
{
	char*		OrginName;
	char*		destName;
	Plane		plane;
	Date		date;
}Flight;

void initFlight(Flight* pFlight, const AirportManager* pManager);
int isFlightFromSourceName(const Flight* pFlight, const char* pName);
int isFlightToDestName(const Flight* pFlight, const char* pName);
int isPlaneCodeInFlight(const Flight* pFlight, const char* pCode);
int isPlaneTypeInFlight(const Flight* pFlight, PlaneType pType);
Airport* setAiportToFlight(const AirportManager* pManager, const char* msg);
void	freeFlight(void* pFlight);





