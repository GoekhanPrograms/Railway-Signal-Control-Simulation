#ifndef TRACK_H
#define TRACK_H
#include "junction.h"
#include "SignalController.h"
#include <string>

using namespace std;

/**
 * Think of a Track as a physical segment of the railway.
It should:
    • Know whether it is occupied or free.
    • Know its start and end points (possibly Junction or Station references).
    • Possibly have a signal attached to it or a reference to its current signal state.
It's essentially the resource that trains move across and that the SignalController and RailwaySystem monitor and
manage.
 */

class Track
{
private:
    bool isOccupied = false;
    int trackId;

public:
    Track(int id);
    bool getIsOccupied();
    void setOccupied(bool isOccupied);
    int getTrackId();
};

#endif