# Dungeon Crawler with Qt
 
A tile-based dungeon crawler game built with C++ and Qt 6. Navigate procedurally structured dungeons, fight enemies, collect loot and traverse multiple levels through doors, ramps and portals.
 
## Features
 
- Tile-based dungeon map rendered with Qt's graphical UI
- Combat system with attack, guardian and stationary enemy controllers
- Interactive world elements: doors, pits, ramps, portals, switches and loot chests
- Multi-level progression with a level changer system
- Graph-based dungeon structure for map traversal
- Character system with active and passive states
- Custom textures loaded via Qt resource system
- Start screen and main game window
## Tech Stack
 
- **Language:** C++
- **Framework:** Qt 6.7.2
- **Build system:** qmake (`.pro` file)
- **IDE:** Qt Creator
## Requirements
 
- Qt 6.7.2 or later
- Qt Creator (recommended) or any qmake-compatible build environment
- C++17 compatible compiler
## Installation
 
1. Clone the repository:
   ```bash
   git clone https://github.com/Saugat-Pandey/dungeon-crawler-qt.git
   cd dungeon-crawler-qt
   ```
 
2. Open `DungeonCrawler.pro` in Qt Creator.
3. Select your Qt kit (Qt 6.7.2 or later) and click **Run**.
Alternatively, build from the command line:
```bash
qmake DungeonCrawler.pro
make
./DungeonCrawler
```
 
## Project Structure
 
```
dungeon-crawler-qt/
├── textures/               # Game textures
├── textures.qrc            # Qt resource file for textures
├── main.cpp                # Entry point
├── mainwindow.cpp/h/ui     # Main game window
├── startscreen.cpp/h/ui    # Start screen
├── dungeoncrawler.cpp/h    # Core game logic
├── character.cpp/h         # Player character
├── active/passive.cpp/h    # Character state system
├── graph.cpp/h             # Graph-based map structure
├── level.cpp/h             # Level representation
├── levelchanger.cpp/h      # Level transition logic
├── tile/wall/floor.cpp/h   # Tile types
├── door/pit/ramp.cpp/h     # Traversal elements
├── portal/switch.cpp/h     # Interactive elements
├── lootchest.cpp/h         # Loot system
├── attackcontroller.cpp/h  # Attack logic
├── guardiancontroller.cpp/h# Guardian enemy logic
├── stationarycontroller.cpp/h # Stationary enemy logic
├── abstractcontroller.cpp/h# Base controller class
├── random.cpp/h            # Random generation utilities
├── list.h                  # Custom list utility
└── DungeonCrawler.pro      # qmake project file
```
 
