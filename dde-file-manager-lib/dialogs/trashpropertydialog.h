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

#ifndef TRASHPROPERTYDIALOG_H
#define TRASHPROPERTYDIALOG_H

#include "basedialog.h"
#include "durl.h"
#include <QLabel>
#include "propertydialog.h"

class TrashPropertyDialog : public BaseDialog
{
    Q_OBJECT
public:
    explicit TrashPropertyDialog(const DUrl& url, QWidget *parent = 0);
    ~TrashPropertyDialog();

    void initUI();
    void startComputerFolderSize(const DUrl& url);

signals:
    void requestStartComputerFolderSize();

public slots:
    void updateFolderSize(qint64 size);

private:
    DUrl m_url;
    QLabel* m_iconLabel;
    QLabel* m_nameLable;
    QLabel* m_countLabel;
    QLabel* m_sizeLabel;
};

#endif // TRASHPROPERTYDIALOG_H
