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
#include <vector>

class QuizQuestion
{
public:
  std::vector<std::string> questionList;
  std::vector<char> correctAnswer;
  mutable char userAnswer = ' ';
  mutable int score = 0;
  mutable int questionIndex = 0;

  QuizQuestion(std::vector<std::string> const &pquestionList, std::vector<char> const &pcorrectAnswer)
  {
    this->questionList = pquestionList;
    this->correctAnswer = pcorrectAnswer;
  }

  bool isCorrectAnswer() const
  {
    if (userAnswer == correctAnswer[questionIndex]) {
      score++;
      return true;
    }
    return false;
  }
};

#endif // QUIZLOOP_H
