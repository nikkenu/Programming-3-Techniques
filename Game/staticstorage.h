#ifndef STATICSTORAGE_H
#define STATICSTORAGE_H
#include <QPixmap>
#include <QVector>

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
        QString getItemName(Items item);
        Items getItemNameAsEnum(QString itemName);
        QPixmap getEpiclorePixmap();
        QVector<Items> getBuildings();
        QVector<Items> getWorkers();

    private:
        StaticStorage();
        ~StaticStorage() = default;

        QVector<Items> m_buildings;
        QVector<Items> m_workers;

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

        //Lore
        QPixmap m_epiclorePic;

    };
}



#endif // STATICSTORAGE_H
