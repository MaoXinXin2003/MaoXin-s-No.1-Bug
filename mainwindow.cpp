#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Search.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->newAction, &QAction::triggered, this, &MainWindow::newActionSlot);
    connect(ui->openAction_3, &QAction::triggered, this, &MainWindow::openActionSlot);
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveActionSlot);
    connect(ui->Search_1, &QAction::triggered, this, &MainWindow::findActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::openActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件",
                 QCoreApplication::applicationFilePath(), "*.txt");
    if (fileName.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请选择一个文件");
    }
    else
    {
        //qDebug() << fileName;
        QFile file(fileName);    //创建文件对象
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}

void MainWindow::saveActionSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, "选择一个文件",
                QCoreApplication::applicationFilePath());
    if (fileName.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请选择一个文件");
    }
    else
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        //ui->textEdit->toPlainText();
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText());
        file.write(ba);
        file.close();
    }
}

void MainWindow::findActionSlot()
{
    openActionSlot();
    //read txt and turn QString to char*
    QString txt = ui->textEdit->toPlainText();
    QByteArray ba = txt.toLatin1();
    char* ch = ba.data();


}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if (k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_S)
    {
        saveActionSlot();
    }
    if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_N){
        newActionSlot();
    }
    if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_O){
        openActionSlot();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m)
{
    QPoint pt = m->pos();
    qDebug() << pt;

    if (m->button() == Qt::LeftButton)
    {
        qDebug() << "左键被按下";
    }
    else if (m->button() == Qt::RightButton)
    {
        qDebug() << "右键被按下";
    }
}

