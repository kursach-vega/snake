#ifndef RENDER_HPP
#define RENDER_HPP

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
    class Render;
}

class Render : public QWidget {
    Q_OBJECT

public:
    explicit Render(QWidget *parent = 0);
    ~Render();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Render *ui;
};

#endif
