using System;

namespace PSXDiscompile
{
    public static class Cutter
    {
        public static int Cut(int value,int offset,int length,bool unsigned)
        {
            if (offset < 0)
                throw new ArgumentOutOfRangeException("offset");
            if (length <= 0)
                throw new ArgumentOutOfRangeException("length");
            if (offset + length > 32)
                throw new ArgumentOutOfRangeException();
            value <<= offset;
            value >>= 32 - length;
            if (unsigned)
            {
                value &= (1 << length) - 1;
            }
            return value;
        }
    }
}
