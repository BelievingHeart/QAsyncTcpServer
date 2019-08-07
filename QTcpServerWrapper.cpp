//
// Created by rocke on 2019/8/7.
//

#include "QTcpServerWrapper.h"
#include <QDebug>
#include "Client.h"

void QTcpServerWrapper::incomingConnection(qintptr handle) {
    // Note: if too many connections are going to setup
    // Note: the client should delete itself after the socket disconnects
    Client *client = new Client(handle, this);
}

void QTcpServerWrapper::startServer() {
    if (listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server Starting...";
    } else {
        qDebug() << "Server failed starting";
    }
}
