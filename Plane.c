#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Plane.h"


const char* PlaneTypeStr[eNofPlane] = { "Commercial","Cargo","Military" };


PlaneType getPlaneTypeFromUser()
{
	int temp;
	printf("Enter plane type: \n");
	do {
		for (int i = 0; i < eNofPlane; i++) {
			printf("Insert %d for %s\n", i, PlaneTypeStr[i]);
		}
		scanf("%d", &temp);

	} while (temp < 0 || temp >= eNofPlane);

	return (PlaneType)temp;
}
