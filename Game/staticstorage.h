#ifndef STATICSTORAGE_H
#define STATICSTORAGE_H
#include <QPixmap>

namespace Student {
    class StaticStorage
    {
    public:
        enum Items {
            HEADQUARTER,
            OUTPOST,
            FARM,
            MINE,
            OILRIG,
            MINER,
            FARMER,
            WORKER
        };

        static StaticStorage& getInstance();

        StaticStorage(const StaticStorage&) = delete;
        StaticStorage& operator=(const StaticStorage&) = delete;
        StaticStorage(StaticStorage&&) = delete;
        StaticStorage& operator=(StaticStorage&&) = delete;

        QPixmap getItemPixmap(Items item);
        /*
        // Buildings
        QPixmap getHeadquarterImg();
        QPixmap getOutpostImg();
        QPixmap getFarmImg();
        QPixmap getMineImg();
        QPixmap getOilrigImg();

        // Workers
        QPixmap getMinerImg();
        QPixmap getFarmerImg();
        QPixmap getWorkerImg();*/



    private:
        StaticStorage();
        ~StaticStorage() = default;

        // Buildings
        QPixmap m_headquarterPic;
        QPixmap m_outpostPic;
        QPixmap m_farmPic;
        QPixmap m_minePic;
        QPixmap m_oilrigPic;

        // Workers
        QPixmap m_farmerPic;
        QPixmap m_minerPic;
        QPixmap m_workerPic;

    };
}



#endif // STATICSTORAGE_H
