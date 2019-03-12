#ifndef QDATETIMEEDITTEST_H
#define QDATETIMEEDITTEST_H

#include <QWidget>
#include <QDateTimeEdit>

namespace Ui {
class QDateTimeEditTest;
}

class QDateTimeEditTest : public QWidget
{
    Q_OBJECT

public:
    explicit QDateTimeEditTest(QWidget *parent = nullptr);
    ~QDateTimeEditTest();

public slots:
    void setStartDateTime();
    void setStopDateTime();

private:
    Ui::QDateTimeEditTest *ui;
    QDateTimeEdit *startEdit;
    QDateTimeEdit *endEdit;
};

#endif // QDATETIMEEDITTEST_H
