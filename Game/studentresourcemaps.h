#ifndef STUDENTRESOURCEMAPS_H
#define STUDENTRESOURCEMAPS_H

#include "core/basicresources.h"

namespace Student {


namespace ConstResourceMaps {

const Course::ResourceMapDouble BW_FARMER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.50},
    {Course::WOOD, 1.50},
    {Course::STONE, 0.25},
    {Course::ORE, 0.25}
};

const Course::ResourceMapDouble BW_MINER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.00},
    {Course::WOOD, 0.75},
    {Course::STONE, 1.50},
    {Course::ORE, 1.50}
};

const Course::ResourceMap BW_RECRUITMENT_COST = {
    {Course::MONEY, 10},
    {Course::FOOD, 25}
};

const Course::ResourceMap ROCK_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 5},
    {Course::ORE, 3},
    {Course::OIL, 0},
};

const Course::ResourceMap WATER_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 1},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
    {Course::OIL, 5},
};

const Course::ResourceMap SAND_BP = {
    {Course::MONEY, 1},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 3},
    {Course::ORE, 5},
    {Course::OIL, 0},
};

}

}

#endif // STUDENTRESOURCEMAPS_H
