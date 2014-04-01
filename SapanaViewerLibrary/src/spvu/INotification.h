//
//  INotification.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_INotification_H_
#define SapanaViewerLibrary_INotification_H_

// Base class includes

// External includes

// Project includes

namespace spvu{
class INotification
{    
public:    

    /**
     * Returns the ID of the notification.
     */
    virtual int getID() const = 0;
    
    /**
     * Returns the content of the notification. Unsingend int as type is
     * used, because mostly node ids will be sent around.
     * is 0 by default.
     */
    virtual unsigned long getContent() const  = 0;
  
  

};
    
/**
 * A simple implementatoin of the INotification interface.
 */
class NotificationImpl : public INotification
{
public:
    
    /**
     * Creates a new notification with default message 0;
     * @param ID id of the message
     */
    explicit NotificationImpl(int ID):NotificationImpl(ID, 0){;}
    
    /**
     * Creates a new notification with a custom message
     */
    explicit NotificationImpl(int ID, unsigned int message):id_(ID), message_(message){;}
    
    /**
     * Deletes the notification
     */
    virtual ~NotificationImpl(){;}

    /**
     * @Implementation
     */
    virtual int getID() const {return id_;}
    
    /**
     * @Implementation
     */
    virtual unsigned long getContent() const {return message_;}

private:
    /**
     * Id of the message
     */
    const int id_;
    
    /**
     * Message of the notification.
     */
    const unsigned long message_;
    
};
}
#endif /* defined(SapanaViewerLibrary_INotification_H_ */
