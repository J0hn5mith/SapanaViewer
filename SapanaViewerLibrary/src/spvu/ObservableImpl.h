//
//  ObservableImpl.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_ObservableImpl_H_
#define SapanaViewerLibrary_ObservableImpl_H_

// Base class includes

// External includes
#include <memory>
#include <map>

// Project includes
#include "IObservable.h"

namespace spvu{
  /**
   * TODO: Documentation
   * (Class that implements the logic behind IObserver interface.
   * This implementation is used by classes that implement that 
   * interface as well, but won't implement the logic behin interface.)
   */
  class ObservableImpl : public IObservable
{
public:
  
  explicit ObservableImpl();
  
  ~ObservableImpl();
  
  /**
   * @Override
   */
  virtual void notifyObservers(std::shared_ptr< const spvu::INotification >)const ;
    
  /**
   * Returns a the list of registerd observers.
   */
  std::shared_ptr< std::unordered_set< std::shared_ptr< spvu::IObserver > > > getObservers();
  
  /**
   * @Override
   */
  virtual void registerObserver(std::shared_ptr< spvu::IObserver > observer) const;
    
  /**
   * @Override
   */
  virtual void unregisterObserver(std::shared_ptr< spvu::IObserver > observer)const ;
private:
  
  /**
   * Map holding the observers that observe this observable.
   */
  std::shared_ptr< std::unordered_set< std::shared_ptr< spvu::IObserver > > > observers_;
                  
  };
}
#endif /* defined(SapanaViewerLibrary_ObservableImpl_H_ */
