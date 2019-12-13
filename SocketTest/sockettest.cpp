#include "sockettest.h"

SocketTest::SocketTest(QObject *parent)
    : QObject(parent)
{

}

void SocketTest::Connect()
{
    // Connected
    socket = new QTcpSocket(this);

    socket->connectToHost("www.facebook.com",80);

    if (socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        // Sent data
        socket->write("hello server/r/n/r/n");

        socket->waitForBytesWritten(3000);
        socket->waitForReadyRead(5000);

        // Got data
        qDebug() << "Reading:" << socket->bytesAvailable();

//        for(int i = 0; i < 10; ++i){
//            qDebug() << socket->readLine();
//        }
//        qDebug() << socket->readLine()
//                 << "\n"
//                 << socket->readLine()
//                 << "\n"
//                 << socket->readLine();

        qDebug() << socket->readAll();

        // Close the connection
        socket->close();
    }
    else
    {
        qDebug() << "Not connected...";
    }

}
