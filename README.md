# MY_WORLD (CSFML GAME)

## 🌎 Project Overview

This project is a 3D impression terraforming game in 2D built using CSMLF (the C binding for SFML).
There is no particular goal, the principle being to shape your map as you like. You have two modes
available: the 'terraform' mode, which allows you to modify the terrain height, and the 'layers' mode,
which allows you to modify the texture of the tiles. You can activate these modes by clicking on
their respective buttons.

## 🎮 Controls & Gameplay

### Controls:

  #### All Modes
    Mouse scroll Up/Down - Zoom / dezoom map view
    'z' - Zoom map view                                    /!\ also a button for it
    'd' - Dezoom map view                                  /!\ also a button for it
    Left/Right arrows - Rotate the map 
    'F5' - Turn On/Off game sounds                         /!\ also a button for it
    Left Mouse Click - Click on buttons
    
  #### Terraform Mode
    Left Mouse Button – Level up a tile
    Right Mouse Buttons - Level down a tile
    '+' / '-' - Increase/Decrease map size by one tile     /!\ also a button for it
    'r' - Reset map to flat                                /!\ also a button for it

  #### Layers Mode
    Left Mouse Button - Select a texture with buttons
                      - Change texture of a tile

## 🛠️ Installation & Compilation

### Prerequisites

Ensure you have CSFML installed on your system:

    sudo apt-get install libcsfml-dev  # For Debian/Ubuntu
    brew install csfml                 # For macOS (Homebrew)

### Running the Game

Run the compiled executable:

./my_hunter

## 📂 Project Structure
    
        ├── audios/                        # Sound effects and background music
        ├── graphics/                      # Sprites and textures
        │   ├── panel.png
        │   ├── buttons.png
        │   ├── clicked/                       # Clicked buttons sprites
        │   ├── hover/                         # Hover buttons sprites
        │   ├── idle/                          # Idle buttons sprites
        │   └── textures/                      # textures sprites
        ├── include/                       # Header files
        │   └── my_world.h                     # main header
        ├── src/                           # Game source code 
        │   ├── button_clicked.c               # Handle clicks on buttons
        │   ├── camera_view.c                  # Handle map rotation
        │   ├── check_clicks.c                 # Handle click detection
        │   ├── click_quit.c                   # Handle exit
        │   ├── click_terraform.c              # Handle move up/down terrain tile
        │   ├── create_buttons.c               # Handle creating buttons
        │   ├── draw_buttons.c                 # Handle drawing all user interface
        │   ├── draw_map.c                     # Handle drawing map
        │   ├── duplicate_map.c                # Handle map duplication when applies a modification
        │   ├── event.c                        # Handle game events
        │   ├── free.c                         # Free all (map, tile, textures, ...)
        │   ├── free_resources.c               # Free all prgram structs
        │   ├── help.c                         # Handle the help panel
        │   ├── hover.c                        # Handle buttons' hover state
        │   ├── init_buttons.c                 # Init all buttons to display
        │   ├── init_resources.c               # Init all program structs
        │   ├── main.c                         # Entry point
        │   ├── resize_map.c                   # Handle resizing map (+/- buttons)
        │   ├── sounds.c                       # Handle all sound effects and music
        │   ├── terraform_mode.c               # Handle terraform mode
        │   ├── texture_loader.c               # Load all textures when needed
        │   ├── texture_mode.c                 # Handle textures/layers mode
        │   ├── texture_tile.c                 # Handle switching tile's texture
        │   ├── tile.c                         # Calculate tile positions
        │   ├── tridim_to_bidim.c              # Get a bidimensional map from a tridimensional
        │   ├── view_mode.c                    # Handle view mode and its functionalities
        │   └── zoom_dezoom.c                  # Handle zoom/dezoom view map
        ├── Makefile                       # Build script
        ├── README.md                      # Project documentation
        └── my_world                       # Executable to run

## 🖼️ Assets Used

Sprites: Buttons, game banner, help panel, tile textures.

Sounds: Button clicks sounds and background music.

## 👨‍💻 Author

Arthur Vignes – Developed for EPITECH 2024 (B-MUL-100 Project).

## 🏛️ License

This project is completely free to use.
