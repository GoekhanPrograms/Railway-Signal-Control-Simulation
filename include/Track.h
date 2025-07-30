#ifndef TRACK_H
#define TRACK_H
#include "junction.h"
#include "SignalController.h"
#include <string>

using namespace std;

/**
 * Represents a physical segment of railway track
 *
 * A Track is a fundamental component of the railway network representing
 * a single segment where trains can be positioned. Each track knows its
 * occupancy status, unique identifier, and whether it contains a junction.
 * Tracks are the basic building blocks that trains move between.
 */

class Track
{
private:
    bool isOccupied = false;
    int trackId;
    bool hasJunction = false;
    Junction *junction = nullptr;

public:
    /**
     * Constructs a track with the given ID
     * @param id Unique track identifier
     */
    Track(int id);

    /**
     * Gets the occupancy status of the track
     * @return true if occupied by a train, false if free
     */
    bool getIsOccupied();

    /**
     * Sets the occupancy status of the track
     * @param isOccupied true if train is on track, false if free
     */
    void setOccupied(bool isOccupied);

    /**
     * Gets the track's unique identifier
     * @return Track ID number
     */
    int getTrackId();

    /**
     * Sets the track's identifier
     * @param id New track ID
     */
    void setTrackId(int id);

    /**
     * Checks if this track has a junction
     * @return true if track contains a junction, false otherwise
     */
    bool getHasJunction() const;

    /**
     * Sets junction status and reference for this track
     * @param hasJunc true if track has junction
     * @param junc Pointer to junction object (optional)
     */
    void setHasJunction(bool hasJunc, Junction *junc = nullptr);

    /**
     * Gets the junction associated with this track
     * @return Pointer to junction, or nullptr if no junction
     */
    Junction *getJunction() const;
};

#endif