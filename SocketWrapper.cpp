//
// Created by rocke on 2019/8/7.
//

#include "SocketWrapper.h"
#include <QDebug>
#include <QThreadPool>
#include "Task.h"

void SocketWrapper::socketConnected() {
    qDebug() << "Client connected event triggered";

}

SocketWrapper::SocketWrapper(qintptr socketDescriptor, QObject *parent) : QObject(parent) {
    _socket = new QTcpSocket(this);
    _socket->setSocketDescriptor(socketDescriptor);

    // connections
    connect(_socket, SIGNAL(connected()), this, SLOT(socketConnected()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

    qDebug() << "Client connected";
}

void SocketWrapper::socketDisconnected() {
    qDebug() << "Client disconnected";
}

void SocketWrapper::socketReadyRead() {
    // Accept incoming messages
    qDebug() << _socket->readAll();

    // And process them, might be a time consuming task
    // => using the thread pool to keep the main thread from locking
    Task *task = new Task;
    // enable by default
    // With this on, QThreadPool will automatically delete the QRunnable object when `run` ends
    task->setAutoDelete(true);
    // resultReady is fired from a background thread then queued up by event loop in the main thread
    connect(task, SIGNAL(resultReady(int)), this, SLOT(taskResultReady(int)));
    QThreadPool::globalInstance()->start(task);


}

void SocketWrapper::taskResultReady(int result) {
    QByteArray output;
    output.append("Task result=");
    output.append(QString::number(result));
    _socket->write(output);
}
