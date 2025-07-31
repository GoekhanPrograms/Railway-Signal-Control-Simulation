#include <gtest/gtest.h>
#include "Junction.h"

class JunctionTest : public ::testing::Test
{
protected:
    Junction *junction = nullptr;

    void SetUp() override
    {
        junction = new Junction(1);
    }
};

TEST_F(JunctionTest, CheckNextTrack)
{
    // Destination "Track8" -> will be turned into "8"; currentTrackId = 5 => has to equal 6
    EXPECT_EQ(junction->getNextTrackForDestination("Track8", 5), 6);
    EXPECT_EQ(junction->getNextTrackForDestination("Track12", 10), 11);
    EXPECT_EQ(junction->getNextTrackForDestination("Track14", 10), 13);
}