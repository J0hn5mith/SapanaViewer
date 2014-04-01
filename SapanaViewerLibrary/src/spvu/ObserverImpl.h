//
//  ObserverImpl.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_ObserverImpl_H_
#define SapanaViewerLibrary_ObserverImpl_H_

// Base class includes

// External includes
#include <memory>
#include <list>

// Project includes
#include "IObservable.h"
#include "INotification.h"

namespace spvu{
  /**
   * TODO: Dokumentation
   * (Analogue to ObserverableImpl)
   */
  class ObserverImpl : public IObserver
  {
  public:
    explicit ObserverImpl();
    ~ObserverImpl();
    
    /**
     * @ Implementation
     */
    virtual void notify(std::shared_ptr<const INotification > ) const;
    
    /**
     * @ Implementation
     */
    virtual void update() const;
    
    /**
     * Returns the list with all notifications on the observers notification list.
     */
    std::shared_ptr< std::list< std::shared_ptr<const INotification > > >  getNotifications();
    
    /**
     * Returns true if the observer has an notification in its
     * notification list.
     */
    bool hasNotification();
    
  private:
    
    std::shared_ptr< std::list< std::shared_ptr<const INotification > > > notifications_;
  };
}
#endif /* defined(SapanaViewerLibrary_ObserverImpl_H_ */
