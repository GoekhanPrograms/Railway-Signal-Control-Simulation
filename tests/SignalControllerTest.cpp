#include <gtest/gtest.h>
#include "SignalController.h"
#include "Track.h"

class SignalControllerTest : public ::testing::Test
{
protected:
    SignalController *controller = nullptr;
    void SetUp() override
    {
        controller = new SignalController();
    }
};

TEST_F(SignalControllerTest, CheckSafety)
{
    Track *track = new Track(0);
    Track *track2 = new Track(1);
    track->setOccupied(true);
    controller->addTrack(0, track);
    controller->addTrack(1, track2);
    EXPECT_FALSE(controller->isSafeToEnter(0));
}

TEST_F(SignalControllerTest, CheckNextTrackFree)
{
    Track *track = new Track(0);
    track->setOccupied(true);
    controller->addTrack(0, track);
    EXPECT_TRUE(controller->isNextTrackFree(0));
}
