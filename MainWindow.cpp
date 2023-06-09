#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <QDateTime>
#include <QComboBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent,Qt::CustomizeWindowHint |
                  Qt::WindowMinimizeButtonHint |
                  Qt::WindowMaximizeButtonHint |
                  Qt::WindowCloseButtonHint)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry. height();
    int width = screenGeometry. width();
    qDebug()<< "Ekran boyutlar:"<< height << width;



    //HARITA_AYARLARI
    ui->MapquickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->MapquickWidget->show();


    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();
    readSettings();

    //görev fonksioyonu
    mission_table_init();


    connect(ui->actionUSB, SIGNAL(triggered()), this, SLOT(baglan_usb()));
    connect(ui->actionTCP_UDP, SIGNAL(triggered()), this, SLOT(baglan_tcp_udp()));
    connect(ui->addtaskpushButton,SIGNAL(pressed()),this,SLOT(addTask()));
    connect(ui->deletetaskpushButton,SIGNAL(clicked(bool)),this,SLOT(removeTask()));

    //connect(stm32SerialPort, SIGNAL(bytesWritten(qint64)), SLOT(handleBytesWritten(qint64)));
    //connect(this, SIGNAL(logView(QString, int)), this,SLOT(logInfoSlot(QString, int)));
}


void MainWindow::mission_table_init(){


    int i=0 , j=0;
    QStandardItemModel *model = new QStandardItemModel(1,16);

    model->setHorizontalHeaderLabels(waypointNames);

    ui->missiontableView->setModel(model);
    ui->missiontableView->show();




}
void MainWindow::addTask(){

    qDebug() << "onAddClicked...";
    combobox_delegate = new Delegate(this);
    QList<QStandardItem*> newRow;
    QStandardItem *item1 = new QStandardItem(QString("col1"));
    QStandardItem *item2 = new QStandardItem(QString("col2"));

    newRow.append(item1);
    newRow.append(item2);

    for (int row = 0 ;row < 16;row++){

        for (int column = 0;column <16;column++){

            QModelIndex model_idx = model->index(row,column,QModelIndex());
            model->insertColumn(column+1,QModelIndex());
            model->setData(model_idx,500);
            //model->setItem
        }
    }


/*
    constexpr int rows =2;
    constexpr int columns = 2;


   for(int row = 0;row < rows; ++row)
    {
        //model->setHeaderData(column,Qt::Horizontal,columnNames.at(column));
        for (int column = 0; column < columns; ++column){
            //model->setData(model->index(row,column),generator.bounded(0,100));
            model->setHeaderData(row,Qt::Vertical,QString("row %1").arg(row + 1));
            model->setItem(row,columns,new QStandardItem(QString("(%1, %2)").arg(rows).arg(column)));
        }
    }
    //sort_proxy.setSourceModel(&model);

    //ui->missiontableView->setSortingEnabled(true);
    ui->missiontableView->setModel(model);

    auto verticalHeader =  ui->missiontableView->verticalHeader();
    auto horizontalHeader =  ui->missiontableView->horizontalHeader();

    if(false){
        //Strench last column
        horizontalHeader->setStretchLastSection(true);

        //Not sure if this makes sense at all
        verticalHeader->setStretchLastSection(true);

    }
*/
}
void MainWindow::removeTask(){

    qDebug() << "onRemoveClicked...";

    QModelIndex currentIndex = ui->missiontableView->selectionModel()->currentIndex();
    model->removeRow(currentIndex.row());
}

void MainWindow::createActions()
{

    ui->actionNew->setShortcut(tr("Ctrl+N"));
    ui->actionNew->setStatusTip(tr("Create a new spreadsheet file"));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));

    ui->actionOpen->setShortcut(tr("Ctrl+O"));
    ui->actionOpen->setStatusTip(tr("Open new file"));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));

    ui->actionSave->setShortcut(tr("Ctrl+S"));
    ui->actionSave->setStatusTip(tr("Save file"));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));

    ui->actionSave_As->setStatusTip(tr("Save as file"));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));

    ui->actionAbout->setStatusTip(tr("Show the Qt library’s About box"));
   connect(ui->actionAbout, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}
void MainWindow::createMenus()
{

}
void MainWindow::createContextMenu()
{

}
void MainWindow::createToolBars()
{

}
void MainWindow::createStatusBar(){


    //Do multipart status bar
    m_statusLeft = new QLabel("Left");
    m_statusLeft->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_statusLeft->setLineWidth(4);

    m_statusMiddle = new QLabel("Middle");
    m_statusMiddle->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_statusMiddle->setLineWidth(4);
    m_statusMiddle->setText("STATE: ");

    m_statusGPS= new QLabel("GPS");
    m_statusGPS->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_statusGPS->setLineWidth(4);
    m_statusGPS->setText("GPS: ");

    m_statusRight = new QLabel("Right");
    m_statusRight->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_statusRight->setAlignment(Qt::AlignRight);
    m_statusRight->setLineWidth(4);
    m_statusRight->setText("LOG: ");

    statusBar()->addPermanentWidget(m_statusLeft, 1);
    statusBar()->addPermanentWidget(m_statusMiddle, 1);
    statusBar()->addPermanentWidget(m_statusGPS, 1);
    statusBar()->addPermanentWidget(m_statusRight, 2);

    statusBar()->styleSheet();

}

void MainWindow::readSettings(){

}

void MainWindow::baglan_usb(){
    port_tara();

}
void MainWindow::baglan_tcp_udp(){
    //port_tara_tcp_udp();

}


void MainWindow::newFile(){

}

void MainWindow::open(){

}

bool MainWindow::save(){

}

bool MainWindow::saveAs(){

}
void MainWindow::find(){

}

