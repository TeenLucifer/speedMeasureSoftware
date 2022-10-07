#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Qt Serial Debugger");

    // 状态栏
    QStatusBar *sBar = statusBar();
    // 状态栏的收、发计数标签
    lblSendNum = new QLabel(this);
    lblRecvNum = new QLabel(this);
    lblSendRate = new QLabel(this);
    lblRecvRate = new QLabel(this);
    // 设置标签最小大小
    lblSendNum->setMinimumSize(100, 20);
    lblRecvNum->setMinimumSize(100, 20);
    lblSendRate->setMinimumSize(100, 20);
    lblRecvRate->setMinimumSize(100, 20);

    // 状态栏显示计数值
    setNumOnLabel(lblSendNum, "S: ", sendNum);
    setNumOnLabel(lblRecvNum, "R: ", recvNum);
    setNumOnLabel(lblSendRate, "Byte/s: ", 0);
    setNumOnLabel(lblRecvRate, "Byte/s: ", 0);
    // 从右往左依次添加
    sBar->addPermanentWidget(lblSendNum);
    sBar->addPermanentWidget(lblSendRate);
    sBar->addPermanentWidget(lblRecvNum);
    sBar->addPermanentWidget(lblRecvRate);

    lblRecvFrameNum = new QLabel(this);
    lblFrameRate = new QLabel(this);
    lblRecvFrameNum->setMinimumSize(100, 20);
    lblFrameRate->setMinimumSize(80, 20);
    setNumOnLabel(lblRecvFrameNum, "FNum: ", recvFrameNum);
    setNumOnLabel(lblFrameRate, "FPS: ", recvFrameRate);
    // 从右往左依次添加
    sBar->addPermanentWidget(lblRecvFrameNum);
    sBar->addPermanentWidget(lblFrameRate);

    // 发送速率、接收速率统计-定时器
    timRate = new QTimer;
    timRate->start(1000);
    connect(timRate, &QTimer::timeout, this, [=](){
        dataRateCalculate();
    });
    timRate_tab1 = new QTimer;
    timRate_tab1->start(1000);
    connect(timRate_tab1, &QTimer::timeout, this, [=](){
        dataRateCalculate();
    });
    timRate_tab1 = new QTimer;
    timRate_tab1->start(1000);
    connect(timRate_tab1, &QTimer::timeout, this, [=](){
        dataRateCalculate();
    });

    // 新建一串口对象
    mySerialPort_tab1 = new QSerialPort(this);
    mySerialPort_tab2 = new QSerialPort(this);

    // 串口接收，信号槽关联
    connect(mySerialPort_tab1, SIGNAL(readyRead()), this, SLOT(serialPort1Read_Slot()));
    connect(mySerialPort_tab2, SIGNAL(readyRead()), this, SLOT(serialPort2Read_Slot()));

    timerTest = new QTimer;
    timerTest->setInterval(10);
    //connect(timerTest, &QTimer::timeout, this, SLOT(timerTest_cb()));
    connect(timerTest, &QTimer::timeout, this, [=](){
        timerTest_cb();
    });

    timerAlg = new QTimer;
    timerAlg->setInterval(5);
    connect(timerAlg, &QTimer::timeout, this, [=](){
        timerAlg_cb();
    });
    ui->pushButton_control->setEnabled(true);
    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_fitting->setEnabled(false);
    pause_flag = false;
    control_flag = false;

    /*显示部分*/
    pPlot1 = ui->winPlot;
    QPlot_init(pPlot1);
    QPlot_widget_init();
    ui->txtPointOriginX->setEnabled(false);
    connect(pPlot1, SIGNAL(afterReplot()), this, SLOT(repPlotCoordinate()));
    connect(pPlot1, &QCustomPlot::mouseMove, this, &MainWindow::MyMouseMoveEvent);

    /*摄像头部分*/
    cameras = QCameraInfo::availableCameras();
    for(int i = 0; i < cameras.size(); ++i)
    {
        ui->comboBox_camId->addItem(cameras.at(i).description());
    }
    camera = new QCamera(this);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(ui->widget_image);
    connect(ui->comboBox_camId, SIGNAL(clicked()), this, SLOT(on_comboBox_camId_clicked()));

    /*串口部分*/
    serialPorts = QSerialPortInfo::availablePorts();
    for(int i = 0; i < serialPorts.size(); ++i)
    {
        ui->cmbSerialPort_tab1->addItem(serialPorts.at(i).portName());
        ui->cmbSerialPort_tab2->addItem(serialPorts.at(i).portName());
    }
    connect(ui->cmbSerialPort_tab1, SIGNAL(clicked()), this, SLOT(on_cmbSerialPort_tab1_clicked()));
    connect(ui->cmbSerialPort_tab2, SIGNAL(clicked()), this, SLOT(on_cmbSerialPort_tab2_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 绘图事件
void MainWindow::paintEvent(QPaintEvent *)
{
    // 绘图
    // 实例化画家对象，this指定绘图设备
    QPainter painter(this);

    // 设置画笔颜色
    QPen pen(QColor(0,0,0));
    // 设置画笔线宽（只对点线圆起作用，对文字不起作用）
    pen.setWidth(1);
    // 设置画笔线条风格，默认是SolidLine实线
    // DashLine虚线，DotLine点线，DashDotLine、DashDotDotLine点划线
    pen.setStyle(Qt::DashDotDotLine);
    // 让画家使用这个画笔
    painter.setPen(pen);

    //painter.drawLine(QPoint(ui->txtRec->x() + ui->txtRec->width(), ui->txtRec->y()), QPoint(this->width(), ui->txtRec->y()));
    //painter.drawLine(QPoint(ui->txtSend->x() + ui->txtSend->width(), ui->txtSend->y()), QPoint(this->width(), ui->txtSend->y()));
    painter.drawLine(QPoint(ui->statusbar->x(), ui->statusbar->y()-2), QPoint(this->width(), ui->statusbar->y()-2));

}

// 发送按键槽函数
// 如果勾选16进制发送，按照asc2的16进制发送

// 状态栏标签显示计数值
void MainWindow::setNumOnLabel(QLabel *lbl, QString strS, long num)
{
    // 标签显示
    QString strN;
    strN.sprintf("%ld", num);
    QString str = strS + strN;
    lbl->setText(str);
}

// 发送速率、接收速率统计-定时器
void MainWindow::dataRateCalculate(void)
{
    sendRate = sendNum - tSend; // * ui->cmbData->currentText().toUInt();
    recvRate = recvNum - tRecv; // * ui->cmbData->currentText().toUInt();
    recvFrameRate = recvFrameNum - tFrame;

    setNumOnLabel(lblSendRate, "Byte/s: ", sendRate);
    setNumOnLabel(lblRecvRate, "Byte/s: ", recvRate);
    setNumOnLabel(lblFrameRate, "FPS: ", recvFrameRate);
    tSend = sendNum;
    tRecv = recvNum;
    tFrame = recvFrameNum;
}

void MainWindow::serialPort1Read_Slot()
{
    char tmpData[7] = {0};
    mySerialPort_tab1->read(tmpData, 7);
    algorithm.laser1Read((uint8_t*)tmpData);
}

void MainWindow::serialPort2Read_Slot()
{
    char tmpData[7] = {0};
    mySerialPort_tab2->read(tmpData, 7);
    algorithm.laser2Read((uint8_t*)tmpData);
}

void MainWindow::on_btnSwitch_tab1_clicked()
{
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity   checkBits;

    // 获取串口波特率
    baudRate = (QSerialPort::BaudRate)ui->cmbBaudRate_tab1->currentText().toUInt();
    // 获取串口数据位
    dataBits = (QSerialPort::DataBits)ui->cmbData_tab1->currentText().toUInt();
    // 获取串口停止位
    if(ui->cmbStop_tab1->currentText() == "1")
    {
        stopBits = QSerialPort::OneStop;
    }
    else if(ui->cmbStop_tab1->currentText() == "1.5")
    {
        stopBits = QSerialPort::OneAndHalfStop;
    }
    else if(ui->cmbStop_tab1->currentText() == "2")
    {
        stopBits = QSerialPort::TwoStop;
    }
    else
    {
        stopBits = QSerialPort::OneStop;
    }

    // 获取串口奇偶校验位
    if(ui->cmbCheck_tab1->currentText() == "无")
    {
        checkBits = QSerialPort::NoParity;
    }
    else if(ui->cmbCheck_tab1->currentText() == "奇校验")
    {
        checkBits = QSerialPort::OddParity;
    }
    else if(ui->cmbCheck_tab1->currentText() == "偶校验")
    {
        checkBits = QSerialPort::EvenParity;
    }
    else
    {
        checkBits = QSerialPort::NoParity;
    }

    // 想想用 substr strchr怎么从带有信息的字符串中提前串口号字符串
    // 初始化串口属性，设置 端口号、波特率、数据位、停止位、奇偶校验位数
    mySerialPort_tab1->setBaudRate(baudRate);
    mySerialPort_tab1->setDataBits(dataBits);
    mySerialPort_tab1->setStopBits(stopBits);
    mySerialPort_tab1->setParity(checkBits);
    // 匹配带有串口设备信息的文本
    QString spTxt = ui->cmbSerialPort_tab1->currentText();
    spTxt = spTxt.section(':', 0, 0);//spTxt.mid(0, spTxt.indexOf(":"));
    //mySerialPort_tab1->setPortName(spTxt);
    int portIdx = ui->cmbSerialPort_tab1->currentIndex();
    mySerialPort_tab1->setPort(serialPorts.at(portIdx));

    // 根据初始化好的串口属性，打开串口
    // 如果打开成功，反转打开按钮显示和功能。打开失败，无变化，并且弹出错误对话框。
    if(ui->btnSwitch_tab1->text() == "打开串口")
    {
        if(mySerialPort_tab1->open(QIODevice::ReadWrite) == true)
        {
            //QMessageBox::
            ui->btnSwitch_tab1->setText("关闭串口");
            // 让端口号下拉框不可选，避免误操作（选择功能不可用，控件背景为灰色）
            ui->cmbSerialPort_tab1->setEnabled(false);
            ui->cmbBaudRate_tab1->setEnabled(false);
            ui->cmbStop_tab1->setEnabled(false);
            ui->cmbData_tab1->setEnabled(false);
            ui->cmbCheck_tab1->setEnabled(false);
        }
        else
        {
            QMessageBox::critical(this, "错误提示", "串口打开失败！！！\r\n\r\n该串口可能被占用，请选择正确的串口\r\n或者波特率过高，超出硬件支持范围");
        }
    }
    else
    {
        mySerialPort_tab1->close();
        ui->btnSwitch_tab1->setText("打开串口");
        // 端口号下拉框恢复可选，避免误操作
        ui->cmbSerialPort_tab1->setEnabled(true);
        ui->cmbBaudRate_tab1->setEnabled(true);
        ui->cmbStop_tab1->setEnabled(true);
        ui->cmbData_tab1->setEnabled(true);
        ui->cmbCheck_tab1->setEnabled(true);
    }

}

void MainWindow::on_btnSwitch_tab2_clicked()
{
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity   checkBits;

    // 获取串口波特率
    baudRate = (QSerialPort::BaudRate)ui->cmbBaudRate_tab2->currentText().toUInt();
    // 获取串口数据位
    dataBits = (QSerialPort::DataBits)ui->cmbData_tab2->currentText().toUInt();
    // 获取串口停止位
    if(ui->cmbStop_tab2->currentText() == "1")
    {
        stopBits = QSerialPort::OneStop;
    }
    else if(ui->cmbStop_tab2->currentText() == "1.5")
    {
        stopBits = QSerialPort::OneAndHalfStop;
    }
    else if(ui->cmbStop_tab2->currentText() == "2")
    {
        stopBits = QSerialPort::TwoStop;
    }
    else
    {
        stopBits = QSerialPort::OneStop;
    }

    // 获取串口奇偶校验位
    if(ui->cmbCheck_tab2->currentText() == "无")
    {
        checkBits = QSerialPort::NoParity;
    }
    else if(ui->cmbCheck_tab2->currentText() == "奇校验")
    {
        checkBits = QSerialPort::OddParity;
    }
    else if(ui->cmbCheck_tab2->currentText() == "偶校验")
    {
        checkBits = QSerialPort::EvenParity;
    }
    else
    {
        checkBits = QSerialPort::NoParity;
    }

    // 想想用 substr strchr怎么从带有信息的字符串中提前串口号字符串
    // 初始化串口属性，设置 端口号、波特率、数据位、停止位、奇偶校验位数
    mySerialPort_tab2->setBaudRate(baudRate);
    mySerialPort_tab2->setDataBits(dataBits);
    mySerialPort_tab2->setStopBits(stopBits);
    mySerialPort_tab2->setParity(checkBits);
    // 匹配带有串口设备信息的文本
    QString spTxt = ui->cmbSerialPort_tab2->currentText();
    spTxt = spTxt.section(':', 0, 0);//spTxt.mid(0, spTxt.indexOf(":"));
    //mySerialPort_tab2->setPortName(spTxt);
    int portIdx = ui->cmbSerialPort_tab2->currentIndex();
    mySerialPort_tab2->setPort(serialPorts.at(portIdx));

    // 根据初始化好的串口属性，打开串口
    // 如果打开成功，反转打开按钮显示和功能。打开失败，无变化，并且弹出错误对话框。
    if(ui->btnSwitch_tab2->text() == "打开串口")
    {
        if(mySerialPort_tab2->open(QIODevice::ReadWrite) == true)
        {
            //QMessageBox::
            ui->btnSwitch_tab2->setText("关闭串口");
            // 让端口号下拉框不可选，避免误操作（选择功能不可用，控件背景为灰色）
            ui->cmbSerialPort_tab2->setEnabled(false);
            ui->cmbBaudRate_tab2->setEnabled(false);
            ui->cmbStop_tab2->setEnabled(false);
            ui->cmbData_tab2->setEnabled(false);
            ui->cmbCheck_tab2->setEnabled(false);
        }
        else
        {
            QMessageBox::critical(this, "错误提示", "串口打开失败！！！\r\n\r\n该串口可能被占用，请选择正确的串口\r\n或者波特率过高，超出硬件支持范围");
        }
    }
    else
    {
        mySerialPort_tab2->close();
        ui->btnSwitch_tab2->setText("打开串口");
        // 端口号下拉框恢复可选，避免误操作
        ui->cmbSerialPort_tab2->setEnabled(true);
        ui->cmbBaudRate_tab2->setEnabled(true);
        ui->cmbStop_tab2->setEnabled(true);
        ui->cmbData_tab2->setEnabled(true);
        ui->cmbCheck_tab2->setEnabled(true);
    }
}

void MainWindow::timerTest_cb()
{
    double sinData = sin(testTime);
    double cosData = cos(testTime);
    testBuff[0] = sinData * 10;
    testBuff[1] = cosData * 10;
    testTime += 0.01;
    ShowPlot_WaveForm(pPlot1, testBuff);
}

void MainWindow::timerAlg_cb()
{
    static uint8_t cnt = 0;
    char data_to_send[8] = {0};
    double showBuff[4] = {};

    data_to_send[0] = 0x50;
    data_to_send[1] = 0x03;
    data_to_send[2] = 0x00;
    data_to_send[3] = 0x34;
    data_to_send[4] = 0x00;
    data_to_send[5] = 0x01;
    data_to_send[6] = 0xc8;
    data_to_send[7] = 0x45;

    if(mySerialPort_tab1->isOpen())
    {
        mySerialPort_tab1->write(data_to_send, 8);
    }
    if(mySerialPort_tab2->isOpen())
    {
        mySerialPort_tab2->write(data_to_send, 8);
    }

    //algorithm.laserSimulation();
    algTime += 0.005;
    cnt++;
    if(cnt % 4 == 0)
    {
        algorithm.laserAlgorithm();
        showBuff[0] = algorithm.getDistance1();
        showBuff[1] = algorithm.getCurveReverse() * algorithm.getDistance2();
        showBuff[2] = algorithm.getSpeedDis1();
        showBuff[3] = algorithm.getCurveReverse() * algorithm.getSpeedDis2();

        algorithm.disCh1.push_back(algorithm.getDistance1());
        algorithm.disCh2.push_back(algorithm.getCurveReverse() * algorithm.getDistance2());
        algorithm.time.push_back(algTime);
        ShowPlot_WaveForm(pPlot1, showBuff);
        cnt = 0;
    }
}

void MainWindow::on_pushButton_control_clicked()
{
    if(control_flag == false)
    {
        timerAlg->start();
        resetXYRange();
        ui->pushButton_control->setText("清除");
        ui->pushButton_pause->setEnabled(true);
    }
    else//clear plot, status reset
    {
        clearPlot();
        algTime = 0;
        algorithm.reset();
        timerAlg->stop();
        ui->pushButton_control->setText("启动");
        ui->pushButton_pause->setEnabled(false);
        ui->pushButton_fitting->setEnabled(false);
        pause_flag = false;
        ui->pushButton_pause->setText("暂停");
    }
    control_flag = !control_flag;
}

void MainWindow::on_pushButton_pause_clicked()
{
    if(pause_flag == false)
    {
        timerAlg->stop();
        ui->pushButton_fitting->setEnabled(true);
        ui->pushButton_pause->setText("继续");
    }
    else
    {
        timerAlg->start();
        resetXYRange();
        ui->pushButton_fitting->setEnabled(false);
        ui->pushButton_pause->setText("暂停");
    }
    pause_flag = !pause_flag;
}

/*显示部分*/
// 绘图图表初始化
void MainWindow::QPlot_init(QCustomPlot *customPlot)
{
    // 添加曲线名称
    QStringList lineNames;//设置图例的文本
    lineNames << "x1" << "x2" << "v1" << "v2";
    // 曲线初始颜色
    QColor initColor[4] = {QColor(255, 0, 0), QColor(0, 0, 255),
                           QColor(0, 0, 0), QColor(255, 0, 255)};
    // 图表添加2条曲线，并设置初始颜色，和图例名称
    for(int i = 0; i < 4; i++)
    {
        pCurve[i] = customPlot->addGraph();
        QPen pen = pCurve[i]->pen();
        pen.setColor(QColor(initColor[i]));
        pen.setWidth(3);
        pCurve[i]->setPen(pen);
        pCurve[i]->setName(lineNames.at(i));
    }
    for(int i = 0; i < 2; ++i)
    {
        pCurve[i]->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)3, 5));
    }
    for(int i = 2; i < 4; ++i)
    {
        pCurve[i]->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)3, 1));
    }

    // 设置背景颜色
    customPlot->setBackground(QColor(255,255,255));
    // 设置背景选择框颜色
    ui->btnColourBack->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(QColor(255,255,255).name()));

    // 设置坐标轴名称
    customPlot->xAxis->setLabel("时间t/s");
    customPlot->yAxis->setLabel("位移x/m");
    //设置标题
    QCPTextElement *m_title;
    customPlot->plotLayout()->insertRow(0);
    m_title = new QCPTextElement(customPlot, "位移-时间图");
    customPlot->plotLayout()->addElement(0, 0, m_title);

    // 设置x,y坐标轴显示范围
    pointCountX = ui->txtPointCountX->text().toUInt();
    pointCountY = ui->txtPointCountY->text().toUInt();
    customPlot->xAxis->setRange(0, pointCountX * 0.02);
    customPlot->yAxis->setRange(pointCountY / 2 * -1, pointCountY / 2);

    customPlot->axisRect()->setupFullAxesBox();//四边安装轴并显示
    customPlot->xAxis->ticker()->setTickCount(ui->txtMainScaleNumX->text().toUInt());//11个主刻度
    customPlot->yAxis->ticker()->setTickCount(ui->txtMainScaleNumY->text().toUInt());//11个主刻度
    customPlot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);//可读性优于设置
    customPlot->yAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);//可读性优于设置

    // 显示图表的图例
    customPlot->legend->setVisible(true);

    // 设置波形曲线的复选框字体颜色
    //ui->chkVisibleCurve1->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");//设定前景颜色,就是字体颜色

    // 允许用户用鼠标拖动轴范围，以鼠标为中心滚轮缩放，点击选择图形:
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // 设置鼠标滚轮的缩放倍率，如果不设置默认为0.85，大于1反方向缩放
    //customPlot->axisRect()->setRangeZoomFactor(0.5);
    // 设置鼠标滚轮缩放的轴方向，仅设置垂直轴。垂直轴和水平轴全选使用：Qt::Vertical | Qt::Horizontal
    customPlot->axisRect()->setRangeZoom(Qt::Vertical | Qt::Horizontal);
}

