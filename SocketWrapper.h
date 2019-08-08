//
// Created by rocke on 2019/8/7.
//

#ifndef QASYNCTCPSERVER_SOCKETWRAPPER_H
#define QASYNCTCPSERVER_SOCKETWRAPPER_H

#include <QObject>
#include <QTcpSocket>

class SocketWrapper : public QObject {
    Q_OBJECT

    QTcpSocket* _socket;
public:
    explicit SocketWrapper(qintptr socketDescriptor, QObject *parent = nullptr);

public slots:
    void socketConnected();
    void socketDisconnected();
    void socketReadyRead();

    void taskResultReady(int);
};


#endif //QASYNCTCPSERVER_SOCKETWRAPPER_H
