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

#ifndef LIBCW_IOMANIP_H
#define LIBCW_IOMANIP_H

RCSTAG_H(iomanip, "$Id$")

#include <iosfwd>
#include <vector>
#include <algorithm>

namespace libcw {

template<class OMANIP_DATA>
  class omanip_id_tct {
    OMANIP_DATA omanip_data;
    std::ios const* id;
  public:
    omanip_id_tct(std::ios const* iosp) : omanip_data(), id(iosp) { }
    bool operator==(std::ios const* iosp) const { return id == iosp; }
    OMANIP_DATA const& get_omanip_data(void) const { return omanip_data; }
    OMANIP_DATA& get_omanip_data(void) { return omanip_data; }
  };

template<class IMANIP_DATA>
  class imanip_id_tct {
    IMANIP_DATA imanip_data;
    std::ios const* id;
  public:
    imanip_id_tct(std::ios const* iosp) : imanip_data(), id(iosp) { }
    bool operator==(std::ios const* iosp) const { return id == iosp; }
    IMANIP_DATA const& get_imanip_data(void) const { return imanip_data; }
    IMANIP_DATA& get_imanip_data(void) { return imanip_data; }
  };

#if __GNUC__ == 2
namespace {

  template<class TYPE>
    struct compiler_bug_workaround {
      static TYPE ids;
    };

  template<class TYPE>
    TYPE compiler_bug_workaround<TYPE>::ids;

} // namespace {anonymous}
#endif

template<class TYPE>
  inline typename TYPE::omanip_data_ct& get_omanip_data(std::ostream const& os)
  {
    typedef omanip_id_tct<typename TYPE::omanip_data_ct> omanip_id_ct;
    typedef std::vector<omanip_id_ct> ids_ct;
#if __GNUC__ == 2
    ids_ct& ids(compiler_bug_workaround<ids_ct>::ids);
#else
    static ids_ct ids;
#endif
    typename ids_ct::iterator i = std::find(ids.begin(), ids.end(), &os);
    if (i == ids.end())
      i = ids.insert(ids.end(), omanip_id_ct(&os));
    return (*i).get_omanip_data();
  }

template<class TYPE>
  inline typename TYPE::imanip_data_ct& get_imanip_data(std::istream const& os)
  {
    typedef imanip_id_tct<typename TYPE::imanip_data_ct> imanip_id_ct;
    typedef std::vector<imanip_id_ct> ids_ct;
#if __GNUC__ == 2
    ids_ct& ids(compiler_bug_workaround<ids_ct>::ids);
#else
    static ids_ct ids;
#endif
    typename ids_ct::iterator i = std::find(ids.begin(), ids.end(), &os);
    if (i == ids.end())
      i = ids.insert(ids.end(), imanip_id_ct(&os));
    return (*i).get_imanip_data();
  }

} // namespace libcw

// Manipulator definitions.

#define __DEFINE_OMANIP0(TYPE, function) \
  enum __omanip0_##function { function }; \
  friend inline std::ostream& operator<<(std::ostream& os, __omanip0_##function) \
      { (libcw::get_omanip_data<TYPE>(os)).function(); return os; }
 
#define __DEFINE_IMANIP0(TYPE, function) \
  enum __imanip0_##function { function }; \
  friend inline istream& operator>>(istream& is, __imanip0_##function) \
      { (libcw::get_imanip_data<TYPE>(is)).function(); return is; }

namespace libcw {

template <class FT, class TP1>
  class manip1_tct {
  public:
    FT func;
    TP1 param1;
    manip1_tct(FT f, TP1 p1) : func(f), param1(p1) { }
  };

} // namespace libcw

#define __DEFINE_OMANIP1_OPERATOR(TYPE, TP1) \
  friend inline std::ostream& operator<<(std::ostream& os, libcw::manip1_tct<void (omanip_data_ct::*)(TP1), TP1> const& m) \
      { (libcw::get_omanip_data<TYPE>(os).*m.func)(m.param1); return os; }

#define __DEFINE_OMANIP1_FUNCTION(function, TP1) \
  static inline libcw::manip1_tct<void (omanip_data_ct::*)(TP1), TP1> function(TP1 p1) \
      { return libcw::manip1_tct<void (omanip_data_ct::*)(TP1), TP1>(&omanip_data_ct::function, p1); }

#define __DEFINE_IMANIP1_OPERATOR(TYPE, TP1) \
  friend inline istream& std::operator>>(std::istream& is, libcw::manip1_tct<void (imanip_data_ct::*)(TP1), TP1> const& m) \
      { (libcw::get_imanip_data<TYPE>(is).*m.func)(m.param1); return is; }

#define __DEFINE_IMANIP1_FUNCTION(function, TP1) \
  static inline libcw::manip1_tct<void (imanip_data_ct::*)(TP1), TP1> function(TP1 p1) \
      { return libcw::manip1_tct<void (imanip_data_ct::*)(TP1), TP1>(&imanip_data_ct::function, p1); }

namespace libcw {

template <class FT, class TP1, class TP2>
  class manip2_tct {
  public:
    FT func;
    TP1 param1;
    TP2 param2;
    manip2_tct(FT f, TP1 p1, TP2 p2) : func(f), param1(p1), param2(p2) { }
  };

} // namespace libcw

#define __DEFINE_OMANIP2_OPERATOR(TYPE, TP1, TP2) \
  friend inline std::ostream& operator<<(std::ostream& os, libcw::manip2_tct<void (omanip_data_ct::*)(TP1, TP2), TP1, TP2> const& m) \
      { (libcw::get_omanip_data<TYPE>(os).*m.func)(m.param1, m.param2); return os; }

#define __DEFINE_OMANIP2_FUNCTION(function, TP1, TP2) \
  static inline libcw::manip2_tct<void (omanip_data_ct::*)(TP1, TP2), TP1, TP2> function(TP1 p1, TP2 p2) \
      { return libcw::manip2_tct<void (omanip_data_ct::*)(TP1, TP2), TP1, TP2>(&omanip_data_ct::function, p1, p2); }

#define __DEFINE_IMANIP2_OPERATOR(TYPE, TP1, TP2) \
  friend inline std::istream& operator>>(std::istream& is, libcw::manip2_tct<void (imanip_data_ct::*)(TP1, TP2), TP1, TP2> const& m) \
      { (libcw::get_imanip_data<TYPE>(is).*m.func)(m.param1, m.param2); return is; }

#define __DEFINE_IMANIP2_FUNCTION(function, TP1, TP2) \
  static inline libcw::manip2_tct<void (imanip_data_ct::*)(TP1, TP2), TP1, TP2> function(TP1 p1, TP2 p2) \
      { return libcw::manip2_tct<void (imanip_data_ct::*)(TP1, TP2), TP1, TP2>(&imanip_data_ct::function, p1, p2); }

#endif // LIBCW_IOMANIP_H
