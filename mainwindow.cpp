#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QToolTip>
#include <QDebug>
#include <cmath>
#include <algorithm>
#include <unordered_map>

struct tstats {
    double mean;
    double median;
    double mode;
    double std_dev;
    double variance;
    double iqr;
};

tstats s;

static double x_vals[MainWindow::NumPoints];
static double y_vals[MainWindow::NumPoints];

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
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
    for (int i = 0; i < n; ++i) sum += arr[i];
    s.mean = sum / n;

    // Median
    s.median = (n % 2 == 0) ? (arr[n / 2 - 1] + arr[n / 2]) / 2.0 : arr[n / 2];

    // Mode
    std::unordered_map<double, int> freq;
    int maxFreq = 0;
    s.mode = arr[0];
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxFreq) {
            maxFreq = freq[arr[i]];
            s.mode = arr[i];
        }
    }

    // Variance & Std Dev
    double var_sum = 0;
    for (int i = 0; i < n; ++i)
        var_sum += std::pow(arr[i] - s.mean, 2);
    s.variance = var_sum / n;
    s.std_dev = std::sqrt(s.variance);

    // IQR
    int mid = n / 2;
    double q1, q3;
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

void generatePDFPoints(double x_vals[], double y_vals[], int points, const tstats &s) {
    double start = s.mean - 4 * s.std_dev;
    double end = s.mean + 4 * s.std_dev;
    double step = (end - start) / (points - 1);

    for (int i = 0; i < points; ++i) {
        double x = start + i * step;
        x_vals[i] = x;
        y_vals[i] = normalPDF(x, s.mean, s.std_dev);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCalc, &QPushButton::clicked, this, &MainWindow::onCalculateGraphClicked);
    connect(ui->buttonNew, &QPushButton::clicked, this, &MainWindow::onNewFileClicked);

    ui->customPlot->setMouseTracking(true);
    connect(ui->customPlot, &QCustomPlot::mouseMove, this, &MainWindow::onMouseMoveInPlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewFileClicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Open File",
        "",
        "Text Files (*.txt);;CSV Files (*.csv);;All Files (*)"
        );

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file.");
        return;
    }

    QTextStream in(&file);
    count = 0;

    // Optional: skip header line if CSV detected
    if (fileName.endsWith(".csv", Qt::CaseInsensitive)) {
        QString header = in.readLine();
        Q_UNUSED(header);
        // If you want, you can check header content here before skipping
    }

    while (!in.atEnd() && count < Max_size) {
        QString line = in.readLine();
        QStringList values = line.split(',', Qt::SkipEmptyParts);
        for (const QString &val : values) {
            bool ok;
            double number = val.trimmed().toDouble(&ok);
            if (ok && count < Max_size) {
                data[count++] = number;
            }
        }
    }
    file.close();

    qDebug() << "Loaded" << count << "data points from" << fileName;
}


void MainWindow::onCalculateGraphClicked()
{
    if (count == 0) {
        QMessageBox::warning(this, "Error", "No data loaded.");
        return;
    }

    calculateStats(data, count, s);
    updateStatistics(s.mean, s.mode, s.median, s.std_dev, s.variance, s.iqr);
    updateGraph();
}

void MainWindow::updateStatistics(double mean, double mode, double median,
                                  double stddev, double variance, double iqr)
{
    ui->labelMean->setText(QString::number(mean, 'f', 2));
    ui->labelMode->setText(QString::number(mode, 'f', 2));
    ui->labelMedian->setText(QString::number(median, 'f', 2));
    ui->labelSD->setText(QString::number(stddev, 'f', 2));
    ui->labelVar->setText(QString::number(variance, 'f', 2));
    ui->labelIQR->setText(QString::number(iqr, 'f', 2));
}

void MainWindow::updateGraph()
{
    generatePDFPoints(x_vals, y_vals, NumPoints, s);

    x.resize(NumPoints);
    y.resize(NumPoints);
    for (int i = 0; i < NumPoints; ++i) {
        x[i] = x_vals[i];
        y[i] = y_vals[i];
    }

    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("Probability Density");
    ui->customPlot->xAxis->setRange(s.mean - 4 * s.std_dev, s.mean + 4 * s.std_dev);
    ui->customPlot->yAxis->rescale();
    ui->customPlot->replot();
}

void MainWindow::onMouseMoveInPlot(QMouseEvent *event)
{
    if (x.isEmpty() || y.isEmpty()) return;

    double xCoord = ui->customPlot->xAxis->pixelToCoord(event->pos().x());

    int closestIndex = -1;
    double minDist = 1e9;

    for (int i = 0; i < x.size(); ++i) {
        double dist = std::abs(x[i] - xCoord);
        if (dist < minDist) {
            minDist = dist;
            closestIndex = i;
        }
    }

    if (closestIndex != -1 && minDist < 0.2) {
        double px = x[closestIndex];
        double py = y[closestIndex];
        QString tooltipText = QString("x: %1\ny: %2")
                                  .arg(px, 0, 'f', 2)
                                  .arg(py, 0, 'f', 4);
        QToolTip::showText(event->globalPos(), tooltipText, ui->customPlot);
    } else {
        QToolTip::hideText();
    }
}
