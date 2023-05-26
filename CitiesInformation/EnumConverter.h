#pragma once
#include <type_traits>

// Use unary operator+ to cast strongly typed enum to the underlying type for switch/case comparison
template<typename E>
constexpr typename std::underlying_type<E>::type operator+(E e)
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}
