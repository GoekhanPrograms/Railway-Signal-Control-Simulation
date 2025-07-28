#ifndef SIGNALCONTROLLER_H
#define SIGNALCONTROLLER_H

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

class SignalController
{
private:
    enum Signal
    {
        RED,
        YELLOW,
        GREEN
    };

public:
    SignalController();
    bool isSafeToEnter(int trackId);
    bool isNextTrackFree(int trackId);
};

#endif