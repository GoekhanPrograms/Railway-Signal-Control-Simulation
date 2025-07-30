#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include "Track.h"

class Train
{
private:
    int id;
    Track *currentTrack;
    string destination;

public:
    Train(int id, Track *currentTrack, string destination);
    Track &getCurrentTrack();
    void setCurrentTrack(Track *track);
    int getId();
    string getDestination();
    void setDestination(string destination);
};

#endif