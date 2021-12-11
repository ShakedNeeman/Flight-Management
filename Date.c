#include "Date.h"

const int DAY_MONTHS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


void getCorrectDate(Date* pDate)
{
	char date[MAX_LENGTH];
	int ok = 1;

	do {
		puts("Enter Flight Date dd$$mm$$yyyy  minimum year 2022\t");
		myGets(date, MAX_LENGTH);
		ok = checkDate(date, pDate);
		if (!ok)
			printf("Error try again\n");
	} while (!ok);
}


int	 checkDate(char* date, Date* pDate)
{
	int day, month, year;
	if (strlen(date) != 12)
		return 0;
	if ((date[2]&& date[3] != '$') || (date[6] && date[7] != '$'))
		return 0;
	sscanf(date, "%d$$%d$$%d", &day, &month, &year);
	if (day < 1 || month < 1 || month > 12 || year < MIN_YEAR)
		return 0;

	if (day > DAY_MONTHS[month - 1])
		return 0;

	pDate->day = day;
	pDate->month = month;
	pDate->year = year;

	return 1;
}

void	printDate(const Date* pDate)
{
	printf("Date: %02d$$%02d$$%04d ", pDate->day, pDate->month, pDate->year);
}

void	printDateValueStr(const void* pDate)
{
	char* myDate = (char*)pDate;
	printf("%s\n", myDate);
}



void	free_Date_Str(void* pDate1)
{
	free(pDate1);
}






