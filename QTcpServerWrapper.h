//
// Created by rocke on 2019/8/7.
//

#ifndef QASYNCTCPSERVER_QTCPSERVERWRAPPER_H
#define QASYNCTCPSERVER_QTCPSERVERWRAPPER_H

#include <QTcpServer>

class QTcpServerWrapper : public QTcpServer{
    Q_OBJECT

public:
    explicit QTcpServerWrapper(QObject *parent= nullptr) : QTcpServer(parent) {}

    void startServer();

protected:
    void incomingConnection(qintptr handle) final;
};


#endif //QASYNCTCPSERVER_QTCPSERVERWRAPPER_H
