#pragma once

#include <iostream>

namespace Onyx
{
    template <typename A, typename B, typename C, typename D>
    class Quartet
    {
    public:
        Quartet() {}

        Quartet(A first, B second, C third, D fourth) : first(first), second(second), third(third), fourth(fourth) {}

        A first;
        B second;
        C third;
        D fourth;
    };
}
