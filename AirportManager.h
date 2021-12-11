#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "generalStrings.h"
#include "AirPort.h"

typedef struct
{
	Airport* airPortsArr;
	int		count;
}AirportManager;

void	initManager(AirportManager* pManager);
void	addAirport(AirportManager* pManager);
Airport* findAirportByName(AirportManager* pManager , char* pName);
void	readAddressAirport(Airport* pAirport);
void	printAirports(const AirportManager* pManager);
void	freeManager(AirportManager* pManager);
int findIfAirportExistsByName(AirportManager* pManager, char* pName);
