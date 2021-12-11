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

void	addAirport(AirportManager* pManager) {

	pManager->airPortsArr = (Airport*)realloc(pManager->airPortsArr,(pManager->count+1)*sizeof(Airport));
	if (pManager->airPortsArr == NULL)
	{
		printf("Allocation Failled\n");
		return 0; 
	}
	char checkName[MAX_LENGTH];
	do {
		printf("Enter airport name:\n");
		myGets(checkName, MAX_LENGTH - 1);
		if (pManager->count == 0)
			break;
	}while (findIfAirportExistsByName(pManager, checkName) == 1);
	strcpy(pManager->airPortsArr[pManager->count].name, checkName);
	readAddressAirport(&pManager->airPortsArr[pManager->count]);
	pManager->count++;

}


void	readAddressAirport(Airport* pAirport) {

	char country[MAX_LENGTH];
	char city[MAX_LENGTH];
	char street[MAX_LENGTH];
	char numHouse[MAX_LENGTH];

	char at[2]="@";
	char sign[2] = "#";

	printf("Enter country name:\n");
	myGets(country, MAX_LENGTH-1);
	printf("Enter city name:\n");
	myGets(city, MAX_LENGTH - 1);
	printf("Enter street name:\n");
	myGets(street, MAX_LENGTH - 1);
	printf("Enter num of house:\n");
	myGets(numHouse, MAX_LENGTH - 1);

	
	pAirport->address = (char*)malloc((strlen(country)+ strlen(city)+ strlen(street)+ strlen(numHouse)+4)*sizeof(char));
	if (pAirport->address == NULL)
	{
		printf("Allocation Failled\n");
		return 0;
	}
	char* corect = checkAddress(country);
	strcpy(pAirport->address, corect);
	strcat(pAirport->address, at);
	corect = checkAddress(city);
	strcat(pAirport->address, corect);
	strcat(pAirport->address, at);
	corect = checkAddress(street);
	strcat(pAirport->address, corect);
	strcat(pAirport->address, at);
	corect = checkAddress(numHouse);
	strcat(pAirport->address, numHouse);
	

}

void printAirports(const AirportManager* pManager)
{
	for (int i = 0; i < pManager->count; i++) {
		printf("Airport name: %-20s Airport address: %s\n", pManager->airPortsArr[i].name, pManager->airPortsArr[i].address);
	}
}


Airport* findAirportByName(AirportManager* pManager , char* pName)
{
	for (int i = 0; i < pManager->count; i++) {
		if (strcmp(pName, pManager->airPortsArr[i].name)==0)
			return &pManager->airPortsArr[i];
	}
	return NULL;

}

void	freeManager(AirportManager* pManager) {
	{
		for (int i = 0; i < pManager->count; i++)
			freeAirPort(&(pManager->airPortsArr[i]));
	}
	free(pManager->airPortsArr);

}

void	initManager(AirportManager* pManager)
{
	char option;
	
	printf("-----------  Init airport Manager\n");
	pManager->airPortsArr = NULL;
	pManager->count = 0;
	do{
	printf("Do you want to enter an airport? y/Y, anything else to exit!!\n");
	scanf("%c", &option);
	cleanBuffer();
	if (toupper(option) == 'Y'){
	
		addAirport(pManager);

	}
	}while (toupper(option) == 'Y');
		
}

int findIfAirportExistsByName(AirportManager* pManager, char* pName)
{
	for (int i = 0; i < pManager->count; i++) {
		if (strcmp(pName, pManager->airPortsArr[i].name) == 0) {
			printf("This name already in use - enter a different name\n");
			return 1;
		}
	}
	
	return 0;
}