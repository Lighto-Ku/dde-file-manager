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

#ifndef COMPUTERPROPERTYDIALOG_H
#define COMPUTERPROPERTYDIALOG_H

#include <QWidget>
#include <QMap>
#include <QDialog>

class ComputerPropertyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ComputerPropertyDialog(QWidget *parent = 0);
    void initUI();
    QHash<QString, QString> getMessage(const QStringList& data);

signals:
    void closed();

public slots:
protected:

private:
    QString getComputerName();
    QString getVersion();
    QString getArch();
    QString getProcessor();
    QString getSWProcessorHZ();
    QString getMemory();
    QString getDisk();
};

#endif // COMPUTERPROPERTYDIALOG_H
