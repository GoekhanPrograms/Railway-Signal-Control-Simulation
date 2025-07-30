#ifndef JUNCTION_H
#define JUNCTION_H
#include <vector>
#include <string>
#include "SignalController.h"

/**
 * The Junction class represents a point in the railway network. It has a unique ID and can connect to other junctions.
 * It's essentially a resource that the RailwaySystem monitors and interacts with.
 * It basically knows the next route at a junction based on the destination.
 */
class Junction
{
private:
    int junctionId;

public:
    Junction(int junctionId);
    int getNextTrackForDestination(const std::string &destination, int currentTrackId);
};

#endif