//
//  MatrixForGUI.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 25.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_MatrixForGUI_H_
#define SapanaViewerLibrary_MatrixForGUI_H_

// Base class includes

// External include
#include <vector>
#include <string>
// Project includes


class MatrixForGUI
{
public:    
      
    explicit MatrixForGUI(std::string label, unsigned long referenceID, std::vector < std::vector < float > > matrix);
    virtual ~MatrixForGUI();
    
    std::string getLabel() {return label_;}
    unsigned long getReferenceID() { return referenceID_ ;}
    std::vector < std::vector < float > > getMatrix() {return matrix_;}

private:
  std::string label_;
    unsigned long referenceID_;
  std::vector < std::vector < float > > matrix_;
  
};

#endif /* defined(SapanaViewerLibrary_MatrixForGUI_H_ */