// 绘图图表的设置控件初始化，主要用于关联控件的信号槽
void MainWindow::QPlot_widget_init(void)
{
    // 获取控件指针数组，方便设置时编码书写
    pChkVisibleCurve[0] = ui->chkVisibleCurve1; pBtnColourCurve[0] = ui->btnColourCurve1; pTxtValueCurve[0] = ui->txtValueCurve1; pRdoBoldCurve[0] = ui->rdoBoldCurve1;
    pChkVisibleCurve[1] = ui->chkVisibleCurve2; pBtnColourCurve[1] = ui->btnColourCurve2; pTxtValueCurve[1] = ui->txtValueCurve2; pRdoBoldCurve[1] = ui->rdoBoldCurve2;

    pCmbLineStyle[0] = ui->cmbLineStyle1; pCmbScatterStyle[0] = ui->cmbScatterStyle1;
    pCmbLineStyle[1] = ui->cmbLineStyle2; pCmbScatterStyle[1] = ui->cmbScatterStyle2;

    for(int i = 0; i < 2; ++i)
    {
        curveSetVisible(pPlot1, pCurve[i], pChkVisibleCurve[i]->checkState());
    }

    // 设置颜色选择框的初始背景颜色，与曲线同步颜色
    for(int i=0; i<2; i++)
    {
        pBtnColourCurve[i]->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(QColor(pCurve[i]->pen().color()).name()));
    }

    // 可见性选择框关联
    for(int i = 0; i < 2; i++)
    {
        connect(pChkVisibleCurve[i], &QCheckBox::clicked, [=](){
            curveSetVisible(pPlot1, pCurve[i], pChkVisibleCurve[i]->checkState());
        });
    }

    // 颜色选择框关联
    for(int i = 0; i < 2; i++)
    {
        connect(pBtnColourCurve[i], &QPushButton::clicked, [=](){
            curveSetColor(pPlot1, pCurve[i], pBtnColourCurve[i]);
        });
    }

    // 加粗显示多选框关联。尽量别用，会导致CPU使用率升高
    for(int i = 0; i < 2; i++)
    {
        connect(pRdoBoldCurve[i], &QRadioButton::clicked, [=](){
            curveSetBold(pPlot1, pCurve[i], pRdoBoldCurve[i]->isChecked());
        });
    }

    // 曲线样式选择关联
    for(int i = 0; i < 2; i++)
    {
        connect(pCmbLineStyle[i], &QComboBox::currentTextChanged, [=](){
            curveSetLineStyle(pPlot1, pCurve[i], pCmbLineStyle[i]->currentIndex());
        });
    }

    // 散点样式选择关联
    for(int i = 0; i < 2; i++)
    {
        //pCurve[i]->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)3, 5));
        connect(pCmbScatterStyle[i], &QComboBox::currentTextChanged, [=](){
            curveSetScatterStyle(pPlot1, pCurve[i], pCmbScatterStyle[i]->currentIndex()+1);
        });
    }

    for(int i = 0; i < 2; i++)
    {
        pCmbScatterStyle[i]->setIconSize(QSize(25,17)); // 设置图片显示像素大小，不然会默认大小显示会模糊
    }

}

