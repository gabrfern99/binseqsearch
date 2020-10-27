/**
 * @file
 * @brief Generic dynamic list.
 *
 * This header provides a type agnostic self re-sizable list.
 *
 * @copyright Copyright 2019 Rodrigo Martins\n
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

#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/**
 * @brief The List object, an opaque type */
typedef struct List List;

/**
 * @brief Create a List
 *
 * @param [out] list The List to be initialized.
 * @param [in] typeSize The size of the type the List will store.
 * @return 0 on success.
 * @return -1 on failure, sets errno.
 * @post Caller should call listFree() when done using the List.
 */
int listInit(List **list, size_t typeSize);

/**
 * @brief Insert an object into a List
 *
 * The object is inserted by copying it into the List.
 *
 * @param [in,out] list The List to be inserted on.
 * @param [in] object The object to insert.
 * @return 0 on success.
 * @return -1 on failure, sets errno.
 */
int listInsert(List *list, const void *object);

/**
 * @brief Get count of objects in the List
 *
 * @param list The List.
 * @return How many objects are contained in list.
 */
size_t listGetCount(const List *list);

/**
 * @brief Get object at index
 *
 * @param list The List.
 * @param index The index position of the element in the List.
 * @return The object at \c index.
 * @todo Implement
 */
void *listGetIndex(const List *list, size_t index);

/**
 * @brief Resize List freeing unused memory
 *
 * When done inserting objects into the List the application may call
 * listTrim() to free memory allocated but unused by the List.
 *
 * @param [in,out] list List to be trimmed.
 * @return How many slots were freed.
 * @todo Implement
 */
size_t listTrim(List *list);

/**
 * @brief Get buffer with objects stored in List
 *
 * @param [in] list The List containing objects.
 * @return The object buffer.
 * @note The buffer is only valid until the next call of listFree(),
 * listInsert() or listTrim().
 */
void *listGetBuffer(const List *list);

/**
 * @brief Free List
 * @param list List to be freed. */
void listFree(List *list);

#endif /* LIST_H */
