/********************************************************************************
** Form generated from reading UI file 'root.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOT_H
#define UI_ROOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "headers/tab_game.hpp"

QT_BEGIN_NAMESPACE

class Ui_root
{
public:
    QWidget *main_window;
    QGridLayout *gridLayout;
    QTabWidget *tabl_snake;
    QWidget *menu;
    QVBoxLayout *verticalLayout_2;
    QLabel *text_menu;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_2;
    QPushButton *transition_game;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *transition_about_game;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *exit_button;
    QSpacerItem *verticalSpacer_4;
    Tab_game *game;
    QVBoxLayout *verticalLayout_5;
    QLabel *text_game;
    QHBoxLayout *horizontalLayout_6;
    QLCDNumber *timer_game_widget;
    QSpacerItem *horizontalSpacer_13;
    QLCDNumber *score_apple_widget;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_3;
    QWidget *end_game_window;
    QVBoxLayout *verticalLayout_3;
    QLabel *end_text;
    QLabel *end_win_text;
    QHBoxLayout *horizontalLayout_5;
    QLCDNumber *time_end_game;
    QSpacerItem *horizontalSpacer_14;
    QLCDNumber *score_apple_end_game;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *start_over;
    QPushButton *return_menu_end;
    QSpacerItem *horizontalSpacer_9;
    QWidget *pause_window;
    QVBoxLayout *verticalLayout_4;
    QLabel *pause_text;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *continue_pause;
    QPushButton *return_menu_pause;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_6;
    QWidget *about_the_game;
    QVBoxLayout *verticalLayout;
    QLabel *text_about_game;
    QSpacerItem *verticalSpacer;
    QLabel *game_descriptions;
    QSpacerItem *verticalSpacer_2;
    QPushButton *about_game_back;

    void setupUi(QMainWindow *root)
    {
        if (root->objectName().isEmpty())
            root->setObjectName(QString::fromUtf8("root"));
        root->resize(800, 700);
        root->setMinimumSize(QSize(800, 700));
        root->setMaximumSize(QSize(800, 700));
        root->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 139, 34);\n"
"QSlider {\n"
"            background-color: #FF3B3B3B;\n"
"            color: white;\n"
"            border : 0.1em;\n"
"            height:  1.5em;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"            height: 0.5em;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"            height:  0 -0.7em;\n"
"}\n"
"\n"
"QSlider:hover {\n"
"            border-color: yellow;\n"
"            background: #FF5A5A5A;\n"
"}"));
        main_window = new QWidget(root);
        main_window->setObjectName(QString::fromUtf8("main_window"));
        gridLayout = new QGridLayout(main_window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabl_snake = new QTabWidget(main_window);
        tabl_snake->setObjectName(QString::fromUtf8("tabl_snake"));
        tabl_snake->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 171, 46);"));
        menu = new QWidget();
        menu->setObjectName(QString::fromUtf8("menu"));
        verticalLayout_2 = new QVBoxLayout(menu);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        text_menu = new QLabel(menu);
        text_menu->setObjectName(QString::fromUtf8("text_menu"));
        QFont font;
        font.setPointSize(32);
        text_menu->setFont(font);
        text_menu->setStyleSheet(QString::fromUtf8("color: rgb(255, 253, 208);"));
        text_menu->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(text_menu);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        transition_game = new QPushButton(menu);
        transition_game->setObjectName(QString::fromUtf8("transition_game"));
        transition_game->setMinimumSize(QSize(250, 50));
        QFont font1;
        font1.setPointSize(17);
        transition_game->setFont(font1);

        gridLayout_2->addWidget(transition_game, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        transition_about_game = new QPushButton(menu);
        transition_about_game->setObjectName(QString::fromUtf8("transition_about_game"));
        transition_about_game->setMinimumSize(QSize(200, 50));
        transition_about_game->setFont(font1);

        gridLayout_2->addWidget(transition_about_game, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        exit_button = new QPushButton(menu);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setMinimumSize(QSize(200, 50));
        exit_button->setFont(font1);

        gridLayout_2->addWidget(exit_button, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        tabl_snake->addTab(menu, QString());
        game = new Tab_game();
        game->setObjectName(QString::fromUtf8("game"));
        verticalLayout_5 = new QVBoxLayout(game);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        text_game = new QLabel(game);
        text_game->setObjectName(QString::fromUtf8("text_game"));
        text_game->setFont(font);
        text_game->setStyleSheet(QString::fromUtf8("color: rgb(255, 253, 208);"));
        text_game->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(text_game);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        timer_game_widget = new QLCDNumber(game);
        timer_game_widget->setObjectName(QString::fromUtf8("timer_game_widget"));
        timer_game_widget->setMinimumSize(QSize(0, 25));
        timer_game_widget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(46, 136, 21);"));
        timer_game_widget->setProperty("intValue", QVariant(0));

        horizontalLayout_6->addWidget(timer_game_widget);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        score_apple_widget = new QLCDNumber(game);
        score_apple_widget->setObjectName(QString::fromUtf8("score_apple_widget"));
        score_apple_widget->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        score_apple_widget->setFont(font2);
        score_apple_widget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(46, 136, 21);"));
        score_apple_widget->setProperty("intValue", QVariant(0));

        horizontalLayout_6->addWidget(score_apple_widget);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        end_game_window = new QWidget(game);
        end_game_window->setObjectName(QString::fromUtf8("end_game_window"));
        end_game_window->setMinimumSize(QSize(200, 150));
        end_game_window->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 136, 22);"));
        verticalLayout_3 = new QVBoxLayout(end_game_window);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        end_text = new QLabel(end_game_window);
        end_text->setObjectName(QString::fromUtf8("end_text"));
        QFont font3;
        font3.setPointSize(20);
        end_text->setFont(font3);
        end_text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        end_text->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(end_text);

        end_win_text = new QLabel(end_game_window);
        end_win_text->setObjectName(QString::fromUtf8("end_win_text"));
        end_win_text->setFont(font3);
        end_win_text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        end_win_text->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(end_win_text);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        time_end_game = new QLCDNumber(end_game_window);
        time_end_game->setObjectName(QString::fromUtf8("time_end_game"));
        time_end_game->setFont(font1);
        time_end_game->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 156, 35);"));
        time_end_game->setDigitCount(5);
        time_end_game->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(time_end_game);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_14);

        score_apple_end_game = new QLCDNumber(end_game_window);
        score_apple_end_game->setObjectName(QString::fromUtf8("score_apple_end_game"));
        score_apple_end_game->setFont(font1);
        score_apple_end_game->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 156, 35);"));
        score_apple_end_game->setSmallDecimalPoint(false);
        score_apple_end_game->setDigitCount(5);
        score_apple_end_game->setMode(QLCDNumber::Dec);
        score_apple_end_game->setSegmentStyle(QLCDNumber::Filled);
        score_apple_end_game->setProperty("value", QVariant(0.000000000000000));
        score_apple_end_game->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(score_apple_end_game);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        start_over = new QPushButton(end_game_window);
        start_over->setObjectName(QString::fromUtf8("start_over"));
        start_over->setMinimumSize(QSize(200, 0));
        start_over->setFont(font1);

        horizontalLayout_4->addWidget(start_over);

        return_menu_end = new QPushButton(end_game_window);
        return_menu_end->setObjectName(QString::fromUtf8("return_menu_end"));
        return_menu_end->setMinimumSize(QSize(200, 0));
        return_menu_end->setFont(font1);

        horizontalLayout_4->addWidget(return_menu_end);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout_3->addWidget(end_game_window, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        pause_window = new QWidget(game);
        pause_window->setObjectName(QString::fromUtf8("pause_window"));
        pause_window->setMinimumSize(QSize(200, 150));
        pause_window->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 136, 22);"));
        verticalLayout_4 = new QVBoxLayout(pause_window);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pause_text = new QLabel(pause_window);
        pause_text->setObjectName(QString::fromUtf8("pause_text"));
        pause_text->setFont(font3);
        pause_text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pause_text->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(pause_text);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        continue_pause = new QPushButton(pause_window);
        continue_pause->setObjectName(QString::fromUtf8("continue_pause"));
        continue_pause->setMinimumSize(QSize(200, 0));
        continue_pause->setFont(font1);

        horizontalLayout_2->addWidget(continue_pause);

        return_menu_pause = new QPushButton(pause_window);
        return_menu_pause->setObjectName(QString::fromUtf8("return_menu_pause"));
        return_menu_pause->setMinimumSize(QSize(200, 0));
        return_menu_pause->setFont(font1);

        horizontalLayout_2->addWidget(return_menu_pause);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout_3->addWidget(pause_window, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 1, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 1, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        tabl_snake->addTab(game, QString());
        about_the_game = new QWidget();
        about_the_game->setObjectName(QString::fromUtf8("about_the_game"));
        about_the_game->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(about_the_game);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_about_game = new QLabel(about_the_game);
        text_about_game->setObjectName(QString::fromUtf8("text_about_game"));
        text_about_game->setFont(font);
        text_about_game->setStyleSheet(QString::fromUtf8("color: rgb(255, 253, 208);"));
        text_about_game->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(text_about_game);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        game_descriptions = new QLabel(about_the_game);
        game_descriptions->setObjectName(QString::fromUtf8("game_descriptions"));
        game_descriptions->setFont(font1);
        game_descriptions->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        game_descriptions->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        game_descriptions->setWordWrap(true);
        game_descriptions->setOpenExternalLinks(false);

        verticalLayout->addWidget(game_descriptions);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        about_game_back = new QPushButton(about_the_game);
        about_game_back->setObjectName(QString::fromUtf8("about_game_back"));
        about_game_back->setFont(font1);

        verticalLayout->addWidget(about_game_back);

        tabl_snake->addTab(about_the_game, QString());

        gridLayout->addWidget(tabl_snake, 0, 0, 1, 1);

        root->setCentralWidget(main_window);

        retranslateUi(root);

        tabl_snake->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(root);
    } // setupUi

    void retranslateUi(QMainWindow *root)
    {
        root->setWindowTitle(QCoreApplication::translate("root", "root", nullptr));
        text_menu->setText(QCoreApplication::translate("root", "\320\227\320\274\320\265\320\271\320\272\320\260 QtE", nullptr));
        transition_game->setText(QCoreApplication::translate("root", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
        transition_about_game->setText(QCoreApplication::translate("root", "\320\236\320\261 \320\270\320\263\321\200\320\265", nullptr));
        exit_button->setText(QCoreApplication::translate("root", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        tabl_snake->setTabText(tabl_snake->indexOf(menu), QCoreApplication::translate("root", "menu", nullptr));
        text_game->setText(QCoreApplication::translate("root", "\320\227\320\274\320\265\320\271\320\272\320\260 QtE", nullptr));
        end_text->setText(QCoreApplication::translate("root", "\320\232\320\276\320\275\320\265\321\206 \320\270\320\263\321\200\321\213", nullptr));
        end_win_text->setText(QCoreApplication::translate("root", "\320\235\320\270\321\207\321\214\321\217", nullptr));
        start_over->setText(QCoreApplication::translate("root", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\267\320\260\320\275\320\276\320\262\320\276", nullptr));
        return_menu_end->setText(QCoreApplication::translate("root", "\320\234\320\265\320\275\321\216", nullptr));
        pause_text->setText(QCoreApplication::translate("root", "\320\237\320\260\321\203\320\267\320\260", nullptr));
        continue_pause->setText(QCoreApplication::translate("root", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        return_menu_pause->setText(QCoreApplication::translate("root", "\320\234\320\265\320\275\321\216", nullptr));
        tabl_snake->setTabText(tabl_snake->indexOf(game), QCoreApplication::translate("root", "game", nullptr));
        text_about_game->setText(QCoreApplication::translate("root", "\320\236\320\261 \320\270\320\263\321\200\320\265", nullptr));
        game_descriptions->setText(QCoreApplication::translate("root", "\320\227\320\274\320\265\320\271\320\272\320\260 - \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\275\320\260\321\217 \320\270\320\263\321\200\320\260, \321\203\321\205\320\276\320\264\321\217\321\211\320\260\321\217 \320\272\320\276\321\200\320\275\321\217\320\274\320\270 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 1970-\321\205. \320\235\320\260\320\270\320\261\320\276\320\273\320\265\320\265 \320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\260 \320\262\320\265\321\200\321\201\320\270\321\217 \320\276\321\202 Nokia, \320\262\320\277\320\265\321\200\320\262\321\213\320\265 \320\277\320\276\321\217\320\262\320\270\320\262\321\210\320\260\321\217\321\201\321\217 \320\262 \320\272\320\275\320\276\320\277\320\276\321\207\320\275\320\276\320\274 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\265 Nokia 6110. \320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\260 \321\204\320\270\320\275\320\273\321\217\320"
                        "\275\320\264\321\201\320\272\320\270\320\274 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272\320\276\320\274 \320\242\320\260\320\275\320\265\320\273\320\270 \320\220\321\200\320\274\320\260\320\275\321\202\320\276. \320\230\320\263\321\200\320\276\320\272 \321\203\320\277\321\200\320\260\320\262\320\273\321\217\320\265\321\202 \320\264\320\273\320\270\320\275\320\275\321\213\320\274, \321\202\320\276\320\275\320\272\320\270\320\274 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\276\320\274, \320\275\320\260\320\277\320\276\320\274\320\270\320\275\320\260\321\216\321\211\320\270\320\274 \320\267\320\274\320\265\321\216, \320\272\320\276\321\202\320\276\321\200\320\276\320\265 \320\277\320\276\320\273\320\267\320\260\320\265\321\202 \320\277\320\276 \320\277\320\273\320\276\321\201\320\272\320\276\321\201\321\202\320\270, \321\201\320\276\320\261\320\270\321\200\320\260\321\217 \320\265\320\264\321\203, \320\270\320\267\320\261\320\265\320\263\320\260\321\217"
                        " \321\201\321\202\320\276\320\273\320\272\320\275\320\276\320\262\320\265\320\275\320\270\321\217 \321\201 \321\201\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\274 \321\205\320\262\320\276\321\201\321\202\320\276\320\274. \320\232\320\260\320\266\320\264\321\213\320\271 \321\200\320\260\320\267, \320\272\320\276\320\263\320\264\320\260 \320\267\320\274\320\265\321\217 \321\201\321\212\320\265\320\264\320\260\320\265\321\202 \320\272\321\203\321\201\320\276\320\272 \320\277\320\270\321\211\320\270, \320\276\320\275\320\260 \321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\201\321\217 \320\264\320\273\320\270\320\275\320\275\320\265\320\265, \321\207\321\202\320\276 \320\277\320\276\321\201\321\202\320\265\320\277\320\265\320\275\320\275\320\276 \321\203\321\201\320\273\320\276\320\266\320\275\321\217\320\265\321\202 \320\270\320\263\321\200\321\203.\n"
"\320\224\320\260\320\275\320\275\320\260\321\217 \320\262\320\265\321\200\321\201\320\270\321\217 \320\270\320"
                        "\263\321\200\321\213 \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\260 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260\320\274\320\270 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \320\272\321\203\321\200\321\201\320\260 \320\264\320\273\321\217 \320\272\321\203\321\200\321\201\320\276\320\262\320\276\320\263\320\276 \320\277\321\200\320\276\320\265\320\272\321\202\320\260 \320\277\320\276 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260 \"\320\234\320\265\321\202\320\276\320\264\321\213 \320\270 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\321\213 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217\" \321\201 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \321\204\321\200\320\265\320\271\320\274\320\262\320\276\321\200\320\272\320\260 Qt.\n"
"\320\241\321\201\321\213\320\273\320\272\320\260 \320\275"
                        "\320\260 \321\200\320\270\320\277\320\276\320\267\320\270\321\202\320\276\321\200\320\270\320\271 git: https://github.com/kursach-vega/snake", nullptr));
        about_game_back->setText(QCoreApplication::translate("root", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        tabl_snake->setTabText(tabl_snake->indexOf(about_the_game), QCoreApplication::translate("root", "about_the_game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class root: public Ui_root {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOT_H
