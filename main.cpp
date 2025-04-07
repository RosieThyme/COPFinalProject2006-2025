//
//dsakjdha
//
#include "QuizLoop.h"
#include <iostream>
#include <limits>
#include <vector>

int main()
 {
    std::vector<std::string> QSet =  {"Which of these best describes a namespace",
        "In a Function Invocation an epilogue is",
    "the act of compiling function invocations in order to optimize code is called",
        "which of these options is considered a macro",
    "how would you dereference the pointer variable pdata"};
    std::vector<std::string> AnswerOptions = {"\nA.a file that can be open using the fopen fucntion\nB.a library containing functions that can be accessed through the name of the library\nC.a built-in library that contains the standard classes and functions\nD.a technique used to shorten variable/function name\n"};
    std::vector<char> QSetAnswers ={'b','a'};

    QuizQuestion quizStruct(QSet,QSetAnswers);
    quizStruct.GameLoop();
    return 0;

 }