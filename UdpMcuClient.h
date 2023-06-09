#ifndef UDPMCUCLIENT_H
#define UDPMCUCLIENT_H

#include <QObject>
#include <QUdpSocket>

class UdpMcuClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpMcuClient(QObject *parent = nullptr);
    void SendData();
signals:

public slots:
    void processPendingDatagrams();
    void Connection_status();
    void host_status();

private:
        QUdpSocket udpSocket;
};

#endif // UDPMCUCLIENT_H
