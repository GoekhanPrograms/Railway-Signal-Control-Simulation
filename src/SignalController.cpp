#include <SignalController.h>

using namespace std;

SignalController::SignalController() {}

void SignalController::addTrack(int id, Track *track)
{
    tracks[id] = track;
    trackSignals[id] = RED;
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
    if (getSignal(trackId) == GREEN && isNextTrackFree(trackId) && !track->getIsOccupied())
    {
        return true; // Safe to enter if its Green and next track is free and not occupied
    }

    if (track->getIsOccupied() || !isNextTrackFree(trackId))
    {
        setSignal(trackId, RED); // Change the signal to RED if not safe to enter
    }

    return false; // Not safe to enter if not safe to enter
}

bool SignalController::isNextTrackFree(int trackId)
{
    auto trackIt = tracks.find(trackId);
    if (trackIt == tracks.end())
    {
        return false; // Not found
    }

    Track *track = trackIt->second; // Receive the Track

    int nextTrackId = trackId + 1; // Next track's ID

    auto nextTrackIt = tracks.find(nextTrackId);
    if (nextTrackIt == tracks.end())
    {
        return true; // Not found
    }

    Track *nextTrack = nextTrackIt->second; // Receive the next Track

    return !nextTrack->getIsOccupied(); // Return true if next track is free
}