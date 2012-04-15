/*
 * Proland: a procedural landscape rendering library.
 * Copyright (c) 2008-2011 INRIA
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#ifndef _PROLAND_TESSELATOR_H_
#define _PROLAND_TESSELATOR_H_

#include "ork/math/vec2.h"
#include "ork/render/Mesh.h"

using namespace ork;

namespace proland
{

/**
 * A tesselator to triangulate arbitrary 2D surfaces defined by a set of
 * contours. Nested contours define holes.
 * @ingroup producer
 * @author Antoine Begault
 */
PROLAND_API class Tesselator : public Object
{
public:
    /**
     * Creates a new tesselator.
     */
    Tesselator();

    /**
     * Destroys this tesselator.
     */
    virtual ~Tesselator();

    /**
     * Starts a new triangulation.
     *
     * @param mesh the mesh where the triangles generated by triangulation
     * are added. This mesh must be in AttributeBuffer#TRIANGLES mode (see
     * Mesh#setMode).
     */
    void beginPolygon(ptr< Mesh<vec2f, unsigned int> > mesh);

    /**
     * Starts a new contour.
     */
    void beginContour();

    /**
     * Defines a new vertex in the current contour.
     */
    void newVertex(float x, float y);

    /**
     * Ends the current contour.
     */
    void endContour();

    /**
     * Ends the current triangulation.
     */
    void endPolygon();

private:
    ptr< Mesh<vec2f, unsigned int> > mesh;

    void *tess;
};

}

#endif
