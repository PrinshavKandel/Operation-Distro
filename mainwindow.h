#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCalculateGraphClicked(); //Responds to buttonCalc clicks
    void onNewFileClicked(); // Responds to buttonNew clicks

private:
    Ui::MainWindow *ui;
    static constexpr int Max_size = 1000;
    double data[Max_size];
    int count = 0;
    void updateStatistics(double mean, double mode, double median, double stddev, double variance, double iqr);
    void updateGraph();
};
#endif // MAINWINDOW_H
