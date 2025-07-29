#ifndef RAILWAYSYSTEM_H
#define RAILWAYSYSTEM_H
#include "Junction.h"
#include "SignalController.h"

/**
 * The RailWaySystem class represents a system of interconnected junctions and signals. It makes the decisions
 */
class RailWaySystem
{
private:
    int id;
    Junction *junction;
    SignalController *signal;

public:
    RailWaySystem(int id, Junction *junction, SignalController *signal);
    bool approveTrainToMove(int trainId);
};

#endif