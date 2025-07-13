#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //Connects .ui file to this window
    connect(ui->buttonCalc, &QPushButton::clicked, this, &MainWindow::onCalculateGraphClicked);
    connect(ui->buttonNew, &QPushButton::clicked, this, &MainWindow::onNewFileClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Placeholder for adding .csv file
void MainWindow::onNewFileClicked()
{

}

//Example Variables
void MainWindow::onCalculateGraphClicked()
{
    double mean = 72.4;
    double mode = 70.0;
    double median = 73.0;
    double stddev = 4.6;
    double variance = 21.2;
    double iqr = 9.0;
    updateStatistics(mean, mode, median, stddev, variance, iqr); //Called when buttonCalc is clicked to update values
    updateGraph(); //Called when buttonCalc is clicked to update graph
}

//Numerical Result Display
void MainWindow::updateStatistics(double mean, double mode, double median, double stddev, double variance, double iqr)
{
    ui->labelMean->setText(QString::number(mean, 'f', 2));
    ui->labelMode->setText(QString::number(mode, 'f', 2));
    ui->labelMedian->setText(QString::number(median, 'f', 2));
    ui->labelSD->setText(QString::number(stddev, 'f', 2));
    ui->labelVar->setText(QString::number(variance, 'f', 2));
    ui->labelIQR->setText(QString::number(iqr, 'f', 2));
}


//Plots graph based on the given values
void MainWindow::updateGraph()
{

}
