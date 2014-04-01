#include <ma.h>
#include <MAUtil/Moblet.h>
#include "PrototypeMoblet.h"
#include <ma>

/**
 * Main function that is called when the program starts.
 */
extern "C" int MAMain()
{
       // vmml::matrix<4,4,int> fooMatrix = new vmml::matrix<4,4,int>();
        MAUtil::Moblet::run(new PrototypeMoblet());
	return 0;
}
