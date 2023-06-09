#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QScreen>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QDataStream>
#include <QTextStream>

#include <QLabel>
#include <QLineEdit>


#include <QString>
#include <QDebug>
#include "string.h"
#include "QTableView"
#include "Delegate.h"

#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QStyledItemDelegate>


#include <QRandomGenerator>


#include <QSortFilterProxyModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum MessageLevel
    {
        INFO = 0,
        WARNING = 1,
        CRITICAL = 2
    };

    void test_all_ports();
    void port_tara();
    //Menu islem slotları

    void replyAction();
    void mission_table_init();

protected:
    //void closeEvent(QCloseEvent *event);

private slots:

    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

    void handleBytesWritten(qint64 bytes);
   // void logInfoSlot(const QString &info, int level);

    void data_alindi();
    void baglan_usb();
    void baglan_tcp_udp();

    void addTask();
    void removeTask();



public slots:



signals:
    void logView(const QString &info, int level);



private:
    Ui::MainWindow *ui;


    //Menu islemnleri
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);


    //Spreadsheet *spreadsheet;
    //FindDialog *findDialog;

    void logMessage(QString str, QString tag, MessageLevel level);



    /* USB CONFIG */

    static const quint16 stm32_vid = 9025;
    static const quint16 stm32_pid = 41;
    bool stm32_is_avaible = false;
    QSerialPort *stm32SerialPort;
    QLabel *status = nullptr;
    QByteArray ReceivedData,TransmitData;
    QString serialBuffer;
    QString stm32_port_name;


    /*STATUS LABEL INDICATOR*/
    QLabel * m_statusLeft;
    QLabel * m_statusMiddle;
    QLabel * m_statusRight;
    QLabel * m_statusGPS;

    char datax1[400];

    //MISSION TABLE
    const QStringList waypointNames{"Command","Delay","Lat","Long","Alt","Frame","Delete","%Grad","Anlge","Dist","AZ"};
    const QStringList splinewaypointNames{"Command","Delay","Lat","Long","Alt","Frame","Delete","%Grad","Anlge","Dist","AZ"};
    const QStringList loiterturnsNames{"Command","Turns","Radius","Lat","Long","Alt","Frame","Delete","%Grad","Anlge","Dist","AZ"};

    QStandardItemModel *model;
    QItemSelectionModel model_slc;
    QStyledItemDelegate model_styled;
    Delegate *combobox_delegate;

};
#endif // MAINWINDOW_H
