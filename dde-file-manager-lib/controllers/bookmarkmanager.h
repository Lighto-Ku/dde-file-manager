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

#ifndef BOOKMARKMANAGER_H
#define BOOKMARKMANAGER_H

#include "basemanager.h"
#include "dabstractfilecontroller.h"

#include "models/bookmark.h"

#include <QDir>

class DAbstractFileInfo;

class BookMarkManager : public DAbstractFileController, public BaseManager
{
    Q_OBJECT
public:
    explicit BookMarkManager(QObject *parent = 0);
    ~BookMarkManager();

    void load();
    void save();
    QList<BookMarkPointer> getBookmarks();
    static QString cachePath();
private:
    void loadJson(const QJsonObject &json);
    void writeJson(QJsonObject &json);
    QList<BookMarkPointer> m_bookmarks;

public slots:
    BookMarkPointer writeIntoBookmark(int index, const QString &name, const DUrl &url);
    void removeBookmark(BookMarkPointer bookmark);
    void renameBookmark(BookMarkPointer bookmark, const QString &newname);
    void moveBookmark(int from, int to);
    // AbstractFileController interface

    void reLoad();

public:
    const QList<DAbstractFileInfoPointer> getChildren(const QSharedPointer<DFMGetChildrensEvent> &event) const Q_DECL_OVERRIDE;
    const DAbstractFileInfoPointer createFileInfo(const QSharedPointer<DFMCreateFileInfoEvnet> &event) const Q_DECL_OVERRIDE;
};

#endif // BOOKMARKMANAGER_H
