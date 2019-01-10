#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDesktopWidget>
#include <QHeaderView>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),table(NULL),sbet(NULL),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout * layout = new QVBoxLayout(this->centralWidget());

    //Init table
    table = new QTableWidget();
    table->setColumnCount(17);
    table->setGeometry(QApplication::desktop()->screenGeometry());

    tableHeader << "Timestamp" << "Latitude" << "Longitude" << "Altitude" << "X Speed" << "Y Speed" << "Z Speed" << "Heading" << "Pitch" << "Roll" << "Wander" << "X Force" << "Y Force" << "Z Force" << "X Angular Rate" << "Y Angular Rate" << "Z Angular Rate" ;
    table->setHorizontalHeaderLabels(tableHeader);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QHeaderView* header = table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(table);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open SBET File"), "",
            tr("SBET File (*.sbet);;All Files (*)"));

    std::string cleanFileName = fileName.toLocal8Bit().constData();

    QtSbetProcessor * sbet = new QtSbetProcessor(table);
    sbet->readFile(cleanFileName);
}

void MainWindow::on_actionExport_As_Text_triggered()
{
    //TODO: export as ASCII
}

void MainWindow::on_actionAbout_triggered()
{
    //TODO: show about dialog
}
