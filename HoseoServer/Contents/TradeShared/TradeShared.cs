using System;
using PacketBase;

namespace TradeShared
{
    public class Trade : Packet
    {
        public override int TestFunc(int value)
        {
            int num = value + 10;
            return base.TestFunc(num);
        }
    }
}
