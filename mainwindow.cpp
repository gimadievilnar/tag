#include "mainwindow.h"

mainWindows::mainWindows(QWidget *parent) : QWidget(parent)
{
    vlay = new QVBoxLayout;
    label = new QLabel;
    mainMap = new QPixmap(":/tag.bmp");
    label->setPixmap(*mainMap);
    label->setFixedSize(800,600);
    vlay->addWidget(label);
    vlay->setContentsMargins(0,0,0,0);
    this->setLayout(vlay);
    CreateMenu();


}

void mainWindows::CreateMenu()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu*   file  = new QMenu("&Файл");
    file->addAction("&Новая игра", this, SLOT(NewGame()),Qt::CTRL + Qt::Key_N);
    file->addSeparator();
    file->addAction("&Exit", this, SLOT(Quit()),Qt::ALT + Qt::Key_F4);
    QMenu*   help  = new QMenu("&Помощь");
    help->addAction("&Правила игры", this, SLOT(GameRules()),Qt::CTRL + Qt::Key_P);
    help->addAction("&Об игре", this, SLOT(AboutGame()),Qt::CTRL + Qt::Key_O);
    menuBar->addMenu(file);
    menuBar->addMenu(help);
    menuBar->setFixedSize(110,20);
    menuBar->show();
}

void mainWindows::NewGame()
{
    tag *wdt = new tag();
    wdt->setWindowTitle("Пятнашки");
    wdt->show();
    this->close();
}

void mainWindows::Quit()
{
    this->close();
}

void mainWindows::AboutGame()
{
    QMessageBox::information(this,"Об игре", "Игра - Пятнашки. Версия 1.0    "
                                  "\n    Автор: Гимадиев Ильнар \n                  2018 г.");
}

void mainWindows::GameRules()
{
    QMessageBox::information(this, "Правила игры",
                             "Игра Пятнашки  -  правила  простые:  разместить фишки в правильном порядке, собрать картинку..."
                             " Задача игрока не только собрать головоломку, но и потратить на перемещение фишек наименьшее "
                             "количество  ходов.  Двигать разрешается только пустую фишку. Время, затраченное на "
                             "прохождение игры, не учитывается.");
}
