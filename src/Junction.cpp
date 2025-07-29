#include <Junction.h>

using namespace std;

void Junction::switchTo(int idx)
{
    if (idx >= 0 && idx < routes.size())
    {
        activeOption = idx;
    }
    // Track *nextTrack;
    // nextTrack->setTrackId(targetTrack->getTrackId() + 1); // next Track's ID
}

Track *Junction::getActiveTrackId()
{
    return routes[activeOption];
}
