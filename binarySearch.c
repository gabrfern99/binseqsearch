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
#include "binarySearch.h"

void *binarySearch(const void *key, const void *array, size_t elementCount,
                   size_t elementSize,
                   int (*compFunc)(const void *, const void *))
{
	char *base = (char *)array;
	size_t first = 0;
	size_t last = elementCount - 1;
	while(first <= last)
	{
		size_t mid = first + (last - first)/2; //(first + last)/2
		int result = compFunc(key, base + mid*elementSize);
		if(first == last && result != 0)
			return NULL;
		if(result < 0) //mid > key
			last = mid - 1;
		else if(result > 0) //mid < key
			first = mid + 1;
		else //key == mid
			return base + mid*elementSize;
	}
	return NULL;
}
/*
f    0       0       0       0       0       0       0
     1       1       1       1       1       1       1
     2       2       2       2       2       2       2
     3       3       3       3       3       3       3
     4       4       4       4       4       4       4
     5       5       5       5       5       5       5
     6       6       6       6       6       6       6
     7       7       7       7       7       7       7
     8       8       8       8       8       8       8
     9       9       9       9       9       9       9
m   10  m   10      10      10      10      10      10
    11  f   11  f   11  f   11  f   11  f   11  f   11
k   12  k   12  k   12  k   12  k   12  kl  12  klm 12
    13      13      13      13  m   13  m   13      13
    14      14      14      14      14      14      14
    15      15      15  l   15  l   15      15      15
    16      16  m   16  m   16      16      16      16
    17      17      17      17      17      17      17
    18      18      18      18      18      18      18
    19      19      19      19      19      19      19
    20      20      20      20      20      20      20
l   21  l   21  l   21      21      21      21      21
*/
