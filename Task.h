//
// Created by rocke on 2019/8/8.
//

#ifndef QASYNCTCPSERVER_TASK_H
#define QASYNCTCPSERVER_TASK_H

#include <QObject>
#include <QRunnable>

class Task : public QObject, public QRunnable {
Q_OBJECT

public:
    // This is going to run on a separate thread
    void run() final;

signals:

    void resultReady(int);
};


#endif //QASYNCTCPSERVER_TASK_H
