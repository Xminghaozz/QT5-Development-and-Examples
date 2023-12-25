#ifndef MODELEX_H
#define MODELEX_H

#include <QAbstractTableModel>
#include <QMap>
#include <QStringList>
#include <QVector>
#include <QWidget>
class ModelEx : public QAbstractTableModel
{
    Q_OBJECT

  public:
    ModelEx( QObject *parent = nullptr );
    ~ModelEx();

    // 虚函数声明
    virtual int rowCount( const QModelIndex &parent = QModelIndex() ) const;
    virtual int columnCount( const QModelIndex &parent = QModelIndex() ) const;
    QVariant    data( const QModelIndex &index, int role ) const;
    QVariant    headerData( int section, Qt::Orientation orientation, int role ) const;

  private:
    QVector<short>       army;
    QVector<short>       weaponType;
    QMap<short, QString> armyMap; // 使用QMap数据结构保存“数值-文字”的映射
    QMap<short, QString> weaponTypeMap;
    QStringList          weapon;
    QStringList          header;
    void                 populateModel(); // 完成表格数据的初始化填充
};
#endif // MODELEX_H
