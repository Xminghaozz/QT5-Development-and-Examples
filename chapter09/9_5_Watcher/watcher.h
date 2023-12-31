#ifndef WATCHER_H
#define WATCHER_H

#include <QFileSystemWatcher>
#include <QLabel>
#include <QWidget>

class Watcher : public QWidget
{
    Q_OBJECT

  public:
    Watcher( QWidget *parent = nullptr );
    ~Watcher();

  public slots:
    void directoryChanged( QString path );

  private:
    QLabel            *pathLabel;
    QFileSystemWatcher fsWatcher;
};
#endif // WATCHER_H
