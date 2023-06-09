#include "MainWindow.h"
#include <QSplashScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect screenrect = a.primaryScreen()->geometry();
    w.move(screenrect.left(), screenrect.top());
    w.resize(screenrect.width(), screenrect.height());


    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/intro.png"));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Setting up the main window..."),
    topRight, Qt::white);

    splash->showMessage(QObject::tr("Loading modules..."),
    topRight, Qt::white);

    //loadModules();

    splash->showMessage(QObject::tr("Establishing connections..."),
    topRight, Qt::white);

    //establishConnections();

    w.showMaximized();
    splash->finish(&w);

    delete splash;

    return a.exec();
}


