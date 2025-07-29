#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>


// Structure definition
struct tstats {
    double mean;
    double median;
    double mode;
    double std_dev;
    double variance;
    double iqr;
};

tstats s;

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void calculateStats(double arr[], int n, tstats &s) {
    bubbleSort(arr, n);

    // Mean
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    s.mean = sum / n;

    // Median
    if (n % 2 == 0)
        s.median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        s.median = arr[n / 2];

    // Mode
    std::unordered_map<double, int> freq;
    int maxFreq = 0;
    s.mode = arr[0];
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxFreq) {
            maxFreq = freq[arr[i]];
            s.mode = arr[i];
        }
    }

    // Variance & Standard Deviation
    double var_sum = 0;
    for (int i = 0; i < n; i++)
        var_sum += (arr[i] - s.mean) * (arr[i] - s.mean);
    s.variance = var_sum / n;
    s.std_dev = std::sqrt(s.variance);

    // IQR
    double q1, q3;
    int mid = n / 2;
    if (n % 2 == 0) {
        q1 = (arr[mid / 2 - 1] + arr[mid / 2]) / 2.0;
        q3 = (arr[mid + mid / 2 - 1] + arr[mid + mid / 2]) / 2.0;
    } else {
        q1 = arr[mid / 2];
        q3 = arr[mid + mid / 2 + 1];
    }
    s.iqr = q3 - q1;
}

double normalPDF(double x, double mean, double std_dev) {
    const double PI = 3.14159265358979323846;
    double exponent = -0.5 * std::pow((x - mean) / std_dev, 2);
    return (1.0 / (std_dev * std::sqrt(2 * PI))) * std::exp(exponent);
}

void generatePDFPoints(std::vector<double> &x_vals, std::vector<double> &y_vals, const tstats &s, int points = 100) {
    double range_start = s.mean - 4 * s.std_dev;
    double range_end = s.mean + 4 * s.std_dev;
    double step = (range_end - range_start) / points;

    x_vals.clear();
    y_vals.clear();

    for (int i = 0; i <= points; ++i) {
        double x = range_start + i * step;
        double y = normalPDF(x, s.mean, s.std_dev);
        x_vals.push_back(x);
        y_vals.push_back(y);
    }
}

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonCalc, &QPushButton::clicked, this, &MainWindow::onCalculateGraphClicked);
    connect(ui->buttonNew, &QPushButton::clicked, this, &MainWindow::onNewFileClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// File Open (works on Mac & Linux using QFileDialog)
void MainWindow::onNewFileClicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (fileName.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file.";
        return;
    }

    QTextStream in(&file);
    count = 0; // Reset count before loading

    while (!in.atEnd() && count < Max_size) {
        QString line = in.readLine();
        QStringList values = line.split(',');

        for (const QString& value : values) {
            bool ok;
            double number = value.toDouble(&ok);
            if (ok && count < Max_size) {
                data[count++] = number;
            }
        }
    }
    file.close();
    qDebug() << "File loaded with" << count << "values.";
}

// Calculate and Display Stats
void MainWindow::onCalculateGraphClicked()
{
    calculateStats(data, count, s);

    updateStatistics(s.mean, s.mode, s.median, s.std_dev, s.variance, s.iqr);
    //updateGraph(); // Must be implemented elsewhere to show plot
}

// Update the Labels in UI
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
