#include "Train.h"

using namespace std;

/**
 * • Train:
 model the train: its ID, position, maybe direction or destination. This is a passive component —
 it reacts to the system but doesn’t make decisions.
 */
Train::Train(int id, Track *currentTrack, string destination)
{
    this->id = id;
    this->currentTrack = currentTrack;
    this->destination = destination;
}

Track &Train::getCurrentTrack()
{
    return *currentTrack;
}

void Train::setCurrentTrack(Track *track)
{
    this->currentTrack = track;
}

int Train::getId()
{
    return id;
}

string Train::getDestination()
{
    return destination;
}

void Train::setDestination(string destination)
{
    this->destination = destination;
}
