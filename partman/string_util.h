/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef INSTALLER_BASE_STRING_UTIL_H
#define INSTALLER_BASE_STRING_UTIL_H

#include <QString>

namespace PartMan {

// Parse a pattern |pattern| from string |str| and returns matched substring
// or an empty string.
// Note that a match group shall be specified in |pattern|.
QString RegexpLabel(const QString& pattern, const QString& str);

}  // namespace installer

#endif  // INSTALLER_BASE_STRING_UTIL_H
