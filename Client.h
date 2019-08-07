//
// Created by rocke on 2019/8/7.
//

#ifndef QASYNCTCPSERVER_CLIENT_H
#define QASYNCTCPSERVER_CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public  QObject{
    Q_OBJECT

    QTcpSocket* _socket;
public:
    explicit Client(qintptr socketDescriptor, QObject *parent= nullptr);

public slots:
    void socketConnected();
    void socketDisconnected();
    void socketReadyRead();
    void taskResultReady();
};


#endif //QASYNCTCPSERVER_CLIENT_H
