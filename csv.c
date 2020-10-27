/**
 * Copyright 2020 Rodrigo Martins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "person.h"
#include "list.h"
#include "readFile.h"

enum personFields
{
	FIELD_FIRST_NAME,
	FIELD_LAST_NAME,
	FIELD_EMAIL,
	FIELD_GENDER,
	FIELD_IP_ADDRESS,
	FIELD_COUNT,
};

//parses the string in one pass
int parseCsv(List **output, const char *fileName)
{
	char *buff;
	if(readFile(&buff, fileName) < 0)
		goto error;
	if(listInit(output, sizeof(Person)) < 0)
		goto freeBuff;
	int currentField = FIELD_FIRST_NAME;
	char *field[FIELD_COUNT];
	char *cursor = buff;
	while(*cursor != '\n') //skip first line, the header
	{
		//malformed entry: got end of string before end of line
		if(*cursor == '\0')
		{
			errno = EPROTO;
			goto freeList;
		}
		cursor++;
	}
	field[currentField] = cursor + 1;
	cursor++;
	//here the cursor is at the start of the first entry
	while(*cursor != '\0')
	{
		switch(*cursor)
		{
		case '\n':
			//malformed entry: got end of line before reading all fields
			if(currentField != FIELD_COUNT - 1)
			{
				errno = EPROTO;
				goto freeList;
			}
			*cursor = '\0'; //break string
			Gender gender;
			if(strcmp(field[FIELD_GENDER], "Female") == 0)
				gender = FEMALE;
			else if(strcmp(field[FIELD_GENDER], "Male") == 0)
				gender = MALE;
			else //malformed entry: invalid gender
			{
				errno = EPROTO;
				goto freeList;
			}
			Person person;
			if(personInit(&person, field[FIELD_FIRST_NAME],
			              field[FIELD_LAST_NAME], field[FIELD_EMAIL],
			              gender, field[FIELD_IP_ADDRESS]) < 0)
				goto freeList;
			if(listInsert(*output, &person) < 0)
				goto freeList;
			/* FALLTHROUGH */
		case ',':
			currentField++;
			if(currentField == FIELD_COUNT)
				currentField = FIELD_FIRST_NAME;
			field[currentField] = cursor + 1;
			*cursor = '\0'; //break string
			break;
		default:
			break;
		}
		cursor++;
	}
	free(buff);
	return 0;
freeList:
	{
		Person *peopleBuff = listGetBuffer(*output);
		for(size_t i=0; i<listGetCount(*output); i++)
			personFree(&peopleBuff[i]);
		listFree(*output);
	}
freeBuff:
	free(buff);
error:
	return -1;
}
