#include "Connections.h"
#include "ui_Connections.h"

Connections::Connections(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connections)
{
    ui->setupUi(this);
}

Connections::~Connections()
{
    delete ui;
}
