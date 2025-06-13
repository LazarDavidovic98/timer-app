
# 🧾 Documentation: Timer Qt Application

This document outlines the design, architecture, and usage of the C++ Qt Timer Application.

---

## 1. Project Overview

This application integrates three timekeeping functionalities:
- Timer: Counts down from a user-defined value.
- Stopwatch: Counts up, supports splits.
- Alarm: Triggers at user-defined time.

Technologies used:
- **C++17**
- **Qt6 (Widgets, Core, GUI)**
- **CMake** for build management

---

## 🗂 2. File and Folder Structure

- **resources/**: Holds PNG icons (`time.png`, `alarm-clock.png`, `stopwatch.png`), a WAV file (`alarm.wav`), a config file (`properties.txt`), and a Qt `.qrc` file.
- **src/**:
  - `main.cpp`: Application entry point.
  - `MainWindow.*`: Central controller, connects panels and handles timer events.
  - `AlarmModel.*`, `TimerModel.*`, `StopWatchModel.*`: Business logic classes.
  - `AlarmPanel.*`, `TimerPanel.*`, `StopWatchPanel.*`, `SplitPanel.*`: UI classes for displaying and controlling the features.
  - `SoundEngine.*`: Uses WinAPI to play alarm sounds.

---

## 3. Core Components

### 3.1 `MainWindow`

- Initializes all timers (`QTimer` objects).
- Calls `setupUI()` to add all panels into a `QTabWidget`.
- Uses `connectPanels()` to wire signals/slots.

```cpp
MainWindow::MainWindow(QWidget* parent)
{
    swingTimerTicker = new QTimer(this);
    alarmTicker = new QTimer(this);
    setupUI();
    connectPanels();
}
```

---

### 3.2 `TimerModel`

- Stores timer values and persists to `resources/properties.txt`.
- Handles countdown with `timeTick()`.

### 3.3 `StopWatchModel`

- Increments milliseconds/seconds/minutes.
- Used with high-frequency timer tick (every 16ms).

### 3.4 `AlarmModel`

- Compares system time to stored alarm value.
- Triggers playback with `SoundEngine::playSound(...)`.

---

## 4. Resources

- Resources are declared via `resources.qrc` and accessed using `:/resources/<filename>` syntax.
```xml
<RCC>
  <qresource prefix="/resources">
    <file>resources/time.png</file>
    <file>resources/alarm-clock.png</file>
    <file>resources/stopwatch.png</file>
    <file>resources/alarm.wav</file>
  </qresource>
</RCC>
```

---

##  5. Usage Guide

### Timer Tab:
1. Click **Set** to input time.
2. Click **Start** to begin countdown.
3. Click **Reset** to reload last saved value.

### Stopwatch Tab:
1. Click **Start** to begin measuring.
2. Use **Split** to record laps (displays in dialog).
3. **Reset** stops and clears.

### Alarm Tab:
1. Click **Set** to define trigger time.
2. Enable or disable alarm.

---

##  6. Known Issues

-  If alarm sound is not heard, check file path or sound driver.
-  If icons are not visible in Visual Studio, ensure `.qrc` is properly added and resource paths are correct.
-  Font fallback warnings may appear in terminal; they are not critical.

---

##  7. Build Instructions

```bash
cmake -DCMAKE_PREFIX_PATH="C:/Qt/6.6.3/mingw_64" ..
cmake --build .
```

If building in **Visual Studio**:
- Add `resources.qrc` via “Add → Existing Item”, set its type to “Qt Resource File”.
- Right-click project → Properties → Qt Project Settings → Enable Qt modules.

---

## Author

Lazar Davidovic – [GitHub Profile](https://github.com/LazarDavidovic98)

---

**MIT License** – Feel free to reuse, extend, or contribute!
