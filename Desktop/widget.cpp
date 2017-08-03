#include "widget.h"
#include "ui_widget.h"
#include <settingsdialog.h>
#include <QBluetoothLocalDevice>

void Widget::window_settings()
{
    settings = new SettingsDialog();
    settings->exec();
}

void Widget::close_and_clear_port()
{
    qDebug()<<"close_and_openport"<<endl;
    Qt_serial_port.close();
    SettingsDialog::Settings p = settings->settings();
    sp->open_serial_port(p.name, p.baudRate, p.dataBits,
                         p.parity, p.stopBits, p.flowControl);
}



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    window_settings();   //bird of the setting window
    sp = new serial_port(this);
    /*
     * порт нужно сначала закрыть, а потом открыть с нужными параметрами
     * закрыть порт QSerialPort object;object.close();
     * открыть порт serial_port object2;object2.openPort(аргументы структуры);
    */
    close_and_clear_port();


    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(value_for_prgs);

    /*
    QBluetoothLocalDevice asd;
    asd.powerOn();
    asd.setHostMode( QBluetoothLocalDevice::HostConnectable );*/

    //connection. data from serial_port sends to Desktop
    connect(sp,SIGNAL(on_pluss_clicked()),this,SLOT(on_plus_clicked()));
    connect(sp,SIGNAL(on_minus_clicked()),this,SLOT(on_minus_clicked()));

    //connection. Data from Destop sends to Serial Port
    connect(this,SIGNAL(signal_on_min_clicked()),sp,SLOT(send_minus_clicked()));
    connect(this,SIGNAL(signal_on_pl_clicked()),sp,SLOT(send_plus_clicked()));


    //connect(sp,&serial_port::)


   // SettingsDialog a;a.show();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::openPort()
{
    SettingsDialog::Settings p = settings->settings();
    sp->open_serial_port(p.name, p.baudRate, p.dataBits,
                         p.parity, p.stopBits, p.flowControl);
}


void Widget::on_plus_clicked()
{
    if(value_for_prgs!=100)
   { value_for_prgs+=10;
    ui->progressBar->setValue(value_for_prgs);
    emit signal_on_pl_clicked();}
}

void Widget::on_minus_clicked()
{
    if(value_for_prgs!=0)
   { value_for_prgs-=10;
    ui->progressBar->setValue(value_for_prgs);
    emit signal_on_min_clicked();}
}

void Widget::set_settings()
{
    settings = new SettingsDialog;
    settings->exec();
  //  connect( );
 //   connect(ui->actionSettings, &QAction::triggered, settings, &this::show);
}
