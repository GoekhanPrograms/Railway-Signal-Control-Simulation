#ifndef JUNCTION_H
#define JUNCTION_H
#include <vector>
#include <string>
#include "SignalController.h"

/**
 * Represents a railway junction that routes trains based on destinations
 *
 * A Junction determines the next track for a train based on its current position
 * and destination. It handles the branching logic at decision points in the
 * railway network (tracks 5, 10, and 19).
 */

class Junction
{
private:
    int junctionId;

public:
    /**
     * Constructs a junction with the given ID
     * @param junctionId Unique identifier for this junction
     */
    Junction(int junctionId);

    /**
     * Determines the next track based on train's destination
     * @param destination The train's target destination (format: "TrackX")
     * @param currentTrackId The track the train is currently on
     * @return ID of the next track the train should move to
     */
    int getNextTrackForDestination(const std::string &destination, int currentTrackId);
};

#endif