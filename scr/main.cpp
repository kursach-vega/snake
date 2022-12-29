#include "../headers/root.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication draw(argc, argv);
    root window;
    window.setWindowTitle("Змейка QtE");
    window.show();
    return draw.exec();
}
