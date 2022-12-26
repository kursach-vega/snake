#include "../headers/draw_image.hpp"

Draw_image::Draw_image(const QString& FILE_PATH) :
    _images(FILE_PATH) {
    return;
}

int Draw_image::height() const {
    return this->_images.height();
}

int Draw_image::width() const {
    return this->_images.width();
}

void Draw_image::draw(QPainter& canvas, short x, short y,
                      ROTATE direction) {
    int radius = static_cast<int>(direction);
    if ( direction == ROTATE::NONE ) {
        canvas.drawPixmap(x, y, this->_images);
        return;
    }
    QTransform tr_image;
    tr_image.rotate(radius);
    canvas.drawPixmap(x, y, this->_images.transformed(tr_image));
    return ;
}
