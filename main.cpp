//
// Example program from https://www.youtube.com/watch?v=BWEIWViWFwI
//
// In the example, a TCP server may open up to 1000 sockets
// However it can use just a bunch of threads from the thread pool to process all the client inputs
// The processed result is finally kicked back to the main thread and sent back to the client

#include <QCoreApplication>
#include "QTcpServerWrapper.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    QTcpServerWrapper server;
    server.startServer();

    return app.exec();
}