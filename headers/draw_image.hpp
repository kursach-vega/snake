#ifndef DRAW_IMAGE_H
#define DRAW_IMAGE_H

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

class Draw_image {
public:
  Draw_image(const QString& file_path);

  void drawRotate(QPainter* canvas, short x, short y, ROTATE direction);
  int height() const;
  int width() const;
  QPixmap get_images() const;

private:
  QPixmap images;

};

#endif // DRAW_IMAGE_H
