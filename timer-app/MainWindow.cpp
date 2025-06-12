#include "MainWindow.h"
#include "TimerModel.h"
#include <QVBoxLayout>
#include <QInputDialog>
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    swingTimerTicker = new QTimer(this);
    swingStopWatchTicker = new QTimer(this);
    alarmTicker = new QTimer(this);

    timerPanel = new TimerPanel(this);
    stopWatchPanel = new StopWatchPanel(this);
    alarmPanel = new AlarmPanel(this);
    splitPanel = new SplitPanel(this);

    setupUI();
    connectPanels();

    connect(alarmTicker, &QTimer::timeout, this, &MainWindow::updateAlarm);
    alarmTicker->start(1000);
}
void MainWindow::setupUI() {
    timerPanel = new TimerPanel(this);
    stopWatchPanel = new StopWatchPanel(this);
    alarmPanel = new AlarmPanel(this);
    splitPanel = new SplitPanel(this);

    timerPanel->setDisplay(QString::fromStdString(timerModel.getTime()));

    QTabWidget* tabs = new QTabWidget(this);
    tabs->addTab(timerPanel, QIcon(":/resources/time.png"), "Timer");
    tabs->addTab(stopWatchPanel, QIcon(":/resources/stopwatch.png"), "StopWatch");
    tabs->addTab(alarmPanel, QIcon(":/resources/alarm-clock.png"), "Alarm");


    QWidget* central = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(central);
    layout->addWidget(tabs);
    setCentralWidget(central);

    setWindowTitle("Timer");
    resize(400, 300);
}

void MainWindow::connectPanels() {
    connect(timerPanel->getStartButton(), &QPushButton::clicked, this, &MainWindow::handleTimerStartStop);
    connect(timerPanel->getResetButton(), &QPushButton::clicked, this, &MainWindow::handleTimerReset);
    connect(timerPanel->getSetButton(), &QPushButton::clicked, this, &MainWindow::handleTimerSet);

    connect(stopWatchPanel->getStartButton(), &QPushButton::clicked, this, &MainWindow::handleStopWatchStartStop);
    connect(stopWatchPanel->getResetButton(), &QPushButton::clicked, this, &MainWindow::handleStopWatchReset);
    connect(stopWatchPanel->getSplitButton(), &QPushButton::clicked, this, &MainWindow::handleStopWatchSplit);
    connect(stopWatchPanel->getShowButton(), &QPushButton::clicked, this, &MainWindow::handleStopWatchShow);

    connect(alarmPanel->getEnableButton(), &QPushButton::clicked, this, &MainWindow::handleAlarmToggle);
    connect(alarmPanel->getSetButton(), &QPushButton::clicked, this, &MainWindow::handleAlarmSet);

    connect(splitPanel->getDeleteAllButton(), &QPushButton::clicked, this, &MainWindow::handleSplitDeleteAll);

    connect(swingTimerTicker, &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(swingStopWatchTicker, &QTimer::timeout, this, &MainWindow::updateStopwatch);
}

void MainWindow::handleTimerStartStop() {
    QString command = timerPanel->getCommandText();
    if (command == "Start") {
        timerPanel->setCommandText("Stop");
        swingTimerTicker->start(1000);
    }
    else {
        timerPanel->setCommandText("Start");
        swingTimerTicker->stop();
    }
}

void MainWindow::handleTimerReset() {
    timerModel.restartTimer();
    timerPanel->setDisplay(QString::fromStdString(timerModel.getTime()));
}

void MainWindow::handleTimerSet() {
    bool ok;
    QString text = QInputDialog::getText(this, "Input timer time", "Set time:", QLineEdit::Normal, QString::fromStdString(timerModel.getTime()), &ok);
    if (ok && !text.isEmpty()) {
        timerModel.setTime(text.toStdString());
        timerPanel->setDisplay(QString::fromStdString(timerModel.getTime()));
    }
}

void MainWindow::updateTimer() {
    if (timerModel.isTimeUp()) {
        swingTimerTicker->stop();
        timerModel.restartTimer();
        timerPanel->setDisplay(QString::fromStdString(timerModel.getTime()));
        timerPanel->setCommandText("Start");
        // SoundEngine::playSound(); // implementirati
    }
    else {
        timerModel.timeTick();
        timerPanel->setDisplay(QString::fromStdString(timerModel.getTime()));
    }
}

void MainWindow::handleStopWatchStartStop() {
    QString command = stopWatchPanel->getCommandText();
    if (command == "Start") {
        stopWatchPanel->setCommandText("Stop");
        stopWatchPanel->enableSplitButton();
        swingStopWatchTicker->start(16);
    }
    else {
        stopWatchPanel->setCommandText("Start");
        stopWatchPanel->disableSplitButton();
        swingStopWatchTicker->stop();
    }
}

void MainWindow::handleStopWatchReset() {
    stopWatchModel.restartStopWatch();
    stopWatchPanel->setDisplay(QString::fromStdString(stopWatchModel.getTime()));
}

void MainWindow::handleStopWatchSplit() {
    splitPanel->add(QString::fromStdString(stopWatchModel.getTime()));
    stopWatchPanel->setDisplayBackground(Qt::red);
    QTimer::singleShot(100, this, [this]() {
        stopWatchPanel->setDisplayBackground(Qt::transparent);
        });
}

void MainWindow::handleStopWatchShow() {
    stopWatchPanel->disableShowButton();
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Split");
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(splitPanel);
    dialog->setLayout(layout);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(dialog, &QDialog::finished, this, [this]() {
        stopWatchPanel->enableShowButton();
        });
    dialog->exec();
}

void MainWindow::updateStopwatch() {
    stopWatchModel.timeTick();
    stopWatchPanel->setDisplay(QString::fromStdString(stopWatchModel.getTime()));
}

void MainWindow::handleAlarmToggle() {
    QString command = alarmPanel->getCommandText();
    if (command == "Enable") {
        alarmModel.enable();
        alarmPanel->setCommandText("Disable");
        alarmPanel->setEnabled(true);
    }
    else {
        alarmModel.disable();
        alarmPanel->setCommandText("Enable");
        alarmPanel->setDisabled(true);
    }
}

void MainWindow::handleAlarmSet() {
    bool ok;
    QString time = QInputDialog::getText(this, "Input alarm time", "Set time:", QLineEdit::Normal, QString::fromStdString(alarmModel.getAlarmTime()), &ok);
    if (ok && !time.isEmpty()) {
        alarmModel.setAlarmTime(time.toStdString());
        alarmPanel->setAlarmDisplay(QString::fromStdString(alarmModel.getAlarmTime()));
    }
}

void MainWindow::updateAlarm() {
    alarmPanel->setTimeDisplay(QString::fromStdString(alarmModel.getTime()));
    if (alarmModel.isTimeUp()) {
        // SoundEngine::playSound(); // implementirati
    }
}

void MainWindow::handleSplitDeleteAll() {
    splitPanel->deleteAll();
}
