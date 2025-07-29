#include "Track.h"

using namespace std;

/**
 * Think of a Track as a physical segment of the railway.
It should:
    • Know whether it is occupied or free.
    • Know its start and end points (possibly Junction or Station references).
    • Possibly have a signal attached to it or a reference to its current signal state.
    • Maybe a method like canTrainEnter() or reserveForTrain(...).
It's essentially the resource that trains move across and that the SignalController and RailwaySystem monitor and
manage.
 */

Track::Track(int trackId)
{
    this->trackId = trackId;
    this->isOccupied = false;
}

bool Track::getIsOccupied()
{
    return isOccupied;
}

void Track::setOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}

int Track::getTrackId()
{
    return trackId;
}

void Track::setTrackId(int trackId)
{
    this->trackId = trackId;
}
