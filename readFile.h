/**
 * @file
 * @brief Reads the content of a file on disk.
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

#ifndef READ_FILE_H
#define READ_FILE_H

/**
 * @brief Read a file from disk and store its content in a buffer
 *
 * @param [out] buff Buffer that will contain the file, NUL terminated.
 * @param [in] name File name file to be read.
 * @return The number of bytes read on success, not including NUL terminator.
 * @return -1 on failure and sets errno.
 * @post Memory for the new string is obtained with malloc(), and can
 * be freed with free().
 */
long readFile(char **buff, const char *name);

#endif /* READ_FILE_H */
