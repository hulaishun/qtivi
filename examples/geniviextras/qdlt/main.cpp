/****************************************************************************
**
** Copyright (C) 2015 Pelagicore AG
** Contact: http://www.pelagicore.com/
**
** This file is part of $FOO$.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial $FOO$ licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Pelagicore. For licensing terms
** and conditions see http://www.pelagicore.com.
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
** As a special exception, Pelagicore gives you certain additional
** rights. These rights are described in Pelagicore LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QCoreApplication>
#include <QTimer>
#include <QtGeniviExtras/QtDlt>

#include "loggingcategories.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(QDltRegistration::messageHandler);

    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.connect(&timer, &QTimer::timeout, [] {
        static int counter = 0;
        counter++;
        qCCritical(FOO) << "FOO CATEGORY";
        qCWarning(BAR) << "BAR CATEGORY";
        qCritical() << "FALLBACK";
    });
    timer.setInterval(1000);
    timer.start();

    return a.exec();
}