// 曲线更新绘图，波形数据绘图
void MainWindow::ShowPlot_WaveForm(QCustomPlot *customPlot, double value[])
{
    cnt++;
    // 给曲线添加数据
    if(ui->radioButton_realTimeSpeed->isChecked())
    {
        for(int i = 0; i < 4; i++)
        {
            //QString strNum = QString::number(num,'g',8);// double类型
            //pTxtValueCurve[i]->setText(QString::number(value[i]));// 显示曲线当前值
            pCurve[i]->addData(algTime, value[i]);// 从原值获取数据
        }
    }
    else
    {
        for(int i = 0; i < 2; i++)
        {
            //QString strNum = QString::number(num,'g',8);// double类型
            //pTxtValueCurve[i]->setText(QString::number(value[i]));// 显示曲线当前值
            pCurve[i]->addData(algTime, value[i]);// 从原值获取数据
        }
    }

    // 设置x坐标轴显示范围，使其自适应缩放x轴，x轴最大显示pointCountX个点。与chkTrackX复选框有关
    if(ui->chkTrackX->checkState())
    {
        //customPlot->xAxis->setRange((pCurve[0]->dataCount()>pointCountX)?(pCurve[0]->dataCount()-pointCountX):0, pCurve[0]->dataCount());
        setAutoTrackX(customPlot);
    }
    // 设置y坐标轴显示范围，使其自适应曲线缩放
    if(ui->chkAdjustY->checkState())
    {
        setAutoTrackY(customPlot);
    }

    // 更新绘图，这种方式在高填充下太浪费资源。有另一种方式rpQueuedReplot，可避免重复绘图。
    // 最好的方法还是将数据填充、和更新绘图分隔开。将更新绘图单独用定时器更新。例程数据量较少没用单独定时器更新，实际工程中建议大家加上。
    //customPlot->replot();
    customPlot->replot(QCustomPlot::rpQueuedReplot);

    static QTime time(QTime::currentTime());
    double key = time.elapsed() / 1000.0; // 开始到现在的时间，单位秒
    ////计算帧数
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 1) // 每1秒求一次平均值
    {
        //状态栏显示帧数和数据总数
        ui->statusbar->showMessage(
            QString("%1 FPS, Total Data points: %2")
            .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
            .arg(customPlot->graph(0)->data()->size()+customPlot->graph(1)->data()->size())
            , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
}

void MainWindow::clearPlot()
{
    //pPlot1->clearGraphs(); // 清除图表的所有数据和设置，需要重新设置才能重新绘图
    //pPlot1->clearPlottables(); // 清除图表中所有曲线，需要重新添加曲线才能绘图
    for(int i=0; i<4; i++){
        pPlot1->graph(i)->data().data()->clear(); // 仅仅清除曲线的数据
    }
    cnt = 0;
    pPlot1->replot(QCustomPlot::rpQueuedReplot);

}

void MainWindow::resetXYRange()
{
    pPlot1->xAxis->setRange(0, pointCountX * 0.02);
    pPlot1->yAxis->setRange(pointCountY / 2 * -1, pointCountY / 2);
}

/* 功能：隐藏/显示曲线n
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：曲线的可见性，>0可见，0不可见
 * */
void MainWindow::curveSetVisible(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    if(arg1)
    {
        pCurve->setVisible(true);
    }
    else
    {
        pCurve->setVisible(false);
    }
    pPlot->replot(QCustomPlot::rpQueuedReplot);
}

/* 功能：弹出颜色对话框，设置曲线n的颜色
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * QPushButton *btn：曲线颜色选择框的按键，与曲线的颜色同步
 * */
void MainWindow::curveSetColor(QCustomPlot *pPlot, QCPGraph *pCurve, QPushButton *btn)
{
    // 获取当前颜色
    QColor bgColor(0,0,0);
    //bgColor = btn->palette().color(QPalette::Background);// 由pushButton的背景色获得颜色
    bgColor = pCurve->pen().color();// 由curve曲线获得颜色
    // 以当前颜色打开调色板，父对象，标题，颜色对话框设置项（显示Alpha透明度通道）
    //QColor color = QColorDialog::getColor(bgColor);
    QColor color = QColorDialog::getColor(bgColor, this,
                                     tr("颜色对话框"),
                                     QColorDialog::ShowAlphaChannel);
    // 判断返回的颜色是否合法。若点击x关闭颜色对话框，会返回QColor(Invalid)无效值，直接使用会导致变为黑色。
    if(color.isValid())
    {
        // 设置选择框颜色
        btn->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(color.name()));
        // 设置曲线颜色
        QPen pen = pCurve->pen();
        pen.setBrush(color);
        pCurve->setPen(pen);
        //pCurve->setPen(QPen(color));
    }
    // 更新绘图
    pPlot->replot(QCustomPlot::rpQueuedReplot);
}

