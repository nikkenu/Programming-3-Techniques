#ifndef STATICSTORAGE_H
#define STATICSTORAGE_H
#include <QPixmap>
#include <QVector>

namespace Student {

/**
 * @brief The StaticStorage class is a sigleton class that holds
 * pixmaps of every bulding, every worker and lore. This class can be
 * all over the code.
 */
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

    /**
     * @brief Gives StaticStorage as an instance.
     * @return Instance of StaticStorage.
     */
    static StaticStorage& getInstance();

    StaticStorage(const StaticStorage&) = delete;
    StaticStorage& operator=(const StaticStorage&) = delete;
    StaticStorage(StaticStorage&&) = delete;
    StaticStorage& operator=(StaticStorage&&) = delete;

    /**
     * @brief Get pixmap of wanted item.
     * @param item wanted.
     * @return Pixmap of wanted item.
     * @pre Parameter items must be in Items-enum.
     */
    QPixmap getItemPixmap(Items item);

    /**
     * @brief Get name of wanted item.
     * @param item wanted.
     * @return Name of wanted item.
     * @pre Parameter items must be in Items-enum.
     */
    QString getItemName(Items item);

    /**
     * @brief Get enum of wanted item.
     * @param itemName: name of item wanted.
     * @return Enum of wanted item.
     * @pre Parameter itemName must macth something.
     */
    Items getItemNameAsEnum(QString itemName);

    /**
     * @brief Gets our epic lore.
     * @return Pixmap of epic lore.
     */
    QPixmap getEpiclorePixmap();

    /**
     * @brief Get all buidings as Items.
     * @return A vector of Items.
     */
    QVector<Items> getBuildings();

    /**
     * @brief Get all workers as Items.
     * @return A vector of Items.
     */
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
