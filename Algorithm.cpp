#include "Algorithm.h"

Algorithm::Algorithm()
{
    speedAcc1 = 0;
    speedAcc2 = 0;
    speedDis1 = 0;
    speedDis2 = 0;
    dtAcc = 0.005;
    dtDis = 0.02;
    coeffAcc = 1;
    coeffDis = 1;

    firstFlag1 = true;
    firstFlag2 = true;
    lastDistance1 = 0;
    lastDistance2 = 0;

    simTime = 0;

    reverse = -1;
}

Algorithm::~Algorithm()
{

}

void Algorithm::imu1Read(uint8_t nowData)
{
    static uint8_t num = 0;
    static uint8_t previousData = 0;
    static uint8_t IMU_DATA[11];
    static uint8_t flag = 0;

    if(flag == 0 && previousData == 0x55 && nowData == 0x51)
    {
        flag = 1;
        IMU_DATA[0] = 0x55;
        IMU_DATA[1] = 0x51;
        num = 2;
    }
    else if(flag == 1)
    {
        IMU_DATA[num++] = nowData;
        if(num == 11)
        {
            uint8_t checkSum = 0;
            for(uint8_t i = 0; i < 10; ++i)
            {
                checkSum += IMU_DATA[i];
            }
            if(checkSum == IMU_DATA[10])
            {
                accX1 = ((IMU_DATA[3] << 8) | IMU_DATA[2]) / 32768 * 16 * 9.8;
                accY1 = ((IMU_DATA[5] << 8) | IMU_DATA[4]) / 32768 * 16 * 9.8;
                accZ1 = ((IMU_DATA[7] << 8) | IMU_DATA[6]) / 32768 * 16 * 9.8;
            }
            flag = 0;
        }
    }
    previousData = nowData;
}

void Algorithm::imu2Read(uint8_t nowData)
{
    static uint8_t num = 0;
    static uint8_t previousData = 0;
    static uint8_t IMU_DATA[11];
    static uint8_t flag = 0;

    if(flag == 0 && previousData == 0x55 && nowData == 0x51)
    {
        flag = 1;
        IMU_DATA[0] = 0x55;
        IMU_DATA[1] = 0x51;
        num = 2;
    }
    else if(flag == 1)
    {
        IMU_DATA[num++] = nowData;
        if(num == 11)
        {
            uint8_t checkSum = 0;
            for(uint8_t i = 0; i < 10; ++i)
            {
                checkSum += IMU_DATA[i];
            }
            if(checkSum == IMU_DATA[10])
            {
                accX2 = ((IMU_DATA[3] << 8) | IMU_DATA[2]) / 32768 * 16 * 9.8;
                accY2 = ((IMU_DATA[5] << 8) | IMU_DATA[4]) / 32768 * 16 * 9.8;
                accZ2 = ((IMU_DATA[7] << 8) | IMU_DATA[6]) / 32768 * 16 * 9.8;
            }
            flag = 0;
        }
    }
    previousData = nowData;
}

uint8_t* Algorithm::laser1Send()
{
    uint8_t cnt = 0;
    uint8_t data_to_send[8] = {0};

    data_to_send[cnt++] = 0x50;
    data_to_send[cnt++] = 0x03;
    data_to_send[cnt++] = 0x00;
    data_to_send[cnt++] = 0x34;
    data_to_send[cnt++] = 0x00;
    data_to_send[cnt++] = 0x01;
    data_to_send[cnt++] = 0xc8;
    data_to_send[cnt++] = 0x45;

    return data_to_send;
}

uint8_t* Algorithm::laser2Send()
{
    uint8_t cnt = 0;
    uint8_t data_to_send[8] = {0};

    data_to_send[cnt++] = 0x50;
    data_to_send[cnt++] = 0x03;
    data_to_send[cnt++] = 0x00;
    data_to_send[cnt++] = 0x34;
    data_to_send[cnt++] = 0x00;
    data_to_send[cnt++] = 0x01;
    data_to_send[cnt++] = 0xc8;
    data_to_send[cnt++] = 0x45;

    return data_to_send;
}

void Algorithm::laser1Read(uint8_t* buff)
{
    static uint8_t num = 0;
    static uint8_t previousData = 0;
    static uint8_t LASER_DATA[7];
    static uint8_t flag = 0;
    static uint16_t laserDistance1 = 0;
    static uint8_t _cnt = 0;

    for(uint8_t i = 0; i < 7; ++i)
    {
        uint8_t nowData = buff[i];
        if(flag == 0 && previousData == 0x50 && nowData == 0x03)
        {
            flag = 1;
            LASER_DATA[0] = 0x50;
            LASER_DATA[1] = 0x03;
            num = 2;
        }
        else if(flag == 1)
        {
            LASER_DATA[num++] = nowData;
            if(num == 7)
            {
                if(checkCRC(LASER_DATA, 7))
                {
                    _cnt++;
                    laserDistance1 += (LASER_DATA[3] << 8) | LASER_DATA[4];
                    if(_cnt % 4 == 0)
                    {
                        distance1 = laserDistance1 / 1000.0 / 4.0;
                        _cnt = 0;
                        laserDistance1 = 0;
                    }
                }
                flag = 0;
            }
        }
        previousData = nowData;
    }
}

