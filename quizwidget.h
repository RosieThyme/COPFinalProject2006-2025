/*
Coder/Developer:
Class: COP 2006-14035, Spring 2025
Date: March 23, 2025
Description:
Log:
*/

#ifndef QUIZWIDGET_H
#define QUIZWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "quizloop.h"

class QuizWidget : public QWidget {
private:
    QLabel *pquestionLabel;
    QLabel *poptionsLabel;
    QLabel *pscoreLabel;
    QuizQuestion quizLoop;
    int currentQuestionIndex;

public:
    QuizWidget(QWidget *parent = nullptr)
        : QWidget(parent),
          quizLoop({
              {"Which of these best describes a namespace?","1.A file that can be open using the fopen function,\n2.A library containing functions that can be accessed through the name of the library\n3.A built-in library that contains the standard classes and functions\n4.A technique used to shorten variable/function name"},
            {"In a function invocation, an epilogue is?","1.What a function executes last\n2.What happens after compling the code\n3.What occurs at the end of the main function\n4.The start of a function"},
            {"The act of compiling function invocations in order to optimize code is called?","1.Function call\n2.Argument vector\n3.Function parameter\n4.Inline function"},
            {"Which of these options is considered a macro?", "1.int data\n2.class data\n3.#define data\n4.struct data"},
            {"How would you dereference the pointer variable `data`?","1.&pdata\n2.this->pdata\n3.*pdata\n4.pdata"},
              {"What is the purpose of the `virtual` keyword in C++?","1.To create a GUI in the program\n2.Allows the programmer to create new functions from the base class\n3.To hide the implementation of the program from the user\n4. A method of error handling"},
              {"Which type of memory allocation is handled by `new`?","1.stack allocation\n2.heap allocation\n3.dynamic memory allocation\n4.static memory allocation"},
              {"What does the `friend` keyword do in C++?","1.creates a new function of the class\n2.inherits the class\n3.a form of a parent class in c++\n4.allows access to a class's protected and private members"},
              {"Which operator is used to access members of a class through a pointer?","1.->\n2.&\n3.^\n4.\\n"},
              {"How do you prevent a class from being inherited in C++?","1.private\n2.Final\n3.final\n4.protected"}
          },
          {'2', '1', '4', '3', '3', '2', '3', '4', '1', '3'}),
          currentQuestionIndex(0) {

        setWindowTitle("C++ Quiz Game");
        resize(500, 300);

        QVBoxLayout *layout = new QVBoxLayout(this);
        pquestionLabel = new QLabel(this);
        poptionsLabel = new QLabel(this);
        pscoreLabel = new QLabel(this);
        //creates text on the Window
        layout->addWidget(pquestionLabel);
        layout->addWidget(poptionsLabel);
        layout->addWidget(pscoreLabel);
        setLayout(layout);

        displayQuestion();
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        int key = event->key();
        if (key >= Qt::Key_1 && key <= Qt::Key_4) {
            char selectedAnswer = static_cast<char>((key - Qt::Key_1) + '1');
            processAnswer(selectedAnswer);
        }
    }

private:
    //checks to see if the Index number exceeds the size of the vector
    void displayQuestion() {
        if (currentQuestionIndex < quizLoop.questionList.size()) {
            pquestionLabel->setText(QString::fromStdString(quizLoop.questionList[currentQuestionIndex][0]));
            poptionsLabel->setText(QString::fromStdString(quizLoop.questionList[currentQuestionIndex][1]));
            quizLoop.correctAnswer[currentQuestionIndex];

            pscoreLabel->setText("Score: " + QString::number(quizLoop.score));
        } else {
            pquestionLabel->setText("Congrats! You have finished the quiz!");
            poptionsLabel->setText("Final Score: " + QString::number(quizLoop.score) + " / " +
                                  QString::number(quizLoop.questionList.size()));
            pscoreLabel->setText("");
        }
    }

    void processAnswer(char userChoice) {
        if (currentQuestionIndex < quizLoop.questionList.size()) {
            quizLoop.userAnswer = userChoice;
            if (userChoice == quizLoop.correctAnswer[currentQuestionIndex])
            {
                quizLoop.score++;
            }
            currentQuestionIndex++;
            displayQuestion();
        }
    }
};

#endif // QUIZWIDGET_H