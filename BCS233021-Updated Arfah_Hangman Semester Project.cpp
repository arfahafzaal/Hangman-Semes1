#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;
void game_instructions();
void start();
string randomiser(string[], int);
void defaulthangman();
void punishedman(int);
void punishedman_hard(int);
void enterCategoryandLevel(string&);
string hideword(const string&);
char Guessesinput(bool[], int);
void recordGuessedLetter(char letter, bool guessedLetters[]);
string guess(const string word, char userInput, string& displayhidden, bool& correctguess, int& wrongattempts);
void easymode(const string&);
void mediummode(const string&);
void hardmode(const string&);
void playCorrectSound() {
    Beep(1000, 500);  // Example: Beep at 1000 Hz for 500 milliseconds
}

void playIncorrectSound() {
    Beep(500, 500);   // Example: Beep at 500 Hz for 500 milliseconds
}




// category animals
string animals_easy[10] = { "lion", "deer", "wolf", "duck", "goat", "dog", "cat", "bear", "hen", "bird" };
string animals_medium[10] = { "elephant", "kangaroo", "turtle", "cheetah", "ostrich", "koala", "jaguar", "sloth", "snake" };
string animals_hard[10] = { "chameleon", "meerkat", "hippopotamus", "wolverine", "thinoceros", "capybara", "antelope", "gazelle", "aardvark" };
// category countries
string countries_easy[10] = { "usa", "canada", "uk", "india", "china", "brazil", "france", "japan", "mexico", "australia" };
string countries_medium[10] = { "argentina", "nigeria", "russia", "germany", "egypt", "italy", "spain", "turkey", "southkorea", "thailand" };
string countries_hard[10] = { "mongolia", "azerbaijan", "namibia", "kyrgyzstan", "tajikistan", "bhutan", "mauritania", "vanuatu", "comoros", "suriname" };
// category movies
string movies_easy[10] = { "avatar", "toy story", "finding nemo", "shrek", "frozen", "moana", "coco", "aladdin", "cars", "zootopia" };
string movies_medium[10] = { "inception", "interstellar", "black panther", "the dark knight", "gravity", "forrest gump", "gladiator", "pulp fiction", "eternal sunshine", "la la land" };
string movies_hard[10] = { "the shawshank redemption", "schindler's list", "citizen kane", "casablanca", "gone with the wind", "lawrence of arabia", "apocalypse now", "blade runner", "inglourious basterds", "the matrix" };


int main()
{
            
    game_instructions();
    start();
    defaulthangman();
    string og_word;
    enterCategoryandLevel(og_word); //this is giving me the final word which is randomized but not yet hidden


    return 0;
}

void game_instructions() {
    cout << "\033[1;32m";
    cout << "                  ***************************************\n";
    cout << "                  *                                     *\n";
    cout << "                  *          Hangman Instructions       *\n";
    cout << "                  *                                     *\n";
    cout << "                  ***************************************\n\n";
    cout << "\033[0m";


    cout << "  1. Guess the correct letters of a hidden word before the hangman is fully drawn.\n";
    cout << "  2. Choose from three categories: Animals, Countries, or Movies.\n";
    cout << "  3. Select a difficulty level: Easy, Medium, or Hard.\n";
    cout << "  4. You will be presented with a hidden word represented by underscores.\n";
    cout << "  5. Guess letters to reveal the hidden word.\n";
    cout << "  6. Incorrect guesses result in the progression of the hangman illustration.\n\n";
    cout << "   - \033[1;32mEasy Mode: 6\033[0m incorrect guesses allowed.\n";   
    cout << "   - \033[1;33mMedium Mode: 5\033[0m incorrect guesses allowed.\n";
    cout << "   - \033[1;31mHard Mode: 4\033[0m incorrect guesses allowed.\n\n";  
    cout << "   - Winning: Correctly guess the word before reaching the maximum incorrect guesses.\n";
    cout << "   - Losing: The hangman is fully drawn before you guess the word.\n\n";
    system("pause");
    system("cls");
}

void start()
{
    cout << "\033[1;34m         ********************************************\033[0m\n";
    cout << "\033[1;34m         *         WELCOME TO THE HANGMAN !         *\033[0m\n";
    cout << "\033[1;34m         ********************************************\033[0m\n\n";

    system("pause");
    system("cls");
}
//if the user selects easy mode, this function will be called

