#ifndef STATICSTORAGE_H
#define STATICSTORAGE_H
#include <QPixmap>

namespace Student {
    class StaticStorage
    {
    public:
        StaticStorage();
        ~StaticStorage();

        // Buildings
        QPixmap getHeadquaterImg();
        QPixmap getOutpostImg();
        QPixmap getFarmImg();
        QPixmap getMineImg();
        QPixmap getOilrigImg();

        // Workers
        QPixmap getMinerImg();
        QPixmap getFarmerImg();
        QPixmap getWorkerImg();

    private:

        // Buildings
        QPixmap m_headquater;
        QPixmap m_outpost;
        QPixmap m_farm;
        QPixmap m_mine;
        QPixmap m_oilrig;

        // Workers
        QPixmap m_farmer;
        QPixmap m_miner;
        QPixmap m_worker;
    };
}



#endif // STATICSTORAGE_H
