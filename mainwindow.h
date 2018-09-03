#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include "tag.h"
#include <QMenuBar>
#include <QMenu>

class mainWindows : public QWidget
{
    Q_OBJECT
    QVBoxLayout *vlay;
    QLabel *label;
    QPixmap *mainMap;
public:
    explicit mainWindows(QWidget *parent = nullptr);
    void CreateMenu();
public slots:
    void NewGame();
    void Quit();
    void AboutGame();
    void GameRules();
};

#endif // MAINWINDOWS_H
