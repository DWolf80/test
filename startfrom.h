#ifndef STARTFROM_H
#define STARTFROM_H
#include <QWidget> //开始界面

namespace Ui{
class Startfrom;
}

class Startfrom:public QWidget
{
//Q_OBJECT
public:
    explicit Startfrom(QWidget *parent=nullptr);
    ~Startfrom();
private:
    Ui::Startfrom *ui;
};

#endif // STARTFROM_H
