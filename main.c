#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "AirPort.h"
#include "generalStrings.h"
#include "AirportManager.h"
#include "AirLine.h"
#include "Plane.h"
#include "Flight.h"

typedef enum
{
	eAddFlight, eAddAirport, ePrintCompany, ePrintAirports,
	ePrintFlightOrigDest, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Add Flight", "Add Airport",
								"Print Airline", "Print all Airports",
								"Print flights between origin-destination" };


int main() {
	AirportManager	pManager;
	AirLine			airLine;
	

	initManager(&pManager);
	initAirLine(&airLine);
	{
		
		int options;
		do
		{

			printf("Please choose one of the following options\n ");
			printf(" 0  - Add Flight\n");
			printf(" 1  - Add Airport\n");
			printf(" 2  - Print Airline\n");
			printf(" 3  - Print all Airports\n");
			printf(" 4  - Print number of flights from origin airport name\n");
			printf(" 5  - Print all flights with plane code\n");
			printf(" 6  - Print all flights with plane type\n");
			printf("-1 - Quit\n");
			scanf("%d", &options);
			cleanBuffer();


			switch (options)
			{
			case 0:
			
			addFlight(&airLine,&pManager);

				break;

			case 1:

			addAirport(&pManager);

				break;

			case 2:
			 printAirLine(&airLine);

				break;

			case 3:

			printAirports(&pManager);

				break;

			case 4:
				printf("Please enter origin airport name:\n");
				char namePort[MAX_LENGTH + 1];
				myGets(namePort, MAX_LENGTH);
				doCountFlightsFromName(&airLine, namePort);
				break;

			case 5:
				; 
					char* code = checkCode("Enter plane code - 4 UPPER CASE letters\n");
					doPrintFlightsWithPlaneCode(&airLine,code);
			
				break;

			case 6:
				;
				int pType;
				do {
					printf("Please enter one of the following types\n0 for Commercial\n1 for Cargo\n2 for Military\n");
					scanf("%d" , &pType);
					if (pType >= eNofPlane || pType < 0)
					{
						printf("worng option try again!");
					}
					else doPrintFlightsWithPlaneType(&airLine, pType);
				} while(pType >= eNofPlane || pType < 0);
			
				break;

			case -1:
				printf(" Goodbey!\n ");

				break;

			default:
				printf("Invalid choice!!try again!(choose option between -1 to 6)\n");
			}
		} while (options != -1);
		freeManager(&pManager);
		freeAirLine(&airLine);

	}
}
