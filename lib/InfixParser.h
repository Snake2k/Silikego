/* InfixParser.h: Recursive-descent infix parser
 * Copyright 2014, 2015, 2016 Vincent Damewood
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined SILIKEGO_INFIX_PARSER_H
#define SILIKEGO_INFIX_PARSER_H

#include <memory>

#include "W32Dll.h"
#include "DataSource.h"
#include "SyntaxTree.h"

namespace Silikego
{
	SILIKEGO_API std::unique_ptr<SyntaxTreeNode> ParseInfix(std::unique_ptr<DataSource> Input);
};

#endif // SILIKEGO_INFIX_PARSER_H
