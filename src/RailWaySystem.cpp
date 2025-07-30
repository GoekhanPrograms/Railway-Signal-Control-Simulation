#include "RailWaySystem.h"
#include <iostream>

using namespace std;

RailWaySystem::RailWaySystem(int id, Junction *junction, SignalController *signal)
{
    this->id = id;
    this->junction = junction;
    this->signal = signal;
}

bool RailWaySystem::approveTrainToMove(int trainId)
{
    Train *train = getTrain(trainId);
    if (!train)
    {
        return false; // Train not found
    }

    Track &currentTrack = train->getCurrentTrack();
    int currentTrackId = currentTrack.getTrackId();

    string destination = train->getDestination();
    int destinationTrackId = std::stoi(destination.substr(5));

    if (currentTrackId == destinationTrackId)
    {
        cout << "Train " << train->getId() << " has reached destination" << endl;
        return false; // Destination reached
    }

    int nextTrackId;
    if (currentTrack.getHasJunction())
    {
        Junction *junction = currentTrack.getJunction();
        nextTrackId = junction->getNextTrackForDestination(train->getDestination(),
                                                           currentTrackId);
    }
    else
    {
        nextTrackId = currentTrackId + 1;
    }

    if (currentTrackId > 23)
    {
        cout << "Reached the end of the railway" << endl;
        return false;
    }

    Track *nextTrack = getTrackById(nextTrackId);
    if (!nextTrack)
    {
        cout << "Track not found" << endl;
        return false;
    }

    if (!signal->isSafeToEnter(nextTrackId))
    {
        cout << "Not safe to enter next track" << endl;
        return false;
    }

    if (nextTrack->getIsOccupied())
    {
        cout << "Track is occupied" << endl;
        return false;
    }

    return true;
}

void RailWaySystem::addTrain(int trainId, Train *train)
{
    trains[trainId] = train;
}

void RailWaySystem::addTrack(Track *track)
{
    tracks.push_back(track);
}

Track *RailWaySystem::getTrackById(int trackId)
{
    for (auto &track : tracks)
    {
        if (track->getTrackId() == trackId)
        {
            return track;
        }
    }
    return nullptr; // Not found
}

void RailWaySystem::moveTrainToNextTrack(int trainId)
{
    Train *train = getTrain(trainId);
    if (!train)
    {
        return;
    }

    Track &currentTrack = train->getCurrentTrack();
    int currentTrackId = currentTrack.getTrackId();

    int nextTrackId;
    if (currentTrack.getHasJunction())
    {
        Junction *junction = currentTrack.getJunction();
        nextTrackId = junction->getNextTrackForDestination(train->getDestination(),
                                                           currentTrackId);
    }
    else
    {
        nextTrackId = currentTrackId + 1;
    }

    Track *nextTrack = getTrackById(nextTrackId);
    if (!nextTrack)
    {
        return;
    }

    currentTrack.setOccupied(false);
    train->setCurrentTrack(nextTrack);
    nextTrack->setOccupied(true);

    signal->setSignal(currentTrackId, GREEN);
    signal->setSignal(nextTrackId, RED);
}

Train *RailWaySystem::getTrain(int trainId)
{
    auto it = trains.find(trainId);
    if (it != trains.end())
    {
        return it->second;
    }
    return nullptr; // Not found
}