/* 功能：加粗显示曲线n
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：曲线的粗细，>0粗，0细
 * */
void MainWindow::curveSetBold(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    // 预先读取曲线的颜色
    QPen pen = pCurve->pen();
    //pen.setBrush(pCurve->pen().color());// 由curve曲线获得颜色

    if(arg1)
    {
        pen.setWidth(3);
        pCurve->setPen(pen);
    }
    else
    {
        pen.setWidth(1);
        pCurve->setPen(pen);
    }
    pPlot->replot(QCustomPlot::rpQueuedReplot);
}

/* 功能：选择曲线样式（线，点，积）
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：曲线样式（线，点，积）
 * */
void MainWindow::curveSetLineStyle(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    // 设置曲线样式
    pCurve->setLineStyle((QCPGraph::LineStyle)arg1);
    pPlot->replot(QCustomPlot::rpQueuedReplot);
}

/* 功能：选择散点样式（空心圆、实心圆、正三角、倒三角）
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：散点样式（空心圆、实心圆、正三角、倒三角）
 * */
void MainWindow::curveSetScatterStyle(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    // 设置散点样式
    if(arg1 <= 10)
    {
        pCurve->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)arg1, 5)); // 散点样式
    }
    else
    { // 后面的散点图形略复杂，太小会看不清
        pCurve->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)arg1, 8)); // 散点样式
    }
    pPlot->replot(QCustomPlot::rpQueuedReplot);
}

