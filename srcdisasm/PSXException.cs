using System;
using System.Runtime.Serialization;

namespace PSXDiscompile
{
    [Serializable]
    public class PSXException : Exception
    {
        public PSXException()
        {
        }

        public PSXException(string message) : base(message)
        {
        }

        public PSXException(string message,Exception innerException) : base(message,innerException)
        {
        }

        protected PSXException(SerializationInfo info,StreamingContext context) : base(info,context)
        {
        }
    }
}
