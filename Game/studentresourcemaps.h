#ifndef STUDENTRESOURCEMAPS_H
#define STUDENTRESOURCEMAPS_H

#include "core/basicresources.h"

namespace Student {


/**
 *@brief This header contains building costs and production of
 * student-made buildigns and efficiensies, recruiment costs of
 * student-made workers and resource genarating abilities for
 * student-made tiles.
 */
namespace ConstResourceMaps {

// Building - Mine
const Course::ResourceMap MINE_BUILD_COST = {
    {Course::BasicResource::MONEY, 50},
    {Course::BasicResource::FOOD, 100},
    {Course::BasicResource::WOOD, 25}
};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::BasicResource::MONEY, 1},
    {Course::BasicResource::FOOD, 5},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 10},
    {Course::BasicResource::ORE, 10}
};

// Building - Oil rig
const Course::ResourceMap OILRIG_BUILD_COST = {
    {Course::BasicResource::MONEY, 50},
    {Course::BasicResource::FOOD, 10},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 75},
    {Course::BasicResource::ORE, 75}
};
const Course::ResourceMap OILRIG_PRODUCTION = {
    {Course::BasicResource::MONEY, 10},
    {Course::BasicResource::FOOD, 5}
};

// Worker - Farmer
const Course::ResourceMapDouble FARMER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.50},
    {Course::WOOD, 1.50},
    {Course::STONE, 0.25},
    {Course::ORE, 0.25}
};

// Worker - Miner
const Course::ResourceMapDouble MINER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.00},
    {Course::WOOD, 0.75},
    {Course::STONE, 1.50},
    {Course::ORE, 1.50}
};

// Recruitment cost for Farmer and Miner
const Course::ResourceMap RECRUITMENT_COST = {
    {Course::MONEY, 10},
    {Course::FOOD, 25}
};

// Tile - Rock
const Course::ResourceMap ROCK_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 5},
    {Course::ORE, 3},
};

// Tile - Water
const Course::ResourceMap WATER_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 1},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
};

// Tile - Sand
const Course::ResourceMap SAND_BP = {
    {Course::MONEY, 1},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 3},
    {Course::ORE, 5},
};

}

}

#endif // STUDENTRESOURCEMAPS_H
