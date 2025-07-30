#include "Track.h"

using namespace std;

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

bool Track::getHasJunction() const
{
    return hasJunction;
}

void Track::setHasJunction(bool hasJunc, Junction *junc)
{
    this->hasJunction = hasJunc;
    this->junction = junc;
}

Junction *Track::getJunction() const
{
    return junction;
}
