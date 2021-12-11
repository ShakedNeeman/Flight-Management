#define _CRT_SECURE_NO_WARNINGS
#ifndef __DATE_H
#define __DATE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "generalStrings.h"

#define MIN_YEAR 2022

typedef struct 
{
	int			day;
	int			month;
	int			year;
}Date;




void	getCorrectDate(Date* pDate);
int		checkDate(char* date, Date* pDate);
void	printDate(const Date* pDate);

void	printDateValueStr(const void* pDate); //print date str type
void	free_Date_Str(void* pDate1); //free date type (char*)



#endif