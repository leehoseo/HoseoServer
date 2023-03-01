#include <set>
#include <memory>
#pragma optimize (off,"")
class CClass
{
public:
	CClass(int id, int count) : m_Id(id), m_Count(count) {}

public:
	int m_Id;
	int m_Count;
};

typedef std::shared_ptr<CClass> CClassPtr;

struct Compare
{
	bool operator()(const CClassPtr& lhs, const CClassPtr& rhs) const
	{
		if (lhs->m_Count == rhs->m_Count)
		{
			return lhs->m_Id < rhs->m_Id;
		}

		return lhs->m_Count < rhs->m_Count;
	}
};

int main()
{
	std::set<CClassPtr, Compare> set;

	CClassPtr a(new CClass(10, 1));
	CClassPtr b(new CClass(20, 1));
	CClassPtr c(new CClass(30, 1));

	set.insert(a);
	set.insert(b);

	if (set.end() == set.find(c))
	{
		set.insert(c);
	}

	return 0;
}