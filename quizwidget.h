#ifndef QUIZWIDGET_H
#define QUIZWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "quizloop.h"

class QuizWidget : public QWidget {
private:
    QLabel *questionLabel;
    QLabel *optionsLabel;
    QLabel *scoreLabel;
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
        questionLabel = new QLabel(this);
        optionsLabel = new QLabel(this);
        scoreLabel = new QLabel(this);

        layout->addWidget(questionLabel);
        layout->addWidget(optionsLabel);
        layout->addWidget(scoreLabel);
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
            questionLabel->setText(QString::fromStdString(quizLoop.questionList[currentQuestionIndex]));
            optionsLabel->setText("1. Option 1\n2. Option 2\n3. Option 3\n4. Option 4");
            scoreLabel->setText("Score: " + QString::number(quizLoop.score));
        } else {
            questionLabel->setText("Congrats! You have finished the quiz!");
            optionsLabel->setText("Final Score: " + QString::number(quizLoop.score) + " / " +
                                  QString::number(quizLoop.questionList.size()));
            scoreLabel->setText("");
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
