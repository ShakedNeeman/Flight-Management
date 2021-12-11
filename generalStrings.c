#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "generalStrings.h"
#include "Plane.h"




char* getStrExactLength()
{
	char* theStr = NULL;
	int len;
	char inpStr[MAX_LENGTH]; //variable to hold the string that the user gives

	//Ask for a string from the user
	printf("Enter a String:");
	myGets(inpStr, sizeof(inpStr));

	//find string size and add 1 for the '\0'
	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*)malloc(len * sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	//can use the strdup function replace line 77 to 82
	//theStr = strdup(inpStr);
	return theStr;
}
char* getStrExactName(const char* msg)
{
	char* str;
	char temp[MAX_LENGTH];
	printf("%s", msg);
	myGets(temp, MAX_LENGTH);
	str = getDynStr(temp);
	return str;
}

char* getDynStr(char* str)
{
	char* theStr;
	theStr = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (!theStr)
		return NULL;

	strcpy(theStr, str);
	return theStr;
}

char* myGets(char* buf, size_t size)
{
	if (buf != NULL && size > 0)
	{
		if (fgets(buf, size, stdin))
		{
			buf[strcspn(buf, "\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;

}

void cleanBuffer()
{
int c;
while ((c = getchar()) != '\n'&&c != EOF);
}

char* checkCode(char* msg) {
	char buf[MAX_LENGTH];
	int flag = 1;
	char* code = malloc(CODE_LENGTH +1);
	do {
		printf("%s", msg);
		scanf("%s", buf);
		cleanBuffer();
	
		if (strlen(buf) != 4)
		{
			printf("Code should be 4 letters\n");
			flag = 0;
			continue;
			
		}
		for (int i = 0; i < CODE_LENGTH; i++) {
			if (buf[i] < 'A' || buf[i] > 'Z') {
				printf("code should be 4 letters UPPER CASE!\n");
				flag = 0;
				break;
			}	else flag = 1;
		}
	
	} while (flag == 0);
	strcpy(code, buf);
	return code;

}

char* checkAddress(char* temp) {
	int i = 0, space = 0, numWord = 1;

	while ( i <= strlen(temp)) {
		if (temp[i] == ' ') 
		{
			space++;
			numWord++;
		}
		i++;
	}	
	if (space > 0) {
		int j = 0 , flag =0;
		while (j < (strlen(temp))) {
			if (countUntilSpace(&temp[j]) % 2 == 0) {
				for (int i = 0; i < (countUntilSpace(&temp[j])); i++)
				{
					if (flag == 0)
					{
						temp[j+i] = toupper(temp[j + i]);
						flag = 1;
					}
					else
					{
						temp[j + i] = tolower(temp[j + i]);
						flag = 0;
					}
				}
				flag = 0;
			}

			else if (numWord == 1) 
			{
				(temp[j] = tolower(temp[j]));
			}
			else(temp[j] = toupper(temp[j]));

		j = countUntilSpace(&temp[j]) + 1 + j;
		numWord= numWord-1;
		}
		
	}
	else(temp[0] = tolower(temp[0]));

		if (space > 0)
		{
			for (int i = 0; i < strlen(temp); i++)
			{
				if (temp[i] == ' ')
					temp[i] = '#';
			}

		}
		return temp;
	}
		

int countUntilSpace(char* word)
{
	int i = 0, count = 0;
	while (word[i] != ' ') {
		if (word[i] == '\0' || word[i] == NULL)
			return count;
		else
		{
			count++;
			i++;
		}
	}
	return count;
}