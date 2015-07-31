#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace cs3358Spring2014Assign06P1
{
    cnPtrQueue::cnPtrQueue() : numItems(0) {}

    bool cnPtrQueue::empty() const
    {
    	return outStack.empty() && inStack.empty();
    }

    cnPtrQueue::size_type cnPtrQueue::size() const
    {
    	return numItems;
    }

    CNode* cnPtrQueue::front()
    {
    	assert( !inStack.empty() || !outStack.empty() );

    	if( outStack.empty() )
    	{
    		while( !inStack.empty() )
    		{
    			outStack.push( inStack.top() );
    			inStack.pop();
    		}
    	}

    	return outStack.top();
    }

	void cnPtrQueue::push(CNode* cnPtr)
	{
		numItems++;
		inStack.push(cnPtr);
	}

	void cnPtrQueue::pop()
	{
		assert( !inStack.empty() || !outStack.empty());

		if( outStack.empty() )
		{
			while( !inStack.empty() )
			{
				outStack.push( inStack.top() );
				inStack.pop();
			}
		}
		outStack.pop();
	}
}
