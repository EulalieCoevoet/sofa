/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 3      *
*                (c) 2006-2008 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU General Public License as published by the Free  *
* Software Foundation; either version 2 of the License, or (at your option)   *
* any later version.                                                          *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for    *
* more details.                                                               *
*                                                                             *
* You should have received a copy of the GNU General Public License along     *
* with this program; if not, write to the Free Software Foundation, Inc., 51  *
* Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.                   *
*******************************************************************************
*                            SOFA :: Applications                             *
*                                                                             *
* Authors: M. Adam, J. Allard, B. Andre, P-J. Bensoussan, S. Cotin, C. Duriez,*
* H. Delingette, F. Falipou, F. Faure, S. Fonteneau, L. Heigeas, C. Mendoza,  *
* M. Nesme, P. Neumann, J-P. de la Plata Alcade, F. Poyer and F. Roy          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
//
// C++ Interface: bfs_adapter
//
// Description:
//
//
// Author: The SOFA team </www.sofa-framework.org>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef bfs_adapter_h
#define bfs_adapter_h

#include <boost/graph/breadth_first_search.hpp>
#include "BglNode.h"
#include "BglScene.h"
#include <sofa/simulation/common/Visitor.h>

namespace sofa
{
namespace simulation
{
namespace bgl
{

/**
Adapt a sofa visitor to breadth-first search in a bgl mapping scene graph.

	@author The SOFA team </www.sofa-framework.org>
*/
class bfs_adapter : public boost::bfs_visitor<>
{
public:
    sofa::simulation::Visitor* visitor;

    typedef BglScene::Hgraph Graph; ///< BGL graph to traverse
    BglScene::H_vertex_node_map& systemMap;      ///< access the System*

    bfs_adapter( sofa::simulation::Visitor* v, BglScene::H_vertex_node_map& s );

    ~bfs_adapter();

    void discover_vertex( Graph::vertex_descriptor u, const Graph &) const;

    void finish_vertex(Graph::vertex_descriptor u, const Graph &) const;
};

}
}
}

#endif
