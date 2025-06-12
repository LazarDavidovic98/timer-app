#include "TimerPanel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <QSpacerItem>

TimerPanel::TimerPanel(QWidget* parent)
    : QWidget(parent)
{
    // Kreiranje dugmadi
    startButton = new QPushButton("Start");
    startButton->setObjectName("startTimer");
    resetButton = new QPushButton("Reset");
    resetButton->setObjectName("resetTimer");
    setButton = new QPushButton("Set");
    setButton->setObjectName("setTimer");

    // Povezivanje signala
    connect(startButton, &QPushButton::clicked, this, &TimerPanel::startClicked);
    connect(resetButton, &QPushButton::clicked, this, &TimerPanel::resetClicked);
    connect(setButton, &QPushButton::clicked, this, &TimerPanel::setClicked);

    // Usklađivanje veličina dugmadi
    QSize dugmeVelicina = resetButton->sizeHint();
    startButton->setFixedSize(dugmeVelicina);
    setButton->setFixedSize(dugmeVelicina);

    // Labela
    timerLabel = new QLabel("00:00:00");
    timerLabel->setObjectName("timerLabel");
    timerLabel->setFont(QFont("", 44, QFont::Bold));
    timerLabel->setAlignment(Qt::AlignCenter);

    // Layouts
    auto* displayPanel = new QHBoxLayout;
    displayPanel->addWidget(timerLabel);

    auto* commandPanel = new QHBoxLayout;
    commandPanel->addWidget(startButton);
    commandPanel->addWidget(resetButton);
    commandPanel->addSpacing(20);
    commandPanel->addWidget(setButton);

    auto* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(displayPanel);
    mainLayout->addLayout(commandPanel);

    setLayout(mainLayout);
}

void TimerPanel::setDisplay(const QString& display) {
    timerLabel->setText(display);
}

void TimerPanel::setCommandText(const QString& text) {
    startButton->setText(text);
}

