#ifndef QUIZWIDGET_H
#define QUIZWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>

// Struct to store a single question and its four answer choices
struct Question {
    QString text;          // The question text
    QStringList options;   // A list containing 4 answer choices
};

// QuizWidget class inherits from QWidget
class QuizWidget : public QWidget {
private:
    QLabel *questionLabel; // Label to display the question
    QLabel *optionsLabel;  // Label to display answer choices
    int currentQuestionIndex;  // Tracks the current question number
    QVector<Question> questions;  // Stores all quiz questions

public:
    // Constructor initializes the quiz and UI
    QuizWidget(QWidget *parent = nullptr) : QWidget(parent), currentQuestionIndex(0) {
        setWindowTitle("Quiz Game");  // Set window title
        resize(400, 200);  // Set window size

        // Create a vertical layout
        QVBoxLayout *layout = new QVBoxLayout(this);
        questionLabel = new QLabel(this);  // Label for question
        optionsLabel = new QLabel(this);   // Label for options
        layout->addWidget(questionLabel);
        layout->addWidget(optionsLabel);
        setLayout(layout);  // Apply the layout

        // Define 10 questions and their answer choices
        questions = {
            {"What is 2 + 2?", {"1", "2", "3", "4"}},
            {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}},
            {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}},
            {"What is the largest ocean?", {"Atlantic", "Indian", "Arctic", "Pacific"}},
            {"Who wrote 'Hamlet'?", {"Shakespeare", "Hemingway", "Tolkien", "Dickens"}},
            {"What is the square root of 64?", {"6", "7", "8", "9"}},
            {"What is the currency of Japan?", {"Yuan", "Won", "Ringgit", "Yen"}},
            {"Which element has the symbol 'O'?", {"Gold", "Oxygen", "Osmium", "Iron"}},
            {"What is the speed of light?", {"300,000 km/s", "150,000 km/s", "1,000 km/s", "3,000 km/s"}},
            {"Who painted the Mona Lisa?", {"Van Gogh", "Da Vinci", "Picasso", "Rembrandt"}}
        };

        displayQuestion();  // Show the first question
    }

    // Handles keyboard input (1,2,3,4 keys)
    void keyPressEvent(QKeyEvent *event) override {
        int key = event->key();
        if (key >= Qt::Key_1 && key <= Qt::Key_4) {  // If the user presses 1-4
            nextQuestion();  // Move to the next question
        }
    }

private:
    // Displays the current question and answer choices
    void displayQuestion() {
        if (currentQuestionIndex < questions.size()) {
            Question q = questions[currentQuestionIndex];
            questionLabel->setText(q.text);  // Set question text
            optionsLabel->setText("1. " + q.options[0] + "\n2. " + q.options[1] +
                                  "\n3. " + q.options[2] + "\n4. " + q.options[3]);
        } else {
            questionLabel->setText("Quiz Complete!");  // End of quiz message
            optionsLabel->setText("");
        }
    }

    // Moves to the next question
    void nextQuestion() {
        if (currentQuestionIndex < questions.size()) {
            currentQuestionIndex++;  // Increase question index
            displayQuestion();  // Show the next question
        }
    }
};

#endif // QUIZWIDGET_H
