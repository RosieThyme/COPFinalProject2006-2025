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
              "Which of these best describes a namespace?",
              "In a function invocation, an epilogue is?",
              "The act of compiling function invocations in order to optimize code is called?",
              "Which of these options is considered a macro?",
              "How would you dereference the pointer variable `data`?",
              "What is the purpose of the `virtual` keyword in C++?",
              "Which type of memory allocation is handled by `new`?",
              "What does the `friend` keyword do in C++?",
              "Which operator is used to access members of a class through a pointer?",
              "How do you prevent a class from being inherited in C++?"
          },
          {'1', '3', '2', '4', '1', '2', '3', '4', '1', '3'}),
          currentQuestionIndex(0) {

        setWindowTitle("C++ Quiz Game");
        resize(500, 300);

        QVBoxLayout *layout = new QVBoxLayout(this);
        pquestionLabel = new QLabel(this);
        poptionsLabel = new QLabel(this);
        pscoreLabel = new QLabel(this);

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
    void displayQuestion() {
        if (currentQuestionIndex < quizLoop.questionList.size()) {
            pquestionLabel->setText(QString::fromStdString(quizLoop.questionList[currentQuestionIndex]));
            poptionsLabel->setText("1. Option 1\n2. Option 2\n3. Option 3\n4. Option 4");
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
            quizLoop.isCorrectAnswer();
            currentQuestionIndex++;
            displayQuestion();
        }
    }
};

#endif // QUIZWIDGET_H