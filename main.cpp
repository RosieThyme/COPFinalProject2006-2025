/*
Coder/Developer: Damien Provost, Hildline Noel
Class: COP 2006-14035, Spring 2025
Date: March 23, 2025
Description:
Log: March 26,2025 - set up the QuizQuestion Function to determine the result of question
*/

#include <QApplication>
#include "quizwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Initialize Qt application
    QuizWidget quiz;  // Create quiz widget
    quiz.show();  // Show the quiz window
    return app.exec();  // Start the event loop
}
