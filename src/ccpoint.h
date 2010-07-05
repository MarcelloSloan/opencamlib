/*  $Id$
 * 
 *  Copyright 2010 Anders Wallin (anders.e.e.wallin "at" gmail.com)
 *  
 *  This file is part of OpenCAMlib.
 *
 *  OpenCAMlib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  OpenCAMlib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with OpenCAMlib.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CCPOINT_H
#define CCPOINT_H

#include <string>
#include <iostream>
#include "point.h"

namespace ocl
{


//class Triangle; // fwd declaration

/// type of cc-point
enum CCType {NONE, VERTEX, 
             EDGE, EDGE_HORIZ_CYL, EDGE_HORIZ_TOR, 
             EDGE_POS, EDGE_NEG,  
             FACET, FACET_TIP, FACET_CYL, 
             ERROR};

///
/// \brief Cutter-Contact (CC) point. A Point wiht a CCType.
///
/// Cutter-Contact (CC) Point.
/// A Point which also contains the type of cutter-contact.
class CCPoint : public Point {
    public:
        /// create a CCPoint at (0,0,0)
        CCPoint();
        /// create CCPoint at (x,y,z)
        CCPoint(double x,double y,double z);
        
        /// create a CCPoint at Point p
        CCPoint(const Point& p); 
        virtual ~CCPoint(){};
        
        /// specifies the type of the Cutter Contact point. 
        CCType type;
        /// assign coordinates of Point to this CCPoint. sets type=NONE
        CCPoint &operator=(const Point &p);
        /// string repr
        std::string str() const;
        /// string repr
        friend std::ostream& operator<<(std::ostream &stream, const CCPoint &p);
        
};



} // end namespace
#endif
// end file point.h