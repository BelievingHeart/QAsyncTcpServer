//
// Created by rocke on 2019/8/8.
//

#include "Task.h"
#include <QDebug>

void Task::run() {
    qDebug() << "Task starts...";

    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += i;
    }

    qDebug() << "Task done";

    emit resultReady(sum);
}
