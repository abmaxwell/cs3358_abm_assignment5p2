#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA17_A5P2
{
    cnPtrQueue::cnPtrQueue() : numItems(0){}

    bool cnPtrQueue::empty() const{
        /// If both stacks are empty then cnPtrQueue must be empty.
        return(inStack.empty() && outStack.empty());
    }
    cnPtrQueue::size_type cnPtrQueue::size() const{
        /// Only indicator of size.
        return numItems;
    }

    CNode* cnPtrQueue::front(){
        /// Check to make sure we're not accessing space that has nothing in it.
        assert(!inStack.empty() || !outStack.empty());

        /// Load inStack into outStack if outStack is empty.
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                /// Return pointer to last element in stack.
                inStack.pop();
            }
        }
        return outStack.top();
    }
    void cnPtrQueue::push(CNode* cnPtr){
        /// Add new item to inStack via push.
        inStack.push(cnPtr);
        ++numItems;
    }
    void cnPtrQueue::pop(){
        /// Check to make sure we're not accessing space that has nothing in it.
        assert(!inStack.empty() || !outStack.empty());

        /// Push first items in inStack onto outStack only if inStack is NOT
        /// empty but outStack is empty.
        if (outStack.empty() ) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                /// Pop item out of inStack.
                inStack.pop();
            }
        }
        /// Pop items out of outStack.
        outStack.pop();
       -- numItems;
    }
}
