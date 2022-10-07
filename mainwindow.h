#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QPainter>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QVideoWidget>
#include <cmath>
#include <vector>
#include "Algorithm.h"
#include "NewCombobox.h"
#include "qcustomplot.h"

#pragma execution_character_set("utf-8")

// 接收缓冲区大小，单位字节
#define BufferSize      50
// 最大帧长度，单位字节
#define MaxFrameLength	40+5			// 对最大帧长度加以限定，防止接收到过长的帧数据
// 完整的帧头，2个字节
#define Frame_Header1   0x3A                    // 串口接收消息包的帧头的第1个字节
#define Frame_Header2   0x3B                    // 串口接收消息包的帧头的第2个字节
// 完整的帧尾，2个字节
#define Frame_Tail1     0x7E                    // 串口接收消息包的帧尾的第1个字节
#define Frame_Tail2     0x7F                    // 串口接收消息包的帧尾的第2个字节

// 功能字1，0x01，自定义波形显示
#define FunWord_WF      0x01
// 功能字2，0x02，信息绘图页面显示，暂时未用
#define FunWord_SM      0x02
// 帧数据中包含有效字节的最大长度
#define ValidByteLength	40			// 对最大帧长度加以限定，防止接收到过长的帧数据

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QCustomPlot *pPlot1;

    // 绘图事件
    void paintEvent(QPaintEvent *);

    void ShowPlot_TimeDemo(QCustomPlot *customPlot, double num);
    void ShowPlot_WaveForm(QCustomPlot *customPlot, double value[]);
    void clearPlot();
    void resetXYRange();


public slots:

    void dataRateCalculate(void);

    void serialPort1Read_Slot();

    void serialPort2Read_Slot();

    void on_btnSwitch_tab1_clicked();

    void on_btnSwitch_tab2_clicked();

    void timerTest_cb();

    void timerAlg_cb();

    void on_pushButton_control_clicked();

    void on_pushButton_pause_clicked();

    void on_comboBox_camId_clicked();

    void on_cmbSerialPort_tab1_clicked();

    void on_cmbSerialPort_tab2_clicked();

private slots:
    void on_chkShowLegend_stateChanged(int arg1);

    void on_btnColourBack_clicked();

    void on_btnClearGraphs_clicked();

    void on_txtPointCountX_returnPressed();

    void on_txtPointCountY_returnPressed();

    void on_txtPointOriginX_returnPressed();

    void on_txtPointOriginY_returnPressed();

    void on_chkTrackX_stateChanged(int arg1);

    void on_chkAdjustY_stateChanged(int arg1);

    void on_txtMainScaleNumX_returnPressed();

    void on_txtMainScaleNumY_returnPressed();

    void repPlotCoordinate();

    void MyMouseMoveEvent(QMouseEvent *event);

    void on_pushButton_openCam_clicked();

    void on_radioButton_reverse_clicked(bool checked);

    void on_pushButton_fitting_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort *mySerialPort;
    QSerialPort *mySerialPort_tab1;
    QSerialPort *mySerialPort_tab2;
    QList<QSerialPortInfo> serialPorts;

    // 发送、接收字节计数
    long sendNum=0, recvNum=0, tSend=0, tRecv=0;// 发送/接收数量，历史发送/接收数量，Byte
    long sendNum_tab1 = 0, recvNum_tab1 = 0;
    long sendNum_tab2 = 0, recvNum_tab2 = 0;
    long sendRate=0, recvRate=0;// 发送/接收速率，Byte/s
    long recvFrameNum=0, recvFrameRate=0, recvErrorNum=0, tFrame=0;// 接收的有效帧数，帧速率，误码帧数量，历史帧数量
    QLabel *lblSendNum, *lblRecvNum, *lblSendRate, *lblRecvRate, *lblRecvFrameNum, *lblFrameRate;

    void setNumOnLabel(QLabel *lbl, QString strS, long num);

    /* 与帧过滤有关的标志位 */
    //int snum = 0;                               // 系统串口接收缓存区的可用字节数
    int tnum = 0;                               // 用户串口接收缓存的指针位置
    unsigned char chrtmp[BufferSize];           // 用户串口接收缓存，将缓存的数据放入这里处理
    int f_h1_flag = 0;                          // 接收到帧头的第一个字节标志位
    int f_h_flag = 0;                           // 接收到帧头标志位
    int f_t1_flag = 0;                          // 接收到帧尾的第一个字节标志位
    // 即是标志位，也包含信息
    int f_fun_word = 0;                         // 功能字，限定为0x01、0x02
    int f_length = 0;                           // 帧数据中包含有效字节的长度

    // 定时发送-定时器
    QTimer *timSend;
    QTimer *timSend_tab1;
    QTimer *timSend_tab2;
    // 发送速率、接收速率统计-定时器
    QTimer *timRate;
    QTimer *timRate_tab1;
    QTimer *timRate_tab2;

    QTimer *timerTest;
    double testTime = 0;
    double testBuff[20];
    int testCnt = 0;

    QTimer *timerAlg;
    double algTime = 0;
    Algorithm algorithm;
    bool pause_flag;
    bool control_flag;

    /*第二页显示部分*/
    // 绘图控件中曲线的指针
    bool showVelFlag = false;
    QCPGraph *pCurve[4];
    // 绘图框X轴显示的坐标点数
    int pointOriginX = 0;
    int pointOriginY = 0;
    int pointCountX = 0;
    int pointCountY = 0;

    double cnt = 0;// 当前绘图的X坐标

    // ui界面中，选择曲线可见性的checkBox的指针。方便用指针数组写代码，不然很占地方
    QCheckBox *pChkVisibleCurve[2];
    // ui界面中，选择曲线颜色的pushButton的指针。方便用指针数组写代码，不然很占地方
    QPushButton *pBtnColourCurve[2];
    // ui界面中，曲线当前值的lineEdit的指针。方便用指针数组写代码，不然很占地方
    QLineEdit *pTxtValueCurve[2];
    // ui界面中，选择曲线粗细的radioButton的指针。方便用指针数组写代码，不然很占地方
    QRadioButton *pRdoBoldCurve[2];
    // ui界面中，选择曲线样式的cmbLineStyle的指针。方便用指针数组写代码，不然很占地方
    QComboBox *pCmbLineStyle[2];
    // ui界面中，选择散点样式的cmbScatterStyle的指针。方便用指针数组写代码，不然很占地方
    QComboBox *pCmbScatterStyle[2];

    /*摄像头部分*/
    QList<QCameraInfo> cameras;
    QCamera* camera;
    QCameraImageCapture* imageCapture;
    QTimer* timerImg;

    void QPlot_init(QCustomPlot *customPlot);
    void QPlot_widget_init(void);

    void curveSetVisible(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1);
    void curveSetColor(QCustomPlot *pPlot, QCPGraph *pCurve, QPushButton *btn);
    void curveSetBold(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1);
    void curveSetLineStyle(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1);
    void curveSetScatterStyle(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1);

    void setAutoTrackX(QCustomPlot *pPlot);
    void setManualSettingX(QCustomPlot *pPlot);
    void setAutoTrackY(QCustomPlot *pPlot);
};
#endif // MAINWINDOW_H
