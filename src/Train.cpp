#include "Train.h"

using namespace std;

/**
 * • Train:
 model the train: its ID, position, maybe direction or destination. This is a passive component —
 it reacts to the system but doesn’t make decisions.
 */
Train::Train(int id, int position, string destination)
{
    this->id = id;
    this->destination = destination;
}