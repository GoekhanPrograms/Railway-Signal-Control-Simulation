#ifndef RAILWAYSYSTEM_H
#define RAILWAYSYSTEM_H
#include "Junction.h"
#include "SignalController.h"
#include "Train.h"
#include <map>
#include <vector>

/**
 * Central coordinator of the railway system
 *
 * The RailWaySystem acts as the main controller that manages all trains, tracks,
 * and signals. It makes decisions about train movement approvals, coordinates
 * with the SignalController for safety, and handles train routing through junctions.
 * This is the primary interface for managing the entire railway network.
 */

class RailWaySystem
{
private:
    int id;
    Junction *junction;
    SignalController *signal;
    map<int, Train *> trains;
    vector<Track *> tracks;

public:
    /**
     * Constructs a railway system with junction and signal controller
     * @param id System identifier
     * @param junction Primary junction for routing decisions
     * @param signal Signal controller for track safety
     */
    RailWaySystem(int id, Junction *junction, SignalController *signal);

    /**
     * Determines if a train is approved to move to the next track
     * @param trainId ID of the train requesting movement
     * @return true if movement is safe and approved, false otherwise
     */
    bool approveTrainToMove(int trainId);

    /**
     * Adds a train to the system
     * @param trainId Unique train identifier
     * @param train Pointer to the train object
     */
    void addTrain(int trainId, Train *train);

    /**
     * Adds a track to the railway network
     * @param track Pointer to the track object
     */
    void addTrack(Track *track);

    /**
     * Retrieves a track by its ID
     * @param trackId The track identifier
     * @return Pointer to the track, or nullptr if not found
     */
    Track *getTrackById(int trackId);

    /**
     * Retrieves a train by its ID
     * @param trainId The train identifier
     * @return Pointer to the train, or nullptr if not found
     */
    Train *getTrain(int trainId);

    /**
     * Moves a train to its next track
     * @param trainId ID of the train to move
     */
    void moveTrainToNextTrack(int trainId);
};

#endif