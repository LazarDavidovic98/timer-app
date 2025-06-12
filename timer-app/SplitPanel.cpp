#include "SplitPanel.h"
#include <QVBoxLayout>
#include <QSpacerItem>

SplitPanel::SplitPanel(QWidget* parent)
    : QWidget(parent)
{
    // Inicijalizacija
    splits = new QListWidget(this);
    deleteAllButton = new QPushButton("Delete all", this);
    deleteAllButton->setObjectName("deleteAllSplit");

    // Povezivanje signala
    connect(deleteAllButton, &QPushButton::clicked, this, &SplitPanel::deleteAllClicked);

    // Podešavanje izgleda
    setMinimumSize(150, 300);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(splits);
    layout->addSpacing(20);
    layout->addWidget(deleteAllButton);

    setLayout(layout);
}

void SplitPanel::add(const QString& time) {
    splits->addItem(time);
}

void SplitPanel::deleteAll() {
    splits->clear();
}

