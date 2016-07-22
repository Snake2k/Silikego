/* StringSource.cc: Class to input data from a string
 * Copyright 2014, 2015, 2016 Vincent Damewood
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

#include "StringSource.h"

StringSource::StringSource(const std::string &NewSource)
	: Source(NewSource), Iterator(Source.begin())
{
}

StringSource::~StringSource()
{
}

bool StringSource::Advance()
{
	if (Iterator != Source.end())
	{
		++Iterator;
		return true;
	}
	else
	{
		return false;
	}
}

char StringSource::GetCurrent()
{
	if (Iterator != Source.end())
	{
		return *Iterator;
	}
	else
	{
		return '\0';
	}
}
