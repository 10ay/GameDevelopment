#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcoming messages to the terminal
    std::cout<<"\n\n\n\n\n\n Gotham City's under Danger. The criminal who goes by the name of Riddler has escaped from Arkham Assylum once again";
    std::cout<<"\n\n He's resorted to using math to trouble you once again. Solve his riddles to reach the highest difficulty and defeat him";
    std::cout<<"\n\n Let's get started. You have three tries on each level.";
    std::cout<<"\n\n You are now on level" << Difficulty;
    std::cout << "\n\n Enter the correct codes to continue...\n\n";
}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declare three number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    
    const int Code_sum = CodeA + CodeB + CodeC;
    const int Code_product = CodeA * CodeB * CodeC;

    //Output Number
    std::cout << std::endl;
    std:: cout << "There are 3 numbers in the code";
    std::cout << "\n The code adds up to: " << Code_sum;
    std::cout << "\n The codes multiply to give: " << Code_product << std::endl;

    int GuessA, GuessB, GuessC;

    //Store Player Guess
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    int tries = 3;


    //Check
    if (GuessSum == Code_sum && GuessProduct == Code_product)
    {
        std::cout << "\n *** You Defeated the Riddler This time! *** ";
        return true;
    }
    else
    {
        std::cout << "\n *** The Riddler won this time. Try again. ***";
        return false;
    }
}


int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    int tries=3;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears my error
        std::cin.ignore(); //Clears the Buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std:: cout <<"\n *** Well Done! Youd defeated the Riddler! ***\n";
    return 0;
}
