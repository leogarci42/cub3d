# cub3D - Raycasting Engine

A 3D maze exploration game built using raycasting techniques, inspired by classic games like Wolfenstein 3D. This project is created as part of the 42 curriculum.

## Overview

cub3D is a real-time raycasting engine that renders a 3D first-person view of a 2D maze using textured walls. The project demonstrates core graphics programming concepts including ray casting, perspective projection, and texture mapping.

## Features

- **Raycasting Rendering**: Real-time ray casting with per-pixel wall rendering
- **Texture Mapping**: Full support for textured walls (North, South, East, West)
- **Supersampling Anti-Aliasing (SSAA)**: 2x supersampling for enhanced visual quality
- **Smooth Navigation**: Mouse and keyboard controls for smooth movement and rotation
- **Map Parsing**: Support for custom maze maps defined in `.cub` format

## Requirements

- **Linux** (MinilibX for Linux)
- **GCC** compiler with C99 standard
- **Make**
- **MinilibX graphics library** (included in the project)

## Building the Project

```bash
make              # Build the project
make clean        # Remove object files
make fclean       # Remove all generated files
make re          # Clean and rebuild
```

The build creates an executable named `cub3D`.

## Usage

```bash
./cub3D <map_file.cub>
```

### Map Format

Map files should be in `.cub` format with the following structure:

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
EA ./path/to/east_texture.xpm
WE ./path/to/west_texture.xpm

F 220,100,0       # Floor color (RGB)
C 225,30,0        # Ceiling color (RGB)

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

- `NO`, `SO`, `EA`, `WE`: Texture paths for each wall direction
- `F`: Floor color in RGB format
- `C`: Ceiling color in RGB format
- `1`: Wall
- `0`: Empty space
- `N`, `S`, `E`, `W`: Player starting position and direction

### Controls

| Command | Action |
|---------|--------|
| `W` | Move forward |
| `A` | Strafe left |
| `S` | Move backward |
| `D` | Strafe right |
| `Left Arrow` | Turn left |
| `Right Arrow` | Turn right |
| `ESC` | Exit the program |

## Project Structure

```
cub/
├── Makefile                 # Build configuration
├── includes/
│   └── cub3d.h             # Main header file
├── all_libft/              # Custom libraries
│   ├── libft/              # Standard C library functions
│   ├── ft_printf/          # Custom printf implementation
│   ├── get_next_line/      # Line reading utility
│   └── all_libft.h         # Library header
├── src/
│   ├── cub3d.c             # Main entry point
│   ├── parsing/            # Map and configuration parsing
│   │   ├── parsing.c       # Main parsing logic
│   │   ├── checker.c       # Map validation
│   │   ├── parse_map.c     # Map parsing utilities
│   │   └── ...
│   └── exec/               # Rendering and execution
│       ├── ft_raycasting.c # Main raycasting logic
│       ├── ft_raycast_core.c # Core ray casting algorithms
│       ├── ft_raycasting_draw.c # Screen rendering
│       ├── ft_mlx.c        # MinilibX interface
│       ├── ft_ssaa.c       # Supersampling anti-aliasing
│       ├── key_handling.c  # Keyboard input handling
│       └── ...
├── minilibx-linux/         # MinilibX graphics library
└── textures/               # Texture resources
```

## Technical Details

### Raycasting Algorithm

The engine uses a traditional raycasting approach:

1. **Ray Casting**: For each column of pixels, cast a ray from the player's position
2. **Wall Detection**: Determine the distance to the nearest wall intersection
3. **Texture Mapping**: Map the appropriate texture based on wall direction
4. **Column Rendering**: Draw a vertical line of pixels from the texture at the correct height

### Supersampling Anti-Aliasing

To improve visual quality, the engine renders at 2x resolution (3840×2160) and downsamples to the display resolution (1920×1080), effectively performing anti-aliasing.

### Coordinate System

- Player position: `(x, y)` in the 2D maze
- Player angle: Direction the player is facing (in radians)
- Field of View (FOV): 80 degrees for realistic perspective

## Custom Libraries

### libft
A custom implementation of standard C library functions including:
- Memory functions: `memset`, `memcpy`, `memcmp`, `memmove`, `memchr`, `calloc`
- String functions: `strlen`, `strchr`, `strdup`, `strdup`, `strjoin`, `strsplit`, etc.
- Character functions: `isalpha`, `isdigit`, `toupper`, `tolower`, etc.
- List operations: Linked list manipulation functions

### ft_printf
A custom printf implementation supporting:
- Format specifiers: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
- Flags: `-`, `0`, `#`, `+`, ` `
- Width and precision specifications

### get_next_line
A function to read lines from a file descriptor, handling buffer management and edge cases.

## Authors

- **leogarci** (leogarci@student.42.fr)
- **salsoysa**

## License

This project is part of the 42 curriculum.

## Troubleshooting

- **MinilibX not found**: Ensure MinilibX is properly installed in the `minilibx-linux` directory
- **Texture loading errors**: Verify that texture paths in the `.cub` file are correct and textures are in XPM format
- **Performance issues**: The `-O2 -march=native` flags in the Makefile provide optimizations; ensure your compiler is recent

## Notes

- The project uses the `-march=native` flag for CPU-specific optimizations
- Texture files must be in XPM format (`.xpm`)
- Wall heights are calculated based on ray distance to create perspective
