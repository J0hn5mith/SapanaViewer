/*
 * CubeData.h
 *
 * CONTAINS NO MOSYNC CODE!!!
 *  Created on: Nov 29, 2013
 *      Author: janmeier
 */

#ifndef CUBEDATA_H_
#define CUBEDATA_H_

#include "ModelData.h"

namespace spvt
{
class CubeData: public spvs::ModelData {
public:
      explicit CubeData();
    
      virtual ~CubeData();

private:

};
        
        
class CoordinateSystem : public spvs::ModelData
{
public:
        explicit CoordinateSystem();
        virtual ~CoordinateSystem();
};
    
class NormalArrow : public spvs::ModelData
{
public:
    explicit NormalArrow();
    virtual ~NormalArrow();
};
    
}





#endif /* CUBEDATA_H_ */
