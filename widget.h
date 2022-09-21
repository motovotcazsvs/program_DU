#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    //void buttonAction();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QPushButton *button_convert;
    QStandardItemModel *item_model_files;
    QMediaPlaylist *pl_list;
    QMediaPlayer *m_player;
    QString open_save_folder;
    QLabel test_info;
    QStringList files;

};

#endif // WIDGET_H
