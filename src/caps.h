#ifndef CAPABILITY_H
#define CAPABILITY_H


// TODO: add __LINE__ and __FILE__ again for ease of debugging?

#include <sys/types.h>
#include <unistd.h>

#include "utils.h"

#ifdef WS_CAPA
#include <sys/capability.h>
#else
typedef int cap_value_t;
const int CAP_CHOWN = 0;
const int CAP_DAC_OVERRIDE = 1;
const int CAP_DAC_READ_SEARCH=2;
const int CAP_FOWNER = 3;
#endif

class Cap {
private:
    bool hascaps;
    bool issetuid;
    bool isusermode;
public:
    Cap();

    // functions that can be called to raise and lower caps
    void drop_caps(std::vector<cap_value_t>cap_arg, int uid, utils::SrcPos srcpos);
    void lower_cap(int cap, int dbuid, utils::SrcPos);
    void raise_cap(int cap, utils::SrcPos);

    bool isSetuid() {return issetuid;};
};




#endif