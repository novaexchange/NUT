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
    uint256 p0 = uint256("0xccdfd64bc8b85762af68ab00d18d46c7266d8547b2e7458dbfd7de10598975a8");
    BOOST_CHECK(Checkpoints::CheckBlock(0, p0));

    // ... any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(0+1, p0));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 0);
}    

BOOST_AUTO_TEST_SUITE_END()
