#ifndef SIGNALCONTROLLER_H
#define SIGNALCONTROLLER_H
#include <map>
#include <vector>

class Track;

/**
 *  SignalController
    • This is like the traffic light manager.
    • It controls access to tracks — i.e., it sets signals to green/red.
    • It checks:
        ○ Is a track safe to enter?
        ○ Is the next track free?
    • Based on Train intentions + track status, it sets signals accordingly.
You can imagine it has access to all tracks and trains.
 */

enum Signal
{
    RED,
    YELLOW,
    GREEN
};

class SignalController
{
private:
    std::map<int, Signal> trackSignals; // Maps track ID to signal state
    std::map<int, Track *> tracks;      // Maps track ID to Track pointer

public:
    SignalController();
    bool isSafeToEnter(int trackId);
    bool isNextTrackFree(int trackId);
    void setSignal(int trackId, Signal signal);
    Signal getSignal(int trackId);
    void addTrack(int trackId, Track *track);
};

#endif