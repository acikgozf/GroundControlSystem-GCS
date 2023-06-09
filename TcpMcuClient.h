#ifndef TCPMCUCLIENT_H
#define TCPMCUCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket>
#include <QDataStream>
#include <QByteArray>

class TcpMcuClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpMcuClient(QObject *parent = nullptr);
    void Connect();


signals:

public slots:
    void tcpconnected();
    void tcpdisconnected();
    void tcpbytesWritten(qint64 bytes);
    void tcpreadyRead();
private:
    QTcpSocket *socket;
};

#endif // TCPMCUCLIENT_H
