//
//  ObservableImpl.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "ObservableImpl.h"

// External includes

// Project includes

using namespace spvu;
                                                                                
ObservableImpl::ObservableImpl()
: observers_( std::make_shared<std::unordered_set< std::shared_ptr< spvu::IObserver > > >() )
{                                                                               
  
}                                                                               
                                                                                
ObservableImpl::~ObservableImpl()
{
  
}

void ObservableImpl::notifyObservers(std::shared_ptr< const spvu::INotification > notification) const
{
  for (auto observer : *observers_)
  {
    observer->notify(notification);
  }
}

std::shared_ptr< std::unordered_set< std::shared_ptr< spvu::IObserver > > > ObservableImpl::getObservers()
{
  return observers_;
}

void ObservableImpl::registerObserver(const std::shared_ptr< spvu::IObserver > observer) const
{
  observers_->insert(observer);
}

void ObservableImpl::unregisterObserver(const std::shared_ptr< spvu::IObserver > observer) const
{
  observers_->erase(observer);
}