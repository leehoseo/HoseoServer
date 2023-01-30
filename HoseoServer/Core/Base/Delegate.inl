#define DELEGATE_NANE(X) CDelegate_

namespace Delegate
{

#define CDELEGATE DELEGATE_NANE(X)##DELEGATE_ARGS_COUNT

	class CDELEGATE
	{
	public:
		DELEGATE_TEMPLATE_ARGS
		static CDELEGATE Clone(DELEGATE_ARGS)
		{
			CDELEGATE delegate;

			return delegate;
		}
	};

#undef CDELEGATE
}