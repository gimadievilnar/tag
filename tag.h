#ifndef TAG_H
#define TAG_H

#include "ui_tag.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cstdlib>
#include <QTime>
#include <QMessageBox>

namespace Ui {
class tag;
}

class tag : public QWidget
{
    Q_OBJECT
    Ui::tag *ui;
    QGridLayout *grid;
    QLabel *label;
    QLabel *textLabel;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay;
    QPixmap *maps[16];
    QPoint positionEmtyCell;
    QPushButton *buttons[16];
public:
    explicit tag(QWidget *parent = nullptr);
    void CreateButton(int x, int y, int index);
    bool CheckCorrectLocation();
    ~tag();
public slots :
    void ButtonsClicked();
};

#endif // TAG_H
