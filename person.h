/**
 * @file
 * @brief A person.
 *
 * @copyright Copyright 2020 Rodrigo Martins\n
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.\n
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.\n
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PERSON_H
#define PERSON_H

typedef enum
{
	MALE,
	FEMALE,
} Gender;

typedef struct
{
	char *firstName;
	char *lastName;
	char *email;
	Gender gender;
	char *ip;
} Person;

/**
 * @brief Initialize Person
 *
 * @param person Person to initialize.
 * @param firstName Value to initialize.
 * @param lastName Value to initialize.
 * @param email Value to initialize.
 * @param gender Value to initialize.
 * @param ip Value to initialize.
 * @return 0 on success.
 * @return -1 on failure, sets errno.
 * @post Application should call personFree() when done using the Person.
 */
int personInit(Person *person, const char *firstName, const char *lastName,
               const char *email, Gender gender, const char *ip);

/**
 * @brief Free Person
 * @param person Person to free. */
void personFree(Person *person);

#endif /* PERSON_H */
