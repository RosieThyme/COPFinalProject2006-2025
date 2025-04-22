/*
Coder/Developer: Hildline Noel
Class: COP 2006-14035, Spring 2025
Date: March 23, 2025
Description: c++ header file that contains how the QuizQuestion class should function when called
Log: March 26,2025 - set up the QuizQuestion Function to determine the result of question
     March 28,2025 - modified constuctor to allow for input
      April 8,2025 - removed unessessary Functions
*/


#ifndef QUIZLOOP_H
#define QUIZLOOP_H

#include <iostream>
#include <vector>

class QuizQuestion {
public:
  std::vector<std::vector<std::string>> questionList;
  std::vector<char> correctAnswer;
  mutable char userAnswer = ' ';
  mutable int score = 0;
  mutable int questionIndex = 0;
//stores the pointers to the vector and the corresponding correct answer
  QuizQuestion(std::vector<std::vector<std::string>> const &pquestionList, std::vector<char> const &pcorrectAnswer) {
    this->questionList = pquestionList;
    this->correctAnswer = pcorrectAnswer;
  }
//checks if the answer is correct
  bool isCorrectAnswer() const {
    if (userAnswer == correctAnswer[questionIndex]) {
      score++;
      return true;
    }
    return false;
  }
};

#endif // QUIZLOOP_H