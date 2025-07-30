#ifndef SIGNALCONTROLLER_H
#define SIGNALCONTROLLER_H
#include <map>
#include <vector>

class Track;

/**
 * Railway traffic signal management system
 *
 * The SignalController manages railway signals (RED/YELLOW/GREEN) to ensure
 * safe train movement. It monitors track occupancy, checks if tracks are
 * safe to enter, and prevents collisions by controlling access to railway
 * segments. Acts as the safety system for the entire railway network.
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
    /**
     * Default constructor for signal controller
     */
    SignalController();

    /**
     * Checks if a track is safe for a train to enter
     * @param trackId ID of the track to check
     * @return true if safe to enter, false otherwise
     */
    bool isSafeToEnter(int trackId);

    /**
     * Checks if the next sequential track is free
     * @param trackId Current track ID
     * @return true if next track is unoccupied, false otherwise
     */
    bool isNextTrackFree(int trackId);

    /**
     * Sets the signal state for a specific track
     * @param trackId Track to update
     * @param signal New signal state (RED/YELLOW/GREEN)
     */
    void setSignal(int trackId, Signal signal);

    /**
     * Gets the current signal state for a track
     * @param trackId Track to query
     * @return Current signal state, defaults to RED if not found
     */
    Signal getSignal(int trackId);

    /**
     * Adds a track to the signal controller's management
     * @param trackId Track identifier
     * @param track Pointer to track object
     */
    void addTrack(int trackId, Track *track);
};

#endif