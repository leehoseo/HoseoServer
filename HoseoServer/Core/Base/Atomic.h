#pragma once

template<typename T>
class CAtomic
{
    template<typename T, typename Func>
    bool TryExchangeWith(T value, T comparand, const Func& func)
    {
        //CScopedTryExchange scopedTryExchange(*this, value, comparand);
        //if (scopedTryExchange)
        {
            func();
            return true;
        }
        return false;
    }
};

