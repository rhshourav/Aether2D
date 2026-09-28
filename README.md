# Aether2D 🌌

A custom 2D game engine built from scratch in C++, designed with a focus on modern engine architecture, memory safety, and performance. 

## 🎯 The Goal
The primary goal of Aether2D is not just to make a game, but to understand the underlying mechanics of game engines. Rather than relying on game-specific logic or deep inheritance trees, Aether2D uses a scalable **Entity Component System (ECS)** to build flexible, data-driven game objects. 

## 🛠️ Tech Stack & Toolchain
* **Language:** C++17
* **Graphics/Windowing:** SDL2 & SDL2_image
* **Architecture:** Entity Component System (ECS)
* **Compiler:** MinGW-w64 (GCC) via MSYS2
* **Environment:** Windows / VS Code

## 🗺️ Engine Development Roadmap

- [x] **Phase 1: Setup & Window Lifecycle**
  - Configured the C++ compiler (g++) and MSYS2 toolchain.
  - Linked SDL2 libraries.
  - Successfully initialized the graphics hardware and opened a window.
- [ ] **Phase 2: Core Game Loop & Time**
  - Implement a continuous `while` loop.
  - Process input events (quitting, keyboard state).
  - Integrate `std::chrono` to calculate Delta Time, decoupling game speed from hardware framerate.
- [ ] **Phase 3: Asset & Memory Management**
  - Build an Asset Manager using `std::unordered_map` for instant texture lookups.
  - Utilize C++ smart pointers (`std::unique_ptr`, `std::shared_ptr`) to prevent memory leaks and automatically clean up resources.
- [ ] **Phase 4: Entity Component System (ECS)**
  - Implement an ECS architecture to replace traditional object-oriented inheritance.
  - Create pure-data components (e.g., `TransformComponent`, `SpriteComponent`, `VelocityComponent`).
- [ ] **Phase 5: Physics & Collision**
  - Implement Axis-Aligned Bounding Box (AABB) collision detection.
  - Calculate simultaneous X and Y axis overlaps to prevent entities from passing through each other.

## 🚀 Getting Started (Windows)
To compile Aether2D using a MinGW-w64 toolchain, run the following command in the terminal:
```bash
g++ main.cpp -o engine.exe -lmingw32 -lSDL2main -lSDL2
```
Then run the executable:
```bash
.\engine.exe
```