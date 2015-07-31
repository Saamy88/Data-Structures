#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace cs3358Spring2014Assign06P1
{
	// to be implemented (part of assignment)
	cnPtrQueue::size_type cnPtrQueue:: size() const
	{
		return numItems;
	}

	void cnPtrQueue::push(CNode* cnPtr)
	{
		numItems++;
		CNode *newNode = new CNode;
		newNode = cnPtr;
		cnPtr = newNode;
	}

	void cnPtrQueue::pop()
	{
		assert(!inStack.empty() ||!outStack.empty());
		if(outStack.empty())
		{
			while(!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		outStack.pop();
	}

	CNode* cnPtrQueue::front()
	{
		assert(!inStack.empty() || !outStack.empty());

		if(outStack.empty())
		{
			while(!inStack.empty())
			{
				outStack.push( inStack.top());
				inStack.pop();
			}
		}
		return outStack.top();
	}

    bool cnPtrQueue::empty() const
    {
    	return outStack.empty() && inStack.empty();
    }
}
