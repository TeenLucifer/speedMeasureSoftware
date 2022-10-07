#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QByteArray>
#include <inttypes.h>
#include <vector>
using namespace std;

#pragma execution_character_set("utf-8")

class Algorithm
{
public:
    Algorithm();
    ~Algorithm();

    void imu1Read(uint8_t nowData);
    void imu2Read(uint8_t nowData);
    uint8_t* laser1Send();
    uint8_t* laser2Send();
    void laser1Read(uint8_t* buff);
    void laser2Read(uint8_t* buff);

    void imuAlgorithm();//integral
    void laserAlgorithm();//differential

    double getSpeedAcc1();
    double getSpeedAcc2();
    double getSpeedDis1();
    double getSpeedDis2();
    double getDistance1();
    double getDistance2();

    void imuSimulation();
    void laserSimulation();

    void reset();

    bool checkCRC(const uint8_t* buff, uint8_t length);
    void setCurveReverse(int flag){reverse = flag;}
    int getCurveReverse(){return reverse;}
    pair<double, double> leastSquareMethod(const vector<double> x, const vector<double> y);

    vector<double> disCh1;
    vector<double> disCh2;
    vector<double> time;
    double fittingSpeed1_1;
    double fittingSpeed1_2;
    double fittingSpeed2_1;
    double fittingSpeed2_2;

private:
    int reverse;

    double speedAcc1;
    double speedAcc2;
    double speedDis1;
    double speedDis2;
    double dtAcc;
    double dtDis;
    int coeffAcc;
    int coeffDis;

    bool firstFlag1;
    bool firstFlag2;
    double lastDistance1;
    double lastDistance2;

    double distance1;
    double distance2;
    double accX1;
    double accY1;
    double accZ1;
    double accX2;
    double accY2;
    double accZ2;



    double simTime;
};


#endif // ALGORITHM_H
