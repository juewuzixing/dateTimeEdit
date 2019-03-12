#include "qdatetimeedittest.h"
#include "ui_qdatetimeedittest.h"
#include <QDateTime>
#include <QDate>
#include <QCalendarWidget>

QDateTimeEditTest::QDateTimeEditTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDateTimeEditTest)
{
    ui->setupUi(this);
    startEdit = ui->startDateTimeEdit;
    endEdit = ui->endDateTimeEdit;

    QCalendarWidget *m_pCalendarWidget;
    m_pCalendarWidget = new QCalendarWidget(this);
    m_pCalendarWidget->setMinimumDate(QDate(2000, 1, 1));
    m_pCalendarWidget->setFixedSize(300,200); //日历控件的显示大小
    m_pCalendarWidget->show();

    QDateTime xmas(QDate(QDateTime::currentDateTime().date().year(),1,1),QTime(00,00));
    QDateTime xmas1(QDate(QDateTime::currentDateTime().date().year(),12,31),QTime(00,00));

    startEdit->setDateTime(xmas);
    startEdit->setCalendarPopup(true);
    startEdit->setCalendarWidget(m_pCalendarWidget);
    endEdit->setDateTime(xmas1);
    endEdit->setCalendarPopup(true);
    endEdit->setCalendarWidget(m_pCalendarWidget);

    connect(startEdit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(setStartDateTime()));
    connect(endEdit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(setStopDateTime()));
}

QDateTimeEditTest::~QDateTimeEditTest()
{
    delete ui;
}

void QDateTimeEditTest::setStartDateTime()
{
    startEdit->setMaximumDateTime(endEdit->dateTime());
}

void QDateTimeEditTest::setStopDateTime()
{
    endEdit->setMinimumDateTime(startEdit->dateTime());
}
