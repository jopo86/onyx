#pragma once

#include <iostream>

namespace Onyx
{
    template <typename A, typename B, typename C>
    class Triple
    {
    public:
        Triple() {}

        Triple(A first, B second, C third) : first(first), second(second), third(third) {}

        A first;
        B second;
        C third;
    };
}