void Algorithm::laser2Read(uint8_t* buff)
{
    static uint8_t num = 0;
    static uint8_t previousData = 0;
    static uint8_t LASER_DATA[7];
    static uint8_t flag = 0;
    static uint16_t laserDistance2 = 0;
    static uint8_t _cnt = 0;

    for(uint8_t i = 0; i < 7; ++i)
    {
        uint8_t nowData = buff[i];
        if(flag == 0 && previousData == 0x50 && nowData == 0x03)
        {
            flag = 1;
            LASER_DATA[0] = 0x50;
            LASER_DATA[1] = 0x03;
            num = 2;
        }
        else if(flag == 1)
        {
            LASER_DATA[num++] = nowData;
            if(num == 7)
            {
                if(checkCRC(LASER_DATA, 7))
                {
                    _cnt++;
                    laserDistance2 += (LASER_DATA[3] << 8) | LASER_DATA[4];
                    if(_cnt % 4 == 0)
                    {
                        distance2 = laserDistance2 / 1000.0 / 4.0;
                        _cnt = 0;
                        laserDistance2 = 0;
                    }
                }
                flag = 0;
            }
        }
        previousData = nowData;
    }

}

void Algorithm::imuAlgorithm()//intregral
{
    speedAcc1 += coeffAcc * accX1 * dtAcc;
    speedAcc2 += coeffAcc * accX2 * dtAcc;
}

void Algorithm::laserAlgorithm()//differential
{
    if(firstFlag1 == true)
    {
        lastDistance1 = distance1;
        firstFlag1 = false;
    }
    else
    {
        speedDis1 = coeffDis * (distance1 - lastDistance1) / dtDis;
        lastDistance1 = distance1;
    }

    if(firstFlag2 == true)
    {
        lastDistance2 = distance1;
        firstFlag2 = false;
    }
    else
    {
        speedDis2 = coeffDis * (distance2 - lastDistance2) / dtDis;
        lastDistance2 = distance2;
    }
}

double Algorithm::getSpeedAcc1()
{
    return speedAcc1;
}

double Algorithm::getSpeedAcc2()
{
    return speedAcc2;
}

double Algorithm::getSpeedDis1()
{
    return speedDis1;
}

double Algorithm::getSpeedDis2()
{
    return speedDis2;
}

double Algorithm::getDistance1()
{
    return distance1;
}

double Algorithm::getDistance2()
{
    return distance2;
}

void Algorithm::imuSimulation()
{
    if(simTime < 5)
    {
        accX1 = 2;
        accX2 = -2;
    }
    else if(5 <= simTime && simTime < 15)
    {
        accX1 = 0;
        accX2 = 0;
    }
    else if(15 <= simTime && simTime < 20)
    {
        accX1 = -2;
        accX2 = 2;
    }

    simTime += 0.005;
}

void Algorithm::laserSimulation()
{
    if(simTime < 1)
    {
        distance1 = 5 * simTime;
        distance2 = 5 * simTime;
    }
    else if(1 <= simTime && simTime < 2)
    {
        distance1 = -5 * simTime + 2 * 5;
        distance2 = -5 * simTime + 2 * 5;
    }

    simTime += 0.005;
}

void Algorithm::reset()
{
    speedAcc1 = 0;
    speedAcc2 = 0;
    speedDis1 = 0;
    speedDis2 = 0;
    dtAcc = 0.005;
    dtDis = 0.02;
    coeffAcc = 1;
    coeffDis = 1;

    firstFlag1 = true;
    firstFlag2 = true;
    distance1 = 0;
    distance2 = 0;
    lastDistance1 = 0;
    lastDistance2 = 0;

    simTime = 0;

    vector<double>().swap(disCh1);
    vector<double>().swap(disCh2);
    vector<double>().swap(time);
}

bool Algorithm::checkCRC(const uint8_t* buff, uint8_t length)
{
    uint16_t CRC = 0xFFFF;
    uint16_t tmp;
    uint8_t CRC_L;
    uint8_t CRC_H;
    //uint8_t buff[7] = {0x50, 0x03, 0x02, 0x00, 0x35, 0x85, 0x9F};
    //uint8_t length = 7;

    for(uint8_t i = 0; i < length - 2; ++i)
    {
        CRC = buff[i] ^ CRC;
        for(uint8_t j = 0; j < 8; ++j)
        {
            tmp = CRC & 0x0001;
            CRC = CRC >> 1;
            if(tmp)
            {
                CRC = CRC ^ 0xA001;
            }
        }
    }
    CRC_L = CRC & 0x00FF;
    CRC_H = CRC >> 8;

    if(CRC_H == buff[length - 1] && CRC_L == buff[length - 2])
    {
        return true;
    }
    return false;
}

pair<double, double> Algorithm::leastSquareMethod(const vector<double> x, const vector<double> y)
{
    double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    int size = x.size();
    for(int i = 0; i < size; ++i)
    {
        t1 += x[i] * x[i];
        t2 += x[i];
        t3 += x[i] * y[i];
        t4 += y[i];
    }
    double k = (t3 * x.size() - t2 * t4) / (t1 * x.size() - t2 * t2);
    double b = (t1 * t4 - t2 * t3) / (t1 * x.size() - t2 * t2);

    return pair<double, double>{k, b};
}
