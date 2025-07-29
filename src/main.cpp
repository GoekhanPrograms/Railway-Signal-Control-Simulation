#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Track.h>

using namespace std;

/**
 * We will use 23 tracks to simulate a railway system. Two trains will move along these
 * tracks simultaneously.
 * At every 5 tracks it splits into two tracks, like 5 -> 5-10 & 14-19 -> 10-14 & 19-23 (essentialy three junctions).
 * Each track has a name as string that is assigned to respectively the id.
 */

int main()
{
    map<int, string> trackNames;
    for (int i = 0; i < 23; ++i)
    {
        trackNames[i] = "Track" + to_string(i + 1);
    }
    // Track tracks[23];
    // tracks[5].hasJunction = true;
}