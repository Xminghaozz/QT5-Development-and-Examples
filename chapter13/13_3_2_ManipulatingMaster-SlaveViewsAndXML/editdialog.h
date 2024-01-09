#ifndef DIALOG_H
#define DIALOG_H

#include "ui_connectdlg.h"
#include <QDialog>
#include <QtGui>
#include <QtSql>
#include <QtWidgets/QDialogButtonBox>
#include <QtXml>
class Dialog : public QDialog
{
  public:
    Dialog( QSqlRelationalTableModel *cars, QSqlTableModel *factory, QDomDocument details,
            QFile *output, QWidget *parent = nullptr );

  private slots:
    void revert();
    void submit();

  private:
    int               addNewCar( const QString &name, int factoryId );
    int               addNewFactory( const QString &factory, const QString &address );
    void              addAttribs( int carId, QStringList attribs );
    QDialogButtonBox *createButtons();
    QGroupBox        *createInputWidgets();
    int               findFactoryId( const QString &factory );
    int               generateCarId();
    int               generateFactoryId();

    QSqlRelationalTableModel *carModel;
    QSqlTableModel           *factoryModel;
    QDomDocument              carDetails;
    QFile                    *outputFile;
    QLineEdit                *factoryEditor;
    QLineEdit                *addressEditor;
    QLineEdit                *carEditor;
    QSpinBox                 *yearEditor;
    QLineEdit                *attribEditor;
};

#endif // DIALOG_H
