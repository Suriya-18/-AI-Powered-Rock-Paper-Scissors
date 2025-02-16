#include <iostream>
#include <ctime>
using namespace std;

string choices[] = {"Rock", "Paper", "Scissors"};
int winCount = 0, lossCount = 0;

string getAIChoice() {
    srand(time(0));
    if (winCount > lossCount) return choices[1];  // AI adapts and chooses Paper if losing
    return choices[rand() % 3];
}

string determineWinner(string player, string ai) {
    if (player == ai) return "It's a tie!";
    if ((player == "Rock" && ai == "Scissors") || 
        (player == "Scissors" && ai == "Paper") || 
        (player == "Paper" && ai == "Rock")) {
        winCount++;
        return "You win!";
    }
    lossCount++;
    return "AI wins!";
}

int main() {
    string playerChoice;
    cout << "Rock-Paper-Scissors Game! Type 'Rock', 'Paper', or 'Scissors' (or 'exit' to stop).\n";

    while (true) {
        cout << "Your choice: ";
        cin >> playerChoice;
        if (playerChoice == "exit") break;

        string aiChoice = getAIChoice();
        cout << "AI chose: " << aiChoice << endl;
        cout << determineWinner(playerChoice, aiChoice) << endl;
    }

    return 0;
}
