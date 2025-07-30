#include <Junction.h>
#include <iostream>

using namespace std;

Junction::Junction(int id) : junctionId(id) {}

int Junction::getNextTrackForDestination(const std::string &destination, int currentTrackId)
{
    int targetTrack = std::stoi(destination.substr(5)); // Get the destination track number

    if (currentTrackId == 5)
    {
        if (targetTrack >= 6 && targetTrack <= 14)
        {
            return 6;
        }
        else if (targetTrack >= 15 && targetTrack <= 23)
        {
            return 15;
        }
    }

    else if (currentTrackId == 10)
    {
        if (targetTrack >= 11 && targetTrack <= 12)
        {
            return 11;
        }
        else if (targetTrack >= 13 && targetTrack <= 14)
        {
            return 13;
        }
    }
    else if (currentTrackId == 19)
    {
        if (targetTrack >= 20 && targetTrack <= 21)
        {
            return 20;
        }
        else if (targetTrack >= 22 && targetTrack <= 23)
        {
            return 22;
        }
    }

    return currentTrackId + 1;
}
