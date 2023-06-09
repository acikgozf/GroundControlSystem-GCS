#include "TcpMcuClient.h"



TcpMcuClient::TcpMcuClient(QObject *parent) : QObject(parent)
{

}

void TcpMcuClient::Connect(){

    //connected
    socket = new QTcpSocket(this);

    //socket->bind(QHostAddress::LocalHost,8);

    connect(socket,SIGNAL(hostFound()),this,SLOT(hostfound()));
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));

    qDebug()<<"Baglaniliyor...";

    socket->connectToHost("192.168.0.111",7); //STM32 FCS ıp adrees and port
    if(!socket->waitForConnected(3000)){
        qDebug()<< "Baglanti Hatasi.."<<socket->errorString();


    }




}

void TcpMcuClient::tcpconnected(){
    qDebug()<<"Baglanilidi..";
    socket->write("merhaba qt\r\n");
}

void TcpMcuClient::tcpdisconnected(){
    qDebug()<<"Baglanilamadi..";
}

void TcpMcuClient::tcpbytesWritten(qint64 bytes){
    qDebug()<<"Bytes yaziliyor..."<<bytes;

}

void TcpMcuClient::tcpreadyRead(){

    qDebug()<<"Datalar okunuyor..";
    qDebug()<<socket->readAll();

}


