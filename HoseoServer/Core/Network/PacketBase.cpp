#include "PacketBase.h"

bool CPacketBase::CheckVerify() const
{
    const uint8_t* buffer = m_Builder.GetBufferPointer();

    // �˻��� �������� ũ��
    const size_t bufferSize = sizeof(buffer);

    // Verifier Ŭ������ ����Ͽ� �˻� ��ü�� �����մϴ�.
    flatbuffers::Verifier verifier(buffer, bufferSize);

    return Verify(verifier);
}
