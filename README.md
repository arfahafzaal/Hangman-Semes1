# Hangman Game README

This repository contains a simple Hangman game written in C++. The game offers players the opportunity to guess a hidden word within a limited number of attempts, with different difficulty levels and categories.

## Table of Contents

- [Introduction](#introduction)
- [Instructions](#instructions)
- [Features](#features)
- [Categories](#categories)
- [Difficulty Levels](#difficulty-levels)
- [Dependencies](#dependencies)
- [How to Play](#how-to-play)
- [Compilation and Execution](#compilation-and-execution)
- [Contribution](#contribution)
- [License](#license)

## Introduction

Hangman is a classic word-guessing game where players try to guess a hidden word letter by letter. For each incorrect guess, a part of a hangman is drawn. The game offers three categories: Animals, Countries, and Movies, and three difficulty levels: Easy, Medium, and Hard.

## Instructions

1. Guess the correct letters of a hidden word before the hangman is fully drawn.
2. Choose from three categories: Animals, Countries, or Movies.
3. Select a difficulty level: Easy, Medium, or Hard.
4. You will be presented with a hidden word represented by underscores.
5. Guess letters to reveal the hidden word.
6. Incorrect guesses result in the progression of the hangman illustration.

   - Easy Mode: 6 incorrect guesses allowed.
   - Medium Mode: 5 incorrect guesses allowed.
   - Hard Mode: 4 incorrect guesses allowed.

   Winning: Correctly guess the word before reaching the maximum incorrect guesses.
   Losing: The hangman is fully drawn before you guess the word.

## Features

- Three categories: Animals, Countries, and Movies.
- Three difficulty levels: Easy, Medium, and Hard.
- Interactive hangman illustrations.
- Sound effects for correct and incorrect guesses.
- Randomly selected words from predefined lists.

## Categories

1. Animals
2. Countries
3. Movies

## Difficulty Levels

1. Easy - 6 incorrect guesses allowed.
2. Medium - 5 incorrect guesses allowed.
3. Hard - 4 incorrect guesses allowed.

## Dependencies

The game uses the `<iostream>`, `<stdlib.h>`, `<time.h>`, `<string>`, and `<Windows.h>` libraries.

## How to Play

1. Run the program.
2. Follow the on-screen instructions.
3. Choose a category and difficulty level.
4. Guess letters to reveal the hidden word.
5. Enjoy the game!

## Compilation and Execution

To compile the code, you can use any C++ compiler. 


## Contribution

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to create an issue or submit a pull request.

## License

This Hangman game is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
