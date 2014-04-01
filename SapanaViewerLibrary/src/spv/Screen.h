//
//  Screen.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 03.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_Screen_H_
#define SapanaViewerLibrary_Screen_H_

// Base class includes

// External includes

// Project includes

/**
 * A abstract representation of a screen of a app.
 * It holds the data that are used to draw such a screen and prpovides a
 * interface that can be used by the app.
 * Further, a screen is abel to render a scene.
 */
namespace spv{
  class Screen    
  {    
    public:    
          
        explicit Screen();    
        virtual ~Screen();
    
    private:    
                  
  };
}
#endif /* defined(SapanaViewerLibrary_Screen_H_ */
