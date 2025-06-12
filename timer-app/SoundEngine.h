#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <string>

class SoundEngine {
public:
    static void playSound(const std::string& filePath);
};

#endif // SOUNDENGINE_H

