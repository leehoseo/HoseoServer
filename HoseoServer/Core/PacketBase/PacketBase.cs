using System;

namespace PacketBase
{
    public class Packet
    {
        [DllExport]
        public virtual int TestFunc(int value)
        {
            return value * 2;
        }
    }
}