void MainWindow::goToCell(){

}
void MainWindow::sort(){

}

void MainWindow::about(){

}
void MainWindow::openRecentFile(){

}

void MainWindow::updateStatusBar(){

}

void MainWindow::spreadsheetModified(){

}

void MainWindow::port_tara(){

    //Kullanilabilir bütün portlar icin..
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if((serialPortInfo.productIdentifier() == stm32_pid) && (serialPortInfo.vendorIdentifier() == stm32_vid)){
                stm32_is_avaible = true;
                stm32_port_name = serialPortInfo.portName();

            }
        }
    }


    if(stm32_is_avaible)
    {
        qDebug()<< "STM32 bulundu..\n";
        //kontrol = stm32SerialPort->open( QIODevice::ReadOnly);
        stm32SerialPort->setPortName(stm32_port_name);
        stm32SerialPort->setBaudRate(QSerialPort::Baud9600);
        stm32SerialPort->setDataBits(QSerialPort::Data8);
        stm32SerialPort->setParity(QSerialPort::NoParity);
        stm32SerialPort->setStopBits(QSerialPort::OneStop);
        stm32SerialPort->setFlowControl(QSerialPort::NoFlowControl);

        if (!stm32SerialPort->open( QIODevice::ReadWrite)){
             qDebug() << "Port acilamadi.. ";
             m_statusLeft->setStyleSheet("QLabel { background-color : red; color : black; }");
             m_statusLeft->setText("DISCONNECTED!");
        }
        else{
             qDebug() << "Port acildi.. ";
              //statusBar()->showEvent();
            m_statusLeft->setStyleSheet("QLabel { background-color : green; color : black; }");
            m_statusLeft->setText("CONNECTED!");
        }

            //stm32SerialPort->write("Ok");
        connect(stm32SerialPort,SIGNAL(readyRead()), this,SLOT(data_alindi()));

    }
    else{
        qDebug()<< "STM32 bulunamadi..\n";
        m_statusLeft->setStyleSheet("QLabel { background-color : yellow; color : black; }");
        m_statusLeft->setText("STM32 bulunamadi!");
    }

}

void MainWindow::data_alindi(){

    bool ok;
    serialBuffer= stm32SerialPort->readAll();
    QStringList bufferSplit = serialBuffer.split(",");

    QString roll = bufferSplit[0];
    QString pitch = bufferSplit[1];

    ui->accrollLineEdit->setText(roll);
    ui->PFDgraphicsView->setRoll(roll.toDouble(&ok));
    ui->PFDgraphicsView->redraw();
    ui->accpitchLineEdit->setText(pitch);
    ui->PFDgraphicsView->setPitch(pitch.toDouble(&ok));
    ui->PFDgraphicsView->redraw();


}

void MainWindow::test_all_ports(){

    /*
     *  Butun portların venor id, product id, ve tanımlarını basar..
     */

    qDebug() << "Number of ports" << QSerialPortInfo::availablePorts().length() << "\n";
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Description" <<serialPortInfo.description()<<"\n";
        qDebug() << "Has vendor id ?" <<serialPortInfo.hasVendorIdentifier()<<"\n";
        qDebug() << "Vendor ID" <<serialPortInfo.vendorIdentifier()<<"\n";
        qDebug() << "Has product id ?" <<serialPortInfo.hasProductIdentifier()<<"\n";
        qDebug() << "Product ID" <<serialPortInfo.portName()<<"\n";

    }
}

void MainWindow::replyAction(){
    TransmitData.clear();

    TransmitData.append("{");//"{000}\n"
    //sprintf(datax1, "%03d", ui->);
    TransmitData.append(datax1);
    TransmitData.append("}\n");

    stm32SerialPort->write(TransmitData);


}

void MainWindow::handleBytesWritten(qint64 bytes){
    replyAction();
}
/*
void MainWindow::logInfoSlot(const QString &info, int level)
{
    logMessage(info,
               QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"),
               (MessageLevel)level);
}

void MainWindow::logMessage(QString str, QString tag, MessageLevel level)
{
    if (ui->level_1->isChecked())
    {

        QString flag;

        if (level == INFO)
        {
            flag = "INFO";
        }
        else if (level == WARNING)
        {
            flag = "WARNING";

        }
        else if (level == CRITICAL)
        {
            flag = "ERROR";

        }

        QListWidgetItem *item = new QListWidgetItem(tr("%1[%2]:%23").arg(tag).arg(
                    flag).arg(str));

        ui->loglist->addItem(item);

        switch (level)
        {
        case INFO:
            item->setBackgroundColor(Qt::white);
            break;

        case WARNING:
            item->setBackgroundColor(Qt::yellow);
            break;

        case CRITICAL:
            item->setBackgroundColor(Qt::red);
            break;

        default:
            break;
        }
    }
    else if (ui->level_2->isChecked())
    {
        if (level == WARNING)
        {
            QListWidgetItem *item = new QListWidgetItem(tr("%1[WARNING]:%2").arg(tag).arg(
                        str));
            ui->loglist->addItem(item);
            item->setBackgroundColor(Qt::yellow);
        }

    }
    else if (ui->level_3->isChecked())
    {
        if (level == CRITICAL)
        {
            QListWidgetItem *item = new QListWidgetItem(tr("%1[ERROR]:%2").arg(tag).arg(
                        str));
            ui->loglist->addItem(item);
            item->setBackgroundColor(Qt::red);
        }

    }

    ui->loglist->setCurrentRow(ui->loglist->count() - 1);
}

*/
MainWindow::~MainWindow()
{

    if(stm32SerialPort->isOpen())
    {
        stm32SerialPort->close();
    }
    delete ui;
}

