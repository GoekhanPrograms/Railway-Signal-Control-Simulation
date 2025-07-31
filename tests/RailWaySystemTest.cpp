#include <gtest/gtest.h>
#include "RailWaySystem.h"
#include "Train.h"

/** Finished results:
 * [==========] Running 5 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from JunctionTest
[ RUN      ] JunctionTest.CheckNextTrack
[       OK ] JunctionTest.CheckNextTrack (0 ms)
[----------] 1 test from JunctionTest (3 ms total)

[----------] 2 tests from SignalControllerTest
[ RUN      ] SignalControllerTest.CheckSafety
[       OK ] SignalControllerTest.CheckSafety (0 ms)
[ RUN      ] SignalControllerTest.CheckNextTrackFree
[       OK ] SignalControllerTest.CheckNextTrackFree (0 ms)
[----------] 2 tests from SignalControllerTest (7 ms total)

[----------] 2 tests from RailWaySystemTest
[ RUN      ] RailWaySystemTest.CheckApproveTrain
Not safe to enter next track
[       OK ] RailWaySystemTest.CheckApproveTrain (0 ms)
[ RUN      ] RailWaySystemTest.CheckIfMoved
[       OK ] RailWaySystemTest.CheckIfMoved (0 ms)
[----------] 2 tests from RailWaySystemTest (8 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 3 test suites ran. (35 ms total)
[  PASSED  ] 5 tests.
 */

class RailWaySystemTest : public ::testing::Test
{
protected:
    RailWaySystem *system = nullptr;
    SignalController *signal = nullptr;
    Junction *junction = nullptr;

    void SetUp() override
    {
        junction = new Junction(1);
        signal = new SignalController();
        system = new RailWaySystem(1, junction, signal);
    }
};

TEST_F(RailWaySystemTest, CheckApproveTrain)
{
    Train *train = new Train(1, new Track(7), "Track8");
    system->addTrain(1, train);
    Track *track8 = new Track(8);
    system->addTrack(track8);
    signal->addTrack(8, track8);
    EXPECT_TRUE(system->approveTrainToMove(1)); // No train on next Track
    track8->setOccupied(true);
    EXPECT_FALSE(system->approveTrainToMove(1)); // Track is occupied
}

TEST_F(RailWaySystemTest, CheckIfMoved)
{
    Train *train = new Train(1, new Track(7), "Track8");
    system->addTrain(1, train);
    system->addTrack(new Track(8));
    system->moveTrainToNextTrack(1);
    EXPECT_EQ(train->getCurrentTrack().getTrackId(), 8); // Track moved
}