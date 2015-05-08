#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QLabel(parent)
{
	resize(300,200);
	setPixmap( QPixmap(":/res/S1.png").scaled( size() ) );
    QPushButton * b = new QPushButton(tr("Start Sliding..."),this);
	connect( b, SIGNAL(clicked()), this, SLOT(startSliding()) );
	_slidingChildWidget = new QLabel(this);
	_slidingChildWidget->setPixmap( QPixmap(":/res/S2.png").scaled( size() ) );

	_slidingChildWidget->resize( this->size() );
	_slidingChildWidget->move( -1* this->size().width(), 0 );
	_slidingChildWidget->show();
	_slidingChildWidget->raise();
}

void MainWindow::startSliding()
{
	//_slidingChildWidget->move( 0,0 );
	QPropertyAnimation *animation = new QPropertyAnimation(_slidingChildWidget, "pos");
	animation->setDuration(3000);
	animation->setStartValue( QPoint(_slidingChildWidget->pos()) );
	animation->setEndValue(QPoint(0,0) );

    animation->start();
}
