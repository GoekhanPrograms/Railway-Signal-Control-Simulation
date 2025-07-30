#ifndef RAILWAYSYSTEM_H
#define RAILWAYSYSTEM_H
#include "Junction.h"
#include "SignalController.h"
#include "Train.h"
#include <map>
#include <vector>

/**
 * The RailWaySystem class represents a system of interconnected junctions and signals. It makes the decisions
 */
class RailWaySystem
{
private:
    int id;
    Junction *junction;
    SignalController *signal;
    map<int, Train *> trains;
    vector<Track *> tracks;

public:
    RailWaySystem(int id, Junction *junction, SignalController *signal);
    bool approveTrainToMove(int trainId);
    void addTrain(int trainId, Train *train);
    void addTrack(Track *track);
    Track *getTrackById(int trackId);
    Train *getTrain(int trainId);
    void moveTrainToNextTrack(int trainId);
};

#endif