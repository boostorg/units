// test.cpp
//
// Copyright (c) 2007-2008
// Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_UNITS_STRINGIZE_IMPL(x) #x
#define BOOST_UNITS_STRINGIZE(x) BOOST_UNITS_STRINGIZE_IMPL(x)

#define BOOST_UNITS_HEADER BOOST_UNITS_STRINGIZE(BOOST_UNITS_HEADER_NAME)

#include BOOST_UNITS_HEADER

int main() {}
