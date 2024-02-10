#include <type_traits>
#include <boost/units/systems/si/length.hpp>
// Remove this when https://github.com/boostorg/units/issues/60 is fixed:
#include <boost/units/systems/si/io.hpp>

using namespace boost::units;
using namespace boost::units::si;

static_assert(std::is_trivial_v<quantity<length>>);

int main() {
   return 0;
}
