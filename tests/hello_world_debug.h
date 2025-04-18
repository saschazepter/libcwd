// This header file is an example of how to write a "debug.h" file
// in the case that your application want to define its own debug channels.
// This example belongs to 'hello_world.cc'.

#ifndef DEBUG_H
#define DEBUG_H

#ifndef CWDEBUG               // This is needed so that others can compile
#include "nodebug.h"          //   your application without having libcwd installed.
			      //   nodebug.h is distributed with the libcwd package
			      //   but must be included in your own package.
			      // Note: you can also just copy nodebug.h here.
#else // CWDEBUG

// Define the namespace where you will put your debug channels.
// This can be any arbitrary namespace except std:: or ::.
#define DEBUGCHANNELS debug_channels
#include <libcwd/debug.h>

namespace debug_channels {    // This is namespace DEBUGCHANNELS
  namespace dc {
    using namespace libcwd::channels::dc;

    // Add custom debug channels here.
    extern libcwd::channel_ct hello; 
  }
}

#endif // CWDEBUG
#endif // DEBUG_H
