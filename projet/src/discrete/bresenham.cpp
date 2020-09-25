/*
**    TP CPE Lyon
**    Copyright (C) 2015 Damien Rohmer
**
**    This program is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**   This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "lib/common/error_handling.hpp"

#include "discrete/line_discrete.hpp"
#include "bresenham_octant.hpp"

namespace cpe
{



/** Compute Bresenham algorithm in the first octant */
void bresenham_first_octant(ivec2 const& p0,ivec2 const& p1,line_discrete& line,int const octant)
{
    /*************************************
    // TO DO
    /*************************************
    // Completez l'algorithme de Bresenham
    //
    // erreur <-  -dx
    // m      <- 2 dy
    // Pour tous les pixels du segment
    //   Ajouter point courant (x,y) au segment
    //
    //   Ajouter m a l'erreur
    //   Si erreur >= 0
    //      Incrementer y
    //      Enlever 2 dx a l'erreur
    //
    */

}

void bresenham(ivec2 const& p0,ivec2 const& p1,line_discrete& line)
{
    bresenham_first_octant(p0,p1,line,0);

    // Sanity check ensuring the discrete line is correctly computed
    ASSERT_CPE(line.size()>0,"Incorrect size of line in Bresenham ( line.size()="+std::to_string(line.size())+" )");
    ASSERT_CPE(line[0]==p0,"Incorrect first point in Bresenham ( line[0]=("+to_string(line[0])+") ; p0=("+to_string(p0)+") )");
    ASSERT_CPE(line[line.size()-1]==p1,"Incorrect last point in Bresenham ( line[end]=("+to_string(line[line.size()-1])+") ; p1=("+to_string(p1)+") )");
}




}