// 设置曲线x轴自动跟随
void MainWindow::setAutoTrackX(QCustomPlot *pPlot)
{
    pointCountX = ui->txtPointCountX->text().toUInt();
    if(pCurve[0]->dataCount() < pointCountX)
    {
        pPlot->xAxis->setRange(0, pointCountX * 0.02);
    }
    else
    {
        pPlot->xAxis->setRange((pCurve[0]->dataCount() > pointCountX) ? (pCurve[0]->dataCount() - pointCountX) * 0.02 : 0, pCurve[0]->dataCount() * 0.02);
    }
}

// 设置曲线x轴手动设置范围（依照右下角输入框）
void MainWindow::setManualSettingX(QCustomPlot *pPlot)
{
    pointOriginX = ui->txtPointOriginX->text().toInt();
    pointCountX = ui->txtPointCountX->text().toUInt();
    pPlot->xAxis->setRange(pointOriginX, pointOriginX+pointCountX);
}

// 设置Y轴自适应
void MainWindow::setAutoTrackY(QCustomPlot *pPlot)
{
    pPlot->graph(0)->rescaleValueAxis();// y轴自适应，可放大可缩小
    for(int i = 1; i < 2; i++)
    {
        pPlot->graph(i)->rescaleValueAxis(true);// y轴自适应，只能放大
    }
}

