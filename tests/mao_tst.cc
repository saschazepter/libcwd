// $Header$
//
// Copyright (C) 2000, by
// 
// Carlo Wood, Run on IRC <carlo@alinoe.com>
// RSA-1024 0x624ACAD5 1997-01-26                    Sign & Encrypt
// Fingerprint16 = 32 EC A7 B6 AC DB 65 A6  F6 F6 55 DD 1C DC FF 61
//
// This file may be distributed under the terms of the Q Public License
// version 1.0 as appearing in the file LICENSE.QPL included in the
// packaging of this file.
//

#include "libcw/sys.h"
#include "libcw/h.h"
#include "libcw/debug.h"

RCSTAG_CC("$Id$")

int main(int UNUSED(argc), char *argv[])
{
  Debug( check_configuration() );

  // Select channels
  ForAllDebugChannels( if (debugChannel.is_on()) debugChannel.off(); );
  Debug( dc::warning.on() );
  Debug( dc::notice.on() );
  Debug( dc::malloc.on() );

  // Turn debug object on
  Debug( libcw_do.on() );

  // Print channels
  Debug( list_channels_on(libcw_do) );

  int *p = new int[5];
  AllocTag(p, "Test array");

#ifdef DEBUGMALLOC
  // Print memory allocations
  Debug( list_allocations_on(libcw_do) );
#else
  cerr << "`libcwd' does not have memory allocation debugging compiled in.\n"
          "Configure `libcwd' using the `configure' option --enable-alloc.\n" 
          "Then recompile libcwd.\n";
#endif

  delete [] p;

  return 0;
}
