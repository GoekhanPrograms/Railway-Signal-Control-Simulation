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
    Train(int id, int position, string destination);
    void move(int distance);
    int getPosition();
    int getId();
    string getDestination();
    void setDestination(string destination);
    void setPosition(int position);
    ~Train();
};

#endif