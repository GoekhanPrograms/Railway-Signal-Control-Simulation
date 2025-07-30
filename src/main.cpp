#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../include/Track.h"
#include "../include/Train.h"
#include "../include/SignalController.h"
#include "../include/RailWaySystem.h"
#include "../include/Junction.h"

using namespace std;

/**
 * We will use 23 tracks to simulate a railway system. Two trains will move along these
 * tracks simultaneously.
 * At every 5 tracks it splits into two tracks, like 5 -> 5-10 & 14-19 -> 10-12 and 12-14 & 19-21 and 21-23 (essentialy three junctions).
 * Each track has a name as string that is assigned to respectively the id.
 * Visually, it looks like this:
 * 1 → 2 → 3 → 4 → 5 (Junction 1)
                 ├─→ 6 → 7 → 8 → 9 → 10 (Junction 2)
                 │                    ├─→ 11 → 12
                 │                    └─→ 13 → 14
                 └─→ 15 → 16 → 17 → 18 → 19 (Junction 3)
                                           ├─→ 20 → 21
                                           └─→ 22 → 23
 */

int main()
{
    map<int, string> trackNames;
    for (int i = 0; i < 23; ++i)
    {
        trackNames[i] = "Track" + to_string(i + 1);
    }

    // 2. Create actual Track objects
    vector<Track *> tracks;
    for (int i = 0; i < 23; ++i)
    {
        Track *track = new Track(i + 1); // Track IDs start from 1
        tracks.push_back(track);
    }

    // Set up junctions
    Junction *junction1 = new Junction(1);
    Junction *junction2 = new Junction(2);
    Junction *junction3 = new Junction(3);

    tracks[4]->setHasJunction(true, junction1);  // Track 5
    tracks[9]->setHasJunction(true, junction2);  // Track 10
    tracks[18]->setHasJunction(true, junction3); // Track 19

    // Create SignalController
    SignalController *signalController = new SignalController();
    for (Track *track : tracks)
    {
        signalController->addTrack(track->getTrackId(), track);
    }

    // Create RailWaySystem
    RailWaySystem *railwaySystem = new RailWaySystem(1, junction1, signalController);

    // Add all tracks to railway system
    for (Track *track : tracks)
    {
        railwaySystem->addTrack(track);
    }

    // Create trains
    Train *train1 = new Train(1, tracks[0], "Track15");
    Train *train2 = new Train(2, tracks[2], "Track20");

    // Add trains to system
    railwaySystem->addTrain(1, train1);
    railwaySystem->addTrain(2, train2);

    // Mark initial tracks as occupied
    tracks[0]->setOccupied(true);
    tracks[2]->setOccupied(true);

    // Simulation
    cout << "Starting Railway Simulation..." << endl;

    for (int step = 0; step < 15; ++step)
    {
        cout << "\n--- Simulation Step " << step + 1 << " ---" << endl;

        // Try to move train 1
        if (railwaySystem->approveTrainToMove(1))
        {
            cout << "Train 1 approved to move" << endl;
            railwaySystem->moveTrainToNextTrack(1);
        }
        else
        {
            cout << "Train 1 movement denied" << endl;
        }

        // Try to move train 2
        if (railwaySystem->approveTrainToMove(2))
        {
            cout << "Train 2 approved to move" << endl;
            railwaySystem->moveTrainToNextTrack(2);
        }
        else
        {
            cout << "Train 2 movement denied" << endl;
        }

        // Print status
        cout << "Train 1 on: " << trackNames[train1->getCurrentTrack().getTrackId() - 1] << endl;
        cout << "Train 2 on: " << trackNames[train2->getCurrentTrack().getTrackId() - 1] << endl;
    }

    // Cleanup
    for (Track *track : tracks)
        delete track;
    delete train1;
    delete train2;
    delete signalController;
    delete railwaySystem;
    delete junction1;
    delete junction2;
    delete junction3;

    return 0;
};