#include "Delegate.h"

Delegate::Delegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}
/*
QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox* combo_box = new QComboBox(parent);

    for(int i = 0; i < this->labels.count(); i++)
    {
        combo_box->addItem(this->labels[i]);
    }
    return combo_box;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = 0;
    QString text = index.model()->data(index, Qt::EditRole).toString();
    QComboBox* combo_box = static_cast<QComboBox*>(editor);

    for(int i = 0; i < this->labels.count(); i++)
    {
        if(text == this->labels[i]){value = i; break;}
    }
    combo_box->setCurrentIndex(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* combo_box = static_cast<QComboBox*>(editor);
    model->setData(index, combo_box->currentText(), Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

*/
