#include <iostream>
#include <chrono>
#include <thread>

//waits seconds amount of time
void sleep(int seconds) {
    std::time_t start = std::time(nullptr);
    std::time_t end = start + seconds;

    while (std::time(nullptr) < end) {}
}

//fancy
enum symbols{rock, paper, scissors};

//parent player class
class player {

protected:

//variables
std::string name;
symbols weapon;
unsigned int score = 0;

//inherited method
virtual void choose() = 0;

static void compare(player& player1, player& player2) {

    //all ditto cases
    if(player1.weapon == player2.weapon) {
        std::cout << "Both players draw";
    }
    //rocks vs scissors
    else if(player1.weapon == rock && player2.weapon == scissors){
        std::cout << player1.name << " wins over " << player2.name << "\n";
        player1.score++;
    } else if(player2.weapon == rock && player1.weapon == scissors) {
        std::cout << player2.name << " wins over " << player1.name << "\n";
        player2.score++;
    }
    
    //rocks vs paper
    else if(player2.weapon == rock && player1.weapon == paper) {
        std::cout << player1.name << " wins over " << player2.name << "\n";
        player1.score++;
    } else if(player1.weapon == rock && player2.weapon == paper) {
        std::cout << player2.name << " wins over " << player1.name << "\n";
        player2.score++;
    }

    //papers vs scissors
    else if(player2.weapon == scissors && player1.weapon == paper) {
        std::cout << player2.name << " wins over " << player1.name << "\n";
        player2.score++;
    }
    else if(player1.weapon == scissors && player2.weapon == paper) {
        std::cout << player1.name << " wins over " << player2.name << "\n";
        player1.score++;
    } else {
        std::cout << "something went wrong lol\n";
    }
}

public:
//actually plays the game
static void play(player& player1, player& player2) {
    std::cout << "\n\nPlaying a game of rock paper scissors!:\n\n";

    sleep(1);

    //player1 choice
    std::cout << player1.name << "'s choice:\n\n";
    player1.choose();

    sleep(1);

    std::cout << "\n\n\n";

    //player2 choice
    std::cout << player2.name << "'s choice:\n\n";
    player2.choose();

    sleep(1);

    std::cout << "\n\n\n";

    //compares and spews results
    compare(player1, player2);

    sleep(1);

    std::cout << "\n\n\n";

    //scores
    std::cout << "scores: \n" << player1.name << ": " << player1.score << "\n" << player2.name << ": " << player2.score << "\n";


}

};

//the class the user uses
class user : public player {

void choose() override {
    std::string in;

    while(true){
        sleep(1);

        std::cout << "\n\n\nPlease choose one of the options:\nrock\npaper\nscissors\n\n";
        std::cin >> in;

        sleep(1);

        if(in == "rock" || in == "paper" || in == "scissors"){
            break;
        } else {
            std::cout << "\n\nYou chose an incorrect option, please choose a valid option\n\n";
            sleep(1);
        }
    }
    if(in == "rock"){
        this->weapon = rock;
    } else if(in == "paper"){
        this->weapon = paper;
    } else {
        this->weapon = scissors;
    }
}

public:

//user constructor
user(std::string nameOf) {
    this->name = nameOf;
}

};

//the class the ai plays with
class ai : public player {

    void choose() override {
        int random = rand() % 3;

        if(random == 0) {
            std::cout << "ai chose rock\n";
            weapon = rock;
        }
        else if(random == 1) {
            std::cout << "ai chose paper\n";
            weapon = paper;
        }
        else {
            std::cout << "ai chose scissors\n";
            weapon = scissors;
        }
    }

public:

//ai constructor
ai() {
    this->name = "AI";
}

};

//main function
int main() {

//gets user to choose name
std::string name;
std::cout << "What is your name?:\n";
std::cin >> name;

//creates user
user the_user = user(name);

//creates ai
ai the_ai = ai();

//plays 10 rounds of game
std::cout << "\n\n\nLet's play 10 rounds!\n\n\n";
for(int i = 0; i < 10; i++){

    std::cout << "\n\nround " << i + 1 << "\n\n";

    sleep(1);

    player::play(the_user, the_ai);

    sleep(1);
}

//end of game!!!!
sleep(1);
std::cout << "\n\nend of game!\n\n";

return 0;
}
