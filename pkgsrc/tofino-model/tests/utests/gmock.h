// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This is the main header file a user should include.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_H_

// This file implements the following syntax:
//
//   ON_CALL(mock_object.Method(...))
//     .With(...) ?
//     .WillByDefault(...);
//
// where With() is optional and WillByDefault() must appear exactly
// once.
//
//   EXPECT_CALL(mock_object.Method(...))
//     .With(...) ?
//     .Times(...) ?
//     .InSequence(...) *
//     .WillOnce(...) *
//     .WillRepeatedly(...) ?
//     .RetiresOnSaturation() ? ;
//
// where all clauses are optional and WillOnce() can be repeated.

// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some commonly used actions.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_

#ifndef _WIN32_WCE
# include <errno.h>
#endif

#include <algorithm>
#include <string>

// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file defines some utilities useful for implementing Google
// Mock.  They are subject to change without notice, so please DO NOT
// USE THEM IN USER CODE.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_
#define GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_

#include <stdio.h>
#include <ostream>  // NOLINT
#include <string>
// This file was GENERATED by command:
//     pump.py gmock-generated-internal-utils.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file contains template meta-programming utility classes needed
// for implementing Google Mock.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_GENERATED_INTERNAL_UTILS_H_
#define GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_GENERATED_INTERNAL_UTILS_H_

// Copyright 2008, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: vadimb@google.com (Vadim Berman)
//
// Low-level types and utilities for porting Google Mock to various
// platforms.  All macros ending with _ and symbols defined in an
// internal namespace are subject to change without notice.  Code
// outside Google Mock MUST NOT USE THEM DIRECTLY.  Macros that don't
// end with _ are part of Google Mock's public API and can be used by
// code outside Google Mock.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PORT_H_
#define GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PORT_H_

#include <assert.h>
#include <stdlib.h>
#include <iostream>

// Most of the utilities needed for porting Google Mock are also
// required for Google Test and are defined in gtest-port.h.
//
// Note to maintainers: to reduce code duplication, prefer adding
// portability utilities to Google Test's gtest-port.h instead of
// here, as Google Mock depends on Google Test.  Only add a utility
// here if it's truly specific to Google Mock.

#include "gtest.h"
// Copyright 2015, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Injection point for custom user configurations.
// The following macros can be defined:
//
//   Flag related macros:
//     GMOCK_DECLARE_bool_(name)
//     GMOCK_DECLARE_int32_(name)
//     GMOCK_DECLARE_string_(name)
//     GMOCK_DEFINE_bool_(name, default_val, doc)
//     GMOCK_DEFINE_int32_(name, default_val, doc)
//     GMOCK_DEFINE_string_(name, default_val, doc)
//
// ** Custom implementation starts here **

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_PORT_H_
#define GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_PORT_H_

#endif  // GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_PORT_H_

// For MS Visual C++, check the compiler version. At least VS 2003 is
// required to compile Google Mock.
#if defined(_MSC_VER) && _MSC_VER < 1310
# error "At least Visual C++ 2003 (7.1) is required to compile Google Mock."
#endif

// Macro for referencing flags.  This is public as we want the user to
// use this syntax to reference Google Mock flags.
#define GMOCK_FLAG(name) FLAGS_gmock_##name

#if !defined(GMOCK_DECLARE_bool_)

// Macros for declaring flags.
# define GMOCK_DECLARE_bool_(name) extern GTEST_API_ bool GMOCK_FLAG(name)
# define GMOCK_DECLARE_int32_(name) \
    extern GTEST_API_ ::testing::internal::Int32 GMOCK_FLAG(name)
# define GMOCK_DECLARE_string_(name) \
    extern GTEST_API_ ::std::string GMOCK_FLAG(name)

// Macros for defining flags.
# define GMOCK_DEFINE_bool_(name, default_val, doc) \
    GTEST_API_ bool GMOCK_FLAG(name) = (default_val)
# define GMOCK_DEFINE_int32_(name, default_val, doc) \
    GTEST_API_ ::testing::internal::Int32 GMOCK_FLAG(name) = (default_val)
# define GMOCK_DEFINE_string_(name, default_val, doc) \
    GTEST_API_ ::std::string GMOCK_FLAG(name) = (default_val)

#endif  // !defined(GMOCK_DECLARE_bool_)

#endif  // GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PORT_H_

namespace testing {

template <typename T>
class Matcher;

namespace internal {

// An IgnoredValue object can be implicitly constructed from ANY value.
// This is used in implementing the IgnoreResult(a) action.
class IgnoredValue {
 public:
  // This constructor template allows any value to be implicitly
  // converted to IgnoredValue.  The object has no data member and
  // doesn't try to remember anything about the argument.  We
  // deliberately omit the 'explicit' keyword in order to allow the
  // conversion to be implicit.
  template <typename T>
  IgnoredValue(const T& /* ignored */) {}  // NOLINT(runtime/explicit)
};

// MatcherTuple<T>::type is a tuple type where each field is a Matcher
// for the corresponding field in tuple type T.
template <typename Tuple>
struct MatcherTuple;

template <>
struct MatcherTuple< ::testing::tuple<> > {
  typedef ::testing::tuple< > type;
};

template <typename A1>
struct MatcherTuple< ::testing::tuple<A1> > {
  typedef ::testing::tuple<Matcher<A1> > type;
};

template <typename A1, typename A2>
struct MatcherTuple< ::testing::tuple<A1, A2> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2> > type;
};

template <typename A1, typename A2, typename A3>
struct MatcherTuple< ::testing::tuple<A1, A2, A3> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3> > type;
};

template <typename A1, typename A2, typename A3, typename A4>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4> >
      type;
};

template <typename A1, typename A2, typename A3, typename A4, typename A5>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                           Matcher<A5> >
      type;
};

template <typename A1, typename A2, typename A3, typename A4, typename A5,
    typename A6>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                           Matcher<A5>, Matcher<A6> >
      type;
};

template <typename A1, typename A2, typename A3, typename A4, typename A5,
    typename A6, typename A7>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                           Matcher<A5>, Matcher<A6>, Matcher<A7> >
      type;
};

template <typename A1, typename A2, typename A3, typename A4, typename A5,
    typename A6, typename A7, typename A8>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                           Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8> >
      type;
};

template <typename A1, typename A2, typename A3, typename A4, typename A5,
    typename A6, typename A7, typename A8, typename A9>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                           Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>,
                           Matcher<A9> >
      type;
};

template <typename A1, typename A2, typename A3, typename A4, typename A5,
    typename A6, typename A7, typename A8, typename A9, typename A10>
struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
    A10> > {
  typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                           Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>,
                           Matcher<A9>, Matcher<A10> >
      type;
};

// Template struct Function<F>, where F must be a function type, contains
// the following typedefs:
//
//   Result:               the function's return type.
//   ArgumentN:            the type of the N-th argument, where N starts with 1.
//   ArgumentTuple:        the tuple type consisting of all parameters of F.
//   ArgumentMatcherTuple: the tuple type consisting of Matchers for all
//                         parameters of F.
//   MakeResultVoid:       the function type obtained by substituting void
//                         for the return type of F.
//   MakeResultIgnoredValue:
//                         the function type obtained by substituting Something
//                         for the return type of F.
template <typename F>
struct Function;

template <typename R>
struct Function<R()> {
  typedef R Result;
  typedef ::testing::tuple<> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid();
  typedef IgnoredValue MakeResultIgnoredValue();
};

template <typename R, typename A1>
struct Function<R(A1)>
    : Function<R()> {
  typedef A1 Argument1;
  typedef ::testing::tuple<A1> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1);
  typedef IgnoredValue MakeResultIgnoredValue(A1);
};

template <typename R, typename A1, typename A2>
struct Function<R(A1, A2)>
    : Function<R(A1)> {
  typedef A2 Argument2;
  typedef ::testing::tuple<A1, A2> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2);
};

template <typename R, typename A1, typename A2, typename A3>
struct Function<R(A1, A2, A3)>
    : Function<R(A1, A2)> {
  typedef A3 Argument3;
  typedef ::testing::tuple<A1, A2, A3> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3);
};

template <typename R, typename A1, typename A2, typename A3, typename A4>
struct Function<R(A1, A2, A3, A4)>
    : Function<R(A1, A2, A3)> {
  typedef A4 Argument4;
  typedef ::testing::tuple<A1, A2, A3, A4> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4);
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5>
struct Function<R(A1, A2, A3, A4, A5)>
    : Function<R(A1, A2, A3, A4)> {
  typedef A5 Argument5;
  typedef ::testing::tuple<A1, A2, A3, A4, A5> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4, A5);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5);
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6>
struct Function<R(A1, A2, A3, A4, A5, A6)>
    : Function<R(A1, A2, A3, A4, A5)> {
  typedef A6 Argument6;
  typedef ::testing::tuple<A1, A2, A3, A4, A5, A6> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6);
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7>
struct Function<R(A1, A2, A3, A4, A5, A6, A7)>
    : Function<R(A1, A2, A3, A4, A5, A6)> {
  typedef A7 Argument7;
  typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7);
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8>
struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8)>
    : Function<R(A1, A2, A3, A4, A5, A6, A7)> {
  typedef A8 Argument8;
  typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8);
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9>
struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9)>
    : Function<R(A1, A2, A3, A4, A5, A6, A7, A8)> {
  typedef A9 Argument9;
  typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
      A9);
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9,
    typename A10>
struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)>
    : Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9)> {
  typedef A10 Argument10;
  typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
      A10> ArgumentTuple;
  typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
  typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
  typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
      A9, A10);
};

}  // namespace internal

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_GENERATED_INTERNAL_UTILS_H_

namespace testing {
namespace internal {

// Silence MSVC C4100 (unreferenced formal parameter) and
// C4805('==': unsafe mix of type 'const int' and type 'const bool')
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
# pragma warning(disable:4805)
#endif

// Joins a vector of strings as if they are fields of a tuple; returns
// the joined string.
GTEST_API_ std::string JoinAsTuple(const Strings& fields);

// Converts an identifier name to a space-separated list of lower-case
// words.  Each maximum substring of the form [A-Za-z][a-z]*|\d+ is
// treated as one word.  For example, both "FooBar123" and
// "foo_bar_123" are converted to "foo bar 123".
GTEST_API_ std::string ConvertIdentifierNameToWords(const char* id_name);

// PointeeOf<Pointer>::type is the type of a value pointed to by a
// Pointer, which can be either a smart pointer or a raw pointer.  The
// following default implementation is for the case where Pointer is a
// smart pointer.
template <typename Pointer>
struct PointeeOf {
  // Smart pointer classes define type element_type as the type of
  // their pointees.
  typedef typename Pointer::element_type type;
};
// This specialization is for the raw pointer case.
template <typename T>
struct PointeeOf<T*> { typedef T type; };  // NOLINT

// GetRawPointer(p) returns the raw pointer underlying p when p is a
// smart pointer, or returns p itself when p is already a raw pointer.
// The following default implementation is for the smart pointer case.
template <typename Pointer>
inline const typename Pointer::element_type* GetRawPointer(const Pointer& p) {
  return p.get();
}
// This overloaded version is for the raw pointer case.
template <typename Element>
inline Element* GetRawPointer(Element* p) { return p; }

// This comparator allows linked_ptr to be stored in sets.
template <typename T>
struct LinkedPtrLessThan {
  bool operator()(const ::testing::internal::linked_ptr<T>& lhs,
                  const ::testing::internal::linked_ptr<T>& rhs) const {
    return lhs.get() < rhs.get();
  }
};

// Symbian compilation can be done with wchar_t being either a native
// type or a typedef.  Using Google Mock with OpenC without wchar_t
// should require the definition of _STLP_NO_WCHAR_T.
//
// MSVC treats wchar_t as a native type usually, but treats it as the
// same as unsigned short when the compiler option /Zc:wchar_t- is
// specified.  It defines _NATIVE_WCHAR_T_DEFINED symbol when wchar_t
// is a native type.
#if (GTEST_OS_SYMBIAN && defined(_STLP_NO_WCHAR_T)) || \
    (defined(_MSC_VER) && !defined(_NATIVE_WCHAR_T_DEFINED))
// wchar_t is a typedef.
#else
# define GMOCK_WCHAR_T_IS_NATIVE_ 1
#endif

// signed wchar_t and unsigned wchar_t are NOT in the C++ standard.
// Using them is a bad practice and not portable.  So DON'T use them.
//
// Still, Google Mock is designed to work even if the user uses signed
// wchar_t or unsigned wchar_t (obviously, assuming the compiler
// supports them).
//
// To gcc,
//   wchar_t == signed wchar_t != unsigned wchar_t == unsigned int
#ifdef __GNUC__
#if !defined(__WCHAR_UNSIGNED__)
// signed/unsigned wchar_t are valid types.
# define GMOCK_HAS_SIGNED_WCHAR_T_ 1
#endif
#endif

// In what follows, we use the term "kind" to indicate whether a type
// is bool, an integer type (excluding bool), a floating-point type,
// or none of them.  This categorization is useful for determining
// when a matcher argument type can be safely converted to another
// type in the implementation of SafeMatcherCast.
enum TypeKind {
  kBool, kInteger, kFloatingPoint, kOther
};

// KindOf<T>::value is the kind of type T.
template <typename T> struct KindOf {
  enum { value = kOther };  // The default kind.
};

// This macro declares that the kind of 'type' is 'kind'.
#define GMOCK_DECLARE_KIND_(type, kind) \
  template <> struct KindOf<type> { enum { value = kind }; }

GMOCK_DECLARE_KIND_(bool, kBool);

// All standard integer types.
GMOCK_DECLARE_KIND_(char, kInteger);
GMOCK_DECLARE_KIND_(signed char, kInteger);
GMOCK_DECLARE_KIND_(unsigned char, kInteger);
GMOCK_DECLARE_KIND_(short, kInteger);  // NOLINT
GMOCK_DECLARE_KIND_(unsigned short, kInteger);  // NOLINT
GMOCK_DECLARE_KIND_(int, kInteger);
GMOCK_DECLARE_KIND_(unsigned int, kInteger);
GMOCK_DECLARE_KIND_(long, kInteger);  // NOLINT
GMOCK_DECLARE_KIND_(unsigned long, kInteger);  // NOLINT

#if GMOCK_WCHAR_T_IS_NATIVE_
GMOCK_DECLARE_KIND_(wchar_t, kInteger);
#endif

// Non-standard integer types.
GMOCK_DECLARE_KIND_(Int64, kInteger);
GMOCK_DECLARE_KIND_(UInt64, kInteger);

// All standard floating-point types.
GMOCK_DECLARE_KIND_(float, kFloatingPoint);
GMOCK_DECLARE_KIND_(double, kFloatingPoint);
GMOCK_DECLARE_KIND_(long double, kFloatingPoint);

#undef GMOCK_DECLARE_KIND_

// Evaluates to the kind of 'type'.
#define GMOCK_KIND_OF_(type) \
  static_cast< ::testing::internal::TypeKind>( \
      ::testing::internal::KindOf<type>::value)

// Evaluates to true iff integer type T is signed.
#define GMOCK_IS_SIGNED_(T) (static_cast<T>(-1) < 0)

// LosslessArithmeticConvertibleImpl<kFromKind, From, kToKind, To>::value
// is true iff arithmetic type From can be losslessly converted to
// arithmetic type To.
//
// It's the user's responsibility to ensure that both From and To are
// raw (i.e. has no CV modifier, is not a pointer, and is not a
// reference) built-in arithmetic types, kFromKind is the kind of
// From, and kToKind is the kind of To; the value is
// implementation-defined when the above pre-condition is violated.
template <TypeKind kFromKind, typename From, TypeKind kToKind, typename To>
struct LosslessArithmeticConvertibleImpl : public false_type {};

// Converting bool to bool is lossless.
template <>
struct LosslessArithmeticConvertibleImpl<kBool, bool, kBool, bool>
    : public true_type {};  // NOLINT

// Converting bool to any integer type is lossless.
template <typename To>
struct LosslessArithmeticConvertibleImpl<kBool, bool, kInteger, To>
    : public true_type {};  // NOLINT

// Converting bool to any floating-point type is lossless.
template <typename To>
struct LosslessArithmeticConvertibleImpl<kBool, bool, kFloatingPoint, To>
    : public true_type {};  // NOLINT

// Converting an integer to bool is lossy.
template <typename From>
struct LosslessArithmeticConvertibleImpl<kInteger, From, kBool, bool>
    : public false_type {};  // NOLINT

// Converting an integer to another non-bool integer is lossless iff
// the target type's range encloses the source type's range.
template <typename From, typename To>
struct LosslessArithmeticConvertibleImpl<kInteger, From, kInteger, To>
    : public bool_constant<
      // When converting from a smaller size to a larger size, we are
      // fine as long as we are not converting from signed to unsigned.
      ((sizeof(From) < sizeof(To)) &&
       (!GMOCK_IS_SIGNED_(From) || GMOCK_IS_SIGNED_(To))) ||
      // When converting between the same size, the signedness must match.
      ((sizeof(From) == sizeof(To)) &&
       (GMOCK_IS_SIGNED_(From) == GMOCK_IS_SIGNED_(To)))> {};  // NOLINT

#undef GMOCK_IS_SIGNED_

// Converting an integer to a floating-point type may be lossy, since
// the format of a floating-point number is implementation-defined.
template <typename From, typename To>
struct LosslessArithmeticConvertibleImpl<kInteger, From, kFloatingPoint, To>
    : public false_type {};  // NOLINT

// Converting a floating-point to bool is lossy.
template <typename From>
struct LosslessArithmeticConvertibleImpl<kFloatingPoint, From, kBool, bool>
    : public false_type {};  // NOLINT

// Converting a floating-point to an integer is lossy.
template <typename From, typename To>
struct LosslessArithmeticConvertibleImpl<kFloatingPoint, From, kInteger, To>
    : public false_type {};  // NOLINT

// Converting a floating-point to another floating-point is lossless
// iff the target type is at least as big as the source type.
template <typename From, typename To>
struct LosslessArithmeticConvertibleImpl<
  kFloatingPoint, From, kFloatingPoint, To>
    : public bool_constant<sizeof(From) <= sizeof(To)> {};  // NOLINT

// LosslessArithmeticConvertible<From, To>::value is true iff arithmetic
// type From can be losslessly converted to arithmetic type To.
//
// It's the user's responsibility to ensure that both From and To are
// raw (i.e. has no CV modifier, is not a pointer, and is not a
// reference) built-in arithmetic types; the value is
// implementation-defined when the above pre-condition is violated.
template <typename From, typename To>
struct LosslessArithmeticConvertible
    : public LosslessArithmeticConvertibleImpl<
  GMOCK_KIND_OF_(From), From, GMOCK_KIND_OF_(To), To> {};  // NOLINT

// This interface knows how to report a Google Mock failure (either
// non-fatal or fatal).
class FailureReporterInterface {
 public:
  // The type of a failure (either non-fatal or fatal).
  enum FailureType {
    kNonfatal, kFatal
  };

  virtual ~FailureReporterInterface() {}

  // Reports a failure that occurred at the given source file location.
  virtual void ReportFailure(FailureType type, const char* file, int line,
                             const std::string& message) = 0;
};

// Returns the failure reporter used by Google Mock.
GTEST_API_ FailureReporterInterface* GetFailureReporter();

// Asserts that condition is true; aborts the process with the given
// message if condition is false.  We cannot use LOG(FATAL) or CHECK()
// as Google Mock might be used to mock the log sink itself.  We
// inline this function to prevent it from showing up in the stack
// trace.
inline void Assert(bool condition, const char* file, int line,
                   const std::string& msg) {
  if (!condition) {
    GetFailureReporter()->ReportFailure(FailureReporterInterface::kFatal,
                                        file, line, msg);
  }
}
inline void Assert(bool condition, const char* file, int line) {
  Assert(condition, file, line, "Assertion failed.");
}

// Verifies that condition is true; generates a non-fatal failure if
// condition is false.
inline void Expect(bool condition, const char* file, int line,
                   const std::string& msg) {
  if (!condition) {
    GetFailureReporter()->ReportFailure(FailureReporterInterface::kNonfatal,
                                        file, line, msg);
  }
}
inline void Expect(bool condition, const char* file, int line) {
  Expect(condition, file, line, "Expectation failed.");
}

// Severity level of a log.
enum LogSeverity {
  kInfo = 0,
  kWarning = 1
};

// Valid values for the --gmock_verbose flag.

// All logs (informational and warnings) are printed.
const char kInfoVerbosity[] = "info";
// Only warnings are printed.
const char kWarningVerbosity[] = "warning";
// No logs are printed.
const char kErrorVerbosity[] = "error";

// Returns true iff a log with the given severity is visible according
// to the --gmock_verbose flag.
GTEST_API_ bool LogIsVisible(LogSeverity severity);

// Prints the given message to stdout iff 'severity' >= the level
// specified by the --gmock_verbose flag.  If stack_frames_to_skip >=
// 0, also prints the stack trace excluding the top
// stack_frames_to_skip frames.  In opt mode, any positive
// stack_frames_to_skip is treated as 0, since we don't know which
// function calls will be inlined by the compiler and need to be
// conservative.
GTEST_API_ void Log(LogSeverity severity, const std::string& message,
                    int stack_frames_to_skip);

// A marker class that is used to resolve parameterless expectations to the
// correct overload. This must not be instantiable, to prevent client code from
// accidentally resolving to the overload; for example:
//
//    ON_CALL(mock, Method({}, nullptr))...
//
class WithoutMatchers {
 private:
  WithoutMatchers() {}
  friend GTEST_API_ WithoutMatchers GetWithoutMatchers();
};

// Internal use only: access the singleton instance of WithoutMatchers.
GTEST_API_ WithoutMatchers GetWithoutMatchers();

// TODO(wan@google.com): group all type utilities together.

// Type traits.

// is_reference<T>::value is non-zero iff T is a reference type.
template <typename T> struct is_reference : public false_type {};
template <typename T> struct is_reference<T&> : public true_type {};

// type_equals<T1, T2>::value is non-zero iff T1 and T2 are the same type.
template <typename T1, typename T2> struct type_equals : public false_type {};
template <typename T> struct type_equals<T, T> : public true_type {};

// remove_reference<T>::type removes the reference from type T, if any.
template <typename T> struct remove_reference { typedef T type; };  // NOLINT
template <typename T> struct remove_reference<T&> { typedef T type; }; // NOLINT

// DecayArray<T>::type turns an array type U[N] to const U* and preserves
// other types.  Useful for saving a copy of a function argument.
template <typename T> struct DecayArray { typedef T type; };  // NOLINT
template <typename T, size_t N> struct DecayArray<T[N]> {
  typedef const T* type;
};
// Sometimes people use arrays whose size is not available at the use site
// (e.g. extern const char kNamePrefix[]).  This specialization covers that
// case.
template <typename T> struct DecayArray<T[]> {
  typedef const T* type;
};

// Disable MSVC warnings for infinite recursion, since in this case the
// the recursion is unreachable.
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4717)
#endif

// Invalid<T>() is usable as an expression of type T, but will terminate
// the program with an assertion failure if actually run.  This is useful
// when a value of type T is needed for compilation, but the statement
// will not really be executed (or we don't care if the statement
// crashes).
template <typename T>
inline T Invalid() {
  Assert(false, "", -1, "Internal error: attempt to return invalid value");
  // This statement is unreachable, and would never terminate even if it
  // could be reached. It is provided only to placate compiler warnings
  // about missing return statements.
  return Invalid<T>();
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif

// Given a raw type (i.e. having no top-level reference or const
// modifier) RawContainer that's either an STL-style container or a
// native array, class StlContainerView<RawContainer> has the
// following members:
//
//   - type is a type that provides an STL-style container view to
//     (i.e. implements the STL container concept for) RawContainer;
//   - const_reference is a type that provides a reference to a const
//     RawContainer;
//   - ConstReference(raw_container) returns a const reference to an STL-style
//     container view to raw_container, which is a RawContainer.
//   - Copy(raw_container) returns an STL-style container view of a
//     copy of raw_container, which is a RawContainer.
//
// This generic version is used when RawContainer itself is already an
// STL-style container.
template <class RawContainer>
class StlContainerView {
 public:
  typedef RawContainer type;
  typedef const type& const_reference;

  static const_reference ConstReference(const RawContainer& container) {
    // Ensures that RawContainer is not a const type.
    testing::StaticAssertTypeEq<RawContainer,
        GTEST_REMOVE_CONST_(RawContainer)>();
    return container;
  }
  static type Copy(const RawContainer& container) { return container; }
};

// This specialization is used when RawContainer is a native array type.
template <typename Element, size_t N>
class StlContainerView<Element[N]> {
 public:
  typedef GTEST_REMOVE_CONST_(Element) RawElement;
  typedef internal::NativeArray<RawElement> type;
  // NativeArray<T> can represent a native array either by value or by
  // reference (selected by a constructor argument), so 'const type'
  // can be used to reference a const native array.  We cannot
  // 'typedef const type& const_reference' here, as that would mean
  // ConstReference() has to return a reference to a local variable.
  typedef const type const_reference;

  static const_reference ConstReference(const Element (&array)[N]) {
    // Ensures that Element is not a const type.
    testing::StaticAssertTypeEq<Element, RawElement>();
#if GTEST_OS_SYMBIAN
    // The Nokia Symbian compiler confuses itself in template instantiation
    // for this call without the cast to Element*:
    // function call '[testing::internal::NativeArray<char *>].NativeArray(
    //     {lval} const char *[4], long, testing::internal::RelationToSource)'
    //     does not match
    // 'testing::internal::NativeArray<char *>::NativeArray(
    //     char *const *, unsigned int, testing::internal::RelationToSource)'
    // (instantiating: 'testing::internal::ContainsMatcherImpl
    //     <const char * (&)[4]>::Matches(const char * (&)[4]) const')
    // (instantiating: 'testing::internal::StlContainerView<char *[4]>::
    //     ConstReference(const char * (&)[4])')
    // (and though the N parameter type is mismatched in the above explicit
    // conversion of it doesn't help - only the conversion of the array).
    return type(const_cast<Element*>(&array[0]), N,
                RelationToSourceReference());
#else
    return type(array, N, RelationToSourceReference());
#endif  // GTEST_OS_SYMBIAN
  }
  static type Copy(const Element (&array)[N]) {
#if GTEST_OS_SYMBIAN
    return type(const_cast<Element*>(&array[0]), N, RelationToSourceCopy());
#else
    return type(array, N, RelationToSourceCopy());
#endif  // GTEST_OS_SYMBIAN
  }
};

// This specialization is used when RawContainer is a native array
// represented as a (pointer, size) tuple.
template <typename ElementPointer, typename Size>
class StlContainerView< ::testing::tuple<ElementPointer, Size> > {
 public:
  typedef GTEST_REMOVE_CONST_(
      typename internal::PointeeOf<ElementPointer>::type) RawElement;
  typedef internal::NativeArray<RawElement> type;
  typedef const type const_reference;

  static const_reference ConstReference(
      const ::testing::tuple<ElementPointer, Size>& array) {
    return type(get<0>(array), get<1>(array), RelationToSourceReference());
  }
  static type Copy(const ::testing::tuple<ElementPointer, Size>& array) {
    return type(get<0>(array), get<1>(array), RelationToSourceCopy());
  }
};

// The following specialization prevents the user from instantiating
// StlContainer with a reference type.
template <typename T> class StlContainerView<T&>;

// A type transform to remove constness from the first part of a pair.
// Pairs like that are used as the value_type of associative containers,
// and this transform produces a similar but assignable pair.
template <typename T>
struct RemoveConstFromKey {
  typedef T type;
};

// Partially specialized to remove constness from std::pair<const K, V>.
template <typename K, typename V>
struct RemoveConstFromKey<std::pair<const K, V> > {
  typedef std::pair<K, V> type;
};

// Mapping from booleans to types. Similar to boost::bool_<kValue> and
// std::integral_constant<bool, kValue>.
template <bool kValue>
struct BooleanConstant {};

// Emit an assertion failure due to incorrect DoDefault() usage. Out-of-lined to
// reduce code size.
GTEST_API_ void IllegalDoDefault(const char* file, int line);

#if GTEST_LANG_CXX11
// Helper types for Apply() below.
template <size_t... Is> struct int_pack { typedef int_pack type; };

template <class Pack, size_t I> struct append;
template <size_t... Is, size_t I>
struct append<int_pack<Is...>, I> : int_pack<Is..., I> {};

template <size_t C>
struct make_int_pack : append<typename make_int_pack<C - 1>::type, C - 1> {};
template <> struct make_int_pack<0> : int_pack<> {};

template <typename F, typename Tuple, size_t... Idx>
auto ApplyImpl(F&& f, Tuple&& args, int_pack<Idx...>) -> decltype(
    std::forward<F>(f)(std::get<Idx>(std::forward<Tuple>(args))...)) {
  return std::forward<F>(f)(std::get<Idx>(std::forward<Tuple>(args))...);
}

// Apply the function to a tuple of arguments.
template <typename F, typename Tuple>
auto Apply(F&& f, Tuple&& args)
    -> decltype(ApplyImpl(std::forward<F>(f), std::forward<Tuple>(args),
                          make_int_pack<std::tuple_size<Tuple>::value>())) {
  return ApplyImpl(std::forward<F>(f), std::forward<Tuple>(args),
                   make_int_pack<std::tuple_size<Tuple>::value>());
}
#endif


#ifdef _MSC_VER
# pragma warning(pop)
#endif

}  // namespace internal
}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_

#if GTEST_LANG_CXX11  // Defined by gtest-port.h via gmock-port.h.
#include <functional>
#include <type_traits>
#endif  // GTEST_LANG_CXX11

namespace testing {

// To implement an action Foo, define:
//   1. a class FooAction that implements the ActionInterface interface, and
//   2. a factory function that creates an Action object from a
//      const FooAction*.
//
// The two-level delegation design follows that of Matcher, providing
// consistency for extension developers.  It also eases ownership
// management as Action objects can now be copied like plain values.

namespace internal {

template <typename F1, typename F2>
class ActionAdaptor;

// BuiltInDefaultValueGetter<T, true>::Get() returns a
// default-constructed T value.  BuiltInDefaultValueGetter<T,
// false>::Get() crashes with an error.
//
// This primary template is used when kDefaultConstructible is true.
template <typename T, bool kDefaultConstructible>
struct BuiltInDefaultValueGetter {
  static T Get() { return T(); }
};
template <typename T>
struct BuiltInDefaultValueGetter<T, false> {
  static T Get() {
    Assert(false, __FILE__, __LINE__,
           "Default action undefined for the function return type.");
    return internal::Invalid<T>();
    // The above statement will never be reached, but is required in
    // order for this function to compile.
  }
};

// BuiltInDefaultValue<T>::Get() returns the "built-in" default value
// for type T, which is NULL when T is a raw pointer type, 0 when T is
// a numeric type, false when T is bool, or "" when T is string or
// std::string.  In addition, in C++11 and above, it turns a
// default-constructed T value if T is default constructible.  For any
// other type T, the built-in default T value is undefined, and the
// function will abort the process.
template <typename T>
class BuiltInDefaultValue {
 public:
#if GTEST_LANG_CXX11
  // This function returns true iff type T has a built-in default value.
  static bool Exists() {
    return ::std::is_default_constructible<T>::value;
  }

  static T Get() {
    return BuiltInDefaultValueGetter<
        T, ::std::is_default_constructible<T>::value>::Get();
  }

#else  // GTEST_LANG_CXX11
  // This function returns true iff type T has a built-in default value.
  static bool Exists() {
    return false;
  }

  static T Get() {
    return BuiltInDefaultValueGetter<T, false>::Get();
  }

#endif  // GTEST_LANG_CXX11
};

// This partial specialization says that we use the same built-in
// default value for T and const T.
template <typename T>
class BuiltInDefaultValue<const T> {
 public:
  static bool Exists() { return BuiltInDefaultValue<T>::Exists(); }
  static T Get() { return BuiltInDefaultValue<T>::Get(); }
};

// This partial specialization defines the default values for pointer
// types.
template <typename T>
class BuiltInDefaultValue<T*> {
 public:
  static bool Exists() { return true; }
  static T* Get() { return NULL; }
};

// The following specializations define the default values for
// specific types we care about.
#define GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(type, value) \
  template <> \
  class BuiltInDefaultValue<type> { \
   public: \
    static bool Exists() { return true; } \
    static type Get() { return value; } \
  }

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(void, );  // NOLINT
#if GTEST_HAS_GLOBAL_STRING
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(::string, "");
#endif  // GTEST_HAS_GLOBAL_STRING
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(::std::string, "");
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(bool, false);
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned char, '\0');
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed char, '\0');
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(char, '\0');

// There's no need for a default action for signed wchar_t, as that
// type is the same as wchar_t for gcc, and invalid for MSVC.
//
// There's also no need for a default action for unsigned wchar_t, as
// that type is the same as unsigned int for gcc, and invalid for
// MSVC.
#if GMOCK_WCHAR_T_IS_NATIVE_
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(wchar_t, 0U);  // NOLINT
#endif

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned short, 0U);  // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed short, 0);     // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned int, 0U);
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed int, 0);
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned long, 0UL);  // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed long, 0L);     // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(UInt64, 0);
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(Int64, 0);
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(float, 0);
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(double, 0);

#undef GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_

}  // namespace internal

// When an unexpected function call is encountered, Google Mock will
// let it return a default value if the user has specified one for its
// return type, or if the return type has a built-in default value;
// otherwise Google Mock won't know what value to return and will have
// to abort the process.
//
// The DefaultValue<T> class allows a user to specify the
// default value for a type T that is both copyable and publicly
// destructible (i.e. anything that can be used as a function return
// type).  The usage is:
//
//   // Sets the default value for type T to be foo.
//   DefaultValue<T>::Set(foo);
template <typename T>
class DefaultValue {
 public:
  // Sets the default value for type T; requires T to be
  // copy-constructable and have a public destructor.
  static void Set(T x) {
    delete producer_;
    producer_ = new FixedValueProducer(x);
  }

  // Provides a factory function to be called to generate the default value.
  // This method can be used even if T is only move-constructible, but it is not
  // limited to that case.
  typedef T (*FactoryFunction)();
  static void SetFactory(FactoryFunction factory) {
    delete producer_;
    producer_ = new FactoryValueProducer(factory);
  }

  // Unsets the default value for type T.
  static void Clear() {
    delete producer_;
    producer_ = NULL;
  }

  // Returns true iff the user has set the default value for type T.
  static bool IsSet() { return producer_ != NULL; }

  // Returns true if T has a default return value set by the user or there
  // exists a built-in default value.
  static bool Exists() {
    return IsSet() || internal::BuiltInDefaultValue<T>::Exists();
  }

  // Returns the default value for type T if the user has set one;
  // otherwise returns the built-in default value. Requires that Exists()
  // is true, which ensures that the return value is well-defined.
  static T Get() {
    return producer_ == NULL ?
        internal::BuiltInDefaultValue<T>::Get() : producer_->Produce();
  }

 private:
  class ValueProducer {
   public:
    virtual ~ValueProducer() {}
    virtual T Produce() = 0;
  };

  class FixedValueProducer : public ValueProducer {
   public:
    explicit FixedValueProducer(T value) : value_(value) {}
    virtual T Produce() { return value_; }

   private:
    const T value_;
    GTEST_DISALLOW_COPY_AND_ASSIGN_(FixedValueProducer);
  };

  class FactoryValueProducer : public ValueProducer {
   public:
    explicit FactoryValueProducer(FactoryFunction factory)
        : factory_(factory) {}
    virtual T Produce() { return factory_(); }

   private:
    const FactoryFunction factory_;
    GTEST_DISALLOW_COPY_AND_ASSIGN_(FactoryValueProducer);
  };

  static ValueProducer* producer_;
};

// This partial specialization allows a user to set default values for
// reference types.
template <typename T>
class DefaultValue<T&> {
 public:
  // Sets the default value for type T&.
  static void Set(T& x) {  // NOLINT
    address_ = &x;
  }

  // Unsets the default value for type T&.
  static void Clear() {
    address_ = NULL;
  }

  // Returns true iff the user has set the default value for type T&.
  static bool IsSet() { return address_ != NULL; }

  // Returns true if T has a default return value set by the user or there
  // exists a built-in default value.
  static bool Exists() {
    return IsSet() || internal::BuiltInDefaultValue<T&>::Exists();
  }

  // Returns the default value for type T& if the user has set one;
  // otherwise returns the built-in default value if there is one;
  // otherwise aborts the process.
  static T& Get() {
    return address_ == NULL ?
        internal::BuiltInDefaultValue<T&>::Get() : *address_;
  }

 private:
  static T* address_;
};

// This specialization allows DefaultValue<void>::Get() to
// compile.
template <>
class DefaultValue<void> {
 public:
  static bool Exists() { return true; }
  static void Get() {}
};

// Points to the user-set default value for type T.
template <typename T>
typename DefaultValue<T>::ValueProducer* DefaultValue<T>::producer_ = NULL;

// Points to the user-set default value for type T&.
template <typename T>
T* DefaultValue<T&>::address_ = NULL;

// Implement this interface to define an action for function type F.
template <typename F>
class ActionInterface {
 public:
  typedef typename internal::Function<F>::Result Result;
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  ActionInterface() {}
  virtual ~ActionInterface() {}

  // Performs the action.  This method is not const, as in general an
  // action can have side effects and be stateful.  For example, a
  // get-the-next-element-from-the-collection action will need to
  // remember the current element.
  virtual Result Perform(const ArgumentTuple& args) = 0;

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionInterface);
};

// An Action<F> is a copyable and IMMUTABLE (except by assignment)
// object that represents an action to be taken when a mock function
// of type F is called.  The implementation of Action<T> is just a
// linked_ptr to const ActionInterface<T>, so copying is fairly cheap.
// Don't inherit from Action!
//
// You can view an object implementing ActionInterface<F> as a
// concrete action (including its current state), and an Action<F>
// object as a handle to it.
template <typename F>
class Action {
 public:
  typedef typename internal::Function<F>::Result Result;
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  // Constructs a null Action.  Needed for storing Action objects in
  // STL containers.
  Action() {}

#if GTEST_LANG_CXX11
  // Construct an Action from a specified callable.
  // This cannot take std::function directly, because then Action would not be
  // directly constructible from lambda (it would require two conversions).
  template <typename G,
            typename = typename ::std::enable_if<
                ::std::is_constructible<::std::function<F>, G>::value>::type>
  Action(G&& fun) : fun_(::std::forward<G>(fun)) {}  // NOLINT
#endif

  // Constructs an Action from its implementation.
  explicit Action(ActionInterface<F>* impl) : impl_(impl) {}

  // This constructor allows us to turn an Action<Func> object into an
  // Action<F>, as long as F's arguments can be implicitly converted
  // to Func's and Func's return type can be implicitly converted to
  // F's.
  template <typename Func>
  explicit Action(const Action<Func>& action);

  // Returns true iff this is the DoDefault() action.
  bool IsDoDefault() const {
#if GTEST_LANG_CXX11
    return impl_ == nullptr && fun_ == nullptr;
#else
    return impl_ == NULL;
#endif
  }

  // Performs the action.  Note that this method is const even though
  // the corresponding method in ActionInterface is not.  The reason
  // is that a const Action<F> means that it cannot be re-bound to
  // another concrete action, not that the concrete action it binds to
  // cannot change state.  (Think of the difference between a const
  // pointer and a pointer to const.)
  Result Perform(ArgumentTuple args) const {
    if (IsDoDefault()) {
      internal::IllegalDoDefault(__FILE__, __LINE__);
    }
#if GTEST_LANG_CXX11
    if (fun_ != nullptr) {
      return internal::Apply(fun_, ::std::move(args));
    }
#endif
    return impl_->Perform(args);
  }

 private:
  template <typename F1, typename F2>
  friend class internal::ActionAdaptor;

  template <typename G>
  friend class Action;

  // In C++11, Action can be implemented either as a generic functor (through
  // std::function), or legacy ActionInterface. In C++98, only ActionInterface
  // is available. The invariants are as follows:
  // * in C++98, impl_ is null iff this is the default action
  // * in C++11, at most one of fun_ & impl_ may be nonnull; both are null iff
  //   this is the default action
#if GTEST_LANG_CXX11
  ::std::function<F> fun_;
#endif
  internal::linked_ptr<ActionInterface<F> > impl_;
};

// The PolymorphicAction class template makes it easy to implement a
// polymorphic action (i.e. an action that can be used in mock
// functions of than one type, e.g. Return()).
//
// To define a polymorphic action, a user first provides a COPYABLE
// implementation class that has a Perform() method template:
//
//   class FooAction {
//    public:
//     template <typename Result, typename ArgumentTuple>
//     Result Perform(const ArgumentTuple& args) const {
//       // Processes the arguments and returns a result, using
//       // tr1::get<N>(args) to get the N-th (0-based) argument in the tuple.
//     }
//     ...
//   };
//
// Then the user creates the polymorphic action using
// MakePolymorphicAction(object) where object has type FooAction.  See
// the definition of Return(void) and SetArgumentPointee<N>(value) for
// complete examples.
template <typename Impl>
class PolymorphicAction {
 public:
  explicit PolymorphicAction(const Impl& impl) : impl_(impl) {}

  template <typename F>
  operator Action<F>() const {
    return Action<F>(new MonomorphicImpl<F>(impl_));
  }

 private:
  template <typename F>
  class MonomorphicImpl : public ActionInterface<F> {
   public:
    typedef typename internal::Function<F>::Result Result;
    typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

    explicit MonomorphicImpl(const Impl& impl) : impl_(impl) {}

    virtual Result Perform(const ArgumentTuple& args) {
      return impl_.template Perform<Result>(args);
    }

   private:
    Impl impl_;

    GTEST_DISALLOW_ASSIGN_(MonomorphicImpl);
  };

  Impl impl_;

  GTEST_DISALLOW_ASSIGN_(PolymorphicAction);
};

// Creates an Action from its implementation and returns it.  The
// created Action object owns the implementation.
template <typename F>
Action<F> MakeAction(ActionInterface<F>* impl) {
  return Action<F>(impl);
}

// Creates a polymorphic action from its implementation.  This is
// easier to use than the PolymorphicAction<Impl> constructor as it
// doesn't require you to explicitly write the template argument, e.g.
//
//   MakePolymorphicAction(foo);
// vs
//   PolymorphicAction<TypeOfFoo>(foo);
template <typename Impl>
inline PolymorphicAction<Impl> MakePolymorphicAction(const Impl& impl) {
  return PolymorphicAction<Impl>(impl);
}

namespace internal {

// Allows an Action<F2> object to pose as an Action<F1>, as long as F2
// and F1 are compatible.
template <typename F1, typename F2>
class ActionAdaptor : public ActionInterface<F1> {
 public:
  typedef typename internal::Function<F1>::Result Result;
  typedef typename internal::Function<F1>::ArgumentTuple ArgumentTuple;

  explicit ActionAdaptor(const Action<F2>& from) : impl_(from.impl_) {}

  virtual Result Perform(const ArgumentTuple& args) {
    return impl_->Perform(args);
  }

 private:
  const internal::linked_ptr<ActionInterface<F2> > impl_;

  GTEST_DISALLOW_ASSIGN_(ActionAdaptor);
};

// Helper struct to specialize ReturnAction to execute a move instead of a copy
// on return. Useful for move-only types, but could be used on any type.
template <typename T>
struct ByMoveWrapper {
  explicit ByMoveWrapper(T value) : payload(internal::move(value)) {}
  T payload;
};

// Implements the polymorphic Return(x) action, which can be used in
// any function that returns the type of x, regardless of the argument
// types.
//
// Note: The value passed into Return must be converted into
// Function<F>::Result when this action is cast to Action<F> rather than
// when that action is performed. This is important in scenarios like
//
// MOCK_METHOD1(Method, T(U));
// ...
// {
//   Foo foo;
//   X x(&foo);
//   EXPECT_CALL(mock, Method(_)).WillOnce(Return(x));
// }
//
// In the example above the variable x holds reference to foo which leaves
// scope and gets destroyed.  If copying X just copies a reference to foo,
// that copy will be left with a hanging reference.  If conversion to T
// makes a copy of foo, the above code is safe. To support that scenario, we
// need to make sure that the type conversion happens inside the EXPECT_CALL
// statement, and conversion of the result of Return to Action<T(U)> is a
// good place for that.
//
// The real life example of the above scenario happens when an invocation
// of gtl::Container() is passed into Return.
//
template <typename R>
class ReturnAction {
 public:
  // Constructs a ReturnAction object from the value to be returned.
  // 'value' is passed by value instead of by const reference in order
  // to allow Return("string literal") to compile.
  explicit ReturnAction(R value) : value_(new R(internal::move(value))) {}

  // This template type conversion operator allows Return(x) to be
  // used in ANY function that returns x's type.
  template <typename F>
  operator Action<F>() const {
    // Assert statement belongs here because this is the best place to verify
    // conditions on F. It produces the clearest error messages
    // in most compilers.
    // Impl really belongs in this scope as a local class but can't
    // because MSVC produces duplicate symbols in different translation units
    // in this case. Until MS fixes that bug we put Impl into the class scope
    // and put the typedef both here (for use in assert statement) and
    // in the Impl class. But both definitions must be the same.
    typedef typename Function<F>::Result Result;
    GTEST_COMPILE_ASSERT_(
        !is_reference<Result>::value,
        use_ReturnRef_instead_of_Return_to_return_a_reference);
    return Action<F>(new Impl<R, F>(value_));
  }

 private:
  // Implements the Return(x) action for a particular function type F.
  template <typename R_, typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;

    // The implicit cast is necessary when Result has more than one
    // single-argument constructor (e.g. Result is std::vector<int>) and R
    // has a type conversion operator template.  In that case, value_(value)
    // won't compile as the compiler doesn't known which constructor of
    // Result to call.  ImplicitCast_ forces the compiler to convert R to
    // Result without considering explicit constructors, thus resolving the
    // ambiguity. value_ is then initialized using its copy constructor.
    explicit Impl(const linked_ptr<R>& value)
        : value_before_cast_(*value),
          value_(ImplicitCast_<Result>(value_before_cast_)) {}

    virtual Result Perform(const ArgumentTuple&) { return value_; }

   private:
    GTEST_COMPILE_ASSERT_(!is_reference<Result>::value,
                          Result_cannot_be_a_reference_type);
    // We save the value before casting just in case it is being cast to a
    // wrapper type.
    R value_before_cast_;
    Result value_;

    GTEST_DISALLOW_COPY_AND_ASSIGN_(Impl);
  };

  // Partially specialize for ByMoveWrapper. This version of ReturnAction will
  // move its contents instead.
  template <typename R_, typename F>
  class Impl<ByMoveWrapper<R_>, F> : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;

    explicit Impl(const linked_ptr<R>& wrapper)
        : performed_(false), wrapper_(wrapper) {}

    virtual Result Perform(const ArgumentTuple&) {
      GTEST_CHECK_(!performed_)
          << "A ByMove() action should only be performed once.";
      performed_ = true;
      return internal::move(wrapper_->payload);
    }

   private:
    bool performed_;
    const linked_ptr<R> wrapper_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  const linked_ptr<R> value_;

  GTEST_DISALLOW_ASSIGN_(ReturnAction);
};

// Implements the ReturnNull() action.
class ReturnNullAction {
 public:
  // Allows ReturnNull() to be used in any pointer-returning function. In C++11
  // this is enforced by returning nullptr, and in non-C++11 by asserting a
  // pointer type on compile time.
  template <typename Result, typename ArgumentTuple>
  static Result Perform(const ArgumentTuple&) {
#if GTEST_LANG_CXX11
    return nullptr;
#else
    GTEST_COMPILE_ASSERT_(internal::is_pointer<Result>::value,
                          ReturnNull_can_be_used_to_return_a_pointer_only);
    return NULL;
#endif  // GTEST_LANG_CXX11
  }
};

// Implements the Return() action.
class ReturnVoidAction {
 public:
  // Allows Return() to be used in any void-returning function.
  template <typename Result, typename ArgumentTuple>
  static void Perform(const ArgumentTuple&) {
    CompileAssertTypesEqual<void, Result>();
  }
};

// Implements the polymorphic ReturnRef(x) action, which can be used
// in any function that returns a reference to the type of x,
// regardless of the argument types.
template <typename T>
class ReturnRefAction {
 public:
  // Constructs a ReturnRefAction object from the reference to be returned.
  explicit ReturnRefAction(T& ref) : ref_(ref) {}  // NOLINT

  // This template type conversion operator allows ReturnRef(x) to be
  // used in ANY function that returns a reference to x's type.
  template <typename F>
  operator Action<F>() const {
    typedef typename Function<F>::Result Result;
    // Asserts that the function return type is a reference.  This
    // catches the user error of using ReturnRef(x) when Return(x)
    // should be used, and generates some helpful error message.
    GTEST_COMPILE_ASSERT_(internal::is_reference<Result>::value,
                          use_Return_instead_of_ReturnRef_to_return_a_value);
    return Action<F>(new Impl<F>(ref_));
  }

 private:
  // Implements the ReturnRef(x) action for a particular function type F.
  template <typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;

    explicit Impl(T& ref) : ref_(ref) {}  // NOLINT

    virtual Result Perform(const ArgumentTuple&) {
      return ref_;
    }

   private:
    T& ref_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  T& ref_;

  GTEST_DISALLOW_ASSIGN_(ReturnRefAction);
};

// Implements the polymorphic ReturnRefOfCopy(x) action, which can be
// used in any function that returns a reference to the type of x,
// regardless of the argument types.
template <typename T>
class ReturnRefOfCopyAction {
 public:
  // Constructs a ReturnRefOfCopyAction object from the reference to
  // be returned.
  explicit ReturnRefOfCopyAction(const T& value) : value_(value) {}  // NOLINT

  // This template type conversion operator allows ReturnRefOfCopy(x) to be
  // used in ANY function that returns a reference to x's type.
  template <typename F>
  operator Action<F>() const {
    typedef typename Function<F>::Result Result;
    // Asserts that the function return type is a reference.  This
    // catches the user error of using ReturnRefOfCopy(x) when Return(x)
    // should be used, and generates some helpful error message.
    GTEST_COMPILE_ASSERT_(
        internal::is_reference<Result>::value,
        use_Return_instead_of_ReturnRefOfCopy_to_return_a_value);
    return Action<F>(new Impl<F>(value_));
  }

 private:
  // Implements the ReturnRefOfCopy(x) action for a particular function type F.
  template <typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;

    explicit Impl(const T& value) : value_(value) {}  // NOLINT

    virtual Result Perform(const ArgumentTuple&) {
      return value_;
    }

   private:
    T value_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  const T value_;

  GTEST_DISALLOW_ASSIGN_(ReturnRefOfCopyAction);
};

// Implements the polymorphic DoDefault() action.
class DoDefaultAction {
 public:
  // This template type conversion operator allows DoDefault() to be
  // used in any function.
  template <typename F>
  operator Action<F>() const { return Action<F>(); }  // NOLINT
};

// Implements the Assign action to set a given pointer referent to a
// particular value.
template <typename T1, typename T2>
class AssignAction {
 public:
  AssignAction(T1* ptr, T2 value) : ptr_(ptr), value_(value) {}

  template <typename Result, typename ArgumentTuple>
  void Perform(const ArgumentTuple& /* args */) const {
    *ptr_ = value_;
  }

 private:
  T1* const ptr_;
  const T2 value_;

  GTEST_DISALLOW_ASSIGN_(AssignAction);
};

#if !GTEST_OS_WINDOWS_MOBILE

// Implements the SetErrnoAndReturn action to simulate return from
// various system calls and libc functions.
template <typename T>
class SetErrnoAndReturnAction {
 public:
  SetErrnoAndReturnAction(int errno_value, T result)
      : errno_(errno_value),
        result_(result) {}
  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple& /* args */) const {
    errno = errno_;
    return result_;
  }

 private:
  const int errno_;
  const T result_;

  GTEST_DISALLOW_ASSIGN_(SetErrnoAndReturnAction);
};

#endif  // !GTEST_OS_WINDOWS_MOBILE

// Implements the SetArgumentPointee<N>(x) action for any function
// whose N-th argument (0-based) is a pointer to x's type.  The
// template parameter kIsProto is true iff type A is ProtocolMessage,
// proto2::Message, or a sub-class of those.
template <size_t N, typename A, bool kIsProto>
class SetArgumentPointeeAction {
 public:
  // Constructs an action that sets the variable pointed to by the
  // N-th function argument to 'value'.
  explicit SetArgumentPointeeAction(const A& value) : value_(value) {}

  template <typename Result, typename ArgumentTuple>
  void Perform(const ArgumentTuple& args) const {
    CompileAssertTypesEqual<void, Result>();
    *::testing::get<N>(args) = value_;
  }

 private:
  const A value_;

  GTEST_DISALLOW_ASSIGN_(SetArgumentPointeeAction);
};

template <size_t N, typename Proto>
class SetArgumentPointeeAction<N, Proto, true> {
 public:
  // Constructs an action that sets the variable pointed to by the
  // N-th function argument to 'proto'.  Both ProtocolMessage and
  // proto2::Message have the CopyFrom() method, so the same
  // implementation works for both.
  explicit SetArgumentPointeeAction(const Proto& proto) : proto_(new Proto) {
    proto_->CopyFrom(proto);
  }

  template <typename Result, typename ArgumentTuple>
  void Perform(const ArgumentTuple& args) const {
    CompileAssertTypesEqual<void, Result>();
    ::testing::get<N>(args)->CopyFrom(*proto_);
  }

 private:
  const internal::linked_ptr<Proto> proto_;

  GTEST_DISALLOW_ASSIGN_(SetArgumentPointeeAction);
};

// Implements the InvokeWithoutArgs(f) action.  The template argument
// FunctionImpl is the implementation type of f, which can be either a
// function pointer or a functor.  InvokeWithoutArgs(f) can be used as an
// Action<F> as long as f's type is compatible with F (i.e. f can be
// assigned to a tr1::function<F>).
template <typename FunctionImpl>
class InvokeWithoutArgsAction {
 public:
  // The c'tor makes a copy of function_impl (either a function
  // pointer or a functor).
  explicit InvokeWithoutArgsAction(FunctionImpl function_impl)
      : function_impl_(function_impl) {}

  // Allows InvokeWithoutArgs(f) to be used as any action whose type is
  // compatible with f.
  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple&) { return function_impl_(); }

 private:
  FunctionImpl function_impl_;

  GTEST_DISALLOW_ASSIGN_(InvokeWithoutArgsAction);
};

// Implements the InvokeWithoutArgs(object_ptr, &Class::Method) action.
template <class Class, typename MethodPtr>
class InvokeMethodWithoutArgsAction {
 public:
  InvokeMethodWithoutArgsAction(Class* obj_ptr, MethodPtr method_ptr)
      : obj_ptr_(obj_ptr), method_ptr_(method_ptr) {}

  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple&) const {
    return (obj_ptr_->*method_ptr_)();
  }

 private:
  Class* const obj_ptr_;
  const MethodPtr method_ptr_;

  GTEST_DISALLOW_ASSIGN_(InvokeMethodWithoutArgsAction);
};

// Implements the InvokeWithoutArgs(callback) action.
template <typename CallbackType>
class InvokeCallbackWithoutArgsAction {
 public:
  // The c'tor takes ownership of the callback.
  explicit InvokeCallbackWithoutArgsAction(CallbackType* callback)
      : callback_(callback) {
    callback->CheckIsRepeatable();  // Makes sure the callback is permanent.
  }

  // This type conversion operator template allows Invoke(callback) to
  // be used wherever the callback's return type can be implicitly
  // converted to that of the mock function.
  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple&) const { return callback_->Run(); }

 private:
  const internal::linked_ptr<CallbackType> callback_;

  GTEST_DISALLOW_ASSIGN_(InvokeCallbackWithoutArgsAction);
};

// Implements the IgnoreResult(action) action.
template <typename A>
class IgnoreResultAction {
 public:
  explicit IgnoreResultAction(const A& action) : action_(action) {}

  template <typename F>
  operator Action<F>() const {
    // Assert statement belongs here because this is the best place to verify
    // conditions on F. It produces the clearest error messages
    // in most compilers.
    // Impl really belongs in this scope as a local class but can't
    // because MSVC produces duplicate symbols in different translation units
    // in this case. Until MS fixes that bug we put Impl into the class scope
    // and put the typedef both here (for use in assert statement) and
    // in the Impl class. But both definitions must be the same.
    typedef typename internal::Function<F>::Result Result;

    // Asserts at compile time that F returns void.
    CompileAssertTypesEqual<void, Result>();

    return Action<F>(new Impl<F>(action_));
  }

 private:
  template <typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename internal::Function<F>::Result Result;
    typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

    explicit Impl(const A& action) : action_(action) {}

    virtual void Perform(const ArgumentTuple& args) {
      // Performs the action and ignores its result.
      action_.Perform(args);
    }

   private:
    // Type OriginalFunction is the same as F except that its return
    // type is IgnoredValue.
    typedef typename internal::Function<F>::MakeResultIgnoredValue
        OriginalFunction;

    const Action<OriginalFunction> action_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  const A action_;

  GTEST_DISALLOW_ASSIGN_(IgnoreResultAction);
};

// A ReferenceWrapper<T> object represents a reference to type T,
// which can be either const or not.  It can be explicitly converted
// from, and implicitly converted to, a T&.  Unlike a reference,
// ReferenceWrapper<T> can be copied and can survive template type
// inference.  This is used to support by-reference arguments in the
// InvokeArgument<N>(...) action.  The idea was from "reference
// wrappers" in tr1, which we don't have in our source tree yet.
template <typename T>
class ReferenceWrapper {
 public:
  // Constructs a ReferenceWrapper<T> object from a T&.
  explicit ReferenceWrapper(T& l_value) : pointer_(&l_value) {}  // NOLINT

  // Allows a ReferenceWrapper<T> object to be implicitly converted to
  // a T&.
  operator T&() const { return *pointer_; }
 private:
  T* pointer_;
};

// Allows the expression ByRef(x) to be printed as a reference to x.
template <typename T>
void PrintTo(const ReferenceWrapper<T>& ref, ::std::ostream* os) {
  T& value = ref;
  UniversalPrinter<T&>::Print(value, os);
}

// Does two actions sequentially.  Used for implementing the DoAll(a1,
// a2, ...) action.
template <typename Action1, typename Action2>
class DoBothAction {
 public:
  DoBothAction(Action1 action1, Action2 action2)
      : action1_(action1), action2_(action2) {}

  // This template type conversion operator allows DoAll(a1, ..., a_n)
  // to be used in ANY function of compatible type.
  template <typename F>
  operator Action<F>() const {
    return Action<F>(new Impl<F>(action1_, action2_));
  }

 private:
  // Implements the DoAll(...) action for a particular function type F.
  template <typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;
    typedef typename Function<F>::MakeResultVoid VoidResult;

    Impl(const Action<VoidResult>& action1, const Action<F>& action2)
        : action1_(action1), action2_(action2) {}

    virtual Result Perform(const ArgumentTuple& args) {
      action1_.Perform(args);
      return action2_.Perform(args);
    }

   private:
    const Action<VoidResult> action1_;
    const Action<F> action2_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  Action1 action1_;
  Action2 action2_;

  GTEST_DISALLOW_ASSIGN_(DoBothAction);
};

}  // namespace internal

// An Unused object can be implicitly constructed from ANY value.
// This is handy when defining actions that ignore some or all of the
// mock function arguments.  For example, given
//
//   MOCK_METHOD3(Foo, double(const string& label, double x, double y));
//   MOCK_METHOD3(Bar, double(int index, double x, double y));
//
// instead of
//
//   double DistanceToOriginWithLabel(const string& label, double x, double y) {
//     return sqrt(x*x + y*y);
//   }
//   double DistanceToOriginWithIndex(int index, double x, double y) {
//     return sqrt(x*x + y*y);
//   }
//   ...
//   EXPECT_CALL(mock, Foo("abc", _, _))
//       .WillOnce(Invoke(DistanceToOriginWithLabel));
//   EXPECT_CALL(mock, Bar(5, _, _))
//       .WillOnce(Invoke(DistanceToOriginWithIndex));
//
// you could write
//
//   // We can declare any uninteresting argument as Unused.
//   double DistanceToOrigin(Unused, double x, double y) {
//     return sqrt(x*x + y*y);
//   }
//   ...
//   EXPECT_CALL(mock, Foo("abc", _, _)).WillOnce(Invoke(DistanceToOrigin));
//   EXPECT_CALL(mock, Bar(5, _, _)).WillOnce(Invoke(DistanceToOrigin));
typedef internal::IgnoredValue Unused;

// This constructor allows us to turn an Action<From> object into an
// Action<To>, as long as To's arguments can be implicitly converted
// to From's and From's return type cann be implicitly converted to
// To's.
template <typename To>
template <typename From>
Action<To>::Action(const Action<From>& from)
    :
#if GTEST_LANG_CXX11
      fun_(from.fun_),
#endif
      impl_(from.impl_ == NULL ? NULL
                               : new internal::ActionAdaptor<To, From>(from)) {
}

// Creates an action that returns 'value'.  'value' is passed by value
// instead of const reference - otherwise Return("string literal")
// will trigger a compiler error about using array as initializer.
template <typename R>
internal::ReturnAction<R> Return(R value) {
  return internal::ReturnAction<R>(internal::move(value));
}

// Creates an action that returns NULL.
inline PolymorphicAction<internal::ReturnNullAction> ReturnNull() {
  return MakePolymorphicAction(internal::ReturnNullAction());
}

// Creates an action that returns from a void function.
inline PolymorphicAction<internal::ReturnVoidAction> Return() {
  return MakePolymorphicAction(internal::ReturnVoidAction());
}

// Creates an action that returns the reference to a variable.
template <typename R>
inline internal::ReturnRefAction<R> ReturnRef(R& x) {  // NOLINT
  return internal::ReturnRefAction<R>(x);
}

// Creates an action that returns the reference to a copy of the
// argument.  The copy is created when the action is constructed and
// lives as long as the action.
template <typename R>
inline internal::ReturnRefOfCopyAction<R> ReturnRefOfCopy(const R& x) {
  return internal::ReturnRefOfCopyAction<R>(x);
}

// Modifies the parent action (a Return() action) to perform a move of the
// argument instead of a copy.
// Return(ByMove()) actions can only be executed once and will assert this
// invariant.
template <typename R>
internal::ByMoveWrapper<R> ByMove(R x) {
  return internal::ByMoveWrapper<R>(internal::move(x));
}

// Creates an action that does the default action for the give mock function.
inline internal::DoDefaultAction DoDefault() {
  return internal::DoDefaultAction();
}

// Creates an action that sets the variable pointed by the N-th
// (0-based) function argument to 'value'.
template <size_t N, typename T>
PolymorphicAction<
  internal::SetArgumentPointeeAction<
    N, T, internal::IsAProtocolMessage<T>::value> >
SetArgPointee(const T& x) {
  return MakePolymorphicAction(internal::SetArgumentPointeeAction<
      N, T, internal::IsAProtocolMessage<T>::value>(x));
}

#if !((GTEST_GCC_VER_ && GTEST_GCC_VER_ < 40000) || GTEST_OS_SYMBIAN)
// This overload allows SetArgPointee() to accept a string literal.
// GCC prior to the version 4.0 and Symbian C++ compiler cannot distinguish
// this overload from the templated version and emit a compile error.
template <size_t N>
PolymorphicAction<
  internal::SetArgumentPointeeAction<N, const char*, false> >
SetArgPointee(const char* p) {
  return MakePolymorphicAction(internal::SetArgumentPointeeAction<
      N, const char*, false>(p));
}

template <size_t N>
PolymorphicAction<
  internal::SetArgumentPointeeAction<N, const wchar_t*, false> >
SetArgPointee(const wchar_t* p) {
  return MakePolymorphicAction(internal::SetArgumentPointeeAction<
      N, const wchar_t*, false>(p));
}
#endif

// The following version is DEPRECATED.
template <size_t N, typename T>
PolymorphicAction<
  internal::SetArgumentPointeeAction<
    N, T, internal::IsAProtocolMessage<T>::value> >
SetArgumentPointee(const T& x) {
  return MakePolymorphicAction(internal::SetArgumentPointeeAction<
      N, T, internal::IsAProtocolMessage<T>::value>(x));
}

// Creates an action that sets a pointer referent to a given value.
template <typename T1, typename T2>
PolymorphicAction<internal::AssignAction<T1, T2> > Assign(T1* ptr, T2 val) {
  return MakePolymorphicAction(internal::AssignAction<T1, T2>(ptr, val));
}

#if !GTEST_OS_WINDOWS_MOBILE

// Creates an action that sets errno and returns the appropriate error.
template <typename T>
PolymorphicAction<internal::SetErrnoAndReturnAction<T> >
SetErrnoAndReturn(int errval, T result) {
  return MakePolymorphicAction(
      internal::SetErrnoAndReturnAction<T>(errval, result));
}

#endif  // !GTEST_OS_WINDOWS_MOBILE

// Various overloads for InvokeWithoutArgs().

// Creates an action that invokes 'function_impl' with no argument.
template <typename FunctionImpl>
PolymorphicAction<internal::InvokeWithoutArgsAction<FunctionImpl> >
InvokeWithoutArgs(FunctionImpl function_impl) {
  return MakePolymorphicAction(
      internal::InvokeWithoutArgsAction<FunctionImpl>(function_impl));
}

// Creates an action that invokes the given method on the given object
// with no argument.
template <class Class, typename MethodPtr>
PolymorphicAction<internal::InvokeMethodWithoutArgsAction<Class, MethodPtr> >
InvokeWithoutArgs(Class* obj_ptr, MethodPtr method_ptr) {
  return MakePolymorphicAction(
      internal::InvokeMethodWithoutArgsAction<Class, MethodPtr>(
          obj_ptr, method_ptr));
}

// Creates an action that performs an_action and throws away its
// result.  In other words, it changes the return type of an_action to
// void.  an_action MUST NOT return void, or the code won't compile.
template <typename A>
inline internal::IgnoreResultAction<A> IgnoreResult(const A& an_action) {
  return internal::IgnoreResultAction<A>(an_action);
}

// Creates a reference wrapper for the given L-value.  If necessary,
// you can explicitly specify the type of the reference.  For example,
// suppose 'derived' is an object of type Derived, ByRef(derived)
// would wrap a Derived&.  If you want to wrap a const Base& instead,
// where Base is a base class of Derived, just write:
//
//   ByRef<const Base>(derived)
template <typename T>
inline internal::ReferenceWrapper<T> ByRef(T& l_value) {  // NOLINT
  return internal::ReferenceWrapper<T>(l_value);
}

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some commonly used cardinalities.  More
// cardinalities can be defined by the user implementing the
// CardinalityInterface interface if necessary.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_CARDINALITIES_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_CARDINALITIES_H_

#include <limits.h>
#include <ostream>  // NOLINT

namespace testing {

// To implement a cardinality Foo, define:
//   1. a class FooCardinality that implements the
//      CardinalityInterface interface, and
//   2. a factory function that creates a Cardinality object from a
//      const FooCardinality*.
//
// The two-level delegation design follows that of Matcher, providing
// consistency for extension developers.  It also eases ownership
// management as Cardinality objects can now be copied like plain values.

// The implementation of a cardinality.
class CardinalityInterface {
 public:
  virtual ~CardinalityInterface() {}

  // Conservative estimate on the lower/upper bound of the number of
  // calls allowed.
  virtual int ConservativeLowerBound() const { return 0; }
  virtual int ConservativeUpperBound() const { return INT_MAX; }

  // Returns true iff call_count calls will satisfy this cardinality.
  virtual bool IsSatisfiedByCallCount(int call_count) const = 0;

  // Returns true iff call_count calls will saturate this cardinality.
  virtual bool IsSaturatedByCallCount(int call_count) const = 0;

  // Describes self to an ostream.
  virtual void DescribeTo(::std::ostream* os) const = 0;
};

// A Cardinality is a copyable and IMMUTABLE (except by assignment)
// object that specifies how many times a mock function is expected to
// be called.  The implementation of Cardinality is just a linked_ptr
// to const CardinalityInterface, so copying is fairly cheap.
// Don't inherit from Cardinality!
class GTEST_API_ Cardinality {
 public:
  // Constructs a null cardinality.  Needed for storing Cardinality
  // objects in STL containers.
  Cardinality() {}

  // Constructs a Cardinality from its implementation.
  explicit Cardinality(const CardinalityInterface* impl) : impl_(impl) {}

  // Conservative estimate on the lower/upper bound of the number of
  // calls allowed.
  int ConservativeLowerBound() const { return impl_->ConservativeLowerBound(); }
  int ConservativeUpperBound() const { return impl_->ConservativeUpperBound(); }

  // Returns true iff call_count calls will satisfy this cardinality.
  bool IsSatisfiedByCallCount(int call_count) const {
    return impl_->IsSatisfiedByCallCount(call_count);
  }

  // Returns true iff call_count calls will saturate this cardinality.
  bool IsSaturatedByCallCount(int call_count) const {
    return impl_->IsSaturatedByCallCount(call_count);
  }

  // Returns true iff call_count calls will over-saturate this
  // cardinality, i.e. exceed the maximum number of allowed calls.
  bool IsOverSaturatedByCallCount(int call_count) const {
    return impl_->IsSaturatedByCallCount(call_count) &&
        !impl_->IsSatisfiedByCallCount(call_count);
  }

  // Describes self to an ostream
  void DescribeTo(::std::ostream* os) const { impl_->DescribeTo(os); }

  // Describes the given actual call count to an ostream.
  static void DescribeActualCallCountTo(int actual_call_count,
                                        ::std::ostream* os);

 private:
  internal::linked_ptr<const CardinalityInterface> impl_;
};

// Creates a cardinality that allows at least n calls.
GTEST_API_ Cardinality AtLeast(int n);

// Creates a cardinality that allows at most n calls.
GTEST_API_ Cardinality AtMost(int n);

// Creates a cardinality that allows any number of calls.
GTEST_API_ Cardinality AnyNumber();

// Creates a cardinality that allows between min and max calls.
GTEST_API_ Cardinality Between(int min, int max);

// Creates a cardinality that allows exactly n calls.
GTEST_API_ Cardinality Exactly(int n);

// Creates a cardinality from its implementation.
inline Cardinality MakeCardinality(const CardinalityInterface* c) {
  return Cardinality(c);
}

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_CARDINALITIES_H_
// This file was GENERATED by command:
//     pump.py gmock-generated-actions.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some commonly used variadic actions.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_ACTIONS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_ACTIONS_H_


namespace testing {
namespace internal {

// InvokeHelper<F> knows how to unpack an N-tuple and invoke an N-ary
// function, method, or callback with the unpacked values, where F is
// a function type that takes N arguments.
template <typename Result, typename ArgumentTuple>
class InvokeHelper;

template <typename R>
class InvokeHelper<R, ::testing::tuple<> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<>&) {
           return function();
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<>&) {
           return (obj_ptr->*method_ptr)();
  }

  template <typename CallbackType>
  static R InvokeCallback(CallbackType* callback,
                          const ::testing::tuple<>&) {
           return callback->Run();
  }
};

template <typename R, typename A1>
class InvokeHelper<R, ::testing::tuple<A1> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1>& args) {
           return function(get<0>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args));
  }

  template <typename CallbackType>
  static R InvokeCallback(CallbackType* callback,
                          const ::testing::tuple<A1>& args) {
           return callback->Run(get<0>(args));
  }
};

template <typename R, typename A1, typename A2>
class InvokeHelper<R, ::testing::tuple<A1, A2> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2>& args) {
           return function(get<0>(args), get<1>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args));
  }

  template <typename CallbackType>
  static R InvokeCallback(CallbackType* callback,
                          const ::testing::tuple<A1, A2>& args) {
           return callback->Run(get<0>(args), get<1>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args));
  }

  template <typename CallbackType>
  static R InvokeCallback(CallbackType* callback,
                          const ::testing::tuple<A1, A2, A3>& args) {
           return callback->Run(get<0>(args), get<1>(args), get<2>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3,
      A4>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args));
  }

  template <typename CallbackType>
  static R InvokeCallback(CallbackType* callback,
                          const ::testing::tuple<A1, A2, A3, A4>& args) {
           return callback->Run(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4,
      A5>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args));
  }

  template <typename CallbackType>
  static R InvokeCallback(CallbackType* callback,
                          const ::testing::tuple<A1, A2, A3, A4, A5>& args) {
           return callback->Run(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args));
  }

  // There is no InvokeCallback() for 6-tuples, as google3 callbacks
  // support 5 arguments at most.
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6,
                            A7>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args));
  }

  // There is no InvokeCallback() for 7-tuples, as google3 callbacks
  // support 5 arguments at most.
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7, A8>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args),
               get<7>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6, A7,
                            A8>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args), get<7>(args));
  }

  // There is no InvokeCallback() for 8-tuples, as google3 callbacks
  // support 5 arguments at most.
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7, A8, A9>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args),
               get<7>(args), get<8>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8,
                            A9>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args), get<7>(args), get<8>(args));
  }

  // There is no InvokeCallback() for 9-tuples, as google3 callbacks
  // support 5 arguments at most.
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9,
    typename A10>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
    A10> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7, A8, A9, A10>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args),
               get<7>(args), get<8>(args), get<9>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8,
                            A9, A10>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args), get<7>(args), get<8>(args), get<9>(args));
  }

  // There is no InvokeCallback() for 10-tuples, as google3 callbacks
  // support 5 arguments at most.
};

// Implements the Invoke(callback) action.
template <typename CallbackType>
class InvokeCallbackAction {
 public:
  // The c'tor takes ownership of the callback.
  explicit InvokeCallbackAction(CallbackType* callback)
      : callback_(callback) {
    callback->CheckIsRepeatable();  // Makes sure the callback is permanent.
  }

  // This type conversion operator template allows Invoke(callback) to
  // be used wherever the callback's type is compatible with that of
  // the mock function, i.e. if the mock function's arguments can be
  // implicitly converted to the callback's arguments and the
  // callback's result can be implicitly converted to the mock
  // function's result.
  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple& args) const {
    return InvokeHelper<Result, ArgumentTuple>::InvokeCallback(
        callback_.get(), args);
  }
 private:
  const linked_ptr<CallbackType> callback_;
};

// An INTERNAL macro for extracting the type of a tuple field.  It's
// subject to change without notice - DO NOT USE IN USER CODE!
#define GMOCK_FIELD_(Tuple, N) \
    typename ::testing::tuple_element<N, Tuple>::type

// SelectArgs<Result, ArgumentTuple, k1, k2, ..., k_n>::type is the
// type of an n-ary function whose i-th (1-based) argument type is the
// k{i}-th (0-based) field of ArgumentTuple, which must be a tuple
// type, and whose return type is Result.  For example,
//   SelectArgs<int, ::testing::tuple<bool, char, double, long>, 0, 3>::type
// is int(bool, long).
//
// SelectArgs<Result, ArgumentTuple, k1, k2, ..., k_n>::Select(args)
// returns the selected fields (k1, k2, ..., k_n) of args as a tuple.
// For example,
//   SelectArgs<int, tuple<bool, char, double>, 2, 0>::Select(
//       ::testing::make_tuple(true, 'a', 2.5))
// returns tuple (2.5, true).
//
// The numbers in list k1, k2, ..., k_n must be >= 0, where n can be
// in the range [0, 10].  Duplicates are allowed and they don't have
// to be in an ascending or descending order.

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7, int k8, int k9, int k10>
class SelectArgs {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7),
      GMOCK_FIELD_(ArgumentTuple, k8), GMOCK_FIELD_(ArgumentTuple, k9),
      GMOCK_FIELD_(ArgumentTuple, k10));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args),
        get<k8>(args), get<k9>(args), get<k10>(args));
  }
};

template <typename Result, typename ArgumentTuple>
class SelectArgs<Result, ArgumentTuple,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type();
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& /* args */) {
    return SelectedArgs();
  }
};

template <typename Result, typename ArgumentTuple, int k1>
class SelectArgs<Result, ArgumentTuple,
                 k1, -1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, k7, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7, int k8>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, k7, k8, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7),
      GMOCK_FIELD_(ArgumentTuple, k8));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args),
        get<k8>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7, int k8, int k9>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, k7, k8, k9, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7),
      GMOCK_FIELD_(ArgumentTuple, k8), GMOCK_FIELD_(ArgumentTuple, k9));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args),
        get<k8>(args), get<k9>(args));
  }
};

#undef GMOCK_FIELD_

// Implements the WithArgs action.
template <typename InnerAction, int k1 = -1, int k2 = -1, int k3 = -1,
    int k4 = -1, int k5 = -1, int k6 = -1, int k7 = -1, int k8 = -1,
    int k9 = -1, int k10 = -1>
class WithArgsAction {
 public:
  explicit WithArgsAction(const InnerAction& action) : action_(action) {}

  template <typename F>
  operator Action<F>() const { return MakeAction(new Impl<F>(action_)); }

 private:
  template <typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;

    explicit Impl(const InnerAction& action) : action_(action) {}

    virtual Result Perform(const ArgumentTuple& args) {
      return action_.Perform(SelectArgs<Result, ArgumentTuple, k1, k2, k3, k4,
          k5, k6, k7, k8, k9, k10>::Select(args));
    }

   private:
    typedef typename SelectArgs<Result, ArgumentTuple,
        k1, k2, k3, k4, k5, k6, k7, k8, k9, k10>::type InnerFunctionType;

    Action<InnerFunctionType> action_;
  };

  const InnerAction action_;

  GTEST_DISALLOW_ASSIGN_(WithArgsAction);
};

// A macro from the ACTION* family (defined later in this file)
// defines an action that can be used in a mock function.  Typically,
// these actions only care about a subset of the arguments of the mock
// function.  For example, if such an action only uses the second
// argument, it can be used in any mock function that takes >= 2
// arguments where the type of the second argument is compatible.
//
// Therefore, the action implementation must be prepared to take more
// arguments than it needs.  The ExcessiveArg type is used to
// represent those excessive arguments.  In order to keep the compiler
// error messages tractable, we define it in the testing namespace
// instead of testing::internal.  However, this is an INTERNAL TYPE
// and subject to change without notice, so a user MUST NOT USE THIS
// TYPE DIRECTLY.
struct ExcessiveArg {};

// A helper class needed for implementing the ACTION* macros.
template <typename Result, class Impl>
class ActionHelper {
 public:
  static Result Perform(Impl* impl, const ::testing::tuple<>& args) {
    return impl->template gmock_PerformImpl<>(args, ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0>
  static Result Perform(Impl* impl, const ::testing::tuple<A0>& args) {
    return impl->template gmock_PerformImpl<A0>(args, get<0>(args),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1>& args) {
    return impl->template gmock_PerformImpl<A0, A1>(args, get<0>(args),
        get<1>(args), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2>(args, get<0>(args),
        get<1>(args), get<2>(args), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2,
      A3>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3>(args, get<0>(args),
        get<1>(args), get<2>(args), get<3>(args), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3,
      A4>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4>(args,
        get<0>(args), get<1>(args), get<2>(args), get<3>(args), get<4>(args),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5>(args,
        get<0>(args), get<1>(args), get<2>(args), get<3>(args), get<4>(args),
        get<5>(args), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6>(args,
        get<0>(args), get<1>(args), get<2>(args), get<3>(args), get<4>(args),
        get<5>(args), get<6>(args), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6, typename A7>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6, A7>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6,
        A7>(args, get<0>(args), get<1>(args), get<2>(args), get<3>(args),
        get<4>(args), get<5>(args), get<6>(args), get<7>(args), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6, typename A7, typename A8>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6, A7, A8>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6, A7,
        A8>(args, get<0>(args), get<1>(args), get<2>(args), get<3>(args),
        get<4>(args), get<5>(args), get<6>(args), get<7>(args), get<8>(args),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6, typename A7, typename A8, typename A9>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6, A7, A8, A9>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6, A7, A8,
        A9>(args, get<0>(args), get<1>(args), get<2>(args), get<3>(args),
        get<4>(args), get<5>(args), get<6>(args), get<7>(args), get<8>(args),
        get<9>(args));
  }
};

}  // namespace internal

// Various overloads for Invoke().

// WithArgs<N1, N2, ..., Nk>(an_action) creates an action that passes
// the selected arguments of the mock function to an_action and
// performs it.  It serves as an adaptor between actions with
// different argument lists.  C++ doesn't support default arguments for
// function templates, so we have to overload it.
template <int k1, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1>(action);
}

template <int k1, int k2, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2>(action);
}

template <int k1, int k2, int k3, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3>(action);
}

template <int k1, int k2, int k3, int k4, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4>(action);
}

template <int k1, int k2, int k3, int k4, int k5, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7,
    typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6,
      k7>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7,
      k8>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    int k9, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8, k9>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8,
      k9>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    int k9, int k10, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8,
    k9, k10>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8,
      k9, k10>(action);
}

// Creates an action that does actions a1, a2, ..., sequentially in
// each invocation.
template <typename Action1, typename Action2>
inline internal::DoBothAction<Action1, Action2>
DoAll(Action1 a1, Action2 a2) {
  return internal::DoBothAction<Action1, Action2>(a1, a2);
}

template <typename Action1, typename Action2, typename Action3>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    Action3> >
DoAll(Action1 a1, Action2 a2, Action3 a3) {
  return DoAll(a1, DoAll(a2, a3));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, Action4> > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4) {
  return DoAll(a1, DoAll(a2, a3, a4));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    Action5> > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5) {
  return DoAll(a1, DoAll(a2, a3, a4, a5));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, Action6> > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    Action7> > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7,
    typename Action8>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    internal::DoBothAction<Action7, Action8> > > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7, Action8 a8) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7, a8));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7,
    typename Action8, typename Action9>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    internal::DoBothAction<Action7, internal::DoBothAction<Action8,
    Action9> > > > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7, Action8 a8, Action9 a9) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7, a8, a9));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7,
    typename Action8, typename Action9, typename Action10>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    internal::DoBothAction<Action7, internal::DoBothAction<Action8,
    internal::DoBothAction<Action9, Action10> > > > > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7, Action8 a8, Action9 a9, Action10 a10) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7, a8, a9, a10));
}

}  // namespace testing

// The ACTION* family of macros can be used in a namespace scope to
// define custom actions easily.  The syntax:
//
//   ACTION(name) { statements; }
//
// will define an action with the given name that executes the
// statements.  The value returned by the statements will be used as
// the return value of the action.  Inside the statements, you can
// refer to the K-th (0-based) argument of the mock function by
// 'argK', and refer to its type by 'argK_type'.  For example:
//
//   ACTION(IncrementArg1) {
//     arg1_type temp = arg1;
//     return ++(*temp);
//   }
//
// allows you to write
//
//   ...WillOnce(IncrementArg1());
//
// You can also refer to the entire argument tuple and its type by
// 'args' and 'args_type', and refer to the mock function type and its
// return type by 'function_type' and 'return_type'.
//
// Note that you don't need to specify the types of the mock function
// arguments.  However rest assured that your code is still type-safe:
// you'll get a compiler error if *arg1 doesn't support the ++
// operator, or if the type of ++(*arg1) isn't compatible with the
// mock function's return type, for example.
//
// Sometimes you'll want to parameterize the action.   For that you can use
// another macro:
//
//   ACTION_P(name, param_name) { statements; }
//
// For example:
//
//   ACTION_P(Add, n) { return arg0 + n; }
//
// will allow you to write:
//
//   ...WillOnce(Add(5));
//
// Note that you don't need to provide the type of the parameter
// either.  If you need to reference the type of a parameter named
// 'foo', you can write 'foo_type'.  For example, in the body of
// ACTION_P(Add, n) above, you can write 'n_type' to refer to the type
// of 'n'.
//
// We also provide ACTION_P2, ACTION_P3, ..., up to ACTION_P10 to support
// multi-parameter actions.
//
// For the purpose of typing, you can view
//
//   ACTION_Pk(Foo, p1, ..., pk) { ... }
//
// as shorthand for
//
//   template <typename p1_type, ..., typename pk_type>
//   FooActionPk<p1_type, ..., pk_type> Foo(p1_type p1, ..., pk_type pk) { ... }
//
// In particular, you can provide the template type arguments
// explicitly when invoking Foo(), as in Foo<long, bool>(5, false);
// although usually you can rely on the compiler to infer the types
// for you automatically.  You can assign the result of expression
// Foo(p1, ..., pk) to a variable of type FooActionPk<p1_type, ...,
// pk_type>.  This can be useful when composing actions.
//
// You can also overload actions with different numbers of parameters:
//
//   ACTION_P(Plus, a) { ... }
//   ACTION_P2(Plus, a, b) { ... }
//
// While it's tempting to always use the ACTION* macros when defining
// a new action, you should also consider implementing ActionInterface
// or using MakePolymorphicAction() instead, especially if you need to
// use the action a lot.  While these approaches require more work,
// they give you more control on the types of the mock function
// arguments and the action parameters, which in general leads to
// better compiler error messages that pay off in the long run.  They
// also allow overloading actions based on parameter types (as opposed
// to just based on the number of parameters).
//
// CAVEAT:
//
// ACTION*() can only be used in a namespace scope.  The reason is
// that C++ doesn't yet allow function-local types to be used to
// instantiate templates.  The up-coming C++0x standard will fix this.
// Once that's done, we'll consider supporting using ACTION*() inside
// a function.
//
// MORE INFORMATION:
//
// To learn more about using these macros, please search for 'ACTION'
// on https://github.com/google/googletest/blob/master/googlemock/docs/CookBook.md

// An internal macro needed for implementing ACTION*().
#define GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_\
    const args_type& args GTEST_ATTRIBUTE_UNUSED_, \
    arg0_type arg0 GTEST_ATTRIBUTE_UNUSED_, \
    arg1_type arg1 GTEST_ATTRIBUTE_UNUSED_, \
    arg2_type arg2 GTEST_ATTRIBUTE_UNUSED_, \
    arg3_type arg3 GTEST_ATTRIBUTE_UNUSED_, \
    arg4_type arg4 GTEST_ATTRIBUTE_UNUSED_, \
    arg5_type arg5 GTEST_ATTRIBUTE_UNUSED_, \
    arg6_type arg6 GTEST_ATTRIBUTE_UNUSED_, \
    arg7_type arg7 GTEST_ATTRIBUTE_UNUSED_, \
    arg8_type arg8 GTEST_ATTRIBUTE_UNUSED_, \
    arg9_type arg9 GTEST_ATTRIBUTE_UNUSED_

// Sometimes you want to give an action explicit template parameters
// that cannot be inferred from its value parameters.  ACTION() and
// ACTION_P*() don't support that.  ACTION_TEMPLATE() remedies that
// and can be viewed as an extension to ACTION() and ACTION_P*().
//
// The syntax:
//
//   ACTION_TEMPLATE(ActionName,
//                   HAS_m_TEMPLATE_PARAMS(kind1, name1, ..., kind_m, name_m),
//                   AND_n_VALUE_PARAMS(p1, ..., p_n)) { statements; }
//
// defines an action template that takes m explicit template
// parameters and n value parameters.  name_i is the name of the i-th
// template parameter, and kind_i specifies whether it's a typename,
// an integral constant, or a template.  p_i is the name of the i-th
// value parameter.
//
// Example:
//
//   // DuplicateArg<k, T>(output) converts the k-th argument of the mock
//   // function to type T and copies it to *output.
//   ACTION_TEMPLATE(DuplicateArg,
//                   HAS_2_TEMPLATE_PARAMS(int, k, typename, T),
//                   AND_1_VALUE_PARAMS(output)) {
//     *output = T(::testing::get<k>(args));
//   }
//   ...
//     int n;
//     EXPECT_CALL(mock, Foo(_, _))
//         .WillOnce(DuplicateArg<1, unsigned char>(&n));
//
// To create an instance of an action template, write:
//
//   ActionName<t1, ..., t_m>(v1, ..., v_n)
//
// where the ts are the template arguments and the vs are the value
// arguments.  The value argument types are inferred by the compiler.
// If you want to explicitly specify the value argument types, you can
// provide additional template arguments:
//
//   ActionName<t1, ..., t_m, u1, ..., u_k>(v1, ..., v_n)
//
// where u_i is the desired type of v_i.
//
// ACTION_TEMPLATE and ACTION/ACTION_P* can be overloaded on the
// number of value parameters, but not on the number of template
// parameters.  Without the restriction, the meaning of the following
// is unclear:
//
//   OverloadedAction<int, bool>(x);
//
// Are we using a single-template-parameter action where 'bool' refers
// to the type of x, or are we using a two-template-parameter action
// where the compiler is asked to infer the type of x?
//
// Implementation notes:
//
// GMOCK_INTERNAL_*_HAS_m_TEMPLATE_PARAMS and
// GMOCK_INTERNAL_*_AND_n_VALUE_PARAMS are internal macros for
// implementing ACTION_TEMPLATE.  The main trick we use is to create
// new macro invocations when expanding a macro.  For example, we have
//
//   #define ACTION_TEMPLATE(name, template_params, value_params)
//       ... GMOCK_INTERNAL_DECL_##template_params ...
//
// which causes ACTION_TEMPLATE(..., HAS_1_TEMPLATE_PARAMS(typename, T), ...)
// to expand to
//
//       ... GMOCK_INTERNAL_DECL_HAS_1_TEMPLATE_PARAMS(typename, T) ...
//
// Since GMOCK_INTERNAL_DECL_HAS_1_TEMPLATE_PARAMS is a macro, the
// preprocessor will continue to expand it to
//
//       ... typename T ...
//
// This technique conforms to the C++ standard and is portable.  It
// allows us to implement action templates using O(N) code, where N is
// the maximum number of template/value parameters supported.  Without
// using it, we'd have to devote O(N^2) amount of code to implement all
// combinations of m and n.

// Declares the template parameters.
#define GMOCK_INTERNAL_DECL_HAS_1_TEMPLATE_PARAMS(kind0, name0) kind0 name0
#define GMOCK_INTERNAL_DECL_HAS_2_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1) kind0 name0, kind1 name1
#define GMOCK_INTERNAL_DECL_HAS_3_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2) kind0 name0, kind1 name1, kind2 name2
#define GMOCK_INTERNAL_DECL_HAS_4_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3) kind0 name0, kind1 name1, kind2 name2, \
    kind3 name3
#define GMOCK_INTERNAL_DECL_HAS_5_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4) kind0 name0, kind1 name1, \
    kind2 name2, kind3 name3, kind4 name4
#define GMOCK_INTERNAL_DECL_HAS_6_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5) kind0 name0, \
    kind1 name1, kind2 name2, kind3 name3, kind4 name4, kind5 name5
#define GMOCK_INTERNAL_DECL_HAS_7_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6) kind0 name0, kind1 name1, kind2 name2, kind3 name3, kind4 name4, \
    kind5 name5, kind6 name6
#define GMOCK_INTERNAL_DECL_HAS_8_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7) kind0 name0, kind1 name1, kind2 name2, kind3 name3, \
    kind4 name4, kind5 name5, kind6 name6, kind7 name7
#define GMOCK_INTERNAL_DECL_HAS_9_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7, kind8, name8) kind0 name0, kind1 name1, kind2 name2, \
    kind3 name3, kind4 name4, kind5 name5, kind6 name6, kind7 name7, \
    kind8 name8
#define GMOCK_INTERNAL_DECL_HAS_10_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1, kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6, kind7, name7, kind8, name8, kind9, name9) kind0 name0, \
    kind1 name1, kind2 name2, kind3 name3, kind4 name4, kind5 name5, \
    kind6 name6, kind7 name7, kind8 name8, kind9 name9

// Lists the template parameters.
#define GMOCK_INTERNAL_LIST_HAS_1_TEMPLATE_PARAMS(kind0, name0) name0
#define GMOCK_INTERNAL_LIST_HAS_2_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1) name0, name1
#define GMOCK_INTERNAL_LIST_HAS_3_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2) name0, name1, name2
#define GMOCK_INTERNAL_LIST_HAS_4_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3) name0, name1, name2, name3
#define GMOCK_INTERNAL_LIST_HAS_5_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4) name0, name1, name2, name3, \
    name4
#define GMOCK_INTERNAL_LIST_HAS_6_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5) name0, name1, \
    name2, name3, name4, name5
#define GMOCK_INTERNAL_LIST_HAS_7_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6) name0, name1, name2, name3, name4, name5, name6
#define GMOCK_INTERNAL_LIST_HAS_8_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7) name0, name1, name2, name3, name4, name5, name6, name7
#define GMOCK_INTERNAL_LIST_HAS_9_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7, kind8, name8) name0, name1, name2, name3, name4, name5, \
    name6, name7, name8
#define GMOCK_INTERNAL_LIST_HAS_10_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1, kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6, kind7, name7, kind8, name8, kind9, name9) name0, name1, name2, \
    name3, name4, name5, name6, name7, name8, name9

// Declares the types of value parameters.
#define GMOCK_INTERNAL_DECL_TYPE_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_DECL_TYPE_AND_1_VALUE_PARAMS(p0) , typename p0##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_2_VALUE_PARAMS(p0, p1) , \
    typename p0##_type, typename p1##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_3_VALUE_PARAMS(p0, p1, p2) , \
    typename p0##_type, typename p1##_type, typename p2##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_4_VALUE_PARAMS(p0, p1, p2, p3) , \
    typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) , \
    typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) , \
    typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) , typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type, \
    typename p6##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7) , typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type, \
    typename p6##_type, typename p7##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8) , typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type, \
    typename p6##_type, typename p7##_type, typename p8##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8, p9) , typename p0##_type, typename p1##_type, \
    typename p2##_type, typename p3##_type, typename p4##_type, \
    typename p5##_type, typename p6##_type, typename p7##_type, \
    typename p8##_type, typename p9##_type

// Initializes the value parameters.
#define GMOCK_INTERNAL_INIT_AND_0_VALUE_PARAMS()\
    ()
#define GMOCK_INTERNAL_INIT_AND_1_VALUE_PARAMS(p0)\
    (p0##_type gmock_p0) : p0(::testing::internal::move(gmock_p0))
#define GMOCK_INTERNAL_INIT_AND_2_VALUE_PARAMS(p0, p1)\
    (p0##_type gmock_p0, \
        p1##_type gmock_p1) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1))
#define GMOCK_INTERNAL_INIT_AND_3_VALUE_PARAMS(p0, p1, p2)\
    (p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2))
#define GMOCK_INTERNAL_INIT_AND_4_VALUE_PARAMS(p0, p1, p2, p3)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3))
#define GMOCK_INTERNAL_INIT_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, \
        p4##_type gmock_p4) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4))
#define GMOCK_INTERNAL_INIT_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5))
#define GMOCK_INTERNAL_INIT_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6))
#define GMOCK_INTERNAL_INIT_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6, \
        p7##_type gmock_p7) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)), \
        p7(::testing::internal::move(gmock_p7))
#define GMOCK_INTERNAL_INIT_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)), \
        p7(::testing::internal::move(gmock_p7)), \
        p8(::testing::internal::move(gmock_p8))
#define GMOCK_INTERNAL_INIT_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6, p7##_type gmock_p7, p8##_type gmock_p8, \
        p9##_type gmock_p9) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)), \
        p7(::testing::internal::move(gmock_p7)), \
        p8(::testing::internal::move(gmock_p8)), \
        p9(::testing::internal::move(gmock_p9))

// Declares the fields for storing the value parameters.
#define GMOCK_INTERNAL_DEFN_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_DEFN_AND_1_VALUE_PARAMS(p0) p0##_type p0;
#define GMOCK_INTERNAL_DEFN_AND_2_VALUE_PARAMS(p0, p1) p0##_type p0; \
    p1##_type p1;
#define GMOCK_INTERNAL_DEFN_AND_3_VALUE_PARAMS(p0, p1, p2) p0##_type p0; \
    p1##_type p1; p2##_type p2;
#define GMOCK_INTERNAL_DEFN_AND_4_VALUE_PARAMS(p0, p1, p2, p3) p0##_type p0; \
    p1##_type p1; p2##_type p2; p3##_type p3;
#define GMOCK_INTERNAL_DEFN_AND_5_VALUE_PARAMS(p0, p1, p2, p3, \
    p4) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4;
#define GMOCK_INTERNAL_DEFN_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, \
    p5) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4; \
    p5##_type p5;
#define GMOCK_INTERNAL_DEFN_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4; \
    p5##_type p5; p6##_type p6;
#define GMOCK_INTERNAL_DEFN_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4; \
    p5##_type p5; p6##_type p6; p7##_type p7;
#define GMOCK_INTERNAL_DEFN_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; \
    p4##_type p4; p5##_type p5; p6##_type p6; p7##_type p7; p8##_type p8;
#define GMOCK_INTERNAL_DEFN_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; \
    p4##_type p4; p5##_type p5; p6##_type p6; p7##_type p7; p8##_type p8; \
    p9##_type p9;

// Lists the value parameters.
#define GMOCK_INTERNAL_LIST_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_LIST_AND_1_VALUE_PARAMS(p0) p0
#define GMOCK_INTERNAL_LIST_AND_2_VALUE_PARAMS(p0, p1) p0, p1
#define GMOCK_INTERNAL_LIST_AND_3_VALUE_PARAMS(p0, p1, p2) p0, p1, p2
#define GMOCK_INTERNAL_LIST_AND_4_VALUE_PARAMS(p0, p1, p2, p3) p0, p1, p2, p3
#define GMOCK_INTERNAL_LIST_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) p0, p1, \
    p2, p3, p4
#define GMOCK_INTERNAL_LIST_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) p0, \
    p1, p2, p3, p4, p5
#define GMOCK_INTERNAL_LIST_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) p0, p1, p2, p3, p4, p5, p6
#define GMOCK_INTERNAL_LIST_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) p0, p1, p2, p3, p4, p5, p6, p7
#define GMOCK_INTERNAL_LIST_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) p0, p1, p2, p3, p4, p5, p6, p7, p8
#define GMOCK_INTERNAL_LIST_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) p0, p1, p2, p3, p4, p5, p6, p7, p8, p9

// Lists the value parameter types.
#define GMOCK_INTERNAL_LIST_TYPE_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_LIST_TYPE_AND_1_VALUE_PARAMS(p0) , p0##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_2_VALUE_PARAMS(p0, p1) , p0##_type, \
    p1##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_3_VALUE_PARAMS(p0, p1, p2) , p0##_type, \
    p1##_type, p2##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_4_VALUE_PARAMS(p0, p1, p2, p3) , \
    p0##_type, p1##_type, p2##_type, p3##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) , \
    p0##_type, p1##_type, p2##_type, p3##_type, p4##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) , \
    p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, p5##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, p5##_type, \
    p6##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
    p5##_type, p6##_type, p7##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
    p5##_type, p6##_type, p7##_type, p8##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8, p9) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
    p5##_type, p6##_type, p7##_type, p8##_type, p9##_type

// Declares the value parameters.
#define GMOCK_INTERNAL_DECL_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_DECL_AND_1_VALUE_PARAMS(p0) p0##_type p0
#define GMOCK_INTERNAL_DECL_AND_2_VALUE_PARAMS(p0, p1) p0##_type p0, \
    p1##_type p1
#define GMOCK_INTERNAL_DECL_AND_3_VALUE_PARAMS(p0, p1, p2) p0##_type p0, \
    p1##_type p1, p2##_type p2
#define GMOCK_INTERNAL_DECL_AND_4_VALUE_PARAMS(p0, p1, p2, p3) p0##_type p0, \
    p1##_type p1, p2##_type p2, p3##_type p3
#define GMOCK_INTERNAL_DECL_AND_5_VALUE_PARAMS(p0, p1, p2, p3, \
    p4) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4
#define GMOCK_INTERNAL_DECL_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, \
    p5) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, \
    p5##_type p5
#define GMOCK_INTERNAL_DECL_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, \
    p5##_type p5, p6##_type p6
#define GMOCK_INTERNAL_DECL_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, \
    p5##_type p5, p6##_type p6, p7##_type p7
#define GMOCK_INTERNAL_DECL_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
    p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8
#define GMOCK_INTERNAL_DECL_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
    p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8, \
    p9##_type p9

// The suffix of the class template implementing the action template.
#define GMOCK_INTERNAL_COUNT_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_COUNT_AND_1_VALUE_PARAMS(p0) P
#define GMOCK_INTERNAL_COUNT_AND_2_VALUE_PARAMS(p0, p1) P2
#define GMOCK_INTERNAL_COUNT_AND_3_VALUE_PARAMS(p0, p1, p2) P3
#define GMOCK_INTERNAL_COUNT_AND_4_VALUE_PARAMS(p0, p1, p2, p3) P4
#define GMOCK_INTERNAL_COUNT_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) P5
#define GMOCK_INTERNAL_COUNT_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) P6
#define GMOCK_INTERNAL_COUNT_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6) P7
#define GMOCK_INTERNAL_COUNT_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) P8
#define GMOCK_INTERNAL_COUNT_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) P9
#define GMOCK_INTERNAL_COUNT_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) P10

// The name of the class template implementing the action template.
#define GMOCK_ACTION_CLASS_(name, value_params)\
    GTEST_CONCAT_TOKEN_(name##Action, GMOCK_INTERNAL_COUNT_##value_params)

#define ACTION_TEMPLATE(name, template_params, value_params)\
  template <GMOCK_INTERNAL_DECL_##template_params\
            GMOCK_INTERNAL_DECL_TYPE_##value_params>\
  class GMOCK_ACTION_CLASS_(name, value_params) {\
   public:\
    explicit GMOCK_ACTION_CLASS_(name, value_params)\
        GMOCK_INTERNAL_INIT_##value_params {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      explicit gmock_Impl GMOCK_INTERNAL_INIT_##value_params {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      GMOCK_INTERNAL_DEFN_##value_params\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(\
          new gmock_Impl<F>(GMOCK_INTERNAL_LIST_##value_params));\
    }\
    GMOCK_INTERNAL_DEFN_##value_params\
   private:\
    GTEST_DISALLOW_ASSIGN_(GMOCK_ACTION_CLASS_(name, value_params));\
  };\
  template <GMOCK_INTERNAL_DECL_##template_params\
            GMOCK_INTERNAL_DECL_TYPE_##value_params>\
  inline GMOCK_ACTION_CLASS_(name, value_params)<\
      GMOCK_INTERNAL_LIST_##template_params\
      GMOCK_INTERNAL_LIST_TYPE_##value_params> name(\
          GMOCK_INTERNAL_DECL_##value_params) {\
    return GMOCK_ACTION_CLASS_(name, value_params)<\
        GMOCK_INTERNAL_LIST_##template_params\
        GMOCK_INTERNAL_LIST_TYPE_##value_params>(\
            GMOCK_INTERNAL_LIST_##value_params);\
  }\
  template <GMOCK_INTERNAL_DECL_##template_params\
            GMOCK_INTERNAL_DECL_TYPE_##value_params>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      GMOCK_ACTION_CLASS_(name, value_params)<\
          GMOCK_INTERNAL_LIST_##template_params\
          GMOCK_INTERNAL_LIST_TYPE_##value_params>::gmock_Impl<F>::\
              gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION(name)\
  class name##Action {\
   public:\
    name##Action() {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl() {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>());\
    }\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##Action);\
  };\
  inline name##Action name() {\
    return name##Action();\
  }\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##Action::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P(name, p0)\
  template <typename p0##_type>\
  class name##ActionP {\
   public:\
    explicit name##ActionP(p0##_type gmock_p0) : \
        p0(::testing::internal::forward<p0##_type>(gmock_p0)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      explicit gmock_Impl(p0##_type gmock_p0) : \
          p0(::testing::internal::forward<p0##_type>(gmock_p0)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0));\
    }\
    p0##_type p0;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP);\
  };\
  template <typename p0##_type>\
  inline name##ActionP<p0##_type> name(p0##_type p0) {\
    return name##ActionP<p0##_type>(p0);\
  }\
  template <typename p0##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP<p0##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P2(name, p0, p1)\
  template <typename p0##_type, typename p1##_type>\
  class name##ActionP2 {\
   public:\
    name##ActionP2(p0##_type gmock_p0, \
        p1##_type gmock_p1) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, \
          p1##_type gmock_p1) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1));\
    }\
    p0##_type p0;\
    p1##_type p1;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP2);\
  };\
  template <typename p0##_type, typename p1##_type>\
  inline name##ActionP2<p0##_type, p1##_type> name(p0##_type p0, \
      p1##_type p1) {\
    return name##ActionP2<p0##_type, p1##_type>(p0, p1);\
  }\
  template <typename p0##_type, typename p1##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP2<p0##_type, p1##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P3(name, p0, p1, p2)\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  class name##ActionP3 {\
   public:\
    name##ActionP3(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, \
          p2##_type gmock_p2) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP3);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  inline name##ActionP3<p0##_type, p1##_type, p2##_type> name(p0##_type p0, \
      p1##_type p1, p2##_type p2) {\
    return name##ActionP3<p0##_type, p1##_type, p2##_type>(p0, p1, p2);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP3<p0##_type, p1##_type, \
          p2##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P4(name, p0, p1, p2, p3)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  class name##ActionP4 {\
   public:\
    name##ActionP4(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, \
        p3##_type gmock_p3) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP4);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  inline name##ActionP4<p0##_type, p1##_type, p2##_type, \
      p3##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, \
      p3##_type p3) {\
    return name##ActionP4<p0##_type, p1##_type, p2##_type, p3##_type>(p0, p1, \
        p2, p3);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP4<p0##_type, p1##_type, p2##_type, \
          p3##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P5(name, p0, p1, p2, p3, p4)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  class name##ActionP5 {\
   public:\
    name##ActionP5(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, \
        p4##_type gmock_p4) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
        p4(::testing::internal::forward<p4##_type>(gmock_p4)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, \
          p4##_type gmock_p4) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
          p4(::testing::internal::forward<p4##_type>(gmock_p4)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP5);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  inline name##ActionP5<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4) {\
    return name##ActionP5<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type>(p0, p1, p2, p3, p4);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP5<p0##_type, p1##_type, p2##_type, p3##_type, \
          p4##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P6(name, p0, p1, p2, p3, p4, p5)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  class name##ActionP6 {\
   public:\
    name##ActionP6(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
        p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
        p5(::testing::internal::forward<p5##_type>(gmock_p5)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, \
          p5##_type gmock_p5) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
          p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
          p5(::testing::internal::forward<p5##_type>(gmock_p5)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP6);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  inline name##ActionP6<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, \
      p3##_type p3, p4##_type p4, p5##_type p5) {\
    return name##ActionP6<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type>(p0, p1, p2, p3, p4, p5);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP6<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P7(name, p0, p1, p2, p3, p4, p5, p6)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  class name##ActionP7 {\
   public:\
    name##ActionP7(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, \
        p6##_type gmock_p6) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
        p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
        p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
        p6(::testing::internal::forward<p6##_type>(gmock_p6)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
          p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
          p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
          p6(::testing::internal::forward<p6##_type>(gmock_p6)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP7);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  inline name##ActionP7<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type> name(p0##_type p0, p1##_type p1, \
      p2##_type p2, p3##_type p3, p4##_type p4, p5##_type p5, \
      p6##_type p6) {\
    return name##ActionP7<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type>(p0, p1, p2, p3, p4, p5, p6);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP7<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P8(name, p0, p1, p2, p3, p4, p5, p6, p7)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  class name##ActionP8 {\
   public:\
    name##ActionP8(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, \
        p7##_type gmock_p7) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
        p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
        p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
        p6(::testing::internal::forward<p6##_type>(gmock_p6)), \
        p7(::testing::internal::forward<p7##_type>(gmock_p7)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, \
          p7##_type gmock_p7) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
          p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
          p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
          p6(::testing::internal::forward<p6##_type>(gmock_p6)), \
          p7(::testing::internal::forward<p7##_type>(gmock_p7)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
      p7##_type p7;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6, p7));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
    p7##_type p7;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP8);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  inline name##ActionP8<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type> name(p0##_type p0, \
      p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, p5##_type p5, \
      p6##_type p6, p7##_type p7) {\
    return name##ActionP8<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type>(p0, p1, p2, p3, p4, p5, \
        p6, p7);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP8<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type, \
          p7##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P9(name, p0, p1, p2, p3, p4, p5, p6, p7, p8)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  class name##ActionP9 {\
   public:\
    name##ActionP9(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
        p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
        p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
        p6(::testing::internal::forward<p6##_type>(gmock_p6)), \
        p7(::testing::internal::forward<p7##_type>(gmock_p7)), \
        p8(::testing::internal::forward<p8##_type>(gmock_p8)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7, \
          p8##_type gmock_p8) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
          p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
          p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
          p6(::testing::internal::forward<p6##_type>(gmock_p6)), \
          p7(::testing::internal::forward<p7##_type>(gmock_p7)), \
          p8(::testing::internal::forward<p8##_type>(gmock_p8)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
      p7##_type p7;\
      p8##_type p8;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6, p7, p8));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
    p7##_type p7;\
    p8##_type p8;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP9);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  inline name##ActionP9<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, \
      p8##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, \
      p8##_type p8) {\
    return name##ActionP9<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type, p8##_type>(p0, p1, p2, \
        p3, p4, p5, p6, p7, p8);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP9<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type, p7##_type, \
          p8##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P10(name, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  class name##ActionP10 {\
   public:\
    name##ActionP10(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8, \
        p9##_type gmock_p9) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
        p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
        p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
        p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
        p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
        p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
        p6(::testing::internal::forward<p6##_type>(gmock_p6)), \
        p7(::testing::internal::forward<p7##_type>(gmock_p7)), \
        p8(::testing::internal::forward<p8##_type>(gmock_p8)), \
        p9(::testing::internal::forward<p9##_type>(gmock_p9)) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7, p8##_type gmock_p8, \
          p9##_type gmock_p9) : p0(::testing::internal::forward<p0##_type>(gmock_p0)), \
          p1(::testing::internal::forward<p1##_type>(gmock_p1)), \
          p2(::testing::internal::forward<p2##_type>(gmock_p2)), \
          p3(::testing::internal::forward<p3##_type>(gmock_p3)), \
          p4(::testing::internal::forward<p4##_type>(gmock_p4)), \
          p5(::testing::internal::forward<p5##_type>(gmock_p5)), \
          p6(::testing::internal::forward<p6##_type>(gmock_p6)), \
          p7(::testing::internal::forward<p7##_type>(gmock_p7)), \
          p8(::testing::internal::forward<p8##_type>(gmock_p8)), \
          p9(::testing::internal::forward<p9##_type>(gmock_p9)) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
      p7##_type p7;\
      p8##_type p8;\
      p9##_type p9;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6, p7, p8, p9));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
    p7##_type p7;\
    p8##_type p8;\
    p9##_type p9;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP10);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  inline name##ActionP10<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, \
      p9##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8, \
      p9##_type p9) {\
    return name##ActionP10<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, p9##_type>(p0, \
        p1, p2, p3, p4, p5, p6, p7, p8, p9);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP10<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type, p7##_type, p8##_type, \
          p9##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

namespace testing {


// The ACTION*() macros trigger warning C4100 (unreferenced formal
// parameter) in MSVC with -W4.  Unfortunately they cannot be fixed in
// the macro definition, as the warnings are generated when the macro
// is expanded and macro expansion cannot contain #pragma.  Therefore
// we suppress them here.
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
#endif

// Various overloads for InvokeArgument<N>().
//
// The InvokeArgument<N>(a1, a2, ..., a_k) action invokes the N-th
// (0-based) argument, which must be a k-ary callable, of the mock
// function, with arguments a1, a2, ..., a_k.
//
// Notes:
//
//   1. The arguments are passed by value by default.  If you need to
//   pass an argument by reference, wrap it inside ByRef().  For
//   example,
//
//     InvokeArgument<1>(5, string("Hello"), ByRef(foo))
//
//   passes 5 and string("Hello") by value, and passes foo by
//   reference.
//
//   2. If the callable takes an argument by reference but ByRef() is
//   not used, it will receive the reference to a copy of the value,
//   instead of the original value.  For example, when the 0-th
//   argument of the mock function takes a const string&, the action
//
//     InvokeArgument<0>(string("Hello"))
//
//   makes a copy of the temporary string("Hello") object and passes a
//   reference of the copy, instead of the original temporary object,
//   to the callable.  This makes it easy for a user to define an
//   InvokeArgument action from temporary values and have it performed
//   later.

namespace internal {
namespace invoke_argument {

// Appears in InvokeArgumentAdl's argument list to help avoid
// accidental calls to user functions of the same name.
struct AdlTag {};

// InvokeArgumentAdl - a helper for InvokeArgument.
// The basic overloads are provided here for generic functors.
// Overloads for other custom-callables are provided in the
// internal/custom/callback-actions.h header.

template <typename R, typename F>
R InvokeArgumentAdl(AdlTag, F f) {
  return f();
}
template <typename R, typename F, typename A1>
R InvokeArgumentAdl(AdlTag, F f, A1 a1) {
  return f(a1);
}
template <typename R, typename F, typename A1, typename A2>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2) {
  return f(a1, a2);
}
template <typename R, typename F, typename A1, typename A2, typename A3>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3) {
  return f(a1, a2, a3);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4) {
  return f(a1, a2, a3, a4);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) {
  return f(a1, a2, a3, a4, a5);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) {
  return f(a1, a2, a3, a4, a5, a6);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7) {
  return f(a1, a2, a3, a4, a5, a6, a7);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7, A8 a8) {
  return f(a1, a2, a3, a4, a5, a6, a7, a8);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8,
    typename A9>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7, A8 a8, A9 a9) {
  return f(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8,
    typename A9, typename A10>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7, A8 a8, A9 a9, A10 a10) {
  return f(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
}  // namespace invoke_argument
}  // namespace internal

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_0_VALUE_PARAMS()) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args));
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_1_VALUE_PARAMS(p0)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_2_VALUE_PARAMS(p0, p1)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_3_VALUE_PARAMS(p0, p1, p2)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_4_VALUE_PARAMS(p0, p1, p2, p3)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6, p7);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

// Various overloads for ReturnNew<T>().
//
// The ReturnNew<T>(a1, a2, ..., a_k) action returns a pointer to a new
// instance of type T, constructed on the heap with constructor arguments
// a1, a2, ..., and a_k. The caller assumes ownership of the returned value.
ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_0_VALUE_PARAMS()) {
  return new T();
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_1_VALUE_PARAMS(p0)) {
  return new T(p0);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_2_VALUE_PARAMS(p0, p1)) {
  return new T(p0, p1);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_3_VALUE_PARAMS(p0, p1, p2)) {
  return new T(p0, p1, p2);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_4_VALUE_PARAMS(p0, p1, p2, p3)) {
  return new T(p0, p1, p2, p3);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4)) {
  return new T(p0, p1, p2, p3, p4);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5)) {
  return new T(p0, p1, p2, p3, p4, p5);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6)) {
  return new T(p0, p1, p2, p3, p4, p5, p6);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7)) {
  return new T(p0, p1, p2, p3, p4, p5, p6, p7);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
  return new T(p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)) {
  return new T(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif

}  // namespace testing

// Include any custom callback actions added by the local installation.
// We must include this header at the end to make sure it can use the
// declarations from this file.
// This file was GENERATED by command:
//     pump.py gmock-generated-actions.h.pump
// DO NOT EDIT BY HAND!!!

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_GENERATED_ACTIONS_H_
#define GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_GENERATED_ACTIONS_H_

#endif  // GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_GENERATED_ACTIONS_H_

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_ACTIONS_H_
// This file was GENERATED by command:
//     pump.py gmock-generated-function-mockers.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements function mockers of various arities.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_FUNCTION_MOCKERS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_FUNCTION_MOCKERS_H_

// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements the ON_CALL() and EXPECT_CALL() macros.
//
// A user can use the ON_CALL() macro to specify the default action of
// a mock method.  The syntax is:
//
//   ON_CALL(mock_object, Method(argument-matchers))
//       .With(multi-argument-matcher)
//       .WillByDefault(action);
//
//  where the .With() clause is optional.
//
// A user can use the EXPECT_CALL() macro to specify an expectation on
// a mock method.  The syntax is:
//
//   EXPECT_CALL(mock_object, Method(argument-matchers))
//       .With(multi-argument-matchers)
//       .Times(cardinality)
//       .InSequence(sequences)
//       .After(expectations)
//       .WillOnce(action)
//       .WillRepeatedly(action)
//       .RetiresOnSaturation();
//
// where all clauses are optional, and .InSequence()/.After()/
// .WillOnce() can appear any number of times.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_

#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some commonly used argument matchers.  More
// matchers can be defined by the user implementing the
// MatcherInterface<T> interface if necessary.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_MATCHERS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_MATCHERS_H_

#include <math.h>
#include <algorithm>
#include <iterator>
#include <limits>
#include <ostream>  // NOLINT
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#if GTEST_HAS_STD_INITIALIZER_LIST_
# include <initializer_list>  // NOLINT -- must be after gtest.h
#endif

namespace testing {

// To implement a matcher Foo for type T, define:
//   1. a class FooMatcherImpl that implements the
//      MatcherInterface<T> interface, and
//   2. a factory function that creates a Matcher<T> object from a
//      FooMatcherImpl*.
//
// The two-level delegation design makes it possible to allow a user
// to write "v" instead of "Eq(v)" where a Matcher is expected, which
// is impossible if we pass matchers by pointers.  It also eases
// ownership management as Matcher objects can now be copied like
// plain values.

// MatchResultListener is an abstract class.  Its << operator can be
// used by a matcher to explain why a value matches or doesn't match.
//
// TODO(wan@google.com): add method
//   bool InterestedInWhy(bool result) const;
// to indicate whether the listener is interested in why the match
// result is 'result'.
class MatchResultListener {
 public:
  // Creates a listener object with the given underlying ostream.  The
  // listener does not own the ostream, and does not dereference it
  // in the constructor or destructor.
  explicit MatchResultListener(::std::ostream* os) : stream_(os) {}
  virtual ~MatchResultListener() = 0;  // Makes this class abstract.

  // Streams x to the underlying ostream; does nothing if the ostream
  // is NULL.
  template <typename T>
  MatchResultListener& operator<<(const T& x) {
    if (stream_ != NULL)
      *stream_ << x;
    return *this;
  }

  // Returns the underlying ostream.
  ::std::ostream* stream() { return stream_; }

  // Returns true iff the listener is interested in an explanation of
  // the match result.  A matcher's MatchAndExplain() method can use
  // this information to avoid generating the explanation when no one
  // intends to hear it.
  bool IsInterested() const { return stream_ != NULL; }

 private:
  ::std::ostream* const stream_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(MatchResultListener);
};

inline MatchResultListener::~MatchResultListener() {
}

// An instance of a subclass of this knows how to describe itself as a
// matcher.
class MatcherDescriberInterface {
 public:
  virtual ~MatcherDescriberInterface() {}

  // Describes this matcher to an ostream.  The function should print
  // a verb phrase that describes the property a value matching this
  // matcher should have.  The subject of the verb phrase is the value
  // being matched.  For example, the DescribeTo() method of the Gt(7)
  // matcher prints "is greater than 7".
  virtual void DescribeTo(::std::ostream* os) const = 0;

  // Describes the negation of this matcher to an ostream.  For
  // example, if the description of this matcher is "is greater than
  // 7", the negated description could be "is not greater than 7".
  // You are not required to override this when implementing
  // MatcherInterface, but it is highly advised so that your matcher
  // can produce good error messages.
  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "not (";
    DescribeTo(os);
    *os << ")";
  }
};

// The implementation of a matcher.
template <typename T>
class MatcherInterface : public MatcherDescriberInterface {
 public:
  // Returns true iff the matcher matches x; also explains the match
  // result to 'listener' if necessary (see the next paragraph), in
  // the form of a non-restrictive relative clause ("which ...",
  // "whose ...", etc) that describes x.  For example, the
  // MatchAndExplain() method of the Pointee(...) matcher should
  // generate an explanation like "which points to ...".
  //
  // Implementations of MatchAndExplain() should add an explanation of
  // the match result *if and only if* they can provide additional
  // information that's not already present (or not obvious) in the
  // print-out of x and the matcher's description.  Whether the match
  // succeeds is not a factor in deciding whether an explanation is
  // needed, as sometimes the caller needs to print a failure message
  // when the match succeeds (e.g. when the matcher is used inside
  // Not()).
  //
  // For example, a "has at least 10 elements" matcher should explain
  // what the actual element count is, regardless of the match result,
  // as it is useful information to the reader; on the other hand, an
  // "is empty" matcher probably only needs to explain what the actual
  // size is when the match fails, as it's redundant to say that the
  // size is 0 when the value is already known to be empty.
  //
  // You should override this method when defining a new matcher.
  //
  // It's the responsibility of the caller (Google Mock) to guarantee
  // that 'listener' is not NULL.  This helps to simplify a matcher's
  // implementation when it doesn't care about the performance, as it
  // can talk to 'listener' without checking its validity first.
  // However, in order to implement dummy listeners efficiently,
  // listener->stream() may be NULL.
  virtual bool MatchAndExplain(T x, MatchResultListener* listener) const = 0;

  // Inherits these methods from MatcherDescriberInterface:
  //   virtual void DescribeTo(::std::ostream* os) const = 0;
  //   virtual void DescribeNegationTo(::std::ostream* os) const;
};

namespace internal {

// Converts a MatcherInterface<T> to a MatcherInterface<const T&>.
template <typename T>
class MatcherInterfaceAdapter : public MatcherInterface<const T&> {
 public:
  explicit MatcherInterfaceAdapter(const MatcherInterface<T>* impl)
      : impl_(impl) {}
  virtual ~MatcherInterfaceAdapter() { delete impl_; }

  virtual void DescribeTo(::std::ostream* os) const { impl_->DescribeTo(os); }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    impl_->DescribeNegationTo(os);
  }

  virtual bool MatchAndExplain(const T& x,
                               MatchResultListener* listener) const {
    return impl_->MatchAndExplain(x, listener);
  }

 private:
  const MatcherInterface<T>* const impl_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(MatcherInterfaceAdapter);
};

}  // namespace internal

// A match result listener that stores the explanation in a string.
class StringMatchResultListener : public MatchResultListener {
 public:
  StringMatchResultListener() : MatchResultListener(&ss_) {}

  // Returns the explanation accumulated so far.
  std::string str() const { return ss_.str(); }

  // Clears the explanation accumulated so far.
  void Clear() { ss_.str(""); }

 private:
  ::std::stringstream ss_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(StringMatchResultListener);
};

namespace internal {

struct AnyEq {
  template <typename A, typename B>
  bool operator()(const A& a, const B& b) const { return a == b; }
};
struct AnyNe {
  template <typename A, typename B>
  bool operator()(const A& a, const B& b) const { return a != b; }
};
struct AnyLt {
  template <typename A, typename B>
  bool operator()(const A& a, const B& b) const { return a < b; }
};
struct AnyGt {
  template <typename A, typename B>
  bool operator()(const A& a, const B& b) const { return a > b; }
};
struct AnyLe {
  template <typename A, typename B>
  bool operator()(const A& a, const B& b) const { return a <= b; }
};
struct AnyGe {
  template <typename A, typename B>
  bool operator()(const A& a, const B& b) const { return a >= b; }
};

// A match result listener that ignores the explanation.
class DummyMatchResultListener : public MatchResultListener {
 public:
  DummyMatchResultListener() : MatchResultListener(NULL) {}

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(DummyMatchResultListener);
};

// A match result listener that forwards the explanation to a given
// ostream.  The difference between this and MatchResultListener is
// that the former is concrete.
class StreamMatchResultListener : public MatchResultListener {
 public:
  explicit StreamMatchResultListener(::std::ostream* os)
      : MatchResultListener(os) {}

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(StreamMatchResultListener);
};

// An internal class for implementing Matcher<T>, which will derive
// from it.  We put functionalities common to all Matcher<T>
// specializations here to avoid code duplication.
template <typename T>
class MatcherBase {
 public:
  // Returns true iff the matcher matches x; also explains the match
  // result to 'listener'.
  bool MatchAndExplain(GTEST_REFERENCE_TO_CONST_(T) x,
                       MatchResultListener* listener) const {
    return impl_->MatchAndExplain(x, listener);
  }

  // Returns true iff this matcher matches x.
  bool Matches(GTEST_REFERENCE_TO_CONST_(T) x) const {
    DummyMatchResultListener dummy;
    return MatchAndExplain(x, &dummy);
  }

  // Describes this matcher to an ostream.
  void DescribeTo(::std::ostream* os) const { impl_->DescribeTo(os); }

  // Describes the negation of this matcher to an ostream.
  void DescribeNegationTo(::std::ostream* os) const {
    impl_->DescribeNegationTo(os);
  }

  // Explains why x matches, or doesn't match, the matcher.
  void ExplainMatchResultTo(GTEST_REFERENCE_TO_CONST_(T) x,
                            ::std::ostream* os) const {
    StreamMatchResultListener listener(os);
    MatchAndExplain(x, &listener);
  }

  // Returns the describer for this matcher object; retains ownership
  // of the describer, which is only guaranteed to be alive when
  // this matcher object is alive.
  const MatcherDescriberInterface* GetDescriber() const {
    return impl_.get();
  }

 protected:
  MatcherBase() {}

  // Constructs a matcher from its implementation.
  explicit MatcherBase(
      const MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)>* impl)
      : impl_(impl) {}

  template <typename U>
  explicit MatcherBase(
      const MatcherInterface<U>* impl,
      typename internal::EnableIf<
          !internal::IsSame<U, GTEST_REFERENCE_TO_CONST_(U)>::value>::type* =
          NULL)
      : impl_(new internal::MatcherInterfaceAdapter<U>(impl)) {}

  virtual ~MatcherBase() {}

 private:
  // shared_ptr (util/gtl/shared_ptr.h) and linked_ptr have similar
  // interfaces.  The former dynamically allocates a chunk of memory
  // to hold the reference count, while the latter tracks all
  // references using a circular linked list without allocating
  // memory.  It has been observed that linked_ptr performs better in
  // typical scenarios.  However, shared_ptr can out-perform
  // linked_ptr when there are many more uses of the copy constructor
  // than the default constructor.
  //
  // If performance becomes a problem, we should see if using
  // shared_ptr helps.
  ::testing::internal::linked_ptr<
      const MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)> >
      impl_;
};

}  // namespace internal

// A Matcher<T> is a copyable and IMMUTABLE (except by assignment)
// object that can check whether a value of type T matches.  The
// implementation of Matcher<T> is just a linked_ptr to const
// MatcherInterface<T>, so copying is fairly cheap.  Don't inherit
// from Matcher!
template <typename T>
class Matcher : public internal::MatcherBase<T> {
 public:
  // Constructs a null matcher.  Needed for storing Matcher objects in STL
  // containers.  A default-constructed matcher is not yet initialized.  You
  // cannot use it until a valid value has been assigned to it.
  explicit Matcher() {}  // NOLINT

  // Constructs a matcher from its implementation.
  explicit Matcher(const MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)>* impl)
      : internal::MatcherBase<T>(impl) {}

  template <typename U>
  explicit Matcher(const MatcherInterface<U>* impl,
                   typename internal::EnableIf<!internal::IsSame<
                       U, GTEST_REFERENCE_TO_CONST_(U)>::value>::type* = NULL)
      : internal::MatcherBase<T>(impl) {}

  // Implicit constructor here allows people to write
  // EXPECT_CALL(foo, Bar(5)) instead of EXPECT_CALL(foo, Bar(Eq(5))) sometimes
  Matcher(T value);  // NOLINT
};

// The following two specializations allow the user to write str
// instead of Eq(str) and "foo" instead of Eq("foo") when a std::string
// matcher is expected.
template <>
class GTEST_API_ Matcher<const std::string&>
    : public internal::MatcherBase<const std::string&> {
 public:
  Matcher() {}

  explicit Matcher(const MatcherInterface<const std::string&>* impl)
      : internal::MatcherBase<const std::string&>(impl) {}

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a std::string object.
  Matcher(const std::string& s);  // NOLINT

#if GTEST_HAS_GLOBAL_STRING
  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a ::string object.
  Matcher(const ::string& s);  // NOLINT
#endif                         // GTEST_HAS_GLOBAL_STRING

  // Allows the user to write "foo" instead of Eq("foo") sometimes.
  Matcher(const char* s);  // NOLINT
};

template <>
class GTEST_API_ Matcher<std::string>
    : public internal::MatcherBase<std::string> {
 public:
  Matcher() {}

  explicit Matcher(const MatcherInterface<const std::string&>* impl)
      : internal::MatcherBase<std::string>(impl) {}
  explicit Matcher(const MatcherInterface<std::string>* impl)
      : internal::MatcherBase<std::string>(impl) {}

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a string object.
  Matcher(const std::string& s);  // NOLINT

#if GTEST_HAS_GLOBAL_STRING
  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a ::string object.
  Matcher(const ::string& s);  // NOLINT
#endif                         // GTEST_HAS_GLOBAL_STRING

  // Allows the user to write "foo" instead of Eq("foo") sometimes.
  Matcher(const char* s);  // NOLINT
};

#if GTEST_HAS_GLOBAL_STRING
// The following two specializations allow the user to write str
// instead of Eq(str) and "foo" instead of Eq("foo") when a ::string
// matcher is expected.
template <>
class GTEST_API_ Matcher<const ::string&>
    : public internal::MatcherBase<const ::string&> {
 public:
  Matcher() {}

  explicit Matcher(const MatcherInterface<const ::string&>* impl)
      : internal::MatcherBase<const ::string&>(impl) {}

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a std::string object.
  Matcher(const std::string& s);  // NOLINT

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a ::string object.
  Matcher(const ::string& s);  // NOLINT

  // Allows the user to write "foo" instead of Eq("foo") sometimes.
  Matcher(const char* s);  // NOLINT
};

template <>
class GTEST_API_ Matcher< ::string>
    : public internal::MatcherBase< ::string> {
 public:
  Matcher() {}

  explicit Matcher(const MatcherInterface<const ::string&>* impl)
      : internal::MatcherBase< ::string>(impl) {}
  explicit Matcher(const MatcherInterface< ::string>* impl)
      : internal::MatcherBase< ::string>(impl) {}

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a std::string object.
  Matcher(const std::string& s);  // NOLINT

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a ::string object.
  Matcher(const ::string& s);  // NOLINT

  // Allows the user to write "foo" instead of Eq("foo") sometimes.
  Matcher(const char* s);  // NOLINT
};
#endif  // GTEST_HAS_GLOBAL_STRING

#if GTEST_HAS_ABSL
// The following two specializations allow the user to write str
// instead of Eq(str) and "foo" instead of Eq("foo") when a absl::string_view
// matcher is expected.
template <>
class GTEST_API_ Matcher<const absl::string_view&>
    : public internal::MatcherBase<const absl::string_view&> {
 public:
  Matcher() {}

  explicit Matcher(const MatcherInterface<const absl::string_view&>* impl)
      : internal::MatcherBase<const absl::string_view&>(impl) {}

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a std::string object.
  Matcher(const std::string& s);  // NOLINT

#if GTEST_HAS_GLOBAL_STRING
  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a ::string object.
  Matcher(const ::string& s);  // NOLINT
#endif                         // GTEST_HAS_GLOBAL_STRING

  // Allows the user to write "foo" instead of Eq("foo") sometimes.
  Matcher(const char* s);  // NOLINT

  // Allows the user to pass absl::string_views directly.
  Matcher(absl::string_view s);  // NOLINT
};

template <>
class GTEST_API_ Matcher<absl::string_view>
    : public internal::MatcherBase<absl::string_view> {
 public:
  Matcher() {}

  explicit Matcher(const MatcherInterface<const absl::string_view&>* impl)
      : internal::MatcherBase<absl::string_view>(impl) {}
  explicit Matcher(const MatcherInterface<absl::string_view>* impl)
      : internal::MatcherBase<absl::string_view>(impl) {}

  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a std::string object.
  Matcher(const std::string& s);  // NOLINT

#if GTEST_HAS_GLOBAL_STRING
  // Allows the user to write str instead of Eq(str) sometimes, where
  // str is a ::string object.
  Matcher(const ::string& s);  // NOLINT
#endif                         // GTEST_HAS_GLOBAL_STRING

  // Allows the user to write "foo" instead of Eq("foo") sometimes.
  Matcher(const char* s);  // NOLINT

  // Allows the user to pass absl::string_views directly.
  Matcher(absl::string_view s);  // NOLINT
};
#endif  // GTEST_HAS_ABSL

// Prints a matcher in a human-readable format.
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matcher<T>& matcher) {
  matcher.DescribeTo(&os);
  return os;
}

// The PolymorphicMatcher class template makes it easy to implement a
// polymorphic matcher (i.e. a matcher that can match values of more
// than one type, e.g. Eq(n) and NotNull()).
//
// To define a polymorphic matcher, a user should provide an Impl
// class that has a DescribeTo() method and a DescribeNegationTo()
// method, and define a member function (or member function template)
//
//   bool MatchAndExplain(const Value& value,
//                        MatchResultListener* listener) const;
//
// See the definition of NotNull() for a complete example.
template <class Impl>
class PolymorphicMatcher {
 public:
  explicit PolymorphicMatcher(const Impl& an_impl) : impl_(an_impl) {}

  // Returns a mutable reference to the underlying matcher
  // implementation object.
  Impl& mutable_impl() { return impl_; }

  // Returns an immutable reference to the underlying matcher
  // implementation object.
  const Impl& impl() const { return impl_; }

  template <typename T>
  operator Matcher<T>() const {
    return Matcher<T>(new MonomorphicImpl<GTEST_REFERENCE_TO_CONST_(T)>(impl_));
  }

 private:
  template <typename T>
  class MonomorphicImpl : public MatcherInterface<T> {
   public:
    explicit MonomorphicImpl(const Impl& impl) : impl_(impl) {}

    virtual void DescribeTo(::std::ostream* os) const {
      impl_.DescribeTo(os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      impl_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(T x, MatchResultListener* listener) const {
      return impl_.MatchAndExplain(x, listener);
    }

   private:
    const Impl impl_;

    GTEST_DISALLOW_ASSIGN_(MonomorphicImpl);
  };

  Impl impl_;

  GTEST_DISALLOW_ASSIGN_(PolymorphicMatcher);
};

// Creates a matcher from its implementation.  This is easier to use
// than the Matcher<T> constructor as it doesn't require you to
// explicitly write the template argument, e.g.
//
//   MakeMatcher(foo);
// vs
//   Matcher<const string&>(foo);
template <typename T>
inline Matcher<T> MakeMatcher(const MatcherInterface<T>* impl) {
  return Matcher<T>(impl);
}

// Creates a polymorphic matcher from its implementation.  This is
// easier to use than the PolymorphicMatcher<Impl> constructor as it
// doesn't require you to explicitly write the template argument, e.g.
//
//   MakePolymorphicMatcher(foo);
// vs
//   PolymorphicMatcher<TypeOfFoo>(foo);
template <class Impl>
inline PolymorphicMatcher<Impl> MakePolymorphicMatcher(const Impl& impl) {
  return PolymorphicMatcher<Impl>(impl);
}

// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
// and MUST NOT BE USED IN USER CODE!!!
namespace internal {

// The MatcherCastImpl class template is a helper for implementing
// MatcherCast().  We need this helper in order to partially
// specialize the implementation of MatcherCast() (C++ allows
// class/struct templates to be partially specialized, but not
// function templates.).

// This general version is used when MatcherCast()'s argument is a
// polymorphic matcher (i.e. something that can be converted to a
// Matcher but is not one yet; for example, Eq(value)) or a value (for
// example, "hello").
template <typename T, typename M>
class MatcherCastImpl {
 public:
  static Matcher<T> Cast(const M& polymorphic_matcher_or_value) {
    // M can be a polymorphic matcher, in which case we want to use
    // its conversion operator to create Matcher<T>.  Or it can be a value
    // that should be passed to the Matcher<T>'s constructor.
    //
    // We can't call Matcher<T>(polymorphic_matcher_or_value) when M is a
    // polymorphic matcher because it'll be ambiguous if T has an implicit
    // constructor from M (this usually happens when T has an implicit
    // constructor from any type).
    //
    // It won't work to unconditionally implict_cast
    // polymorphic_matcher_or_value to Matcher<T> because it won't trigger
    // a user-defined conversion from M to T if one exists (assuming M is
    // a value).
    return CastImpl(
        polymorphic_matcher_or_value,
        BooleanConstant<
            internal::ImplicitlyConvertible<M, Matcher<T> >::value>(),
        BooleanConstant<
            internal::ImplicitlyConvertible<M, T>::value>());
  }

 private:
  template <bool Ignore>
  static Matcher<T> CastImpl(const M& polymorphic_matcher_or_value,
                             BooleanConstant<true> /* convertible_to_matcher */,
                             BooleanConstant<Ignore>) {
    // M is implicitly convertible to Matcher<T>, which means that either
    // M is a polymorphic matcher or Matcher<T> has an implicit constructor
    // from M.  In both cases using the implicit conversion will produce a
    // matcher.
    //
    // Even if T has an implicit constructor from M, it won't be called because
    // creating Matcher<T> would require a chain of two user-defined conversions
    // (first to create T from M and then to create Matcher<T> from T).
    return polymorphic_matcher_or_value;
  }

  // M can't be implicitly converted to Matcher<T>, so M isn't a polymorphic
  // matcher. It's a value of a type implicitly convertible to T. Use direct
  // initialization to create a matcher.
  static Matcher<T> CastImpl(
      const M& value, BooleanConstant<false> /* convertible_to_matcher */,
      BooleanConstant<true> /* convertible_to_T */) {
    return Matcher<T>(ImplicitCast_<T>(value));
  }

  // M can't be implicitly converted to either Matcher<T> or T. Attempt to use
  // polymorphic matcher Eq(value) in this case.
  //
  // Note that we first attempt to perform an implicit cast on the value and
  // only fall back to the polymorphic Eq() matcher afterwards because the
  // latter calls bool operator==(const Lhs& lhs, const Rhs& rhs) in the end
  // which might be undefined even when Rhs is implicitly convertible to Lhs
  // (e.g. std::pair<const int, int> vs. std::pair<int, int>).
  //
  // We don't define this method inline as we need the declaration of Eq().
  static Matcher<T> CastImpl(
      const M& value, BooleanConstant<false> /* convertible_to_matcher */,
      BooleanConstant<false> /* convertible_to_T */);
};

// This more specialized version is used when MatcherCast()'s argument
// is already a Matcher.  This only compiles when type T can be
// statically converted to type U.
template <typename T, typename U>
class MatcherCastImpl<T, Matcher<U> > {
 public:
  static Matcher<T> Cast(const Matcher<U>& source_matcher) {
    return Matcher<T>(new Impl(source_matcher));
  }

 private:
  class Impl : public MatcherInterface<T> {
   public:
    explicit Impl(const Matcher<U>& source_matcher)
        : source_matcher_(source_matcher) {}

    // We delegate the matching logic to the source matcher.
    virtual bool MatchAndExplain(T x, MatchResultListener* listener) const {
#if GTEST_LANG_CXX11
      using FromType = typename std::remove_cv<typename std::remove_pointer<
          typename std::remove_reference<T>::type>::type>::type;
      using ToType = typename std::remove_cv<typename std::remove_pointer<
          typename std::remove_reference<U>::type>::type>::type;
      // Do not allow implicitly converting base*/& to derived*/&.
      static_assert(
          // Do not trigger if only one of them is a pointer. That implies a
          // regular conversion and not a down_cast.
          (std::is_pointer<typename std::remove_reference<T>::type>::value !=
           std::is_pointer<typename std::remove_reference<U>::type>::value) ||
              std::is_same<FromType, ToType>::value ||
              !std::is_base_of<FromType, ToType>::value,
          "Can't implicitly convert from <base> to <derived>");
#endif  // GTEST_LANG_CXX11

      return source_matcher_.MatchAndExplain(static_cast<U>(x), listener);
    }

    virtual void DescribeTo(::std::ostream* os) const {
      source_matcher_.DescribeTo(os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      source_matcher_.DescribeNegationTo(os);
    }

   private:
    const Matcher<U> source_matcher_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };
};

// This even more specialized version is used for efficiently casting
// a matcher to its own type.
template <typename T>
class MatcherCastImpl<T, Matcher<T> > {
 public:
  static Matcher<T> Cast(const Matcher<T>& matcher) { return matcher; }
};

}  // namespace internal

// In order to be safe and clear, casting between different matcher
// types is done explicitly via MatcherCast<T>(m), which takes a
// matcher m and returns a Matcher<T>.  It compiles only when T can be
// statically converted to the argument type of m.
template <typename T, typename M>
inline Matcher<T> MatcherCast(const M& matcher) {
  return internal::MatcherCastImpl<T, M>::Cast(matcher);
}

// Implements SafeMatcherCast().
//
// We use an intermediate class to do the actual safe casting as Nokia's
// Symbian compiler cannot decide between
// template <T, M> ... (M) and
// template <T, U> ... (const Matcher<U>&)
// for function templates but can for member function templates.
template <typename T>
class SafeMatcherCastImpl {
 public:
  // This overload handles polymorphic matchers and values only since
  // monomorphic matchers are handled by the next one.
  template <typename M>
  static inline Matcher<T> Cast(const M& polymorphic_matcher_or_value) {
    return internal::MatcherCastImpl<T, M>::Cast(polymorphic_matcher_or_value);
  }

  // This overload handles monomorphic matchers.
  //
  // In general, if type T can be implicitly converted to type U, we can
  // safely convert a Matcher<U> to a Matcher<T> (i.e. Matcher is
  // contravariant): just keep a copy of the original Matcher<U>, convert the
  // argument from type T to U, and then pass it to the underlying Matcher<U>.
  // The only exception is when U is a reference and T is not, as the
  // underlying Matcher<U> may be interested in the argument's address, which
  // is not preserved in the conversion from T to U.
  template <typename U>
  static inline Matcher<T> Cast(const Matcher<U>& matcher) {
    // Enforce that T can be implicitly converted to U.
    GTEST_COMPILE_ASSERT_((internal::ImplicitlyConvertible<T, U>::value),
                          T_must_be_implicitly_convertible_to_U);
    // Enforce that we are not converting a non-reference type T to a reference
    // type U.
    GTEST_COMPILE_ASSERT_(
        internal::is_reference<T>::value || !internal::is_reference<U>::value,
        cannot_convert_non_reference_arg_to_reference);
    // In case both T and U are arithmetic types, enforce that the
    // conversion is not lossy.
    typedef GTEST_REMOVE_REFERENCE_AND_CONST_(T) RawT;
    typedef GTEST_REMOVE_REFERENCE_AND_CONST_(U) RawU;
    const bool kTIsOther = GMOCK_KIND_OF_(RawT) == internal::kOther;
    const bool kUIsOther = GMOCK_KIND_OF_(RawU) == internal::kOther;
    GTEST_COMPILE_ASSERT_(
        kTIsOther || kUIsOther ||
        (internal::LosslessArithmeticConvertible<RawT, RawU>::value),
        conversion_of_arithmetic_types_must_be_lossless);
    return MatcherCast<T>(matcher);
  }
};

template <typename T, typename M>
inline Matcher<T> SafeMatcherCast(const M& polymorphic_matcher) {
  return SafeMatcherCastImpl<T>::Cast(polymorphic_matcher);
}

// A<T>() returns a matcher that matches any value of type T.
template <typename T>
Matcher<T> A();

// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
// and MUST NOT BE USED IN USER CODE!!!
namespace internal {

// If the explanation is not empty, prints it to the ostream.
inline void PrintIfNotEmpty(const std::string& explanation,
                            ::std::ostream* os) {
  if (explanation != "" && os != NULL) {
    *os << ", " << explanation;
  }
}

// Returns true if the given type name is easy to read by a human.
// This is used to decide whether printing the type of a value might
// be helpful.
inline bool IsReadableTypeName(const std::string& type_name) {
  // We consider a type name readable if it's short or doesn't contain
  // a template or function type.
  return (type_name.length() <= 20 ||
          type_name.find_first_of("<(") == std::string::npos);
}

// Matches the value against the given matcher, prints the value and explains
// the match result to the listener. Returns the match result.
// 'listener' must not be NULL.
// Value cannot be passed by const reference, because some matchers take a
// non-const argument.
template <typename Value, typename T>
bool MatchPrintAndExplain(Value& value, const Matcher<T>& matcher,
                          MatchResultListener* listener) {
  if (!listener->IsInterested()) {
    // If the listener is not interested, we do not need to construct the
    // inner explanation.
    return matcher.Matches(value);
  }

  StringMatchResultListener inner_listener;
  const bool match = matcher.MatchAndExplain(value, &inner_listener);

  UniversalPrint(value, listener->stream());
#if GTEST_HAS_RTTI
  const std::string& type_name = GetTypeName<Value>();
  if (IsReadableTypeName(type_name))
    *listener->stream() << " (of type " << type_name << ")";
#endif
  PrintIfNotEmpty(inner_listener.str(), listener->stream());

  return match;
}

// An internal helper class for doing compile-time loop on a tuple's
// fields.
template <size_t N>
class TuplePrefix {
 public:
  // TuplePrefix<N>::Matches(matcher_tuple, value_tuple) returns true
  // iff the first N fields of matcher_tuple matches the first N
  // fields of value_tuple, respectively.
  template <typename MatcherTuple, typename ValueTuple>
  static bool Matches(const MatcherTuple& matcher_tuple,
                      const ValueTuple& value_tuple) {
    return TuplePrefix<N - 1>::Matches(matcher_tuple, value_tuple)
        && get<N - 1>(matcher_tuple).Matches(get<N - 1>(value_tuple));
  }

  // TuplePrefix<N>::ExplainMatchFailuresTo(matchers, values, os)
  // describes failures in matching the first N fields of matchers
  // against the first N fields of values.  If there is no failure,
  // nothing will be streamed to os.
  template <typename MatcherTuple, typename ValueTuple>
  static void ExplainMatchFailuresTo(const MatcherTuple& matchers,
                                     const ValueTuple& values,
                                     ::std::ostream* os) {
    // First, describes failures in the first N - 1 fields.
    TuplePrefix<N - 1>::ExplainMatchFailuresTo(matchers, values, os);

    // Then describes the failure (if any) in the (N - 1)-th (0-based)
    // field.
    typename tuple_element<N - 1, MatcherTuple>::type matcher =
        get<N - 1>(matchers);
    typedef typename tuple_element<N - 1, ValueTuple>::type Value;
    GTEST_REFERENCE_TO_CONST_(Value) value = get<N - 1>(values);
    StringMatchResultListener listener;
    if (!matcher.MatchAndExplain(value, &listener)) {
      // TODO(wan): include in the message the name of the parameter
      // as used in MOCK_METHOD*() when possible.
      *os << "  Expected arg #" << N - 1 << ": ";
      get<N - 1>(matchers).DescribeTo(os);
      *os << "\n           Actual: ";
      // We remove the reference in type Value to prevent the
      // universal printer from printing the address of value, which
      // isn't interesting to the user most of the time.  The
      // matcher's MatchAndExplain() method handles the case when
      // the address is interesting.
      internal::UniversalPrint(value, os);
      PrintIfNotEmpty(listener.str(), os);
      *os << "\n";
    }
  }
};

// The base case.
template <>
class TuplePrefix<0> {
 public:
  template <typename MatcherTuple, typename ValueTuple>
  static bool Matches(const MatcherTuple& /* matcher_tuple */,
                      const ValueTuple& /* value_tuple */) {
    return true;
  }

  template <typename MatcherTuple, typename ValueTuple>
  static void ExplainMatchFailuresTo(const MatcherTuple& /* matchers */,
                                     const ValueTuple& /* values */,
                                     ::std::ostream* /* os */) {}
};

// TupleMatches(matcher_tuple, value_tuple) returns true iff all
// matchers in matcher_tuple match the corresponding fields in
// value_tuple.  It is a compiler error if matcher_tuple and
// value_tuple have different number of fields or incompatible field
// types.
template <typename MatcherTuple, typename ValueTuple>
bool TupleMatches(const MatcherTuple& matcher_tuple,
                  const ValueTuple& value_tuple) {
  // Makes sure that matcher_tuple and value_tuple have the same
  // number of fields.
  GTEST_COMPILE_ASSERT_(tuple_size<MatcherTuple>::value ==
                        tuple_size<ValueTuple>::value,
                        matcher_and_value_have_different_numbers_of_fields);
  return TuplePrefix<tuple_size<ValueTuple>::value>::
      Matches(matcher_tuple, value_tuple);
}

// Describes failures in matching matchers against values.  If there
// is no failure, nothing will be streamed to os.
template <typename MatcherTuple, typename ValueTuple>
void ExplainMatchFailureTupleTo(const MatcherTuple& matchers,
                                const ValueTuple& values,
                                ::std::ostream* os) {
  TuplePrefix<tuple_size<MatcherTuple>::value>::ExplainMatchFailuresTo(
      matchers, values, os);
}

// TransformTupleValues and its helper.
//
// TransformTupleValuesHelper hides the internal machinery that
// TransformTupleValues uses to implement a tuple traversal.
template <typename Tuple, typename Func, typename OutIter>
class TransformTupleValuesHelper {
 private:
  typedef ::testing::tuple_size<Tuple> TupleSize;

 public:
  // For each member of tuple 't', taken in order, evaluates '*out++ = f(t)'.
  // Returns the final value of 'out' in case the caller needs it.
  static OutIter Run(Func f, const Tuple& t, OutIter out) {
    return IterateOverTuple<Tuple, TupleSize::value>()(f, t, out);
  }

 private:
  template <typename Tup, size_t kRemainingSize>
  struct IterateOverTuple {
    OutIter operator() (Func f, const Tup& t, OutIter out) const {
      *out++ = f(::testing::get<TupleSize::value - kRemainingSize>(t));
      return IterateOverTuple<Tup, kRemainingSize - 1>()(f, t, out);
    }
  };
  template <typename Tup>
  struct IterateOverTuple<Tup, 0> {
    OutIter operator() (Func /* f */, const Tup& /* t */, OutIter out) const {
      return out;
    }
  };
};

// Successively invokes 'f(element)' on each element of the tuple 't',
// appending each result to the 'out' iterator. Returns the final value
// of 'out'.
template <typename Tuple, typename Func, typename OutIter>
OutIter TransformTupleValues(Func f, const Tuple& t, OutIter out) {
  return TransformTupleValuesHelper<Tuple, Func, OutIter>::Run(f, t, out);
}

// Implements A<T>().
template <typename T>
class AnyMatcherImpl : public MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)> {
 public:
  virtual bool MatchAndExplain(GTEST_REFERENCE_TO_CONST_(T) /* x */,
                               MatchResultListener* /* listener */) const {
    return true;
  }
  virtual void DescribeTo(::std::ostream* os) const { *os << "is anything"; }
  virtual void DescribeNegationTo(::std::ostream* os) const {
    // This is mostly for completeness' safe, as it's not very useful
    // to write Not(A<bool>()).  However we cannot completely rule out
    // such a possibility, and it doesn't hurt to be prepared.
    *os << "never matches";
  }
};

// Implements _, a matcher that matches any value of any
// type.  This is a polymorphic matcher, so we need a template type
// conversion operator to make it appearing as a Matcher<T> for any
// type T.
class AnythingMatcher {
 public:
  template <typename T>
  operator Matcher<T>() const { return A<T>(); }
};

// Implements a matcher that compares a given value with a
// pre-supplied value using one of the ==, <=, <, etc, operators.  The
// two values being compared don't have to have the same type.
//
// The matcher defined here is polymorphic (for example, Eq(5) can be
// used to match an int, a short, a double, etc).  Therefore we use
// a template type conversion operator in the implementation.
//
// The following template definition assumes that the Rhs parameter is
// a "bare" type (i.e. neither 'const T' nor 'T&').
template <typename D, typename Rhs, typename Op>
class ComparisonBase {
 public:
  explicit ComparisonBase(const Rhs& rhs) : rhs_(rhs) {}
  template <typename Lhs>
  operator Matcher<Lhs>() const {
    return MakeMatcher(new Impl<Lhs>(rhs_));
  }

 private:
  template <typename Lhs>
  class Impl : public MatcherInterface<Lhs> {
   public:
    explicit Impl(const Rhs& rhs) : rhs_(rhs) {}
    virtual bool MatchAndExplain(
        Lhs lhs, MatchResultListener* /* listener */) const {
      return Op()(lhs, rhs_);
    }
    virtual void DescribeTo(::std::ostream* os) const {
      *os << D::Desc() << " ";
      UniversalPrint(rhs_, os);
    }
    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << D::NegatedDesc() <<  " ";
      UniversalPrint(rhs_, os);
    }
   private:
    Rhs rhs_;
    GTEST_DISALLOW_ASSIGN_(Impl);
  };
  Rhs rhs_;
  GTEST_DISALLOW_ASSIGN_(ComparisonBase);
};

template <typename Rhs>
class EqMatcher : public ComparisonBase<EqMatcher<Rhs>, Rhs, AnyEq> {
 public:
  explicit EqMatcher(const Rhs& rhs)
      : ComparisonBase<EqMatcher<Rhs>, Rhs, AnyEq>(rhs) { }
  static const char* Desc() { return "is equal to"; }
  static const char* NegatedDesc() { return "isn't equal to"; }
};
template <typename Rhs>
class NeMatcher : public ComparisonBase<NeMatcher<Rhs>, Rhs, AnyNe> {
 public:
  explicit NeMatcher(const Rhs& rhs)
      : ComparisonBase<NeMatcher<Rhs>, Rhs, AnyNe>(rhs) { }
  static const char* Desc() { return "isn't equal to"; }
  static const char* NegatedDesc() { return "is equal to"; }
};
template <typename Rhs>
class LtMatcher : public ComparisonBase<LtMatcher<Rhs>, Rhs, AnyLt> {
 public:
  explicit LtMatcher(const Rhs& rhs)
      : ComparisonBase<LtMatcher<Rhs>, Rhs, AnyLt>(rhs) { }
  static const char* Desc() { return "is <"; }
  static const char* NegatedDesc() { return "isn't <"; }
};
template <typename Rhs>
class GtMatcher : public ComparisonBase<GtMatcher<Rhs>, Rhs, AnyGt> {
 public:
  explicit GtMatcher(const Rhs& rhs)
      : ComparisonBase<GtMatcher<Rhs>, Rhs, AnyGt>(rhs) { }
  static const char* Desc() { return "is >"; }
  static const char* NegatedDesc() { return "isn't >"; }
};
template <typename Rhs>
class LeMatcher : public ComparisonBase<LeMatcher<Rhs>, Rhs, AnyLe> {
 public:
  explicit LeMatcher(const Rhs& rhs)
      : ComparisonBase<LeMatcher<Rhs>, Rhs, AnyLe>(rhs) { }
  static const char* Desc() { return "is <="; }
  static const char* NegatedDesc() { return "isn't <="; }
};
template <typename Rhs>
class GeMatcher : public ComparisonBase<GeMatcher<Rhs>, Rhs, AnyGe> {
 public:
  explicit GeMatcher(const Rhs& rhs)
      : ComparisonBase<GeMatcher<Rhs>, Rhs, AnyGe>(rhs) { }
  static const char* Desc() { return "is >="; }
  static const char* NegatedDesc() { return "isn't >="; }
};

// Implements the polymorphic IsNull() matcher, which matches any raw or smart
// pointer that is NULL.
class IsNullMatcher {
 public:
  template <typename Pointer>
  bool MatchAndExplain(const Pointer& p,
                       MatchResultListener* /* listener */) const {
#if GTEST_LANG_CXX11
    return p == nullptr;
#else  // GTEST_LANG_CXX11
    return GetRawPointer(p) == NULL;
#endif  // GTEST_LANG_CXX11
  }

  void DescribeTo(::std::ostream* os) const { *os << "is NULL"; }
  void DescribeNegationTo(::std::ostream* os) const {
    *os << "isn't NULL";
  }
};

// Implements the polymorphic NotNull() matcher, which matches any raw or smart
// pointer that is not NULL.
class NotNullMatcher {
 public:
  template <typename Pointer>
  bool MatchAndExplain(const Pointer& p,
                       MatchResultListener* /* listener */) const {
#if GTEST_LANG_CXX11
    return p != nullptr;
#else  // GTEST_LANG_CXX11
    return GetRawPointer(p) != NULL;
#endif  // GTEST_LANG_CXX11
  }

  void DescribeTo(::std::ostream* os) const { *os << "isn't NULL"; }
  void DescribeNegationTo(::std::ostream* os) const {
    *os << "is NULL";
  }
};

// Ref(variable) matches any argument that is a reference to
// 'variable'.  This matcher is polymorphic as it can match any
// super type of the type of 'variable'.
//
// The RefMatcher template class implements Ref(variable).  It can
// only be instantiated with a reference type.  This prevents a user
// from mistakenly using Ref(x) to match a non-reference function
// argument.  For example, the following will righteously cause a
// compiler error:
//
//   int n;
//   Matcher<int> m1 = Ref(n);   // This won't compile.
//   Matcher<int&> m2 = Ref(n);  // This will compile.
template <typename T>
class RefMatcher;

template <typename T>
class RefMatcher<T&> {
  // Google Mock is a generic framework and thus needs to support
  // mocking any function types, including those that take non-const
  // reference arguments.  Therefore the template parameter T (and
  // Super below) can be instantiated to either a const type or a
  // non-const type.
 public:
  // RefMatcher() takes a T& instead of const T&, as we want the
  // compiler to catch using Ref(const_value) as a matcher for a
  // non-const reference.
  explicit RefMatcher(T& x) : object_(x) {}  // NOLINT

  template <typename Super>
  operator Matcher<Super&>() const {
    // By passing object_ (type T&) to Impl(), which expects a Super&,
    // we make sure that Super is a super type of T.  In particular,
    // this catches using Ref(const_value) as a matcher for a
    // non-const reference, as you cannot implicitly convert a const
    // reference to a non-const reference.
    return MakeMatcher(new Impl<Super>(object_));
  }

 private:
  template <typename Super>
  class Impl : public MatcherInterface<Super&> {
   public:
    explicit Impl(Super& x) : object_(x) {}  // NOLINT

    // MatchAndExplain() takes a Super& (as opposed to const Super&)
    // in order to match the interface MatcherInterface<Super&>.
    virtual bool MatchAndExplain(
        Super& x, MatchResultListener* listener) const {
      *listener << "which is located @" << static_cast<const void*>(&x);
      return &x == &object_;
    }

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "references the variable ";
      UniversalPrinter<Super&>::Print(object_, os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "does not reference the variable ";
      UniversalPrinter<Super&>::Print(object_, os);
    }

   private:
    const Super& object_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  T& object_;

  GTEST_DISALLOW_ASSIGN_(RefMatcher);
};

// Polymorphic helper functions for narrow and wide string matchers.
inline bool CaseInsensitiveCStringEquals(const char* lhs, const char* rhs) {
  return String::CaseInsensitiveCStringEquals(lhs, rhs);
}

inline bool CaseInsensitiveCStringEquals(const wchar_t* lhs,
                                         const wchar_t* rhs) {
  return String::CaseInsensitiveWideCStringEquals(lhs, rhs);
}

// String comparison for narrow or wide strings that can have embedded NUL
// characters.
template <typename StringType>
bool CaseInsensitiveStringEquals(const StringType& s1,
                                 const StringType& s2) {
  // Are the heads equal?
  if (!CaseInsensitiveCStringEquals(s1.c_str(), s2.c_str())) {
    return false;
  }

  // Skip the equal heads.
  const typename StringType::value_type nul = 0;
  const size_t i1 = s1.find(nul), i2 = s2.find(nul);

  // Are we at the end of either s1 or s2?
  if (i1 == StringType::npos || i2 == StringType::npos) {
    return i1 == i2;
  }

  // Are the tails equal?
  return CaseInsensitiveStringEquals(s1.substr(i1 + 1), s2.substr(i2 + 1));
}

// String matchers.

// Implements equality-based string matchers like StrEq, StrCaseNe, and etc.
template <typename StringType>
class StrEqualityMatcher {
 public:
  StrEqualityMatcher(const StringType& str, bool expect_eq,
                     bool case_sensitive)
      : string_(str), expect_eq_(expect_eq), case_sensitive_(case_sensitive) {}

#if GTEST_HAS_ABSL
  bool MatchAndExplain(const absl::string_view& s,
                       MatchResultListener* listener) const {
    if (s.data() == NULL) {
      return !expect_eq_;
    }
    // This should fail to compile if absl::string_view is used with wide
    // strings.
    const StringType& str = string(s);
    return MatchAndExplain(str, listener);
  }
#endif  // GTEST_HAS_ABSL

  // Accepts pointer types, particularly:
  //   const char*
  //   char*
  //   const wchar_t*
  //   wchar_t*
  template <typename CharType>
  bool MatchAndExplain(CharType* s, MatchResultListener* listener) const {
    if (s == NULL) {
      return !expect_eq_;
    }
    return MatchAndExplain(StringType(s), listener);
  }

  // Matches anything that can convert to StringType.
  //
  // This is a template, not just a plain function with const StringType&,
  // because absl::string_view has some interfering non-explicit constructors.
  template <typename MatcheeStringType>
  bool MatchAndExplain(const MatcheeStringType& s,
                       MatchResultListener* /* listener */) const {
    const StringType& s2(s);
    const bool eq = case_sensitive_ ? s2 == string_ :
        CaseInsensitiveStringEquals(s2, string_);
    return expect_eq_ == eq;
  }

  void DescribeTo(::std::ostream* os) const {
    DescribeToHelper(expect_eq_, os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    DescribeToHelper(!expect_eq_, os);
  }

 private:
  void DescribeToHelper(bool expect_eq, ::std::ostream* os) const {
    *os << (expect_eq ? "is " : "isn't ");
    *os << "equal to ";
    if (!case_sensitive_) {
      *os << "(ignoring case) ";
    }
    UniversalPrint(string_, os);
  }

  const StringType string_;
  const bool expect_eq_;
  const bool case_sensitive_;

  GTEST_DISALLOW_ASSIGN_(StrEqualityMatcher);
};

// Implements the polymorphic HasSubstr(substring) matcher, which
// can be used as a Matcher<T> as long as T can be converted to a
// string.
template <typename StringType>
class HasSubstrMatcher {
 public:
  explicit HasSubstrMatcher(const StringType& substring)
      : substring_(substring) {}

#if GTEST_HAS_ABSL
  bool MatchAndExplain(const absl::string_view& s,
                       MatchResultListener* listener) const {
    if (s.data() == NULL) {
      return false;
    }
    // This should fail to compile if absl::string_view is used with wide
    // strings.
    const StringType& str = string(s);
    return MatchAndExplain(str, listener);
  }
#endif  // GTEST_HAS_ABSL

  // Accepts pointer types, particularly:
  //   const char*
  //   char*
  //   const wchar_t*
  //   wchar_t*
  template <typename CharType>
  bool MatchAndExplain(CharType* s, MatchResultListener* listener) const {
    return s != NULL && MatchAndExplain(StringType(s), listener);
  }

  // Matches anything that can convert to StringType.
  //
  // This is a template, not just a plain function with const StringType&,
  // because absl::string_view has some interfering non-explicit constructors.
  template <typename MatcheeStringType>
  bool MatchAndExplain(const MatcheeStringType& s,
                       MatchResultListener* /* listener */) const {
    const StringType& s2(s);
    return s2.find(substring_) != StringType::npos;
  }

  // Describes what this matcher matches.
  void DescribeTo(::std::ostream* os) const {
    *os << "has substring ";
    UniversalPrint(substring_, os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "has no substring ";
    UniversalPrint(substring_, os);
  }

 private:
  const StringType substring_;

  GTEST_DISALLOW_ASSIGN_(HasSubstrMatcher);
};

// Implements the polymorphic StartsWith(substring) matcher, which
// can be used as a Matcher<T> as long as T can be converted to a
// string.
template <typename StringType>
class StartsWithMatcher {
 public:
  explicit StartsWithMatcher(const StringType& prefix) : prefix_(prefix) {
  }

#if GTEST_HAS_ABSL
  bool MatchAndExplain(const absl::string_view& s,
                       MatchResultListener* listener) const {
    if (s.data() == NULL) {
      return false;
    }
    // This should fail to compile if absl::string_view is used with wide
    // strings.
    const StringType& str = string(s);
    return MatchAndExplain(str, listener);
  }
#endif  // GTEST_HAS_ABSL

  // Accepts pointer types, particularly:
  //   const char*
  //   char*
  //   const wchar_t*
  //   wchar_t*
  template <typename CharType>
  bool MatchAndExplain(CharType* s, MatchResultListener* listener) const {
    return s != NULL && MatchAndExplain(StringType(s), listener);
  }

  // Matches anything that can convert to StringType.
  //
  // This is a template, not just a plain function with const StringType&,
  // because absl::string_view has some interfering non-explicit constructors.
  template <typename MatcheeStringType>
  bool MatchAndExplain(const MatcheeStringType& s,
                       MatchResultListener* /* listener */) const {
    const StringType& s2(s);
    return s2.length() >= prefix_.length() &&
        s2.substr(0, prefix_.length()) == prefix_;
  }

  void DescribeTo(::std::ostream* os) const {
    *os << "starts with ";
    UniversalPrint(prefix_, os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "doesn't start with ";
    UniversalPrint(prefix_, os);
  }

 private:
  const StringType prefix_;

  GTEST_DISALLOW_ASSIGN_(StartsWithMatcher);
};

// Implements the polymorphic EndsWith(substring) matcher, which
// can be used as a Matcher<T> as long as T can be converted to a
// string.
template <typename StringType>
class EndsWithMatcher {
 public:
  explicit EndsWithMatcher(const StringType& suffix) : suffix_(suffix) {}

#if GTEST_HAS_ABSL
  bool MatchAndExplain(const absl::string_view& s,
                       MatchResultListener* listener) const {
    if (s.data() == NULL) {
      return false;
    }
    // This should fail to compile if absl::string_view is used with wide
    // strings.
    const StringType& str = string(s);
    return MatchAndExplain(str, listener);
  }
#endif  // GTEST_HAS_ABSL

  // Accepts pointer types, particularly:
  //   const char*
  //   char*
  //   const wchar_t*
  //   wchar_t*
  template <typename CharType>
  bool MatchAndExplain(CharType* s, MatchResultListener* listener) const {
    return s != NULL && MatchAndExplain(StringType(s), listener);
  }

  // Matches anything that can convert to StringType.
  //
  // This is a template, not just a plain function with const StringType&,
  // because absl::string_view has some interfering non-explicit constructors.
  template <typename MatcheeStringType>
  bool MatchAndExplain(const MatcheeStringType& s,
                       MatchResultListener* /* listener */) const {
    const StringType& s2(s);
    return s2.length() >= suffix_.length() &&
        s2.substr(s2.length() - suffix_.length()) == suffix_;
  }

  void DescribeTo(::std::ostream* os) const {
    *os << "ends with ";
    UniversalPrint(suffix_, os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "doesn't end with ";
    UniversalPrint(suffix_, os);
  }

 private:
  const StringType suffix_;

  GTEST_DISALLOW_ASSIGN_(EndsWithMatcher);
};

// Implements polymorphic matchers MatchesRegex(regex) and
// ContainsRegex(regex), which can be used as a Matcher<T> as long as
// T can be converted to a string.
class MatchesRegexMatcher {
 public:
  MatchesRegexMatcher(const RE* regex, bool full_match)
      : regex_(regex), full_match_(full_match) {}

#if GTEST_HAS_ABSL
  bool MatchAndExplain(const absl::string_view& s,
                       MatchResultListener* listener) const {
    return s.data() && MatchAndExplain(string(s), listener);
  }
#endif  // GTEST_HAS_ABSL

  // Accepts pointer types, particularly:
  //   const char*
  //   char*
  //   const wchar_t*
  //   wchar_t*
  template <typename CharType>
  bool MatchAndExplain(CharType* s, MatchResultListener* listener) const {
    return s != NULL && MatchAndExplain(std::string(s), listener);
  }

  // Matches anything that can convert to std::string.
  //
  // This is a template, not just a plain function with const std::string&,
  // because absl::string_view has some interfering non-explicit constructors.
  template <class MatcheeStringType>
  bool MatchAndExplain(const MatcheeStringType& s,
                       MatchResultListener* /* listener */) const {
    const std::string& s2(s);
    return full_match_ ? RE::FullMatch(s2, *regex_) :
        RE::PartialMatch(s2, *regex_);
  }

  void DescribeTo(::std::ostream* os) const {
    *os << (full_match_ ? "matches" : "contains")
        << " regular expression ";
    UniversalPrinter<std::string>::Print(regex_->pattern(), os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "doesn't " << (full_match_ ? "match" : "contain")
        << " regular expression ";
    UniversalPrinter<std::string>::Print(regex_->pattern(), os);
  }

 private:
  const internal::linked_ptr<const RE> regex_;
  const bool full_match_;

  GTEST_DISALLOW_ASSIGN_(MatchesRegexMatcher);
};

// Implements a matcher that compares the two fields of a 2-tuple
// using one of the ==, <=, <, etc, operators.  The two fields being
// compared don't have to have the same type.
//
// The matcher defined here is polymorphic (for example, Eq() can be
// used to match a tuple<int, short>, a tuple<const long&, double>,
// etc).  Therefore we use a template type conversion operator in the
// implementation.
template <typename D, typename Op>
class PairMatchBase {
 public:
  template <typename T1, typename T2>
  operator Matcher< ::testing::tuple<T1, T2> >() const {
    return MakeMatcher(new Impl< ::testing::tuple<T1, T2> >);
  }
  template <typename T1, typename T2>
  operator Matcher<const ::testing::tuple<T1, T2>&>() const {
    return MakeMatcher(new Impl<const ::testing::tuple<T1, T2>&>);
  }

 private:
  static ::std::ostream& GetDesc(::std::ostream& os) {  // NOLINT
    return os << D::Desc();
  }

  template <typename Tuple>
  class Impl : public MatcherInterface<Tuple> {
   public:
    virtual bool MatchAndExplain(
        Tuple args,
        MatchResultListener* /* listener */) const {
      return Op()(::testing::get<0>(args), ::testing::get<1>(args));
    }
    virtual void DescribeTo(::std::ostream* os) const {
      *os << "are " << GetDesc;
    }
    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "aren't " << GetDesc;
    }
  };
};

class Eq2Matcher : public PairMatchBase<Eq2Matcher, AnyEq> {
 public:
  static const char* Desc() { return "an equal pair"; }
};
class Ne2Matcher : public PairMatchBase<Ne2Matcher, AnyNe> {
 public:
  static const char* Desc() { return "an unequal pair"; }
};
class Lt2Matcher : public PairMatchBase<Lt2Matcher, AnyLt> {
 public:
  static const char* Desc() { return "a pair where the first < the second"; }
};
class Gt2Matcher : public PairMatchBase<Gt2Matcher, AnyGt> {
 public:
  static const char* Desc() { return "a pair where the first > the second"; }
};
class Le2Matcher : public PairMatchBase<Le2Matcher, AnyLe> {
 public:
  static const char* Desc() { return "a pair where the first <= the second"; }
};
class Ge2Matcher : public PairMatchBase<Ge2Matcher, AnyGe> {
 public:
  static const char* Desc() { return "a pair where the first >= the second"; }
};

// Implements the Not(...) matcher for a particular argument type T.
// We do not nest it inside the NotMatcher class template, as that
// will prevent different instantiations of NotMatcher from sharing
// the same NotMatcherImpl<T> class.
template <typename T>
class NotMatcherImpl : public MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)> {
 public:
  explicit NotMatcherImpl(const Matcher<T>& matcher)
      : matcher_(matcher) {}

  virtual bool MatchAndExplain(GTEST_REFERENCE_TO_CONST_(T) x,
                               MatchResultListener* listener) const {
    return !matcher_.MatchAndExplain(x, listener);
  }

  virtual void DescribeTo(::std::ostream* os) const {
    matcher_.DescribeNegationTo(os);
  }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    matcher_.DescribeTo(os);
  }

 private:
  const Matcher<T> matcher_;

  GTEST_DISALLOW_ASSIGN_(NotMatcherImpl);
};

// Implements the Not(m) matcher, which matches a value that doesn't
// match matcher m.
template <typename InnerMatcher>
class NotMatcher {
 public:
  explicit NotMatcher(InnerMatcher matcher) : matcher_(matcher) {}

  // This template type conversion operator allows Not(m) to be used
  // to match any type m can match.
  template <typename T>
  operator Matcher<T>() const {
    return Matcher<T>(new NotMatcherImpl<T>(SafeMatcherCast<T>(matcher_)));
  }

 private:
  InnerMatcher matcher_;

  GTEST_DISALLOW_ASSIGN_(NotMatcher);
};

// Implements the AllOf(m1, m2) matcher for a particular argument type
// T. We do not nest it inside the BothOfMatcher class template, as
// that will prevent different instantiations of BothOfMatcher from
// sharing the same BothOfMatcherImpl<T> class.
template <typename T>
class AllOfMatcherImpl
    : public MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)> {
 public:
  explicit AllOfMatcherImpl(std::vector<Matcher<T> > matchers)
      : matchers_(internal::move(matchers)) {}

  virtual void DescribeTo(::std::ostream* os) const {
    *os << "(";
    for (size_t i = 0; i < matchers_.size(); ++i) {
      if (i != 0) *os << ") and (";
      matchers_[i].DescribeTo(os);
    }
    *os << ")";
  }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "(";
    for (size_t i = 0; i < matchers_.size(); ++i) {
      if (i != 0) *os << ") or (";
      matchers_[i].DescribeNegationTo(os);
    }
    *os << ")";
  }

  virtual bool MatchAndExplain(GTEST_REFERENCE_TO_CONST_(T) x,
                               MatchResultListener* listener) const {
    // If either matcher1_ or matcher2_ doesn't match x, we only need
    // to explain why one of them fails.
    std::string all_match_result;

    for (size_t i = 0; i < matchers_.size(); ++i) {
      StringMatchResultListener slistener;
      if (matchers_[i].MatchAndExplain(x, &slistener)) {
        if (all_match_result.empty()) {
          all_match_result = slistener.str();
        } else {
          std::string result = slistener.str();
          if (!result.empty()) {
            all_match_result += ", and ";
            all_match_result += result;
          }
        }
      } else {
        *listener << slistener.str();
        return false;
      }
    }

    // Otherwise we need to explain why *both* of them match.
    *listener << all_match_result;
    return true;
  }

 private:
  const std::vector<Matcher<T> > matchers_;

  GTEST_DISALLOW_ASSIGN_(AllOfMatcherImpl);
};

#if GTEST_LANG_CXX11
// VariadicMatcher is used for the variadic implementation of
// AllOf(m_1, m_2, ...) and AnyOf(m_1, m_2, ...).
// CombiningMatcher<T> is used to recursively combine the provided matchers
// (of type Args...).
template <template <typename T> class CombiningMatcher, typename... Args>
class VariadicMatcher {
 public:
  VariadicMatcher(const Args&... matchers)  // NOLINT
      : matchers_(matchers...) {
    static_assert(sizeof...(Args) > 0, "Must have at least one matcher.");
  }

  // This template type conversion operator allows an
  // VariadicMatcher<Matcher1, Matcher2...> object to match any type that
  // all of the provided matchers (Matcher1, Matcher2, ...) can match.
  template <typename T>
  operator Matcher<T>() const {
    std::vector<Matcher<T> > values;
    CreateVariadicMatcher<T>(&values, std::integral_constant<size_t, 0>());
    return Matcher<T>(new CombiningMatcher<T>(internal::move(values)));
  }

 private:
  template <typename T, size_t I>
  void CreateVariadicMatcher(std::vector<Matcher<T> >* values,
                             std::integral_constant<size_t, I>) const {
    values->push_back(SafeMatcherCast<T>(std::get<I>(matchers_)));
    CreateVariadicMatcher<T>(values, std::integral_constant<size_t, I + 1>());
  }

  template <typename T>
  void CreateVariadicMatcher(
      std::vector<Matcher<T> >*,
      std::integral_constant<size_t, sizeof...(Args)>) const {}

  tuple<Args...> matchers_;

  GTEST_DISALLOW_ASSIGN_(VariadicMatcher);
};

template <typename... Args>
using AllOfMatcher = VariadicMatcher<AllOfMatcherImpl, Args...>;

#endif  // GTEST_LANG_CXX11

// Used for implementing the AllOf(m_1, ..., m_n) matcher, which
// matches a value that matches all of the matchers m_1, ..., and m_n.
template <typename Matcher1, typename Matcher2>
class BothOfMatcher {
 public:
  BothOfMatcher(Matcher1 matcher1, Matcher2 matcher2)
      : matcher1_(matcher1), matcher2_(matcher2) {}

  // This template type conversion operator allows a
  // BothOfMatcher<Matcher1, Matcher2> object to match any type that
  // both Matcher1 and Matcher2 can match.
  template <typename T>
  operator Matcher<T>() const {
    std::vector<Matcher<T> > values;
    values.push_back(SafeMatcherCast<T>(matcher1_));
    values.push_back(SafeMatcherCast<T>(matcher2_));
    return Matcher<T>(new AllOfMatcherImpl<T>(internal::move(values)));
  }

 private:
  Matcher1 matcher1_;
  Matcher2 matcher2_;

  GTEST_DISALLOW_ASSIGN_(BothOfMatcher);
};

// Implements the AnyOf(m1, m2) matcher for a particular argument type
// T.  We do not nest it inside the AnyOfMatcher class template, as
// that will prevent different instantiations of AnyOfMatcher from
// sharing the same EitherOfMatcherImpl<T> class.
template <typename T>
class AnyOfMatcherImpl
    : public MatcherInterface<GTEST_REFERENCE_TO_CONST_(T)> {
 public:
  explicit AnyOfMatcherImpl(std::vector<Matcher<T> > matchers)
      : matchers_(internal::move(matchers)) {}

  virtual void DescribeTo(::std::ostream* os) const {
    *os << "(";
    for (size_t i = 0; i < matchers_.size(); ++i) {
      if (i != 0) *os << ") or (";
      matchers_[i].DescribeTo(os);
    }
    *os << ")";
  }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "(";
    for (size_t i = 0; i < matchers_.size(); ++i) {
      if (i != 0) *os << ") and (";
      matchers_[i].DescribeNegationTo(os);
    }
    *os << ")";
  }

  virtual bool MatchAndExplain(GTEST_REFERENCE_TO_CONST_(T) x,
                               MatchResultListener* listener) const {
    std::string no_match_result;

    // If either matcher1_ or matcher2_ matches x, we just need to
    // explain why *one* of them matches.
    for (size_t i = 0; i < matchers_.size(); ++i) {
      StringMatchResultListener slistener;
      if (matchers_[i].MatchAndExplain(x, &slistener)) {
        *listener << slistener.str();
        return true;
      } else {
        if (no_match_result.empty()) {
          no_match_result = slistener.str();
        } else {
          std::string result = slistener.str();
          if (!result.empty()) {
            no_match_result += ", and ";
            no_match_result += result;
          }
        }
      }
    }

    // Otherwise we need to explain why *both* of them fail.
    *listener << no_match_result;
    return false;
  }

 private:
  const std::vector<Matcher<T> > matchers_;

  GTEST_DISALLOW_ASSIGN_(AnyOfMatcherImpl);
};

#if GTEST_LANG_CXX11
// AnyOfMatcher is used for the variadic implementation of AnyOf(m_1, m_2, ...).
template <typename... Args>
using AnyOfMatcher = VariadicMatcher<AnyOfMatcherImpl, Args...>;

#endif  // GTEST_LANG_CXX11

// Used for implementing the AnyOf(m_1, ..., m_n) matcher, which
// matches a value that matches at least one of the matchers m_1, ...,
// and m_n.
template <typename Matcher1, typename Matcher2>
class EitherOfMatcher {
 public:
  EitherOfMatcher(Matcher1 matcher1, Matcher2 matcher2)
      : matcher1_(matcher1), matcher2_(matcher2) {}

  // This template type conversion operator allows a
  // EitherOfMatcher<Matcher1, Matcher2> object to match any type that
  // both Matcher1 and Matcher2 can match.
  template <typename T>
  operator Matcher<T>() const {
    std::vector<Matcher<T> > values;
    values.push_back(SafeMatcherCast<T>(matcher1_));
    values.push_back(SafeMatcherCast<T>(matcher2_));
    return Matcher<T>(new AnyOfMatcherImpl<T>(internal::move(values)));
  }

 private:
  Matcher1 matcher1_;
  Matcher2 matcher2_;

  GTEST_DISALLOW_ASSIGN_(EitherOfMatcher);
};

// Used for implementing Truly(pred), which turns a predicate into a
// matcher.
template <typename Predicate>
class TrulyMatcher {
 public:
  explicit TrulyMatcher(Predicate pred) : predicate_(pred) {}

  // This method template allows Truly(pred) to be used as a matcher
  // for type T where T is the argument type of predicate 'pred'.  The
  // argument is passed by reference as the predicate may be
  // interested in the address of the argument.
  template <typename T>
  bool MatchAndExplain(T& x,  // NOLINT
                       MatchResultListener* /* listener */) const {
    // Without the if-statement, MSVC sometimes warns about converting
    // a value to bool (warning 4800).
    //
    // We cannot write 'return !!predicate_(x);' as that doesn't work
    // when predicate_(x) returns a class convertible to bool but
    // having no operator!().
    if (predicate_(x))
      return true;
    return false;
  }

  void DescribeTo(::std::ostream* os) const {
    *os << "satisfies the given predicate";
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "doesn't satisfy the given predicate";
  }

 private:
  Predicate predicate_;

  GTEST_DISALLOW_ASSIGN_(TrulyMatcher);
};

// Used for implementing Matches(matcher), which turns a matcher into
// a predicate.
template <typename M>
class MatcherAsPredicate {
 public:
  explicit MatcherAsPredicate(M matcher) : matcher_(matcher) {}

  // This template operator() allows Matches(m) to be used as a
  // predicate on type T where m is a matcher on type T.
  //
  // The argument x is passed by reference instead of by value, as
  // some matcher may be interested in its address (e.g. as in
  // Matches(Ref(n))(x)).
  template <typename T>
  bool operator()(const T& x) const {
    // We let matcher_ commit to a particular type here instead of
    // when the MatcherAsPredicate object was constructed.  This
    // allows us to write Matches(m) where m is a polymorphic matcher
    // (e.g. Eq(5)).
    //
    // If we write Matcher<T>(matcher_).Matches(x) here, it won't
    // compile when matcher_ has type Matcher<const T&>; if we write
    // Matcher<const T&>(matcher_).Matches(x) here, it won't compile
    // when matcher_ has type Matcher<T>; if we just write
    // matcher_.Matches(x), it won't compile when matcher_ is
    // polymorphic, e.g. Eq(5).
    //
    // MatcherCast<const T&>() is necessary for making the code work
    // in all of the above situations.
    return MatcherCast<const T&>(matcher_).Matches(x);
  }

 private:
  M matcher_;

  GTEST_DISALLOW_ASSIGN_(MatcherAsPredicate);
};

// For implementing ASSERT_THAT() and EXPECT_THAT().  The template
// argument M must be a type that can be converted to a matcher.
template <typename M>
class PredicateFormatterFromMatcher {
 public:
  explicit PredicateFormatterFromMatcher(M m) : matcher_(internal::move(m)) {}

  // This template () operator allows a PredicateFormatterFromMatcher
  // object to act as a predicate-formatter suitable for using with
  // Google Test's EXPECT_PRED_FORMAT1() macro.
  template <typename T>
  AssertionResult operator()(const char* value_text, const T& x) const {
    // We convert matcher_ to a Matcher<const T&> *now* instead of
    // when the PredicateFormatterFromMatcher object was constructed,
    // as matcher_ may be polymorphic (e.g. NotNull()) and we won't
    // know which type to instantiate it to until we actually see the
    // type of x here.
    //
    // We write SafeMatcherCast<const T&>(matcher_) instead of
    // Matcher<const T&>(matcher_), as the latter won't compile when
    // matcher_ has type Matcher<T> (e.g. An<int>()).
    // We don't write MatcherCast<const T&> either, as that allows
    // potentially unsafe downcasting of the matcher argument.
    const Matcher<const T&> matcher = SafeMatcherCast<const T&>(matcher_);
    StringMatchResultListener listener;
    if (MatchPrintAndExplain(x, matcher, &listener))
      return AssertionSuccess();

    ::std::stringstream ss;
    ss << "Value of: " << value_text << "\n"
       << "Expected: ";
    matcher.DescribeTo(&ss);
    ss << "\n  Actual: " << listener.str();
    return AssertionFailure() << ss.str();
  }

 private:
  const M matcher_;

  GTEST_DISALLOW_ASSIGN_(PredicateFormatterFromMatcher);
};

// A helper function for converting a matcher to a predicate-formatter
// without the user needing to explicitly write the type.  This is
// used for implementing ASSERT_THAT() and EXPECT_THAT().
// Implementation detail: 'matcher' is received by-value to force decaying.
template <typename M>
inline PredicateFormatterFromMatcher<M>
MakePredicateFormatterFromMatcher(M matcher) {
  return PredicateFormatterFromMatcher<M>(internal::move(matcher));
}

// Implements the polymorphic floating point equality matcher, which matches
// two float values using ULP-based approximation or, optionally, a
// user-specified epsilon.  The template is meant to be instantiated with
// FloatType being either float or double.
template <typename FloatType>
class FloatingEqMatcher {
 public:
  // Constructor for FloatingEqMatcher.
  // The matcher's input will be compared with expected.  The matcher treats two
  // NANs as equal if nan_eq_nan is true.  Otherwise, under IEEE standards,
  // equality comparisons between NANs will always return false.  We specify a
  // negative max_abs_error_ term to indicate that ULP-based approximation will
  // be used for comparison.
  FloatingEqMatcher(FloatType expected, bool nan_eq_nan) :
    expected_(expected), nan_eq_nan_(nan_eq_nan), max_abs_error_(-1) {
  }

  // Constructor that supports a user-specified max_abs_error that will be used
  // for comparison instead of ULP-based approximation.  The max absolute
  // should be non-negative.
  FloatingEqMatcher(FloatType expected, bool nan_eq_nan,
                    FloatType max_abs_error)
      : expected_(expected),
        nan_eq_nan_(nan_eq_nan),
        max_abs_error_(max_abs_error) {
    GTEST_CHECK_(max_abs_error >= 0)
        << ", where max_abs_error is" << max_abs_error;
  }

  // Implements floating point equality matcher as a Matcher<T>.
  template <typename T>
  class Impl : public MatcherInterface<T> {
   public:
    Impl(FloatType expected, bool nan_eq_nan, FloatType max_abs_error)
        : expected_(expected),
          nan_eq_nan_(nan_eq_nan),
          max_abs_error_(max_abs_error) {}

    virtual bool MatchAndExplain(T value,
                                 MatchResultListener* listener) const {
      const FloatingPoint<FloatType> actual(value), expected(expected_);

      // Compares NaNs first, if nan_eq_nan_ is true.
      if (actual.is_nan() || expected.is_nan()) {
        if (actual.is_nan() && expected.is_nan()) {
          return nan_eq_nan_;
        }
        // One is nan; the other is not nan.
        return false;
      }
      if (HasMaxAbsError()) {
        // We perform an equality check so that inf will match inf, regardless
        // of error bounds.  If the result of value - expected_ would result in
        // overflow or if either value is inf, the default result is infinity,
        // which should only match if max_abs_error_ is also infinity.
        if (value == expected_) {
          return true;
        }

        const FloatType diff = value - expected_;
        if (fabs(diff) <= max_abs_error_) {
          return true;
        }

        if (listener->IsInterested()) {
          *listener << "which is " << diff << " from " << expected_;
        }
        return false;
      } else {
        return actual.AlmostEquals(expected);
      }
    }

    virtual void DescribeTo(::std::ostream* os) const {
      // os->precision() returns the previously set precision, which we
      // store to restore the ostream to its original configuration
      // after outputting.
      const ::std::streamsize old_precision = os->precision(
          ::std::numeric_limits<FloatType>::digits10 + 2);
      if (FloatingPoint<FloatType>(expected_).is_nan()) {
        if (nan_eq_nan_) {
          *os << "is NaN";
        } else {
          *os << "never matches";
        }
      } else {
        *os << "is approximately " << expected_;
        if (HasMaxAbsError()) {
          *os << " (absolute error <= " << max_abs_error_ << ")";
        }
      }
      os->precision(old_precision);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      // As before, get original precision.
      const ::std::streamsize old_precision = os->precision(
          ::std::numeric_limits<FloatType>::digits10 + 2);
      if (FloatingPoint<FloatType>(expected_).is_nan()) {
        if (nan_eq_nan_) {
          *os << "isn't NaN";
        } else {
          *os << "is anything";
        }
      } else {
        *os << "isn't approximately " << expected_;
        if (HasMaxAbsError()) {
          *os << " (absolute error > " << max_abs_error_ << ")";
        }
      }
      // Restore original precision.
      os->precision(old_precision);
    }

   private:
    bool HasMaxAbsError() const {
      return max_abs_error_ >= 0;
    }

    const FloatType expected_;
    const bool nan_eq_nan_;
    // max_abs_error will be used for value comparison when >= 0.
    const FloatType max_abs_error_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  // The following 3 type conversion operators allow FloatEq(expected) and
  // NanSensitiveFloatEq(expected) to be used as a Matcher<float>, a
  // Matcher<const float&>, or a Matcher<float&>, but nothing else.
  // (While Google's C++ coding style doesn't allow arguments passed
  // by non-const reference, we may see them in code not conforming to
  // the style.  Therefore Google Mock needs to support them.)
  operator Matcher<FloatType>() const {
    return MakeMatcher(
        new Impl<FloatType>(expected_, nan_eq_nan_, max_abs_error_));
  }

  operator Matcher<const FloatType&>() const {
    return MakeMatcher(
        new Impl<const FloatType&>(expected_, nan_eq_nan_, max_abs_error_));
  }

  operator Matcher<FloatType&>() const {
    return MakeMatcher(
        new Impl<FloatType&>(expected_, nan_eq_nan_, max_abs_error_));
  }

 private:
  const FloatType expected_;
  const bool nan_eq_nan_;
  // max_abs_error will be used for value comparison when >= 0.
  const FloatType max_abs_error_;

  GTEST_DISALLOW_ASSIGN_(FloatingEqMatcher);
};

// A 2-tuple ("binary") wrapper around FloatingEqMatcher:
// FloatingEq2Matcher() matches (x, y) by matching FloatingEqMatcher(x, false)
// against y, and FloatingEq2Matcher(e) matches FloatingEqMatcher(x, false, e)
// against y. The former implements "Eq", the latter "Near". At present, there
// is no version that compares NaNs as equal.
template <typename FloatType>
class FloatingEq2Matcher {
 public:
  FloatingEq2Matcher() { Init(-1, false); }

  explicit FloatingEq2Matcher(bool nan_eq_nan) { Init(-1, nan_eq_nan); }

  explicit FloatingEq2Matcher(FloatType max_abs_error) {
    Init(max_abs_error, false);
  }

  FloatingEq2Matcher(FloatType max_abs_error, bool nan_eq_nan) {
    Init(max_abs_error, nan_eq_nan);
  }

  template <typename T1, typename T2>
  operator Matcher< ::testing::tuple<T1, T2> >() const {
    return MakeMatcher(
        new Impl< ::testing::tuple<T1, T2> >(max_abs_error_, nan_eq_nan_));
  }
  template <typename T1, typename T2>
  operator Matcher<const ::testing::tuple<T1, T2>&>() const {
    return MakeMatcher(
        new Impl<const ::testing::tuple<T1, T2>&>(max_abs_error_, nan_eq_nan_));
  }

 private:
  static ::std::ostream& GetDesc(::std::ostream& os) {  // NOLINT
    return os << "an almost-equal pair";
  }

  template <typename Tuple>
  class Impl : public MatcherInterface<Tuple> {
   public:
    Impl(FloatType max_abs_error, bool nan_eq_nan) :
        max_abs_error_(max_abs_error),
        nan_eq_nan_(nan_eq_nan) {}

    virtual bool MatchAndExplain(Tuple args,
                                 MatchResultListener* listener) const {
      if (max_abs_error_ == -1) {
        FloatingEqMatcher<FloatType> fm(::testing::get<0>(args), nan_eq_nan_);
        return static_cast<Matcher<FloatType> >(fm).MatchAndExplain(
            ::testing::get<1>(args), listener);
      } else {
        FloatingEqMatcher<FloatType> fm(::testing::get<0>(args), nan_eq_nan_,
                                        max_abs_error_);
        return static_cast<Matcher<FloatType> >(fm).MatchAndExplain(
            ::testing::get<1>(args), listener);
      }
    }
    virtual void DescribeTo(::std::ostream* os) const {
      *os << "are " << GetDesc;
    }
    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "aren't " << GetDesc;
    }

   private:
    FloatType max_abs_error_;
    const bool nan_eq_nan_;
  };

  void Init(FloatType max_abs_error_val, bool nan_eq_nan_val) {
    max_abs_error_ = max_abs_error_val;
    nan_eq_nan_ = nan_eq_nan_val;
  }
  FloatType max_abs_error_;
  bool nan_eq_nan_;
};

// Implements the Pointee(m) matcher for matching a pointer whose
// pointee matches matcher m.  The pointer can be either raw or smart.
template <typename InnerMatcher>
class PointeeMatcher {
 public:
  explicit PointeeMatcher(const InnerMatcher& matcher) : matcher_(matcher) {}

  // This type conversion operator template allows Pointee(m) to be
  // used as a matcher for any pointer type whose pointee type is
  // compatible with the inner matcher, where type Pointer can be
  // either a raw pointer or a smart pointer.
  //
  // The reason we do this instead of relying on
  // MakePolymorphicMatcher() is that the latter is not flexible
  // enough for implementing the DescribeTo() method of Pointee().
  template <typename Pointer>
  operator Matcher<Pointer>() const {
    return Matcher<Pointer>(
        new Impl<GTEST_REFERENCE_TO_CONST_(Pointer)>(matcher_));
  }

 private:
  // The monomorphic implementation that works for a particular pointer type.
  template <typename Pointer>
  class Impl : public MatcherInterface<Pointer> {
   public:
    typedef typename PointeeOf<GTEST_REMOVE_CONST_(  // NOLINT
        GTEST_REMOVE_REFERENCE_(Pointer))>::type Pointee;

    explicit Impl(const InnerMatcher& matcher)
        : matcher_(MatcherCast<const Pointee&>(matcher)) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "points to a value that ";
      matcher_.DescribeTo(os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "does not point to a value that ";
      matcher_.DescribeTo(os);
    }

    virtual bool MatchAndExplain(Pointer pointer,
                                 MatchResultListener* listener) const {
      if (GetRawPointer(pointer) == NULL)
        return false;

      *listener << "which points to ";
      return MatchPrintAndExplain(*pointer, matcher_, listener);
    }

   private:
    const Matcher<const Pointee&> matcher_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  const InnerMatcher matcher_;

  GTEST_DISALLOW_ASSIGN_(PointeeMatcher);
};

#if GTEST_HAS_RTTI
// Implements the WhenDynamicCastTo<T>(m) matcher that matches a pointer or
// reference that matches inner_matcher when dynamic_cast<T> is applied.
// The result of dynamic_cast<To> is forwarded to the inner matcher.
// If To is a pointer and the cast fails, the inner matcher will receive NULL.
// If To is a reference and the cast fails, this matcher returns false
// immediately.
template <typename To>
class WhenDynamicCastToMatcherBase {
 public:
  explicit WhenDynamicCastToMatcherBase(const Matcher<To>& matcher)
      : matcher_(matcher) {}

  void DescribeTo(::std::ostream* os) const {
    GetCastTypeDescription(os);
    matcher_.DescribeTo(os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    GetCastTypeDescription(os);
    matcher_.DescribeNegationTo(os);
  }

 protected:
  const Matcher<To> matcher_;

  static std::string GetToName() {
    return GetTypeName<To>();
  }

 private:
  static void GetCastTypeDescription(::std::ostream* os) {
    *os << "when dynamic_cast to " << GetToName() << ", ";
  }

  GTEST_DISALLOW_ASSIGN_(WhenDynamicCastToMatcherBase);
};

// Primary template.
// To is a pointer. Cast and forward the result.
template <typename To>
class WhenDynamicCastToMatcher : public WhenDynamicCastToMatcherBase<To> {
 public:
  explicit WhenDynamicCastToMatcher(const Matcher<To>& matcher)
      : WhenDynamicCastToMatcherBase<To>(matcher) {}

  template <typename From>
  bool MatchAndExplain(From from, MatchResultListener* listener) const {
    // TODO(sbenza): Add more detail on failures. ie did the dyn_cast fail?
    To to = dynamic_cast<To>(from);
    return MatchPrintAndExplain(to, this->matcher_, listener);
  }
};

// Specialize for references.
// In this case we return false if the dynamic_cast fails.
template <typename To>
class WhenDynamicCastToMatcher<To&> : public WhenDynamicCastToMatcherBase<To&> {
 public:
  explicit WhenDynamicCastToMatcher(const Matcher<To&>& matcher)
      : WhenDynamicCastToMatcherBase<To&>(matcher) {}

  template <typename From>
  bool MatchAndExplain(From& from, MatchResultListener* listener) const {
    // We don't want an std::bad_cast here, so do the cast with pointers.
    To* to = dynamic_cast<To*>(&from);
    if (to == NULL) {
      *listener << "which cannot be dynamic_cast to " << this->GetToName();
      return false;
    }
    return MatchPrintAndExplain(*to, this->matcher_, listener);
  }
};
#endif  // GTEST_HAS_RTTI

// Implements the Field() matcher for matching a field (i.e. member
// variable) of an object.
template <typename Class, typename FieldType>
class FieldMatcher {
 public:
  FieldMatcher(FieldType Class::*field,
               const Matcher<const FieldType&>& matcher)
      : field_(field), matcher_(matcher), whose_field_("whose given field ") {}

  FieldMatcher(const std::string& field_name, FieldType Class::*field,
               const Matcher<const FieldType&>& matcher)
      : field_(field),
        matcher_(matcher),
        whose_field_("whose field `" + field_name + "` ") {}

  void DescribeTo(::std::ostream* os) const {
    *os << "is an object " << whose_field_;
    matcher_.DescribeTo(os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "is an object " << whose_field_;
    matcher_.DescribeNegationTo(os);
  }

  template <typename T>
  bool MatchAndExplain(const T& value, MatchResultListener* listener) const {
    return MatchAndExplainImpl(
        typename ::testing::internal::
            is_pointer<GTEST_REMOVE_CONST_(T)>::type(),
        value, listener);
  }

 private:
  // The first argument of MatchAndExplainImpl() is needed to help
  // Symbian's C++ compiler choose which overload to use.  Its type is
  // true_type iff the Field() matcher is used to match a pointer.
  bool MatchAndExplainImpl(false_type /* is_not_pointer */, const Class& obj,
                           MatchResultListener* listener) const {
    *listener << whose_field_ << "is ";
    return MatchPrintAndExplain(obj.*field_, matcher_, listener);
  }

  bool MatchAndExplainImpl(true_type /* is_pointer */, const Class* p,
                           MatchResultListener* listener) const {
    if (p == NULL)
      return false;

    *listener << "which points to an object ";
    // Since *p has a field, it must be a class/struct/union type and
    // thus cannot be a pointer.  Therefore we pass false_type() as
    // the first argument.
    return MatchAndExplainImpl(false_type(), *p, listener);
  }

  const FieldType Class::*field_;
  const Matcher<const FieldType&> matcher_;

  // Contains either "whose given field " if the name of the field is unknown
  // or "whose field `name_of_field` " if the name is known.
  const std::string whose_field_;

  GTEST_DISALLOW_ASSIGN_(FieldMatcher);
};

// Implements the Property() matcher for matching a property
// (i.e. return value of a getter method) of an object.
//
// Property is a const-qualified member function of Class returning
// PropertyType.
template <typename Class, typename PropertyType, typename Property>
class PropertyMatcher {
 public:
  // The property may have a reference type, so 'const PropertyType&'
  // may cause double references and fail to compile.  That's why we
  // need GTEST_REFERENCE_TO_CONST, which works regardless of
  // PropertyType being a reference or not.
  typedef GTEST_REFERENCE_TO_CONST_(PropertyType) RefToConstProperty;

  PropertyMatcher(Property property, const Matcher<RefToConstProperty>& matcher)
      : property_(property),
        matcher_(matcher),
        whose_property_("whose given property ") {}

  PropertyMatcher(const std::string& property_name, Property property,
                  const Matcher<RefToConstProperty>& matcher)
      : property_(property),
        matcher_(matcher),
        whose_property_("whose property `" + property_name + "` ") {}

  void DescribeTo(::std::ostream* os) const {
    *os << "is an object " << whose_property_;
    matcher_.DescribeTo(os);
  }

  void DescribeNegationTo(::std::ostream* os) const {
    *os << "is an object " << whose_property_;
    matcher_.DescribeNegationTo(os);
  }

  template <typename T>
  bool MatchAndExplain(const T&value, MatchResultListener* listener) const {
    return MatchAndExplainImpl(
        typename ::testing::internal::
            is_pointer<GTEST_REMOVE_CONST_(T)>::type(),
        value, listener);
  }

 private:
  // The first argument of MatchAndExplainImpl() is needed to help
  // Symbian's C++ compiler choose which overload to use.  Its type is
  // true_type iff the Property() matcher is used to match a pointer.
  bool MatchAndExplainImpl(false_type /* is_not_pointer */, const Class& obj,
                           MatchResultListener* listener) const {
    *listener << whose_property_ << "is ";
    // Cannot pass the return value (for example, int) to MatchPrintAndExplain,
    // which takes a non-const reference as argument.
#if defined(_PREFAST_ ) && _MSC_VER == 1800
    // Workaround bug in VC++ 2013's /analyze parser.
    // https://connect.microsoft.com/VisualStudio/feedback/details/1106363/internal-compiler-error-with-analyze-due-to-failure-to-infer-move
    posix::Abort();  // To make sure it is never run.
    return false;
#else
    RefToConstProperty result = (obj.*property_)();
    return MatchPrintAndExplain(result, matcher_, listener);
#endif
  }

  bool MatchAndExplainImpl(true_type /* is_pointer */, const Class* p,
                           MatchResultListener* listener) const {
    if (p == NULL)
      return false;

    *listener << "which points to an object ";
    // Since *p has a property method, it must be a class/struct/union
    // type and thus cannot be a pointer.  Therefore we pass
    // false_type() as the first argument.
    return MatchAndExplainImpl(false_type(), *p, listener);
  }

  Property property_;
  const Matcher<RefToConstProperty> matcher_;

  // Contains either "whose given property " if the name of the property is
  // unknown or "whose property `name_of_property` " if the name is known.
  const std::string whose_property_;

  GTEST_DISALLOW_ASSIGN_(PropertyMatcher);
};

// Type traits specifying various features of different functors for ResultOf.
// The default template specifies features for functor objects.
// Functor classes have to typedef argument_type and result_type
// to be compatible with ResultOf.
template <typename Functor>
struct CallableTraits {
  typedef typename Functor::result_type ResultType;
  typedef Functor StorageType;

  static void CheckIsValid(Functor /* functor */) {}
  template <typename T>
  static ResultType Invoke(Functor f, T arg) { return f(arg); }
};

// Specialization for function pointers.
template <typename ArgType, typename ResType>
struct CallableTraits<ResType(*)(ArgType)> {
  typedef ResType ResultType;
  typedef ResType(*StorageType)(ArgType);

  static void CheckIsValid(ResType(*f)(ArgType)) {
    GTEST_CHECK_(f != NULL)
        << "NULL function pointer is passed into ResultOf().";
  }
  template <typename T>
  static ResType Invoke(ResType(*f)(ArgType), T arg) {
    return (*f)(arg);
  }
};

// Implements the ResultOf() matcher for matching a return value of a
// unary function of an object.
template <typename Callable>
class ResultOfMatcher {
 public:
  typedef typename CallableTraits<Callable>::ResultType ResultType;

  ResultOfMatcher(Callable callable, const Matcher<ResultType>& matcher)
      : callable_(callable), matcher_(matcher) {
    CallableTraits<Callable>::CheckIsValid(callable_);
  }

  template <typename T>
  operator Matcher<T>() const {
    return Matcher<T>(new Impl<T>(callable_, matcher_));
  }

 private:
  typedef typename CallableTraits<Callable>::StorageType CallableStorageType;

  template <typename T>
  class Impl : public MatcherInterface<T> {
   public:
    Impl(CallableStorageType callable, const Matcher<ResultType>& matcher)
        : callable_(callable), matcher_(matcher) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "is mapped by the given callable to a value that ";
      matcher_.DescribeTo(os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "is mapped by the given callable to a value that ";
      matcher_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(T obj, MatchResultListener* listener) const {
      *listener << "which is mapped by the given callable to ";
      // Cannot pass the return value (for example, int) to
      // MatchPrintAndExplain, which takes a non-const reference as argument.
      ResultType result =
          CallableTraits<Callable>::template Invoke<T>(callable_, obj);
      return MatchPrintAndExplain(result, matcher_, listener);
    }

   private:
    // Functors often define operator() as non-const method even though
    // they are actually stateless. But we need to use them even when
    // 'this' is a const pointer. It's the user's responsibility not to
    // use stateful callables with ResultOf(), which does't guarantee
    // how many times the callable will be invoked.
    mutable CallableStorageType callable_;
    const Matcher<ResultType> matcher_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };  // class Impl

  const CallableStorageType callable_;
  const Matcher<ResultType> matcher_;

  GTEST_DISALLOW_ASSIGN_(ResultOfMatcher);
};

// Implements a matcher that checks the size of an STL-style container.
template <typename SizeMatcher>
class SizeIsMatcher {
 public:
  explicit SizeIsMatcher(const SizeMatcher& size_matcher)
       : size_matcher_(size_matcher) {
  }

  template <typename Container>
  operator Matcher<Container>() const {
    return MakeMatcher(new Impl<Container>(size_matcher_));
  }

  template <typename Container>
  class Impl : public MatcherInterface<Container> {
   public:
    typedef internal::StlContainerView<
         GTEST_REMOVE_REFERENCE_AND_CONST_(Container)> ContainerView;
    typedef typename ContainerView::type::size_type SizeType;
    explicit Impl(const SizeMatcher& size_matcher)
        : size_matcher_(MatcherCast<SizeType>(size_matcher)) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "size ";
      size_matcher_.DescribeTo(os);
    }
    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "size ";
      size_matcher_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(Container container,
                                 MatchResultListener* listener) const {
      SizeType size = container.size();
      StringMatchResultListener size_listener;
      const bool result = size_matcher_.MatchAndExplain(size, &size_listener);
      *listener
          << "whose size " << size << (result ? " matches" : " doesn't match");
      PrintIfNotEmpty(size_listener.str(), listener->stream());
      return result;
    }

   private:
    const Matcher<SizeType> size_matcher_;
    GTEST_DISALLOW_ASSIGN_(Impl);
  };

 private:
  const SizeMatcher size_matcher_;
  GTEST_DISALLOW_ASSIGN_(SizeIsMatcher);
};

// Implements a matcher that checks the begin()..end() distance of an STL-style
// container.
template <typename DistanceMatcher>
class BeginEndDistanceIsMatcher {
 public:
  explicit BeginEndDistanceIsMatcher(const DistanceMatcher& distance_matcher)
      : distance_matcher_(distance_matcher) {}

  template <typename Container>
  operator Matcher<Container>() const {
    return MakeMatcher(new Impl<Container>(distance_matcher_));
  }

  template <typename Container>
  class Impl : public MatcherInterface<Container> {
   public:
    typedef internal::StlContainerView<
        GTEST_REMOVE_REFERENCE_AND_CONST_(Container)> ContainerView;
    typedef typename std::iterator_traits<
        typename ContainerView::type::const_iterator>::difference_type
        DistanceType;
    explicit Impl(const DistanceMatcher& distance_matcher)
        : distance_matcher_(MatcherCast<DistanceType>(distance_matcher)) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "distance between begin() and end() ";
      distance_matcher_.DescribeTo(os);
    }
    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "distance between begin() and end() ";
      distance_matcher_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(Container container,
                                 MatchResultListener* listener) const {
#if GTEST_HAS_STD_BEGIN_AND_END_
      using std::begin;
      using std::end;
      DistanceType distance = std::distance(begin(container), end(container));
#else
      DistanceType distance = std::distance(container.begin(), container.end());
#endif
      StringMatchResultListener distance_listener;
      const bool result =
          distance_matcher_.MatchAndExplain(distance, &distance_listener);
      *listener << "whose distance between begin() and end() " << distance
                << (result ? " matches" : " doesn't match");
      PrintIfNotEmpty(distance_listener.str(), listener->stream());
      return result;
    }

   private:
    const Matcher<DistanceType> distance_matcher_;
    GTEST_DISALLOW_ASSIGN_(Impl);
  };

 private:
  const DistanceMatcher distance_matcher_;
  GTEST_DISALLOW_ASSIGN_(BeginEndDistanceIsMatcher);
};

// Implements an equality matcher for any STL-style container whose elements
// support ==. This matcher is like Eq(), but its failure explanations provide
// more detailed information that is useful when the container is used as a set.
// The failure message reports elements that are in one of the operands but not
// the other. The failure messages do not report duplicate or out-of-order
// elements in the containers (which don't properly matter to sets, but can
// occur if the containers are vectors or lists, for example).
//
// Uses the container's const_iterator, value_type, operator ==,
// begin(), and end().
template <typename Container>
class ContainerEqMatcher {
 public:
  typedef internal::StlContainerView<Container> View;
  typedef typename View::type StlContainer;
  typedef typename View::const_reference StlContainerReference;

  // We make a copy of expected in case the elements in it are modified
  // after this matcher is created.
  explicit ContainerEqMatcher(const Container& expected)
      : expected_(View::Copy(expected)) {
    // Makes sure the user doesn't instantiate this class template
    // with a const or reference type.
    (void)testing::StaticAssertTypeEq<Container,
        GTEST_REMOVE_REFERENCE_AND_CONST_(Container)>();
  }

  void DescribeTo(::std::ostream* os) const {
    *os << "equals ";
    UniversalPrint(expected_, os);
  }
  void DescribeNegationTo(::std::ostream* os) const {
    *os << "does not equal ";
    UniversalPrint(expected_, os);
  }

  template <typename LhsContainer>
  bool MatchAndExplain(const LhsContainer& lhs,
                       MatchResultListener* listener) const {
    // GTEST_REMOVE_CONST_() is needed to work around an MSVC 8.0 bug
    // that causes LhsContainer to be a const type sometimes.
    typedef internal::StlContainerView<GTEST_REMOVE_CONST_(LhsContainer)>
        LhsView;
    typedef typename LhsView::type LhsStlContainer;
    StlContainerReference lhs_stl_container = LhsView::ConstReference(lhs);
    if (lhs_stl_container == expected_)
      return true;

    ::std::ostream* const os = listener->stream();
    if (os != NULL) {
      // Something is different. Check for extra values first.
      bool printed_header = false;
      for (typename LhsStlContainer::const_iterator it =
               lhs_stl_container.begin();
           it != lhs_stl_container.end(); ++it) {
        if (internal::ArrayAwareFind(expected_.begin(), expected_.end(), *it) ==
            expected_.end()) {
          if (printed_header) {
            *os << ", ";
          } else {
            *os << "which has these unexpected elements: ";
            printed_header = true;
          }
          UniversalPrint(*it, os);
        }
      }

      // Now check for missing values.
      bool printed_header2 = false;
      for (typename StlContainer::const_iterator it = expected_.begin();
           it != expected_.end(); ++it) {
        if (internal::ArrayAwareFind(
                lhs_stl_container.begin(), lhs_stl_container.end(), *it) ==
            lhs_stl_container.end()) {
          if (printed_header2) {
            *os << ", ";
          } else {
            *os << (printed_header ? ",\nand" : "which")
                << " doesn't have these expected elements: ";
            printed_header2 = true;
          }
          UniversalPrint(*it, os);
        }
      }
    }

    return false;
  }

 private:
  const StlContainer expected_;

  GTEST_DISALLOW_ASSIGN_(ContainerEqMatcher);
};

// A comparator functor that uses the < operator to compare two values.
struct LessComparator {
  template <typename T, typename U>
  bool operator()(const T& lhs, const U& rhs) const { return lhs < rhs; }
};

// Implements WhenSortedBy(comparator, container_matcher).
template <typename Comparator, typename ContainerMatcher>
class WhenSortedByMatcher {
 public:
  WhenSortedByMatcher(const Comparator& comparator,
                      const ContainerMatcher& matcher)
      : comparator_(comparator), matcher_(matcher) {}

  template <typename LhsContainer>
  operator Matcher<LhsContainer>() const {
    return MakeMatcher(new Impl<LhsContainer>(comparator_, matcher_));
  }

  template <typename LhsContainer>
  class Impl : public MatcherInterface<LhsContainer> {
   public:
    typedef internal::StlContainerView<
         GTEST_REMOVE_REFERENCE_AND_CONST_(LhsContainer)> LhsView;
    typedef typename LhsView::type LhsStlContainer;
    typedef typename LhsView::const_reference LhsStlContainerReference;
    // Transforms std::pair<const Key, Value> into std::pair<Key, Value>
    // so that we can match associative containers.
    typedef typename RemoveConstFromKey<
        typename LhsStlContainer::value_type>::type LhsValue;

    Impl(const Comparator& comparator, const ContainerMatcher& matcher)
        : comparator_(comparator), matcher_(matcher) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "(when sorted) ";
      matcher_.DescribeTo(os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "(when sorted) ";
      matcher_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(LhsContainer lhs,
                                 MatchResultListener* listener) const {
      LhsStlContainerReference lhs_stl_container = LhsView::ConstReference(lhs);
      ::std::vector<LhsValue> sorted_container(lhs_stl_container.begin(),
                                               lhs_stl_container.end());
      ::std::sort(
           sorted_container.begin(), sorted_container.end(), comparator_);

      if (!listener->IsInterested()) {
        // If the listener is not interested, we do not need to
        // construct the inner explanation.
        return matcher_.Matches(sorted_container);
      }

      *listener << "which is ";
      UniversalPrint(sorted_container, listener->stream());
      *listener << " when sorted";

      StringMatchResultListener inner_listener;
      const bool match = matcher_.MatchAndExplain(sorted_container,
                                                  &inner_listener);
      PrintIfNotEmpty(inner_listener.str(), listener->stream());
      return match;
    }

   private:
    const Comparator comparator_;
    const Matcher<const ::std::vector<LhsValue>&> matcher_;

    GTEST_DISALLOW_COPY_AND_ASSIGN_(Impl);
  };

 private:
  const Comparator comparator_;
  const ContainerMatcher matcher_;

  GTEST_DISALLOW_ASSIGN_(WhenSortedByMatcher);
};

// Implements Pointwise(tuple_matcher, rhs_container).  tuple_matcher
// must be able to be safely cast to Matcher<tuple<const T1&, const
// T2&> >, where T1 and T2 are the types of elements in the LHS
// container and the RHS container respectively.
template <typename TupleMatcher, typename RhsContainer>
class PointwiseMatcher {
  GTEST_COMPILE_ASSERT_(
      !IsHashTable<GTEST_REMOVE_REFERENCE_AND_CONST_(RhsContainer)>::value,
      use_UnorderedPointwise_with_hash_tables);

 public:
  typedef internal::StlContainerView<RhsContainer> RhsView;
  typedef typename RhsView::type RhsStlContainer;
  typedef typename RhsStlContainer::value_type RhsValue;

  // Like ContainerEq, we make a copy of rhs in case the elements in
  // it are modified after this matcher is created.
  PointwiseMatcher(const TupleMatcher& tuple_matcher, const RhsContainer& rhs)
      : tuple_matcher_(tuple_matcher), rhs_(RhsView::Copy(rhs)) {
    // Makes sure the user doesn't instantiate this class template
    // with a const or reference type.
    (void)testing::StaticAssertTypeEq<RhsContainer,
        GTEST_REMOVE_REFERENCE_AND_CONST_(RhsContainer)>();
  }

  template <typename LhsContainer>
  operator Matcher<LhsContainer>() const {
    GTEST_COMPILE_ASSERT_(
        !IsHashTable<GTEST_REMOVE_REFERENCE_AND_CONST_(LhsContainer)>::value,
        use_UnorderedPointwise_with_hash_tables);

    return MakeMatcher(new Impl<LhsContainer>(tuple_matcher_, rhs_));
  }

  template <typename LhsContainer>
  class Impl : public MatcherInterface<LhsContainer> {
   public:
    typedef internal::StlContainerView<
         GTEST_REMOVE_REFERENCE_AND_CONST_(LhsContainer)> LhsView;
    typedef typename LhsView::type LhsStlContainer;
    typedef typename LhsView::const_reference LhsStlContainerReference;
    typedef typename LhsStlContainer::value_type LhsValue;
    // We pass the LHS value and the RHS value to the inner matcher by
    // reference, as they may be expensive to copy.  We must use tuple
    // instead of pair here, as a pair cannot hold references (C++ 98,
    // 20.2.2 [lib.pairs]).
    typedef ::testing::tuple<const LhsValue&, const RhsValue&> InnerMatcherArg;

    Impl(const TupleMatcher& tuple_matcher, const RhsStlContainer& rhs)
        // mono_tuple_matcher_ holds a monomorphic version of the tuple matcher.
        : mono_tuple_matcher_(SafeMatcherCast<InnerMatcherArg>(tuple_matcher)),
          rhs_(rhs) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "contains " << rhs_.size()
          << " values, where each value and its corresponding value in ";
      UniversalPrinter<RhsStlContainer>::Print(rhs_, os);
      *os << " ";
      mono_tuple_matcher_.DescribeTo(os);
    }
    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "doesn't contain exactly " << rhs_.size()
          << " values, or contains a value x at some index i"
          << " where x and the i-th value of ";
      UniversalPrint(rhs_, os);
      *os << " ";
      mono_tuple_matcher_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(LhsContainer lhs,
                                 MatchResultListener* listener) const {
      LhsStlContainerReference lhs_stl_container = LhsView::ConstReference(lhs);
      const size_t actual_size = lhs_stl_container.size();
      if (actual_size != rhs_.size()) {
        *listener << "which contains " << actual_size << " values";
        return false;
      }

      typename LhsStlContainer::const_iterator left = lhs_stl_container.begin();
      typename RhsStlContainer::const_iterator right = rhs_.begin();
      for (size_t i = 0; i != actual_size; ++i, ++left, ++right) {
        if (listener->IsInterested()) {
          StringMatchResultListener inner_listener;
          // Create InnerMatcherArg as a temporarily object to avoid it outlives
          // *left and *right. Dereference or the conversion to `const T&` may
          // return temp objects, e.g for vector<bool>.
          if (!mono_tuple_matcher_.MatchAndExplain(
                  InnerMatcherArg(ImplicitCast_<const LhsValue&>(*left),
                                  ImplicitCast_<const RhsValue&>(*right)),
                  &inner_listener)) {
            *listener << "where the value pair (";
            UniversalPrint(*left, listener->stream());
            *listener << ", ";
            UniversalPrint(*right, listener->stream());
            *listener << ") at index #" << i << " don't match";
            PrintIfNotEmpty(inner_listener.str(), listener->stream());
            return false;
          }
        } else {
          if (!mono_tuple_matcher_.Matches(
                  InnerMatcherArg(ImplicitCast_<const LhsValue&>(*left),
                                  ImplicitCast_<const RhsValue&>(*right))))
            return false;
        }
      }

      return true;
    }

   private:
    const Matcher<InnerMatcherArg> mono_tuple_matcher_;
    const RhsStlContainer rhs_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

 private:
  const TupleMatcher tuple_matcher_;
  const RhsStlContainer rhs_;

  GTEST_DISALLOW_ASSIGN_(PointwiseMatcher);
};

// Holds the logic common to ContainsMatcherImpl and EachMatcherImpl.
template <typename Container>
class QuantifierMatcherImpl : public MatcherInterface<Container> {
 public:
  typedef GTEST_REMOVE_REFERENCE_AND_CONST_(Container) RawContainer;
  typedef StlContainerView<RawContainer> View;
  typedef typename View::type StlContainer;
  typedef typename View::const_reference StlContainerReference;
  typedef typename StlContainer::value_type Element;

  template <typename InnerMatcher>
  explicit QuantifierMatcherImpl(InnerMatcher inner_matcher)
      : inner_matcher_(
           testing::SafeMatcherCast<const Element&>(inner_matcher)) {}

  // Checks whether:
  // * All elements in the container match, if all_elements_should_match.
  // * Any element in the container matches, if !all_elements_should_match.
  bool MatchAndExplainImpl(bool all_elements_should_match,
                           Container container,
                           MatchResultListener* listener) const {
    StlContainerReference stl_container = View::ConstReference(container);
    size_t i = 0;
    for (typename StlContainer::const_iterator it = stl_container.begin();
         it != stl_container.end(); ++it, ++i) {
      StringMatchResultListener inner_listener;
      const bool matches = inner_matcher_.MatchAndExplain(*it, &inner_listener);

      if (matches != all_elements_should_match) {
        *listener << "whose element #" << i
                  << (matches ? " matches" : " doesn't match");
        PrintIfNotEmpty(inner_listener.str(), listener->stream());
        return !all_elements_should_match;
      }
    }
    return all_elements_should_match;
  }

 protected:
  const Matcher<const Element&> inner_matcher_;

  GTEST_DISALLOW_ASSIGN_(QuantifierMatcherImpl);
};

// Implements Contains(element_matcher) for the given argument type Container.
// Symmetric to EachMatcherImpl.
template <typename Container>
class ContainsMatcherImpl : public QuantifierMatcherImpl<Container> {
 public:
  template <typename InnerMatcher>
  explicit ContainsMatcherImpl(InnerMatcher inner_matcher)
      : QuantifierMatcherImpl<Container>(inner_matcher) {}

  // Describes what this matcher does.
  virtual void DescribeTo(::std::ostream* os) const {
    *os << "contains at least one element that ";
    this->inner_matcher_.DescribeTo(os);
  }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "doesn't contain any element that ";
    this->inner_matcher_.DescribeTo(os);
  }

  virtual bool MatchAndExplain(Container container,
                               MatchResultListener* listener) const {
    return this->MatchAndExplainImpl(false, container, listener);
  }

 private:
  GTEST_DISALLOW_ASSIGN_(ContainsMatcherImpl);
};

// Implements Each(element_matcher) for the given argument type Container.
// Symmetric to ContainsMatcherImpl.
template <typename Container>
class EachMatcherImpl : public QuantifierMatcherImpl<Container> {
 public:
  template <typename InnerMatcher>
  explicit EachMatcherImpl(InnerMatcher inner_matcher)
      : QuantifierMatcherImpl<Container>(inner_matcher) {}

  // Describes what this matcher does.
  virtual void DescribeTo(::std::ostream* os) const {
    *os << "only contains elements that ";
    this->inner_matcher_.DescribeTo(os);
  }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "contains some element that ";
    this->inner_matcher_.DescribeNegationTo(os);
  }

  virtual bool MatchAndExplain(Container container,
                               MatchResultListener* listener) const {
    return this->MatchAndExplainImpl(true, container, listener);
  }

 private:
  GTEST_DISALLOW_ASSIGN_(EachMatcherImpl);
};

// Implements polymorphic Contains(element_matcher).
template <typename M>
class ContainsMatcher {
 public:
  explicit ContainsMatcher(M m) : inner_matcher_(m) {}

  template <typename Container>
  operator Matcher<Container>() const {
    return MakeMatcher(new ContainsMatcherImpl<Container>(inner_matcher_));
  }

 private:
  const M inner_matcher_;

  GTEST_DISALLOW_ASSIGN_(ContainsMatcher);
};

// Implements polymorphic Each(element_matcher).
template <typename M>
class EachMatcher {
 public:
  explicit EachMatcher(M m) : inner_matcher_(m) {}

  template <typename Container>
  operator Matcher<Container>() const {
    return MakeMatcher(new EachMatcherImpl<Container>(inner_matcher_));
  }

 private:
  const M inner_matcher_;

  GTEST_DISALLOW_ASSIGN_(EachMatcher);
};

struct Rank1 {};
struct Rank0 : Rank1 {};

namespace pair_getters {
#if GTEST_LANG_CXX11
using std::get;
template <typename T>
auto First(T& x, Rank1) -> decltype(get<0>(x)) {  // NOLINT
  return get<0>(x);
}
template <typename T>
auto First(T& x, Rank0) -> decltype((x.first)) {  // NOLINT
  return x.first;
}

template <typename T>
auto Second(T& x, Rank1) -> decltype(get<1>(x)) {  // NOLINT
  return get<1>(x);
}
template <typename T>
auto Second(T& x, Rank0) -> decltype((x.second)) {  // NOLINT
  return x.second;
}
#else
template <typename T>
typename T::first_type& First(T& x, Rank0) {  // NOLINT
  return x.first;
}
template <typename T>
const typename T::first_type& First(const T& x, Rank0) {
  return x.first;
}

template <typename T>
typename T::second_type& Second(T& x, Rank0) {  // NOLINT
  return x.second;
}
template <typename T>
const typename T::second_type& Second(const T& x, Rank0) {
  return x.second;
}
#endif  // GTEST_LANG_CXX11
}  // namespace pair_getters

// Implements Key(inner_matcher) for the given argument pair type.
// Key(inner_matcher) matches an std::pair whose 'first' field matches
// inner_matcher.  For example, Contains(Key(Ge(5))) can be used to match an
// std::map that contains at least one element whose key is >= 5.
template <typename PairType>
class KeyMatcherImpl : public MatcherInterface<PairType> {
 public:
  typedef GTEST_REMOVE_REFERENCE_AND_CONST_(PairType) RawPairType;
  typedef typename RawPairType::first_type KeyType;

  template <typename InnerMatcher>
  explicit KeyMatcherImpl(InnerMatcher inner_matcher)
      : inner_matcher_(
          testing::SafeMatcherCast<const KeyType&>(inner_matcher)) {
  }

  // Returns true iff 'key_value.first' (the key) matches the inner matcher.
  virtual bool MatchAndExplain(PairType key_value,
                               MatchResultListener* listener) const {
    StringMatchResultListener inner_listener;
    const bool match = inner_matcher_.MatchAndExplain(
        pair_getters::First(key_value, Rank0()), &inner_listener);
    const std::string explanation = inner_listener.str();
    if (explanation != "") {
      *listener << "whose first field is a value " << explanation;
    }
    return match;
  }

  // Describes what this matcher does.
  virtual void DescribeTo(::std::ostream* os) const {
    *os << "has a key that ";
    inner_matcher_.DescribeTo(os);
  }

  // Describes what the negation of this matcher does.
  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "doesn't have a key that ";
    inner_matcher_.DescribeTo(os);
  }

 private:
  const Matcher<const KeyType&> inner_matcher_;

  GTEST_DISALLOW_ASSIGN_(KeyMatcherImpl);
};

// Implements polymorphic Key(matcher_for_key).
template <typename M>
class KeyMatcher {
 public:
  explicit KeyMatcher(M m) : matcher_for_key_(m) {}

  template <typename PairType>
  operator Matcher<PairType>() const {
    return MakeMatcher(new KeyMatcherImpl<PairType>(matcher_for_key_));
  }

 private:
  const M matcher_for_key_;

  GTEST_DISALLOW_ASSIGN_(KeyMatcher);
};

// Implements Pair(first_matcher, second_matcher) for the given argument pair
// type with its two matchers. See Pair() function below.
template <typename PairType>
class PairMatcherImpl : public MatcherInterface<PairType> {
 public:
  typedef GTEST_REMOVE_REFERENCE_AND_CONST_(PairType) RawPairType;
  typedef typename RawPairType::first_type FirstType;
  typedef typename RawPairType::second_type SecondType;

  template <typename FirstMatcher, typename SecondMatcher>
  PairMatcherImpl(FirstMatcher first_matcher, SecondMatcher second_matcher)
      : first_matcher_(
            testing::SafeMatcherCast<const FirstType&>(first_matcher)),
        second_matcher_(
            testing::SafeMatcherCast<const SecondType&>(second_matcher)) {
  }

  // Describes what this matcher does.
  virtual void DescribeTo(::std::ostream* os) const {
    *os << "has a first field that ";
    first_matcher_.DescribeTo(os);
    *os << ", and has a second field that ";
    second_matcher_.DescribeTo(os);
  }

  // Describes what the negation of this matcher does.
  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "has a first field that ";
    first_matcher_.DescribeNegationTo(os);
    *os << ", or has a second field that ";
    second_matcher_.DescribeNegationTo(os);
  }

  // Returns true iff 'a_pair.first' matches first_matcher and 'a_pair.second'
  // matches second_matcher.
  virtual bool MatchAndExplain(PairType a_pair,
                               MatchResultListener* listener) const {
    if (!listener->IsInterested()) {
      // If the listener is not interested, we don't need to construct the
      // explanation.
      return first_matcher_.Matches(pair_getters::First(a_pair, Rank0())) &&
             second_matcher_.Matches(pair_getters::Second(a_pair, Rank0()));
    }
    StringMatchResultListener first_inner_listener;
    if (!first_matcher_.MatchAndExplain(pair_getters::First(a_pair, Rank0()),
                                        &first_inner_listener)) {
      *listener << "whose first field does not match";
      PrintIfNotEmpty(first_inner_listener.str(), listener->stream());
      return false;
    }
    StringMatchResultListener second_inner_listener;
    if (!second_matcher_.MatchAndExplain(pair_getters::Second(a_pair, Rank0()),
                                         &second_inner_listener)) {
      *listener << "whose second field does not match";
      PrintIfNotEmpty(second_inner_listener.str(), listener->stream());
      return false;
    }
    ExplainSuccess(first_inner_listener.str(), second_inner_listener.str(),
                   listener);
    return true;
  }

 private:
  void ExplainSuccess(const std::string& first_explanation,
                      const std::string& second_explanation,
                      MatchResultListener* listener) const {
    *listener << "whose both fields match";
    if (first_explanation != "") {
      *listener << ", where the first field is a value " << first_explanation;
    }
    if (second_explanation != "") {
      *listener << ", ";
      if (first_explanation != "") {
        *listener << "and ";
      } else {
        *listener << "where ";
      }
      *listener << "the second field is a value " << second_explanation;
    }
  }

  const Matcher<const FirstType&> first_matcher_;
  const Matcher<const SecondType&> second_matcher_;

  GTEST_DISALLOW_ASSIGN_(PairMatcherImpl);
};

// Implements polymorphic Pair(first_matcher, second_matcher).
template <typename FirstMatcher, typename SecondMatcher>
class PairMatcher {
 public:
  PairMatcher(FirstMatcher first_matcher, SecondMatcher second_matcher)
      : first_matcher_(first_matcher), second_matcher_(second_matcher) {}

  template <typename PairType>
  operator Matcher<PairType> () const {
    return MakeMatcher(
        new PairMatcherImpl<PairType>(
            first_matcher_, second_matcher_));
  }

 private:
  const FirstMatcher first_matcher_;
  const SecondMatcher second_matcher_;

  GTEST_DISALLOW_ASSIGN_(PairMatcher);
};

// Implements ElementsAre() and ElementsAreArray().
template <typename Container>
class ElementsAreMatcherImpl : public MatcherInterface<Container> {
 public:
  typedef GTEST_REMOVE_REFERENCE_AND_CONST_(Container) RawContainer;
  typedef internal::StlContainerView<RawContainer> View;
  typedef typename View::type StlContainer;
  typedef typename View::const_reference StlContainerReference;
  typedef typename StlContainer::value_type Element;

  // Constructs the matcher from a sequence of element values or
  // element matchers.
  template <typename InputIter>
  ElementsAreMatcherImpl(InputIter first, InputIter last) {
    while (first != last) {
      matchers_.push_back(MatcherCast<const Element&>(*first++));
    }
  }

  // Describes what this matcher does.
  virtual void DescribeTo(::std::ostream* os) const {
    if (count() == 0) {
      *os << "is empty";
    } else if (count() == 1) {
      *os << "has 1 element that ";
      matchers_[0].DescribeTo(os);
    } else {
      *os << "has " << Elements(count()) << " where\n";
      for (size_t i = 0; i != count(); ++i) {
        *os << "element #" << i << " ";
        matchers_[i].DescribeTo(os);
        if (i + 1 < count()) {
          *os << ",\n";
        }
      }
    }
  }

  // Describes what the negation of this matcher does.
  virtual void DescribeNegationTo(::std::ostream* os) const {
    if (count() == 0) {
      *os << "isn't empty";
      return;
    }

    *os << "doesn't have " << Elements(count()) << ", or\n";
    for (size_t i = 0; i != count(); ++i) {
      *os << "element #" << i << " ";
      matchers_[i].DescribeNegationTo(os);
      if (i + 1 < count()) {
        *os << ", or\n";
      }
    }
  }

  virtual bool MatchAndExplain(Container container,
                               MatchResultListener* listener) const {
    // To work with stream-like "containers", we must only walk
    // through the elements in one pass.

    const bool listener_interested = listener->IsInterested();

    // explanations[i] is the explanation of the element at index i.
    ::std::vector<std::string> explanations(count());
    StlContainerReference stl_container = View::ConstReference(container);
    typename StlContainer::const_iterator it = stl_container.begin();
    size_t exam_pos = 0;
    bool mismatch_found = false;  // Have we found a mismatched element yet?

    // Go through the elements and matchers in pairs, until we reach
    // the end of either the elements or the matchers, or until we find a
    // mismatch.
    for (; it != stl_container.end() && exam_pos != count(); ++it, ++exam_pos) {
      bool match;  // Does the current element match the current matcher?
      if (listener_interested) {
        StringMatchResultListener s;
        match = matchers_[exam_pos].MatchAndExplain(*it, &s);
        explanations[exam_pos] = s.str();
      } else {
        match = matchers_[exam_pos].Matches(*it);
      }

      if (!match) {
        mismatch_found = true;
        break;
      }
    }
    // If mismatch_found is true, 'exam_pos' is the index of the mismatch.

    // Find how many elements the actual container has.  We avoid
    // calling size() s.t. this code works for stream-like "containers"
    // that don't define size().
    size_t actual_count = exam_pos;
    for (; it != stl_container.end(); ++it) {
      ++actual_count;
    }

    if (actual_count != count()) {
      // The element count doesn't match.  If the container is empty,
      // there's no need to explain anything as Google Mock already
      // prints the empty container.  Otherwise we just need to show
      // how many elements there actually are.
      if (listener_interested && (actual_count != 0)) {
        *listener << "which has " << Elements(actual_count);
      }
      return false;
    }

    if (mismatch_found) {
      // The element count matches, but the exam_pos-th element doesn't match.
      if (listener_interested) {
        *listener << "whose element #" << exam_pos << " doesn't match";
        PrintIfNotEmpty(explanations[exam_pos], listener->stream());
      }
      return false;
    }

    // Every element matches its expectation.  We need to explain why
    // (the obvious ones can be skipped).
    if (listener_interested) {
      bool reason_printed = false;
      for (size_t i = 0; i != count(); ++i) {
        const std::string& s = explanations[i];
        if (!s.empty()) {
          if (reason_printed) {
            *listener << ",\nand ";
          }
          *listener << "whose element #" << i << " matches, " << s;
          reason_printed = true;
        }
      }
    }
    return true;
  }

 private:
  static Message Elements(size_t count) {
    return Message() << count << (count == 1 ? " element" : " elements");
  }

  size_t count() const { return matchers_.size(); }

  ::std::vector<Matcher<const Element&> > matchers_;

  GTEST_DISALLOW_ASSIGN_(ElementsAreMatcherImpl);
};

// Connectivity matrix of (elements X matchers), in element-major order.
// Initially, there are no edges.
// Use NextGraph() to iterate over all possible edge configurations.
// Use Randomize() to generate a random edge configuration.
class GTEST_API_ MatchMatrix {
 public:
  MatchMatrix(size_t num_elements, size_t num_matchers)
      : num_elements_(num_elements),
        num_matchers_(num_matchers),
        matched_(num_elements_* num_matchers_, 0) {
  }

  size_t LhsSize() const { return num_elements_; }
  size_t RhsSize() const { return num_matchers_; }
  bool HasEdge(size_t ilhs, size_t irhs) const {
    return matched_[SpaceIndex(ilhs, irhs)] == 1;
  }
  void SetEdge(size_t ilhs, size_t irhs, bool b) {
    matched_[SpaceIndex(ilhs, irhs)] = b ? 1 : 0;
  }

  // Treating the connectivity matrix as a (LhsSize()*RhsSize())-bit number,
  // adds 1 to that number; returns false if incrementing the graph left it
  // empty.
  bool NextGraph();

  void Randomize();

  std::string DebugString() const;

 private:
  size_t SpaceIndex(size_t ilhs, size_t irhs) const {
    return ilhs * num_matchers_ + irhs;
  }

  size_t num_elements_;
  size_t num_matchers_;

  // Each element is a char interpreted as bool. They are stored as a
  // flattened array in lhs-major order, use 'SpaceIndex()' to translate
  // a (ilhs, irhs) matrix coordinate into an offset.
  ::std::vector<char> matched_;
};

typedef ::std::pair<size_t, size_t> ElementMatcherPair;
typedef ::std::vector<ElementMatcherPair> ElementMatcherPairs;

// Returns a maximum bipartite matching for the specified graph 'g'.
// The matching is represented as a vector of {element, matcher} pairs.
GTEST_API_ ElementMatcherPairs
FindMaxBipartiteMatching(const MatchMatrix& g);

struct UnorderedMatcherRequire {
  enum Flags {
    Superset = 1 << 0,
    Subset = 1 << 1,
    ExactMatch = Superset | Subset,
  };
};

// Untyped base class for implementing UnorderedElementsAre.  By
// putting logic that's not specific to the element type here, we
// reduce binary bloat and increase compilation speed.
class GTEST_API_ UnorderedElementsAreMatcherImplBase {
 protected:
  explicit UnorderedElementsAreMatcherImplBase(
      UnorderedMatcherRequire::Flags matcher_flags)
      : match_flags_(matcher_flags) {}

  // A vector of matcher describers, one for each element matcher.
  // Does not own the describers (and thus can be used only when the
  // element matchers are alive).
  typedef ::std::vector<const MatcherDescriberInterface*> MatcherDescriberVec;

  // Describes this UnorderedElementsAre matcher.
  void DescribeToImpl(::std::ostream* os) const;

  // Describes the negation of this UnorderedElementsAre matcher.
  void DescribeNegationToImpl(::std::ostream* os) const;

  bool VerifyMatchMatrix(const ::std::vector<std::string>& element_printouts,
                         const MatchMatrix& matrix,
                         MatchResultListener* listener) const;

  bool FindPairing(const MatchMatrix& matrix,
                   MatchResultListener* listener) const;

  MatcherDescriberVec& matcher_describers() {
    return matcher_describers_;
  }

  static Message Elements(size_t n) {
    return Message() << n << " element" << (n == 1 ? "" : "s");
  }

  UnorderedMatcherRequire::Flags match_flags() const { return match_flags_; }

 private:
  UnorderedMatcherRequire::Flags match_flags_;
  MatcherDescriberVec matcher_describers_;

  GTEST_DISALLOW_ASSIGN_(UnorderedElementsAreMatcherImplBase);
};

// Implements UnorderedElementsAre, UnorderedElementsAreArray, IsSubsetOf, and
// IsSupersetOf.
template <typename Container>
class UnorderedElementsAreMatcherImpl
    : public MatcherInterface<Container>,
      public UnorderedElementsAreMatcherImplBase {
 public:
  typedef GTEST_REMOVE_REFERENCE_AND_CONST_(Container) RawContainer;
  typedef internal::StlContainerView<RawContainer> View;
  typedef typename View::type StlContainer;
  typedef typename View::const_reference StlContainerReference;
  typedef typename StlContainer::const_iterator StlContainerConstIterator;
  typedef typename StlContainer::value_type Element;

  template <typename InputIter>
  UnorderedElementsAreMatcherImpl(UnorderedMatcherRequire::Flags matcher_flags,
                                  InputIter first, InputIter last)
      : UnorderedElementsAreMatcherImplBase(matcher_flags) {
    for (; first != last; ++first) {
      matchers_.push_back(MatcherCast<const Element&>(*first));
      matcher_describers().push_back(matchers_.back().GetDescriber());
    }
  }

  // Describes what this matcher does.
  virtual void DescribeTo(::std::ostream* os) const {
    return UnorderedElementsAreMatcherImplBase::DescribeToImpl(os);
  }

  // Describes what the negation of this matcher does.
  virtual void DescribeNegationTo(::std::ostream* os) const {
    return UnorderedElementsAreMatcherImplBase::DescribeNegationToImpl(os);
  }

  virtual bool MatchAndExplain(Container container,
                               MatchResultListener* listener) const {
    StlContainerReference stl_container = View::ConstReference(container);
    ::std::vector<std::string> element_printouts;
    MatchMatrix matrix =
        AnalyzeElements(stl_container.begin(), stl_container.end(),
                        &element_printouts, listener);

    if (matrix.LhsSize() == 0 && matrix.RhsSize() == 0) {
      return true;
    }

    if (match_flags() == UnorderedMatcherRequire::ExactMatch) {
      if (matrix.LhsSize() != matrix.RhsSize()) {
        // The element count doesn't match.  If the container is empty,
        // there's no need to explain anything as Google Mock already
        // prints the empty container. Otherwise we just need to show
        // how many elements there actually are.
        if (matrix.LhsSize() != 0 && listener->IsInterested()) {
          *listener << "which has " << Elements(matrix.LhsSize());
        }
        return false;
      }
    }

    return VerifyMatchMatrix(element_printouts, matrix, listener) &&
           FindPairing(matrix, listener);
  }

 private:
  template <typename ElementIter>
  MatchMatrix AnalyzeElements(ElementIter elem_first, ElementIter elem_last,
                              ::std::vector<std::string>* element_printouts,
                              MatchResultListener* listener) const {
    element_printouts->clear();
    ::std::vector<char> did_match;
    size_t num_elements = 0;
    for (; elem_first != elem_last; ++num_elements, ++elem_first) {
      if (listener->IsInterested()) {
        element_printouts->push_back(PrintToString(*elem_first));
      }
      for (size_t irhs = 0; irhs != matchers_.size(); ++irhs) {
        did_match.push_back(Matches(matchers_[irhs])(*elem_first));
      }
    }

    MatchMatrix matrix(num_elements, matchers_.size());
    ::std::vector<char>::const_iterator did_match_iter = did_match.begin();
    for (size_t ilhs = 0; ilhs != num_elements; ++ilhs) {
      for (size_t irhs = 0; irhs != matchers_.size(); ++irhs) {
        matrix.SetEdge(ilhs, irhs, *did_match_iter++ != 0);
      }
    }
    return matrix;
  }

  ::std::vector<Matcher<const Element&> > matchers_;

  GTEST_DISALLOW_ASSIGN_(UnorderedElementsAreMatcherImpl);
};

// Functor for use in TransformTuple.
// Performs MatcherCast<Target> on an input argument of any type.
template <typename Target>
struct CastAndAppendTransform {
  template <typename Arg>
  Matcher<Target> operator()(const Arg& a) const {
    return MatcherCast<Target>(a);
  }
};

// Implements UnorderedElementsAre.
template <typename MatcherTuple>
class UnorderedElementsAreMatcher {
 public:
  explicit UnorderedElementsAreMatcher(const MatcherTuple& args)
      : matchers_(args) {}

  template <typename Container>
  operator Matcher<Container>() const {
    typedef GTEST_REMOVE_REFERENCE_AND_CONST_(Container) RawContainer;
    typedef typename internal::StlContainerView<RawContainer>::type View;
    typedef typename View::value_type Element;
    typedef ::std::vector<Matcher<const Element&> > MatcherVec;
    MatcherVec matchers;
    matchers.reserve(::testing::tuple_size<MatcherTuple>::value);
    TransformTupleValues(CastAndAppendTransform<const Element&>(), matchers_,
                         ::std::back_inserter(matchers));
    return MakeMatcher(new UnorderedElementsAreMatcherImpl<Container>(
        UnorderedMatcherRequire::ExactMatch, matchers.begin(), matchers.end()));
  }

 private:
  const MatcherTuple matchers_;
  GTEST_DISALLOW_ASSIGN_(UnorderedElementsAreMatcher);
};

// Implements ElementsAre.
template <typename MatcherTuple>
class ElementsAreMatcher {
 public:
  explicit ElementsAreMatcher(const MatcherTuple& args) : matchers_(args) {}

  template <typename Container>
  operator Matcher<Container>() const {
    GTEST_COMPILE_ASSERT_(
        !IsHashTable<GTEST_REMOVE_REFERENCE_AND_CONST_(Container)>::value ||
            ::testing::tuple_size<MatcherTuple>::value < 2,
        use_UnorderedElementsAre_with_hash_tables);

    typedef GTEST_REMOVE_REFERENCE_AND_CONST_(Container) RawContainer;
    typedef typename internal::StlContainerView<RawContainer>::type View;
    typedef typename View::value_type Element;
    typedef ::std::vector<Matcher<const Element&> > MatcherVec;
    MatcherVec matchers;
    matchers.reserve(::testing::tuple_size<MatcherTuple>::value);
    TransformTupleValues(CastAndAppendTransform<const Element&>(), matchers_,
                         ::std::back_inserter(matchers));
    return MakeMatcher(new ElementsAreMatcherImpl<Container>(
                           matchers.begin(), matchers.end()));
  }

 private:
  const MatcherTuple matchers_;
  GTEST_DISALLOW_ASSIGN_(ElementsAreMatcher);
};

// Implements UnorderedElementsAreArray(), IsSubsetOf(), and IsSupersetOf().
template <typename T>
class UnorderedElementsAreArrayMatcher {
 public:
  template <typename Iter>
  UnorderedElementsAreArrayMatcher(UnorderedMatcherRequire::Flags match_flags,
                                   Iter first, Iter last)
      : match_flags_(match_flags), matchers_(first, last) {}

  template <typename Container>
  operator Matcher<Container>() const {
    return MakeMatcher(new UnorderedElementsAreMatcherImpl<Container>(
        match_flags_, matchers_.begin(), matchers_.end()));
  }

 private:
  UnorderedMatcherRequire::Flags match_flags_;
  ::std::vector<T> matchers_;

  GTEST_DISALLOW_ASSIGN_(UnorderedElementsAreArrayMatcher);
};

// Implements ElementsAreArray().
template <typename T>
class ElementsAreArrayMatcher {
 public:
  template <typename Iter>
  ElementsAreArrayMatcher(Iter first, Iter last) : matchers_(first, last) {}

  template <typename Container>
  operator Matcher<Container>() const {
    GTEST_COMPILE_ASSERT_(
        !IsHashTable<GTEST_REMOVE_REFERENCE_AND_CONST_(Container)>::value,
        use_UnorderedElementsAreArray_with_hash_tables);

    return MakeMatcher(new ElementsAreMatcherImpl<Container>(
        matchers_.begin(), matchers_.end()));
  }

 private:
  const ::std::vector<T> matchers_;

  GTEST_DISALLOW_ASSIGN_(ElementsAreArrayMatcher);
};

// Given a 2-tuple matcher tm of type Tuple2Matcher and a value second
// of type Second, BoundSecondMatcher<Tuple2Matcher, Second>(tm,
// second) is a polymorphic matcher that matches a value x iff tm
// matches tuple (x, second).  Useful for implementing
// UnorderedPointwise() in terms of UnorderedElementsAreArray().
//
// BoundSecondMatcher is copyable and assignable, as we need to put
// instances of this class in a vector when implementing
// UnorderedPointwise().
template <typename Tuple2Matcher, typename Second>
class BoundSecondMatcher {
 public:
  BoundSecondMatcher(const Tuple2Matcher& tm, const Second& second)
      : tuple2_matcher_(tm), second_value_(second) {}

  template <typename T>
  operator Matcher<T>() const {
    return MakeMatcher(new Impl<T>(tuple2_matcher_, second_value_));
  }

  // We have to define this for UnorderedPointwise() to compile in
  // C++98 mode, as it puts BoundSecondMatcher instances in a vector,
  // which requires the elements to be assignable in C++98.  The
  // compiler cannot generate the operator= for us, as Tuple2Matcher
  // and Second may not be assignable.
  //
  // However, this should never be called, so the implementation just
  // need to assert.
  void operator=(const BoundSecondMatcher& /*rhs*/) {
    GTEST_LOG_(FATAL) << "BoundSecondMatcher should never be assigned.";
  }

 private:
  template <typename T>
  class Impl : public MatcherInterface<T> {
   public:
    typedef ::testing::tuple<T, Second> ArgTuple;

    Impl(const Tuple2Matcher& tm, const Second& second)
        : mono_tuple2_matcher_(SafeMatcherCast<const ArgTuple&>(tm)),
          second_value_(second) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "and ";
      UniversalPrint(second_value_, os);
      *os << " ";
      mono_tuple2_matcher_.DescribeTo(os);
    }

    virtual bool MatchAndExplain(T x, MatchResultListener* listener) const {
      return mono_tuple2_matcher_.MatchAndExplain(ArgTuple(x, second_value_),
                                                  listener);
    }

   private:
    const Matcher<const ArgTuple&> mono_tuple2_matcher_;
    const Second second_value_;

    GTEST_DISALLOW_ASSIGN_(Impl);
  };

  const Tuple2Matcher tuple2_matcher_;
  const Second second_value_;
};

// Given a 2-tuple matcher tm and a value second,
// MatcherBindSecond(tm, second) returns a matcher that matches a
// value x iff tm matches tuple (x, second).  Useful for implementing
// UnorderedPointwise() in terms of UnorderedElementsAreArray().
template <typename Tuple2Matcher, typename Second>
BoundSecondMatcher<Tuple2Matcher, Second> MatcherBindSecond(
    const Tuple2Matcher& tm, const Second& second) {
  return BoundSecondMatcher<Tuple2Matcher, Second>(tm, second);
}

// Returns the description for a matcher defined using the MATCHER*()
// macro where the user-supplied description string is "", if
// 'negation' is false; otherwise returns the description of the
// negation of the matcher.  'param_values' contains a list of strings
// that are the print-out of the matcher's parameters.
GTEST_API_ std::string FormatMatcherDescription(bool negation,
                                                const char* matcher_name,
                                                const Strings& param_values);

// Implements a matcher that checks the value of a optional<> type variable.
template <typename ValueMatcher>
class OptionalMatcher {
 public:
  explicit OptionalMatcher(const ValueMatcher& value_matcher)
      : value_matcher_(value_matcher) {}

  template <typename Optional>
  operator Matcher<Optional>() const {
    return MakeMatcher(new Impl<Optional>(value_matcher_));
  }

  template <typename Optional>
  class Impl : public MatcherInterface<Optional> {
   public:
    typedef GTEST_REMOVE_REFERENCE_AND_CONST_(Optional) OptionalView;
    typedef typename OptionalView::value_type ValueType;
    explicit Impl(const ValueMatcher& value_matcher)
        : value_matcher_(MatcherCast<ValueType>(value_matcher)) {}

    virtual void DescribeTo(::std::ostream* os) const {
      *os << "value ";
      value_matcher_.DescribeTo(os);
    }

    virtual void DescribeNegationTo(::std::ostream* os) const {
      *os << "value ";
      value_matcher_.DescribeNegationTo(os);
    }

    virtual bool MatchAndExplain(Optional optional,
                                 MatchResultListener* listener) const {
      if (!optional) {
        *listener << "which is not engaged";
        return false;
      }
      const ValueType& value = *optional;
      StringMatchResultListener value_listener;
      const bool match = value_matcher_.MatchAndExplain(value, &value_listener);
      *listener << "whose value " << PrintToString(value)
                << (match ? " matches" : " doesn't match");
      PrintIfNotEmpty(value_listener.str(), listener->stream());
      return match;
    }

   private:
    const Matcher<ValueType> value_matcher_;
    GTEST_DISALLOW_ASSIGN_(Impl);
  };

 private:
  const ValueMatcher value_matcher_;
  GTEST_DISALLOW_ASSIGN_(OptionalMatcher);
};

namespace variant_matcher {
// Overloads to allow VariantMatcher to do proper ADL lookup.
template <typename T>
void holds_alternative() {}
template <typename T>
void get() {}

// Implements a matcher that checks the value of a variant<> type variable.
template <typename T>
class VariantMatcher {
 public:
  explicit VariantMatcher(::testing::Matcher<const T&> matcher)
      : matcher_(internal::move(matcher)) {}

  template <typename Variant>
  bool MatchAndExplain(const Variant& value,
                       ::testing::MatchResultListener* listener) const {
    if (!listener->IsInterested()) {
      return holds_alternative<T>(value) && matcher_.Matches(get<T>(value));
    }

    if (!holds_alternative<T>(value)) {
      *listener << "whose value is not of type '" << GetTypeName() << "'";
      return false;
    }

    const T& elem = get<T>(value);
    StringMatchResultListener elem_listener;
    const bool match = matcher_.MatchAndExplain(elem, &elem_listener);
    *listener << "whose value " << PrintToString(elem)
              << (match ? " matches" : " doesn't match");
    PrintIfNotEmpty(elem_listener.str(), listener->stream());
    return match;
  }

  void DescribeTo(std::ostream* os) const {
    *os << "is a variant<> with value of type '" << GetTypeName()
        << "' and the value ";
    matcher_.DescribeTo(os);
  }

  void DescribeNegationTo(std::ostream* os) const {
    *os << "is a variant<> with value of type other than '" << GetTypeName()
        << "' or the value ";
    matcher_.DescribeNegationTo(os);
  }

 private:
  static std::string GetTypeName() {
#if GTEST_HAS_RTTI
    GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(
        return internal::GetTypeName<T>());
#endif
    return "the element type";
  }

  const ::testing::Matcher<const T&> matcher_;
};

}  // namespace variant_matcher

namespace any_cast_matcher {

// Overloads to allow AnyCastMatcher to do proper ADL lookup.
template <typename T>
void any_cast() {}

// Implements a matcher that any_casts the value.
template <typename T>
class AnyCastMatcher {
 public:
  explicit AnyCastMatcher(const ::testing::Matcher<const T&>& matcher)
      : matcher_(matcher) {}

  template <typename AnyType>
  bool MatchAndExplain(const AnyType& value,
                       ::testing::MatchResultListener* listener) const {
    if (!listener->IsInterested()) {
      const T* ptr = any_cast<T>(&value);
      return ptr != NULL && matcher_.Matches(*ptr);
    }

    const T* elem = any_cast<T>(&value);
    if (elem == NULL) {
      *listener << "whose value is not of type '" << GetTypeName() << "'";
      return false;
    }

    StringMatchResultListener elem_listener;
    const bool match = matcher_.MatchAndExplain(*elem, &elem_listener);
    *listener << "whose value " << PrintToString(*elem)
              << (match ? " matches" : " doesn't match");
    PrintIfNotEmpty(elem_listener.str(), listener->stream());
    return match;
  }

  void DescribeTo(std::ostream* os) const {
    *os << "is an 'any' type with value of type '" << GetTypeName()
        << "' and the value ";
    matcher_.DescribeTo(os);
  }

  void DescribeNegationTo(std::ostream* os) const {
    *os << "is an 'any' type with value of type other than '" << GetTypeName()
        << "' or the value ";
    matcher_.DescribeNegationTo(os);
  }

 private:
  static std::string GetTypeName() {
#if GTEST_HAS_RTTI
    GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(
        return internal::GetTypeName<T>());
#endif
    return "the element type";
  }

  const ::testing::Matcher<const T&> matcher_;
};

}  // namespace any_cast_matcher
}  // namespace internal

// ElementsAreArray(iterator_first, iterator_last)
// ElementsAreArray(pointer, count)
// ElementsAreArray(array)
// ElementsAreArray(container)
// ElementsAreArray({ e1, e2, ..., en })
//
// The ElementsAreArray() functions are like ElementsAre(...), except
// that they are given a homogeneous sequence rather than taking each
// element as a function argument. The sequence can be specified as an
// array, a pointer and count, a vector, an initializer list, or an
// STL iterator range. In each of these cases, the underlying sequence
// can be either a sequence of values or a sequence of matchers.
//
// All forms of ElementsAreArray() make a copy of the input matcher sequence.

template <typename Iter>
inline internal::ElementsAreArrayMatcher<
    typename ::std::iterator_traits<Iter>::value_type>
ElementsAreArray(Iter first, Iter last) {
  typedef typename ::std::iterator_traits<Iter>::value_type T;
  return internal::ElementsAreArrayMatcher<T>(first, last);
}

template <typename T>
inline internal::ElementsAreArrayMatcher<T> ElementsAreArray(
    const T* pointer, size_t count) {
  return ElementsAreArray(pointer, pointer + count);
}

template <typename T, size_t N>
inline internal::ElementsAreArrayMatcher<T> ElementsAreArray(
    const T (&array)[N]) {
  return ElementsAreArray(array, N);
}

template <typename Container>
inline internal::ElementsAreArrayMatcher<typename Container::value_type>
ElementsAreArray(const Container& container) {
  return ElementsAreArray(container.begin(), container.end());
}

#if GTEST_HAS_STD_INITIALIZER_LIST_
template <typename T>
inline internal::ElementsAreArrayMatcher<T>
ElementsAreArray(::std::initializer_list<T> xs) {
  return ElementsAreArray(xs.begin(), xs.end());
}
#endif

// UnorderedElementsAreArray(iterator_first, iterator_last)
// UnorderedElementsAreArray(pointer, count)
// UnorderedElementsAreArray(array)
// UnorderedElementsAreArray(container)
// UnorderedElementsAreArray({ e1, e2, ..., en })
//
// UnorderedElementsAreArray() verifies that a bijective mapping onto a
// collection of matchers exists.
//
// The matchers can be specified as an array, a pointer and count, a container,
// an initializer list, or an STL iterator range. In each of these cases, the
// underlying matchers can be either values or matchers.

template <typename Iter>
inline internal::UnorderedElementsAreArrayMatcher<
    typename ::std::iterator_traits<Iter>::value_type>
UnorderedElementsAreArray(Iter first, Iter last) {
  typedef typename ::std::iterator_traits<Iter>::value_type T;
  return internal::UnorderedElementsAreArrayMatcher<T>(
      internal::UnorderedMatcherRequire::ExactMatch, first, last);
}

template <typename T>
inline internal::UnorderedElementsAreArrayMatcher<T>
UnorderedElementsAreArray(const T* pointer, size_t count) {
  return UnorderedElementsAreArray(pointer, pointer + count);
}

template <typename T, size_t N>
inline internal::UnorderedElementsAreArrayMatcher<T>
UnorderedElementsAreArray(const T (&array)[N]) {
  return UnorderedElementsAreArray(array, N);
}

template <typename Container>
inline internal::UnorderedElementsAreArrayMatcher<
    typename Container::value_type>
UnorderedElementsAreArray(const Container& container) {
  return UnorderedElementsAreArray(container.begin(), container.end());
}

#if GTEST_HAS_STD_INITIALIZER_LIST_
template <typename T>
inline internal::UnorderedElementsAreArrayMatcher<T>
UnorderedElementsAreArray(::std::initializer_list<T> xs) {
  return UnorderedElementsAreArray(xs.begin(), xs.end());
}
#endif

// _ is a matcher that matches anything of any type.
//
// This definition is fine as:
//
//   1. The C++ standard permits using the name _ in a namespace that
//      is not the global namespace or ::std.
//   2. The AnythingMatcher class has no data member or constructor,
//      so it's OK to create global variables of this type.
//   3. c-style has approved of using _ in this case.
const internal::AnythingMatcher _ = {};
// Creates a matcher that matches any value of the given type T.
template <typename T>
inline Matcher<T> A() {
  return Matcher<T>(new internal::AnyMatcherImpl<T>());
}

// Creates a matcher that matches any value of the given type T.
template <typename T>
inline Matcher<T> An() { return A<T>(); }

// Creates a polymorphic matcher that matches anything equal to x.
// Note: if the parameter of Eq() were declared as const T&, Eq("foo")
// wouldn't compile.
template <typename T>
inline internal::EqMatcher<T> Eq(T x) { return internal::EqMatcher<T>(x); }

// Constructs a Matcher<T> from a 'value' of type T.  The constructed
// matcher matches any value that's equal to 'value'.
template <typename T>
Matcher<T>::Matcher(T value) { *this = Eq(value); }

template <typename T, typename M>
Matcher<T> internal::MatcherCastImpl<T, M>::CastImpl(
    const M& value,
    internal::BooleanConstant<false> /* convertible_to_matcher */,
    internal::BooleanConstant<false> /* convertible_to_T */) {
  return Eq(value);
}

// Creates a monomorphic matcher that matches anything with type Lhs
// and equal to rhs.  A user may need to use this instead of Eq(...)
// in order to resolve an overloading ambiguity.
//
// TypedEq<T>(x) is just a convenient short-hand for Matcher<T>(Eq(x))
// or Matcher<T>(x), but more readable than the latter.
//
// We could define similar monomorphic matchers for other comparison
// operations (e.g. TypedLt, TypedGe, and etc), but decided not to do
// it yet as those are used much less than Eq() in practice.  A user
// can always write Matcher<T>(Lt(5)) to be explicit about the type,
// for example.
template <typename Lhs, typename Rhs>
inline Matcher<Lhs> TypedEq(const Rhs& rhs) { return Eq(rhs); }

// Creates a polymorphic matcher that matches anything >= x.
template <typename Rhs>
inline internal::GeMatcher<Rhs> Ge(Rhs x) {
  return internal::GeMatcher<Rhs>(x);
}

// Creates a polymorphic matcher that matches anything > x.
template <typename Rhs>
inline internal::GtMatcher<Rhs> Gt(Rhs x) {
  return internal::GtMatcher<Rhs>(x);
}

// Creates a polymorphic matcher that matches anything <= x.
template <typename Rhs>
inline internal::LeMatcher<Rhs> Le(Rhs x) {
  return internal::LeMatcher<Rhs>(x);
}

// Creates a polymorphic matcher that matches anything < x.
template <typename Rhs>
inline internal::LtMatcher<Rhs> Lt(Rhs x) {
  return internal::LtMatcher<Rhs>(x);
}

// Creates a polymorphic matcher that matches anything != x.
template <typename Rhs>
inline internal::NeMatcher<Rhs> Ne(Rhs x) {
  return internal::NeMatcher<Rhs>(x);
}

// Creates a polymorphic matcher that matches any NULL pointer.
inline PolymorphicMatcher<internal::IsNullMatcher > IsNull() {
  return MakePolymorphicMatcher(internal::IsNullMatcher());
}

// Creates a polymorphic matcher that matches any non-NULL pointer.
// This is convenient as Not(NULL) doesn't compile (the compiler
// thinks that that expression is comparing a pointer with an integer).
inline PolymorphicMatcher<internal::NotNullMatcher > NotNull() {
  return MakePolymorphicMatcher(internal::NotNullMatcher());
}

// Creates a polymorphic matcher that matches any argument that
// references variable x.
template <typename T>
inline internal::RefMatcher<T&> Ref(T& x) {  // NOLINT
  return internal::RefMatcher<T&>(x);
}

// Creates a matcher that matches any double argument approximately
// equal to rhs, where two NANs are considered unequal.
inline internal::FloatingEqMatcher<double> DoubleEq(double rhs) {
  return internal::FloatingEqMatcher<double>(rhs, false);
}

// Creates a matcher that matches any double argument approximately
// equal to rhs, including NaN values when rhs is NaN.
inline internal::FloatingEqMatcher<double> NanSensitiveDoubleEq(double rhs) {
  return internal::FloatingEqMatcher<double>(rhs, true);
}

// Creates a matcher that matches any double argument approximately equal to
// rhs, up to the specified max absolute error bound, where two NANs are
// considered unequal.  The max absolute error bound must be non-negative.
inline internal::FloatingEqMatcher<double> DoubleNear(
    double rhs, double max_abs_error) {
  return internal::FloatingEqMatcher<double>(rhs, false, max_abs_error);
}

// Creates a matcher that matches any double argument approximately equal to
// rhs, up to the specified max absolute error bound, including NaN values when
// rhs is NaN.  The max absolute error bound must be non-negative.
inline internal::FloatingEqMatcher<double> NanSensitiveDoubleNear(
    double rhs, double max_abs_error) {
  return internal::FloatingEqMatcher<double>(rhs, true, max_abs_error);
}

// Creates a matcher that matches any float argument approximately
// equal to rhs, where two NANs are considered unequal.
inline internal::FloatingEqMatcher<float> FloatEq(float rhs) {
  return internal::FloatingEqMatcher<float>(rhs, false);
}

// Creates a matcher that matches any float argument approximately
// equal to rhs, including NaN values when rhs is NaN.
inline internal::FloatingEqMatcher<float> NanSensitiveFloatEq(float rhs) {
  return internal::FloatingEqMatcher<float>(rhs, true);
}

// Creates a matcher that matches any float argument approximately equal to
// rhs, up to the specified max absolute error bound, where two NANs are
// considered unequal.  The max absolute error bound must be non-negative.
inline internal::FloatingEqMatcher<float> FloatNear(
    float rhs, float max_abs_error) {
  return internal::FloatingEqMatcher<float>(rhs, false, max_abs_error);
}

// Creates a matcher that matches any float argument approximately equal to
// rhs, up to the specified max absolute error bound, including NaN values when
// rhs is NaN.  The max absolute error bound must be non-negative.
inline internal::FloatingEqMatcher<float> NanSensitiveFloatNear(
    float rhs, float max_abs_error) {
  return internal::FloatingEqMatcher<float>(rhs, true, max_abs_error);
}

// Creates a matcher that matches a pointer (raw or smart) that points
// to a value that matches inner_matcher.
template <typename InnerMatcher>
inline internal::PointeeMatcher<InnerMatcher> Pointee(
    const InnerMatcher& inner_matcher) {
  return internal::PointeeMatcher<InnerMatcher>(inner_matcher);
}

#if GTEST_HAS_RTTI
// Creates a matcher that matches a pointer or reference that matches
// inner_matcher when dynamic_cast<To> is applied.
// The result of dynamic_cast<To> is forwarded to the inner matcher.
// If To is a pointer and the cast fails, the inner matcher will receive NULL.
// If To is a reference and the cast fails, this matcher returns false
// immediately.
template <typename To>
inline PolymorphicMatcher<internal::WhenDynamicCastToMatcher<To> >
WhenDynamicCastTo(const Matcher<To>& inner_matcher) {
  return MakePolymorphicMatcher(
      internal::WhenDynamicCastToMatcher<To>(inner_matcher));
}
#endif  // GTEST_HAS_RTTI

// Creates a matcher that matches an object whose given field matches
// 'matcher'.  For example,
//   Field(&Foo::number, Ge(5))
// matches a Foo object x iff x.number >= 5.
template <typename Class, typename FieldType, typename FieldMatcher>
inline PolymorphicMatcher<
  internal::FieldMatcher<Class, FieldType> > Field(
    FieldType Class::*field, const FieldMatcher& matcher) {
  return MakePolymorphicMatcher(
      internal::FieldMatcher<Class, FieldType>(
          field, MatcherCast<const FieldType&>(matcher)));
  // The call to MatcherCast() is required for supporting inner
  // matchers of compatible types.  For example, it allows
  //   Field(&Foo::bar, m)
  // to compile where bar is an int32 and m is a matcher for int64.
}

// Same as Field() but also takes the name of the field to provide better error
// messages.
template <typename Class, typename FieldType, typename FieldMatcher>
inline PolymorphicMatcher<internal::FieldMatcher<Class, FieldType> > Field(
    const std::string& field_name, FieldType Class::*field,
    const FieldMatcher& matcher) {
  return MakePolymorphicMatcher(internal::FieldMatcher<Class, FieldType>(
      field_name, field, MatcherCast<const FieldType&>(matcher)));
}

// Creates a matcher that matches an object whose given property
// matches 'matcher'.  For example,
//   Property(&Foo::str, StartsWith("hi"))
// matches a Foo object x iff x.str() starts with "hi".
template <typename Class, typename PropertyType, typename PropertyMatcher>
inline PolymorphicMatcher<internal::PropertyMatcher<
    Class, PropertyType, PropertyType (Class::*)() const> >
Property(PropertyType (Class::*property)() const,
         const PropertyMatcher& matcher) {
  return MakePolymorphicMatcher(
      internal::PropertyMatcher<Class, PropertyType,
                                PropertyType (Class::*)() const>(
          property,
          MatcherCast<GTEST_REFERENCE_TO_CONST_(PropertyType)>(matcher)));
  // The call to MatcherCast() is required for supporting inner
  // matchers of compatible types.  For example, it allows
  //   Property(&Foo::bar, m)
  // to compile where bar() returns an int32 and m is a matcher for int64.
}

// Same as Property() above, but also takes the name of the property to provide
// better error messages.
template <typename Class, typename PropertyType, typename PropertyMatcher>
inline PolymorphicMatcher<internal::PropertyMatcher<
    Class, PropertyType, PropertyType (Class::*)() const> >
Property(const std::string& property_name,
         PropertyType (Class::*property)() const,
         const PropertyMatcher& matcher) {
  return MakePolymorphicMatcher(
      internal::PropertyMatcher<Class, PropertyType,
                                PropertyType (Class::*)() const>(
          property_name, property,
          MatcherCast<GTEST_REFERENCE_TO_CONST_(PropertyType)>(matcher)));
}

#if GTEST_LANG_CXX11
// The same as above but for reference-qualified member functions.
template <typename Class, typename PropertyType, typename PropertyMatcher>
inline PolymorphicMatcher<internal::PropertyMatcher<
    Class, PropertyType, PropertyType (Class::*)() const &> >
Property(PropertyType (Class::*property)() const &,
         const PropertyMatcher& matcher) {
  return MakePolymorphicMatcher(
      internal::PropertyMatcher<Class, PropertyType,
                                PropertyType (Class::*)() const &>(
          property,
          MatcherCast<GTEST_REFERENCE_TO_CONST_(PropertyType)>(matcher)));
}

// Three-argument form for reference-qualified member functions.
template <typename Class, typename PropertyType, typename PropertyMatcher>
inline PolymorphicMatcher<internal::PropertyMatcher<
    Class, PropertyType, PropertyType (Class::*)() const &> >
Property(const std::string& property_name,
         PropertyType (Class::*property)() const &,
         const PropertyMatcher& matcher) {
  return MakePolymorphicMatcher(
      internal::PropertyMatcher<Class, PropertyType,
                                PropertyType (Class::*)() const &>(
          property_name, property,
          MatcherCast<GTEST_REFERENCE_TO_CONST_(PropertyType)>(matcher)));
}
#endif

// Creates a matcher that matches an object iff the result of applying
// a callable to x matches 'matcher'.
// For example,
//   ResultOf(f, StartsWith("hi"))
// matches a Foo object x iff f(x) starts with "hi".
// callable parameter can be a function, function pointer, or a functor.
// Callable has to satisfy the following conditions:
//   * It is required to keep no state affecting the results of
//     the calls on it and make no assumptions about how many calls
//     will be made. Any state it keeps must be protected from the
//     concurrent access.
//   * If it is a function object, it has to define type result_type.
//     We recommend deriving your functor classes from std::unary_function.
//
template <typename Callable, typename ResultOfMatcher>
internal::ResultOfMatcher<Callable> ResultOf(
    Callable callable, const ResultOfMatcher& matcher) {
  return internal::ResultOfMatcher<Callable>(
          callable,
          MatcherCast<typename internal::CallableTraits<Callable>::ResultType>(
              matcher));
  // The call to MatcherCast() is required for supporting inner
  // matchers of compatible types.  For example, it allows
  //   ResultOf(Function, m)
  // to compile where Function() returns an int32 and m is a matcher for int64.
}

// String matchers.

// Matches a string equal to str.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::string> > StrEq(
    const std::string& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::string>(str, true, true));
}

// Matches a string not equal to str.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::string> > StrNe(
    const std::string& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::string>(str, false, true));
}

// Matches a string equal to str, ignoring case.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::string> > StrCaseEq(
    const std::string& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::string>(str, true, false));
}

// Matches a string not equal to str, ignoring case.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::string> > StrCaseNe(
    const std::string& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::string>(str, false, false));
}

// Creates a matcher that matches any string, std::string, or C string
// that contains the given substring.
inline PolymorphicMatcher<internal::HasSubstrMatcher<std::string> > HasSubstr(
    const std::string& substring) {
  return MakePolymorphicMatcher(
      internal::HasSubstrMatcher<std::string>(substring));
}

// Matches a string that starts with 'prefix' (case-sensitive).
inline PolymorphicMatcher<internal::StartsWithMatcher<std::string> > StartsWith(
    const std::string& prefix) {
  return MakePolymorphicMatcher(
      internal::StartsWithMatcher<std::string>(prefix));
}

// Matches a string that ends with 'suffix' (case-sensitive).
inline PolymorphicMatcher<internal::EndsWithMatcher<std::string> > EndsWith(
    const std::string& suffix) {
  return MakePolymorphicMatcher(internal::EndsWithMatcher<std::string>(suffix));
}

// Matches a string that fully matches regular expression 'regex'.
// The matcher takes ownership of 'regex'.
inline PolymorphicMatcher<internal::MatchesRegexMatcher> MatchesRegex(
    const internal::RE* regex) {
  return MakePolymorphicMatcher(internal::MatchesRegexMatcher(regex, true));
}
inline PolymorphicMatcher<internal::MatchesRegexMatcher> MatchesRegex(
    const std::string& regex) {
  return MatchesRegex(new internal::RE(regex));
}

// Matches a string that contains regular expression 'regex'.
// The matcher takes ownership of 'regex'.
inline PolymorphicMatcher<internal::MatchesRegexMatcher> ContainsRegex(
    const internal::RE* regex) {
  return MakePolymorphicMatcher(internal::MatchesRegexMatcher(regex, false));
}
inline PolymorphicMatcher<internal::MatchesRegexMatcher> ContainsRegex(
    const std::string& regex) {
  return ContainsRegex(new internal::RE(regex));
}

#if GTEST_HAS_GLOBAL_WSTRING || GTEST_HAS_STD_WSTRING
// Wide string matchers.

// Matches a string equal to str.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::wstring> > StrEq(
    const std::wstring& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::wstring>(str, true, true));
}

// Matches a string not equal to str.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::wstring> > StrNe(
    const std::wstring& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::wstring>(str, false, true));
}

// Matches a string equal to str, ignoring case.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::wstring> >
StrCaseEq(const std::wstring& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::wstring>(str, true, false));
}

// Matches a string not equal to str, ignoring case.
inline PolymorphicMatcher<internal::StrEqualityMatcher<std::wstring> >
StrCaseNe(const std::wstring& str) {
  return MakePolymorphicMatcher(
      internal::StrEqualityMatcher<std::wstring>(str, false, false));
}

// Creates a matcher that matches any ::wstring, std::wstring, or C wide string
// that contains the given substring.
inline PolymorphicMatcher<internal::HasSubstrMatcher<std::wstring> > HasSubstr(
    const std::wstring& substring) {
  return MakePolymorphicMatcher(
      internal::HasSubstrMatcher<std::wstring>(substring));
}

// Matches a string that starts with 'prefix' (case-sensitive).
inline PolymorphicMatcher<internal::StartsWithMatcher<std::wstring> >
StartsWith(const std::wstring& prefix) {
  return MakePolymorphicMatcher(
      internal::StartsWithMatcher<std::wstring>(prefix));
}

// Matches a string that ends with 'suffix' (case-sensitive).
inline PolymorphicMatcher<internal::EndsWithMatcher<std::wstring> > EndsWith(
    const std::wstring& suffix) {
  return MakePolymorphicMatcher(
      internal::EndsWithMatcher<std::wstring>(suffix));
}

#endif  // GTEST_HAS_GLOBAL_WSTRING || GTEST_HAS_STD_WSTRING

// Creates a polymorphic matcher that matches a 2-tuple where the
// first field == the second field.
inline internal::Eq2Matcher Eq() { return internal::Eq2Matcher(); }

// Creates a polymorphic matcher that matches a 2-tuple where the
// first field >= the second field.
inline internal::Ge2Matcher Ge() { return internal::Ge2Matcher(); }

// Creates a polymorphic matcher that matches a 2-tuple where the
// first field > the second field.
inline internal::Gt2Matcher Gt() { return internal::Gt2Matcher(); }

// Creates a polymorphic matcher that matches a 2-tuple where the
// first field <= the second field.
inline internal::Le2Matcher Le() { return internal::Le2Matcher(); }

// Creates a polymorphic matcher that matches a 2-tuple where the
// first field < the second field.
inline internal::Lt2Matcher Lt() { return internal::Lt2Matcher(); }

// Creates a polymorphic matcher that matches a 2-tuple where the
// first field != the second field.
inline internal::Ne2Matcher Ne() { return internal::Ne2Matcher(); }

// Creates a polymorphic matcher that matches a 2-tuple where
// FloatEq(first field) matches the second field.
inline internal::FloatingEq2Matcher<float> FloatEq() {
  return internal::FloatingEq2Matcher<float>();
}

// Creates a polymorphic matcher that matches a 2-tuple where
// DoubleEq(first field) matches the second field.
inline internal::FloatingEq2Matcher<double> DoubleEq() {
  return internal::FloatingEq2Matcher<double>();
}

// Creates a polymorphic matcher that matches a 2-tuple where
// FloatEq(first field) matches the second field with NaN equality.
inline internal::FloatingEq2Matcher<float> NanSensitiveFloatEq() {
  return internal::FloatingEq2Matcher<float>(true);
}

// Creates a polymorphic matcher that matches a 2-tuple where
// DoubleEq(first field) matches the second field with NaN equality.
inline internal::FloatingEq2Matcher<double> NanSensitiveDoubleEq() {
  return internal::FloatingEq2Matcher<double>(true);
}

// Creates a polymorphic matcher that matches a 2-tuple where
// FloatNear(first field, max_abs_error) matches the second field.
inline internal::FloatingEq2Matcher<float> FloatNear(float max_abs_error) {
  return internal::FloatingEq2Matcher<float>(max_abs_error);
}

// Creates a polymorphic matcher that matches a 2-tuple where
// DoubleNear(first field, max_abs_error) matches the second field.
inline internal::FloatingEq2Matcher<double> DoubleNear(double max_abs_error) {
  return internal::FloatingEq2Matcher<double>(max_abs_error);
}

// Creates a polymorphic matcher that matches a 2-tuple where
// FloatNear(first field, max_abs_error) matches the second field with NaN
// equality.
inline internal::FloatingEq2Matcher<float> NanSensitiveFloatNear(
    float max_abs_error) {
  return internal::FloatingEq2Matcher<float>(max_abs_error, true);
}

// Creates a polymorphic matcher that matches a 2-tuple where
// DoubleNear(first field, max_abs_error) matches the second field with NaN
// equality.
inline internal::FloatingEq2Matcher<double> NanSensitiveDoubleNear(
    double max_abs_error) {
  return internal::FloatingEq2Matcher<double>(max_abs_error, true);
}

// Creates a matcher that matches any value of type T that m doesn't
// match.
template <typename InnerMatcher>
inline internal::NotMatcher<InnerMatcher> Not(InnerMatcher m) {
  return internal::NotMatcher<InnerMatcher>(m);
}

// Returns a matcher that matches anything that satisfies the given
// predicate.  The predicate can be any unary function or functor
// whose return type can be implicitly converted to bool.
template <typename Predicate>
inline PolymorphicMatcher<internal::TrulyMatcher<Predicate> >
Truly(Predicate pred) {
  return MakePolymorphicMatcher(internal::TrulyMatcher<Predicate>(pred));
}

// Returns a matcher that matches the container size. The container must
// support both size() and size_type which all STL-like containers provide.
// Note that the parameter 'size' can be a value of type size_type as well as
// matcher. For instance:
//   EXPECT_THAT(container, SizeIs(2));     // Checks container has 2 elements.
//   EXPECT_THAT(container, SizeIs(Le(2));  // Checks container has at most 2.
template <typename SizeMatcher>
inline internal::SizeIsMatcher<SizeMatcher>
SizeIs(const SizeMatcher& size_matcher) {
  return internal::SizeIsMatcher<SizeMatcher>(size_matcher);
}

// Returns a matcher that matches the distance between the container's begin()
// iterator and its end() iterator, i.e. the size of the container. This matcher
// can be used instead of SizeIs with containers such as std::forward_list which
// do not implement size(). The container must provide const_iterator (with
// valid iterator_traits), begin() and end().
template <typename DistanceMatcher>
inline internal::BeginEndDistanceIsMatcher<DistanceMatcher>
BeginEndDistanceIs(const DistanceMatcher& distance_matcher) {
  return internal::BeginEndDistanceIsMatcher<DistanceMatcher>(distance_matcher);
}

// Returns a matcher that matches an equal container.
// This matcher behaves like Eq(), but in the event of mismatch lists the
// values that are included in one container but not the other. (Duplicate
// values and order differences are not explained.)
template <typename Container>
inline PolymorphicMatcher<internal::ContainerEqMatcher<  // NOLINT
                            GTEST_REMOVE_CONST_(Container)> >
    ContainerEq(const Container& rhs) {
  // This following line is for working around a bug in MSVC 8.0,
  // which causes Container to be a const type sometimes.
  typedef GTEST_REMOVE_CONST_(Container) RawContainer;
  return MakePolymorphicMatcher(
      internal::ContainerEqMatcher<RawContainer>(rhs));
}

// Returns a matcher that matches a container that, when sorted using
// the given comparator, matches container_matcher.
template <typename Comparator, typename ContainerMatcher>
inline internal::WhenSortedByMatcher<Comparator, ContainerMatcher>
WhenSortedBy(const Comparator& comparator,
             const ContainerMatcher& container_matcher) {
  return internal::WhenSortedByMatcher<Comparator, ContainerMatcher>(
      comparator, container_matcher);
}

// Returns a matcher that matches a container that, when sorted using
// the < operator, matches container_matcher.
template <typename ContainerMatcher>
inline internal::WhenSortedByMatcher<internal::LessComparator, ContainerMatcher>
WhenSorted(const ContainerMatcher& container_matcher) {
  return
      internal::WhenSortedByMatcher<internal::LessComparator, ContainerMatcher>(
          internal::LessComparator(), container_matcher);
}

// Matches an STL-style container or a native array that contains the
// same number of elements as in rhs, where its i-th element and rhs's
// i-th element (as a pair) satisfy the given pair matcher, for all i.
// TupleMatcher must be able to be safely cast to Matcher<tuple<const
// T1&, const T2&> >, where T1 and T2 are the types of elements in the
// LHS container and the RHS container respectively.
template <typename TupleMatcher, typename Container>
inline internal::PointwiseMatcher<TupleMatcher,
                                  GTEST_REMOVE_CONST_(Container)>
Pointwise(const TupleMatcher& tuple_matcher, const Container& rhs) {
  // This following line is for working around a bug in MSVC 8.0,
  // which causes Container to be a const type sometimes (e.g. when
  // rhs is a const int[])..
  typedef GTEST_REMOVE_CONST_(Container) RawContainer;
  return internal::PointwiseMatcher<TupleMatcher, RawContainer>(
      tuple_matcher, rhs);
}

#if GTEST_HAS_STD_INITIALIZER_LIST_

// Supports the Pointwise(m, {a, b, c}) syntax.
template <typename TupleMatcher, typename T>
inline internal::PointwiseMatcher<TupleMatcher, std::vector<T> > Pointwise(
    const TupleMatcher& tuple_matcher, std::initializer_list<T> rhs) {
  return Pointwise(tuple_matcher, std::vector<T>(rhs));
}

#endif  // GTEST_HAS_STD_INITIALIZER_LIST_

// UnorderedPointwise(pair_matcher, rhs) matches an STL-style
// container or a native array that contains the same number of
// elements as in rhs, where in some permutation of the container, its
// i-th element and rhs's i-th element (as a pair) satisfy the given
// pair matcher, for all i.  Tuple2Matcher must be able to be safely
// cast to Matcher<tuple<const T1&, const T2&> >, where T1 and T2 are
// the types of elements in the LHS container and the RHS container
// respectively.
//
// This is like Pointwise(pair_matcher, rhs), except that the element
// order doesn't matter.
template <typename Tuple2Matcher, typename RhsContainer>
inline internal::UnorderedElementsAreArrayMatcher<
    typename internal::BoundSecondMatcher<
        Tuple2Matcher, typename internal::StlContainerView<GTEST_REMOVE_CONST_(
                           RhsContainer)>::type::value_type> >
UnorderedPointwise(const Tuple2Matcher& tuple2_matcher,
                   const RhsContainer& rhs_container) {
  // This following line is for working around a bug in MSVC 8.0,
  // which causes RhsContainer to be a const type sometimes (e.g. when
  // rhs_container is a const int[]).
  typedef GTEST_REMOVE_CONST_(RhsContainer) RawRhsContainer;

  // RhsView allows the same code to handle RhsContainer being a
  // STL-style container and it being a native C-style array.
  typedef typename internal::StlContainerView<RawRhsContainer> RhsView;
  typedef typename RhsView::type RhsStlContainer;
  typedef typename RhsStlContainer::value_type Second;
  const RhsStlContainer& rhs_stl_container =
      RhsView::ConstReference(rhs_container);

  // Create a matcher for each element in rhs_container.
  ::std::vector<internal::BoundSecondMatcher<Tuple2Matcher, Second> > matchers;
  for (typename RhsStlContainer::const_iterator it = rhs_stl_container.begin();
       it != rhs_stl_container.end(); ++it) {
    matchers.push_back(
        internal::MatcherBindSecond(tuple2_matcher, *it));
  }

  // Delegate the work to UnorderedElementsAreArray().
  return UnorderedElementsAreArray(matchers);
}

#if GTEST_HAS_STD_INITIALIZER_LIST_

// Supports the UnorderedPointwise(m, {a, b, c}) syntax.
template <typename Tuple2Matcher, typename T>
inline internal::UnorderedElementsAreArrayMatcher<
    typename internal::BoundSecondMatcher<Tuple2Matcher, T> >
UnorderedPointwise(const Tuple2Matcher& tuple2_matcher,
                   std::initializer_list<T> rhs) {
  return UnorderedPointwise(tuple2_matcher, std::vector<T>(rhs));
}

#endif  // GTEST_HAS_STD_INITIALIZER_LIST_

// Matches an STL-style container or a native array that contains at
// least one element matching the given value or matcher.
//
// Examples:
//   ::std::set<int> page_ids;
//   page_ids.insert(3);
//   page_ids.insert(1);
//   EXPECT_THAT(page_ids, Contains(1));
//   EXPECT_THAT(page_ids, Contains(Gt(2)));
//   EXPECT_THAT(page_ids, Not(Contains(4)));
//
//   ::std::map<int, size_t> page_lengths;
//   page_lengths[1] = 100;
//   EXPECT_THAT(page_lengths,
//               Contains(::std::pair<const int, size_t>(1, 100)));
//
//   const char* user_ids[] = { "joe", "mike", "tom" };
//   EXPECT_THAT(user_ids, Contains(Eq(::std::string("tom"))));
template <typename M>
inline internal::ContainsMatcher<M> Contains(M matcher) {
  return internal::ContainsMatcher<M>(matcher);
}

// IsSupersetOf(iterator_first, iterator_last)
// IsSupersetOf(pointer, count)
// IsSupersetOf(array)
// IsSupersetOf(container)
// IsSupersetOf({e1, e2, ..., en})
//
// IsSupersetOf() verifies that a surjective partial mapping onto a collection
// of matchers exists. In other words, a container matches
// IsSupersetOf({e1, ..., en}) if and only if there is a permutation
// {y1, ..., yn} of some of the container's elements where y1 matches e1,
// ..., and yn matches en. Obviously, the size of the container must be >= n
// in order to have a match. Examples:
//
// - {1, 2, 3} matches IsSupersetOf({Ge(3), Ne(0)}), as 3 matches Ge(3) and
//   1 matches Ne(0).
// - {1, 2} doesn't match IsSupersetOf({Eq(1), Lt(2)}), even though 1 matches
//   both Eq(1) and Lt(2). The reason is that different matchers must be used
//   for elements in different slots of the container.
// - {1, 1, 2} matches IsSupersetOf({Eq(1), Lt(2)}), as (the first) 1 matches
//   Eq(1) and (the second) 1 matches Lt(2).
// - {1, 2, 3} matches IsSupersetOf(Gt(1), Gt(1)), as 2 matches (the first)
//   Gt(1) and 3 matches (the second) Gt(1).
//
// The matchers can be specified as an array, a pointer and count, a container,
// an initializer list, or an STL iterator range. In each of these cases, the
// underlying matchers can be either values or matchers.

template <typename Iter>
inline internal::UnorderedElementsAreArrayMatcher<
    typename ::std::iterator_traits<Iter>::value_type>
IsSupersetOf(Iter first, Iter last) {
  typedef typename ::std::iterator_traits<Iter>::value_type T;
  return internal::UnorderedElementsAreArrayMatcher<T>(
      internal::UnorderedMatcherRequire::Superset, first, last);
}

template <typename T>
inline internal::UnorderedElementsAreArrayMatcher<T> IsSupersetOf(
    const T* pointer, size_t count) {
  return IsSupersetOf(pointer, pointer + count);
}

template <typename T, size_t N>
inline internal::UnorderedElementsAreArrayMatcher<T> IsSupersetOf(
    const T (&array)[N]) {
  return IsSupersetOf(array, N);
}

template <typename Container>
inline internal::UnorderedElementsAreArrayMatcher<
    typename Container::value_type>
IsSupersetOf(const Container& container) {
  return IsSupersetOf(container.begin(), container.end());
}

#if GTEST_HAS_STD_INITIALIZER_LIST_
template <typename T>
inline internal::UnorderedElementsAreArrayMatcher<T> IsSupersetOf(
    ::std::initializer_list<T> xs) {
  return IsSupersetOf(xs.begin(), xs.end());
}
#endif

// IsSubsetOf(iterator_first, iterator_last)
// IsSubsetOf(pointer, count)
// IsSubsetOf(array)
// IsSubsetOf(container)
// IsSubsetOf({e1, e2, ..., en})
//
// IsSubsetOf() verifies that an injective mapping onto a collection of matchers
// exists.  In other words, a container matches IsSubsetOf({e1, ..., en}) if and
// only if there is a subset of matchers {m1, ..., mk} which would match the
// container using UnorderedElementsAre.  Obviously, the size of the container
// must be <= n in order to have a match. Examples:
//
// - {1} matches IsSubsetOf({Gt(0), Lt(0)}), as 1 matches Gt(0).
// - {1, -1} matches IsSubsetOf({Lt(0), Gt(0)}), as 1 matches Gt(0) and -1
//   matches Lt(0).
// - {1, 2} doesn't matches IsSubsetOf({Gt(0), Lt(0)}), even though 1 and 2 both
//   match Gt(0). The reason is that different matchers must be used for
//   elements in different slots of the container.
//
// The matchers can be specified as an array, a pointer and count, a container,
// an initializer list, or an STL iterator range. In each of these cases, the
// underlying matchers can be either values or matchers.

template <typename Iter>
inline internal::UnorderedElementsAreArrayMatcher<
    typename ::std::iterator_traits<Iter>::value_type>
IsSubsetOf(Iter first, Iter last) {
  typedef typename ::std::iterator_traits<Iter>::value_type T;
  return internal::UnorderedElementsAreArrayMatcher<T>(
      internal::UnorderedMatcherRequire::Subset, first, last);
}

template <typename T>
inline internal::UnorderedElementsAreArrayMatcher<T> IsSubsetOf(
    const T* pointer, size_t count) {
  return IsSubsetOf(pointer, pointer + count);
}

template <typename T, size_t N>
inline internal::UnorderedElementsAreArrayMatcher<T> IsSubsetOf(
    const T (&array)[N]) {
  return IsSubsetOf(array, N);
}

template <typename Container>
inline internal::UnorderedElementsAreArrayMatcher<
    typename Container::value_type>
IsSubsetOf(const Container& container) {
  return IsSubsetOf(container.begin(), container.end());
}

#if GTEST_HAS_STD_INITIALIZER_LIST_
template <typename T>
inline internal::UnorderedElementsAreArrayMatcher<T> IsSubsetOf(
    ::std::initializer_list<T> xs) {
  return IsSubsetOf(xs.begin(), xs.end());
}
#endif

// Matches an STL-style container or a native array that contains only
// elements matching the given value or matcher.
//
// Each(m) is semantically equivalent to Not(Contains(Not(m))). Only
// the messages are different.
//
// Examples:
//   ::std::set<int> page_ids;
//   // Each(m) matches an empty container, regardless of what m is.
//   EXPECT_THAT(page_ids, Each(Eq(1)));
//   EXPECT_THAT(page_ids, Each(Eq(77)));
//
//   page_ids.insert(3);
//   EXPECT_THAT(page_ids, Each(Gt(0)));
//   EXPECT_THAT(page_ids, Not(Each(Gt(4))));
//   page_ids.insert(1);
//   EXPECT_THAT(page_ids, Not(Each(Lt(2))));
//
//   ::std::map<int, size_t> page_lengths;
//   page_lengths[1] = 100;
//   page_lengths[2] = 200;
//   page_lengths[3] = 300;
//   EXPECT_THAT(page_lengths, Not(Each(Pair(1, 100))));
//   EXPECT_THAT(page_lengths, Each(Key(Le(3))));
//
//   const char* user_ids[] = { "joe", "mike", "tom" };
//   EXPECT_THAT(user_ids, Not(Each(Eq(::std::string("tom")))));
template <typename M>
inline internal::EachMatcher<M> Each(M matcher) {
  return internal::EachMatcher<M>(matcher);
}

// Key(inner_matcher) matches an std::pair whose 'first' field matches
// inner_matcher.  For example, Contains(Key(Ge(5))) can be used to match an
// std::map that contains at least one element whose key is >= 5.
template <typename M>
inline internal::KeyMatcher<M> Key(M inner_matcher) {
  return internal::KeyMatcher<M>(inner_matcher);
}

// Pair(first_matcher, second_matcher) matches a std::pair whose 'first' field
// matches first_matcher and whose 'second' field matches second_matcher.  For
// example, EXPECT_THAT(map_type, ElementsAre(Pair(Ge(5), "foo"))) can be used
// to match a std::map<int, string> that contains exactly one element whose key
// is >= 5 and whose value equals "foo".
template <typename FirstMatcher, typename SecondMatcher>
inline internal::PairMatcher<FirstMatcher, SecondMatcher>
Pair(FirstMatcher first_matcher, SecondMatcher second_matcher) {
  return internal::PairMatcher<FirstMatcher, SecondMatcher>(
      first_matcher, second_matcher);
}

// Returns a predicate that is satisfied by anything that matches the
// given matcher.
template <typename M>
inline internal::MatcherAsPredicate<M> Matches(M matcher) {
  return internal::MatcherAsPredicate<M>(matcher);
}

// Returns true iff the value matches the matcher.
template <typename T, typename M>
inline bool Value(const T& value, M matcher) {
  return testing::Matches(matcher)(value);
}

// Matches the value against the given matcher and explains the match
// result to listener.
template <typename T, typename M>
inline bool ExplainMatchResult(
    M matcher, const T& value, MatchResultListener* listener) {
  return SafeMatcherCast<const T&>(matcher).MatchAndExplain(value, listener);
}

// Returns a string representation of the given matcher.  Useful for description
// strings of matchers defined using MATCHER_P* macros that accept matchers as
// their arguments.  For example:
//
// MATCHER_P(XAndYThat, matcher,
//           "X that " + DescribeMatcher<int>(matcher, negation) +
//               " and Y that " + DescribeMatcher<double>(matcher, negation)) {
//   return ExplainMatchResult(matcher, arg.x(), result_listener) &&
//          ExplainMatchResult(matcher, arg.y(), result_listener);
// }
template <typename T, typename M>
std::string DescribeMatcher(const M& matcher, bool negation = false) {
  ::std::stringstream ss;
  Matcher<T> monomorphic_matcher = SafeMatcherCast<T>(matcher);
  if (negation) {
    monomorphic_matcher.DescribeNegationTo(&ss);
  } else {
    monomorphic_matcher.DescribeTo(&ss);
  }
  return ss.str();
}

#if GTEST_LANG_CXX11
// Define variadic matcher versions. They are overloaded in
// gmock-generated-matchers.h for the cases supported by pre C++11 compilers.
template <typename... Args>
internal::AllOfMatcher<typename std::decay<const Args&>::type...> AllOf(
    const Args&... matchers) {
  return internal::AllOfMatcher<typename std::decay<const Args&>::type...>(
      matchers...);
}

template <typename... Args>
internal::AnyOfMatcher<typename std::decay<const Args&>::type...> AnyOf(
    const Args&... matchers) {
  return internal::AnyOfMatcher<typename std::decay<const Args&>::type...>(
      matchers...);
}

template <typename... Args>
internal::ElementsAreMatcher<tuple<typename std::decay<const Args&>::type...>>
ElementsAre(const Args&... matchers) {
  return internal::ElementsAreMatcher<
      tuple<typename std::decay<const Args&>::type...>>(
      make_tuple(matchers...));
}

template <typename... Args>
internal::UnorderedElementsAreMatcher<
    tuple<typename std::decay<const Args&>::type...>>
UnorderedElementsAre(const Args&... matchers) {
  return internal::UnorderedElementsAreMatcher<
      tuple<typename std::decay<const Args&>::type...>>(
      make_tuple(matchers...));
}

#endif  // GTEST_LANG_CXX11

// AllArgs(m) is a synonym of m.  This is useful in
//
//   EXPECT_CALL(foo, Bar(_, _)).With(AllArgs(Eq()));
//
// which is easier to read than
//
//   EXPECT_CALL(foo, Bar(_, _)).With(Eq());
template <typename InnerMatcher>
inline InnerMatcher AllArgs(const InnerMatcher& matcher) { return matcher; }

// Returns a matcher that matches the value of an optional<> type variable.
// The matcher implementation only uses '!arg' and requires that the optional<>
// type has a 'value_type' member type and that '*arg' is of type 'value_type'
// and is printable using 'PrintToString'. It is compatible with
// std::optional/std::experimental::optional.
// Note that to compare an optional type variable against nullopt you should
// use Eq(nullopt) and not Optional(Eq(nullopt)). The latter implies that the
// optional value contains an optional itself.
template <typename ValueMatcher>
inline internal::OptionalMatcher<ValueMatcher> Optional(
    const ValueMatcher& value_matcher) {
  return internal::OptionalMatcher<ValueMatcher>(value_matcher);
}

// Returns a matcher that matches the value of a absl::any type variable.
template <typename T>
PolymorphicMatcher<internal::any_cast_matcher::AnyCastMatcher<T> > AnyWith(
    const Matcher<const T&>& matcher) {
  return MakePolymorphicMatcher(
      internal::any_cast_matcher::AnyCastMatcher<T>(matcher));
}

// Returns a matcher that matches the value of a variant<> type variable.
// The matcher implementation uses ADL to find the holds_alternative and get
// functions.
// It is compatible with std::variant.
template <typename T>
PolymorphicMatcher<internal::variant_matcher::VariantMatcher<T> > VariantWith(
    const Matcher<const T&>& matcher) {
  return MakePolymorphicMatcher(
      internal::variant_matcher::VariantMatcher<T>(matcher));
}

// These macros allow using matchers to check values in Google Test
// tests.  ASSERT_THAT(value, matcher) and EXPECT_THAT(value, matcher)
// succeed iff the value matches the matcher.  If the assertion fails,
// the value and the description of the matcher will be printed.
#define ASSERT_THAT(value, matcher) ASSERT_PRED_FORMAT1(\
    ::testing::internal::MakePredicateFormatterFromMatcher(matcher), value)
#define EXPECT_THAT(value, matcher) EXPECT_PRED_FORMAT1(\
    ::testing::internal::MakePredicateFormatterFromMatcher(matcher), value)

}  // namespace testing

// Include any custom callback matchers added by the local installation.
// We must include this header at the end to make sure it can use the
// declarations from this file.
// Copyright 2015, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ============================================================
// An installation-specific extension point for gmock-matchers.h.
// ============================================================
//
// Adds google3 callback support to CallableTraits.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_MATCHERS_H_
#define GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_MATCHERS_H_
#endif  // GMOCK_INCLUDE_GMOCK_INTERNAL_CUSTOM_GMOCK_MATCHERS_H_

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_MATCHERS_H_

#if GTEST_HAS_EXCEPTIONS
# include <stdexcept>  // NOLINT
#endif

namespace testing {

// An abstract handle of an expectation.
class Expectation;

// A set of expectation handles.
class ExpectationSet;

// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
// and MUST NOT BE USED IN USER CODE!!!
namespace internal {

// Implements a mock function.
template <typename F> class FunctionMocker;

// Base class for expectations.
class ExpectationBase;

// Implements an expectation.
template <typename F> class TypedExpectation;

// Helper class for testing the Expectation class template.
class ExpectationTester;

// Base class for function mockers.
template <typename F> class FunctionMockerBase;

// Protects the mock object registry (in class Mock), all function
// mockers, and all expectations.
//
// The reason we don't use more fine-grained protection is: when a
// mock function Foo() is called, it needs to consult its expectations
// to see which one should be picked.  If another thread is allowed to
// call a mock function (either Foo() or a different one) at the same
// time, it could affect the "retired" attributes of Foo()'s
// expectations when InSequence() is used, and thus affect which
// expectation gets picked.  Therefore, we sequence all mock function
// calls to ensure the integrity of the mock objects' states.
GTEST_API_ GTEST_DECLARE_STATIC_MUTEX_(g_gmock_mutex);

// Untyped base class for ActionResultHolder<R>.
class UntypedActionResultHolderBase;

// Abstract base class of FunctionMockerBase.  This is the
// type-agnostic part of the function mocker interface.  Its pure
// virtual methods are implemented by FunctionMockerBase.
class GTEST_API_ UntypedFunctionMockerBase {
 public:
  UntypedFunctionMockerBase();
  virtual ~UntypedFunctionMockerBase();

  // Verifies that all expectations on this mock function have been
  // satisfied.  Reports one or more Google Test non-fatal failures
  // and returns false if not.
  bool VerifyAndClearExpectationsLocked()
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Clears the ON_CALL()s set on this mock function.
  virtual void ClearDefaultActionsLocked()
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) = 0;

  // In all of the following Untyped* functions, it's the caller's
  // responsibility to guarantee the correctness of the arguments'
  // types.

  // Performs the default action with the given arguments and returns
  // the action's result.  The call description string will be used in
  // the error message to describe the call in the case the default
  // action fails.
  // L = *
  virtual UntypedActionResultHolderBase* UntypedPerformDefaultAction(
      void* untyped_args, const std::string& call_description) const = 0;

  // Performs the given action with the given arguments and returns
  // the action's result.
  // L = *
  virtual UntypedActionResultHolderBase* UntypedPerformAction(
      const void* untyped_action, void* untyped_args) const = 0;

  // Writes a message that the call is uninteresting (i.e. neither
  // explicitly expected nor explicitly unexpected) to the given
  // ostream.
  virtual void UntypedDescribeUninterestingCall(
      const void* untyped_args,
      ::std::ostream* os) const
          GTEST_LOCK_EXCLUDED_(g_gmock_mutex) = 0;

  // Returns the expectation that matches the given function arguments
  // (or NULL is there's no match); when a match is found,
  // untyped_action is set to point to the action that should be
  // performed (or NULL if the action is "do default"), and
  // is_excessive is modified to indicate whether the call exceeds the
  // expected number.
  virtual const ExpectationBase* UntypedFindMatchingExpectation(
      const void* untyped_args,
      const void** untyped_action, bool* is_excessive,
      ::std::ostream* what, ::std::ostream* why)
          GTEST_LOCK_EXCLUDED_(g_gmock_mutex) = 0;

  // Prints the given function arguments to the ostream.
  virtual void UntypedPrintArgs(const void* untyped_args,
                                ::std::ostream* os) const = 0;

  // Sets the mock object this mock method belongs to, and registers
  // this information in the global mock registry.  Will be called
  // whenever an EXPECT_CALL() or ON_CALL() is executed on this mock
  // method.
  // TODO(wan@google.com): rename to SetAndRegisterOwner().
  void RegisterOwner(const void* mock_obj)
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Sets the mock object this mock method belongs to, and sets the
  // name of the mock function.  Will be called upon each invocation
  // of this mock function.
  void SetOwnerAndName(const void* mock_obj, const char* name)
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Returns the mock object this mock method belongs to.  Must be
  // called after RegisterOwner() or SetOwnerAndName() has been
  // called.
  const void* MockObject() const
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Returns the name of this mock method.  Must be called after
  // SetOwnerAndName() has been called.
  const char* Name() const
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Returns the result of invoking this mock function with the given
  // arguments.  This function can be safely called from multiple
  // threads concurrently.  The caller is responsible for deleting the
  // result.
  UntypedActionResultHolderBase* UntypedInvokeWith(void* untyped_args)
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

 protected:
  typedef std::vector<const void*> UntypedOnCallSpecs;

  typedef std::vector<internal::linked_ptr<ExpectationBase> >
  UntypedExpectations;

  // Returns an Expectation object that references and co-owns exp,
  // which must be an expectation on this mock function.
  Expectation GetHandleOf(ExpectationBase* exp);

  // Address of the mock object this mock method belongs to.  Only
  // valid after this mock method has been called or
  // ON_CALL/EXPECT_CALL has been invoked on it.
  const void* mock_obj_;  // Protected by g_gmock_mutex.

  // Name of the function being mocked.  Only valid after this mock
  // method has been called.
  const char* name_;  // Protected by g_gmock_mutex.

  // All default action specs for this function mocker.
  UntypedOnCallSpecs untyped_on_call_specs_;

  // All expectations for this function mocker.
  //
  // It's undefined behavior to interleave expectations (EXPECT_CALLs
  // or ON_CALLs) and mock function calls.  Also, the order of
  // expectations is important.  Therefore it's a logic race condition
  // to read/write untyped_expectations_ concurrently.  In order for
  // tools like tsan to catch concurrent read/write accesses to
  // untyped_expectations, we deliberately leave accesses to it
  // unprotected.
  UntypedExpectations untyped_expectations_;
};  // class UntypedFunctionMockerBase

// Untyped base class for OnCallSpec<F>.
class UntypedOnCallSpecBase {
 public:
  // The arguments are the location of the ON_CALL() statement.
  UntypedOnCallSpecBase(const char* a_file, int a_line)
      : file_(a_file), line_(a_line), last_clause_(kNone) {}

  // Where in the source file was the default action spec defined?
  const char* file() const { return file_; }
  int line() const { return line_; }

 protected:
  // Gives each clause in the ON_CALL() statement a name.
  enum Clause {
    // Do not change the order of the enum members!  The run-time
    // syntax checking relies on it.
    kNone,
    kWith,
    kWillByDefault
  };

  // Asserts that the ON_CALL() statement has a certain property.
  void AssertSpecProperty(bool property,
                          const std::string& failure_message) const {
    Assert(property, file_, line_, failure_message);
  }

  // Expects that the ON_CALL() statement has a certain property.
  void ExpectSpecProperty(bool property,
                          const std::string& failure_message) const {
    Expect(property, file_, line_, failure_message);
  }

  const char* file_;
  int line_;

  // The last clause in the ON_CALL() statement as seen so far.
  // Initially kNone and changes as the statement is parsed.
  Clause last_clause_;
};  // class UntypedOnCallSpecBase

// This template class implements an ON_CALL spec.
template <typename F>
class OnCallSpec : public UntypedOnCallSpecBase {
 public:
  typedef typename Function<F>::ArgumentTuple ArgumentTuple;
  typedef typename Function<F>::ArgumentMatcherTuple ArgumentMatcherTuple;

  // Constructs an OnCallSpec object from the information inside
  // the parenthesis of an ON_CALL() statement.
  OnCallSpec(const char* a_file, int a_line,
             const ArgumentMatcherTuple& matchers)
      : UntypedOnCallSpecBase(a_file, a_line),
        matchers_(matchers),
        // By default, extra_matcher_ should match anything.  However,
        // we cannot initialize it with _ as that triggers a compiler
        // bug in Symbian's C++ compiler (cannot decide between two
        // overloaded constructors of Matcher<const ArgumentTuple&>).
        extra_matcher_(A<const ArgumentTuple&>()) {
  }

  // Implements the .With() clause.
  OnCallSpec& With(const Matcher<const ArgumentTuple&>& m) {
    // Makes sure this is called at most once.
    ExpectSpecProperty(last_clause_ < kWith,
                       ".With() cannot appear "
                       "more than once in an ON_CALL().");
    last_clause_ = kWith;

    extra_matcher_ = m;
    return *this;
  }

  // Implements the .WillByDefault() clause.
  OnCallSpec& WillByDefault(const Action<F>& action) {
    ExpectSpecProperty(last_clause_ < kWillByDefault,
                       ".WillByDefault() must appear "
                       "exactly once in an ON_CALL().");
    last_clause_ = kWillByDefault;

    ExpectSpecProperty(!action.IsDoDefault(),
                       "DoDefault() cannot be used in ON_CALL().");
    action_ = action;
    return *this;
  }

  // Returns true iff the given arguments match the matchers.
  bool Matches(const ArgumentTuple& args) const {
    return TupleMatches(matchers_, args) && extra_matcher_.Matches(args);
  }

  // Returns the action specified by the user.
  const Action<F>& GetAction() const {
    AssertSpecProperty(last_clause_ == kWillByDefault,
                       ".WillByDefault() must appear exactly "
                       "once in an ON_CALL().");
    return action_;
  }

 private:
  // The information in statement
  //
  //   ON_CALL(mock_object, Method(matchers))
  //       .With(multi-argument-matcher)
  //       .WillByDefault(action);
  //
  // is recorded in the data members like this:
  //
  //   source file that contains the statement => file_
  //   line number of the statement            => line_
  //   matchers                                => matchers_
  //   multi-argument-matcher                  => extra_matcher_
  //   action                                  => action_
  ArgumentMatcherTuple matchers_;
  Matcher<const ArgumentTuple&> extra_matcher_;
  Action<F> action_;
};  // class OnCallSpec

// Possible reactions on uninteresting calls.
enum CallReaction {
  kAllow,
  kWarn,
  kFail,
};

}  // namespace internal

// Utilities for manipulating mock objects.
class GTEST_API_ Mock {
 public:
  // The following public methods can be called concurrently.

  // Tells Google Mock to ignore mock_obj when checking for leaked
  // mock objects.
  static void AllowLeak(const void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Verifies and clears all expectations on the given mock object.
  // If the expectations aren't satisfied, generates one or more
  // Google Test non-fatal failures and returns false.
  static bool VerifyAndClearExpectations(void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Verifies all expectations on the given mock object and clears its
  // default actions and expectations.  Returns true iff the
  // verification was successful.
  static bool VerifyAndClear(void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

 private:
  friend class internal::UntypedFunctionMockerBase;

  // Needed for a function mocker to register itself (so that we know
  // how to clear a mock object).
  template <typename F>
  friend class internal::FunctionMockerBase;

  template <typename M>
  friend class NiceMock;

  template <typename M>
  friend class NaggyMock;

  template <typename M>
  friend class StrictMock;

  // Tells Google Mock to allow uninteresting calls on the given mock
  // object.
  static void AllowUninterestingCalls(const void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock to warn the user about uninteresting calls on
  // the given mock object.
  static void WarnUninterestingCalls(const void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock to fail uninteresting calls on the given mock
  // object.
  static void FailUninterestingCalls(const void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock the given mock object is being destroyed and
  // its entry in the call-reaction table should be removed.
  static void UnregisterCallReaction(const void* mock_obj)
      GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Returns the reaction Google Mock will have on uninteresting calls
  // made on the given mock object.
  static internal::CallReaction GetReactionOnUninterestingCalls(
      const void* mock_obj)
          GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Verifies that all expectations on the given mock object have been
  // satisfied.  Reports one or more Google Test non-fatal failures
  // and returns false if not.
  static bool VerifyAndClearExpectationsLocked(void* mock_obj)
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex);

  // Clears all ON_CALL()s set on the given mock object.
  static void ClearDefaultActionsLocked(void* mock_obj)
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex);

  // Registers a mock object and a mock method it owns.
  static void Register(
      const void* mock_obj,
      internal::UntypedFunctionMockerBase* mocker)
          GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock where in the source code mock_obj is used in an
  // ON_CALL or EXPECT_CALL.  In case mock_obj is leaked, this
  // information helps the user identify which object it is.
  static void RegisterUseByOnCallOrExpectCall(
      const void* mock_obj, const char* file, int line)
          GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Unregisters a mock method; removes the owning mock object from
  // the registry when the last mock method associated with it has
  // been unregistered.  This is called only in the destructor of
  // FunctionMockerBase.
  static void UnregisterLocked(internal::UntypedFunctionMockerBase* mocker)
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex);
};  // class Mock

// An abstract handle of an expectation.  Useful in the .After()
// clause of EXPECT_CALL() for setting the (partial) order of
// expectations.  The syntax:
//
//   Expectation e1 = EXPECT_CALL(...)...;
//   EXPECT_CALL(...).After(e1)...;
//
// sets two expectations where the latter can only be matched after
// the former has been satisfied.
//
// Notes:
//   - This class is copyable and has value semantics.
//   - Constness is shallow: a const Expectation object itself cannot
//     be modified, but the mutable methods of the ExpectationBase
//     object it references can be called via expectation_base().
//   - The constructors and destructor are defined out-of-line because
//     the Symbian WINSCW compiler wants to otherwise instantiate them
//     when it sees this class definition, at which point it doesn't have
//     ExpectationBase available yet, leading to incorrect destruction
//     in the linked_ptr (or compilation errors if using a checking
//     linked_ptr).
class GTEST_API_ Expectation {
 public:
  // Constructs a null object that doesn't reference any expectation.
  Expectation();

  ~Expectation();

  // This single-argument ctor must not be explicit, in order to support the
  //   Expectation e = EXPECT_CALL(...);
  // syntax.
  //
  // A TypedExpectation object stores its pre-requisites as
  // Expectation objects, and needs to call the non-const Retire()
  // method on the ExpectationBase objects they reference.  Therefore
  // Expectation must receive a *non-const* reference to the
  // ExpectationBase object.
  Expectation(internal::ExpectationBase& exp);  // NOLINT

  // The compiler-generated copy ctor and operator= work exactly as
  // intended, so we don't need to define our own.

  // Returns true iff rhs references the same expectation as this object does.
  bool operator==(const Expectation& rhs) const {
    return expectation_base_ == rhs.expectation_base_;
  }

  bool operator!=(const Expectation& rhs) const { return !(*this == rhs); }

 private:
  friend class ExpectationSet;
  friend class Sequence;
  friend class ::testing::internal::ExpectationBase;
  friend class ::testing::internal::UntypedFunctionMockerBase;

  template <typename F>
  friend class ::testing::internal::FunctionMockerBase;

  template <typename F>
  friend class ::testing::internal::TypedExpectation;

  // This comparator is needed for putting Expectation objects into a set.
  class Less {
   public:
    bool operator()(const Expectation& lhs, const Expectation& rhs) const {
      return lhs.expectation_base_.get() < rhs.expectation_base_.get();
    }
  };

  typedef ::std::set<Expectation, Less> Set;

  Expectation(
      const internal::linked_ptr<internal::ExpectationBase>& expectation_base);

  // Returns the expectation this object references.
  const internal::linked_ptr<internal::ExpectationBase>&
  expectation_base() const {
    return expectation_base_;
  }

  // A linked_ptr that co-owns the expectation this handle references.
  internal::linked_ptr<internal::ExpectationBase> expectation_base_;
};

// A set of expectation handles.  Useful in the .After() clause of
// EXPECT_CALL() for setting the (partial) order of expectations.  The
// syntax:
//
//   ExpectationSet es;
//   es += EXPECT_CALL(...)...;
//   es += EXPECT_CALL(...)...;
//   EXPECT_CALL(...).After(es)...;
//
// sets three expectations where the last one can only be matched
// after the first two have both been satisfied.
//
// This class is copyable and has value semantics.
class ExpectationSet {
 public:
  // A bidirectional iterator that can read a const element in the set.
  typedef Expectation::Set::const_iterator const_iterator;

  // An object stored in the set.  This is an alias of Expectation.
  typedef Expectation::Set::value_type value_type;

  // Constructs an empty set.
  ExpectationSet() {}

  // This single-argument ctor must not be explicit, in order to support the
  //   ExpectationSet es = EXPECT_CALL(...);
  // syntax.
  ExpectationSet(internal::ExpectationBase& exp) {  // NOLINT
    *this += Expectation(exp);
  }

  // This single-argument ctor implements implicit conversion from
  // Expectation and thus must not be explicit.  This allows either an
  // Expectation or an ExpectationSet to be used in .After().
  ExpectationSet(const Expectation& e) {  // NOLINT
    *this += e;
  }

  // The compiler-generator ctor and operator= works exactly as
  // intended, so we don't need to define our own.

  // Returns true iff rhs contains the same set of Expectation objects
  // as this does.
  bool operator==(const ExpectationSet& rhs) const {
    return expectations_ == rhs.expectations_;
  }

  bool operator!=(const ExpectationSet& rhs) const { return !(*this == rhs); }

  // Implements the syntax
  //   expectation_set += EXPECT_CALL(...);
  ExpectationSet& operator+=(const Expectation& e) {
    expectations_.insert(e);
    return *this;
  }

  int size() const { return static_cast<int>(expectations_.size()); }

  const_iterator begin() const { return expectations_.begin(); }
  const_iterator end() const { return expectations_.end(); }

 private:
  Expectation::Set expectations_;
};


// Sequence objects are used by a user to specify the relative order
// in which the expectations should match.  They are copyable (we rely
// on the compiler-defined copy constructor and assignment operator).
class GTEST_API_ Sequence {
 public:
  // Constructs an empty sequence.
  Sequence() : last_expectation_(new Expectation) {}

  // Adds an expectation to this sequence.  The caller must ensure
  // that no other thread is accessing this Sequence object.
  void AddExpectation(const Expectation& expectation) const;

 private:
  // The last expectation in this sequence.  We use a linked_ptr here
  // because Sequence objects are copyable and we want the copies to
  // be aliases.  The linked_ptr allows the copies to co-own and share
  // the same Expectation object.
  internal::linked_ptr<Expectation> last_expectation_;
};  // class Sequence

// An object of this type causes all EXPECT_CALL() statements
// encountered in its scope to be put in an anonymous sequence.  The
// work is done in the constructor and destructor.  You should only
// create an InSequence object on the stack.
//
// The sole purpose for this class is to support easy definition of
// sequential expectations, e.g.
//
//   {
//     InSequence dummy;  // The name of the object doesn't matter.
//
//     // The following expectations must match in the order they appear.
//     EXPECT_CALL(a, Bar())...;
//     EXPECT_CALL(a, Baz())...;
//     ...
//     EXPECT_CALL(b, Xyz())...;
//   }
//
// You can create InSequence objects in multiple threads, as long as
// they are used to affect different mock objects.  The idea is that
// each thread can create and set up its own mocks as if it's the only
// thread.  However, for clarity of your tests we recommend you to set
// up mocks in the main thread unless you have a good reason not to do
// so.
class GTEST_API_ InSequence {
 public:
  InSequence();
  ~InSequence();
 private:
  bool sequence_created_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(InSequence);  // NOLINT
} GTEST_ATTRIBUTE_UNUSED_;

namespace internal {

// Points to the implicit sequence introduced by a living InSequence
// object (if any) in the current thread or NULL.
GTEST_API_ extern ThreadLocal<Sequence*> g_gmock_implicit_sequence;

// Base class for implementing expectations.
//
// There are two reasons for having a type-agnostic base class for
// Expectation:
//
//   1. We need to store collections of expectations of different
//   types (e.g. all pre-requisites of a particular expectation, all
//   expectations in a sequence).  Therefore these expectation objects
//   must share a common base class.
//
//   2. We can avoid binary code bloat by moving methods not depending
//   on the template argument of Expectation to the base class.
//
// This class is internal and mustn't be used by user code directly.
class GTEST_API_ ExpectationBase {
 public:
  // source_text is the EXPECT_CALL(...) source that created this Expectation.
  ExpectationBase(const char* file, int line, const std::string& source_text);

  virtual ~ExpectationBase();

  // Where in the source file was the expectation spec defined?
  const char* file() const { return file_; }
  int line() const { return line_; }
  const char* source_text() const { return source_text_.c_str(); }
  // Returns the cardinality specified in the expectation spec.
  const Cardinality& cardinality() const { return cardinality_; }

  // Describes the source file location of this expectation.
  void DescribeLocationTo(::std::ostream* os) const {
    *os << FormatFileLocation(file(), line()) << " ";
  }

  // Describes how many times a function call matching this
  // expectation has occurred.
  void DescribeCallCountTo(::std::ostream* os) const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // If this mock method has an extra matcher (i.e. .With(matcher)),
  // describes it to the ostream.
  virtual void MaybeDescribeExtraMatcherTo(::std::ostream* os) = 0;

 protected:
  friend class ::testing::Expectation;
  friend class UntypedFunctionMockerBase;

  enum Clause {
    // Don't change the order of the enum members!
    kNone,
    kWith,
    kTimes,
    kInSequence,
    kAfter,
    kWillOnce,
    kWillRepeatedly,
    kRetiresOnSaturation
  };

  typedef std::vector<const void*> UntypedActions;

  // Returns an Expectation object that references and co-owns this
  // expectation.
  virtual Expectation GetHandle() = 0;

  // Asserts that the EXPECT_CALL() statement has the given property.
  void AssertSpecProperty(bool property,
                          const std::string& failure_message) const {
    Assert(property, file_, line_, failure_message);
  }

  // Expects that the EXPECT_CALL() statement has the given property.
  void ExpectSpecProperty(bool property,
                          const std::string& failure_message) const {
    Expect(property, file_, line_, failure_message);
  }

  // Explicitly specifies the cardinality of this expectation.  Used
  // by the subclasses to implement the .Times() clause.
  void SpecifyCardinality(const Cardinality& cardinality);

  // Returns true iff the user specified the cardinality explicitly
  // using a .Times().
  bool cardinality_specified() const { return cardinality_specified_; }

  // Sets the cardinality of this expectation spec.
  void set_cardinality(const Cardinality& a_cardinality) {
    cardinality_ = a_cardinality;
  }

  // The following group of methods should only be called after the
  // EXPECT_CALL() statement, and only when g_gmock_mutex is held by
  // the current thread.

  // Retires all pre-requisites of this expectation.
  void RetireAllPreRequisites()
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Returns true iff this expectation is retired.
  bool is_retired() const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return retired_;
  }

  // Retires this expectation.
  void Retire()
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    retired_ = true;
  }

  // Returns true iff this expectation is satisfied.
  bool IsSatisfied() const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return cardinality().IsSatisfiedByCallCount(call_count_);
  }

  // Returns true iff this expectation is saturated.
  bool IsSaturated() const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return cardinality().IsSaturatedByCallCount(call_count_);
  }

  // Returns true iff this expectation is over-saturated.
  bool IsOverSaturated() const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return cardinality().IsOverSaturatedByCallCount(call_count_);
  }

  // Returns true iff all pre-requisites of this expectation are satisfied.
  bool AllPrerequisitesAreSatisfied() const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Adds unsatisfied pre-requisites of this expectation to 'result'.
  void FindUnsatisfiedPrerequisites(ExpectationSet* result) const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Returns the number this expectation has been invoked.
  int call_count() const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return call_count_;
  }

  // Increments the number this expectation has been invoked.
  void IncrementCallCount()
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    call_count_++;
  }

  // Checks the action count (i.e. the number of WillOnce() and
  // WillRepeatedly() clauses) against the cardinality if this hasn't
  // been done before.  Prints a warning if there are too many or too
  // few actions.
  void CheckActionCountIfNotDone() const
      GTEST_LOCK_EXCLUDED_(mutex_);

  friend class ::testing::Sequence;
  friend class ::testing::internal::ExpectationTester;

  template <typename Function>
  friend class TypedExpectation;

  // Implements the .Times() clause.
  void UntypedTimes(const Cardinality& a_cardinality);

  // This group of fields are part of the spec and won't change after
  // an EXPECT_CALL() statement finishes.
  const char* file_;          // The file that contains the expectation.
  int line_;                  // The line number of the expectation.
  const std::string source_text_;  // The EXPECT_CALL(...) source text.
  // True iff the cardinality is specified explicitly.
  bool cardinality_specified_;
  Cardinality cardinality_;            // The cardinality of the expectation.
  // The immediate pre-requisites (i.e. expectations that must be
  // satisfied before this expectation can be matched) of this
  // expectation.  We use linked_ptr in the set because we want an
  // Expectation object to be co-owned by its FunctionMocker and its
  // successors.  This allows multiple mock objects to be deleted at
  // different times.
  ExpectationSet immediate_prerequisites_;

  // This group of fields are the current state of the expectation,
  // and can change as the mock function is called.
  int call_count_;  // How many times this expectation has been invoked.
  bool retired_;    // True iff this expectation has retired.
  UntypedActions untyped_actions_;
  bool extra_matcher_specified_;
  bool repeated_action_specified_;  // True if a WillRepeatedly() was specified.
  bool retires_on_saturation_;
  Clause last_clause_;
  mutable bool action_count_checked_;  // Under mutex_.
  mutable Mutex mutex_;  // Protects action_count_checked_.

  GTEST_DISALLOW_ASSIGN_(ExpectationBase);
};  // class ExpectationBase

// Impements an expectation for the given function type.
template <typename F>
class TypedExpectation : public ExpectationBase {
 public:
  typedef typename Function<F>::ArgumentTuple ArgumentTuple;
  typedef typename Function<F>::ArgumentMatcherTuple ArgumentMatcherTuple;
  typedef typename Function<F>::Result Result;

  TypedExpectation(FunctionMockerBase<F>* owner, const char* a_file, int a_line,
                   const std::string& a_source_text,
                   const ArgumentMatcherTuple& m)
      : ExpectationBase(a_file, a_line, a_source_text),
        owner_(owner),
        matchers_(m),
        // By default, extra_matcher_ should match anything.  However,
        // we cannot initialize it with _ as that triggers a compiler
        // bug in Symbian's C++ compiler (cannot decide between two
        // overloaded constructors of Matcher<const ArgumentTuple&>).
        extra_matcher_(A<const ArgumentTuple&>()),
        repeated_action_(DoDefault()) {}

  virtual ~TypedExpectation() {
    // Check the validity of the action count if it hasn't been done
    // yet (for example, if the expectation was never used).
    CheckActionCountIfNotDone();
    for (UntypedActions::const_iterator it = untyped_actions_.begin();
         it != untyped_actions_.end(); ++it) {
      delete static_cast<const Action<F>*>(*it);
    }
  }

  // Implements the .With() clause.
  TypedExpectation& With(const Matcher<const ArgumentTuple&>& m) {
    if (last_clause_ == kWith) {
      ExpectSpecProperty(false,
                         ".With() cannot appear "
                         "more than once in an EXPECT_CALL().");
    } else {
      ExpectSpecProperty(last_clause_ < kWith,
                         ".With() must be the first "
                         "clause in an EXPECT_CALL().");
    }
    last_clause_ = kWith;

    extra_matcher_ = m;
    extra_matcher_specified_ = true;
    return *this;
  }

  // Implements the .Times() clause.
  TypedExpectation& Times(const Cardinality& a_cardinality) {
    ExpectationBase::UntypedTimes(a_cardinality);
    return *this;
  }

  // Implements the .Times() clause.
  TypedExpectation& Times(int n) {
    return Times(Exactly(n));
  }

  // Implements the .InSequence() clause.
  TypedExpectation& InSequence(const Sequence& s) {
    ExpectSpecProperty(last_clause_ <= kInSequence,
                       ".InSequence() cannot appear after .After(),"
                       " .WillOnce(), .WillRepeatedly(), or "
                       ".RetiresOnSaturation().");
    last_clause_ = kInSequence;

    s.AddExpectation(GetHandle());
    return *this;
  }
  TypedExpectation& InSequence(const Sequence& s1, const Sequence& s2) {
    return InSequence(s1).InSequence(s2);
  }
  TypedExpectation& InSequence(const Sequence& s1, const Sequence& s2,
                               const Sequence& s3) {
    return InSequence(s1, s2).InSequence(s3);
  }
  TypedExpectation& InSequence(const Sequence& s1, const Sequence& s2,
                               const Sequence& s3, const Sequence& s4) {
    return InSequence(s1, s2, s3).InSequence(s4);
  }
  TypedExpectation& InSequence(const Sequence& s1, const Sequence& s2,
                               const Sequence& s3, const Sequence& s4,
                               const Sequence& s5) {
    return InSequence(s1, s2, s3, s4).InSequence(s5);
  }

  // Implements that .After() clause.
  TypedExpectation& After(const ExpectationSet& s) {
    ExpectSpecProperty(last_clause_ <= kAfter,
                       ".After() cannot appear after .WillOnce(),"
                       " .WillRepeatedly(), or "
                       ".RetiresOnSaturation().");
    last_clause_ = kAfter;

    for (ExpectationSet::const_iterator it = s.begin(); it != s.end(); ++it) {
      immediate_prerequisites_ += *it;
    }
    return *this;
  }
  TypedExpectation& After(const ExpectationSet& s1, const ExpectationSet& s2) {
    return After(s1).After(s2);
  }
  TypedExpectation& After(const ExpectationSet& s1, const ExpectationSet& s2,
                          const ExpectationSet& s3) {
    return After(s1, s2).After(s3);
  }
  TypedExpectation& After(const ExpectationSet& s1, const ExpectationSet& s2,
                          const ExpectationSet& s3, const ExpectationSet& s4) {
    return After(s1, s2, s3).After(s4);
  }
  TypedExpectation& After(const ExpectationSet& s1, const ExpectationSet& s2,
                          const ExpectationSet& s3, const ExpectationSet& s4,
                          const ExpectationSet& s5) {
    return After(s1, s2, s3, s4).After(s5);
  }

  // Implements the .WillOnce() clause.
  TypedExpectation& WillOnce(const Action<F>& action) {
    ExpectSpecProperty(last_clause_ <= kWillOnce,
                       ".WillOnce() cannot appear after "
                       ".WillRepeatedly() or .RetiresOnSaturation().");
    last_clause_ = kWillOnce;

    untyped_actions_.push_back(new Action<F>(action));
    if (!cardinality_specified()) {
      set_cardinality(Exactly(static_cast<int>(untyped_actions_.size())));
    }
    return *this;
  }

  // Implements the .WillRepeatedly() clause.
  TypedExpectation& WillRepeatedly(const Action<F>& action) {
    if (last_clause_ == kWillRepeatedly) {
      ExpectSpecProperty(false,
                         ".WillRepeatedly() cannot appear "
                         "more than once in an EXPECT_CALL().");
    } else {
      ExpectSpecProperty(last_clause_ < kWillRepeatedly,
                         ".WillRepeatedly() cannot appear "
                         "after .RetiresOnSaturation().");
    }
    last_clause_ = kWillRepeatedly;
    repeated_action_specified_ = true;

    repeated_action_ = action;
    if (!cardinality_specified()) {
      set_cardinality(AtLeast(static_cast<int>(untyped_actions_.size())));
    }

    // Now that no more action clauses can be specified, we check
    // whether their count makes sense.
    CheckActionCountIfNotDone();
    return *this;
  }

  // Implements the .RetiresOnSaturation() clause.
  TypedExpectation& RetiresOnSaturation() {
    ExpectSpecProperty(last_clause_ < kRetiresOnSaturation,
                       ".RetiresOnSaturation() cannot appear "
                       "more than once.");
    last_clause_ = kRetiresOnSaturation;
    retires_on_saturation_ = true;

    // Now that no more action clauses can be specified, we check
    // whether their count makes sense.
    CheckActionCountIfNotDone();
    return *this;
  }

  // Returns the matchers for the arguments as specified inside the
  // EXPECT_CALL() macro.
  const ArgumentMatcherTuple& matchers() const {
    return matchers_;
  }

  // Returns the matcher specified by the .With() clause.
  const Matcher<const ArgumentTuple&>& extra_matcher() const {
    return extra_matcher_;
  }

  // Returns the action specified by the .WillRepeatedly() clause.
  const Action<F>& repeated_action() const { return repeated_action_; }

  // If this mock method has an extra matcher (i.e. .With(matcher)),
  // describes it to the ostream.
  virtual void MaybeDescribeExtraMatcherTo(::std::ostream* os) {
    if (extra_matcher_specified_) {
      *os << "    Expected args: ";
      extra_matcher_.DescribeTo(os);
      *os << "\n";
    }
  }

 private:
  template <typename Function>
  friend class FunctionMockerBase;

  // Returns an Expectation object that references and co-owns this
  // expectation.
  virtual Expectation GetHandle() {
    return owner_->GetHandleOf(this);
  }

  // The following methods will be called only after the EXPECT_CALL()
  // statement finishes and when the current thread holds
  // g_gmock_mutex.

  // Returns true iff this expectation matches the given arguments.
  bool Matches(const ArgumentTuple& args) const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return TupleMatches(matchers_, args) && extra_matcher_.Matches(args);
  }

  // Returns true iff this expectation should handle the given arguments.
  bool ShouldHandleArguments(const ArgumentTuple& args) const
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();

    // In case the action count wasn't checked when the expectation
    // was defined (e.g. if this expectation has no WillRepeatedly()
    // or RetiresOnSaturation() clause), we check it when the
    // expectation is used for the first time.
    CheckActionCountIfNotDone();
    return !is_retired() && AllPrerequisitesAreSatisfied() && Matches(args);
  }

  // Describes the result of matching the arguments against this
  // expectation to the given ostream.
  void ExplainMatchResultTo(
      const ArgumentTuple& args,
      ::std::ostream* os) const
          GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();

    if (is_retired()) {
      *os << "         Expected: the expectation is active\n"
          << "           Actual: it is retired\n";
    } else if (!Matches(args)) {
      if (!TupleMatches(matchers_, args)) {
        ExplainMatchFailureTupleTo(matchers_, args, os);
      }
      StringMatchResultListener listener;
      if (!extra_matcher_.MatchAndExplain(args, &listener)) {
        *os << "    Expected args: ";
        extra_matcher_.DescribeTo(os);
        *os << "\n           Actual: don't match";

        internal::PrintIfNotEmpty(listener.str(), os);
        *os << "\n";
      }
    } else if (!AllPrerequisitesAreSatisfied()) {
      *os << "         Expected: all pre-requisites are satisfied\n"
          << "           Actual: the following immediate pre-requisites "
          << "are not satisfied:\n";
      ExpectationSet unsatisfied_prereqs;
      FindUnsatisfiedPrerequisites(&unsatisfied_prereqs);
      int i = 0;
      for (ExpectationSet::const_iterator it = unsatisfied_prereqs.begin();
           it != unsatisfied_prereqs.end(); ++it) {
        it->expectation_base()->DescribeLocationTo(os);
        *os << "pre-requisite #" << i++ << "\n";
      }
      *os << "                   (end of pre-requisites)\n";
    } else {
      // This line is here just for completeness' sake.  It will never
      // be executed as currently the ExplainMatchResultTo() function
      // is called only when the mock function call does NOT match the
      // expectation.
      *os << "The call matches the expectation.\n";
    }
  }

  // Returns the action that should be taken for the current invocation.
  const Action<F>& GetCurrentAction(
      const FunctionMockerBase<F>* mocker,
      const ArgumentTuple& args) const
          GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    const int count = call_count();
    Assert(count >= 1, __FILE__, __LINE__,
           "call_count() is <= 0 when GetCurrentAction() is "
           "called - this should never happen.");

    const int action_count = static_cast<int>(untyped_actions_.size());
    if (action_count > 0 && !repeated_action_specified_ &&
        count > action_count) {
      // If there is at least one WillOnce() and no WillRepeatedly(),
      // we warn the user when the WillOnce() clauses ran out.
      ::std::stringstream ss;
      DescribeLocationTo(&ss);
      ss << "Actions ran out in " << source_text() << "...\n"
         << "Called " << count << " times, but only "
         << action_count << " WillOnce()"
         << (action_count == 1 ? " is" : "s are") << " specified - ";
      mocker->DescribeDefaultActionTo(args, &ss);
      Log(kWarning, ss.str(), 1);
    }

    return count <= action_count ?
        *static_cast<const Action<F>*>(untyped_actions_[count - 1]) :
        repeated_action();
  }

  // Given the arguments of a mock function call, if the call will
  // over-saturate this expectation, returns the default action;
  // otherwise, returns the next action in this expectation.  Also
  // describes *what* happened to 'what', and explains *why* Google
  // Mock does it to 'why'.  This method is not const as it calls
  // IncrementCallCount().  A return value of NULL means the default
  // action.
  const Action<F>* GetActionForArguments(
      const FunctionMockerBase<F>* mocker,
      const ArgumentTuple& args,
      ::std::ostream* what,
      ::std::ostream* why)
          GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    if (IsSaturated()) {
      // We have an excessive call.
      IncrementCallCount();
      *what << "Mock function called more times than expected - ";
      mocker->DescribeDefaultActionTo(args, what);
      DescribeCallCountTo(why);

      // TODO(wan@google.com): allow the user to control whether
      // unexpected calls should fail immediately or continue using a
      // flag --gmock_unexpected_calls_are_fatal.
      return NULL;
    }

    IncrementCallCount();
    RetireAllPreRequisites();

    if (retires_on_saturation_ && IsSaturated()) {
      Retire();
    }

    // Must be done after IncrementCount()!
    *what << "Mock function call matches " << source_text() <<"...\n";
    return &(GetCurrentAction(mocker, args));
  }

  // All the fields below won't change once the EXPECT_CALL()
  // statement finishes.
  FunctionMockerBase<F>* const owner_;
  ArgumentMatcherTuple matchers_;
  Matcher<const ArgumentTuple&> extra_matcher_;
  Action<F> repeated_action_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(TypedExpectation);
};  // class TypedExpectation

// A MockSpec object is used by ON_CALL() or EXPECT_CALL() for
// specifying the default behavior of, or expectation on, a mock
// function.

// Note: class MockSpec really belongs to the ::testing namespace.
// However if we define it in ::testing, MSVC will complain when
// classes in ::testing::internal declare it as a friend class
// template.  To workaround this compiler bug, we define MockSpec in
// ::testing::internal and import it into ::testing.

// Logs a message including file and line number information.
GTEST_API_ void LogWithLocation(testing::internal::LogSeverity severity,
                                const char* file, int line,
                                const std::string& message);

template <typename F>
class MockSpec {
 public:
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;
  typedef typename internal::Function<F>::ArgumentMatcherTuple
      ArgumentMatcherTuple;

  // Constructs a MockSpec object, given the function mocker object
  // that the spec is associated with.
  MockSpec(internal::FunctionMockerBase<F>* function_mocker,
           const ArgumentMatcherTuple& matchers)
      : function_mocker_(function_mocker), matchers_(matchers) {}

  // Adds a new default action spec to the function mocker and returns
  // the newly created spec.
  internal::OnCallSpec<F>& InternalDefaultActionSetAt(
      const char* file, int line, const char* obj, const char* call) {
    LogWithLocation(internal::kInfo, file, line,
                    std::string("ON_CALL(") + obj + ", " + call + ") invoked");
    return function_mocker_->AddNewOnCallSpec(file, line, matchers_);
  }

  // Adds a new expectation spec to the function mocker and returns
  // the newly created spec.
  internal::TypedExpectation<F>& InternalExpectedAt(
      const char* file, int line, const char* obj, const char* call) {
    const std::string source_text(std::string("EXPECT_CALL(") + obj + ", " +
                                  call + ")");
    LogWithLocation(internal::kInfo, file, line, source_text + " invoked");
    return function_mocker_->AddNewExpectation(
        file, line, source_text, matchers_);
  }

  // This operator overload is used to swallow the superfluous parameter list
  // introduced by the ON/EXPECT_CALL macros. See the macro comments for more
  // explanation.
  MockSpec<F>& operator()(const internal::WithoutMatchers&, void* const) {
    return *this;
  }

 private:
  template <typename Function>
  friend class internal::FunctionMocker;

  // The function mocker that owns this spec.
  internal::FunctionMockerBase<F>* const function_mocker_;
  // The argument matchers specified in the spec.
  ArgumentMatcherTuple matchers_;

  GTEST_DISALLOW_ASSIGN_(MockSpec);
};  // class MockSpec

// Wrapper type for generically holding an ordinary value or lvalue reference.
// If T is not a reference type, it must be copyable or movable.
// ReferenceOrValueWrapper<T> is movable, and will also be copyable unless
// T is a move-only value type (which means that it will always be copyable
// if the current platform does not support move semantics).
//
// The primary template defines handling for values, but function header
// comments describe the contract for the whole template (including
// specializations).
template <typename T>
class ReferenceOrValueWrapper {
 public:
  // Constructs a wrapper from the given value/reference.
  explicit ReferenceOrValueWrapper(T value)
      : value_(::testing::internal::move(value)) {
  }

  // Unwraps and returns the underlying value/reference, exactly as
  // originally passed. The behavior of calling this more than once on
  // the same object is unspecified.
  T Unwrap() { return ::testing::internal::move(value_); }

  // Provides nondestructive access to the underlying value/reference.
  // Always returns a const reference (more precisely,
  // const RemoveReference<T>&). The behavior of calling this after
  // calling Unwrap on the same object is unspecified.
  const T& Peek() const {
    return value_;
  }

 private:
  T value_;
};

// Specialization for lvalue reference types. See primary template
// for documentation.
template <typename T>
class ReferenceOrValueWrapper<T&> {
 public:
  // Workaround for debatable pass-by-reference lint warning (c-library-team
  // policy precludes NOLINT in this context)
  typedef T& reference;
  explicit ReferenceOrValueWrapper(reference ref)
      : value_ptr_(&ref) {}
  T& Unwrap() { return *value_ptr_; }
  const T& Peek() const { return *value_ptr_; }

 private:
  T* value_ptr_;
};

// MSVC warns about using 'this' in base member initializer list, so
// we need to temporarily disable the warning.  We have to do it for
// the entire class to suppress the warning, even though it's about
// the constructor only.

#ifdef _MSC_VER
# pragma warning(push)          // Saves the current warning state.
# pragma warning(disable:4355)  // Temporarily disables warning 4355.
#endif  // _MSV_VER

// C++ treats the void type specially.  For example, you cannot define
// a void-typed variable or pass a void value to a function.
// ActionResultHolder<T> holds a value of type T, where T must be a
// copyable type or void (T doesn't need to be default-constructable).
// It hides the syntactic difference between void and other types, and
// is used to unify the code for invoking both void-returning and
// non-void-returning mock functions.

// Untyped base class for ActionResultHolder<T>.
class UntypedActionResultHolderBase {
 public:
  virtual ~UntypedActionResultHolderBase() {}

  // Prints the held value as an action's result to os.
  virtual void PrintAsActionResult(::std::ostream* os) const = 0;
};

// This generic definition is used when T is not void.
template <typename T>
class ActionResultHolder : public UntypedActionResultHolderBase {
 public:
  // Returns the held value. Must not be called more than once.
  T Unwrap() {
    return result_.Unwrap();
  }

  // Prints the held value as an action's result to os.
  virtual void PrintAsActionResult(::std::ostream* os) const {
    *os << "\n          Returns: ";
    // T may be a reference type, so we don't use UniversalPrint().
    UniversalPrinter<T>::Print(result_.Peek(), os);
  }

  // Performs the given mock function's default action and returns the
  // result in a new-ed ActionResultHolder.
  template <typename F>
  static ActionResultHolder* PerformDefaultAction(
      const FunctionMockerBase<F>* func_mocker,
      typename RvalueRef<typename Function<F>::ArgumentTuple>::type args,
      const std::string& call_description) {
    return new ActionResultHolder(Wrapper(func_mocker->PerformDefaultAction(
        internal::move(args), call_description)));
  }

  // Performs the given action and returns the result in a new-ed
  // ActionResultHolder.
  template <typename F>
  static ActionResultHolder* PerformAction(
      const Action<F>& action,
      typename RvalueRef<typename Function<F>::ArgumentTuple>::type args) {
    return new ActionResultHolder(
        Wrapper(action.Perform(internal::move(args))));
  }

 private:
  typedef ReferenceOrValueWrapper<T> Wrapper;

  explicit ActionResultHolder(Wrapper result)
      : result_(::testing::internal::move(result)) {
  }

  Wrapper result_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionResultHolder);
};

// Specialization for T = void.
template <>
class ActionResultHolder<void> : public UntypedActionResultHolderBase {
 public:
  void Unwrap() { }

  virtual void PrintAsActionResult(::std::ostream* /* os */) const {}

  // Performs the given mock function's default action and returns ownership
  // of an empty ActionResultHolder*.
  template <typename F>
  static ActionResultHolder* PerformDefaultAction(
      const FunctionMockerBase<F>* func_mocker,
      typename RvalueRef<typename Function<F>::ArgumentTuple>::type args,
      const std::string& call_description) {
    func_mocker->PerformDefaultAction(internal::move(args), call_description);
    return new ActionResultHolder;
  }

  // Performs the given action and returns ownership of an empty
  // ActionResultHolder*.
  template <typename F>
  static ActionResultHolder* PerformAction(
      const Action<F>& action,
      typename RvalueRef<typename Function<F>::ArgumentTuple>::type args) {
    action.Perform(internal::move(args));
    return new ActionResultHolder;
  }

 private:
  ActionResultHolder() {}
  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionResultHolder);
};

// The base of the function mocker class for the given function type.
// We put the methods in this class instead of its child to avoid code
// bloat.
template <typename F>
class FunctionMockerBase : public UntypedFunctionMockerBase {
 public:
  typedef typename Function<F>::Result Result;
  typedef typename Function<F>::ArgumentTuple ArgumentTuple;
  typedef typename Function<F>::ArgumentMatcherTuple ArgumentMatcherTuple;

  FunctionMockerBase() {}

  // The destructor verifies that all expectations on this mock
  // function have been satisfied.  If not, it will report Google Test
  // non-fatal failures for the violations.
  virtual ~FunctionMockerBase()
        GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    MutexLock l(&g_gmock_mutex);
    VerifyAndClearExpectationsLocked();
    Mock::UnregisterLocked(this);
    ClearDefaultActionsLocked();
  }

  // Returns the ON_CALL spec that matches this mock function with the
  // given arguments; returns NULL if no matching ON_CALL is found.
  // L = *
  const OnCallSpec<F>* FindOnCallSpec(
      const ArgumentTuple& args) const {
    for (UntypedOnCallSpecs::const_reverse_iterator it
             = untyped_on_call_specs_.rbegin();
         it != untyped_on_call_specs_.rend(); ++it) {
      const OnCallSpec<F>* spec = static_cast<const OnCallSpec<F>*>(*it);
      if (spec->Matches(args))
        return spec;
    }

    return NULL;
  }

  // Performs the default action of this mock function on the given
  // arguments and returns the result. Asserts (or throws if
  // exceptions are enabled) with a helpful call descrption if there
  // is no valid return value. This method doesn't depend on the
  // mutable state of this object, and thus can be called concurrently
  // without locking.
  // L = *
  Result PerformDefaultAction(
      typename RvalueRef<typename Function<F>::ArgumentTuple>::type args,
      const std::string& call_description) const {
    const OnCallSpec<F>* const spec =
        this->FindOnCallSpec(args);
    if (spec != NULL) {
      return spec->GetAction().Perform(internal::move(args));
    }
    const std::string message =
        call_description +
        "\n    The mock function has no default action "
        "set, and its return type has no default value set.";
#if GTEST_HAS_EXCEPTIONS
    if (!DefaultValue<Result>::Exists()) {
      throw std::runtime_error(message);
    }
#else
    Assert(DefaultValue<Result>::Exists(), "", -1, message);
#endif
    return DefaultValue<Result>::Get();
  }

  // Performs the default action with the given arguments and returns
  // the action's result.  The call description string will be used in
  // the error message to describe the call in the case the default
  // action fails.  The caller is responsible for deleting the result.
  // L = *
  virtual UntypedActionResultHolderBase* UntypedPerformDefaultAction(
      void* untyped_args,  // must point to an ArgumentTuple
      const std::string& call_description) const {
    ArgumentTuple* args = static_cast<ArgumentTuple*>(untyped_args);
    return ResultHolder::PerformDefaultAction(this, internal::move(*args),
                                              call_description);
  }

  // Performs the given action with the given arguments and returns
  // the action's result.  The caller is responsible for deleting the
  // result.
  // L = *
  virtual UntypedActionResultHolderBase* UntypedPerformAction(
      const void* untyped_action, void* untyped_args) const {
    // Make a copy of the action before performing it, in case the
    // action deletes the mock object (and thus deletes itself).
    const Action<F> action = *static_cast<const Action<F>*>(untyped_action);
    ArgumentTuple* args = static_cast<ArgumentTuple*>(untyped_args);
    return ResultHolder::PerformAction(action, internal::move(*args));
  }

  // Implements UntypedFunctionMockerBase::ClearDefaultActionsLocked():
  // clears the ON_CALL()s set on this mock function.
  virtual void ClearDefaultActionsLocked()
      GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();

    // Deleting our default actions may trigger other mock objects to be
    // deleted, for example if an action contains a reference counted smart
    // pointer to that mock object, and that is the last reference. So if we
    // delete our actions within the context of the global mutex we may deadlock
    // when this method is called again. Instead, make a copy of the set of
    // actions to delete, clear our set within the mutex, and then delete the
    // actions outside of the mutex.
    UntypedOnCallSpecs specs_to_delete;
    untyped_on_call_specs_.swap(specs_to_delete);

    g_gmock_mutex.Unlock();
    for (UntypedOnCallSpecs::const_iterator it =
             specs_to_delete.begin();
         it != specs_to_delete.end(); ++it) {
      delete static_cast<const OnCallSpec<F>*>(*it);
    }

    // Lock the mutex again, since the caller expects it to be locked when we
    // return.
    g_gmock_mutex.Lock();
  }

 protected:
  template <typename Function>
  friend class MockSpec;

  typedef ActionResultHolder<Result> ResultHolder;

  // Returns the result of invoking this mock function with the given
  // arguments.  This function can be safely called from multiple
  // threads concurrently.
  Result InvokeWith(
      typename RvalueRef<typename Function<F>::ArgumentTuple>::type args)
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    // const_cast is required since in C++98 we still pass ArgumentTuple around
    // by const& instead of rvalue reference.
    void* untyped_args = const_cast<void*>(static_cast<const void*>(&args));
    scoped_ptr<ResultHolder> holder(
        DownCast_<ResultHolder*>(this->UntypedInvokeWith(untyped_args)));
    return holder->Unwrap();
  }

  // Adds and returns a default action spec for this mock function.
  OnCallSpec<F>& AddNewOnCallSpec(
      const char* file, int line,
      const ArgumentMatcherTuple& m)
          GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    Mock::RegisterUseByOnCallOrExpectCall(MockObject(), file, line);
    OnCallSpec<F>* const on_call_spec = new OnCallSpec<F>(file, line, m);
    untyped_on_call_specs_.push_back(on_call_spec);
    return *on_call_spec;
  }

  // Adds and returns an expectation spec for this mock function.
  TypedExpectation<F>& AddNewExpectation(const char* file, int line,
                                         const std::string& source_text,
                                         const ArgumentMatcherTuple& m)
      GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    Mock::RegisterUseByOnCallOrExpectCall(MockObject(), file, line);
    TypedExpectation<F>* const expectation =
        new TypedExpectation<F>(this, file, line, source_text, m);
    const linked_ptr<ExpectationBase> untyped_expectation(expectation);
    // See the definition of untyped_expectations_ for why access to
    // it is unprotected here.
    untyped_expectations_.push_back(untyped_expectation);

    // Adds this expectation into the implicit sequence if there is one.
    Sequence* const implicit_sequence = g_gmock_implicit_sequence.get();
    if (implicit_sequence != NULL) {
      implicit_sequence->AddExpectation(Expectation(untyped_expectation));
    }

    return *expectation;
  }

 private:
  template <typename Func> friend class TypedExpectation;

  // Some utilities needed for implementing UntypedInvokeWith().

  // Describes what default action will be performed for the given
  // arguments.
  // L = *
  void DescribeDefaultActionTo(const ArgumentTuple& args,
                               ::std::ostream* os) const {
    const OnCallSpec<F>* const spec = FindOnCallSpec(args);

    if (spec == NULL) {
      *os << (internal::type_equals<Result, void>::value ?
              "returning directly.\n" :
              "returning default value.\n");
    } else {
      *os << "taking default action specified at:\n"
          << FormatFileLocation(spec->file(), spec->line()) << "\n";
    }
  }

  // Writes a message that the call is uninteresting (i.e. neither
  // explicitly expected nor explicitly unexpected) to the given
  // ostream.
  virtual void UntypedDescribeUninterestingCall(
      const void* untyped_args,
      ::std::ostream* os) const
          GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    const ArgumentTuple& args =
        *static_cast<const ArgumentTuple*>(untyped_args);
    *os << "Uninteresting mock function call - ";
    DescribeDefaultActionTo(args, os);
    *os << "    Function call: " << Name();
    UniversalPrint(args, os);
  }

  // Returns the expectation that matches the given function arguments
  // (or NULL is there's no match); when a match is found,
  // untyped_action is set to point to the action that should be
  // performed (or NULL if the action is "do default"), and
  // is_excessive is modified to indicate whether the call exceeds the
  // expected number.
  //
  // Critical section: We must find the matching expectation and the
  // corresponding action that needs to be taken in an ATOMIC
  // transaction.  Otherwise another thread may call this mock
  // method in the middle and mess up the state.
  //
  // However, performing the action has to be left out of the critical
  // section.  The reason is that we have no control on what the
  // action does (it can invoke an arbitrary user function or even a
  // mock function) and excessive locking could cause a dead lock.
  virtual const ExpectationBase* UntypedFindMatchingExpectation(
      const void* untyped_args,
      const void** untyped_action, bool* is_excessive,
      ::std::ostream* what, ::std::ostream* why)
          GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    const ArgumentTuple& args =
        *static_cast<const ArgumentTuple*>(untyped_args);
    MutexLock l(&g_gmock_mutex);
    TypedExpectation<F>* exp = this->FindMatchingExpectationLocked(args);
    if (exp == NULL) {  // A match wasn't found.
      this->FormatUnexpectedCallMessageLocked(args, what, why);
      return NULL;
    }

    // This line must be done before calling GetActionForArguments(),
    // which will increment the call count for *exp and thus affect
    // its saturation status.
    *is_excessive = exp->IsSaturated();
    const Action<F>* action = exp->GetActionForArguments(this, args, what, why);
    if (action != NULL && action->IsDoDefault())
      action = NULL;  // Normalize "do default" to NULL.
    *untyped_action = action;
    return exp;
  }

  // Prints the given function arguments to the ostream.
  virtual void UntypedPrintArgs(const void* untyped_args,
                                ::std::ostream* os) const {
    const ArgumentTuple& args =
        *static_cast<const ArgumentTuple*>(untyped_args);
    UniversalPrint(args, os);
  }

  // Returns the expectation that matches the arguments, or NULL if no
  // expectation matches them.
  TypedExpectation<F>* FindMatchingExpectationLocked(
      const ArgumentTuple& args) const
          GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    // See the definition of untyped_expectations_ for why access to
    // it is unprotected here.
    for (typename UntypedExpectations::const_reverse_iterator it =
             untyped_expectations_.rbegin();
         it != untyped_expectations_.rend(); ++it) {
      TypedExpectation<F>* const exp =
          static_cast<TypedExpectation<F>*>(it->get());
      if (exp->ShouldHandleArguments(args)) {
        return exp;
      }
    }
    return NULL;
  }

  // Returns a message that the arguments don't match any expectation.
  void FormatUnexpectedCallMessageLocked(
      const ArgumentTuple& args,
      ::std::ostream* os,
      ::std::ostream* why) const
          GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    *os << "\nUnexpected mock function call - ";
    DescribeDefaultActionTo(args, os);
    PrintTriedExpectationsLocked(args, why);
  }

  // Prints a list of expectations that have been tried against the
  // current mock function call.
  void PrintTriedExpectationsLocked(
      const ArgumentTuple& args,
      ::std::ostream* why) const
          GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    const int count = static_cast<int>(untyped_expectations_.size());
    *why << "Google Mock tried the following " << count << " "
         << (count == 1 ? "expectation, but it didn't match" :
             "expectations, but none matched")
         << ":\n";
    for (int i = 0; i < count; i++) {
      TypedExpectation<F>* const expectation =
          static_cast<TypedExpectation<F>*>(untyped_expectations_[i].get());
      *why << "\n";
      expectation->DescribeLocationTo(why);
      if (count > 1) {
        *why << "tried expectation #" << i << ": ";
      }
      *why << expectation->source_text() << "...\n";
      expectation->ExplainMatchResultTo(args, why);
      expectation->DescribeCallCountTo(why);
    }
  }

  // There is no generally useful and implementable semantics of
  // copying a mock object, so copying a mock is usually a user error.
  // Thus we disallow copying function mockers.  If the user really
  // wants to copy a mock object, they should implement their own copy
  // operation, for example:
  //
  //   class MockFoo : public Foo {
  //    public:
  //     // Defines a copy constructor explicitly.
  //     MockFoo(const MockFoo& src) {}
  //     ...
  //   };
  GTEST_DISALLOW_COPY_AND_ASSIGN_(FunctionMockerBase);
};  // class FunctionMockerBase

#ifdef _MSC_VER
# pragma warning(pop)  // Restores the warning state.
#endif  // _MSV_VER

// Implements methods of FunctionMockerBase.

// Verifies that all expectations on this mock function have been
// satisfied.  Reports one or more Google Test non-fatal failures and
// returns false if not.

// Reports an uninteresting call (whose description is in msg) in the
// manner specified by 'reaction'.
void ReportUninterestingCall(CallReaction reaction, const std::string& msg);

}  // namespace internal

// The style guide prohibits "using" statements in a namespace scope
// inside a header file.  However, the MockSpec class template is
// meant to be defined in the ::testing namespace.  The following line
// is just a trick for working around a bug in MSVC 8.0, which cannot
// handle it if we define MockSpec in ::testing.
using internal::MockSpec;

// Const(x) is a convenient function for obtaining a const reference
// to x.  This is useful for setting expectations on an overloaded
// const mock method, e.g.
//
//   class MockFoo : public FooInterface {
//    public:
//     MOCK_METHOD0(Bar, int());
//     MOCK_CONST_METHOD0(Bar, int&());
//   };
//
//   MockFoo foo;
//   // Expects a call to non-const MockFoo::Bar().
//   EXPECT_CALL(foo, Bar());
//   // Expects a call to const MockFoo::Bar().
//   EXPECT_CALL(Const(foo), Bar());
template <typename T>
inline const T& Const(const T& x) { return x; }

// Constructs an Expectation object that references and co-owns exp.
inline Expectation::Expectation(internal::ExpectationBase& exp)  // NOLINT
    : expectation_base_(exp.GetHandle().expectation_base()) {}

}  // namespace testing

// Implementation for ON_CALL and EXPECT_CALL macros. A separate macro is
// required to avoid compile errors when the name of the method used in call is
// a result of macro expansion. See CompilesWithMethodNameExpandedFromMacro
// tests in internal/gmock-spec-builders_test.cc for more details.
//
// This macro supports statements both with and without parameter matchers. If
// the parameter list is omitted, gMock will accept any parameters, which allows
// tests to be written that don't need to encode the number of method
// parameter. This technique may only be used for non-overloaded methods.
//
//   // These are the same:
//   ON_CALL(mock, NoArgsMethod()).WillByDefault(...);
//   ON_CALL(mock, NoArgsMethod).WillByDefault(...);
//
//   // As are these:
//   ON_CALL(mock, TwoArgsMethod(_, _)).WillByDefault(...);
//   ON_CALL(mock, TwoArgsMethod).WillByDefault(...);
//
//   // Can also specify args if you want, of course:
//   ON_CALL(mock, TwoArgsMethod(_, 45)).WillByDefault(...);
//
//   // Overloads work as long as you specify parameters:
//   ON_CALL(mock, OverloadedMethod(_)).WillByDefault(...);
//   ON_CALL(mock, OverloadedMethod(_, _)).WillByDefault(...);
//
//   // Oops! Which overload did you want?
//   ON_CALL(mock, OverloadedMethod).WillByDefault(...);
//     => ERROR: call to member function 'gmock_OverloadedMethod' is ambiguous
//
// How this works: The mock class uses two overloads of the gmock_Method
// expectation setter method plus an operator() overload on the MockSpec object.
// In the matcher list form, the macro expands to:
//
//   // This statement:
//   ON_CALL(mock, TwoArgsMethod(_, 45))...
//
//   // ...expands to:
//   mock.gmock_TwoArgsMethod(_, 45)(WithoutMatchers(), nullptr)...
//   |-------------v---------------||------------v-------------|
//       invokes first overload        swallowed by operator()
//
//   // ...which is essentially:
//   mock.gmock_TwoArgsMethod(_, 45)...
//
// Whereas the form without a matcher list:
//
//   // This statement:
//   ON_CALL(mock, TwoArgsMethod)...
//
//   // ...expands to:
//   mock.gmock_TwoArgsMethod(WithoutMatchers(), nullptr)...
//   |-----------------------v--------------------------|
//                 invokes second overload
//
//   // ...which is essentially:
//   mock.gmock_TwoArgsMethod(_, _)...
//
// The WithoutMatchers() argument is used to disambiguate overloads and to
// block the caller from accidentally invoking the second overload directly. The
// second argument is an internal type derived from the method signature. The
// failure to disambiguate two overloads of this method in the ON_CALL statement
// is how we block callers from setting expectations on overloaded methods.
#define GMOCK_ON_CALL_IMPL_(mock_expr, Setter, call)                          \
  ((mock_expr).gmock_##call)(::testing::internal::GetWithoutMatchers(), NULL) \
      .Setter(__FILE__, __LINE__, #mock_expr, #call)

#define ON_CALL(obj, call) \
  GMOCK_ON_CALL_IMPL_(obj, InternalDefaultActionSetAt, call)

#define EXPECT_CALL(obj, call) \
  GMOCK_ON_CALL_IMPL_(obj, InternalExpectedAt, call)

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_

#if GTEST_HAS_STD_FUNCTION_
# include <functional>
#endif

namespace testing {
namespace internal {

template <typename F>
class FunctionMockerBase;

// Note: class FunctionMocker really belongs to the ::testing
// namespace.  However if we define it in ::testing, MSVC will
// complain when classes in ::testing::internal declare it as a
// friend class template.  To workaround this compiler bug, we define
// FunctionMocker in ::testing::internal and import it into ::testing.
template <typename F>
class FunctionMocker;

template <typename R>
class FunctionMocker<R()> : public
    internal::FunctionMockerBase<R()> {
 public:
  typedef R F();
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With() {
    return MockSpec<F>(this, ::testing::make_tuple());
  }

  R Invoke() {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple());
  }
};

template <typename R, typename A1>
class FunctionMocker<R(A1)> : public
    internal::FunctionMockerBase<R(A1)> {
 public:
  typedef R F(A1);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1) {
    return MockSpec<F>(this, ::testing::make_tuple(m1));
  }

  R Invoke(A1 a1) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1)));
  }
};

template <typename R, typename A1, typename A2>
class FunctionMocker<R(A1, A2)> : public
    internal::FunctionMockerBase<R(A1, A2)> {
 public:
  typedef R F(A1, A2);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2));
  }

  R Invoke(A1 a1, A2 a2) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2)));
  }
};

template <typename R, typename A1, typename A2, typename A3>
class FunctionMocker<R(A1, A2, A3)> : public
    internal::FunctionMockerBase<R(A1, A2, A3)> {
 public:
  typedef R F(A1, A2, A3);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3));
  }

  R Invoke(A1 a1, A2 a2, A3 a3) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4>
class FunctionMocker<R(A1, A2, A3, A4)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4)> {
 public:
  typedef R F(A1, A2, A3, A4);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5>
class FunctionMocker<R(A1, A2, A3, A4, A5)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4, A5)> {
 public:
  typedef R F(A1, A2, A3, A4, A5);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4, m5));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4), internal::forward<A5>(a5)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6>
class FunctionMocker<R(A1, A2, A3, A4, A5, A6)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6)> {
 public:
  typedef R F(A1, A2, A3, A4, A5, A6);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
      const Matcher<A6>& m6) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4, m5, m6));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4), internal::forward<A5>(a5),
        internal::forward<A6>(a6)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7>
class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7)> {
 public:
  typedef R F(A1, A2, A3, A4, A5, A6, A7);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
      const Matcher<A6>& m6, const Matcher<A7>& m7) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4, m5, m6, m7));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4), internal::forward<A5>(a5),
        internal::forward<A6>(a6), internal::forward<A7>(a7)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8>
class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8)> {
 public:
  typedef R F(A1, A2, A3, A4, A5, A6, A7, A8);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
      const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4, m5, m6, m7,
        m8));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4), internal::forward<A5>(a5),
        internal::forward<A6>(a6), internal::forward<A7>(a7),
        internal::forward<A8>(a8)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9>
class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9)> {
 public:
  typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
      const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
      const Matcher<A9>& m9) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4, m5, m6, m7,
        m8, m9));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4), internal::forward<A5>(a5),
        internal::forward<A6>(a6), internal::forward<A7>(a7),
        internal::forward<A8>(a8), internal::forward<A9>(a9)));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9,
    typename A10>
class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)> : public
    internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)> {
 public:
  typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
  typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

  MockSpec<F> With(const Matcher<A1>& m1, const Matcher<A2>& m2,
      const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
      const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
      const Matcher<A9>& m9, const Matcher<A10>& m10) {
    return MockSpec<F>(this, ::testing::make_tuple(m1, m2, m3, m4, m5, m6, m7,
        m8, m9, m10));
  }

  R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9,
      A10 a10) {
    // Even though gcc and MSVC don't enforce it, 'this->' is required
    // by the C++ standard [14.6.4] here, as the base class type is
    // dependent on the template argument (and thus shouldn't be
    // looked into when resolving InvokeWith).
    return this->InvokeWith(ArgumentTuple(internal::forward<A1>(a1),
        internal::forward<A2>(a2), internal::forward<A3>(a3),
        internal::forward<A4>(a4), internal::forward<A5>(a5),
        internal::forward<A6>(a6), internal::forward<A7>(a7),
        internal::forward<A8>(a8), internal::forward<A9>(a9),
        internal::forward<A10>(a10)));
  }
};

// Removes the given pointer; this is a helper for the expectation setter method
// for parameterless matchers.
//
// We want to make sure that the user cannot set a parameterless expectation on
// overloaded methods, including methods which are overloaded on const. Example:
//
//   class MockClass {
//     MOCK_METHOD0(GetName, string&());
//     MOCK_CONST_METHOD0(GetName, const string&());
//   };
//
//   TEST() {
//     // This should be an error, as it's not clear which overload is expected.
//     EXPECT_CALL(mock, GetName).WillOnce(ReturnRef(value));
//   }
//
// Here are the generated expectation-setter methods:
//
//   class MockClass {
//     // Overload 1
//     MockSpec<string&()> gmock_GetName() { ... }
//     // Overload 2. Declared const so that the compiler will generate an
//     // error when trying to resolve between this and overload 4 in
//     // 'gmock_GetName(WithoutMatchers(), nullptr)'.
//     MockSpec<string&()> gmock_GetName(
//         const WithoutMatchers&, const Function<string&()>*) const {
//       // Removes const from this, calls overload 1
//       return AdjustConstness_(this)->gmock_GetName();
//     }
//
//     // Overload 3
//     const string& gmock_GetName() const { ... }
//     // Overload 4
//     MockSpec<const string&()> gmock_GetName(
//         const WithoutMatchers&, const Function<const string&()>*) const {
//       // Does not remove const, calls overload 3
//       return AdjustConstness_const(this)->gmock_GetName();
//     }
//   }
//
template <typename MockType>
const MockType* AdjustConstness_const(const MockType* mock) {
  return mock;
}

// Removes const from and returns the given pointer; this is a helper for the
// expectation setter method for parameterless matchers.
template <typename MockType>
MockType* AdjustConstness_(const MockType* mock) {
  return const_cast<MockType*>(mock);
}

}  // namespace internal

// The style guide prohibits "using" statements in a namespace scope
// inside a header file.  However, the FunctionMocker class template
// is meant to be defined in the ::testing namespace.  The following
// line is just a trick for working around a bug in MSVC 8.0, which
// cannot handle it if we define FunctionMocker in ::testing.
using internal::FunctionMocker;

// GMOCK_RESULT_(tn, F) expands to the result type of function type F.
// We define this as a variadic macro in case F contains unprotected
// commas (the same reason that we use variadic macros in other places
// in this file).
// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_RESULT_(tn, ...) \
    tn ::testing::internal::Function<__VA_ARGS__>::Result

// The type of argument N of the given function type.
// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_ARG_(tn, N, ...) \
    tn ::testing::internal::Function<__VA_ARGS__>::Argument##N

// The matcher type for argument N of the given function type.
// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_MATCHER_(tn, N, ...) \
    const ::testing::Matcher<GMOCK_ARG_(tn, N, __VA_ARGS__)>&

// The variable for mocking the given method.
// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_MOCKER_(arity, constness, Method) \
    GTEST_CONCAT_TOKEN_(gmock##constness##arity##_##Method##_, __LINE__)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD0_(tn, constness, ct, Method, ...)                       \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method() constness {                     \
    GTEST_COMPILE_ASSERT_(                                                   \
        (::testing::tuple_size<tn ::testing::internal::Function<             \
             __VA_ARGS__>::ArgumentTuple>::value == 0),                      \
        this_method_does_not_take_0_arguments);                              \
    GMOCK_MOCKER_(0, constness, Method).SetOwnerAndName(this, #Method);      \
    return GMOCK_MOCKER_(0, constness, Method).Invoke();                     \
  }                                                                          \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method() constness {              \
    GMOCK_MOCKER_(0, constness, Method).RegisterOwner(this);                 \
    return GMOCK_MOCKER_(0, constness, Method).With();                       \
  }                                                                          \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                           \
      const ::testing::internal::WithoutMatchers&,                           \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {         \
    return ::testing::internal::AdjustConstness_##constness(this)            \
        ->gmock_##Method();                                                  \
  }                                                                          \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(0, constness, \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD1_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 1),                       \
        this_method_does_not_take_1_argument);                                \
    GMOCK_MOCKER_(1, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(1, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
            gmock_a1));                                                       \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1) constness {                \
    GMOCK_MOCKER_(1, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(1, constness, Method).With(gmock_a1);                \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(1, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD2_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 2),                       \
        this_method_does_not_take_2_arguments);                               \
    GMOCK_MOCKER_(2, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(2, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2) constness {                \
    GMOCK_MOCKER_(2, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(2, constness, Method).With(gmock_a1, gmock_a2);      \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(2, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD3_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 3),                       \
        this_method_does_not_take_3_arguments);                               \
    GMOCK_MOCKER_(3, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(3, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3) constness {                \
    GMOCK_MOCKER_(3, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(3, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3);                                  \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(3, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD4_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                          \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 4),                       \
        this_method_does_not_take_4_arguments);                               \
    GMOCK_MOCKER_(4, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(4, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>( \
                    gmock_a4));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                            \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4) constness {                \
    GMOCK_MOCKER_(4, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(4, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4);                        \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(4, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD5_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                          \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4,                          \
            GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 5),                       \
        this_method_does_not_take_5_arguments);                               \
    GMOCK_MOCKER_(5, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(5, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>( \
                    gmock_a4),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>( \
                    gmock_a5));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                            \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4,                            \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5) constness {                \
    GMOCK_MOCKER_(5, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(5, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5);              \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(5, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD6_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                          \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4,                          \
            GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5,                          \
            GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 6),                       \
        this_method_does_not_take_6_arguments);                               \
    GMOCK_MOCKER_(6, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(6, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>( \
                    gmock_a4),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>( \
                    gmock_a5),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>( \
                    gmock_a6));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                            \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4,                            \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5,                            \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6) constness {                \
    GMOCK_MOCKER_(6, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(6, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6);    \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(6, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD7_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                          \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4,                          \
            GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5,                          \
            GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6,                          \
            GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 7),                       \
        this_method_does_not_take_7_arguments);                               \
    GMOCK_MOCKER_(7, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(7, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>( \
                    gmock_a4),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>( \
                    gmock_a5),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>( \
                    gmock_a6),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>( \
                    gmock_a7));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                            \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4,                            \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5,                            \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6,                            \
      GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7) constness {                \
    GMOCK_MOCKER_(7, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(7, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6,     \
              gmock_a7);                                                      \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(7, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD8_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                          \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4,                          \
            GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5,                          \
            GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6,                          \
            GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7,                          \
            GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 8),                       \
        this_method_does_not_take_8_arguments);                               \
    GMOCK_MOCKER_(8, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(8, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>( \
                    gmock_a4),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>( \
                    gmock_a5),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>( \
                    gmock_a6),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>( \
                    gmock_a7),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>( \
                    gmock_a8));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                            \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4,                            \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5,                            \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6,                            \
      GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7,                            \
      GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8) constness {                \
    GMOCK_MOCKER_(8, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(8, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6,     \
              gmock_a7, gmock_a8);                                            \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(8, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD9_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                              \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                          \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                          \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                          \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4,                          \
            GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5,                          \
            GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6,                          \
            GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7,                          \
            GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8,                          \
            GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9) constness {              \
    GTEST_COMPILE_ASSERT_(                                                    \
        (::testing::tuple_size<tn ::testing::internal::Function<              \
             __VA_ARGS__>::ArgumentTuple>::value == 9),                       \
        this_method_does_not_take_9_arguments);                               \
    GMOCK_MOCKER_(9, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(9, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>( \
                    gmock_a1),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>( \
                    gmock_a2),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>( \
                    gmock_a3),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>( \
                    gmock_a4),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>( \
                    gmock_a5),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>( \
                    gmock_a6),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>( \
                    gmock_a7),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>( \
                    gmock_a8),                                                \
                ::testing::internal::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>( \
                    gmock_a9));                                               \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                            \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                            \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                            \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4,                            \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5,                            \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6,                            \
      GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7,                            \
      GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8,                            \
      GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9) constness {                \
    GMOCK_MOCKER_(9, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(9, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6,     \
              gmock_a7, gmock_a8, gmock_a9);                                  \
  }                                                                           \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                            \
      const ::testing::internal::WithoutMatchers&,                            \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {          \
    return ::testing::internal::AdjustConstness_##constness(this)             \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(),      \
                         ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>());     \
  }                                                                           \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(9, constness,  \
                                                               Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD10_(tn, constness, ct, Method, ...)                        \
  GMOCK_RESULT_(tn, __VA_ARGS__)                                               \
  ct Method(GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1,                           \
            GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2,                           \
            GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3,                           \
            GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4,                           \
            GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5,                           \
            GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6,                           \
            GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7,                           \
            GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8,                           \
            GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9,                           \
            GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10) constness {             \
    GTEST_COMPILE_ASSERT_(                                                     \
        (::testing::tuple_size<tn ::testing::internal::Function<               \
             __VA_ARGS__>::ArgumentTuple>::value == 10),                       \
        this_method_does_not_take_10_arguments);                               \
    GMOCK_MOCKER_(10, constness, Method).SetOwnerAndName(this, #Method);       \
    return GMOCK_MOCKER_(10, constness, Method)                                \
        .Invoke(::testing::internal::forward<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(  \
                    gmock_a1),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(  \
                    gmock_a2),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(  \
                    gmock_a3),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(  \
                    gmock_a4),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(  \
                    gmock_a5),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(  \
                    gmock_a6),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(  \
                    gmock_a7),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(  \
                    gmock_a8),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(  \
                    gmock_a9),                                                 \
                ::testing::internal::forward<GMOCK_ARG_(tn, 10, __VA_ARGS__)>( \
                    gmock_a10));                                               \
  }                                                                            \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                             \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1,                             \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2,                             \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3,                             \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4,                             \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5,                             \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6,                             \
      GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7,                             \
      GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8,                             \
      GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9,                             \
      GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10) constness {               \
    GMOCK_MOCKER_(10, constness, Method).RegisterOwner(this);                  \
    return GMOCK_MOCKER_(10, constness, Method)                                \
        .With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6,      \
              gmock_a7, gmock_a8, gmock_a9, gmock_a10);                        \
  }                                                                            \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method(                             \
      const ::testing::internal::WithoutMatchers&,                             \
      constness ::testing::internal::Function<__VA_ARGS__>*) const {           \
    return ::testing::internal::AdjustConstness_##constness(this)              \
        ->gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(),       \
                         ::testing::A<GMOCK_ARG_(tn, 10, __VA_ARGS__)>());     \
  }                                                                            \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(10, constness,  \
                                                               Method)

#define MOCK_METHOD0(m, ...) GMOCK_METHOD0_(, , , m, __VA_ARGS__)
#define MOCK_METHOD1(m, ...) GMOCK_METHOD1_(, , , m, __VA_ARGS__)
#define MOCK_METHOD2(m, ...) GMOCK_METHOD2_(, , , m, __VA_ARGS__)
#define MOCK_METHOD3(m, ...) GMOCK_METHOD3_(, , , m, __VA_ARGS__)
#define MOCK_METHOD4(m, ...) GMOCK_METHOD4_(, , , m, __VA_ARGS__)
#define MOCK_METHOD5(m, ...) GMOCK_METHOD5_(, , , m, __VA_ARGS__)
#define MOCK_METHOD6(m, ...) GMOCK_METHOD6_(, , , m, __VA_ARGS__)
#define MOCK_METHOD7(m, ...) GMOCK_METHOD7_(, , , m, __VA_ARGS__)
#define MOCK_METHOD8(m, ...) GMOCK_METHOD8_(, , , m, __VA_ARGS__)
#define MOCK_METHOD9(m, ...) GMOCK_METHOD9_(, , , m, __VA_ARGS__)
#define MOCK_METHOD10(m, ...) GMOCK_METHOD10_(, , , m, __VA_ARGS__)

#define MOCK_CONST_METHOD0(m, ...) GMOCK_METHOD0_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD1(m, ...) GMOCK_METHOD1_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD2(m, ...) GMOCK_METHOD2_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD3(m, ...) GMOCK_METHOD3_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD4(m, ...) GMOCK_METHOD4_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD5(m, ...) GMOCK_METHOD5_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD6(m, ...) GMOCK_METHOD6_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD7(m, ...) GMOCK_METHOD7_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD8(m, ...) GMOCK_METHOD8_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD9(m, ...) GMOCK_METHOD9_(, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD10(m, ...) GMOCK_METHOD10_(, const, , m, __VA_ARGS__)

#define MOCK_METHOD0_T(m, ...) GMOCK_METHOD0_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD1_T(m, ...) GMOCK_METHOD1_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD2_T(m, ...) GMOCK_METHOD2_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD3_T(m, ...) GMOCK_METHOD3_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD4_T(m, ...) GMOCK_METHOD4_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD5_T(m, ...) GMOCK_METHOD5_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD6_T(m, ...) GMOCK_METHOD6_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD7_T(m, ...) GMOCK_METHOD7_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD8_T(m, ...) GMOCK_METHOD8_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD9_T(m, ...) GMOCK_METHOD9_(typename, , , m, __VA_ARGS__)
#define MOCK_METHOD10_T(m, ...) GMOCK_METHOD10_(typename, , , m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_T(m, ...) \
    GMOCK_METHOD0_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_T(m, ...) \
    GMOCK_METHOD1_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_T(m, ...) \
    GMOCK_METHOD2_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_T(m, ...) \
    GMOCK_METHOD3_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_T(m, ...) \
    GMOCK_METHOD4_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_T(m, ...) \
    GMOCK_METHOD5_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_T(m, ...) \
    GMOCK_METHOD6_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_T(m, ...) \
    GMOCK_METHOD7_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_T(m, ...) \
    GMOCK_METHOD8_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_T(m, ...) \
    GMOCK_METHOD9_(typename, const, , m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_T(m, ...) \
    GMOCK_METHOD10_(typename, const, , m, __VA_ARGS__)

#define MOCK_METHOD0_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD0_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD1_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD1_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD2_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD2_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD3_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD3_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD4_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD4_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD5_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD5_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD6_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD6_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD7_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD7_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD8_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD8_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD9_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD9_(, , ct, m, __VA_ARGS__)
#define MOCK_METHOD10_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD10_(, , ct, m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD0_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD1_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD2_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD3_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD4_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD5_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD6_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD7_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD8_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD9_(, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD10_(, const, ct, m, __VA_ARGS__)

#define MOCK_METHOD0_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD0_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD1_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD1_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD2_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD2_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD3_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD3_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD4_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD4_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD5_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD5_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD6_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD6_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD7_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD7_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD8_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD8_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD9_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD9_(typename, , ct, m, __VA_ARGS__)
#define MOCK_METHOD10_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD10_(typename, , ct, m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD0_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD1_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD2_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD3_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD4_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD5_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD6_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD7_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD8_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD9_(typename, const, ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD10_(typename, const, ct, m, __VA_ARGS__)

// A MockFunction<F> class has one mock method whose type is F.  It is
// useful when you just want your test code to emit some messages and
// have Google Mock verify the right messages are sent (and perhaps at
// the right times).  For example, if you are exercising code:
//
//   Foo(1);
//   Foo(2);
//   Foo(3);
//
// and want to verify that Foo(1) and Foo(3) both invoke
// mock.Bar("a"), but Foo(2) doesn't invoke anything, you can write:
//
// TEST(FooTest, InvokesBarCorrectly) {
//   MyMock mock;
//   MockFunction<void(string check_point_name)> check;
//   {
//     InSequence s;
//
//     EXPECT_CALL(mock, Bar("a"));
//     EXPECT_CALL(check, Call("1"));
//     EXPECT_CALL(check, Call("2"));
//     EXPECT_CALL(mock, Bar("a"));
//   }
//   Foo(1);
//   check.Call("1");
//   Foo(2);
//   check.Call("2");
//   Foo(3);
// }
//
// The expectation spec says that the first Bar("a") must happen
// before check point "1", the second Bar("a") must happen after check
// point "2", and nothing should happen between the two check
// points. The explicit check points make it easy to tell which
// Bar("a") is called by which call to Foo().
//
// MockFunction<F> can also be used to exercise code that accepts
// std::function<F> callbacks. To do so, use AsStdFunction() method
// to create std::function proxy forwarding to original object's Call.
// Example:
//
// TEST(FooTest, RunsCallbackWithBarArgument) {
//   MockFunction<int(string)> callback;
//   EXPECT_CALL(callback, Call("bar")).WillOnce(Return(1));
//   Foo(callback.AsStdFunction());
// }
template <typename F>
class MockFunction;

template <typename R>
class MockFunction<R()> {
 public:
  MockFunction() {}

  MOCK_METHOD0_T(Call, R());

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R()> AsStdFunction() {
    return [this]() -> R {
      return this->Call();
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0>
class MockFunction<R(A0)> {
 public:
  MockFunction() {}

  MOCK_METHOD1_T(Call, R(A0));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0)> AsStdFunction() {
    return [this](A0 a0) -> R {
      return this->Call(::std::move(a0));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1>
class MockFunction<R(A0, A1)> {
 public:
  MockFunction() {}

  MOCK_METHOD2_T(Call, R(A0, A1));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1)> AsStdFunction() {
    return [this](A0 a0, A1 a1) -> R {
      return this->Call(::std::move(a0), ::std::move(a1));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2>
class MockFunction<R(A0, A1, A2)> {
 public:
  MockFunction() {}

  MOCK_METHOD3_T(Call, R(A0, A1, A2));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3>
class MockFunction<R(A0, A1, A2, A3)> {
 public:
  MockFunction() {}

  MOCK_METHOD4_T(Call, R(A0, A1, A2, A3));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3,
    typename A4>
class MockFunction<R(A0, A1, A2, A3, A4)> {
 public:
  MockFunction() {}

  MOCK_METHOD5_T(Call, R(A0, A1, A2, A3, A4));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3, A4)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3), ::std::move(a4));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3,
    typename A4, typename A5>
class MockFunction<R(A0, A1, A2, A3, A4, A5)> {
 public:
  MockFunction() {}

  MOCK_METHOD6_T(Call, R(A0, A1, A2, A3, A4, A5));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3, A4, A5)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3), ::std::move(a4), ::std::move(a5));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6>
class MockFunction<R(A0, A1, A2, A3, A4, A5, A6)> {
 public:
  MockFunction() {}

  MOCK_METHOD7_T(Call, R(A0, A1, A2, A3, A4, A5, A6));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3, A4, A5, A6)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3), ::std::move(a4), ::std::move(a5), ::std::move(a6));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7>
class MockFunction<R(A0, A1, A2, A3, A4, A5, A6, A7)> {
 public:
  MockFunction() {}

  MOCK_METHOD8_T(Call, R(A0, A1, A2, A3, A4, A5, A6, A7));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3, A4, A5, A6, A7)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3), ::std::move(a4), ::std::move(a5), ::std::move(a6),
          ::std::move(a7));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8>
class MockFunction<R(A0, A1, A2, A3, A4, A5, A6, A7, A8)> {
 public:
  MockFunction() {}

  MOCK_METHOD9_T(Call, R(A0, A1, A2, A3, A4, A5, A6, A7, A8));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3, A4, A5, A6, A7, A8)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7,
        A8 a8) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3), ::std::move(a4), ::std::move(a5), ::std::move(a6),
          ::std::move(a7), ::std::move(a8));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

template <typename R, typename A0, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8,
    typename A9>
class MockFunction<R(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)> {
 public:
  MockFunction() {}

  MOCK_METHOD10_T(Call, R(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9));

#if GTEST_HAS_STD_FUNCTION_
  ::std::function<R(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)> AsStdFunction() {
    return [this](A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7,
        A8 a8, A9 a9) -> R {
      return this->Call(::std::move(a0), ::std::move(a1), ::std::move(a2),
          ::std::move(a3), ::std::move(a4), ::std::move(a5), ::std::move(a6),
          ::std::move(a7), ::std::move(a8), ::std::move(a9));
    };
  }
#endif  // GTEST_HAS_STD_FUNCTION_

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFunction);
};

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_FUNCTION_MOCKERS_H_
// This file was GENERATED by command:
//     pump.py gmock-generated-matchers.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2008, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some commonly used variadic matchers.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_MATCHERS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_MATCHERS_H_

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace testing {
namespace internal {

// The type of the i-th (0-based) field of Tuple.
#define GMOCK_FIELD_TYPE_(Tuple, i) \
    typename ::testing::tuple_element<i, Tuple>::type

// TupleFields<Tuple, k0, ..., kn> is for selecting fields from a
// tuple of type Tuple.  It has two members:
//
//   type: a tuple type whose i-th field is the ki-th field of Tuple.
//   GetSelectedFields(t): returns fields k0, ..., and kn of t as a tuple.
//
// For example, in class TupleFields<tuple<bool, char, int>, 2, 0>, we have:
//
//   type is tuple<int, bool>, and
//   GetSelectedFields(make_tuple(true, 'a', 42)) is (42, true).

template <class Tuple, int k0 = -1, int k1 = -1, int k2 = -1, int k3 = -1,
    int k4 = -1, int k5 = -1, int k6 = -1, int k7 = -1, int k8 = -1,
    int k9 = -1>
class TupleFields;

// This generic version is used when there are 10 selectors.
template <class Tuple, int k0, int k1, int k2, int k3, int k4, int k5, int k6,
    int k7, int k8, int k9>
class TupleFields {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3), GMOCK_FIELD_TYPE_(Tuple, k4),
      GMOCK_FIELD_TYPE_(Tuple, k5), GMOCK_FIELD_TYPE_(Tuple, k6),
      GMOCK_FIELD_TYPE_(Tuple, k7), GMOCK_FIELD_TYPE_(Tuple, k8),
      GMOCK_FIELD_TYPE_(Tuple, k9)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t), get<k4>(t),
        get<k5>(t), get<k6>(t), get<k7>(t), get<k8>(t), get<k9>(t));
  }
};

// The following specialization is used for 0 ~ 9 selectors.

template <class Tuple>
class TupleFields<Tuple, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<> type;
  static type GetSelectedFields(const Tuple& /* t */) {
    return type();
  }
};

template <class Tuple, int k0>
class TupleFields<Tuple, k0, -1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t));
  }
};

template <class Tuple, int k0, int k1>
class TupleFields<Tuple, k0, k1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t));
  }
};

template <class Tuple, int k0, int k1, int k2>
class TupleFields<Tuple, k0, k1, k2, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t));
  }
};

template <class Tuple, int k0, int k1, int k2, int k3>
class TupleFields<Tuple, k0, k1, k2, k3, -1, -1, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t));
  }
};

template <class Tuple, int k0, int k1, int k2, int k3, int k4>
class TupleFields<Tuple, k0, k1, k2, k3, k4, -1, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3), GMOCK_FIELD_TYPE_(Tuple, k4)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t), get<k4>(t));
  }
};

template <class Tuple, int k0, int k1, int k2, int k3, int k4, int k5>
class TupleFields<Tuple, k0, k1, k2, k3, k4, k5, -1, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3), GMOCK_FIELD_TYPE_(Tuple, k4),
      GMOCK_FIELD_TYPE_(Tuple, k5)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t), get<k4>(t),
        get<k5>(t));
  }
};

template <class Tuple, int k0, int k1, int k2, int k3, int k4, int k5, int k6>
class TupleFields<Tuple, k0, k1, k2, k3, k4, k5, k6, -1, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3), GMOCK_FIELD_TYPE_(Tuple, k4),
      GMOCK_FIELD_TYPE_(Tuple, k5), GMOCK_FIELD_TYPE_(Tuple, k6)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t), get<k4>(t),
        get<k5>(t), get<k6>(t));
  }
};

template <class Tuple, int k0, int k1, int k2, int k3, int k4, int k5, int k6,
    int k7>
class TupleFields<Tuple, k0, k1, k2, k3, k4, k5, k6, k7, -1, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3), GMOCK_FIELD_TYPE_(Tuple, k4),
      GMOCK_FIELD_TYPE_(Tuple, k5), GMOCK_FIELD_TYPE_(Tuple, k6),
      GMOCK_FIELD_TYPE_(Tuple, k7)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t), get<k4>(t),
        get<k5>(t), get<k6>(t), get<k7>(t));
  }
};

template <class Tuple, int k0, int k1, int k2, int k3, int k4, int k5, int k6,
    int k7, int k8>
class TupleFields<Tuple, k0, k1, k2, k3, k4, k5, k6, k7, k8, -1> {
 public:
  typedef ::testing::tuple<GMOCK_FIELD_TYPE_(Tuple, k0),
      GMOCK_FIELD_TYPE_(Tuple, k1), GMOCK_FIELD_TYPE_(Tuple, k2),
      GMOCK_FIELD_TYPE_(Tuple, k3), GMOCK_FIELD_TYPE_(Tuple, k4),
      GMOCK_FIELD_TYPE_(Tuple, k5), GMOCK_FIELD_TYPE_(Tuple, k6),
      GMOCK_FIELD_TYPE_(Tuple, k7), GMOCK_FIELD_TYPE_(Tuple, k8)> type;
  static type GetSelectedFields(const Tuple& t) {
    return type(get<k0>(t), get<k1>(t), get<k2>(t), get<k3>(t), get<k4>(t),
        get<k5>(t), get<k6>(t), get<k7>(t), get<k8>(t));
  }
};

#undef GMOCK_FIELD_TYPE_

// Implements the Args() matcher.
template <class ArgsTuple, int k0 = -1, int k1 = -1, int k2 = -1, int k3 = -1,
    int k4 = -1, int k5 = -1, int k6 = -1, int k7 = -1, int k8 = -1,
    int k9 = -1>
class ArgsMatcherImpl : public MatcherInterface<ArgsTuple> {
 public:
  // ArgsTuple may have top-level const or reference modifiers.
  typedef GTEST_REMOVE_REFERENCE_AND_CONST_(ArgsTuple) RawArgsTuple;
  typedef typename internal::TupleFields<RawArgsTuple, k0, k1, k2, k3, k4, k5,
      k6, k7, k8, k9>::type SelectedArgs;
  typedef Matcher<const SelectedArgs&> MonomorphicInnerMatcher;

  template <typename InnerMatcher>
  explicit ArgsMatcherImpl(const InnerMatcher& inner_matcher)
      : inner_matcher_(SafeMatcherCast<const SelectedArgs&>(inner_matcher)) {}

  virtual bool MatchAndExplain(ArgsTuple args,
                               MatchResultListener* listener) const {
    const SelectedArgs& selected_args = GetSelectedArgs(args);
    if (!listener->IsInterested())
      return inner_matcher_.Matches(selected_args);

    PrintIndices(listener->stream());
    *listener << "are " << PrintToString(selected_args);

    StringMatchResultListener inner_listener;
    const bool match = inner_matcher_.MatchAndExplain(selected_args,
                                                      &inner_listener);
    PrintIfNotEmpty(inner_listener.str(), listener->stream());
    return match;
  }

  virtual void DescribeTo(::std::ostream* os) const {
    *os << "are a tuple ";
    PrintIndices(os);
    inner_matcher_.DescribeTo(os);
  }

  virtual void DescribeNegationTo(::std::ostream* os) const {
    *os << "are a tuple ";
    PrintIndices(os);
    inner_matcher_.DescribeNegationTo(os);
  }

 private:
  static SelectedArgs GetSelectedArgs(ArgsTuple args) {
    return TupleFields<RawArgsTuple, k0, k1, k2, k3, k4, k5, k6, k7, k8,
        k9>::GetSelectedFields(args);
  }

  // Prints the indices of the selected fields.
  static void PrintIndices(::std::ostream* os) {
    *os << "whose fields (";
    const int indices[10] = { k0, k1, k2, k3, k4, k5, k6, k7, k8, k9 };
    for (int i = 0; i < 10; i++) {
      if (indices[i] < 0)
        break;

      if (i >= 1)
        *os << ", ";

      *os << "#" << indices[i];
    }
    *os << ") ";
  }

  const MonomorphicInnerMatcher inner_matcher_;

  GTEST_DISALLOW_ASSIGN_(ArgsMatcherImpl);
};

template <class InnerMatcher, int k0 = -1, int k1 = -1, int k2 = -1,
    int k3 = -1, int k4 = -1, int k5 = -1, int k6 = -1, int k7 = -1,
    int k8 = -1, int k9 = -1>
class ArgsMatcher {
 public:
  explicit ArgsMatcher(const InnerMatcher& inner_matcher)
      : inner_matcher_(inner_matcher) {}

  template <typename ArgsTuple>
  operator Matcher<ArgsTuple>() const {
    return MakeMatcher(new ArgsMatcherImpl<ArgsTuple, k0, k1, k2, k3, k4, k5,
        k6, k7, k8, k9>(inner_matcher_));
  }

 private:
  const InnerMatcher inner_matcher_;

  GTEST_DISALLOW_ASSIGN_(ArgsMatcher);
};

// A set of metafunctions for computing the result type of AllOf.
// AllOf(m1, ..., mN) returns
// AllOfResultN<decltype(m1), ..., decltype(mN)>::type.

// Although AllOf isn't defined for one argument, AllOfResult1 is defined
// to simplify the implementation.
template <typename M1>
struct AllOfResult1 {
  typedef M1 type;
};

template <typename M1, typename M2>
struct AllOfResult2 {
  typedef BothOfMatcher<
      typename AllOfResult1<M1>::type,
      typename AllOfResult1<M2>::type
  > type;
};

template <typename M1, typename M2, typename M3>
struct AllOfResult3 {
  typedef BothOfMatcher<
      typename AllOfResult1<M1>::type,
      typename AllOfResult2<M2, M3>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4>
struct AllOfResult4 {
  typedef BothOfMatcher<
      typename AllOfResult2<M1, M2>::type,
      typename AllOfResult2<M3, M4>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5>
struct AllOfResult5 {
  typedef BothOfMatcher<
      typename AllOfResult2<M1, M2>::type,
      typename AllOfResult3<M3, M4, M5>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6>
struct AllOfResult6 {
  typedef BothOfMatcher<
      typename AllOfResult3<M1, M2, M3>::type,
      typename AllOfResult3<M4, M5, M6>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7>
struct AllOfResult7 {
  typedef BothOfMatcher<
      typename AllOfResult3<M1, M2, M3>::type,
      typename AllOfResult4<M4, M5, M6, M7>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8>
struct AllOfResult8 {
  typedef BothOfMatcher<
      typename AllOfResult4<M1, M2, M3, M4>::type,
      typename AllOfResult4<M5, M6, M7, M8>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9>
struct AllOfResult9 {
  typedef BothOfMatcher<
      typename AllOfResult4<M1, M2, M3, M4>::type,
      typename AllOfResult5<M5, M6, M7, M8, M9>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9, typename M10>
struct AllOfResult10 {
  typedef BothOfMatcher<
      typename AllOfResult5<M1, M2, M3, M4, M5>::type,
      typename AllOfResult5<M6, M7, M8, M9, M10>::type
  > type;
};

// A set of metafunctions for computing the result type of AnyOf.
// AnyOf(m1, ..., mN) returns
// AnyOfResultN<decltype(m1), ..., decltype(mN)>::type.

// Although AnyOf isn't defined for one argument, AnyOfResult1 is defined
// to simplify the implementation.
template <typename M1>
struct AnyOfResult1 {
  typedef M1 type;
};

template <typename M1, typename M2>
struct AnyOfResult2 {
  typedef EitherOfMatcher<
      typename AnyOfResult1<M1>::type,
      typename AnyOfResult1<M2>::type
  > type;
};

template <typename M1, typename M2, typename M3>
struct AnyOfResult3 {
  typedef EitherOfMatcher<
      typename AnyOfResult1<M1>::type,
      typename AnyOfResult2<M2, M3>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4>
struct AnyOfResult4 {
  typedef EitherOfMatcher<
      typename AnyOfResult2<M1, M2>::type,
      typename AnyOfResult2<M3, M4>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5>
struct AnyOfResult5 {
  typedef EitherOfMatcher<
      typename AnyOfResult2<M1, M2>::type,
      typename AnyOfResult3<M3, M4, M5>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6>
struct AnyOfResult6 {
  typedef EitherOfMatcher<
      typename AnyOfResult3<M1, M2, M3>::type,
      typename AnyOfResult3<M4, M5, M6>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7>
struct AnyOfResult7 {
  typedef EitherOfMatcher<
      typename AnyOfResult3<M1, M2, M3>::type,
      typename AnyOfResult4<M4, M5, M6, M7>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8>
struct AnyOfResult8 {
  typedef EitherOfMatcher<
      typename AnyOfResult4<M1, M2, M3, M4>::type,
      typename AnyOfResult4<M5, M6, M7, M8>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9>
struct AnyOfResult9 {
  typedef EitherOfMatcher<
      typename AnyOfResult4<M1, M2, M3, M4>::type,
      typename AnyOfResult5<M5, M6, M7, M8, M9>::type
  > type;
};

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9, typename M10>
struct AnyOfResult10 {
  typedef EitherOfMatcher<
      typename AnyOfResult5<M1, M2, M3, M4, M5>::type,
      typename AnyOfResult5<M6, M7, M8, M9, M10>::type
  > type;
};

}  // namespace internal

// Args<N1, N2, ..., Nk>(a_matcher) matches a tuple if the selected
// fields of it matches a_matcher.  C++ doesn't support default
// arguments for function templates, so we have to overload it.
template <typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher>(matcher);
}

template <int k1, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1>(matcher);
}

template <int k1, int k2, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2>(matcher);
}

template <int k1, int k2, int k3, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3>(matcher);
}

template <int k1, int k2, int k3, int k4, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4>(matcher);
}

template <int k1, int k2, int k3, int k4, int k5, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5>(matcher);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6>(matcher);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7,
    typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6,
      k7>(matcher);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7, k8>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7,
      k8>(matcher);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    int k9, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7, k8, k9>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7, k8,
      k9>(matcher);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    int k9, int k10, typename InnerMatcher>
inline internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7, k8, k9,
    k10>
Args(const InnerMatcher& matcher) {
  return internal::ArgsMatcher<InnerMatcher, k1, k2, k3, k4, k5, k6, k7, k8,
      k9, k10>(matcher);
}

// ElementsAre(e_1, e_2, ... e_n) matches an STL-style container with
// n elements, where the i-th element in the container must
// match the i-th argument in the list.  Each argument of
// ElementsAre() can be either a value or a matcher.  We support up to
// 10 arguments.
//
// The use of DecayArray in the implementation allows ElementsAre()
// to accept string literals, whose type is const char[N], but we
// want to treat them as const char*.
//
// NOTE: Since ElementsAre() cares about the order of the elements, it
// must not be used with containers whose elements's order is
// undefined (e.g. hash_map).

inline internal::ElementsAreMatcher<
    ::testing::tuple<> >
ElementsAre() {
  typedef ::testing::tuple<> Args;
  return internal::ElementsAreMatcher<Args>(Args());
}

template <typename T1>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type> >
ElementsAre(const T1& e1) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1));
}

template <typename T1, typename T2>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type> >
ElementsAre(const T1& e1, const T2& e2) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2));
}

template <typename T1, typename T2, typename T3>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3));
}

template <typename T1, typename T2, typename T3, typename T4>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5, e6));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5, e6, e7));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type,
        typename internal::DecayArray<T8>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7, const T8& e8) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type,
      typename internal::DecayArray<T8>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5, e6, e7,
      e8));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type,
        typename internal::DecayArray<T8>::type,
        typename internal::DecayArray<T9>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7, const T8& e8, const T9& e9) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type,
      typename internal::DecayArray<T8>::type,
      typename internal::DecayArray<T9>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5, e6, e7,
      e8, e9));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9, typename T10>
inline internal::ElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type,
        typename internal::DecayArray<T8>::type,
        typename internal::DecayArray<T9>::type,
        typename internal::DecayArray<T10>::type> >
ElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7, const T8& e8, const T9& e9,
    const T10& e10) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type,
      typename internal::DecayArray<T8>::type,
      typename internal::DecayArray<T9>::type,
      typename internal::DecayArray<T10>::type> Args;
  return internal::ElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5, e6, e7,
      e8, e9, e10));
}

// UnorderedElementsAre(e_1, e_2, ..., e_n) is an ElementsAre extension
// that matches n elements in any order.  We support up to n=10 arguments.
//
// If you have >10 elements, consider UnorderedElementsAreArray() or
// UnorderedPointwise() instead.

inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<> >
UnorderedElementsAre() {
  typedef ::testing::tuple<> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args());
}

template <typename T1>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type> >
UnorderedElementsAre(const T1& e1) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1));
}

template <typename T1, typename T2>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2));
}

template <typename T1, typename T2, typename T3>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3));
}

template <typename T1, typename T2, typename T3, typename T4>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5,
      e6));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5,
      e6, e7));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type,
        typename internal::DecayArray<T8>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7, const T8& e8) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type,
      typename internal::DecayArray<T8>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5,
      e6, e7, e8));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type,
        typename internal::DecayArray<T8>::type,
        typename internal::DecayArray<T9>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7, const T8& e8, const T9& e9) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type,
      typename internal::DecayArray<T8>::type,
      typename internal::DecayArray<T9>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5,
      e6, e7, e8, e9));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9, typename T10>
inline internal::UnorderedElementsAreMatcher<
    ::testing::tuple<
        typename internal::DecayArray<T1>::type,
        typename internal::DecayArray<T2>::type,
        typename internal::DecayArray<T3>::type,
        typename internal::DecayArray<T4>::type,
        typename internal::DecayArray<T5>::type,
        typename internal::DecayArray<T6>::type,
        typename internal::DecayArray<T7>::type,
        typename internal::DecayArray<T8>::type,
        typename internal::DecayArray<T9>::type,
        typename internal::DecayArray<T10>::type> >
UnorderedElementsAre(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
    const T5& e5, const T6& e6, const T7& e7, const T8& e8, const T9& e9,
    const T10& e10) {
  typedef ::testing::tuple<
      typename internal::DecayArray<T1>::type,
      typename internal::DecayArray<T2>::type,
      typename internal::DecayArray<T3>::type,
      typename internal::DecayArray<T4>::type,
      typename internal::DecayArray<T5>::type,
      typename internal::DecayArray<T6>::type,
      typename internal::DecayArray<T7>::type,
      typename internal::DecayArray<T8>::type,
      typename internal::DecayArray<T9>::type,
      typename internal::DecayArray<T10>::type> Args;
  return internal::UnorderedElementsAreMatcher<Args>(Args(e1, e2, e3, e4, e5,
      e6, e7, e8, e9, e10));
}

// AllOf(m1, m2, ..., mk) matches any value that matches all of the given
// sub-matchers.  AllOf is called fully qualified to prevent ADL from firing.

template <typename M1, typename M2>
inline typename internal::AllOfResult2<M1, M2>::type
AllOf(M1 m1, M2 m2) {
  return typename internal::AllOfResult2<M1, M2>::type(
      m1,
      m2);
}

template <typename M1, typename M2, typename M3>
inline typename internal::AllOfResult3<M1, M2, M3>::type
AllOf(M1 m1, M2 m2, M3 m3) {
  return typename internal::AllOfResult3<M1, M2, M3>::type(
      m1,
      ::testing::AllOf(m2, m3));
}

template <typename M1, typename M2, typename M3, typename M4>
inline typename internal::AllOfResult4<M1, M2, M3, M4>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4) {
  return typename internal::AllOfResult4<M1, M2, M3, M4>::type(
      ::testing::AllOf(m1, m2),
      ::testing::AllOf(m3, m4));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5>
inline typename internal::AllOfResult5<M1, M2, M3, M4, M5>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5) {
  return typename internal::AllOfResult5<M1, M2, M3, M4, M5>::type(
      ::testing::AllOf(m1, m2),
      ::testing::AllOf(m3, m4, m5));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6>
inline typename internal::AllOfResult6<M1, M2, M3, M4, M5, M6>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6) {
  return typename internal::AllOfResult6<M1, M2, M3, M4, M5, M6>::type(
      ::testing::AllOf(m1, m2, m3),
      ::testing::AllOf(m4, m5, m6));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7>
inline typename internal::AllOfResult7<M1, M2, M3, M4, M5, M6, M7>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7) {
  return typename internal::AllOfResult7<M1, M2, M3, M4, M5, M6, M7>::type(
      ::testing::AllOf(m1, m2, m3),
      ::testing::AllOf(m4, m5, m6, m7));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8>
inline typename internal::AllOfResult8<M1, M2, M3, M4, M5, M6, M7, M8>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7, M8 m8) {
  return typename internal::AllOfResult8<M1, M2, M3, M4, M5, M6, M7, M8>::type(
      ::testing::AllOf(m1, m2, m3, m4),
      ::testing::AllOf(m5, m6, m7, m8));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9>
inline typename internal::AllOfResult9<M1, M2, M3, M4, M5, M6, M7, M8, M9>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7, M8 m8, M9 m9) {
  return typename internal::AllOfResult9<M1, M2, M3, M4, M5, M6, M7, M8,
      M9>::type(
      ::testing::AllOf(m1, m2, m3, m4),
      ::testing::AllOf(m5, m6, m7, m8, m9));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9, typename M10>
inline typename internal::AllOfResult10<M1, M2, M3, M4, M5, M6, M7, M8, M9,
    M10>::type
AllOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7, M8 m8, M9 m9, M10 m10) {
  return typename internal::AllOfResult10<M1, M2, M3, M4, M5, M6, M7, M8, M9,
      M10>::type(
      ::testing::AllOf(m1, m2, m3, m4, m5),
      ::testing::AllOf(m6, m7, m8, m9, m10));
}

// AnyOf(m1, m2, ..., mk) matches any value that matches any of the given
// sub-matchers.  AnyOf is called fully qualified to prevent ADL from firing.

template <typename M1, typename M2>
inline typename internal::AnyOfResult2<M1, M2>::type
AnyOf(M1 m1, M2 m2) {
  return typename internal::AnyOfResult2<M1, M2>::type(
      m1,
      m2);
}

template <typename M1, typename M2, typename M3>
inline typename internal::AnyOfResult3<M1, M2, M3>::type
AnyOf(M1 m1, M2 m2, M3 m3) {
  return typename internal::AnyOfResult3<M1, M2, M3>::type(
      m1,
      ::testing::AnyOf(m2, m3));
}

template <typename M1, typename M2, typename M3, typename M4>
inline typename internal::AnyOfResult4<M1, M2, M3, M4>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4) {
  return typename internal::AnyOfResult4<M1, M2, M3, M4>::type(
      ::testing::AnyOf(m1, m2),
      ::testing::AnyOf(m3, m4));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5>
inline typename internal::AnyOfResult5<M1, M2, M3, M4, M5>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5) {
  return typename internal::AnyOfResult5<M1, M2, M3, M4, M5>::type(
      ::testing::AnyOf(m1, m2),
      ::testing::AnyOf(m3, m4, m5));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6>
inline typename internal::AnyOfResult6<M1, M2, M3, M4, M5, M6>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6) {
  return typename internal::AnyOfResult6<M1, M2, M3, M4, M5, M6>::type(
      ::testing::AnyOf(m1, m2, m3),
      ::testing::AnyOf(m4, m5, m6));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7>
inline typename internal::AnyOfResult7<M1, M2, M3, M4, M5, M6, M7>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7) {
  return typename internal::AnyOfResult7<M1, M2, M3, M4, M5, M6, M7>::type(
      ::testing::AnyOf(m1, m2, m3),
      ::testing::AnyOf(m4, m5, m6, m7));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8>
inline typename internal::AnyOfResult8<M1, M2, M3, M4, M5, M6, M7, M8>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7, M8 m8) {
  return typename internal::AnyOfResult8<M1, M2, M3, M4, M5, M6, M7, M8>::type(
      ::testing::AnyOf(m1, m2, m3, m4),
      ::testing::AnyOf(m5, m6, m7, m8));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9>
inline typename internal::AnyOfResult9<M1, M2, M3, M4, M5, M6, M7, M8, M9>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7, M8 m8, M9 m9) {
  return typename internal::AnyOfResult9<M1, M2, M3, M4, M5, M6, M7, M8,
      M9>::type(
      ::testing::AnyOf(m1, m2, m3, m4),
      ::testing::AnyOf(m5, m6, m7, m8, m9));
}

template <typename M1, typename M2, typename M3, typename M4, typename M5,
    typename M6, typename M7, typename M8, typename M9, typename M10>
inline typename internal::AnyOfResult10<M1, M2, M3, M4, M5, M6, M7, M8, M9,
    M10>::type
AnyOf(M1 m1, M2 m2, M3 m3, M4 m4, M5 m5, M6 m6, M7 m7, M8 m8, M9 m9, M10 m10) {
  return typename internal::AnyOfResult10<M1, M2, M3, M4, M5, M6, M7, M8, M9,
      M10>::type(
      ::testing::AnyOf(m1, m2, m3, m4, m5),
      ::testing::AnyOf(m6, m7, m8, m9, m10));
}

}  // namespace testing


// The MATCHER* family of macros can be used in a namespace scope to
// define custom matchers easily.
//
// Basic Usage
// ===========
//
// The syntax
//
//   MATCHER(name, description_string) { statements; }
//
// defines a matcher with the given name that executes the statements,
// which must return a bool to indicate if the match succeeds.  Inside
// the statements, you can refer to the value being matched by 'arg',
// and refer to its type by 'arg_type'.
//
// The description string documents what the matcher does, and is used
// to generate the failure message when the match fails.  Since a
// MATCHER() is usually defined in a header file shared by multiple
// C++ source files, we require the description to be a C-string
// literal to avoid possible side effects.  It can be empty, in which
// case we'll use the sequence of words in the matcher name as the
// description.
//
// For example:
//
//   MATCHER(IsEven, "") { return (arg % 2) == 0; }
//
// allows you to write
//
//   // Expects mock_foo.Bar(n) to be called where n is even.
//   EXPECT_CALL(mock_foo, Bar(IsEven()));
//
// or,
//
//   // Verifies that the value of some_expression is even.
//   EXPECT_THAT(some_expression, IsEven());
//
// If the above assertion fails, it will print something like:
//
//   Value of: some_expression
//   Expected: is even
//     Actual: 7
//
// where the description "is even" is automatically calculated from the
// matcher name IsEven.
//
// Argument Type
// =============
//
// Note that the type of the value being matched (arg_type) is
// determined by the context in which you use the matcher and is
// supplied to you by the compiler, so you don't need to worry about
// declaring it (nor can you).  This allows the matcher to be
// polymorphic.  For example, IsEven() can be used to match any type
// where the value of "(arg % 2) == 0" can be implicitly converted to
// a bool.  In the "Bar(IsEven())" example above, if method Bar()
// takes an int, 'arg_type' will be int; if it takes an unsigned long,
// 'arg_type' will be unsigned long; and so on.
//
// Parameterizing Matchers
// =======================
//
// Sometimes you'll want to parameterize the matcher.  For that you
// can use another macro:
//
//   MATCHER_P(name, param_name, description_string) { statements; }
//
// For example:
//
//   MATCHER_P(HasAbsoluteValue, value, "") { return abs(arg) == value; }
//
// will allow you to write:
//
//   EXPECT_THAT(Blah("a"), HasAbsoluteValue(n));
//
// which may lead to this message (assuming n is 10):
//
//   Value of: Blah("a")
//   Expected: has absolute value 10
//     Actual: -9
//
// Note that both the matcher description and its parameter are
// printed, making the message human-friendly.
//
// In the matcher definition body, you can write 'foo_type' to
// reference the type of a parameter named 'foo'.  For example, in the
// body of MATCHER_P(HasAbsoluteValue, value) above, you can write
// 'value_type' to refer to the type of 'value'.
//
// We also provide MATCHER_P2, MATCHER_P3, ..., up to MATCHER_P10 to
// support multi-parameter matchers.
//
// Describing Parameterized Matchers
// =================================
//
// The last argument to MATCHER*() is a string-typed expression.  The
// expression can reference all of the matcher's parameters and a
// special bool-typed variable named 'negation'.  When 'negation' is
// false, the expression should evaluate to the matcher's description;
// otherwise it should evaluate to the description of the negation of
// the matcher.  For example,
//
//   using testing::PrintToString;
//
//   MATCHER_P2(InClosedRange, low, hi,
//       std::string(negation ? "is not" : "is") + " in range [" +
//       PrintToString(low) + ", " + PrintToString(hi) + "]") {
//     return low <= arg && arg <= hi;
//   }
//   ...
//   EXPECT_THAT(3, InClosedRange(4, 6));
//   EXPECT_THAT(3, Not(InClosedRange(2, 4)));
//
// would generate two failures that contain the text:
//
//   Expected: is in range [4, 6]
//   ...
//   Expected: is not in range [2, 4]
//
// If you specify "" as the description, the failure message will
// contain the sequence of words in the matcher name followed by the
// parameter values printed as a tuple.  For example,
//
//   MATCHER_P2(InClosedRange, low, hi, "") { ... }
//   ...
//   EXPECT_THAT(3, InClosedRange(4, 6));
//   EXPECT_THAT(3, Not(InClosedRange(2, 4)));
//
// would generate two failures that contain the text:
//
//   Expected: in closed range (4, 6)
//   ...
//   Expected: not (in closed range (2, 4))
//
// Types of Matcher Parameters
// ===========================
//
// For the purpose of typing, you can view
//
//   MATCHER_Pk(Foo, p1, ..., pk, description_string) { ... }
//
// as shorthand for
//
//   template <typename p1_type, ..., typename pk_type>
//   FooMatcherPk<p1_type, ..., pk_type>
//   Foo(p1_type p1, ..., pk_type pk) { ... }
//
// When you write Foo(v1, ..., vk), the compiler infers the types of
// the parameters v1, ..., and vk for you.  If you are not happy with
// the result of the type inference, you can specify the types by
// explicitly instantiating the template, as in Foo<long, bool>(5,
// false).  As said earlier, you don't get to (or need to) specify
// 'arg_type' as that's determined by the context in which the matcher
// is used.  You can assign the result of expression Foo(p1, ..., pk)
// to a variable of type FooMatcherPk<p1_type, ..., pk_type>.  This
// can be useful when composing matchers.
//
// While you can instantiate a matcher template with reference types,
// passing the parameters by pointer usually makes your code more
// readable.  If, however, you still want to pass a parameter by
// reference, be aware that in the failure message generated by the
// matcher you will see the value of the referenced object but not its
// address.
//
// Explaining Match Results
// ========================
//
// Sometimes the matcher description alone isn't enough to explain why
// the match has failed or succeeded.  For example, when expecting a
// long string, it can be very helpful to also print the diff between
// the expected string and the actual one.  To achieve that, you can
// optionally stream additional information to a special variable
// named result_listener, whose type is a pointer to class
// MatchResultListener:
//
//   MATCHER_P(EqualsLongString, str, "") {
//     if (arg == str) return true;
//
//     *result_listener << "the difference: "
///                     << DiffStrings(str, arg);
//     return false;
//   }
//
// Overloading Matchers
// ====================
//
// You can overload matchers with different numbers of parameters:
//
//   MATCHER_P(Blah, a, description_string1) { ... }
//   MATCHER_P2(Blah, a, b, description_string2) { ... }
//
// Caveats
// =======
//
// When defining a new matcher, you should also consider implementing
// MatcherInterface or using MakePolymorphicMatcher().  These
// approaches require more work than the MATCHER* macros, but also
// give you more control on the types of the value being matched and
// the matcher parameters, which may leads to better compiler error
// messages when the matcher is used wrong.  They also allow
// overloading matchers based on parameter types (as opposed to just
// based on the number of parameters).
//
// MATCHER*() can only be used in a namespace scope.  The reason is
// that C++ doesn't yet allow function-local types to be used to
// instantiate templates.  The up-coming C++0x standard will fix this.
// Once that's done, we'll consider supporting using MATCHER*() inside
// a function.
//
// More Information
// ================
//
// To learn more about using these macros, please search for 'MATCHER'
// on https://github.com/google/googletest/blob/master/googlemock/docs/
// CookBook.md

#define MATCHER(name, description)\
  class name##Matcher {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl()\
           {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<>()));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>());\
    }\
    name##Matcher() {\
    }\
   private:\
  };\
  inline name##Matcher name() {\
    return name##Matcher();\
  }\
  template <typename arg_type>\
  bool name##Matcher::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P(name, p0, description)\
  template <typename p0##_type>\
  class name##MatcherP {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      explicit gmock_Impl(p0##_type gmock_p0)\
           : p0(::testing::internal::move(gmock_p0)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type>(p0)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0));\
    }\
    explicit name##MatcherP(p0##_type gmock_p0) : \
        p0(::testing::internal::move(gmock_p0)) {\
    }\
    p0##_type const p0;\
   private:\
  };\
  template <typename p0##_type>\
  inline name##MatcherP<p0##_type> name(p0##_type p0) {\
    return name##MatcherP<p0##_type>(p0);\
  }\
  template <typename p0##_type>\
  template <typename arg_type>\
  bool name##MatcherP<p0##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P2(name, p0, p1, description)\
  template <typename p0##_type, typename p1##_type>\
  class name##MatcherP2 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type>(p0, p1)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1));\
    }\
    name##MatcherP2(p0##_type gmock_p0, \
        p1##_type gmock_p1) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type>\
  inline name##MatcherP2<p0##_type, p1##_type> name(p0##_type p0, \
      p1##_type p1) {\
    return name##MatcherP2<p0##_type, p1##_type>(p0, p1);\
  }\
  template <typename p0##_type, typename p1##_type>\
  template <typename arg_type>\
  bool name##MatcherP2<p0##_type, \
      p1##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P3(name, p0, p1, p2, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  class name##MatcherP3 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type>(p0, p1, \
                    p2)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2));\
    }\
    name##MatcherP3(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  inline name##MatcherP3<p0##_type, p1##_type, p2##_type> name(p0##_type p0, \
      p1##_type p1, p2##_type p2) {\
    return name##MatcherP3<p0##_type, p1##_type, p2##_type>(p0, p1, p2);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  template <typename arg_type>\
  bool name##MatcherP3<p0##_type, p1##_type, \
      p2##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P4(name, p0, p1, p2, p3, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  class name##MatcherP4 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, \
                    p3##_type>(p0, p1, p2, p3)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3));\
    }\
    name##MatcherP4(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, \
        p3##_type gmock_p3) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  inline name##MatcherP4<p0##_type, p1##_type, p2##_type, \
      p3##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, \
      p3##_type p3) {\
    return name##MatcherP4<p0##_type, p1##_type, p2##_type, p3##_type>(p0, \
        p1, p2, p3);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  template <typename arg_type>\
  bool name##MatcherP4<p0##_type, p1##_type, p2##_type, \
      p3##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P5(name, p0, p1, p2, p3, p4, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  class name##MatcherP5 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)), \
               p4(::testing::internal::move(gmock_p4)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
      p4##_type const p4;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, p3##_type, \
                    p4##_type>(p0, p1, p2, p3, p4)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3, p4));\
    }\
    name##MatcherP5(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, \
        p4##_type gmock_p4) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
    p4##_type const p4;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  inline name##MatcherP5<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4) {\
    return name##MatcherP5<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type>(p0, p1, p2, p3, p4);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  template <typename arg_type>\
  bool name##MatcherP5<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P6(name, p0, p1, p2, p3, p4, p5, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  class name##MatcherP6 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)), \
               p4(::testing::internal::move(gmock_p4)), \
               p5(::testing::internal::move(gmock_p5)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
      p4##_type const p4;\
      p5##_type const p5;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, p3##_type, \
                    p4##_type, p5##_type>(p0, p1, p2, p3, p4, p5)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3, p4, p5));\
    }\
    name##MatcherP6(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
    p4##_type const p4;\
    p5##_type const p5;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  inline name##MatcherP6<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, \
      p3##_type p3, p4##_type p4, p5##_type p5) {\
    return name##MatcherP6<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type>(p0, p1, p2, p3, p4, p5);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  template <typename arg_type>\
  bool name##MatcherP6<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
      p5##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P7(name, p0, p1, p2, p3, p4, p5, p6, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  class name##MatcherP7 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)), \
               p4(::testing::internal::move(gmock_p4)), \
               p5(::testing::internal::move(gmock_p5)), \
               p6(::testing::internal::move(gmock_p6)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
      p4##_type const p4;\
      p5##_type const p5;\
      p6##_type const p6;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, p3##_type, \
                    p4##_type, p5##_type, p6##_type>(p0, p1, p2, p3, p4, p5, \
                    p6)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3, p4, p5, p6));\
    }\
    name##MatcherP7(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, \
        p6##_type gmock_p6) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
    p4##_type const p4;\
    p5##_type const p5;\
    p6##_type const p6;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  inline name##MatcherP7<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type> name(p0##_type p0, p1##_type p1, \
      p2##_type p2, p3##_type p3, p4##_type p4, p5##_type p5, \
      p6##_type p6) {\
    return name##MatcherP7<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type>(p0, p1, p2, p3, p4, p5, p6);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  template <typename arg_type>\
  bool name##MatcherP7<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
      p5##_type, p6##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P8(name, p0, p1, p2, p3, p4, p5, p6, p7, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  class name##MatcherP8 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)), \
               p4(::testing::internal::move(gmock_p4)), \
               p5(::testing::internal::move(gmock_p5)), \
               p6(::testing::internal::move(gmock_p6)), \
               p7(::testing::internal::move(gmock_p7)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
      p4##_type const p4;\
      p5##_type const p5;\
      p6##_type const p6;\
      p7##_type const p7;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, p3##_type, \
                    p4##_type, p5##_type, p6##_type, p7##_type>(p0, p1, p2, \
                    p3, p4, p5, p6, p7)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3, p4, p5, p6, p7));\
    }\
    name##MatcherP8(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, \
        p7##_type gmock_p7) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)), \
        p7(::testing::internal::move(gmock_p7)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
    p4##_type const p4;\
    p5##_type const p5;\
    p6##_type const p6;\
    p7##_type const p7;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  inline name##MatcherP8<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type> name(p0##_type p0, \
      p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, p5##_type p5, \
      p6##_type p6, p7##_type p7) {\
    return name##MatcherP8<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type>(p0, p1, p2, p3, p4, p5, \
        p6, p7);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  template <typename arg_type>\
  bool name##MatcherP8<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
      p5##_type, p6##_type, \
      p7##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P9(name, p0, p1, p2, p3, p4, p5, p6, p7, p8, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  class name##MatcherP9 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7, p8##_type gmock_p8)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)), \
               p4(::testing::internal::move(gmock_p4)), \
               p5(::testing::internal::move(gmock_p5)), \
               p6(::testing::internal::move(gmock_p6)), \
               p7(::testing::internal::move(gmock_p7)), \
               p8(::testing::internal::move(gmock_p8)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
      p4##_type const p4;\
      p5##_type const p5;\
      p6##_type const p6;\
      p7##_type const p7;\
      p8##_type const p8;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, p3##_type, \
                    p4##_type, p5##_type, p6##_type, p7##_type, \
                    p8##_type>(p0, p1, p2, p3, p4, p5, p6, p7, p8)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3, p4, p5, p6, p7, p8));\
    }\
    name##MatcherP9(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)), \
        p7(::testing::internal::move(gmock_p7)), \
        p8(::testing::internal::move(gmock_p8)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
    p4##_type const p4;\
    p5##_type const p5;\
    p6##_type const p6;\
    p7##_type const p7;\
    p8##_type const p8;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  inline name##MatcherP9<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, \
      p8##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, \
      p8##_type p8) {\
    return name##MatcherP9<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type, p8##_type>(p0, p1, p2, \
        p3, p4, p5, p6, p7, p8);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  template <typename arg_type>\
  bool name##MatcherP9<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
      p5##_type, p6##_type, p7##_type, \
      p8##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#define MATCHER_P10(name, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, description)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  class name##MatcherP10 {\
   public:\
    template <typename arg_type>\
    class gmock_Impl : public ::testing::MatcherInterface<\
        GTEST_REFERENCE_TO_CONST_(arg_type)> {\
     public:\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7, p8##_type gmock_p8, \
          p9##_type gmock_p9)\
           : p0(::testing::internal::move(gmock_p0)), \
               p1(::testing::internal::move(gmock_p1)), \
               p2(::testing::internal::move(gmock_p2)), \
               p3(::testing::internal::move(gmock_p3)), \
               p4(::testing::internal::move(gmock_p4)), \
               p5(::testing::internal::move(gmock_p5)), \
               p6(::testing::internal::move(gmock_p6)), \
               p7(::testing::internal::move(gmock_p7)), \
               p8(::testing::internal::move(gmock_p8)), \
               p9(::testing::internal::move(gmock_p9)) {}\
      virtual bool MatchAndExplain(\
          GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
          ::testing::MatchResultListener* result_listener) const;\
      virtual void DescribeTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(false);\
      }\
      virtual void DescribeNegationTo(::std::ostream* gmock_os) const {\
        *gmock_os << FormatDescription(true);\
      }\
      p0##_type const p0;\
      p1##_type const p1;\
      p2##_type const p2;\
      p3##_type const p3;\
      p4##_type const p4;\
      p5##_type const p5;\
      p6##_type const p6;\
      p7##_type const p7;\
      p8##_type const p8;\
      p9##_type const p9;\
     private:\
      ::std::string FormatDescription(bool negation) const {\
        ::std::string gmock_description = (description);\
        if (!gmock_description.empty())\
          return gmock_description;\
        return ::testing::internal::FormatMatcherDescription(\
            negation, #name, \
            ::testing::internal::UniversalTersePrintTupleFieldsToStrings(\
                ::testing::tuple<p0##_type, p1##_type, p2##_type, p3##_type, \
                    p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, \
                    p9##_type>(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)));\
      }\
    };\
    template <typename arg_type>\
    operator ::testing::Matcher<arg_type>() const {\
      return ::testing::Matcher<arg_type>(\
          new gmock_Impl<arg_type>(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9));\
    }\
    name##MatcherP10(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8, \
        p9##_type gmock_p9) : p0(::testing::internal::move(gmock_p0)), \
        p1(::testing::internal::move(gmock_p1)), \
        p2(::testing::internal::move(gmock_p2)), \
        p3(::testing::internal::move(gmock_p3)), \
        p4(::testing::internal::move(gmock_p4)), \
        p5(::testing::internal::move(gmock_p5)), \
        p6(::testing::internal::move(gmock_p6)), \
        p7(::testing::internal::move(gmock_p7)), \
        p8(::testing::internal::move(gmock_p8)), \
        p9(::testing::internal::move(gmock_p9)) {\
    }\
    p0##_type const p0;\
    p1##_type const p1;\
    p2##_type const p2;\
    p3##_type const p3;\
    p4##_type const p4;\
    p5##_type const p5;\
    p6##_type const p6;\
    p7##_type const p7;\
    p8##_type const p8;\
    p9##_type const p9;\
   private:\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  inline name##MatcherP10<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, \
      p9##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8, \
      p9##_type p9) {\
    return name##MatcherP10<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, p9##_type>(p0, \
        p1, p2, p3, p4, p5, p6, p7, p8, p9);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  template <typename arg_type>\
  bool name##MatcherP10<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, \
      p9##_type>::gmock_Impl<arg_type>::MatchAndExplain(\
      GTEST_REFERENCE_TO_CONST_(arg_type) arg,\
      ::testing::MatchResultListener* result_listener GTEST_ATTRIBUTE_UNUSED_)\
          const

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_MATCHERS_H_
// This file was GENERATED by command:
//     pump.py gmock-generated-nice-strict.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2008, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Implements class templates NiceMock, NaggyMock, and StrictMock.
//
// Given a mock class MockFoo that is created using Google Mock,
// NiceMock<MockFoo> is a subclass of MockFoo that allows
// uninteresting calls (i.e. calls to mock methods that have no
// EXPECT_CALL specs), NaggyMock<MockFoo> is a subclass of MockFoo
// that prints a warning when an uninteresting call occurs, and
// StrictMock<MockFoo> is a subclass of MockFoo that treats all
// uninteresting calls as errors.
//
// Currently a mock is naggy by default, so MockFoo and
// NaggyMock<MockFoo> behave like the same.  However, we will soon
// switch the default behavior of mocks to be nice, as that in general
// leads to more maintainable tests.  When that happens, MockFoo will
// stop behaving like NaggyMock<MockFoo> and start behaving like
// NiceMock<MockFoo>.
//
// NiceMock, NaggyMock, and StrictMock "inherit" the constructors of
// their respective base class.  Therefore you can write
// NiceMock<MockFoo>(5, "a") to construct a nice mock where MockFoo
// has a constructor that accepts (int, const char*), for example.
//
// A known limitation is that NiceMock<MockFoo>, NaggyMock<MockFoo>,
// and StrictMock<MockFoo> only works for mock methods defined using
// the MOCK_METHOD* family of macros DIRECTLY in the MockFoo class.
// If a mock method is defined in a base class of MockFoo, the "nice"
// or "strict" modifier may not affect it, depending on the compiler.
// In particular, nesting NiceMock, NaggyMock, and StrictMock is NOT
// supported.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_NICE_STRICT_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_NICE_STRICT_H_


namespace testing {

template <class MockClass>
class NiceMock : public MockClass {
 public:
  NiceMock() : MockClass() {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

#if GTEST_LANG_CXX11
  // Ideally, we would inherit base class's constructors through a using
  // declaration, which would preserve their visibility. However, many existing
  // tests rely on the fact that current implementation reexports protected
  // constructors as public. These tests would need to be cleaned up first.

  // Single argument constructor is special-cased so that it can be
  // made explicit.
  template <typename A>
  explicit NiceMock(A&& arg) : MockClass(std::forward<A>(arg)) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename... An>
  NiceMock(A1&& arg1, A2&& arg2, An&&... args)
      : MockClass(std::forward<A1>(arg1), std::forward<A2>(arg2),
                  std::forward<An>(args)...) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }
#else
  // C++98 doesn't have variadic templates, so we have to define one
  // for each arity.
  template <typename A1>
  explicit NiceMock(const A1& a1) : MockClass(a1) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }
  template <typename A1, typename A2>
  NiceMock(const A1& a1, const A2& a2) : MockClass(a1, a2) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3>
  NiceMock(const A1& a1, const A2& a2, const A3& a3) : MockClass(a1, a2, a3) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4>
  NiceMock(const A1& a1, const A2& a2, const A3& a3,
      const A4& a4) : MockClass(a1, a2, a3, a4) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5>
  NiceMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5) : MockClass(a1, a2, a3, a4, a5) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6>
  NiceMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6) : MockClass(a1, a2, a3, a4, a5, a6) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7>
  NiceMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7) : MockClass(a1, a2, a3, a4, a5,
      a6, a7) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8>
  NiceMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8) : MockClass(a1,
      a2, a3, a4, a5, a6, a7, a8) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8, typename A9>
  NiceMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8,
      const A9& a9) : MockClass(a1, a2, a3, a4, a5, a6, a7, a8, a9) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8, typename A9, typename A10>
  NiceMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9,
      const A10& a10) : MockClass(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) {
    ::testing::Mock::AllowUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

#endif  // GTEST_LANG_CXX11

  ~NiceMock() {
    ::testing::Mock::UnregisterCallReaction(
        internal::ImplicitCast_<MockClass*>(this));
  }

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(NiceMock);
};

template <class MockClass>
class NaggyMock : public MockClass {
 public:
  NaggyMock() : MockClass() {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

#if GTEST_LANG_CXX11
  // Ideally, we would inherit base class's constructors through a using
  // declaration, which would preserve their visibility. However, many existing
  // tests rely on the fact that current implementation reexports protected
  // constructors as public. These tests would need to be cleaned up first.

  // Single argument constructor is special-cased so that it can be
  // made explicit.
  template <typename A>
  explicit NaggyMock(A&& arg) : MockClass(std::forward<A>(arg)) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename... An>
  NaggyMock(A1&& arg1, A2&& arg2, An&&... args)
      : MockClass(std::forward<A1>(arg1), std::forward<A2>(arg2),
                  std::forward<An>(args)...) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }
#else
  // C++98 doesn't have variadic templates, so we have to define one
  // for each arity.
  template <typename A1>
  explicit NaggyMock(const A1& a1) : MockClass(a1) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }
  template <typename A1, typename A2>
  NaggyMock(const A1& a1, const A2& a2) : MockClass(a1, a2) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3) : MockClass(a1, a2, a3) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3,
      const A4& a4) : MockClass(a1, a2, a3, a4) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5) : MockClass(a1, a2, a3, a4, a5) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6) : MockClass(a1, a2, a3, a4, a5, a6) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7) : MockClass(a1, a2, a3, a4, a5,
      a6, a7) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8) : MockClass(a1,
      a2, a3, a4, a5, a6, a7, a8) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8, typename A9>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8,
      const A9& a9) : MockClass(a1, a2, a3, a4, a5, a6, a7, a8, a9) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8, typename A9, typename A10>
  NaggyMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9,
      const A10& a10) : MockClass(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) {
    ::testing::Mock::WarnUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

#endif  // GTEST_LANG_CXX11

  ~NaggyMock() {
    ::testing::Mock::UnregisterCallReaction(
        internal::ImplicitCast_<MockClass*>(this));
  }

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(NaggyMock);
};

template <class MockClass>
class StrictMock : public MockClass {
 public:
  StrictMock() : MockClass() {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

#if GTEST_LANG_CXX11
  // Ideally, we would inherit base class's constructors through a using
  // declaration, which would preserve their visibility. However, many existing
  // tests rely on the fact that current implementation reexports protected
  // constructors as public. These tests would need to be cleaned up first.

  // Single argument constructor is special-cased so that it can be
  // made explicit.
  template <typename A>
  explicit StrictMock(A&& arg) : MockClass(std::forward<A>(arg)) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename... An>
  StrictMock(A1&& arg1, A2&& arg2, An&&... args)
      : MockClass(std::forward<A1>(arg1), std::forward<A2>(arg2),
                  std::forward<An>(args)...) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }
#else
  // C++98 doesn't have variadic templates, so we have to define one
  // for each arity.
  template <typename A1>
  explicit StrictMock(const A1& a1) : MockClass(a1) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }
  template <typename A1, typename A2>
  StrictMock(const A1& a1, const A2& a2) : MockClass(a1, a2) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3>
  StrictMock(const A1& a1, const A2& a2, const A3& a3) : MockClass(a1, a2, a3) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4>
  StrictMock(const A1& a1, const A2& a2, const A3& a3,
      const A4& a4) : MockClass(a1, a2, a3, a4) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5>
  StrictMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5) : MockClass(a1, a2, a3, a4, a5) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6>
  StrictMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6) : MockClass(a1, a2, a3, a4, a5, a6) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7>
  StrictMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7) : MockClass(a1, a2, a3, a4, a5,
      a6, a7) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8>
  StrictMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8) : MockClass(a1,
      a2, a3, a4, a5, a6, a7, a8) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8, typename A9>
  StrictMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8,
      const A9& a9) : MockClass(a1, a2, a3, a4, a5, a6, a7, a8, a9) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

  template <typename A1, typename A2, typename A3, typename A4, typename A5,
      typename A6, typename A7, typename A8, typename A9, typename A10>
  StrictMock(const A1& a1, const A2& a2, const A3& a3, const A4& a4,
      const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9,
      const A10& a10) : MockClass(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) {
    ::testing::Mock::FailUninterestingCalls(
        internal::ImplicitCast_<MockClass*>(this));
  }

#endif  // GTEST_LANG_CXX11

  ~StrictMock() {
    ::testing::Mock::UnregisterCallReaction(
        internal::ImplicitCast_<MockClass*>(this));
  }

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(StrictMock);
};

// The following specializations catch some (relatively more common)
// user errors of nesting nice and strict mocks.  They do NOT catch
// all possible errors.

// These specializations are declared but not defined, as NiceMock,
// NaggyMock, and StrictMock cannot be nested.

template <typename MockClass>
class NiceMock<NiceMock<MockClass> >;
template <typename MockClass>
class NiceMock<NaggyMock<MockClass> >;
template <typename MockClass>
class NiceMock<StrictMock<MockClass> >;

template <typename MockClass>
class NaggyMock<NiceMock<MockClass> >;
template <typename MockClass>
class NaggyMock<NaggyMock<MockClass> >;
template <typename MockClass>
class NaggyMock<StrictMock<MockClass> >;

template <typename MockClass>
class StrictMock<NiceMock<MockClass> >;
template <typename MockClass>
class StrictMock<NaggyMock<MockClass> >;
template <typename MockClass>
class StrictMock<StrictMock<MockClass> >;

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_NICE_STRICT_H_
// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some actions that depend on gmock-generated-actions.h.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_MORE_ACTIONS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_MORE_ACTIONS_H_

#include <algorithm>


namespace testing {
namespace internal {

// Implements the Invoke(f) action.  The template argument
// FunctionImpl is the implementation type of f, which can be either a
// function pointer or a functor.  Invoke(f) can be used as an
// Action<F> as long as f's type is compatible with F (i.e. f can be
// assigned to a tr1::function<F>).
template <typename FunctionImpl>
class InvokeAction {
 public:
  // The c'tor makes a copy of function_impl (either a function
  // pointer or a functor).
  explicit InvokeAction(FunctionImpl function_impl)
      : function_impl_(function_impl) {}

  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple& args) {
    return InvokeHelper<Result, ArgumentTuple>::Invoke(function_impl_, args);
  }

 private:
  FunctionImpl function_impl_;

  GTEST_DISALLOW_ASSIGN_(InvokeAction);
};

// Implements the Invoke(object_ptr, &Class::Method) action.
template <class Class, typename MethodPtr>
class InvokeMethodAction {
 public:
  InvokeMethodAction(Class* obj_ptr, MethodPtr method_ptr)
      : method_ptr_(method_ptr), obj_ptr_(obj_ptr) {}

  template <typename Result, typename ArgumentTuple>
  Result Perform(const ArgumentTuple& args) const {
    return InvokeHelper<Result, ArgumentTuple>::InvokeMethod(
        obj_ptr_, method_ptr_, args);
  }

 private:
  // The order of these members matters.  Reversing the order can trigger
  // warning C4121 in MSVC (see
  // http://computer-programming-forum.com/7-vc.net/6fbc30265f860ad1.htm ).
  const MethodPtr method_ptr_;
  Class* const obj_ptr_;

  GTEST_DISALLOW_ASSIGN_(InvokeMethodAction);
};

// An internal replacement for std::copy which mimics its behavior. This is
// necessary because Visual Studio deprecates ::std::copy, issuing warning 4996.
// However Visual Studio 2010 and later do not honor #pragmas which disable that
// warning.
template<typename InputIterator, typename OutputIterator>
inline OutputIterator CopyElements(InputIterator first,
                                   InputIterator last,
                                   OutputIterator output) {
  for (; first != last; ++first, ++output) {
    *output = *first;
  }
  return output;
}

}  // namespace internal

// Various overloads for Invoke().

// Creates an action that invokes 'function_impl' with the mock
// function's arguments.
template <typename FunctionImpl>
PolymorphicAction<internal::InvokeAction<FunctionImpl> > Invoke(
    FunctionImpl function_impl) {
  return MakePolymorphicAction(
      internal::InvokeAction<FunctionImpl>(function_impl));
}

// Creates an action that invokes the given method on the given object
// with the mock function's arguments.
template <class Class, typename MethodPtr>
PolymorphicAction<internal::InvokeMethodAction<Class, MethodPtr> > Invoke(
    Class* obj_ptr, MethodPtr method_ptr) {
  return MakePolymorphicAction(
      internal::InvokeMethodAction<Class, MethodPtr>(obj_ptr, method_ptr));
}

// WithoutArgs(inner_action) can be used in a mock function with a
// non-empty argument list to perform inner_action, which takes no
// argument.  In other words, it adapts an action accepting no
// argument to one that accepts (and ignores) arguments.
template <typename InnerAction>
inline internal::WithArgsAction<InnerAction>
WithoutArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction>(action);
}

// WithArg<k>(an_action) creates an action that passes the k-th
// (0-based) argument of the mock function to an_action and performs
// it.  It adapts an action accepting one argument to one that accepts
// multiple arguments.  For convenience, we also provide
// WithArgs<k>(an_action) (defined below) as a synonym.
template <int k, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k>
WithArg(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k>(action);
}

// The ACTION*() macros trigger warning C4100 (unreferenced formal
// parameter) in MSVC with -W4.  Unfortunately they cannot be fixed in
// the macro definition, as the warnings are generated when the macro
// is expanded and macro expansion cannot contain #pragma.  Therefore
// we suppress them here.
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
#endif

// Action ReturnArg<k>() returns the k-th argument of the mock function.
ACTION_TEMPLATE(ReturnArg,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_0_VALUE_PARAMS()) {
  return ::testing::get<k>(args);
}

// Action SaveArg<k>(pointer) saves the k-th (0-based) argument of the
// mock function to *pointer.
ACTION_TEMPLATE(SaveArg,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_1_VALUE_PARAMS(pointer)) {
  *pointer = ::testing::get<k>(args);
}

// Action SaveArgPointee<k>(pointer) saves the value pointed to
// by the k-th (0-based) argument of the mock function to *pointer.
ACTION_TEMPLATE(SaveArgPointee,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_1_VALUE_PARAMS(pointer)) {
  *pointer = *::testing::get<k>(args);
}

// Action SetArgReferee<k>(value) assigns 'value' to the variable
// referenced by the k-th (0-based) argument of the mock function.
ACTION_TEMPLATE(SetArgReferee,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_1_VALUE_PARAMS(value)) {
  typedef typename ::testing::tuple_element<k, args_type>::type argk_type;
  // Ensures that argument #k is a reference.  If you get a compiler
  // error on the next line, you are using SetArgReferee<k>(value) in
  // a mock function whose k-th (0-based) argument is not a reference.
  GTEST_COMPILE_ASSERT_(internal::is_reference<argk_type>::value,
                        SetArgReferee_must_be_used_with_a_reference_argument);
  ::testing::get<k>(args) = value;
}

// Action SetArrayArgument<k>(first, last) copies the elements in
// source range [first, last) to the array pointed to by the k-th
// (0-based) argument, which can be either a pointer or an
// iterator. The action does not take ownership of the elements in the
// source range.
ACTION_TEMPLATE(SetArrayArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_2_VALUE_PARAMS(first, last)) {
  // Visual Studio deprecates ::std::copy, so we use our own copy in that case.
#ifdef _MSC_VER
  internal::CopyElements(first, last, ::testing::get<k>(args));
#else
  ::std::copy(first, last, ::testing::get<k>(args));
#endif
}

// Action DeleteArg<k>() deletes the k-th (0-based) argument of the mock
// function.
ACTION_TEMPLATE(DeleteArg,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_0_VALUE_PARAMS()) {
  delete ::testing::get<k>(args);
}

// This action returns the value pointed to by 'pointer'.
ACTION_P(ReturnPointee, pointer) { return *pointer; }

// Action Throw(exception) can be used in a mock function of any type
// to throw the given exception.  Any copyable value can be thrown.
#if GTEST_HAS_EXCEPTIONS

// Suppresses the 'unreachable code' warning that VC generates in opt modes.
# ifdef _MSC_VER
#  pragma warning(push)          // Saves the current warning state.
#  pragma warning(disable:4702)  // Temporarily disables warning 4702.
# endif
ACTION_P(Throw, exception) { throw exception; }
# ifdef _MSC_VER
#  pragma warning(pop)           // Restores the warning state.
# endif

#endif  // GTEST_HAS_EXCEPTIONS

#ifdef _MSC_VER
# pragma warning(pop)
#endif

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_MORE_ACTIONS_H_
// Copyright 2013, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: marcus.boerger@google.com (Marcus Boerger)

// Google Mock - a framework for writing C++ mock classes.
//
// This file implements some matchers that depend on gmock-generated-matchers.h.
//
// Note that tests are implemented in gmock-matchers_test.cc rather than
// gmock-more-matchers-test.cc.

// GOOGLETEST_CM0002 DO NOT DELETE

#ifndef GMOCK_GMOCK_MORE_MATCHERS_H_
#define GMOCK_GMOCK_MORE_MATCHERS_H_


namespace testing {

// Silence C4100 (unreferenced formal
// parameter) for MSVC
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
#if (_MSC_VER == 1900)
// and silence C4800 (C4800: 'int *const ': forcing value
// to bool 'true' or 'false') for MSVC 14
# pragma warning(disable:4800)
  #endif
#endif

// Defines a matcher that matches an empty container. The container must
// support both size() and empty(), which all STL-like containers provide.
MATCHER(IsEmpty, negation ? "isn't empty" : "is empty") {
  if (arg.empty()) {
    return true;
  }
  *result_listener << "whose size is " << arg.size();
  return false;
}

// Define a matcher that matches a value that evaluates in boolean
// context to true.  Useful for types that define "explicit operator
// bool" operators and so can't be compared for equality with true
// and false.
MATCHER(IsTrue, negation ? "is false" : "is true") {
  return static_cast<bool>(arg);
}

// Define a matcher that matches a value that evaluates in boolean
// context to false.  Useful for types that define "explicit operator
// bool" operators and so can't be compared for equality with true
// and false.
MATCHER(IsFalse, negation ? "is true" : "is false") {
  return !static_cast<bool>(arg);
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif


}  // namespace testing

#endif  // GMOCK_GMOCK_MORE_MATCHERS_H_

namespace testing {

// Declares Google Mock flags that we want a user to use programmatically.
GMOCK_DECLARE_bool_(catch_leaked_mocks);
GMOCK_DECLARE_string_(verbose);
GMOCK_DECLARE_int32_(default_mock_behavior);

// Initializes Google Mock.  This must be called before running the
// tests.  In particular, it parses the command line for the flags
// that Google Mock recognizes.  Whenever a Google Mock flag is seen,
// it is removed from argv, and *argc is decremented.
//
// No value is returned.  Instead, the Google Mock flag variables are
// updated.
//
// Since Google Test is needed for Google Mock to work, this function
// also initializes Google Test and parses its flags, if that hasn't
// been done.
GTEST_API_ void InitGoogleMock(int* argc, char** argv);

// This overloaded version can be used in Windows programs compiled in
// UNICODE mode.
GTEST_API_ void InitGoogleMock(int* argc, wchar_t** argv);

}  // namespace testing

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_H_
