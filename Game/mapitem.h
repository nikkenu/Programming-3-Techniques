#ifndef MAPITEM_HH
#define MAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>
#include <QDebug>

#include "core/gameobject.h"
#include "buildings/buildingbase.h"

namespace Student {

/**
 * @brief The MapItem class is a custom QGraphicsItem that
 * acts as a single GameObject's graphical element.
 */
class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief Constructor
     * @param obj shared_ptr to the obj.
     * @param size of the created item in pixels.
     * @pre obj must have a valid Coordinate.
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    /**
     * @brief boundingRect
     * @return the bounding rectangle of this item.
     */
    QRectF boundingRect() const override;

    /**
     * @brief paints the item
     * @param painter
     * @param option
     * @param widget
     * @note The GraphicsView containing the scene this belongs to
     * usually calls this function.
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    /**
     * @brief getBoundObject
     * @return the object this item is bound to.
     */
    const std::shared_ptr<Course::GameObject> &getBoundObject();

    /**
     * @brief updateLoc moves the item if the position has changed.
     */
    void updateLoc();

    /**
     * @brief checks if this instance has obj as bound obj.
     * @param obj to compare to.
     * @return True: if obj is pointing to the same object as this item.
     * False otherwise.
     */
    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief getSize
     * @return size of the object in pixels.
     * @post Exception guarantee: No-throw
     */
    int getSize() const;

    /**
     * @brief setSize
     * @param size of the object in pixels.
     * @pre 0 < size <= 500
     * @post Exception guarantee: No-throw
     */
    void setSize(int size);

    /**
     * @brief Adds building's pixmap and name.
     * @param building: pixmap of building.
     * @param buildingName: type of the building.
     */
    void addBuilding(QPixmap building, QString buildingName);

    /**
     * @brief Adds worker's pixmap and name.
     * @param worker: pixmap of worker.
     * @param workerName: type of the worker.
     */
    void addWorker(QPixmap worker, QString workerName);

    /**
     * @brief Removes building pixmap and erases it's name.
     */
    void removeBuilding();

    /**
     * @brief Check if item has a building.
     * @return True if has and false if not.
     */
    bool checkForBuildings();

    /**
     * @brief Check if item has a worker.
     * @return True if has and false if not.
     */
    bool checkForWorkers();

    /**
     * @brief Returns the name of the building in MapItem
     * @return Name of the building
     */
    QString getBuildingName();

    /**
     * @brief Gets names of the workers
     * @return A vector of worker names.
     */
    QVector<QString> getWorkerNames();

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;

    static std::map<std::string, QColor> c_mapcolors;
    static void addNewColor(std::string type);

    QPixmap m_building;
    bool m_itemHasBuilding = false;
    QString m_buildingName;

    QVector<QPixmap> m_worker;
    bool m_itemHasWorker = false;
    QVector<QString> m_workerNames;
};
}
#endif // MAPITEM_HH
