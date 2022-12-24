#include "../headers/draw_image.hpp"

Draw_image::Draw_image(const QString& FILE_PATH) :
    images(FILE_PATH) {
    return;
}

int Draw_image::height() const {
    return this->images.height();
}

int Draw_image::width() const {
    return this->images.width();
}

void Draw_image::drawRotate(QPainter* canvas, short x, short y,
                            ROTATE direction = ROTATE::NONE) {
    int radius = static_cast<int>(direction);
    if ( direction == ROTATE::NONE ) {
        canvas-> drawPixmap(x, y, images);
        return;
    }
    QTransform tr_image;
    tr_image.rotate(radius);
    images = images.transformed(tr_image);
    canvas-> drawPixmap(x, y, images);
    tr_image.rotate(-radius);
    images = images.transformed(tr_image);
    return ;
}
