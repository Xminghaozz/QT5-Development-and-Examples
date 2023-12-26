#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QDialog>
#include <QDir>
#include <QFileInfoList>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>

class FileView : public QDialog
{
    Q_OBJECT

  public:
    FileView( QWidget *parent = nullptr );
    ~FileView();
    void showFileInfoList( QFileInfoList list );

  public slots:
    void slotShow( QDir dir );
    void slotDirShow( QListWidgetItem *item );

  private:
    QLineEdit   *fileLineEdit;
    QListWidget *fileListWidget;
    QVBoxLayout *mainLayout;
};
#endif // FILEVIEW_H
