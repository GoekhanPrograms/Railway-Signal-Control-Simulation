#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include "Track.h"

/**
 * Represents a train in the railway system
 *
 * A Train is a mobile entity that moves through the railway network from
 * track to track. Each train has a unique identifier, knows its current
 * position, and has a destination it's trying to reach. Trains are passive
 * components that respond to system decisions rather than making autonomous choices.
 */

class Train
{
private:
    int id;
    Track *currentTrack;
    string destination;

public:
    /**
     * Constructs a train with ID, starting position, and destination
     * @param id Unique train identifier
     * @param currentTrack Starting track position
     * @param destination Target destination in format "TrackX"
     */
    Train(int id, Track *currentTrack, string destination);
    /**
     * Gets the track the train is currently positioned on
     * @return Reference to current track
     */
    Track &getCurrentTrack();

    /**
     * Moves the train to a new track
     * @param track Pointer to the new track
     */
    void setCurrentTrack(Track *track);

    /**
     * Gets the train's unique identifier
     * @return Train ID number
     */
    int getId();

    /**
     * Gets the train's destination
     * @return Destination string in format "TrackX"
     */
    string getDestination();

    /**
     * Sets a new destination for the train
     * @param destination New destination in format "TrackX"
     */
    void setDestination(string destination);
};

#endif