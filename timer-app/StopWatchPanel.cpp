#include "StopWatchPanel.h"
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPalette>

StopWatchPanel::StopWatchPanel(QWidget* parent)
    : QWidget(parent)
{
    stopWatchLabel = new QLabel("00:00:00");
    stopWatchLabel->setFont(QFont("", 44, QFont::Bold));
    stopWatchLabel->setAutoFillBackground(true);

    startButton = new QPushButton("Start");
    resetButton = new QPushButton("Reset");
    splitButton = new QPushButton("Split");
    showButton = new QPushButton("Show");

    // Identifikatori (možeš koristiti objectName ako bude trebalo)
    startButton->setObjectName("startStopWatch");
    resetButton->setObjectName("resetStopWatch");
    splitButton->setObjectName("splitStopWatch");
    showButton->setObjectName("showStopWatch");

    // Onemogući Split dugme na početku
    splitButton->setEnabled(false);

    // Emituj signale
    connect(startButton, &QPushButton::clicked, this, &StopWatchPanel::startClicked);
    connect(resetButton, &QPushButton::clicked, this, &StopWatchPanel::resetClicked);
    connect(splitButton, &QPushButton::clicked, this, &StopWatchPanel::splitClicked);
    connect(showButton, &QPushButton::clicked, this, &StopWatchPanel::showClicked);

    // Poravnanja
    QHBoxLayout* commandLayout = new QHBoxLayout;
    commandLayout->addWidget(startButton);
    commandLayout->addWidget(resetButton);
    commandLayout->addSpacing(20);
    commandLayout->addWidget(splitButton);
    commandLayout->addWidget(showButton);
    commandLayout->setAlignment(Qt::AlignLeft);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(stopWatchLabel, 0, Qt::AlignHCenter);
    mainLayout->addLayout(commandLayout);

    setLayout(mainLayout);
}

void StopWatchPanel::setDisplay(const QString& display) {
    stopWatchLabel->setText(display);
}

void StopWatchPanel::setCommandText(const QString& text) {
    startButton->setText(text);
}

void StopWatchPanel::disableShowButton() {
    showButton->setEnabled(false);
}

void StopWatchPanel::enableShowButton() {
    showButton->setEnabled(true);
}

void StopWatchPanel::disableSplitButton() {
    splitButton->setEnabled(false);
}

void StopWatchPanel::enableSplitButton() {
    splitButton->setEnabled(true);
}

void StopWatchPanel::setDisplayBackground(const QColor& color) {
    QPalette palette = stopWatchLabel->palette();
    palette.setColor(QPalette::Window, color);
    stopWatchLabel->setPalette(palette);
}
