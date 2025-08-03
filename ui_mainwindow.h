#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *line_5;
    QLabel *labelHeader;
    QFrame *line;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *line_4;
    QLabel *labelFooter;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *line_6;
    QLabel *Mean;
    QLabel *labelMean;
    QFrame *line_2;
    QLabel *Median;
    QLabel *labelMedian;
    QFrame *line_3;
    QFrame *line_11;
    QLabel *Mode;
    QLabel *labelMode;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_7;
    QLabel *SD;
    QLabel *labelSD;
    QFrame *line_8;
    QLabel *Var;
    QLabel *labelVar;
    QFrame *line_9;
    QLabel *IQR;
    QLabel *labelIQR;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonNew;
    QFrame *line_10;
    QPushButton *buttonCalc;
    QFrame *line_12;
    QFrame *line_13;
    QCustomPlot *customPlot;
    QFrame *line_14;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1281, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line_5 = new QFrame(verticalLayoutWidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_5);

        labelHeader = new QLabel(verticalLayoutWidget);
        labelHeader->setObjectName("labelHeader");
        QFont font;
        font.setFamilies({QString::fromUtf8("Impact")});
        font.setPointSize(36);
        labelHeader->setFont(font);

        verticalLayout->addWidget(labelHeader, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 690, 1281, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line_4 = new QFrame(verticalLayoutWidget_2);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line_4);

        labelFooter = new QLabel(verticalLayoutWidget_2);
        labelFooter->setObjectName("labelFooter");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Trebuchet MS")});
        font1.setPointSize(8);
        font1.setBold(true);
        labelFooter->setFont(font1);

        verticalLayout_2->addWidget(labelFooter, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 80, 291, 611));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        line_6 = new QFrame(verticalLayoutWidget_3);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line_6);

        Mean = new QLabel(verticalLayoutWidget_3);
        Mean->setObjectName("Mean");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Trebuchet MS")});
        font2.setPointSize(10);
        Mean->setFont(font2);

        verticalLayout_3->addWidget(Mean, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelMean = new QLabel(verticalLayoutWidget_3);
        labelMean->setObjectName("labelMean");
        labelMean->setFont(font2);

        verticalLayout_3->addWidget(labelMean, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        line_2 = new QFrame(verticalLayoutWidget_3);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line_2);

        Median = new QLabel(verticalLayoutWidget_3);
        Median->setObjectName("Median");
        Median->setFont(font2);

        verticalLayout_3->addWidget(Median, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelMedian = new QLabel(verticalLayoutWidget_3);
        labelMedian->setObjectName("labelMedian");
        labelMedian->setFont(font2);

        verticalLayout_3->addWidget(labelMedian, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        line_3 = new QFrame(verticalLayoutWidget_3);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line_3);

        line_11 = new QFrame(verticalLayoutWidget_3);
        line_11->setObjectName("line_11");
        line_11->setFrameShape(QFrame::Shape::VLine);
        line_11->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line_11);

        Mode = new QLabel(verticalLayoutWidget_3);
        Mode->setObjectName("Mode");
        Mode->setFont(font2);

        verticalLayout_3->addWidget(Mode, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelMode = new QLabel(verticalLayoutWidget_3);
        labelMode->setObjectName("labelMode");
        labelMode->setFont(font2);

        verticalLayout_3->addWidget(labelMode, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(990, 80, 291, 611));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        line_7 = new QFrame(verticalLayoutWidget_4);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line_7);

        SD = new QLabel(verticalLayoutWidget_4);
        SD->setObjectName("SD");
        SD->setFont(font2);

        verticalLayout_4->addWidget(SD, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelSD = new QLabel(verticalLayoutWidget_4);
        labelSD->setObjectName("labelSD");
        labelSD->setFont(font2);

        verticalLayout_4->addWidget(labelSD, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        line_8 = new QFrame(verticalLayoutWidget_4);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::Shape::HLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line_8);

        Var = new QLabel(verticalLayoutWidget_4);
        Var->setObjectName("Var");
        Var->setFont(font2);

        verticalLayout_4->addWidget(Var, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelVar = new QLabel(verticalLayoutWidget_4);
        labelVar->setObjectName("labelVar");
        labelVar->setFont(font2);

        verticalLayout_4->addWidget(labelVar, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        line_9 = new QFrame(verticalLayoutWidget_4);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line_9);

        IQR = new QLabel(verticalLayoutWidget_4);
        IQR->setObjectName("IQR");
        IQR->setFont(font2);

        verticalLayout_4->addWidget(IQR, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelIQR = new QLabel(verticalLayoutWidget_4);
        labelIQR->setObjectName("labelIQR");
        labelIQR->setFont(font2);

        verticalLayout_4->addWidget(labelIQR, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(290, 599, 701, 91));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        buttonNew = new QPushButton(horizontalLayoutWidget);
        buttonNew->setObjectName("buttonNew");

        horizontalLayout_2->addWidget(buttonNew);

        line_10 = new QFrame(horizontalLayoutWidget);
        line_10->setObjectName("line_10");
        line_10->setFrameShape(QFrame::Shape::VLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_2->addWidget(line_10);

        buttonCalc = new QPushButton(horizontalLayoutWidget);
        buttonCalc->setObjectName("buttonCalc");

        horizontalLayout_2->addWidget(buttonCalc);

        line_12 = new QFrame(centralwidget);
        line_12->setObjectName("line_12");
        line_12->setGeometry(QRect(980, 80, 20, 611));
        line_12->setFrameShape(QFrame::Shape::VLine);
        line_12->setFrameShadow(QFrame::Shadow::Sunken);
        line_13 = new QFrame(centralwidget);
        line_13->setObjectName("line_13");
        line_13->setGeometry(QRect(290, 591, 701, 20));
        line_13->setFrameShape(QFrame::Shape::HLine);
        line_13->setFrameShadow(QFrame::Shadow::Sunken);
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");
        customPlot->setGeometry(QRect(300, 90, 681, 501));
        line_14 = new QFrame(centralwidget);
        line_14->setObjectName("line_14");
        line_14->setGeometry(QRect(280, 80, 20, 611));
        line_14->setFrameShape(QFrame::Shape::VLine);
        line_14->setFrameShadow(QFrame::Shadow::Sunken);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelHeader->setText(QCoreApplication::translate("MainWindow", "Project Distro", nullptr));
        labelFooter->setText(QCoreApplication::translate("MainWindow", "Aaryan Khadka | Abhinab Badal | Binayak Dhungana | Prinshav Kandel", nullptr));
        Mean->setText(QCoreApplication::translate("MainWindow", "Mean", nullptr));
        labelMean->setText(QString());
        Median->setText(QCoreApplication::translate("MainWindow", "Median", nullptr));
        labelMedian->setText(QString());
        Mode->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        labelMode->setText(QString());
        SD->setText(QCoreApplication::translate("MainWindow", "Standard Deviation", nullptr));
        labelSD->setText(QString());
        Var->setText(QCoreApplication::translate("MainWindow", "Variance", nullptr));
        labelVar->setText(QString());
        IQR->setText(QCoreApplication::translate("MainWindow", "Interquartile Range", nullptr));
        labelIQR->setText(QString());
        buttonNew->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        buttonCalc->setText(QCoreApplication::translate("MainWindow", "Calculate Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
