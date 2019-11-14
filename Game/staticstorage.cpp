#include "staticstorage.h"

namespace Student {

    StaticStorage::StaticStorage()
    {
        m_headquater.load(":/images/images/headquarter.png");
        m_farm.load(":/images/images/scarecrow.png");
        m_mine.load(":/images/images/data.png");
        m_outpost.load(":/images/images/lighthouse.png");

        m_miner.load(":/images/images/miner.png");
        m_farmer.load(":/images/images/farmer.png");
        m_worker.load(":/images/images/worker.png");
    }

    StaticStorage::~StaticStorage()
    {

    }

    QPixmap StaticStorage::getHeadquaterImg()
    {
        return m_headquater;
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
    }
}