void MainWindow::on_chkShowLegend_stateChanged(int arg1)
{
    if(arg1)
    {
        // 显示图表的图例
        pPlot1->legend->setVisible(true);
    }
    else
    {
        // 不显示图表的图例
        pPlot1->legend->setVisible(false);
    }
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_btnColourBack_clicked()
{
    // 获取当前颜色
    QColor bgColor(0,0,0);
    bgColor = ui->btnColourBack->palette().color(QPalette::Background);// 由pushButton的背景色获得颜色
    // 以当前颜色打开调色板，父对象，标题，颜色对话框设置项（显示Alpha透明度通道）
    //QColor color = QColorDialog::getColor(bgColor);
    QColor color = QColorDialog::getColor(bgColor, this,
                                     tr("颜色对话框"),
                                     QColorDialog::ShowAlphaChannel);

    // 判断返回的颜色是否合法。若点击x关闭颜色对话框，会返回QColor(Invalid)无效值，直接使用会导致变为黑色。
    if(color.isValid())
    {
        // 设置背景颜色
        pPlot1->setBackground(color);
        // 设置背景选择框颜色
        ui->btnColourBack->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(color.name()));
    }
    // 更新绘图
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_btnClearGraphs_clicked()
{
    for(int i = 0; i < 2; i++)
    {
        pPlot1->graph(i)->data().data()->clear(); // 仅仅清除曲线的数据
    }
    cnt = 0;
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_txtPointCountX_returnPressed()
{
    if(ui->chkTrackX->checkState())
    {
        setAutoTrackX(pPlot1);
    }
    else
    {
        setManualSettingX(pPlot1);
    }
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_txtPointCountY_returnPressed()
{
    pointCountY = ui->txtPointCountY->text().toUInt();
    pPlot1->yAxis->setRange(pointCountY / 2 * -1, pointCountY / 2);
    ui->txtPointOriginY->setText(QString::number(pointCountY / 2 * -1));
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_txtPointOriginX_returnPressed()
{
    setManualSettingX(pPlot1);
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_txtPointOriginY_returnPressed()
{
    pointOriginY = ui->txtPointOriginY->text().toInt();
    pointCountY = ui->txtPointCountY->text().toUInt();
    pPlot1->yAxis->setRange(pointOriginY, pointOriginY + pointCountY);
    qDebug() << pointOriginY << pointCountY;
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_chkTrackX_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->txtPointOriginX->setEnabled(false);
        setAutoTrackX(pPlot1);
        pPlot1->replot(QCustomPlot::rpQueuedReplot);
    }
    else
    {
        ui->txtPointOriginX->setEnabled(true);
    }
}

void MainWindow::on_chkAdjustY_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->txtPointOriginY->setEnabled(false);
        ui->txtPointCountY->setEnabled(false);
        setAutoTrackY(pPlot1);
        pPlot1->replot(QCustomPlot::rpQueuedReplot);
    }
    else
    {
        ui->txtPointOriginY->setEnabled(true);
        ui->txtPointCountY->setEnabled(true);
    }
}

void MainWindow::on_txtMainScaleNumX_returnPressed()
{
    pPlot1->xAxis->ticker()->setTickCount(ui->txtMainScaleNumX->text().toUInt());
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::on_txtMainScaleNumY_returnPressed()
{
    pPlot1->yAxis->ticker()->setTickCount(ui->txtMainScaleNumY->text().toUInt());
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::repPlotCoordinate()
{
    static int xOrigin, yOrigin, yCount;
    static int xOriginLast, yOriginLast, yCountLast;

    xOrigin = pPlot1->xAxis->range().lower;
    yOrigin = pPlot1->yAxis->range().lower;
    yCount = pPlot1->yAxis->range().size();
    // 与上次不同时才会更新显示，解决有曲线数据时无法输入y的参数的问题
    if(xOriginLast != xOrigin){
        ui->txtPointOriginX->setText(QString::number(xOrigin));
    }
    if(yOriginLast != yOrigin){
        ui->txtPointOriginY->setText(QString::number(yOrigin));
    }
    if(yCountLast != yCount){
        ui->txtPointCountY->setText(QString::number(yCount));
    }
    // 记录历史值
    xOriginLast = xOrigin;
    yOriginLast = yOrigin;
    yCountLast = yCount;
}

void MainWindow::MyMouseMoveEvent(QMouseEvent *event)
{
    if(pPlot1->graphCount() == 0)
    {
        return;
    }

    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = pPlot1->xAxis->pixelToCoord(x_pos);
    float y_val = pPlot1->yAxis->pixelToCoord(y_pos);

    float x_begin = pPlot1->xAxis->range().lower;
    float x_end = pPlot1->xAxis->range().upper;
    float y_begin = pPlot1->yAxis->range().lower;
    float y_end = pPlot1->yAxis->range().upper;
    float x_tolerate = (x_end - x_begin) / 40;
    float y_tolerate = (y_end - y_begin) / 40;

    if(x_val < x_begin || x_val > x_end)
    {
        return;
    }

    int index = 0;
    int index_left = pPlot1->graph(0)->findBegin(x_val, true);
    int index_right = pPlot1->graph(0)->findEnd(x_val, true);
    float dif_left = fabs(pPlot1->graph(0)->data()->at(index_left)->key - x_val);
    float dif_right = fabs(pPlot1->graph(0)->data()->at(index_right)->key - x_val);
    index = ((dif_left < dif_right) ? index_left : index_right);

    double x_posval = pPlot1->graph(0)->data()->at(index)->key;//通过得到的索引获取key值
    double y_posval = pPlot1->graph(0)->data()->at(index)->value;//通过得到的索引获取value值

    float dx = fabs(x_posval - x_val);
    float dy = fabs(y_posval - y_val);

    int graphIndex = 0;//curve index closest to the cursor
    //通过遍历每条曲线在index处的value值，得到离光标点最近的value及对应曲线索引
    for (int i = 0, n = pPlot1->xAxis->graphs().count(); i < n; i++)
    {
        y_posval = fabs(pPlot1->graph(i)->data()->at(index)->value - y_val);
        if (y_posval < dy)
        {
            dy = y_posval;
            graphIndex = i;
        }
    }

    //判断光标点与最近点的距离是否在设定范围内
    if (dy <= y_tolerate && dx <= x_tolerate)
    {
        y_posval = pPlot1->graph(graphIndex)->data()->at(index)->value;

        QString strToolTip = QString("CH%1 \nx=%2\ny=%3").arg(graphIndex + 1).arg(x_posval).arg(y_posval);

        QToolTip::showText(cursor().pos(), strToolTip, pPlot1);
    }
}

void MainWindow::on_pushButton_openCam_clicked()
{
    static bool flag = false;
    if(flag == false)
    {
        int index = ui->comboBox_camId->currentIndex();
        camera->stop();
        camera = new QCamera(cameras[index]);
        camera->setCaptureMode(QCamera::CaptureStillImage);
        camera->setViewfinder(ui->widget_image);
        camera->start();
        ui->pushButton_openCam->setText("关闭摄像头");
    }
    else
    {
        camera->stop();
        ui->pushButton_openCam->setText("打开摄像头");
    }
    flag = !flag;
}

void MainWindow::on_comboBox_camId_clicked()
{
    ui->comboBox_camId->clear();
    cameras = QCameraInfo::availableCameras();
    for(int i = 0; i < cameras.size(); ++i)
    {
        ui->comboBox_camId->addItem(cameras.at(i).description());
    }
    ui->comboBox_camId->showPopup();
}

void MainWindow::on_cmbSerialPort_tab1_clicked()
{
    ui->cmbSerialPort_tab1->clear();
    serialPorts = QSerialPortInfo::availablePorts();
    for(int i = 0; i < serialPorts.size(); ++i)
    {
        ui->cmbSerialPort_tab1->addItem(serialPorts.at(i).portName());
    }
    ui->cmbSerialPort_tab1->showPopup();
}

void MainWindow::on_cmbSerialPort_tab2_clicked()
{
    ui->cmbSerialPort_tab2->clear();
    serialPorts = QSerialPortInfo::availablePorts();
    for(int i = 0; i < serialPorts.size(); ++i)
    {
        ui->cmbSerialPort_tab2->addItem(serialPorts.at(i).portName());
    }
    ui->cmbSerialPort_tab2->showPopup();
}

void MainWindow::on_radioButton_reverse_clicked(bool checked)
{
    if(checked)
    {
        this->algorithm.setCurveReverse(-1);
    }
    else
    {
        this->algorithm.setCurveReverse(1);
    }
}

void MainWindow::on_pushButton_fitting_clicked()
{
    double startTime = ui->lineEdit_startTime->text().toDouble();
    double fittingTime = ui->lineEdit_fittingTime->text().toDouble();
    double endTime = ui->lineEdit_endTime->text().toDouble();
    int startTimeIdx = 0;
    int fittingTimeIdx = 0;
    int endTimeIdx = 0;
    for(int i = 0; i < algorithm.time.size(); ++i)
    {

        if((algorithm.time[i] - startTime <= 0.02) && (algorithm.time[i] - startTime >= -0.02))
        {
            startTimeIdx = i;
            continue;
        }
        if((algorithm.time[i] - fittingTime <= 0.02) && (algorithm.time[i] - fittingTime >= -0.02))
        {
            fittingTimeIdx = i;
            continue;
        }
        if((algorithm.time[i] - endTime <= 0.02) && (algorithm.time[i] - endTime >= -0.02))
        {
            endTimeIdx = i;
            continue;
        }
    }
    vector<double> disCh1_1(algorithm.disCh1.begin() + startTimeIdx, algorithm.disCh1.begin() + fittingTimeIdx);
    vector<double> disCh1_2(algorithm.disCh1.begin() + fittingTimeIdx, algorithm.disCh1.begin() + endTimeIdx);
    vector<double> disCh2_1(algorithm.disCh2.begin() + startTimeIdx, algorithm.disCh2.begin() + fittingTimeIdx);
    vector<double> disCh2_2(algorithm.disCh2.begin() + fittingTimeIdx, algorithm.disCh2.begin() + endTimeIdx);
    vector<double> time_1(algorithm.time.begin() + startTimeIdx, algorithm.time.begin() + fittingTimeIdx);
    vector<double> time_2(algorithm.time.begin() + fittingTimeIdx, algorithm.time.begin() + endTimeIdx);
    pair<double, double> vel1_1 = algorithm.leastSquareMethod(time_1, disCh1_1);
    pair<double, double> vel1_2 = algorithm.leastSquareMethod(time_2, disCh1_2);
    pair<double, double> vel2_1 = algorithm.leastSquareMethod(time_1, disCh2_1);
    pair<double, double> vel2_2 = algorithm.leastSquareMethod(time_2, disCh2_2);
    algorithm.fittingSpeed1_1 = vel1_1.first;
    algorithm.fittingSpeed1_2 = vel1_2.first;
    algorithm.fittingSpeed2_1 = vel2_1.first;
    algorithm.fittingSpeed2_2 = vel2_2.first;

    showVelFlag = true;

    QVector<double> v1_1 = QVector<double>::fromStdVector(vector<double>(time_1.size(), algorithm.fittingSpeed1_1));
    QVector<double> v1_2 = QVector<double>::fromStdVector(vector<double>(time_2.size(), algorithm.fittingSpeed1_2));
    QVector<double> v2_1 = QVector<double>::fromStdVector(vector<double>(time_1.size(), algorithm.fittingSpeed2_1));
    QVector<double> v2_2 = QVector<double>::fromStdVector(vector<double>(time_2.size(), algorithm.fittingSpeed2_2));
    QVector<double> time_1_ = QVector<double>::fromStdVector(time_1);
    QVector<double> time_2_ = QVector<double>::fromStdVector(time_2);

    pCurve[2]->data().clear();
    pCurve[3]->data().clear();

    pCurve[2]->addData(time_1_, v1_1);
    pCurve[2]->addData(time_2_, v1_2);
    pCurve[3]->addData(time_1_, v2_1);
    pCurve[3]->addData(time_2_, v2_2);
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

