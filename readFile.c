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

long readFile(char **buff, const char *name)
{
	FILE *fp = fopen(name, "r");
	if(fp == NULL)
		return -1;
	if(fseek(fp, 0, SEEK_END) != 0)
		goto closeFile;
	long fileSize = ftell(fp);
	rewind(fp);
	*buff = malloc(fileSize + 1); //+1 for NUL
	if(*buff == NULL)
		goto closeFile;
	if(fread(*buff, 1, (size_t)fileSize, fp) < (size_t)fileSize)
		goto free;
	if(fclose(fp) != 0)
		goto free;
	(*buff)[fileSize] = '\0';
	return fileSize;
free:
	free(*buff);
closeFile:
	fclose(fp);
	return -1;
}
