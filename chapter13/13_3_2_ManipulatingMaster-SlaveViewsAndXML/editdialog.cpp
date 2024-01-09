#include "editdialog.h"
#include <QMessageBox>
#include <QMetaType>
#include <QVBoxLayout>
int uniqueCarId;
int uniqueFactoryId;
Dialog::Dialog( QSqlRelationalTableModel *cars, QSqlTableModel *factory, QDomDocument details,
                QFile *output, QWidget *parent )
{
    carModel                         = cars;
    factoryModel                     = factory;
    carDetails                       = details;
    outputFile                       = output;
    QGroupBox        *inputWidgetBox = createInputWidgets();
    QDialogButtonBox *buttonBox      = createButtons();

    // 界面布局
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( inputWidgetBox );
    layout->addWidget( buttonBox );
    this->setLayout( layout );
    this->setWindowTitle( tr( "添加产品" ) );
}

void Dialog::revert()
{
    factoryEditor->clear();
    carEditor->clear();
    addressEditor->clear();
    yearEditor->setValue( QDate::currentDate().year() );
    attribEditor->clear();
}

void Dialog::submit()
{
    QString factory = factoryEditor->text();
    QString address = addressEditor->text();
    QString name    = carEditor->text();
    if ( factory.isEmpty() || address.isEmpty() || name.isEmpty() )
    {
        QString message( tr( "请输入工厂名、地址、和产品名称！" ) );
        QMessageBox::information( this, tr( "添加产品" ), message );
    }
    else
    {
        int factoryId = findFactoryId( factory );
        if ( factoryId == -1 )
        {
            factoryId = addNewFactory( factory, address );
        }
        int         carId = addNewCar( name, factoryId );
        QStringList attribs;
        attribs = attribEditor->text().split( ";", Qt::SkipEmptyParts );
        addAttribs( carId, attribs );
        accept();
    }
}

int Dialog::addNewCar( const QString &name, int factoryId )
{
    int        id = generateCarId(); // 生成一个汽车表的主键值
    QSqlRecord record;
    /*在汽车表中插入一条新纪录*/
    QSqlField f1( "carid", QVariant::Int );
    QSqlField f2( "name", QVariant::String );
    QSqlField f3( "factoryid", QVariant::Int );
    QSqlField f4( "year", QVariant::Int );
    f1.setValue( QVariant( id ) );
    f2.setValue( QVariant( name ) );
    f3.setValue( QVariant( factoryId ) );
    f4.setValue( QVariant( yearEditor->value() ) );
    record.append( f1 );
    record.append( f2 );
    record.append( f3 );
    record.append( f4 );
    carModel->insertRecord( -1, record );
    return id;
}

int Dialog::addNewFactory( const QString &factory, const QString &address )
{
    QSqlRecord record;
    int        id = generateFactoryId(); // 生成一个汽车制造商表的主键
    /*在汽车制造商表中插入一条新纪录，厂名和地址由参数传入*/
    QSqlField f1( "id", QVariant::Int );
    QSqlField f2( "manufactory", QVariant::String );
    QSqlField f3( "address", QVariant::String );
    f1.setValue( QVariant( id ) );
    f2.setValue( QVariant( factory ) );
    f3.setValue( QVariant( address ) );
    record.append( f1 );
    record.append( f2 );
    record.append( f3 );
    factoryModel->insertRecord( -1, record );
    return id; // 返回新纪录的主键值
}

void Dialog::addAttribs( int carId, QStringList attribs )
{
    /*创建一个car标签*/
    QDomElement carNode = carDetails.createElement( "car" );
    carNode.setAttribute( "id", carId );

    for ( int i = 0; i < attribs.count(); i++ )
    {
        QString attribNumber = QString::number( i + 1 );
        if ( i < 10 )
            attribNumber.prepend( 0 );
        QDomText    textNode   = carDetails.createTextNode( attribs.at( i ) );
        QDomElement attribNode = carDetails.createElement( "attrib" );
        attribNode.setAttribute( "number", attribNumber );
        attribNode.appendChild( textNode );
        carNode.appendChild( attribNode );
    }

    QDomNodeList archive = carDetails.elementsByTagName( "archive" );
    archive.item( 0 ).appendChild( carNode );

    if ( !outputFile->open( QIODevice::WriteOnly ) )
    {
        return;
    }
    else
    {
        QTextStream stream( outputFile );
        archive.item( 0 ).save( stream, 4 );
        outputFile->close();
    }
}

QDialogButtonBox *Dialog::createButtons()
{
    QPushButton *closeBtn  = new QPushButton( tr( "关闭" ) );
    QPushButton *revertBtn = new QPushButton( tr( "撤销" ) );
    QPushButton *submitBtn = new QPushButton( tr( "提交" ) );
    closeBtn->setDefault( true );

    connect( closeBtn, &QPushButton::clicked, this, &Dialog::close );
    connect( revertBtn, &QPushButton::clicked, this, &Dialog::revert );
    connect( submitBtn, &QPushButton::clicked, this, &Dialog::submit );

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton( submitBtn, QDialogButtonBox::ResetRole );
    buttonBox->addButton( revertBtn, QDialogButtonBox::ResetRole );
    buttonBox->addButton( closeBtn, QDialogButtonBox::ResetRole );

    return buttonBox;
}

QGroupBox *Dialog::createInputWidgets()
{
    QGroupBox *box          = new QGroupBox( tr( "添加产品" ) );
    QLabel    *factoryLabel = new QLabel( tr( "制造商:" ) );
    QLabel    *addressLabel = new QLabel( tr( "厂址:" ) );
    QLabel    *carLabel     = new QLabel( tr( "品牌:" ) );
    QLabel    *yearLabel    = new QLabel( tr( "上市时间:" ) );
    QLabel    *attribLabel  = new QLabel( tr( "产品属性 (由分号;隔开):" ) );
    factoryEditor           = new QLineEdit;
    carEditor               = new QLineEdit;
    addressEditor           = new QLineEdit;
    yearEditor              = new QSpinBox;
    yearEditor->setMinimum( 1900 );
    yearEditor->setMaximum( QDate::currentDate().year() );
    yearEditor->setValue( yearEditor->maximum() );
    yearEditor->setReadOnly( false );
    attribEditor = new QLineEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget( factoryLabel, 0, 0 );
    layout->addWidget( factoryEditor, 0, 1 );
    layout->addWidget( addressLabel, 1, 0 );
    layout->addWidget( addressEditor, 1, 1 );
    layout->addWidget( carLabel, 2, 0 );
    layout->addWidget( carEditor, 2, 1 );
    layout->addWidget( yearLabel, 3, 0 );
    layout->addWidget( yearEditor, 3, 1 );
    layout->addWidget( attribLabel, 4, 0, 1, 2 );
    layout->addWidget( attribEditor, 5, 0, 1, 2 );
    box->setLayout( layout );

    return box;
}

int Dialog::findFactoryId( const QString &factory )
{
    int row = 0;
    while ( row < factoryModel->rowCount() )
    {
        QSqlRecord record = factoryModel->record( row );
        if ( record.value( "manufactory" ) == factory )
            return record.value( "id" ).toInt();
        else
            row++;
    }
    return -1; // 如果未查询到，返回-1
}

int Dialog::generateCarId()
{
    uniqueCarId += 1;
    return uniqueCarId;
}

int Dialog::generateFactoryId()
{
    uniqueFactoryId += 1;
    return uniqueFactoryId;
}
