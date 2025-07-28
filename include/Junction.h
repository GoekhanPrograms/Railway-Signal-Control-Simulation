#ifndef JUNCTION_H
#define JUNCTION_H
#include <vector>
#include "SignalController.h"

/**
 * The Junction class represents a point in the railway network. It has a unique ID and can connect to other junctions.
 * It's essentially a resource that the RailwaySystem monitors and interacts with.
 * It basically knows the shortest route at a junction based on the destination.
 */
class Junction
{
private:
    int id;
    vector<int> connectedJunctions; // based on trackIds
    int shortestRouteDistance;
    SignalController *signal;

public:
    Junction(int id);
};

#endif