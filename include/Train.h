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
    void move(int distance);
    Track &getCurrentTrack();
    int getId();
    string getDestination();
    void setDestination(string destination);
};

#endif