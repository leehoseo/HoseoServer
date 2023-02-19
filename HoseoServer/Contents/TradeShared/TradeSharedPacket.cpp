#include "TradeSharedPacket.h"
#include "Person_generated.h"

namespace TradePacket
{
	uint8_t* MakePersonBuffer(std::string name, int age)
	{
		flatbuffers::FlatBufferBuilder builder;
		auto buildedName = builder.CreateString(name);
		
		builder.Finish(CreatePerson(builder, buildedName, age));
		
		return builder.GetBufferPointer();
	}

}