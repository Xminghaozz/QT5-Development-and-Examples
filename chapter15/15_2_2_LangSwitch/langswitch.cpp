#include "langswitch.h"
#include <QApplication>
#include <QTranslator>
#include <QVBoxLayout>

LangSwitch::LangSwitch( QWidget *parent )
    : QWidget( parent )
{
    createScreen();
}

LangSwitch::~LangSwitch() {}

void LangSwitch::changeLang( int index )
{
    QString langCode = combo->itemData( index ).toString();
    changeTr( langCode ); // 读取相应的".qm"文件
    refreshLabel();       // 刷新标签上的文字
}

void LangSwitch::createScreen()
{
    combo = new QComboBox;
    combo->addItem( "English", "en" );
    combo->addItem( "Chinese", "zh" );
    combo->addItem( "Latin", "la" );

    label = new QLabel;
    refreshLabel(); // 设置标签的内容
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( combo, 1 );
    layout->addWidget( label, 5 );
    this->setLayout( layout );

    connect( combo, &QComboBox::currentIndexChanged, this, &LangSwitch::changeLang );
}

void LangSwitch::changeTr( const QString &langCode )
{
    static QTranslator *translator;
    if ( translator != nullptr )
    {
        qApp->removeTranslator( translator );
        delete translator;
        translator = nullptr;
    }

    translator         = new QTranslator;
    QString qmFilename = "lang_" + langCode;
    if ( translator->load(
             QString( "D:/QTWorkSpace/QT5 Development and Examples/chapter15/15_2_2_LangSwitch/" ) +
             qmFilename ) )
    {
        qApp->installTranslator( translator );
    }
}

void LangSwitch::refreshLabel() { label->setText( tr( "TXT_HELLO_WORLD", "Hello World" ) ); }
