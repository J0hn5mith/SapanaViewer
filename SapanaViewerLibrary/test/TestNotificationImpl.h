//
//  TestNotificationImpl.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 08.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestNotificationImpl_H_
#define SapanaViewerLibrary_TestNotificationImpl_H_

// Base class includes
#include "INotification.h"
// External includes

// Project includes

namespace spvt{
  class TestNotificationImpl : public spvu::INotification
  {    
    public:    
          
        explicit TestNotificationImpl();    
        virtual ~TestNotificationImpl();    
    
    /**
     * @Implementation
     */
    virtual int getID() const{return id_;}
    private:
    const int id_;
                  
  };
}
#endif /* defined(SapanaViewerLibrary_TestNotificationImpl_H_ */
