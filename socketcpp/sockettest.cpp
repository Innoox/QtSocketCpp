#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{
}

void SocketTest::Connect()
{
    // connecting to the host
    socket = new QTcpSocket(this);
    socket->connectToHost("google.com", 80);
    //socket->connectToHost("voidrealms.com", 80);
    //socket->connectToHost("youtube.com", 80);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        // send data
        socket->write("Hello there. Connection is valid!\r\n\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        // getting data
        qDebug() << socket->readAll();

        // close connection
        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }
}
