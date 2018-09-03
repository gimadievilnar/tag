#include "tag.h"
#include "mainwindow.h"

tag::tag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tag)
{
    ui->setupUi(this);
    hlay = new QHBoxLayout;
    grid = new QGridLayout;
    grid->setHorizontalSpacing(2);
    grid->setVerticalSpacing(2);

    maps[0]=new QPixmap(":/VinniePooh.bmp"); maps[1]=new QPixmap(":/VinniePooh_01.bmp");
    maps[2]=new QPixmap(":/VinniePooh_02.bmp"); maps[3]=new QPixmap(":/VinniePooh_03.bmp");
    maps[4]=new QPixmap(":/VinniePooh_04.bmp"); maps[5]=new QPixmap(":/VinniePooh_05.bmp");
    maps[6]=new QPixmap(":/VinniePooh_06.bmp"); maps[7]=new QPixmap(":/VinniePooh_07.bmp");
    maps[8]=new QPixmap(":/VinniePooh_08.bmp"); maps[9]=new QPixmap(":/VinniePooh_09.bmp");
    maps[10]=new QPixmap(":/VinniePooh_10.bmp"); maps[11]=new QPixmap(":/VinniePooh_11.bmp");
    maps[12]=new QPixmap(":/VinniePooh_12.bmp"); maps[13]=new QPixmap(":/VinniePooh_13.bmp");
    maps[14]=new QPixmap(":/VinniePooh_14.bmp"); maps[15]=new QPixmap(":/VinniePooh_15.bmp");

    QTime time(0, 0, 0);
    srand(time.secsTo(QTime::QTime::currentTime()));
    int index[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int random = 0, i=0; i<15; i++)
    {
        do random = 1+rand()%15;
        while((std::find (index, std::end (index), random))!=std::end(index));
        index[i]=random;
    }
    int Chaos = 0;
    int CurrNum;
    for (int i = 0; i < 14; i++)
    {
        CurrNum = index[i];
        for (int j = i + 1; j < 15; j++)
           if (CurrNum > index[j])
                Chaos++;
    }
    if (Chaos % 2 == 1)
    {
        int temp = index[13];
        index[13] = index[14];
        index[14] = temp;
    }
    for(int x = 0, n = 0; x < 4; x++)
        for(int y = 0; y < 4; y++, n++)
            if(n != 15) CreateButton(x, y, index[n]);
    positionEmtyCell.setX(3);
    positionEmtyCell.setY(3);

    label = new QLabel;
    label->setPixmap(*maps[0]);
    label->setFixedSize(250,250);

    textLabel = new QLabel("<h1><code><em><font color=red>Исходная картинка:</font></em></code></h1>");
    textLabel->setAlignment(Qt::AlignLeft);
    textLabel->setFixedSize(250,25);

    hlay->addLayout(grid);
    vlay = new QVBoxLayout;
    vlay->addWidget(textLabel);
    vlay->addWidget(label);
    vlay->setAlignment(Qt::AlignTop);
    vlay->setSpacing(2);

    hlay->addLayout(vlay);
    hlay->setSpacing(30);
    this->setLayout(hlay);
}

void tag::CreateButton(int x, int y, int index)
{
    QPushButton *button = new QPushButton;
    button->setFixedSize(140,140);
    QIcon icon(*maps[index]);
    button->setIcon(icon);
    button->setIconSize(QSize(140,140));
    connect(button, SIGNAL(clicked()), this, SLOT(ButtonsClicked()));
    buttons[index] = button;
    grid->addWidget(button, x, y);
}

bool tag::CheckCorrectLocation()
{
    if(grid->itemAtPosition(positionEmtyCell.x(), positionEmtyCell.y()) != nullptr) return false;
    for(int x = 0, index = 1; x < 4; x++)
        for(int y = 0; y < 4; y++, index++)
        {
            if(grid->itemAtPosition(x,y) == nullptr) continue;
            if(buttons[index] != static_cast <QPushButton*> (grid->itemAtPosition(x,y)->widget())) return false;
        }
    return true;
}

tag::~tag()
{
    delete ui;
}

void tag::ButtonsClicked()
{
    int x, y, rowSpan, columnSpan;
    QPushButton* clickedButton = static_cast<QPushButton*>(sender());
    grid->getItemPosition(grid->indexOf(clickedButton), &x, &y, &rowSpan, &columnSpan);
    if((positionEmtyCell.x() == x+1 && positionEmtyCell.y() == y)||
            (positionEmtyCell.x() == x-1 && positionEmtyCell.y() == y) ||
            (positionEmtyCell.x() == x && positionEmtyCell.y() == y+1) ||
            (positionEmtyCell.x() == x && positionEmtyCell.y() == y-1) )
    {
        grid->removeWidget(clickedButton);
        grid->addWidget(clickedButton, positionEmtyCell.x(), positionEmtyCell.y());
        positionEmtyCell.setX(x);
        positionEmtyCell.setY(y);
        if(CheckCorrectLocation())
        {
            QMessageBox::StandardButton StdButton = QMessageBox::information (this,"Игра окончена!", "Поздравляю! Вы выиграли! Победа!", QMessageBox::Ok);
            if(StdButton == QMessageBox::Ok) QApplication::quit();
        }
    }
}
