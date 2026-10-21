# Frogs and Toads

```
              _              _
  __   ___.--'_`.          .'_`--.___   __
 ( _`.'. -   'o` )        ( 'o`   - .`.'_ )
 _\.'_'      _.-'          `-._      `_`./_
( \`. )    //\`              '/\\    ( .'/ )
 \_`-'`---'\\__,            ,__//`---'`-'_/
  \`        `-\              /-'        '/
   `                                    '
```

[ascii art credit](https://www.ludd.ltu.se/~vk/pics/ascii/ascii3.shtml)

## Assignment starter

This is the starter project for the MVC and Raylib assignment. The console game is supplied; loss detection, Raylib keyboard input, and graphical board rendering are deliberately unfinished. Students later add mouse input. Follow the assignment sheet for requirements and marks.

## Build and run

Use Visual Studio 2026 with the Desktop development with C++ workload, the v145 C++ toolset, and a compatible Windows SDK.

1. Fork this starter GitHub repository.
2. Clone your forked repository to your computer.
3. In File Explorer, open the repository folder and double-click `build-VisualStudio2026.bat`. An internet connection is required on the first run to download Raylib sources. The script generates the Visual Studio solution and project files; it does not compile the game.
4. Open the generated `.slnx` solution in Visual Studio. Its name follows the repository folder name (`FrogsAndToads.slnx` when the folder is named `FrogsAndToads`).
5. Select **Debug | x64**, then build and run. The starter runs the console game by default.

Raylib is downloaded into `build/external/raylib-master` and built from source as part of the solution. No Raylib NuGet installation is required. The download folder is ignored by Git, so each fresh clone needs the setup step.

## Game Rules

The game is played on a linear board with N squares. In the variant we will be working with, N is equal to 7. All but the center square are filled with Frogs (F) to the left and Toads (T) to the right. The goal of the game is to get all the frogs and toads to switch places.

The game is played by moving the frogs and toads, one at a time, into an empty square either by sliding into an adjacent square, or by hopping over a single piece of the opposite species into an empty one. Frogs can only move to the right and hop over toads. Toads can only move to the left and hop over frogs.

Here’s an example of two initial moves in a game that begins in this state:  
`F F F . T T T`

Move 1: The first toad slides into the empty square in the middle:  
`F F F T . T T`

Move 2: The first frog jumps over the first toad:  
`F F . T F T T`

Play continues in this manner until all the toads are on the left and all frogs on the right. The player does _not_ need to alternate between Frogs and Toads.

The winning state of the board looks like this:  
`T T T . F F F`

If, before arriving at the winning state, no further moves are possible, the player loses.

An example of a losing state:  
`. F F T F T T`

From the starting board, selecting one-based positions **5, 3, 2, 1** reaches this losing state. The unfinished starter still reports it as `Playing` until loss detection is completed. The goal board must report `Solved`, even though it also has no legal moves. Restart restores `Playing`; rejected moves and read-only queries preserve the board and status.
