#include "widget.h"
#include "ui_widget.h"

#include <QStandardItemModel>
//#include <QTableView>
#include <QFileDialog>
#include <QDir>
#include <QFile>

#include <QLineEdit>
//#include <QGridLayout>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



/*
    QGridLayout *l = new QGridLayout();
    l->addWidget(new QPushButton("Convert files"));
    setLayout(l);
*/
    //addWidget(new QPushButton("Convert files"));

    // создаем кнопку
    //button_convert = new QPushButton("Convert files", this);
    //m_button->resize(200, 100);//установка размеров кнопки
    // устанавливаем размер и положение кнопки
   // button_convert->setGeometry(QRect(QPoint(100, 100), QSize(200, 200)));

    //connect(button_convert, SIGNAL(clicked()), this, SLOT(buttonAction()));



/*
    QTableView  *tableView = new QTableView(this);
    QStandardItemModel *model = new QStandardItemModel(3,3, tableView);
    tableView->setModel(model);

    for(int row=0; row!=model->rowCount(); ++row){
        for(int column=0; column!=model->columnCount(); ++column){
            QStandardItem *newItem = new QStandardItem(tr("%1").arg((row+1)*(column+1)));
            model->setItem(row, column, newItem);
        }
    }
*/

    item_model_files = new QStandardItemModel(this);
    ui->tableView->setModel(item_model_files);
    item_model_files->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track") << tr("File Path"));
    ui->tableView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
    // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    m_player = new QMediaPlayer(this);          // Инициализируем плеер
    pl_list = new QMediaPlaylist(m_player);  // Инициализируем плейлист
    m_player->setPlaylist(pl_list);          // Устанавливаем плейлист в плеер
    m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
    pl_list->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрыван


}
/*
void Widget::buttonAction()
{
    button_convert->setText("pressed");
}
*/
Widget::~Widget()
{
    delete ui;
    delete item_model_files;
    delete pl_list;
    delete m_player;
}

void Widget::on_pushButton_clicked()
{
    QStringList files2 = QFileDialog::getOpenFileNames(this, tr("Open files"), QString("C:/"), tr("Audio Files (*.mp3)"));
    files.append(files2);

    foreach (QString filePath, files2) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        item_model_files->appendRow(items);
        pl_list->addMedia(QUrl(filePath));
    }
}

void Widget::on_pushButton_2_clicked()
{
    QString str_int1;
    QString str_int2;
    QString main_str;
    int num_track;

    QString si = ui->lineEdit->text();
    num_track = si.toInt();

    foreach (QString filePath2, files) {
        main_str = open_save_folder;
        if(num_track < 10) str_int1 = "000";
        else if(num_track < 100) str_int1 = "00";
        else if(num_track < 1000) str_int1 = "0";
        else str_int1 = "";
        str_int2.setNum(num_track);
        main_str.append(str_int1);
        main_str.append(str_int2);
        main_str.append(".mp3");
        QFile::copy(filePath2, main_str);
        num_track++;
    }
}

void Widget::on_pushButton_3_clicked()
{
    open_save_folder = QFileDialog::getExistingDirectory(0, "Directory Dialog", "C:/");
    open_save_folder.append("/");
}
