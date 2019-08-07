//
// Example program from https://www.youtube.com/watch?v=BWEIWViWFwI
//

#include <QCoreApplication>
#include "QTcpServerWrapper.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    QTcpServerWrapper server;
    server.startServer();

    return app.exec();
}