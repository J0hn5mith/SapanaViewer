//
//  IObserver.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_IObserver_H_
#define SapanaViewerLibrary_IObserver_H_

// Base class includes

// External includes
#include <memory>
#include <list>

// Project includes
#include "INotification.h"

namespace spvu{
  /**
   * A observer that observes a IObservable.
   * To avoid inheritance, the implementation of the observer is realised
   * in ObservableImpl. This has the advantage, that a observing class
   * only needs to implement this interface and the implementation code
   * can be used by composition.
   */
  class IObserver    
  {    
    public:
    
    /**
     * The observer recieves a notification and puts it into its
     * notificaton list.
     * Member function is const so that it can be invoked by const pointer.
     * @param The notification.
     */
    virtual void notify(std::shared_ptr< const spvu::INotification >) const = 0;
    
    /**
     * Processes the the notifications in the notification list
     * Also ereases the empties the notification list.
     * Member function is const so that it can be invoked by const pointer.
     */
    virtual void update() const =0;
    
  };
}
#endif /* defined(SapanaViewerLibrary_IObserver_H_ */
