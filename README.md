
# ⏱ Timer Application

This project is a cross-platform desktop application developed using **C++** and **Qt6**, providing functionality for three core timekeeping tools:
- **Timer** – counts down from a given time.
- **Stopwatch** – measures elapsed time with split functionality.
- **Alarm** – alerts the user at a set time.

## 🗂 Project Structure

```
timer-app/
├── resources/               # Icons and alarm sound
│   ├── alarm-clock.png
│   ├── stopwatch.png
│   ├── time.png
│   ├── alarm.wav
│   ├── properties.txt
│   └── resources.qrc
├── src/                     # Source and header files
│   ├── AlarmModel.{h,cpp}
│   ├── AlarmPanel.{h,cpp}
│   ├── MainWindow.{h,cpp}
│   ├── SoundEngine.{h,cpp}
│   ├── SplitPanel.{h,cpp}
│   ├── StopWatchModel.{h,cpp}
│   ├── StopWatchPanel.{h,cpp}
│   ├── TimerModel.{h,cpp}
│   ├── TimerPanel.{h,cpp}
│   └── main.cpp
├── CMakeLists.txt           # CMake build configuration
├── timer-app.sln            # Visual Studio solution file
└── README.md
```

## How to Build

### Requirements
- **Qt 6.x** (e.g. 6.6.3) with `mingw_64` or MSVC toolchain
- **CMake >= 3.14**
- **Visual Studio 2022** or **Visual Studio Code**
- Compiler: MinGW or MSVC

### Build with CMake
```bash
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH="C:/Qt/6.6.3/mingw_64"
cmake --build .
```

### Run
```bash
./TimeApp.exe
```

## Features

-  Start, Stop, Reset for Timer and Stopwatch
-  Alarm scheduling with toggle
-  Display of time splits for Stopwatch
-  Resource loading via `.qrc` file (icons, sounds)
-  Modular architecture

## Notes

- Font rendering warnings (e.g., `CreateFontFaceFromHDC()`) may occur on Windows. They do not impact functionality.
- If using Visual Studio, make sure the `.qrc` file is set to `Qt Resource File` in properties.

---

**Detailed documentation is available here**: [Documentation](docs/Documentation.md)

Developed as an educational project to explore GUI development in C++ using Qt.
