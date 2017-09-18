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

#ifndef GVFSMOUNTMANAGER_H
#define GVFSMOUNTMANAGER_H

#include <QObject>
#include <QStringList>

class QDrive;
class QVolume;
class QMount;
class QDiskInfo;
class MountSecretDiskAskPasswordDialog;

#undef signals
extern "C" {
    #include <gio/gio.h>
}
#define signals public

class GvfsMountManager : public QObject
{
    Q_OBJECT
public:
    explicit GvfsMountManager(QObject *parent = 0);
    void initConnect();

    static GvfsMountManager* instance();
    static MountSecretDiskAskPasswordDialog* mountSecretDiskAskPasswordDialog;

    static QMap<QString, QDrive> Drives;
    static QMap<QString, QVolume> Volumes;
    static QMap<QString, QMount> Mounts;
    static QMap<QString, QDiskInfo> DiskInfos;

    static QStringList Drives_Keys;
    static QStringList Volumes_Drive_Keys;
    static QStringList Volumes_No_Drive_Keys;

    static QStringList NoVolumes_Mounts_Keys;
    static QStringList Lsblk_Keys;

    static QStringList getIconNames(GThemedIcon *icon);
    static QDrive gDriveToqDrive(GDrive *drive);
    static QVolume gVolumeToqVolume(GVolume *volume);
    static QMount gMountToqMount(GMount *mount);

    static QDiskInfo qVolumeToqDiskInfo(const QVolume&  volume);
    static QDiskInfo qMountToqDiskinfo(const QMount& mount);

    static QVolume getVolumeByMountedRootUri(const QString& mounted_root_uri);
    static QVolume getVolumeByUnixDevice(const QString& unix_device);

    static void monitor_mount_added_root(GVolumeMonitor *volume_monitor, GMount *mount);
    static void monitor_mount_removed_root(GVolumeMonitor *volume_monitor, GMount *mount);

    static void monitor_mount_added(GVolumeMonitor *volume_monitor, GMount *mount);
    static void monitor_mount_removed (GVolumeMonitor *volume_monitor, GMount *mount);
    static void monitor_mount_changed (GVolumeMonitor *volume_monitor, GMount *mount);

    static void monitor_volume_added (GVolumeMonitor *volume_monitor, GVolume *volume);
    static void monitor_volume_removed (GVolumeMonitor *volume_monitor, GVolume *volume);
    static void monitor_volume_changed (GVolumeMonitor *volume_monitor, GVolume *volume);


    static GMountOperation* new_mount_op();
    static void ask_password_cb(GMountOperation *op,
                                const char      *message,
                                const char      *default_user,
                                const char      *default_domain,
                                GAskPasswordFlags flags);

    static void mount(const QString& path);
    static void mount(const QDiskInfo& diskInfo);
    static void mount_device(const QString& unix_device);
    static void mount_mounted(const QString& mounted_root_uri);
    static void unmount(const QDiskInfo& diskInfo);
    static void unmount(const QString&  id);
    static void unmount_mounted(const QString& mounted_root_uri);
    static void eject(const QString& path);
    static void eject(const QDiskInfo& diskInfo);
    static void eject_device(const QString&  unix_device);
    static void eject_mounted(const QString&  mounted_root_uri);
    static void stop_device(const QString& drive_unix_device);

    static void mount_with_mounted_uri_done(GObject *object, GAsyncResult *res, gpointer user_data);
    static void mount_with_device_file_cb (GObject *object, GAsyncResult *res, gpointer user_data);
    static void unmount_done_cb(GObject *object, GAsyncResult *res, gpointer user_data);
    static void eject_with_device_file_cb(GObject *object, GAsyncResult *res, gpointer user_data);
    static void eject_with_mounted_file_cb(GObject *object, GAsyncResult *res, gpointer user_data);
    static void stop_with_device_file_cb(GObject *object, GAsyncResult *res, gpointer user_data);

    static void printVolumeMounts();

    static QDiskInfo getDiskInfo(const QString& path);
    static bool isDVD(const QVolume& volume);
    static bool isIgnoreUnusedMounts(const QMount& mount);

    static QString getDriveUnixDevice(const QString& unix_device);

    bool getAutoMountSwitch() const;
    void setAutoMountSwitch(bool autoMountSwitch);

    void autoMountAllDisks();

signals:
    void loadDiskInfoFinished();
    void mount_added(const QDiskInfo& diskInfo);
    void mount_removed(const QDiskInfo& diskInfo);
    void volume_added(const QDiskInfo& diskInfo);
    void volume_removed(const QDiskInfo& diskInfo);
    void volume_changed(const QDiskInfo& diskInfo); // only for cd/dvd

public slots:
    void startMonitor();
    void listDrives();
    void getDrives(GList *drives);
    void listVolumes();
    void getVolumes(GList *volumes);
    void listMounts();
    void updateDiskInfos();
    void getMounts(GList *mounts);

    void listMountsBylsblk();

private:
    GVolumeMonitor* m_gVolumeMonitor = NULL;
    bool m_autoMountSwitch = false;
};

#endif // GVFSMOUNTMANAGER_H
