//
//dsakjdha
//
#include <QuizLoop.h>
#include <iostream>
#include <limits>
#include <vector>

int main()
 {
    std::vector<std::string> qSet =  {"what does the data type 'string' represent?", "which best describes a name space?"};
    std::vector<char> qSetAnswers ={'b','a'};

    QuizQuestion quizStruct(qSet,qSetAnswers);
    quizStruct.GameLoop();
    return 0;


 }