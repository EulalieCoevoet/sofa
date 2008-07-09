/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 3      *
*                (c) 2006-2008 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Modules                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#ifndef SOFA_COMPONENT_CONTROLLER_NULLFORCEFEEDBACK_H
#define SOFA_COMPONENT_CONTROLLER_NULLFORCEFEEDBACK_H

#include <sofa/component/controller/ForceFeedback.h>
#include <sofa/component/controller/OmniDriver.h>


namespace sofa
{

namespace component
{

namespace controller
{
using namespace std;

/**
* Omni driver force field
*/
class NullForceFeedback : public sofa::component::controller::ForceFeedback
{

public:
    void init();

    virtual void computeForce(double x, double y, double z, double u, double v, double w, double q, double& fx, double& fy, double& fz);
};

} // namespace controller

} // namespace component

} // namespace sofa

#endif
