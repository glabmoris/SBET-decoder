#ifndef QTSBETPROCESSOR_H
#define QTSBETPROCESSOR_H

#include <QTableWidget>
#include "../../SbetProcessor.hpp"

class QtSbetProcessor : public SbetProcessor
{
public:
    QtSbetProcessor(QTableWidget * table);

    //Overload
    void processEntry(SbetEntry * entry);

private:
    QTableWidget * table;
};


#endif // QTSBETPROCESSOR_H
