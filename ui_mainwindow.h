/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "NewCombobox.h"
#include "qcustomplot.h"
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_6;
    QGridLayout *gridLayout_6;
    QCustomPlot *winPlot;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QToolBox *toolBox;
    QWidget *page_serialPortCfg;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QComboBox *cmbCheck_tab1;
    QLabel *lblBaudRate_tab1;
    QPushButton *btnSwitch_tab1;
    QComboBox *cmbStop_tab1;
    QLabel *lblStop_tab1;
    NewCombobox *cmbSerialPort_tab1;
    QLabel *lblSerialPort_tab1;
    QLabel *lblSwitch_tab1;
    QComboBox *cmbData_tab1;
    QLabel *lblData_tab1;
    QComboBox *cmbBaudRate_tab1;
    QLabel *lblCheck_tab1;
    QWidget *tab_6;
    QGridLayout *gridLayout_5;
    QLabel *lblSerialPort_tab2;
    NewCombobox *cmbSerialPort_tab2;
    QLabel *lblBaudRate_tab2;
    QComboBox *cmbBaudRate_tab2;
    QLabel *lblStop_tab2;
    QComboBox *cmbStop_tab2;
    QLabel *lblData_tab2;
    QComboBox *cmbData_tab2;
    QLabel *lblCheck_tab2;
    QComboBox *cmbCheck_tab2;
    QLabel *lblSwitch_tab2;
    QPushButton *btnSwitch_tab2;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_curveCfg;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_3;
    QLineEdit *txtValueCurve1;
    QRadioButton *rdoBoldCurve1;
    QCheckBox *chkVisibleCurve1;
    QPushButton *btnColourCurve1;
    QComboBox *cmbScatterStyle1;
    QComboBox *cmbLineStyle1;
    QFrame *line;
    QWidget *widget_4;
    QLineEdit *txtValueCurve2;
    QRadioButton *rdoBoldCurve2;
    QCheckBox *chkVisibleCurve2;
    QPushButton *btnColourCurve2;
    QComboBox *cmbLineStyle2;
    QComboBox *cmbScatterStyle2;
    QFrame *line_2;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QCheckBox *chkShowLegend;
    QLabel *label_2;
    QLineEdit *txtMainScaleNumX;
    QLabel *label_3;
    QLineEdit *txtMainScaleNumY;
    QPushButton *btnClearGraphs;
    QPushButton *btnResetSettings;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnColourBack;
    QLabel *label;
    QCheckBox *chkDrawDemo;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *chkTrackX;
    QCheckBox *chkAdjustY;
    QFrame *FramePagePoint;
    QGridLayout *gridLayout_2;
    QLabel *lblPointOrigin;
    QLabel *lblPointCount;
    QLabel *lblPointCountX;
    QLineEdit *txtPointOriginX;
    QLineEdit *txtPointCountX;
    QLabel *lblPointCountY;
    QLineEdit *txtPointOriginY;
    QLineEdit *txtPointCountY;
    QSpacerItem *verticalSpacer;
    QWidget *page_imageCfg;
    QVBoxLayout *verticalLayout;
    QVideoWidget *widget_image;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_openCam;
    NewCombobox *comboBox_camId;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioButton_reverse;
    QRadioButton *radioButton_realTimeSpeed;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_startTime;
    QLineEdit *lineEdit_startTime;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_fittingTime;
    QLineEdit *lineEdit_fittingTime;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_endTime_3;
    QLineEdit *lineEdit_endTime;
    QPushButton *pushButton_fitting;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_control;
    QPushButton *pushButton_pause;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 838);
        MainWindow->setMinimumSize(QSize(240, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        winPlot = new QCustomPlot(frame_6);
        winPlot->setObjectName(QString::fromUtf8("winPlot"));

        gridLayout_6->addWidget(winPlot, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_6);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(380, 0));
        frame_2->setMaximumSize(QSize(380, 16777215));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 0, -1);
        toolBox = new QToolBox(frame_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setCursor(QCursor(Qt::ArrowCursor));
        toolBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBox->setStyleSheet(QString::fromUtf8(""));
        toolBox->setFrameShape(QFrame::Box);
        toolBox->setFrameShadow(QFrame::Sunken);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        page_serialPortCfg = new QWidget();
        page_serialPortCfg->setObjectName(QString::fromUtf8("page_serialPortCfg"));
        page_serialPortCfg->setGeometry(QRect(0, 0, 363, 552));
        verticalLayout_7 = new QVBoxLayout(page_serialPortCfg);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget = new QTabWidget(page_serialPortCfg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        cmbCheck_tab1 = new QComboBox(tab_5);
        cmbCheck_tab1->addItem(QString());
        cmbCheck_tab1->addItem(QString());
        cmbCheck_tab1->addItem(QString());
        cmbCheck_tab1->setObjectName(QString::fromUtf8("cmbCheck_tab1"));

        gridLayout_4->addWidget(cmbCheck_tab1, 4, 1, 1, 1);

        lblBaudRate_tab1 = new QLabel(tab_5);
        lblBaudRate_tab1->setObjectName(QString::fromUtf8("lblBaudRate_tab1"));

        gridLayout_4->addWidget(lblBaudRate_tab1, 1, 0, 1, 1);

        btnSwitch_tab1 = new QPushButton(tab_5);
        btnSwitch_tab1->setObjectName(QString::fromUtf8("btnSwitch_tab1"));

        gridLayout_4->addWidget(btnSwitch_tab1, 5, 1, 1, 1);

        cmbStop_tab1 = new QComboBox(tab_5);
        cmbStop_tab1->addItem(QString());
        cmbStop_tab1->addItem(QString());
        cmbStop_tab1->addItem(QString());
        cmbStop_tab1->setObjectName(QString::fromUtf8("cmbStop_tab1"));

        gridLayout_4->addWidget(cmbStop_tab1, 2, 1, 1, 1);

        lblStop_tab1 = new QLabel(tab_5);
        lblStop_tab1->setObjectName(QString::fromUtf8("lblStop_tab1"));

        gridLayout_4->addWidget(lblStop_tab1, 2, 0, 1, 1);

        cmbSerialPort_tab1 = new NewCombobox(tab_5);
        cmbSerialPort_tab1->setObjectName(QString::fromUtf8("cmbSerialPort_tab1"));

        gridLayout_4->addWidget(cmbSerialPort_tab1, 0, 1, 1, 1);

        lblSerialPort_tab1 = new QLabel(tab_5);
        lblSerialPort_tab1->setObjectName(QString::fromUtf8("lblSerialPort_tab1"));

        gridLayout_4->addWidget(lblSerialPort_tab1, 0, 0, 1, 1);

        lblSwitch_tab1 = new QLabel(tab_5);
        lblSwitch_tab1->setObjectName(QString::fromUtf8("lblSwitch_tab1"));

        gridLayout_4->addWidget(lblSwitch_tab1, 5, 0, 1, 1);

        cmbData_tab1 = new QComboBox(tab_5);
        cmbData_tab1->addItem(QString());
        cmbData_tab1->addItem(QString());
        cmbData_tab1->addItem(QString());
        cmbData_tab1->addItem(QString());
        cmbData_tab1->setObjectName(QString::fromUtf8("cmbData_tab1"));

        gridLayout_4->addWidget(cmbData_tab1, 3, 1, 1, 1);

        lblData_tab1 = new QLabel(tab_5);
        lblData_tab1->setObjectName(QString::fromUtf8("lblData_tab1"));

        gridLayout_4->addWidget(lblData_tab1, 3, 0, 1, 1);

        cmbBaudRate_tab1 = new QComboBox(tab_5);
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->addItem(QString());
        cmbBaudRate_tab1->setObjectName(QString::fromUtf8("cmbBaudRate_tab1"));
        cmbBaudRate_tab1->setEditable(true);
        cmbBaudRate_tab1->setMaxVisibleItems(20);

        gridLayout_4->addWidget(cmbBaudRate_tab1, 1, 1, 1, 1);

        lblCheck_tab1 = new QLabel(tab_5);
        lblCheck_tab1->setObjectName(QString::fromUtf8("lblCheck_tab1"));

        gridLayout_4->addWidget(lblCheck_tab1, 4, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_5 = new QGridLayout(tab_6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lblSerialPort_tab2 = new QLabel(tab_6);
        lblSerialPort_tab2->setObjectName(QString::fromUtf8("lblSerialPort_tab2"));

        gridLayout_5->addWidget(lblSerialPort_tab2, 0, 0, 1, 1);

        cmbSerialPort_tab2 = new NewCombobox(tab_6);
        cmbSerialPort_tab2->setObjectName(QString::fromUtf8("cmbSerialPort_tab2"));

        gridLayout_5->addWidget(cmbSerialPort_tab2, 0, 1, 1, 1);

        lblBaudRate_tab2 = new QLabel(tab_6);
        lblBaudRate_tab2->setObjectName(QString::fromUtf8("lblBaudRate_tab2"));

        gridLayout_5->addWidget(lblBaudRate_tab2, 1, 0, 1, 1);

        cmbBaudRate_tab2 = new QComboBox(tab_6);
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->addItem(QString());
        cmbBaudRate_tab2->setObjectName(QString::fromUtf8("cmbBaudRate_tab2"));
        cmbBaudRate_tab2->setEditable(true);
        cmbBaudRate_tab2->setMaxVisibleItems(20);

        gridLayout_5->addWidget(cmbBaudRate_tab2, 1, 1, 1, 1);

        lblStop_tab2 = new QLabel(tab_6);
        lblStop_tab2->setObjectName(QString::fromUtf8("lblStop_tab2"));

        gridLayout_5->addWidget(lblStop_tab2, 2, 0, 1, 1);

        cmbStop_tab2 = new QComboBox(tab_6);
        cmbStop_tab2->addItem(QString());
        cmbStop_tab2->addItem(QString());
        cmbStop_tab2->addItem(QString());
        cmbStop_tab2->setObjectName(QString::fromUtf8("cmbStop_tab2"));

        gridLayout_5->addWidget(cmbStop_tab2, 2, 1, 1, 1);

        lblData_tab2 = new QLabel(tab_6);
        lblData_tab2->setObjectName(QString::fromUtf8("lblData_tab2"));

        gridLayout_5->addWidget(lblData_tab2, 3, 0, 1, 1);

        cmbData_tab2 = new QComboBox(tab_6);
        cmbData_tab2->addItem(QString());
        cmbData_tab2->addItem(QString());
        cmbData_tab2->addItem(QString());
        cmbData_tab2->addItem(QString());
        cmbData_tab2->setObjectName(QString::fromUtf8("cmbData_tab2"));

        gridLayout_5->addWidget(cmbData_tab2, 3, 1, 1, 1);

        lblCheck_tab2 = new QLabel(tab_6);
        lblCheck_tab2->setObjectName(QString::fromUtf8("lblCheck_tab2"));

        gridLayout_5->addWidget(lblCheck_tab2, 4, 0, 1, 1);

        cmbCheck_tab2 = new QComboBox(tab_6);
        cmbCheck_tab2->addItem(QString());
        cmbCheck_tab2->addItem(QString());
        cmbCheck_tab2->addItem(QString());
        cmbCheck_tab2->setObjectName(QString::fromUtf8("cmbCheck_tab2"));

        gridLayout_5->addWidget(cmbCheck_tab2, 4, 1, 1, 1);

        lblSwitch_tab2 = new QLabel(tab_6);
        lblSwitch_tab2->setObjectName(QString::fromUtf8("lblSwitch_tab2"));

        gridLayout_5->addWidget(lblSwitch_tab2, 5, 0, 1, 1);

        btnSwitch_tab2 = new QPushButton(tab_6);
        btnSwitch_tab2->setObjectName(QString::fromUtf8("btnSwitch_tab2"));

        gridLayout_5->addWidget(btnSwitch_tab2, 5, 1, 1, 1);

        tabWidget->addTab(tab_6, QString());

        verticalLayout_7->addWidget(tabWidget);

        verticalSpacer_3 = new QSpacerItem(20, 238, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        toolBox->addItem(page_serialPortCfg, QString::fromUtf8("\344\270\262\345\217\243\351\205\215\347\275\256"));
        page_curveCfg = new QWidget();
        page_curveCfg->setObjectName(QString::fromUtf8("page_curveCfg"));
        page_curveCfg->setGeometry(QRect(0, 0, 363, 552));
        verticalLayout_4 = new QVBoxLayout(page_curveCfg);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_3 = new QWidget(page_curveCfg);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(335, 22));
        widget_3->setMaximumSize(QSize(16777215, 22));
        txtValueCurve1 = new QLineEdit(widget_3);
        txtValueCurve1->setObjectName(QString::fromUtf8("txtValueCurve1"));
        txtValueCurve1->setGeometry(QRect(110, 0, 71, 20));
        rdoBoldCurve1 = new QRadioButton(widget_3);
        rdoBoldCurve1->setObjectName(QString::fromUtf8("rdoBoldCurve1"));
        rdoBoldCurve1->setGeometry(QRect(90, 3, 16, 16));
        rdoBoldCurve1->setChecked(false);
        chkVisibleCurve1 = new QCheckBox(widget_3);
        chkVisibleCurve1->setObjectName(QString::fromUtf8("chkVisibleCurve1"));
        chkVisibleCurve1->setGeometry(QRect(0, 3, 53, 16));
        chkVisibleCurve1->setChecked(true);
        btnColourCurve1 = new QPushButton(widget_3);
        btnColourCurve1->setObjectName(QString::fromUtf8("btnColourCurve1"));
        btnColourCurve1->setGeometry(QRect(60, 0, 21, 21));
        cmbScatterStyle1 = new QComboBox(widget_3);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/ssNone.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/ssCross.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/ssPlus.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/ssCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/ssDisc.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/pic/ssSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/pic/ssDiamond.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/pic/ssStar.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/pic/ssTriangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/pic/ssTriangleInverted.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon9, QString());
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/pic/ssCrossSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/pic/ssPlusSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon11, QString());
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/pic/ssCrossCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon12, QString());
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/pic/ssPlusCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon13, QString());
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/pic/ssPeace.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon14, QString());
        cmbScatterStyle1->setObjectName(QString::fromUtf8("cmbScatterStyle1"));
        cmbScatterStyle1->setGeometry(QRect(240, 0, 91, 20));
        cmbScatterStyle1->setFocusPolicy(Qt::WheelFocus);
        cmbScatterStyle1->setMaxVisibleItems(20);
        cmbLineStyle1 = new QComboBox(widget_3);
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->setObjectName(QString::fromUtf8("cmbLineStyle1"));
        cmbLineStyle1->setGeometry(QRect(190, 0, 41, 20));

        verticalLayout_4->addWidget(widget_3);

        line = new QFrame(page_curveCfg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        widget_4 = new QWidget(page_curveCfg);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 22));
        widget_4->setMaximumSize(QSize(16777215, 22));
        txtValueCurve2 = new QLineEdit(widget_4);
        txtValueCurve2->setObjectName(QString::fromUtf8("txtValueCurve2"));
        txtValueCurve2->setGeometry(QRect(110, 0, 71, 20));
        rdoBoldCurve2 = new QRadioButton(widget_4);
        rdoBoldCurve2->setObjectName(QString::fromUtf8("rdoBoldCurve2"));
        rdoBoldCurve2->setGeometry(QRect(90, 3, 16, 16));
        rdoBoldCurve2->setChecked(false);
        chkVisibleCurve2 = new QCheckBox(widget_4);
        chkVisibleCurve2->setObjectName(QString::fromUtf8("chkVisibleCurve2"));
        chkVisibleCurve2->setEnabled(true);
        chkVisibleCurve2->setGeometry(QRect(0, 3, 53, 16));
        chkVisibleCurve2->setChecked(true);
        btnColourCurve2 = new QPushButton(widget_4);
        btnColourCurve2->setObjectName(QString::fromUtf8("btnColourCurve2"));
        btnColourCurve2->setGeometry(QRect(60, 0, 21, 21));
        cmbLineStyle2 = new QComboBox(widget_4);
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->setObjectName(QString::fromUtf8("cmbLineStyle2"));
        cmbLineStyle2->setGeometry(QRect(190, 0, 41, 20));
        cmbScatterStyle2 = new QComboBox(widget_4);
        cmbScatterStyle2->addItem(icon, QString());
        cmbScatterStyle2->addItem(icon1, QString());
        cmbScatterStyle2->addItem(icon2, QString());
        cmbScatterStyle2->addItem(icon3, QString());
        cmbScatterStyle2->addItem(icon4, QString());
        cmbScatterStyle2->addItem(icon5, QString());
        cmbScatterStyle2->addItem(icon6, QString());
        cmbScatterStyle2->addItem(icon7, QString());
        cmbScatterStyle2->addItem(icon8, QString());
        cmbScatterStyle2->addItem(icon9, QString());
        cmbScatterStyle2->addItem(icon10, QString());
        cmbScatterStyle2->addItem(icon11, QString());
        cmbScatterStyle2->addItem(icon12, QString());
        cmbScatterStyle2->addItem(icon13, QString());
        cmbScatterStyle2->addItem(icon14, QString());
        cmbScatterStyle2->setObjectName(QString::fromUtf8("cmbScatterStyle2"));
        cmbScatterStyle2->setGeometry(QRect(240, 0, 91, 20));
        cmbScatterStyle2->setFocusPolicy(Qt::WheelFocus);
        cmbScatterStyle2->setMaxVisibleItems(20);

        verticalLayout_4->addWidget(widget_4);

        line_2 = new QFrame(page_curveCfg);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        widget = new QWidget(page_curveCfg);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        chkShowLegend = new QCheckBox(widget);
        chkShowLegend->setObjectName(QString::fromUtf8("chkShowLegend"));
        chkShowLegend->setChecked(true);

        gridLayout_3->addWidget(chkShowLegend, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        txtMainScaleNumX = new QLineEdit(widget);
        txtMainScaleNumX->setObjectName(QString::fromUtf8("txtMainScaleNumX"));

        gridLayout_3->addWidget(txtMainScaleNumX, 1, 1, 1, 2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        txtMainScaleNumY = new QLineEdit(widget);
        txtMainScaleNumY->setObjectName(QString::fromUtf8("txtMainScaleNumY"));

        gridLayout_3->addWidget(txtMainScaleNumY, 2, 1, 1, 2);

        btnClearGraphs = new QPushButton(widget);
        btnClearGraphs->setObjectName(QString::fromUtf8("btnClearGraphs"));

        gridLayout_3->addWidget(btnClearGraphs, 3, 0, 1, 1);

        btnResetSettings = new QPushButton(widget);
        btnResetSettings->setObjectName(QString::fromUtf8("btnResetSettings"));

        gridLayout_3->addWidget(btnResetSettings, 3, 1, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnColourBack = new QPushButton(widget);
        btnColourBack->setObjectName(QString::fromUtf8("btnColourBack"));
        btnColourBack->setMinimumSize(QSize(21, 21));
        btnColourBack->setMaximumSize(QSize(21, 21));

        horizontalLayout_4->addWidget(btnColourBack);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);


        gridLayout_3->addLayout(horizontalLayout_4, 4, 0, 1, 2);

        chkDrawDemo = new QCheckBox(widget);
        chkDrawDemo->setObjectName(QString::fromUtf8("chkDrawDemo"));
        chkDrawDemo->setChecked(false);

        gridLayout_3->addWidget(chkDrawDemo, 4, 2, 1, 1);


        verticalLayout_4->addWidget(widget);

        widget_6 = new QWidget(page_curveCfg);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_7 = new QHBoxLayout(widget_6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        chkTrackX = new QCheckBox(widget_6);
        chkTrackX->setObjectName(QString::fromUtf8("chkTrackX"));
        chkTrackX->setChecked(true);

        verticalLayout_5->addWidget(chkTrackX);

        chkAdjustY = new QCheckBox(widget_6);
        chkAdjustY->setObjectName(QString::fromUtf8("chkAdjustY"));

        verticalLayout_5->addWidget(chkAdjustY);


        horizontalLayout_7->addLayout(verticalLayout_5);

        FramePagePoint = new QFrame(widget_6);
        FramePagePoint->setObjectName(QString::fromUtf8("FramePagePoint"));
        FramePagePoint->setFrameShape(QFrame::WinPanel);
        FramePagePoint->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(FramePagePoint);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblPointOrigin = new QLabel(FramePagePoint);
        lblPointOrigin->setObjectName(QString::fromUtf8("lblPointOrigin"));

        gridLayout_2->addWidget(lblPointOrigin, 0, 1, 1, 1);

        lblPointCount = new QLabel(FramePagePoint);
        lblPointCount->setObjectName(QString::fromUtf8("lblPointCount"));

        gridLayout_2->addWidget(lblPointCount, 0, 2, 1, 1);

        lblPointCountX = new QLabel(FramePagePoint);
        lblPointCountX->setObjectName(QString::fromUtf8("lblPointCountX"));

        gridLayout_2->addWidget(lblPointCountX, 1, 0, 1, 1);

        txtPointOriginX = new QLineEdit(FramePagePoint);
        txtPointOriginX->setObjectName(QString::fromUtf8("txtPointOriginX"));
        txtPointOriginX->setMinimumSize(QSize(81, 20));
        txtPointOriginX->setMaximumSize(QSize(81, 20));

        gridLayout_2->addWidget(txtPointOriginX, 1, 1, 1, 1);

        txtPointCountX = new QLineEdit(FramePagePoint);
        txtPointCountX->setObjectName(QString::fromUtf8("txtPointCountX"));
        txtPointCountX->setMinimumSize(QSize(81, 20));
        txtPointCountX->setMaximumSize(QSize(81, 20));
        txtPointCountX->setFocusPolicy(Qt::StrongFocus);

        gridLayout_2->addWidget(txtPointCountX, 1, 2, 1, 1);

        lblPointCountY = new QLabel(FramePagePoint);
        lblPointCountY->setObjectName(QString::fromUtf8("lblPointCountY"));

        gridLayout_2->addWidget(lblPointCountY, 2, 0, 1, 1);

        txtPointOriginY = new QLineEdit(FramePagePoint);
        txtPointOriginY->setObjectName(QString::fromUtf8("txtPointOriginY"));
        txtPointOriginY->setMinimumSize(QSize(81, 20));
        txtPointOriginY->setMaximumSize(QSize(81, 20));

        gridLayout_2->addWidget(txtPointOriginY, 2, 1, 1, 1);

        txtPointCountY = new QLineEdit(FramePagePoint);
        txtPointCountY->setObjectName(QString::fromUtf8("txtPointCountY"));
        txtPointCountY->setMinimumSize(QSize(81, 20));
        txtPointCountY->setMaximumSize(QSize(81, 20));

        gridLayout_2->addWidget(txtPointCountY, 2, 2, 1, 1);


        horizontalLayout_7->addWidget(FramePagePoint);


        verticalLayout_4->addWidget(widget_6);

        verticalSpacer = new QSpacerItem(20, 182, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/chart_curve_32px_506507_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_curveCfg, icon15, QString::fromUtf8("\346\233\262\347\272\277/\346\225\243\347\202\271\350\256\276\347\275\256"));
        page_imageCfg = new QWidget();
        page_imageCfg->setObjectName(QString::fromUtf8("page_imageCfg"));
        page_imageCfg->setGeometry(QRect(0, 0, 363, 552));
        verticalLayout = new QVBoxLayout(page_imageCfg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_image = new QVideoWidget(page_imageCfg);
        widget_image->setObjectName(QString::fromUtf8("widget_image"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_image->sizePolicy().hasHeightForWidth());
        widget_image->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widget_image);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_openCam = new QPushButton(page_imageCfg);
        pushButton_openCam->setObjectName(QString::fromUtf8("pushButton_openCam"));

        horizontalLayout_2->addWidget(pushButton_openCam);

        comboBox_camId = new NewCombobox(page_imageCfg);
        comboBox_camId->setObjectName(QString::fromUtf8("comboBox_camId"));

        horizontalLayout_2->addWidget(comboBox_camId);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        radioButton_reverse = new QRadioButton(page_imageCfg);
        radioButton_reverse->setObjectName(QString::fromUtf8("radioButton_reverse"));
        radioButton_reverse->setChecked(true);
        radioButton_reverse->setAutoExclusive(false);

        horizontalLayout_9->addWidget(radioButton_reverse);

        radioButton_realTimeSpeed = new QRadioButton(page_imageCfg);
        radioButton_realTimeSpeed->setObjectName(QString::fromUtf8("radioButton_realTimeSpeed"));
        radioButton_realTimeSpeed->setAutoExclusive(false);

        horizontalLayout_9->addWidget(radioButton_realTimeSpeed);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_startTime = new QLabel(page_imageCfg);
        label_startTime->setObjectName(QString::fromUtf8("label_startTime"));

        horizontalLayout_6->addWidget(label_startTime);

        lineEdit_startTime = new QLineEdit(page_imageCfg);
        lineEdit_startTime->setObjectName(QString::fromUtf8("lineEdit_startTime"));

        horizontalLayout_6->addWidget(lineEdit_startTime);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_fittingTime = new QLabel(page_imageCfg);
        label_fittingTime->setObjectName(QString::fromUtf8("label_fittingTime"));

        horizontalLayout_5->addWidget(label_fittingTime);

        lineEdit_fittingTime = new QLineEdit(page_imageCfg);
        lineEdit_fittingTime->setObjectName(QString::fromUtf8("lineEdit_fittingTime"));

        horizontalLayout_5->addWidget(lineEdit_fittingTime);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_endTime_3 = new QLabel(page_imageCfg);
        label_endTime_3->setObjectName(QString::fromUtf8("label_endTime_3"));

        horizontalLayout_8->addWidget(label_endTime_3);

        lineEdit_endTime = new QLineEdit(page_imageCfg);
        lineEdit_endTime->setObjectName(QString::fromUtf8("lineEdit_endTime"));

        horizontalLayout_8->addWidget(lineEdit_endTime);


        verticalLayout->addLayout(horizontalLayout_8);

        pushButton_fitting = new QPushButton(page_imageCfg);
        pushButton_fitting->setObjectName(QString::fromUtf8("pushButton_fitting"));

        verticalLayout->addWidget(pushButton_fitting);

        verticalSpacer_2 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/axis_64px_1200251_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_imageCfg, icon16, QString::fromUtf8("\345\256\236\346\227\266\345\233\276\345\203\217"));

        verticalLayout_3->addWidget(toolBox);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(0, 80));
        frame_5->setMaximumSize(QSize(16777215, 80));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_control = new QPushButton(frame_5);
        pushButton_control->setObjectName(QString::fromUtf8("pushButton_control"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_control->sizePolicy().hasHeightForWidth());
        pushButton_control->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_control);

        pushButton_pause = new QPushButton(frame_5);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        sizePolicy1.setHeightForWidth(pushButton_pause->sizePolicy().hasHeightForWidth());
        pushButton_pause->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_pause);


        verticalLayout_3->addWidget(frame_5);


        horizontalLayout_3->addWidget(frame_2);

        horizontalLayout_3->setStretch(1, 1);

        gridLayout->addWidget(frame_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setMinimumSize(QSize(0, 22));
        statusbar->setMaximumSize(QSize(16777215, 22));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(2);
        toolBox->layout()->setSpacing(6);
        tabWidget->setCurrentIndex(0);
        cmbData_tab1->setCurrentIndex(3);
        cmbBaudRate_tab1->setCurrentIndex(10);
        cmbBaudRate_tab2->setCurrentIndex(10);
        cmbData_tab2->setCurrentIndex(3);
        cmbLineStyle1->setCurrentIndex(1);
        cmbLineStyle2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        cmbCheck_tab1->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        cmbCheck_tab1->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        cmbCheck_tab1->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        lblBaudRate_tab1->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        btnSwitch_tab1->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        cmbStop_tab1->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cmbStop_tab1->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        cmbStop_tab1->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        lblStop_tab1->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        lblSerialPort_tab1->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        lblSwitch_tab1->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", nullptr));
        cmbData_tab1->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        cmbData_tab1->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        cmbData_tab1->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        cmbData_tab1->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        lblData_tab1->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        cmbBaudRate_tab1->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        cmbBaudRate_tab1->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        cmbBaudRate_tab1->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        cmbBaudRate_tab1->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cmbBaudRate_tab1->setItemText(4, QCoreApplication::translate("MainWindow", "14400", nullptr));
        cmbBaudRate_tab1->setItemText(5, QCoreApplication::translate("MainWindow", "19200", nullptr));
        cmbBaudRate_tab1->setItemText(6, QCoreApplication::translate("MainWindow", "38400", nullptr));
        cmbBaudRate_tab1->setItemText(7, QCoreApplication::translate("MainWindow", "43000", nullptr));
        cmbBaudRate_tab1->setItemText(8, QCoreApplication::translate("MainWindow", "57600", nullptr));
        cmbBaudRate_tab1->setItemText(9, QCoreApplication::translate("MainWindow", "76800", nullptr));
        cmbBaudRate_tab1->setItemText(10, QCoreApplication::translate("MainWindow", "115200", nullptr));
        cmbBaudRate_tab1->setItemText(11, QCoreApplication::translate("MainWindow", "128000", nullptr));
        cmbBaudRate_tab1->setItemText(12, QCoreApplication::translate("MainWindow", "230400", nullptr));
        cmbBaudRate_tab1->setItemText(13, QCoreApplication::translate("MainWindow", "256000", nullptr));
        cmbBaudRate_tab1->setItemText(14, QCoreApplication::translate("MainWindow", "460800", nullptr));
        cmbBaudRate_tab1->setItemText(15, QCoreApplication::translate("MainWindow", "921600", nullptr));
        cmbBaudRate_tab1->setItemText(16, QCoreApplication::translate("MainWindow", "1382400", nullptr));

        lblCheck_tab1->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\2431", nullptr));
        lblSerialPort_tab2->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        lblBaudRate_tab2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        cmbBaudRate_tab2->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        cmbBaudRate_tab2->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        cmbBaudRate_tab2->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        cmbBaudRate_tab2->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cmbBaudRate_tab2->setItemText(4, QCoreApplication::translate("MainWindow", "14400", nullptr));
        cmbBaudRate_tab2->setItemText(5, QCoreApplication::translate("MainWindow", "19200", nullptr));
        cmbBaudRate_tab2->setItemText(6, QCoreApplication::translate("MainWindow", "38400", nullptr));
        cmbBaudRate_tab2->setItemText(7, QCoreApplication::translate("MainWindow", "43000", nullptr));
        cmbBaudRate_tab2->setItemText(8, QCoreApplication::translate("MainWindow", "57600", nullptr));
        cmbBaudRate_tab2->setItemText(9, QCoreApplication::translate("MainWindow", "76800", nullptr));
        cmbBaudRate_tab2->setItemText(10, QCoreApplication::translate("MainWindow", "115200", nullptr));
        cmbBaudRate_tab2->setItemText(11, QCoreApplication::translate("MainWindow", "128000", nullptr));
        cmbBaudRate_tab2->setItemText(12, QCoreApplication::translate("MainWindow", "230400", nullptr));
        cmbBaudRate_tab2->setItemText(13, QCoreApplication::translate("MainWindow", "256000", nullptr));
        cmbBaudRate_tab2->setItemText(14, QCoreApplication::translate("MainWindow", "460800", nullptr));
        cmbBaudRate_tab2->setItemText(15, QCoreApplication::translate("MainWindow", "921600", nullptr));
        cmbBaudRate_tab2->setItemText(16, QCoreApplication::translate("MainWindow", "1382400", nullptr));

        lblStop_tab2->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        cmbStop_tab2->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cmbStop_tab2->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        cmbStop_tab2->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        lblData_tab2->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        cmbData_tab2->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        cmbData_tab2->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        cmbData_tab2->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        cmbData_tab2->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        lblCheck_tab2->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        cmbCheck_tab2->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        cmbCheck_tab2->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        cmbCheck_tab2->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        lblSwitch_tab2->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", nullptr));
        btnSwitch_tab2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\2432", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_serialPortCfg), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        txtValueCurve1->setText(QString());
        rdoBoldCurve1->setText(QString());
        chkVisibleCurve1->setText(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\2421", nullptr));
        btnColourCurve1->setText(QString());
        cmbScatterStyle1->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\225\243\347\202\271", nullptr));
        cmbScatterStyle1->setItemText(1, QCoreApplication::translate("MainWindow", "x\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(2, QCoreApplication::translate("MainWindow", "+\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(3, QCoreApplication::translate("MainWindow", "\347\251\272\345\277\203\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(4, QCoreApplication::translate("MainWindow", "\345\256\236\345\277\203\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(5, QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(6, QCoreApplication::translate("MainWindow", "\350\217\261\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(7, QCoreApplication::translate("MainWindow", "\346\230\237\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(8, QCoreApplication::translate("MainWindow", "\346\255\243\344\270\211\350\247\222", nullptr));
        cmbScatterStyle1->setItemText(9, QCoreApplication::translate("MainWindow", "\345\200\222\344\270\211\350\247\222", nullptr));
        cmbScatterStyle1->setItemText(10, QCoreApplication::translate("MainWindow", "x\346\241\206", nullptr));
        cmbScatterStyle1->setItemText(11, QCoreApplication::translate("MainWindow", "+\346\241\206", nullptr));
        cmbScatterStyle1->setItemText(12, QCoreApplication::translate("MainWindow", "x\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(13, QCoreApplication::translate("MainWindow", "+\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(14, QCoreApplication::translate("MainWindow", "\345\222\214\345\271\263", nullptr));

        cmbLineStyle1->setItemText(0, QCoreApplication::translate("MainWindow", "\347\202\271", nullptr));
        cmbLineStyle1->setItemText(1, QCoreApplication::translate("MainWindow", "\347\272\277", nullptr));
        cmbLineStyle1->setItemText(2, QCoreApplication::translate("MainWindow", "\345\267\246", nullptr));
        cmbLineStyle1->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\263", nullptr));
        cmbLineStyle1->setItemText(4, QCoreApplication::translate("MainWindow", "\344\270\255", nullptr));
        cmbLineStyle1->setItemText(5, QCoreApplication::translate("MainWindow", "\347\247\257", nullptr));

        txtValueCurve2->setText(QString());
        rdoBoldCurve2->setText(QString());
        chkVisibleCurve2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\2422", nullptr));
        btnColourCurve2->setText(QString());
        cmbLineStyle2->setItemText(0, QCoreApplication::translate("MainWindow", "\347\202\271", nullptr));
        cmbLineStyle2->setItemText(1, QCoreApplication::translate("MainWindow", "\347\272\277", nullptr));
        cmbLineStyle2->setItemText(2, QCoreApplication::translate("MainWindow", "\345\267\246", nullptr));
        cmbLineStyle2->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\263", nullptr));
        cmbLineStyle2->setItemText(4, QCoreApplication::translate("MainWindow", "\344\270\255", nullptr));
        cmbLineStyle2->setItemText(5, QCoreApplication::translate("MainWindow", "\347\247\257", nullptr));

        cmbScatterStyle2->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\225\243\347\202\271", nullptr));
        cmbScatterStyle2->setItemText(1, QCoreApplication::translate("MainWindow", "x\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(2, QCoreApplication::translate("MainWindow", "+\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(3, QCoreApplication::translate("MainWindow", "\347\251\272\345\277\203\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(4, QCoreApplication::translate("MainWindow", "\345\256\236\345\277\203\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(5, QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(6, QCoreApplication::translate("MainWindow", "\350\217\261\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(7, QCoreApplication::translate("MainWindow", "\346\230\237\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(8, QCoreApplication::translate("MainWindow", "\346\255\243\344\270\211\350\247\222", nullptr));
        cmbScatterStyle2->setItemText(9, QCoreApplication::translate("MainWindow", "\345\200\222\344\270\211\350\247\222", nullptr));
        cmbScatterStyle2->setItemText(10, QCoreApplication::translate("MainWindow", "x\346\241\206", nullptr));
        cmbScatterStyle2->setItemText(11, QCoreApplication::translate("MainWindow", "+\346\241\206", nullptr));
        cmbScatterStyle2->setItemText(12, QCoreApplication::translate("MainWindow", "x\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(13, QCoreApplication::translate("MainWindow", "+\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(14, QCoreApplication::translate("MainWindow", "\345\222\214\345\271\263", nullptr));

        chkShowLegend->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\233\276\344\276\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X\350\275\264\344\270\273\345\210\273\345\272\246\346\225\260\357\274\232", nullptr));
        txtMainScaleNumX->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264\344\270\273\345\210\273\345\272\246\346\225\260\357\274\232", nullptr));
        txtMainScaleNumY->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        btnClearGraphs->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\273\230\345\233\276", nullptr));
        btnResetSettings->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\350\256\276\347\275\256", nullptr));
        btnColourBack->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276\345\214\272\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
        chkDrawDemo->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276\346\274\224\347\244\272-\346\233\262\347\272\277", nullptr));
        chkTrackX->setText(QCoreApplication::translate("MainWindow", "X\350\275\264\350\267\237\351\232\217", nullptr));
        chkAdjustY->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264\350\207\252\351\200\202\345\272\224", nullptr));
        lblPointOrigin->setText(QCoreApplication::translate("MainWindow", "\345\216\237\347\202\271\344\275\215\347\275\256", nullptr));
        lblPointCount->setText(QCoreApplication::translate("MainWindow", "\351\241\265\345\271\205\347\202\271\346\225\260", nullptr));
        lblPointCountX->setText(QCoreApplication::translate("MainWindow", "X\357\274\232", nullptr));
        txtPointOriginX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txtPointCountX->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lblPointCountY->setText(QCoreApplication::translate("MainWindow", "Y\357\274\232", nullptr));
        txtPointOriginY->setText(QCoreApplication::translate("MainWindow", "-2", nullptr));
        txtPointCountY->setText(QCoreApplication::translate("MainWindow", "80", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_curveCfg), QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277/\346\225\243\347\202\271\350\256\276\347\275\256", nullptr));
        pushButton_openCam->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        radioButton_reverse->setText(QCoreApplication::translate("MainWindow", "\345\217\215\345\220\221", nullptr));
        radioButton_realTimeSpeed->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\256\236\346\227\266\351\200\237\345\272\246", nullptr));
        label_startTime->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        lineEdit_startTime->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_fittingTime->setText(QCoreApplication::translate("MainWindow", "\347\242\260\346\222\236\346\227\266\351\227\264\357\274\232", nullptr));
        lineEdit_fittingTime->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_endTime_3->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        lineEdit_endTime->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_fitting->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\213\237\345\220\210\351\200\237\345\272\246", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_imageCfg), QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\345\233\276\345\203\217", nullptr));
        pushButton_control->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
