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

#ifndef LIBCW_BFD_H
#define LIBCW_BFD_H

#ifndef DEBUGUSEBFD

RCSTAG_H(nobfd, "$Id$")

#else // DEBUGUSEBFD

RCSTAG_H(bfd, "$Id$")

#include <bfd.h>

#ifndef DEBUGNONAMESPACE
namespace libcw {
  namespace debug {
#endif

class location_ct;

#ifndef DEBUGNONAMESPACE
  };
};
#endif // DEBUGNONAMESPACE

extern ostream& operator<<(ostream& os, libcw::debug::location_ct const& location);

#ifndef DEBUGNONAMESPACE
namespace libcw {
  namespace debug {
#endif

namespace channels {
  namespace dc {
    extern channel_ct const bfd;
  };
};

extern char const* pc_function_name(void const* addr);
extern char const* const unknown_function_c;

//
// class location_ct
//
// The normal usage of this class is to print file-name:line-number information as follows:
// Dout(dc::notice, "Called from " << location_ct((char*)__builtin_return_address(0) + libcw_bfd_builtin_return_address_offset) );
//
class location_ct {
private:
  char* M_filepath;				// Allocated in `M_pc_location' using new [], or NULL when unknown.
  char* M_filename;				// Points inside M_filepath just after the last '/' or to the beginning.
  unsigned int M_line;
  char const* M_func;				// Pointer to static string.

  void M_pc_location(void const* addr);

public:
  // Constructor
  location_ct(void const* addr) { M_pc_location(addr); }
      // Construct a location object for address `addr'.

  // Destructor
  ~location_ct() { clear(); }

  // Provided, but deprecated (I honestly think you never need them):
  location_ct(void) : M_filepath(NULL), M_func("<uninitialized location_ct>") { }	// Default constructor
  location_ct(location_ct const& location);						// Copy constructor
  location_ct& operator=(location_ct const& location);					// Assignment operator

  void pc_location(void const* addr) { clear(); M_pc_location(addr); }
      // Set this location object to a different address.

  void clear(void);
      // Reset this location object (frees memory).

public:
  // Accessors
  bool is_known(void) const { return M_filepath != NULL; }
      // Returns false if no source-file:line-number information is known for this location (or when it is uninitialized or cleared).

  string filename(void) const { ASSERT( M_filepath != NULL ); return M_filename; }
      // Return the source file name (without path).  We don't allow to retrieve a pointer
      // to M_filepath; that is dangerous as the memory that it is pointing to could be deleted.

  unsigned int line(void) const { return M_line; }
      // Return the line number; only valid if is_known() returns true.

  char const* function(void) const { return M_func; }
      // Return the mangled function name or `unknown_location_c' when no function could be found.
      // Two other strings that can be returned are "<uninitialized location_ct>" and "<cleared location_ct>",
      // the idea is to never print that: you should know it when a location object is in these states.

  // Printing
  void print_filepath_on(ostream& os) const { ASSERT( M_filepath != NULL ); os << M_filepath; }
  void print_filename_on(ostream& os) const { ASSERT( M_filepath != NULL ); os << M_filename; }
  friend ostream& ::operator<<(ostream& os, location_ct const& location);		// Prints a default "M_filename:M_line".
};

#ifndef DEBUGNONAMESPACE
  };
};
#endif // DEBUGNONAMESPACE

#endif // DEBUGUSEBFD

#endif // LIBCW_BFD_H
