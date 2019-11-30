#include "staticstorage.h"

namespace Student {

StaticStorage& StaticStorage::getInstance()
{
    static StaticStorage instance;
    return instance;
}

QPixmap StaticStorage::getItemPixmap(Items item)
{
    if(item == Items::FARM)
    {
        return m_farmPic;
    }
    else if(item == Items::MINE)
    {
        return m_minePic;
    }
    else if(item == Items::MINER)
    {
        return m_minerPic;
    }
    else if(item == Items::FARMER)
    {
        return m_farmerPic;
    }
    else if(item == Items::OILRIG)
    {
        return m_oilrigPic;
    }
    else if(item == Items::WORKER)
    {
        return m_workerPic;
    }
    else if(item == Items::OUTPOST)
    {
        return m_outpostPic;
    }
    else
    {
        return m_headquarterPic;
    }
}

QString StaticStorage::getItemName(StaticStorage::Items item)
{
    switch(item)
    {
        case Items::FARM:
        return "Farm";

        case Items::MINE:
        return "Mine";

        case Items::MINER:
        return "Miner";

        case Items::FARMER:
        return "Farmer";

        case Items::OILRIG:
        return "Oilrig";

        case Items::WORKER:
        return "Worker";

        case Items::OUTPOST:
        return "Outpost";

        case Items::HEADQUARTER:
        return "Headquarter";
    }
}

StaticStorage::Items StaticStorage::getItemNameAsEnum(QString itemName)
{
    if(itemName == "Headquarter")
    {
        return Items::HEADQUARTER;
    }
    else if(itemName == "Outpost")
    {
        return Items::OUTPOST;
    }
    else if(itemName == "Farm")
    {
        return Items::FARM;
    }
    else if(itemName == "Oilrig")
    {
        return Items::OILRIG;
    }
    else if(itemName == "Miner")
    {
        return Items::MINER;
    }
    else if(itemName == "Farmer")
    {
        return Items::FARMER;
    }
    else if(itemName == "Worker")
    {
        return Items::WORKER;
    }
    else if(itemName == "Mine")
    {
        return Items::MINE;
    }
}

QPixmap StaticStorage::getEpiclorePixmap()
{
    return m_epiclorePic;
}

QVector<StaticStorage::Items> StaticStorage::getBuildings()
{
    return m_buildings;
}

QVector<StaticStorage::Items> StaticStorage::getWorkers()
{
    return m_workers;
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

    m_epiclorePic.load(":/images/images/epiclore.png");

    m_buildings.push_back(Items::FARM);
    m_buildings.push_back(Items::OUTPOST);
    m_buildings.push_back(Items::OILRIG);
    m_buildings.push_back(Items::HEADQUARTER);
    m_buildings.push_back(Items::MINE);

    m_workers.push_back(Items::MINER);
    m_workers.push_back(Items::FARMER);
    m_workers.push_back(Items::WORKER);
}

}


