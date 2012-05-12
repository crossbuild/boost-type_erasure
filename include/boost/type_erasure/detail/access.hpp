// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_DETAIL_ACCESS_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_ACCESS_HPP_INCLUDED

#include <boost/type_erasure/detail/storage.hpp>
#include <boost/type_erasure/detail/any_base.hpp>

namespace boost {
namespace type_erasure {

template<class Concept, class T>
class any;

namespace detail {

struct access
{
    template<class Derived>
    static const typename Derived::table_type&
    table(const ::boost::type_erasure::any_base<Derived>& arg)
    {
        return static_cast<const Derived&>(arg).table;
    }
    template<class Derived>
    static ::boost::type_erasure::detail::storage&
    data(::boost::type_erasure::any_base<Derived>& arg)
    {
        return static_cast<Derived&>(arg).data;
    }
    template<class Concept, class T>
    static const ::boost::type_erasure::detail::storage&
    data(::boost::type_erasure::any_base< ::boost::type_erasure::any<Concept, const T&> >& arg)
    {
        return static_cast< ::boost::type_erasure::any<Concept, const T&>&>(arg).data;
    }
    template<class Derived>
    static const ::boost::type_erasure::detail::storage&
    data(const ::boost::type_erasure::any_base<Derived>& arg)
    {
        return static_cast<const Derived&>(arg).data;
    }
};

}
}
}

#endif
