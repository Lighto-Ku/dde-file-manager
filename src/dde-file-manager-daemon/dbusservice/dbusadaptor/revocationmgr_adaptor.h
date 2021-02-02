/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i ../revocation/revocationmanager.h -c RevocationMgrAdaptor -l RevocationManager -a ../dbusservice/dbusadaptor/revocationmgr_adaptor revocation.xml
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef REVOCATIONMGR_ADAPTOR_H
#define REVOCATIONMGR_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "../revocation/revocationmanager.h"
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface com.deepin.filemanager.daemon.RevocationManager
 */
class RevocationMgrAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.filemanager.daemon.RevocationManager")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.deepin.filemanager.daemon.RevocationManager\">\n"
"    <signal name=\"fmgrRevocationAction\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"user\"/>\n"
"    </signal>\n"
"    <signal name=\"deskRevocationAction\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"user\"/>\n"
"    </signal>\n"
"    <method name=\"pushEvent\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"event\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"user\"/>\n"
"    </method>\n"
"    <method name=\"popEvent\">\n"
"      <arg direction=\"out\" type=\"i\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    RevocationMgrAdaptor(RevocationManager *parent);
    virtual ~RevocationMgrAdaptor();

    inline RevocationManager *parent() const
    { return static_cast<RevocationManager *>(QObject::parent()); }

public: // PROPERTIES
public Q_SLOTS: // METHODS
    int popEvent();
    void pushEvent(int event, const QString &user);
Q_SIGNALS: // SIGNALS
    void deskRevocationAction(const QString &user);
    void fmgrRevocationAction(const QString &user);
};

#endif
