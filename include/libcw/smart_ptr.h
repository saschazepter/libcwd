// $Header$
//
// Copyright (C) 2002, by
//
// Carlo Wood, Run on IRC <carlo@alinoe.com>
// RSA-1024 0x624ACAD5 1997-01-26                    Sign & Encrypt
// Fingerprint16 = 32 EC A7 B6 AC DB 65 A6  F6 F6 55 DD 1C DC FF 61
//
// This file may be distributed under the terms of the Q Public License
// version 1.0 as appearing in the file LICENSE.QPL included in the
// packaging of this file.
//

/** \file libcw/smart_ptr.h
 * Do not include this header file directly, instead include "\ref preparation_step2 "debug.h"".
 */

#ifndef	LIBCW_SMART_PTR_H
#define	LIBCW_SMART_PTR_H

#ifndef LIBCW_PRIVATE_STRUCT_TSD_H
#include <libcw/private_struct_TSD.h>
#endif

namespace libcw {
  namespace debug {
    namespace _private_ {

class refcnt_charptr_ct {
private:
  int M_reference_count;	// Number of smart_ptr objects pointing to this stub, or -1 when M_ptr points to a string literal.
  char* M_ptr;			// Pointer to the actual character string, either allocated with new char[...] or a string literal.
public:
  refcnt_charptr_ct(char* ptr) : M_reference_count(1), M_ptr(ptr) { }
  refcnt_charptr_ct(char const* ptr) : M_reference_count(-1), M_ptr(const_cast<char*>(ptr)) { }
  void increment(void)
  {
    if (M_reference_count != -1)
      ++M_reference_count;
  }
  bool decrement(void)
  {
    if (M_ptr && M_reference_count != -1 && --M_reference_count == 0)
    {
      delete [] M_ptr;
      M_ptr = NULL;
      return true;
    }
    return false;
  }
  char* get(void) const { return M_ptr; }
  int reference_count(void) const { return M_reference_count; }
};

class smart_ptr {
private:
  refcnt_charptr_ct* M_ptr;

public:
  // Default constructor and destructor.
  smart_ptr(void) : M_ptr(NULL) { }
  ~smart_ptr() { if (M_ptr) M_ptr->decrement(); }

  // Copy constructor.
  smart_ptr(smart_ptr const& ptr) : M_ptr(NULL) { copy_from(ptr); }

  // Other constructors.
  smart_ptr(char const* ptr) : M_ptr(NULL) { copy_from(ptr); }
  smart_ptr(char* ptr) : M_ptr(NULL) { copy_from(ptr); }

public:
  // Assignment operators.
  smart_ptr& operator=(smart_ptr const& ptr) { copy_from(ptr); return *this; }
  smart_ptr& operator=(char const* ptr) { copy_from(ptr); return *this; }
  smart_ptr& operator=(char* ptr) { copy_from(ptr); return *this; }

public:
  // Casting operators.
  operator char* (void) { return M_ptr->get(); }
  operator char const* (void) const { return M_ptr->get(); }

  // Comparison Operators.
  bool operator==(smart_ptr const& ptr) const { return M_ptr == ptr.M_ptr; }
  bool operator==(char const* ptr) const { return M_ptr->get() == ptr; }
  bool operator!=(smart_ptr const& ptr) const { return M_ptr != ptr.M_ptr; }
  bool operator!=(char const* ptr) const { return M_ptr->get() != ptr; }

public:
  int get_reference_count(void) const { return M_ptr ? M_ptr->reference_count() : 0; }
  bool is_null(void) const { return M_ptr == NULL; }
  char const* get(void) const { return M_ptr->get(); }

protected:
  // Helper methods.
  void copy_from(smart_ptr const& ptr);
  void copy_from(char const* ptr);
  void copy_from(char* ptr);

private:
  // Implementation.
  void increment(void) { if (M_ptr) M_ptr->increment(); }
  void decrement(LIBCWD_TSD_PARAM);
};
		
    } // namespace _private_
  } // namespace debug
} // namespace libcw

#endif // LIBCW_SMART_PTR_H
