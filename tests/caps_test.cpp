#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch_test_macros.hpp>


#include "../src/caps.h"

#include <sys/capability.h>


bool debugflag = false;
bool traceflag = false;

TEST_CASE( "Caps", "[capabilities]" ) {

  Cap caps{}; // default constructor without arguments

  SECTION("check interfaces are present and callable") {
    bool issetuid = caps.isSetuid(); // isSetuid()
    bool hascaps = caps.hasCaps(); // hasCaps()
    bool isusermode = caps.isUserMode(); // isUserMode()
  }

  SECTION("check cap drop is present and callable") {
    caps.drop_caps({CAP_DAC_OVERRIDE, CAP_CHOWN, CAP_FOWNER}, getuid(), utils::SrcPos(__FILE__, __LINE__, __func__));
  }

}