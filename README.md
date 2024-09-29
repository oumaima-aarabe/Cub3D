# Cub3D

## Introduction
Welcome to Cub3D, a project inspired by the classic game Wolfenstein 3D! This project is a raycasting game engine implemented in C, using the MiniLibX library for graphics. The goal is to create a simplified version of the game engine capable of rendering 3D environments from a 2D map.

## Description
Cub3D is a project that explores the fundamentals of raycasting and graphics rendering. It reads a map file representing a 2D maze and renders a 3D perspective of the environment in real-time. The project also includes features like texture mapping, sprite rendering, and basic collision detection.

## Features
- **Raycasting Engine**: Cub3D implements a basic raycasting engine to render 3D environments from a 2D map.
- **Texture Mapping**: Textures are applied to walls and sprites to enhance the visual experience.
- **Map Parsing**: The project reads a simple map file to generate the game environment dynamically.

## Getting Started
To run Cub3D on your local machine, follow these steps:

 ## Requirements

To build and run Cub3d on macOS, you need the following dependencies installed on your machine:

- **MiniLibX (mlx)**: A simple X-Window (X11) programming API for rendering graphics.

### Installing Dependencies on macOS

For macOS, you can use Homebrew to install the necessary packages:

 **Install Homebrew** (if not already installed):
    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```


### Installation
1. Clone this repository to your local machine:
   ```bash
   git clone git@github.com:oumaima-aarabe/Cub3D.git
2.compile the source code using make or make bonus to get all features

3.To run the Cub3D game, execute the following command in your terminal:

  
    ./cub3d path_to_map_file.cub
   
## Controls
- `W`: Move forward
- `A`: Strafe left
- `S`: Move backward
- `D`: Strafe right
- `Q`: Rotate left
- `E`: Rotate right
- `ESC`: Exit the game
  you can use the mouse too to move in bonus
