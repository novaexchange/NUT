//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p0 = uint256("0xe3d4af8e968b4613bf036de1b155c690050624c560592722465d6ebbc0fec37c");
    BOOST_CHECK(Checkpoints::CheckBlock(0, p0));

    // ... any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(0+1, p0));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 0);
}    

BOOST_AUTO_TEST_SUITE_END()
