//
//  MultipleInheritableEnableSharedFromThis.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 17.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.

//

#ifndef SapanaViewerLibrary_MultipleInheritableEnableSharedFromThis_H_
#define SapanaViewerLibrary_MultipleInheritableEnableSharedFromThis_H_

/* Trick to allow multiple inheritance of objects
 * inheriting shared_from_this.
 * cf. http://stackoverflow.com/a/12793989/587407
 */

// Base class includes

// External includes
#include <memory>

// Project includes

namespace spvu{
    
class MultipleInheritableEnableSharedFromThis: public std::enable_shared_from_this<MultipleInheritableEnableSharedFromThis>
{
public:
    virtual ~MultipleInheritableEnableSharedFromThis()
    {}
};

template <class T>
class inheritable_enable_shared_from_this : virtual public MultipleInheritableEnableSharedFromThis
{
public:
    std::shared_ptr<T> shared_from_this() {
        return std::dynamic_pointer_cast<T>(MultipleInheritableEnableSharedFromThis::shared_from_this());
    }
    /* Utility method to easily downcast.
     * Useful when a child doesn't inherit directly from enable_shared_from_this
     * but wants to use the feature.
     */
    template <class Down>
    std::shared_ptr<Down> downcasted_shared_from_this() {
        return std::dynamic_pointer_cast<Down>(MultipleInheritableEnableSharedFromThis::shared_from_this());
    }
};
}
#endif /* defined(SapanaViewerLibrary_MultipleInheritableEnableSharedFromThis_H_ */
