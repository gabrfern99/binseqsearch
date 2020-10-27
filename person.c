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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int personInit(Person *person, const char *firstName, const char *lastName,
               const char *email, Gender gender, const char *ip)
{
	size_t firstNameLen = strlen(firstName);
	size_t lastNameLen = strlen(lastName);
	size_t emailLen = strlen(email);
	size_t ipLen = strlen(ip);
	size_t strBuffSize =
		+ firstNameLen + 1 //+1 for NUL
		+ lastNameLen + 1
		+ emailLen + 1
		+ ipLen + 1;
	void *strBuff = malloc(strBuffSize);
	if(strBuff == NULL)
		return -1;
	person->gender = gender;
	person->firstName = strBuff;
	person->lastName = person->firstName + firstNameLen + 1; //+1 for NULL
	person->email = person->lastName + lastNameLen + 1;
	person->ip = person->email + emailLen + 1;
	strcpy(person->firstName, firstName);
	strcpy(person->lastName, lastName);
	strcpy(person->email, email);
	strcpy(person->ip, ip);
	return 0;
}

void personFree(Person *person)
{
	free(person->firstName);
}
