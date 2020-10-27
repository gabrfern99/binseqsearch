/**
 * This file is part of Planets
 * Copyright 2019 Rodrigo Martins
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

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "list.h"

#define INITIAL_LIST_SIZE 16 ///< Number of slots in a new list

/**
 * @internal
 * @brief The struct that makes the List opaque type */
struct List
{
	size_t usedSlots; ///< Occupied slots
	size_t freeSlots; ///< Unoccupied slots
	size_t typeSize; ///< Size of a single object
	unsigned char *objects; ///< Object buffer
};

int listInit(List **list, size_t typeSize)
{
	*list = malloc(sizeof(List));
	if(*list == NULL)
		return -1;
	(*list)->usedSlots = 0;
	(*list)->freeSlots = INITIAL_LIST_SIZE;
	(*list)->typeSize = typeSize;
	(*list)->objects = malloc((*list)->freeSlots*(*list)->typeSize);
	if((*list)->objects == NULL)
	{
		free(*list);
		return -1;
	}
	return 0;
}

int listInsert(List *list, const void *object)
{
	if(list->freeSlots == 0)
	{
		unsigned char *newBuff =
			realloc(list->objects, 2*list->usedSlots*list->typeSize);
		if(newBuff == NULL)
			return -1;
		list->freeSlots = list->usedSlots;
		list->objects = newBuff;
	}
	void *firstFreeSlot = list->objects + list->usedSlots*list->typeSize;
	memcpy(firstFreeSlot, object, list->typeSize);
	list->usedSlots++;
	list->freeSlots--;
	return 0;
}

inline size_t listGetCount(const List *list)
{
	return list->usedSlots;
}

inline void *listGetBuffer(const List *list)
{
	return list->objects;
}

void listFree(List *list)
{
	free(list->objects);
	free(list);
}
