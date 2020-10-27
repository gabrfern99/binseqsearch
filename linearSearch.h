/**
 * @file
 * @brief Linear search of an array.
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

#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

/**
 * @brief Linear search of an array
 *
 * @param key Key to search for.
 * @param array Array containing elements to search on.
 * @param elementCount Number of elements in \c array.
 * @param elementSize Size of each element in \c array.
 * @param compFunc Comparison routine that compares two elements. It
 * is expected to have two arguments which point to the \c key object
 * and to an \c array member, in that order, and returns zero if the
 * \c key object matches the \c array member, and nonzero otherwise.
 * @return a pointer to a matching member of the \c array.
 * @return NULL if no match is found.
 * @warning if you pass in const, consider the return to also be const.
 */
void *linearSearch(const void *key, const void *array, size_t elementCount,
                   size_t elementSize,
                   int (*compFunc)(const void *, const void *));

#endif /* LINEARSEARCH_H */
