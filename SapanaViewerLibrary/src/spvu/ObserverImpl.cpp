//
//  ObserverImpl.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "ObserverImpl.h"

// External includes

// Project includes

// Debug includes

using namespace spvu;
                                                                                
ObserverImpl::ObserverImpl()
:notifications_(std::make_shared< std::list< std::shared_ptr<const INotification >  >>())
{

}                                                                               
                                                                                
ObserverImpl::~ObserverImpl()                                      
{                                                                               
 // TODO: Does it need any special code here? 
}

void ObserverImpl::notify(std::shared_ptr<const INotification > status) const
{
  notifications_->push_front(status);
}

bool ObserverImpl::hasNotification()
{
  if (!notifications_->empty()) {
    return true;
  }
  return false;
}

std::shared_ptr< std::list< std::shared_ptr<const INotification > > >  ObserverImpl::getNotifications()
{
  return notifications_;
}

void ObserverImpl::update() const
{
  notifications_->clear();
}