#ifndef JUNCTION_H
#define JUNCTION_H
#include <vector>
#include "SignalController.h"

/**
 * The Junction class represents a point in the railway network. It has a unique ID and can connect to other junctions.
 * It's essentially a resource that the RailwaySystem monitors and interacts with.
 * It basically knows the next route at a junction based on the destination.
 */
class Junction
{
private:
    vector<Track *> routes; // based on trackIds
    int activeOption;

public:
    Track *getActiveTrackId(); // tells system where it points
    void switchTo(int idx);
};

#endif