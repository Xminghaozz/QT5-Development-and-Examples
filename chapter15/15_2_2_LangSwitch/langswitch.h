#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QComboBox>
#include <QLabel>
#include <QWidget>

class LangSwitch : public QWidget
{
    Q_OBJECT

  public:
    LangSwitch( QWidget *parent = nullptr );
    ~LangSwitch();

  private slots:
    void changeLang( int index );

  private:
    void       createScreen();
    void       changeTr( const QString &langCode );
    void       refreshLabel();
    QComboBox *combo; // 在界面中可以看见的下拉标签
    QLabel    *label; // 在界面中可以看见的标签
};
#endif // LANGSWITCH_H
