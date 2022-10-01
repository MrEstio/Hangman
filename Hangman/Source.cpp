#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;
int main()
{
	const int MAX_WRONG = 8; // Максимальное кол-во ошибок
	vector<string>words; // Подборка слов для загадывания 
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; // Слово для отгадывания 
	int wrong = 0; // Кол-во ошибочных вариантов
	string soFar(THE_WORD.size(), '-'); // Часть слова, открытая на данный момент
	string used = ""; // Уже отгаданные буквы
	cout << "Welcome to Hangman. Good luck!\n";
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) // основной цикл
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrent guesses left.\n";
		cout << "\nYou've used the followong letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); // Перевод в верхний регистр.
		// Так как загаданное слово записано в верхнем регистре
		while(used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";
			// Обновить переменную soFar, включив в нее новую угаданную букву
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry. " << guess << " isn't in the word. \n";
			++wrong;
		}
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou've been hanged!";
		}
		else
		{
			cout << "\nYou guessed it";
		}
	}
	cout << "\nThe word was " << THE_WORD << endl;
	return 0;
}
