#pragma comment(lib, "winmm.lib")

#include "SoundEngine.h"
#include <windows.h>

void SoundEngine::playSound(const std::string& filePath) {
    PlaySoundA(filePath.c_str(), NULL, SND_FILENAME | SND_SYNC);
}
