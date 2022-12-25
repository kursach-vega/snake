#ifndef DRAW_IMAGE_HPP
#define DRAW_IMAGE_HPP

#include <QString>
#include <QPixmap>
#include <QPainter>

enum class ROTATE {
        RIGHT = 0,
        DOWN = 90,
        LEFT = 180,
        UP = 270,
        NONE = -1,
};

class Draw_image  {
public:
    Draw_image(const QString& FILE_PATH);

    void draw(QPainter& canvas, short x, short y,
              ROTATE direction = ROTATE::NONE);
    int height() const;
    int width() const;
    QPixmap get_images() const;

private:
    QPixmap _images;
};

#endif
