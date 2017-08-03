/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>
#include <QDataStream>
//#include <QDebug>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingsDialog;
}

class QIntValidator;

QT_END_NAMESPACE

/*!
 * \brief Диалог настроек
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Настройки
     */
    struct Settings {
        /*!
         * \brief name имя порта
         */
        QString name;
        /*!
         * \brief baudRate скорость модуляции
         */
        qint32 baudRate;
        QString stringBaudRate;
        /*!
         * \brief dataBits биты данных
         */
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        /*!
         * \brief parity бит четности
         */
        QSerialPort::Parity parity;
        QString stringParity;
        /*!
         * \brief stopBits стоп-бит
         */
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        /*!
         * \brief flowControl тип потока управления
         */
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    /*!
     * \brief Инициализация диалога настроек
     * \param parent предок
     */
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    Settings settings() const;

signals:
    /*!
     * \brief Настройки обновлены
     */
    void settingsUpdated();

private slots:
    /*!
     * \brief Возвращает информацию о порте
     * \param idx номер порта в списке
     */
    void showPortInfo(int idx);
    /*!
     * \brief Применяет наройки
     */
    void apply();
    /*!
     * \brief Проверяет пользовательскую скорость модуляции
     * \param idx номер списке
     */
    void checkCustomBaudRatePolicy(int idx);
    /*!
     * \brief Проверяет пользовательский порт
     * \param idx номер списке
     */
    void checkCustomDevicePathPolicy(int idx);

private:
    /*!
     * \brief Заполняет параметры портов
     */
    void fillPortsParameters();
    /*!
     * \brief Заполняет информацию о порте
     */
    void fillPortsInfo();
    /*!
     * \brief Обновляет настройки
     */
    void updateSettings();

private:
    /*!
     * \brief Графический интерфейс
     */
    Ui::SettingsDialog *ui;
    /*!
     * \brief Текущие настройки
     */
    Settings currentSettings;
    /*!
     * \brief Числовой валидатор
     */
    QIntValidator *intValidator;
};

#endif // SETTINGSDIALOG_H
