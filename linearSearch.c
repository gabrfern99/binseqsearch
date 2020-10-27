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
#include "linearSearch.h"

void *linearSearch(const void *key, const void *array, size_t elementCount,
                   size_t elementSize,
                   int (*compFunc)(const void *, const void *))
{
	char *base = (char *)array;
	size_t cursor = 0;
	while(cursor < elementCount)
		if(compFunc(key, base + cursor*elementSize))
			cursor++;
		else
			return base + cursor*elementSize;
	return NULL;
}
