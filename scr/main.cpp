#include "../headers/root.hpp"
#include <QApplication>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[]) {
    std::srand(std::time(nullptr));
    QApplication draw(argc, argv);
    root window;
    window.setWindowTitle("Змейка");
    window.show();
    return draw.exec();
}
