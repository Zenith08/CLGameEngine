# C++ Command Line Games

C++ is one of the most powerful programming languages in the world*. Despite this, achieving visual output is extremly challenging and achieving cross-platform visuals is borderline impossible without an expansive library or framework.

The Command Line Game Engine attempts to solve this by providing the tools needed to create a game using only the command prompt window for output.

## The Library
Taking inspiration from the Unity game engine, all a user needs to do to create a game with this project is provide their own `GameState` object, extending the built in class. Here, they can define any fields or information they need to store like player score, or other relevent topics.
Each game can also have a list of `GameObjects`. Each Game Object defines a thing in the world and can have its own behaviour, including movement, collision, and animation. Upon loading a Game State, the necessary GameObjects should be defined and added to the world. Then, the game will call the `tick` and `render` methods of the GameState allowing easy drawing to the screen.

## Games
### Dodgeball
![Easy Mode](/docs/dodgeball.png) ![Hard Mode](/docs/dodgeball-hard.png)
Dodgeball is a simple game where the player plays as a dot on the screen. The goal is to avoid the large ball for as long as possible and gain a high score. Thanks to a persistance system, the high score is even saved for the next player.
### Space Invaders
![Space Invaders](/docs/space-invaders.png)
Based on the classic arcade game, this rendition of Space Invaders was designed to showcase the flexability and expandability of this game engine. Featuring animated enemies, shields with limited durability, and more, this game shows the extent of what is possible with a basic understanding of programming, and the command line.
