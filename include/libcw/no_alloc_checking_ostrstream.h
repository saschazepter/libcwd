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

#ifndef LIBCW_NO_ALLOC_CHECKING_OSTRSTREAM_H
#define LIBCW_NO_ALLOC_CHECKING_OSTRSTREAM_H

RCSTAG_H(no_alloc_checking_ostrstream, "$Id$")

#include <strstream>

namespace libcw {
  namespace debug {

#ifdef DEBUGMALLOC

class no_alloc_checking_ostrstream : public std::ostrstream {
private:
  std::strstreambuf* my_sb;
public:
  no_alloc_checking_ostrstream(void);
  ~no_alloc_checking_ostrstream();
  std::strstreambuf* rdbuf() { return my_sb; }
};

#else // !DEBUGMALLOC

typedef ostrstream no_alloc_checking_ostrstream;

#endif // !DEBUGMALLOC

  }	// namespace debug
}	// namespace libcw

#endif // LIBCW_NO_ALLOC_CHECKING_OSTRSTREAM_H
