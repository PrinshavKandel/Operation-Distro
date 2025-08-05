#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCalculateGraphClicked();   // Responds to Calculate button
    void onNewFileClicked();          // Responds to New File button
    void onMouseMoveInPlot(QMouseEvent *event);    // Hover interaction

private:
    Ui::MainWindow *ui;

    QVector<double> x;
    QVector<double> y;
public:
    static constexpr int Max_size = 10000;
    static constexpr int NumPoints = 500;

    double data[Max_size];
    int count = 0;

    void updateStatistics(double mean, double mode, double median,
                          double stddev, double variance, double iqr);
    void updateGraph();
    void onupdategrades();
};

#endif // MAINWINDOW_H
