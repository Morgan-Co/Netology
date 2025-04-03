#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(const std::vector<QString> &results, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QList<QLabel *> labels = this->findChildren<QLabel *>();
    int count = qMin<int>(labels.size(), results.size());

    for (int i = 0; i < count; ++i) {
        labels[i]->setText(results[i]);
    }

}

Dialog::~Dialog()
{
    delete ui;
}
