#include <RailWaySystem.h>

using namespace std;

RailWaySystem::RailWaySystem(int id, Junction *junction, SignalController *signal)
{
    this->id = id;
    this->junction = junction;
    this->signal = signal;
}

 bool RailWaySystem::approveTrainToMove(int trainId){
    // -> from signalcontroller: isSafeToEnter(trackId)==true &&
    // -> from junction: 

    return false;
 }