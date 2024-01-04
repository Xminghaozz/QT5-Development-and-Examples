#include "timeserver.h"
#include "dialog.h"
#include "timethread.h"
TimeServer::TimeServer( QObject *parent )
    : QTcpServer{ parent }
{
    dlg = (Dialog *) parent;
}

void TimeServer::incomingConnection( qintptr socketDescriptor )
{
    TimeThread *thread = new TimeThread( socketDescriptor, 0 );
    connect( thread, &TimeThread::finished, dlg, &Dialog::slotShow );
    connect( thread, &TimeThread::finished, thread, &TimeThread::deleteLater,
             Qt::DirectConnection );

    thread->start();
}