void easymode(const string& og_word) {
    defaulthangman(); //theres a system("cls") in entercategory func which is why im again calling my default hangman
    string hiddenword = hideword(og_word); // the hideword function is taking the final word tht came frm the func randomizer and changing each of its alphabets with "-" and storing in string hiddenword
    cout << "             " << hiddenword << endl << endl;
    char userinput = ' ';
    int wrongattempts = 0;
    string Guessedword;
    bool correctguess = false;
    const int alphabets_size = 26;
    bool guessedLetter[alphabets_size] = { false }; // Array to keep track of guessed letters


    for (int i = 0; i < 6; i++) {
        userinput = Guessesinput(guessedLetter, alphabets_size);   //asking the user to guess
        Guessedword = guess(og_word, userinput, hiddenword, correctguess, wrongattempts);  //here word is the random word tht was generated, userinput is users guess, hiddenword is the original word hidden with -.
        cout << "            " << Guessedword << endl;


        if (correctguess)
        {
            cout << "Keep going, you got this." << endl;
            cout << endl;

        }

        if (!correctguess)
        {
            wrongattempts++;
            punishedman(wrongattempts);
            cout << endl;
            cout << "            " << Guessedword << endl << endl;
            cout << "\033[1;31mHmm. Try again. You have " << 6 - wrongattempts << " attempts left.\033[0m" << endl;
            i--;
        }

        if (Guessedword == og_word)
        {
            playCorrectSound();
            cout << "\033[1;32mLetsgo! Goodjob!\033[0m" << endl;
            cout << "The word was " << og_word;
            break;
        }

        if (wrongattempts == 6)
        {
            playIncorrectSound();
            cout << "\033[1;34mOops! You're dead.\033[0m";
            cout << "The word was " << og_word;
            break;
        }
    }
}

//if the user selects medium mode, this function will be called, it has lesser attempts than easymode

void mediummode(const string& og_word) {
    defaulthangman(); //theres a system("cls") in entercategory func which is why im again calling my default hangman
    string hiddenword = hideword(og_word); // the hideword function is taking the final word tht came frm the func randomizer and changing each of its alphabets with "-" and storing in string hiddenword
    cout << "             " << hiddenword << endl << endl;
    char userinput = ' ';
    int wrongattempts = 0;
    string Guessedword;
    bool correctguess = false;
    const int alphabets_size = 26;
    bool guessedLetter[alphabets_size] = { false }; // Array to keep track of guessed letters


    for (int i = 0; i < 6; i++) {
        userinput = Guessesinput(guessedLetter, alphabets_size);   //asking the user to guess
        Guessedword = guess(og_word, userinput, hiddenword, correctguess, wrongattempts);  //here word is the random word tht was generated, userinput is users guess, hiddenword is the original word hidden with -.
        cout << "            " << Guessedword << endl;


        if (correctguess)
        {
            cout << "Keep going, you got this." << endl;
            cout << endl;

        }

        if (!correctguess)
        {
            wrongattempts++;
            punishedman(wrongattempts);
            cout << endl;
            cout << "            " << Guessedword << endl << endl;
            cout << "\033[1;31mHmm. Try again. You have " << 5 - wrongattempts << " attempts left.\033[0m" << endl;
            i--;
        }

        if (Guessedword == og_word)
        {
            playCorrectSound;
            cout << "\033[1;32mLetsgo! Goodjob!\033[0m" << endl;
            cout << "The word was " << og_word;
            break;
        }

        if (wrongattempts == 5)
        {
            playIncorrectSound;
            cout << "\033[1;34mOops! You're dead.\033[0m";
            cout << "The word was " << og_word;
            break;
        }
    }
}

//if the user selects hard mode, this function will be called, it has lesser attempts than easy and medium mode and 2 bodyparts will be coming at once 

void hardmode(const string& og_word) {
    defaulthangman();
    string hiddenword = hideword(og_word);
    cout << "             " << hiddenword << endl << endl;
    char userinput = ' ';
    int wrongattempts = 0;
    string Guessedword;
    bool correctguess = false;
    const int alphabets_size = 26;
    bool guessedLetter[alphabets_size] = { false }; // Array to keep track of guessed letters

    for (int i = 0; i < 6; i++) {
        userinput = Guessesinput(guessedLetter, alphabets_size);   //asking the user to guess
        Guessedword = guess(og_word, userinput, hiddenword, correctguess, wrongattempts);  //here word is the random word tht was generated, userinput is users guess, hiddenword is the original word hidden with -.
        cout << "            " << Guessedword << endl;


        if (correctguess)
        {
            cout << "Keep going, you got this." << endl;
            cout << endl;
            continue;
        }

        if (!correctguess)
        {
            wrongattempts++;
            punishedman_hard(wrongattempts);
            cout << endl;
            cout << "            " << Guessedword << endl << endl;
            cout << "\033[1;31mHmm. You have " << 3 - wrongattempts << " attempts left.\033[0m" << endl;
            i--;
        }

        if (Guessedword == og_word)
        {
            playCorrectSound;
            cout << "\033[1;32mLetsgo! Goodjob!\033[0m" << endl;
            cout << "\033[1;32mThe word was " << og_word << "\033[0m";
            break;
        }

        if (wrongattempts == 3)
        {
            playIncorrectSound;
            cout << "\033[1;34mOops! You're dead.\033[0m";
            cout << "\033[1;31mThe word was " << og_word << "\033[0m";
            break;
        }
    }
}

void defaulthangman() {
    cout << "\033[1;31m  HANGMAN- Where every miss is a near death experience!        \033[0m" << endl << endl;

    cout << "=========\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n\n";
}

