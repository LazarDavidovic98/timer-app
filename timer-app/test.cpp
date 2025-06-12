//// main.cpp
//#include <iostream>
//#include <thread>
//#include <chrono>
//#include "StopWatchModel.h"
//#include "TimerModel.h"
//#include "AlarmModel.h"
//#include "SoundEngine.h"
//
//int main() {
//
//    //--------- STOP WATCH MODEL ---------//
//
//    StopWatchModel stopwatch;
//
//    std::cout << "TESTIRAMO STOP WATCH" << std::endl;
//
//    // Simulacija vremena - 312 "tikova" (trebalo bi da pređe sekundu)
//    for (int i = 0; i < 312; ++i) {
//        stopwatch.timeTick();
//        std::cout << stopwatch.getTime() << "\r" << std::flush;
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//    }
//
//    std::cout << std::endl << "Finalno vreme: " << stopwatch.getTime() << std::endl;
//
//    // Test resetovanja
//    stopwatch.restartStopWatch();
//    std::cout << "Nakon resetovanja: " << stopwatch.getTime() << std::endl;
//
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//
//
//
//    //--------- TIMER MODEL TEST ---------// 
//
//    std::cout << "TESTIRAMO TIMER" << std::endl;
//    TimerModel timer;
//
//    // Postavi početno vreme (možeš promeniti po želji)
//    timer.setTime("00:00:10");
//
//    std::cout << "Odbrojavanje pocinje" << std::endl;
//
//    // Petlja odbrojava dok vreme ne istekne
//    while (!timer.isTimeUp()) {
//        std::cout << timer.getTime() << "\r" << std::flush;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        timer.timeTick();
//    }
//
//    std::cout << timer.getTime() << std::endl;
//    std::cout << "Vreme je isteklo!" << std::endl;
//    SoundEngine::playSound("resources/alarm.wav");
//   
//
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//
//
//
//
//
//    //--------- ALARM MODEL TEST ---------// 
//
//    AlarmModel alarm;
//
//    std::cout << "TESTIRAMO ALARM MODEL" << std::endl;
//
//    // Dohvatanje trenutnog sistemskog vremena koristeći localtime_s
//    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//    std::tm localTime;
//    localtime_s(&localTime, &now);  // SIGURNA verzija
//
//    // Dodajemo 5 sekundi na trenutno vreme
//    int h = localTime.tm_hour;
//    int m = localTime.tm_min;
//    int s = localTime.tm_sec + 5;
//
//    if (s >= 60) {
//        s -= 60;
//        m++;
//    }
//    if (m >= 60) {
//        m -= 60;
//        h++;
//    }
//    if (h >= 24) {
//        h = 0;
//    }
//
//    // Formatiranje alarma kao string "hh:mm:ss"
//    char buffer[9];
//    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", h, m, s);
//    std::string alarmTimeStr(buffer);
//
//    // Podesimo alarm
//    alarm.setAlarmTime(alarmTimeStr);
//    alarm.enable();
//
//    std::cout << "Alarm postavljen za: " << alarm.getAlarmTime() << std::endl;
//
//    // Proveravamo alarm svakih 500ms
//    while (true) {
//        std::string currentTime = alarm.getTime();
//        std::cout << "Trenutno vreme: " << currentTime << "\r" << std::flush;
//
//        if (alarm.isTimeUp()) {
//            std::cout << std::endl << "🔔 Alarm aktiviran!" << std::endl;
//            SoundEngine::playSound("resources/alarm.wav");
//            break;
//        }
//
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    }
//
//    getchar();
//    return 0;
//}




// GUI TEST: 

#include <QApplication>
#include <QMainWindow>
#include "StopWatchPanel.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    StopWatchPanel* panel = new StopWatchPanel;

    QObject::connect(panel, &StopWatchPanel::startClicked, []() {
        qDebug("START clicked!");
        });

    window.setCentralWidget(panel);
    window.resize(400, 200);
    window.show();

    return app.exec();
}
