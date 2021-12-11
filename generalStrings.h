#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "generalStrings.h"
#include "Plane.h"
#define MAX_LENGTH 255

char*	getStrExactLength();
char* 	myGets(char* buf, size_t size);
char*   getStrExactName(const char* msg);
char*	getDynStr(char* str);
void	cleanBuffer();
char*   checkCode(char* msg);
char*	checkAddress(char* temp);
int		countUntilSpace(char* word);