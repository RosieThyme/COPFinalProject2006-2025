#ifndef QUIZLOOP_H
#define QUIZLOOP_H
/*
Coder/Developer: Hildline Noel
Class: COP 2006-14035, Spring 2025
Date: March 23, 2025
Description:
Log: March 26,2025 - set up the QuizQuestion Function to determine the result of question
*/

#include <iostream>
#include <cstring>
#include <limits>
#include <vector>

class QuizQuestion
{
public:
  std::vector<std::string> questionList = {};
  std::vector<char> correctAnswer = {};
  mutable char userAnswer= ' ';
  mutable int score = 0;
  mutable int questionIndex = 0;

  QuizQuestion(std::vector<std::string>  const &pquestionList,std::vector<char> const &pcorrectAnswer)
  {
    this->questionList = pquestionList;
    this->correctAnswer = pcorrectAnswer;
  }
  int gameLoop() const
  {
    for (int item = 0; item < questionList.size(); item++)
    {
        nextQuestion();
    }
    std::cout <<score<<"/"<<questionList.size() <<std::endl;
    return 0;
  }

  int nextQuestion() const
  {
    if (questionIndex < questionList.size())
    {
      std::cout << questionList[questionIndex]<<std::endl;
      userAnswer = userInput();
      // storeAnswer();
      isCorrectAnswer();

      questionIndex++;
    }
    return 0;
  }

  static char userInput()
  {
    char character;
    bool validInput = false;
    //as long as the user has not entered a valid input
    while (!validInput)
    {
      // attempt to run the code
      try
      {
        std::cin >> character;
        //if the user does not enter a number, prompt the user to enter the correct information
        if (std::cin.fail())
        {
          std::cout<< "enter in a numeric value:"<< std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        //if the number turns out to be a negative number, throw an error message
        else if (character < 0)
        {
          throw 400;
        }
        //if the user enters the correct information exit the loop
        else
        {
          validInput = true;
        }
      }
      catch (int errorNumber)
      {
        std::cout <<"ERROR "<<errorNumber <<": Number is not positive"<< std::endl;
        exit(400);
      }
    }
    //return user input
    return character;

  }

  bool isCorrectAnswer() const
  {
    if (userAnswer == correctAnswer[questionIndex])
    {
      score++;
      return true;
    }
    return false;
  }
};
#endif //QUIZLOOP_H
