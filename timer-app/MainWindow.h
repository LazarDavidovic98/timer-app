#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTabWidget>

#include "TimerModel.h"
#include "StopWatchModel.h"
#include "AlarmModel.h"

#include "TimerPanel.h"
#include "StopWatchPanel.h"
#include "AlarmPanel.h"
#include "SplitPanel.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    void setupUI();
    void connectPanels();
    TimerModel timerModel;
    StopWatchModel stopWatchModel;
    AlarmModel alarmModel;

    TimerPanel* timerPanel;
    StopWatchPanel* stopWatchPanel;
    AlarmPanel* alarmPanel;
    SplitPanel* splitPanel;

    QTimer* swingTimerTicker;
    QTimer* swingStopWatchTicker;
    QTimer* alarmTicker;
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    // Timer
    void handleTimerStartStop();
    void handleTimerReset();
    void handleTimerSet();
    void updateTimer();

    // Stopwatch
    void handleStopWatchStartStop();
    void handleStopWatchReset();
    void handleStopWatchSplit();
    void handleStopWatchShow();
    void updateStopwatch();

    // Alarm
    void handleAlarmToggle();
    void handleAlarmSet();
    void updateAlarm();

    // Split
    void handleSplitDeleteAll();

private:



};

#endif // MAINWINDOW_H
