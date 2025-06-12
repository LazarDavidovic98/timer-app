// main.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "TimerModel.h"

int main() {
    TimerModel timer;

    // Postavi početno vreme (možeš promeniti po želji)
    timer.setTime("00:00:10");

    std::cout << "Odbrojavanje počinje..." << std::endl;

    // Petlja odbrojava dok vreme ne istekne
    while (!timer.isTimeUp()) {
        std::cout << timer.getTime() << "\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        timer.timeTick();
    }

    std::cout << timer.getTime() << std::endl;
    std::cout << "Vreme je isteklo!" << std::endl;

    return 0;
}
