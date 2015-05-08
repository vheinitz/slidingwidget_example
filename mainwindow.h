#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>



class MainWindow : public QLabel
{
    Q_OBJECT
    
    QLabel * _slidingChildWidget;
public:
    explicit MainWindow(QWidget *parent = 0);
public slots:
   void startSliding();
};

#endif // MAINWINDOW_H
