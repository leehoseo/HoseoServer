#pragma once
#include "Component.h"

class CTaskComponent : public CComponent
{
	COMPONENT_FOUNDATION(CTaskComponent)

private:

};
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// \file AssetTask.h
///// \author excel96
///// \date 2015.11.5
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//#pragma once
//
//#include "Base/AsyncEvent.h"
//
//namespace Asset
//{
//    //------------------------------------------------------------------------------------------------------------------
//
//    // ���� ���� Ÿ��
//    enum ExeType
//    {
//        ET_GAME = 0x00000001, ///< ���� ����
//        ET_LOGIN = 0x00000002, ///< �α��� ����
//        ET_WORLD = 0x00000004, ///< ���� ����
//        ET_SOCIAL = 0x00000008, ///< �Ҽ� ����
//        ET_QUERY = 0x00000010, ///< ���� ����
//        ET_CENTER = 0x00000020, ///< ���� ����
//        ET_MATCH = 0x00000040, ///< ��ġ ����
//        ET_AUCTION = 0x00000080, ///< ���� ����
//        ET_TRACE = 0x00000100, ///< �α� ����
//        ET_FAM = 0x00000200, ///< �� ����
//        ET_DOCK = 0x00000400, ///< �� ����
//        ET_ASSET = 0x00010000, ///< �ּ� ������
//        ET_DUMMY = 0x00020000, ///< ���� Ŭ���̾�Ʈ
//        ET_SIMPLE = 0x00040000, ///< ���� Ŭ���̾�Ʈ
//        ET_ALL = 0xFFFFFFFF, ///< ��� 
//    };
//
//    //------------------------------------------------------------------------------------------------------------------
//
//    // Ư�� �ּ¸� �ε��ϱ⸦ ó���ϱ� ���� �ּ� �̸� ��
//    class CAssetNameSet
//    {
//    private:
//        stx::set<tstring, Text::LexLess> m_NameSet; ///< �ּ� ���
//
//
//    public:
//        /// \brief ������
//        CAssetNameSet();
//
//        /// \brief ������
//        CAssetNameSet(LPCTSTR text);
//        CAssetNameSet(const tstring& text);
//
//        /// \brief �Ҹ���
//        ~CAssetNameSet();
//
//
//    public:
//        /// \brief �߰�
//        void Add(LPCTSTR name);
//        void Add(const tstring& name);
//
//        /// \brief ����ֳ�?
//        bool IsEmpty() const;
//
//        /// \brief ���� ��ȯ
//        size_t GetCount() const;
//
//        /// \brief ���ε��� ����ΰ�?
//        bool IsMatch(LPCTSTR name) const;
//        bool IsMatch(const tstring& name) const;
//
//        /// \brief ���ڿ� ������ ��ȯ�Ѵ�.
//        tstring ToString() const;
//    };
//
//    //------------------------------------------------------------------------------------------------------------------
//
//    // ���ε� �߿� ���� ǥ�ø� ���� ������ �ݹ�
//    typedef Delegate::Delegate2<void, int, int> CAssetProgressCallback;
//
//    // ���ε� �Ϸ� �� ������ �ݹ�
//    typedef Delegate::Delegate1<void, const CAssetNameSet&> CAssetFinishCallback;
//
//    //------------------------------------------------------------------------------------------------------------------
//
//    /// \brief �ּ� �ε��� �½�ũ ��ü
//    class CTask :
//        public CAsyncEvent,
//        public CCountable<CTask>
//    {
//    public:
//        typedef std::function<void()> Callback;
//
//
//    private:
//        Callback m_Callback; ///< ȣ���� �Լ�
//
//        static CAtomic<int> s_PendingCount; ///< ���� ó������ ���� �½�ũ ��ü�� ��
//
//
//    public:
//        /// \brief ������
//        CTask(const Callback& callback);
//
//        /// \brief �Ҹ���
//        virtual ~CTask();
//
//
//    public:
//        /// \brief �̺�Ʈ�� ������ �����Ѵ�.
//        virtual void Execute(bool success, DWORD transferred, CAsyncEventSink* sink) override;
//
//
//    public:
//        /// \brief �½�ũ�� ����Ʈ�Ѵ�.
//        static void PostTask(CTask* task);
//
//        /// \brief ���� ó������ ���� �½�ũ�� ���� ��ȯ�Ѵ�.
//        static int GetPendingCount();
//    };
//
//    //------------------------------------------------------------------------------------------------------------------
//
//    void WaitAll();
//
//    /// \brief �־��� �Լ��ڸ� ����Ʈ
//    template <typename Functor>
//    inline void Post(const Functor& func)
//    {
//        CTask::PostTask(xnew(CTask, func));
//    }
//
//    /// \brief ȣ���ڰ� �ش� ���� �ִ� ���̶�� �־��� �Լ��ڸ� ����Ʈ
//    template <typename Functor>
//    inline void Post(LPCTSTR name, const Functor& func, ExeType exe, const CAssetNameSet& wanted, int flag)
//    {
//        if ((flag & exe) != 0)
//        {
//            if (wanted.IsMatch(name))
//            {
//                CTask::PostTask(xnew(CTask, func));
//            }
//        }
//    }
//
//    /// \brief ����Ʈ�� �½�ũ ��ü���� �Ϸ�Ǳ⸦ ��ٸ���.
//    inline void WaitAll()
//    {
//        while (0 < CTask::GetPendingCount())
//        {
//            Sleep(100);
//        }
//    }
//
//    /// \brief �ش� ���� �ִ� �ּ��� ���, �־��� �Լ��ڸ� ����
//    template <typename Functor>
//    inline void Exec(LPCTSTR name, const CAssetNameSet& wanted, const Functor& func)
//    {
//        if (wanted.IsMatch(name))
//        {
//            func();
//        }
//    }
//
//    //------------------------------------------------------------------------------------------------------------------
//}