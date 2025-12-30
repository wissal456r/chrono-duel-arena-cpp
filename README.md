Chrono Duel Arena

Chrono Duel Arena is a simple console-based fighting game written in C++. Players can battle each other or face an AI opponent, choosing actions each turn to attack, defend, charge energy, heal, or unleash a special move. The game features animated fights in the console using text characters and a round-based combat system.

⸻

Features
	•	Two Game Modes:
	•	Player vs Player
	•	Player vs Machine (AI)
	•	Round-Based Combat:
	•	Each match has 2 rounds.
	•	Players’ HP and Energy are tracked throughout the rounds.
	•	Winner is determined based on round wins.
	•	Player Actions:
	•	Attack: Deal damage to opponent, gain energy.
	•	Defend: Gain small energy and reduce damage from attacks.
	•	Charge: Increase energy to unlock special moves.
	•	Heal: Recover some HP (maximum 100).
	•	Special Move: Powerful attack that consumes energy.
	•	Animated Fighting Display:
	•	Fighters move toward each other and attack using ASCII art.
	•	Hit animations make fights visually dynamic.
	•	AI Opponent:
	•	The AI selects actions based on its energy level, using special moves when possible.

⸻

How to Play
	1.	Clone or download the repository.
	2.	Compile the code using a C++ compiler (tested with g++ and Visual Studio):
  g++ -o ChronoDuelArena game.cpp
  3.	Run the executable:
  ./ChronoDuelArena   # Linux/Mac
ChronoDuelArena.exe # Windows
4.	Choose a game mode:
	•	1 for Player vs Player
	•	2 for Player vs Machine
	5.	Enter player names (or let AI be Player 2).
	6.	Each player selects an action each turn.
	7.	The fight continues until round time ends or a player’s HP reaches zero.
	8.	The winner is announced at the end of 2 rounds.
  =========== CHRONO DUEL ARENA ===========
Mode: Player vs Machine | Round: 1 | Time Left: 8s

Player1 HP: 100 Energy: 0
AI       HP: 100 Energy: 0

O>            <O
/|\           /|\
/ \           / \
Hit animations and movements are displayed dynamically in the console.

⸻

Requirements
	•	C++ compiler with C++11 or higher
	•	Compatible with Windows, Linux, and macOS terminals

⸻

Future Improvements
	•	Add more rounds or a full tournament mode.
	•	Include more complex AI behaviors.
	•	Implement graphical user interface (GUI) for a more interactive experience.
	•	Add sound effects and music.

⸻

Author :
Wissal Aboulkheri & Yasmine Baba
