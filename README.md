## 🐾 qt_hieronymus_desktop_pets

**qt_hieronymus_desktop_pets** is a cross-platform desktop pet application built with Qt 6 and QML. It aims to bring animated, interactive companions to your desktop environment. This project is currently in early development and not yet feature-complete. This product uses Qt under the LGPL license.
---

### 🚧 Status: Work in Progress

This repository contains the initial structure, build configuration, and basic UI components. Core features such as pet behavior, animations, and user interaction are under active development.

---

### ✨ Features (Planned)

- Animated desktop pet with idle and interactive states
- QML-based UI for smooth transitions and customization
- Cross-platform support (Windows, macOS, Linux)
- Modular resource system for avatars and menus

---

### 🛠️ Build Instructions

#### Requirements

- Qt 6.8 or newer
- CMake 3.16+
- C++11-compatible compiler

#### Steps

```bash
git clone https://github.com/Hibiki-Yomi/qt_hieronymus_desktop_pets.git
cd qt_hieronymus_desktop_pets
mkdir build && cd build
cmake ..
make
```

#### Run

```bash
./qt_hieronymus_desktop_pets
```

---

### 📁 Project Structure

```plaintext
├── CMakeLists.txt
├── main.cpp
├── Main.qml
├── MenuWindow.qml
├── Avatar.qml
├── mainwindow_events.h
├── logo.svg / logo.png / burger.svg
```

---

### 📄 License

This project is licensed under the [LGPL-2.1](LICENSE). You are free to use, modify, and distribute under the terms of this license.

---

### 🤝 Contributing

Contributions are welcome! Feel free to open issues or submit pull requests. Please follow these guidelines:

- Keep code style consistent
- Test your changes before submitting
- Modularize QML components for maintainability

---

### 🙌 Acknowledgments

Inspired by the charm of desktop companions and the flexibility of Qt. Special thanks to the Qt community and open-source contributors.
