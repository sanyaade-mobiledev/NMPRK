/***************************************************************************
 * Copyright 2012 Intel Corporation                                        *
 *Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.        *
 * You may obtain a copy of the License at                                 *
 * http://www.apache.org/licenses/LICENSE-2.0                              *
 * Unless required by applicable law or agreed to in writing, software     *
 * distributed under the License is distributed on an "AS IS" BASIS,       *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
 * See the License for the specific language governing permissions and     *
 * limitations under the License.                                          *
 ***************************************************************************/
/**************************************************************************
 * Author: Stewart Dale <IASI NM TEAM>                                    *
 * Updates:							                                      *
 * 4/30: prep for initial external release                                *
 **************************************************************************/


#include "OsSpecificFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

namespace TransportPlugin
{
int
OsSpecificFunctions::stricmp(const char* str1, const char* str2)
{
    return _stricmp(str1, str2);
}

int
OsSpecificFunctions::strcpys(char* dst, unsigned int dstSize, const char* src)
{
    return strcpy_s(dst, dstSize, src);
}

int
OsSpecificFunctions::sprintfs(char* dst, unsigned int dstSize, const char* format, ...)
{
    va_list list;

    va_start(list, format);
    int result = vsprintf_s(dst, dstSize, format, list);
    va_end(list);

    return result;
}
}
