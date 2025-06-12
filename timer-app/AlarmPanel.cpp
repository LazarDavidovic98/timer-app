#include "AlarmPanel.h"
#include <QBoxLayout>
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QSizePolicy>

AlarmPanel::AlarmPanel(QWidget* parent)
    : QWidget(parent)
{
    enableButton = new QPushButton("Enable");
    enableButton->setObjectName("enableAlarm");
    setButton = new QPushButton("Set");
    setButton->setObjectName("setAlarm");

    connect(enableButton, &QPushButton::clicked, this, &AlarmPanel::enableClicked);
    connect(setButton, &QPushButton::clicked, this, &AlarmPanel::setClicked);

    // Podešavanje dimenzija
    enableButton->setFixedSize(80, 30);
    setButton->setFixedSize(67, 26);

    timeLabel = new QLabel("00:00:00");
    timeLabel->setObjectName("timeLabel");
    timeLabel->setFont(QFont("", 34, QFont::Bold));
    timeLabel->setAlignment(Qt::AlignCenter);

    alarmLabel = new QLabel("00:00:00");
    alarmLabel->setObjectName("alarmLabel");
    alarmLabel->setFont(QFont("", 17, QFont::Bold));
    alarmLabel->setAlignment(Qt::AlignCenter);
    alarmLabel->setStyleSheet("color: gray;");

    // Layouts
    auto* displayLayout = new QHBoxLayout;
    displayLayout->addWidget(timeLabel);

    auto* alarmLayout = new QHBoxLayout;
    alarmLayout->addWidget(alarmLabel);

    auto* commandLayout = new QHBoxLayout;
    commandLayout->addWidget(enableButton);
    commandLayout->addWidget(setButton);

    auto* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(displayLayout);
    mainLayout->addLayout(alarmLayout);
    mainLayout->addLayout(commandLayout);

    setLayout(mainLayout);
}

void AlarmPanel::setTimeDisplay(const QString& display) {
    timeLabel->setText(display);
}

void AlarmPanel::setAlarmDisplay(const QString& display) {
    alarmLabel->setText(display);
}

void AlarmPanel::setCommandText(const QString& command) {
    enableButton->setText(command);
}

void AlarmPanel::setDisabledStyle() {
    alarmLabel->setStyleSheet("color: gray;");
}

void AlarmPanel::setEnabledStyle() {
    alarmLabel->setStyleSheet("color: rgb(29, 135, 57);");
}
