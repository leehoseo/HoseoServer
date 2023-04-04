#include "PacketBase.h"

bool CPacketBase::CheckVerify() const
{
    const uint8_t* buffer = m_Builder.GetBufferPointer();

    // 검사할 데이터의 크기
    const size_t bufferSize = sizeof(buffer);

    // Verifier 클래스를 사용하여 검사 객체를 생성합니다.
    flatbuffers::Verifier verifier(buffer, bufferSize);

    return Verify(verifier);
}