void punishedman(int wrongattempts) //prints the hangman based on the number of stages, takes the stage # as parameter
{
    system("cls");
    cout << "\033[1;31m  HANGMAN- Where every miss is a near death experience!        \033[0m" << endl<<endl ;
    if (wrongattempts == 0)
        cout << "=========\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n\n";
    if (wrongattempts == 1)
        cout << "=========\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n\n";
    if (wrongattempts == 2)
        cout << "=========\n  +---+\n  |   |\n  O   |\n /    |\n      |\n      |\n=========\n\n";
    if (wrongattempts == 3)
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n\n";
    if (wrongattempts == 4)
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n\n";
    if (wrongattempts == 5)
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n\n";
    if (wrongattempts == 6)
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========= \n\n";
}

void punishedman_hard(int wrongattempts) //prints the hangman based on the number of stages, takes the stage # as parameter
{
    system("cls");
    cout << "\033[1;31m********** Welcome to hangman! ************\033[0m" << endl;
    cout << "Where Every Miss Is A Near Death Experience!" << endl;
    if (wrongattempts == 0)
    {

        cout << "=========\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n\n";
    }

    if (wrongattempts == 1)
    {
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n\n";
    }
    if (wrongattempts == 2)
    {
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n\n";
    }
    if (wrongattempts == 3)
    {
        cout << "=========\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========= \n\n";
    }
}




char Guessesinput(bool guessedLetters[], int alphabetSize) {
    char userInput;
    cout << "Take your guess: ";
    cin >> userInput;
    cout << endl;

    // Check if the letter has already been guessed
    while (guessedLetters[userInput - 'a'])
    {
        cout << "You've already guessed that letter. Try again: ";
        cin >> userInput;
        cout << endl;
    }

    // Record the guessed letter
    recordGuessedLetter(userInput, guessedLetters);

    return userInput;
}

void recordGuessedLetter(char letter, bool guessedLetters[])
{
    guessedLetters[letter - 'a'] = true;
}


string randomiser(string words[], int size)
{
    srand(time(0));  // seed for the rand function to initialize the random number generator with the current time.
    return words[rand() % size];
}


//creating a new string hideword and hiding each char of og_word with _ and returning new string leaving spaces unchanged

string hideword(const string& word) {
    string hide_word;

    for (char ch : word) {
        if (ch == ' ') {
            hide_word += ' '; // leave spaces unchanged
        }
        else {
            hide_word += '_'; // replace other characters with -
        }
    }

    return hide_word;
}



string guess(const string word, char userInput, string& displayhidden, bool& correctguess, int& wrongattempts)

{

    correctguess = false;

    for (int i = 0; i < word.length(); i++)
    {
        if (userInput == word[i])
        {
            displayhidden[i] = userInput;  // comparing guessed letter with each index of original word
            correctguess = true;
        }
    }

    return displayhidden;
}

void enterCategoryandLevel(string& og_word) {
    string name;
    int choice;
    int level;

    cout << "\nPlayer name: ";
    getline(cin, name);

    do {
        cout << "Hello " << name << "! " "You have 3 categories to select from:\n ";
        cout << "1: Animals   (Press 1)\n 2: Countries (Press 2)\n 3: Movies    (Press 3)\n";
        cin >> choice;

        if (choice <= 0 || choice > 3) {
            cout << "Oops! Seems like you are testing us. Press 5 to try again" << endl;
            cin >> choice;
        }
    } while (choice == 5);

    do {
        cout << "Select your level of difficulty: \n" << "1. Easy- A piece of cake \t(Press 1)\n" << "2. Medium - The Goldilocks Zone  (Press 2)\n" << "3. Hard  - Are You Ready To Test Those Braincells? (Press 3)\n ";
        cin >> level;

        if (level <= 0 || level > 3) {
            cout << "Alas! That level does not exist. Press 7 to try again ";
            cin >> level;
        }
    } while (level == 7);

    cout << endl;
    system("cls");

    if (choice == 1 && level == 1) {
        og_word = randomiser(animals_easy, 10);
        easymode(og_word);  //passing og_word to easymode if user selects easy mode, all of the other if statements have the same functioning for diff categories and levels
    }

    if (choice == 1 && level == 2) {
        og_word = randomiser(animals_medium, 10);
        mediummode(og_word);
    }

    if (choice == 1 && level == 3) {
        og_word = randomiser(animals_hard, 10);
        hardmode(og_word);
    }

    if (choice == 2 && level == 1) {
        og_word = randomiser(countries_easy, 10);
        easymode(og_word);
    }

    if (choice == 2 && level == 2) {
        og_word = randomiser(countries_medium, 10);
        mediummode(og_word);
    }

    if (choice == 2 && level == 3) {
        og_word = randomiser(countries_hard, 10);
        hardmode(og_word);
    }

    if (choice == 3 && level == 1) {
        og_word = randomiser(movies_easy, 10);
        easymode(og_word);
    }

    if (choice == 3 && level == 2) {
        og_word = randomiser(movies_medium, 10);
        mediummode(og_word);
    }

    if (choice == 3 && level == 3) {
        og_word = randomiser(movies_hard, 10);
        hardmode(og_word);
    }
}
