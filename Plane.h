#define _CRT_SECURE_NO_WARNINGS
#ifndef _PLANE_
#define _PLANE_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "generalStrings.h"


#define CODE_LENGTH 4



typedef enum {eCommercial,eCargo,eMilitary,eNofPlane} PlaneType;
const char* PlaneTypeStr[eNofPlane];


typedef struct 
{
char  planeCode[CODE_LENGTH+1];
PlaneType type;
}Plane;


PlaneType getPlaneTypeFromUser();





#endif