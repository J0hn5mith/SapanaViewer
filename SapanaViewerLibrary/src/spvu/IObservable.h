//
//  IObservable.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_IObservable_H_
#define SapanaViewerLibrary_IObservable_H_

// Base class includes

// External includes
#include <memory>
#include <unordered_set>

// Project includes
#include "IObserver.h"

namespace spvu{
  /**
   *
   */
  class IObservable    
  {    
    public:
    
    /**
     * Informs associated observers about the cange in the observable.
     * @param notification notification that is sent to the observers.
     */
    virtual void notifyObservers(std::shared_ptr<const INotification > notification) const = 0;
    
    /**
     * Registers a new observer to listen to the observable.
     * Is const because Observers that only have a const reference to the Observable
     * can register them selfe. 
     * @param observer Observer that is registered
     */
    virtual void registerObserver(std::shared_ptr< spvu::IObserver >) const = 0;
    
    /**
     * Removes a observer observable. This observer is no longer informed about
     * changes of the observable. 
     * @param observer that is unregistered
     */
    virtual void unregisterObserver(std::shared_ptr< spvu::IObserver >) const = 0;
                  
  };
}
#endif /* defined(SapanaViewerLibrary_IObservable_H_ */
