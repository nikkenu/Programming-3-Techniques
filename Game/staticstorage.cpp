#include "staticstorage.h"

namespace Student {

StaticStorage& StaticStorage::getInstance()
{
    static StaticStorage instance;
    return instance;
}

QPixmap StaticStorage::getItemPixmap(Items item)
{
    switch(item)
    {
        case Items::FARM:
        return m_farmPic;

        case Items::MINE:
        return m_minePic;

        case Items::MINER:
        return m_minerPic;

        case Items::FARMER:
        return m_farmerPic;

        case Items::OILRIG:
        return m_oilrigPic;

        case Items::WORKER:
        return m_workerPic;

        case Items::OUTPOST:
        return m_outpostPic;

        case Items::HEADQUARTER:
        return m_headquarterPic;

    }
}

StaticStorage::StaticStorage()
{
    m_headquarterPic.load(":/images/images/headquarter.png");
    m_farmPic.load(":/images/images/scarecrow.png");
    m_minePic.load(":/images/images/data.png");
    m_outpostPic.load(":/images/images/lighthouse.png");
    m_oilrigPic.load(":/images/images/oilrig.png");

    m_minerPic.load(":/images/images/miner.png");
    m_farmerPic.load(":/images/images/farmer.png");
    m_workerPic.load(":/images/images/worker.png");
}
/*
QPixmap StaticStorage::getHeadquarterImg()
{
    return m_headquarter;
}

QPixmap StaticStorage::getOutpostImg()
{
    return m_outpost;
}

QPixmap StaticStorage::getFarmImg()
{
    return m_farm;
}

QPixmap StaticStorage::getMineImg()
{
    return m_mine;
}

QPixmap StaticStorage::getOilrigImg()
{
    return m_oilrig;
}

QPixmap StaticStorage::getMinerImg()
{
    return m_miner;
}

QPixmap StaticStorage::getFarmerImg()
{
    return m_farmer;
}

QPixmap StaticStorage::getWorkerImg()
{
    return m_worker;
}*/

}


