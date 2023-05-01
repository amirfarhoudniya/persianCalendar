#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //make the persian calendar
    QCalendar cal(QCalendar::System::Jalali);
    QCalendarWidget *calWidget = new QCalendarWidget();
    calWidget->setLocale(QLocale(QLocale::Persian , QLocale::Iran));
    calWidget->setCalendar(cal);

    //set Saturday and Sunday as Regular day
    QTextCharFormat regularDayFormat;
    regularDayFormat.setForeground(Qt::black);
    calWidget->setWeekdayTextFormat(Qt::Saturday, regularDayFormat);
    calWidget->setWeekdayTextFormat(Qt::Sunday, regularDayFormat);

    // Set Fridays as holiday
    QTextCharFormat holidayFormat;
    holidayFormat.setForeground(Qt::red);
    calWidget->setWeekdayTextFormat(Qt::Friday, holidayFormat);

    // Set the layout direction to right-to-left
    calWidget->setLayoutDirection(Qt::RightToLeft);
    setCentralWidget(calWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

