#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;
// PLAYER 
struct Player {
    string name;
    int hp = 100;
    int energy = 0;
    int roundWins = 0;
};
//CLEAR SCREEN 
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// DRAW
void drawFight(Player &p1, Player &p2, int leftPos, int rightPos, bool hit,
               string mode, int round, int timeLeft) {
    cout << "=========== CHRONO DUEL ARENA ===========\n";
    cout << "Mode: " << mode
         << " | Round: " << round
         << " | Time Left: " << timeLeft << "s\n\n";
    cout << p1.name << " HP: " << p1.hp << " Energy: " << p1.energy << endl;
    cout << p2.name << " HP: " << p2.hp << " Energy: " << p2.energy << endl;
    cout << "\n";
    string L(leftPos, ' ');
    int gapSize = rightPos - leftPos - 18;
    if (gapSize < 0) gapSize = 0;
    string GAP(gapSize, ' ');
    if (hit) {
        cout << L << "O>==💥==<==💥==<O\n";
        cout << L << "/|\\            /|\\\n";
        cout << L << "/ \\            / \\\n";
    } else {
        cout << L << "O>            " << GAP << "<O\n";
        cout << L << "/|\\           " << GAP << "/|\\\n";
        cout << L << "/ \\           " << GAP << "/ \\\n";
    }
}
//ACTIONS 
int chooseAction(Player &p) {
    int c;
    cout << "\n" << p.name << " choose action:\n";
    cout << "1.Attack  2.Defend  3.Charge  4.Heal  5.Special\n";
    cin >> c;
    return c;
}
void applyAction(Player &a, Player &d, int action) {
    switch (action) {
        case 1: d.hp -= 8; a.energy += 2; break;
        case 2: a.energy += 1; break;
        case 3: a.energy += 3; break;
        case 4:
            a.hp += 5;
            if (a.hp > 100) a.hp = 100;
            break;
        case 5:
            if (a.energy >= 10) {
                d.hp -= 20;
                a.energy -= 10;
            }
            break;
    }
    if (d.hp < 0) d.hp = 0;
}
//AI 
int aiChooseAction(Player &ai) {
    if (ai.energy >= 10) return 5;
    return rand() % 4 + 1;
}
// PLAY ONE ROUND 
void playRound(Player &p1, Player &p2, int round, int modeChoice, string mode) {
    p1.hp = 100;
    p2.hp = 100;
    p1.energy = 0;
    p2.energy = 0;
    const int ROUND_TIME = 10;
    auto roundStart = steady_clock::now();
    while (p1.hp > 0 && p2.hp > 0) {
        int timeLeft = ROUND_TIME -
            duration_cast<seconds>(steady_clock::now() - roundStart).count();
        if (timeLeft <= 0) break;
        int leftPos = 2, rightPos = 42;
        //Show idle fighters
        clearScreen();
        drawFight(p1, p2, leftPos, rightPos, false, mode, round, timeLeft);
        //Choose actions FIRST
        int a1 = chooseAction(p1);
        int a2 = (modeChoice == 1) ? chooseAction(p2) : aiChooseAction(p2);
        // Move fighters
        while (leftPos < 18 && rightPos > 26) {
            clearScreen();
            drawFight(p1, p2, leftPos, rightPos, false, mode, round, timeLeft);
            leftPos++;
            rightPos--;
            this_thread::sleep_for(milliseconds(80));
        }
        //Apply actions
        applyAction(p1, p2, a1);
        applyAction(p2, p1, a2);
        //Hit animation
        clearScreen();
        drawFight(p1, p2, leftPos, rightPos, true, mode, round, timeLeft);
        this_thread::sleep_for(milliseconds(400));
    }
    // Round Result 
    clearScreen();
    cout << "========= ROUND " << round << " RESULTS =========\n";
    cout << p1.name << " HP: " << p1.hp << endl;
    cout << p2.name << " HP: " << p2.hp << endl;
    if (p1.hp > p2.hp) {
        cout << p1.name << " wins Round " << round << "!\n";
        p1.roundWins++;
    } else if (p2.hp > p1.hp) {
        cout << p2.name << " wins Round " << round << "!\n";
        p2.roundWins++;
    } else {
        cout << "Round " << round << " is a DRAW!\n";
    }
    this_thread::sleep_for(seconds(3));
}
//  MAIN 
int main() {
    srand(time(0));
    cout << "==== CHRONO DUEL ARENA ====\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Machine\n";
    cout << "Choose mode: ";
    int modeChoice;
    cin >> modeChoice;
    string mode = (modeChoice == 1)
        ? "Player vs Player"
        : "Player vs Machine";
    Player p1, p2;
    cout << "Enter Player 1 name: ";
    cin >> p1.name;

    if (modeChoice == 1) {
        cout << "Enter Player 2 name: ";
        cin >> p2.name;
    } else {
        p2.name = "AI";
    }
    playRound(p1, p2, 1, modeChoice, mode);
    playRound(p1, p2, 2, modeChoice, mode);
    clearScreen();
    cout << "=========== FINAL RESULTS ===========\n";
    cout << p1.name << " Round Wins: " << p1.roundWins << endl;
    cout << p2.name << " Round Wins: " << p2.roundWins << endl;

    if (p1.roundWins > p2.roundWins)
        cout << "FINAL WINNER: " << p1.name << endl;
    else if (p2.roundWins > p1.roundWins)
        cout << "FINAL WINNER: " << p2.name << endl;
    else
        cout << "FINAL RESULT: DRAW\n";

    return 0;
}