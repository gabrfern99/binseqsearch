#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearch.h"
#include "linearSearch.h"
#include "person.h"
#include "list.h"
#include "csv.h"

#define PATH_MAX_LEN 256
#define NAME_MAX_LEN 256
size_t comparisionCount = 0;

static int comparePerson(const void *p1, const void *p2)
{
	const Person *person1 = p1;
	const Person *person2 = p2;
	comparisionCount++;
	return strcmp(person1->firstName, person2->firstName);
}

int main(void)
{
	List *people = NULL;
	char path[PATH_MAX_LEN + 1]; //+1 for NUL
	while(1)
	{
		printf("Please enter a file path: ");
		if(scanf("%s", path) != 1) //BUG: beware the buffer overflow
			continue;
		if(parseCsv(&people, path) < 0)
		{
			perror(path);
			continue;
		}
		break;
	}
	int algoChoice = 0;
	while(algoChoice != 1  && algoChoice != 2)
	{
		printf("1 - linear\n2 - binary\n");
		printf("Please enter a search algorithm: ");
		if(scanf("%d", &algoChoice) != 1) //BUG: beware the integer overflow?
			continue;
	}
	char nameToSearch[NAME_MAX_LEN + 1]; //+1 for NUL
	while(1)
	{
		printf("Please enter a name to search for: ");
		if(scanf("%s", nameToSearch) != 1) //BUG: beware the buffer overflow
			continue;
		break;
	}
	Person personKey;
	if(personInit(&personKey, nameToSearch, "", "", MALE, "") < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	Person *peopleBuff = listGetBuffer(people);
	qsort(peopleBuff, listGetCount(people), sizeof(Person), comparePerson);
	comparisionCount = 0; //reset comparisions made by qsort
	Person *person;
	if(algoChoice == 1)
		person = linearSearch(&personKey, peopleBuff, listGetCount(people),
		                      sizeof(Person), comparePerson);
	else
		person = binarySearch(&personKey, peopleBuff, listGetCount(people),
		                      sizeof(Person), comparePerson);
	if(person == NULL)
		printf("Person not found\n");
	else
		printf("%s %s (%s) %s %s\n",
		       person->firstName, person->lastName,
		       person->email,
		       person->gender == MALE ? "Male" : "Female",
		       person->ip);

	for(size_t i=0; i<listGetCount(people); i++)
		personFree(&peopleBuff[i]);
	listFree(people);
	personFree(&personKey);
	printf("Number of comparisions: %zu\n", comparisionCount);
	exit(EXIT_SUCCESS);
}
