#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QStringList>

#include "qtsbetprocessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionOpen_triggered();

    void on_actionExport_As_Text_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;

    QTableWidget   *table;
    QStringList     tableHeader;

    QtSbetProcessor * sbet;
};

#endif // MAINWINDOW_H
