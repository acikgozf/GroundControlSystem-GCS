#include "UdpMcuClient.h"

UdpMcuClient::UdpMcuClient(QObject *parent) : QObject(parent)
{

   QByteArray datagram;
   QString    veri;


   udpSocket.bind(QHostAddress::LocalHost,7);

   udpSocket.connectToHost("192.168.0.111",8);

   connect(&udpSocket, SIGNAL(hostFound()),this, SLOT(host_status()));
   connect(&udpSocket, SIGNAL(connected()),this, SLOT(Connection_status()));
   connect(&udpSocket, SIGNAL(QUdpSocket::readyRead()),this, SLOT(processPendingDatagrams()));


   //veri = "merhaba";
   //datagram.append(veri);

   //udpSocket.writeDatagram(datagram,"192.168.0.111");
}
void UdpMcuClient::SendData()
{
    QByteArray data;
    data.append("Hello from UDP");
    udpSocket.writeDatagram(data,QHostAddress::LocalHost,7);

}

void UdpMcuClient::host_status(){

    qDebug() << "Host bulundu..";
}

void UdpMcuClient::Connection_status(){

    qDebug() << "Baglanti_durumu_(baglanildi)";
}

void UdpMcuClient::processPendingDatagrams()
{
     QByteArray datagram;
    while (udpSocket.hasPendingDatagrams())// En az bir datagram beklenir okumak için vt:bool
    {
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());

        qDebug() << "Udp data"<<datagram;

    }


    //QDateTime dateTime;

    //QDataStream in(&datagram, QIODevice::ReadOnly);
    //in.setVersion(QDataStream::Qt_5_1);
    //qDebug() << "Udp data" << in;
    //in >> dateTime >> temperature >> humidity >> altitude;


    //dateLineEdit->setText(dateTime.date().toString());
    //timeLineEdit->setText(dateTime.time().toString());

    //GyrPitchLineEdit->setText(tr("%1 °C").arg(temperature));
    //GyrYawLineEdit->setText(tr("%1%").arg(humidity));
    //GyrRollLineEdit->setText(tr("%1 m").arg(altitude));


}
