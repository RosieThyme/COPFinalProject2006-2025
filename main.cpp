#include <QApplication>
#include "quizwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Initialize Qt application
    QuizWidget quiz;  // Create quiz widget
    quiz.show();  // Show the quiz window
    return app.exec();  // Start the event loop
}
