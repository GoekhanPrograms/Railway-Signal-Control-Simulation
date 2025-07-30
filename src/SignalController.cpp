#include "SignalController.h"
#include "Track.h"

using namespace std;

SignalController::SignalController() {}

void SignalController::addTrack(int id, Track *track)
{
    tracks[id] = track;
    trackSignals[id] = GREEN;
}

void SignalController::setSignal(int trackId, Signal signal)
{
    trackSignals[trackId] = signal;
}

Signal SignalController::getSignal(int trackId)
{
    auto it = trackSignals.find(trackId);
    if (it != trackSignals.end())
    {
        return it->second;
    }
    return RED; // Default
}

bool SignalController::isSafeToEnter(int trackId)
{
    auto trackIt = tracks.find(trackId);
    if (trackIt == tracks.end())
    {
        return false; // Not found
    }

    Track *track = trackIt->second; // Receive the Track

    if (track->getIsOccupied())
    {
        setSignal(trackId, RED);
        return false; // Safe to enter if next track is free and not occupied
    }

    if (!isNextTrackFree(trackId))
    {
        setSignal(trackId, YELLOW);
        return true;
    }

    setSignal(trackId, GREEN); // Change the signal to RED if not safe to enter
    return true;               // Not safe to enter if not safe to enter
}

bool SignalController::isNextTrackFree(int trackId)
{
    int nextTrackId = trackId + 1; // Next track's ID

    auto nextTrackIt = tracks.find(nextTrackId);
    if (nextTrackIt == tracks.end())
    {
        return true; // Not found
    }

    Track *nextTrack = nextTrackIt->second; // Receive the next Track

    return !nextTrack->getIsOccupied(); // Return true if next track is free
}