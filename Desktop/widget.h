#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <settingsdialog.h>
#include <serial_port.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    QSerialPort Qt_serial_port;
    serial_port *sp;
    SettingsDialog *settings;
    int value_for_prgs=50;
    void window_settings();
    void close_and_clear_port();
    void openPort();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:
    void signal_on_pl_clicked();
    void signal_on_min_clicked();


public slots:
    void on_plus_clicked();
    void on_minus_clicked();

private:
    Ui::Widget *ui;
    void set_settings();
};

#endif // WIDGET_H
