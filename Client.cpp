//
// Created by rocke on 2019/8/7.
//

#include "Client.h"
#include <QDebug>


void Client::socketConnected(){
    qDebug() << "Client connected event triggered";

}

Client::Client(qintptr socketDescriptor, QObject *parent) : QObject(parent) {
    _socket = new QTcpSocket(this);
    _socket->setSocketDescriptor(socketDescriptor);

    // connections
    connect(_socket, SIGNAL(connected()), this, SLOT(socketConnected()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

    qDebug() << "Client connected";
}

void Client::socketDisconnected() {
    qDebug() << "Client disconnected";
}

void Client::socketReadyRead() {
    // Accept incoming messages
    qDebug() << _socket->readAll();

    // And process them, might be a time consuming task
    // => using the thread pool to keep the main thread from locking
    // todo: fill up process code
}

void Client::taskResultReady() {
    // todo: fill this up
}
