#ifndef QTSBETPROCESSOR_CPP
#define QTSBETPROCESSOR_CPP

#include "qtsbetprocessor.h"
#include <cmath>

QtSbetProcessor::QtSbetProcessor(QTableWidget * table)
{
    this->table = table;
}

void QtSbetProcessor::processEntry(SbetEntry * entry){
    table->insertRow( table->rowCount() );

    QTableWidgetItem * timestamp = new QTableWidgetItem(QString::number(entry->time, 'f', 6));
    timestamp->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,0,timestamp);

    QTableWidgetItem * latitude = new QTableWidgetItem(QString::number((entry->latitude * 180)/M_PI, 'f', 12));
    latitude->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,1,latitude);

    QTableWidgetItem * longitude = new QTableWidgetItem(QString::number((entry->longitude * 180)/M_PI, 'f', 12));
    longitude->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,2,longitude);

    QTableWidgetItem * altitude = new QTableWidgetItem(QString::number(entry->altitude, 'f', 6));
    altitude->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,3,altitude);

    QTableWidgetItem * xSpeed = new QTableWidgetItem(QString::number(entry->xSpeed, 'f', 6));
    xSpeed->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,4,xSpeed);

    QTableWidgetItem * ySpeed = new QTableWidgetItem(QString::number(entry->ySpeed, 'f', 6));
    ySpeed->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,5,ySpeed);

    QTableWidgetItem * zSpeed = new QTableWidgetItem(QString::number(entry->zSpeed, 'f', 6));
    zSpeed->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,6,zSpeed);

    QTableWidgetItem * heading = new QTableWidgetItem(QString::number(entry->heading, 'f', 6));
    heading->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,7,heading);

    QTableWidgetItem * pitch = new QTableWidgetItem(QString::number(entry->pitch, 'f', 6));
    pitch->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,8,pitch);

    QTableWidgetItem * roll = new QTableWidgetItem(QString::number(entry->roll, 'f', 6));
    roll->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,9,roll);

    QTableWidgetItem * wander = new QTableWidgetItem(QString::number(entry->wander, 'f', 6));
    wander->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,10,wander);

    QTableWidgetItem * xForce = new QTableWidgetItem(QString::number(entry->xForce, 'f', 6));
    xForce->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,11,xForce);

    QTableWidgetItem * yForce = new QTableWidgetItem(QString::number(entry->yForce, 'f', 6));
    yForce->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,12,yForce);

    QTableWidgetItem * zForce = new QTableWidgetItem(QString::number(entry->zForce, 'f', 6));
    zForce->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,13,zForce);

    QTableWidgetItem * xAngularRate = new QTableWidgetItem(QString::number(entry->xAngularRate, 'f', 6));
    xAngularRate->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,14,xAngularRate);

    QTableWidgetItem * yAngularRate = new QTableWidgetItem(QString::number(entry->yAngularRate, 'f', 6));
    yAngularRate->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,15,yAngularRate);

    QTableWidgetItem * zAngularRate = new QTableWidgetItem(QString::number(entry->zAngularRate, 'f', 6));
    zAngularRate->setTextAlignment(Qt::AlignRight);
    table->setItem(table->rowCount()-1,16,zAngularRate);
}


#endif
