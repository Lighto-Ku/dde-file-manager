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

#ifndef COPYJOBCONTROLLER_H
#define COPYJOBCONTROLLER_H

#include <QtCore>
#include <QtDBus>

class CopyJobInterface;
class CopyjobWorker;

class CopyJobController : public QObject
{
    Q_OBJECT
public:
    explicit CopyJobController(QObject *parent = 0);
    ~CopyJobController();

    void initConnect();
};

#endif // COPYJOBCONTROLLER_H
