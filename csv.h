/**
 * @file
 * @brief A non-generic Person CSV parser.
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

#ifndef CSV_H
#define CSV_H

/**
 * @brief Get a Person List fom a CSV file
 *
 * This is not a generic parser, it expects a Person.
 *
 * @param [out] output Output List.
 * @param [in] fileName Name of file to be read.
 * @return 0 on success.
 * @return -1 on failure, sets errno.
 * @post On success, caller should call listFree() when done using the List.
 * @post On success, caller should free() each Person in List.
 */
int parseCsv(List **output, const char *fileName);

#endif /* CSV_H */
