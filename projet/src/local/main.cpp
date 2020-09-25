
/** TP 5ETI IMI- CPE Lyon - 2015-2016 */



#include "lib/common/error_handling.hpp"

#include "discrete/bresenham.hpp"
#include "discrete/line_discrete.hpp"
#include "discrete/line_interpolation_parameter.hpp"
#include "image/image.hpp"
#include "image/drawer.hpp"
#include "discrete/triangle_scanline.hpp"
#include "image/image_zbuffer.hpp"
#include "lib/mesh/mesh.hpp"
#include "lib/mesh/mesh_io.hpp"
#include "render_engine/render_engine.hpp"
#include "lib/3d/mat4.hpp"
#include "lib/3d/mat3.hpp"
#include "image/texture.hpp"

#include <iostream>
#include <fstream>
#include <cmath>



using namespace cpe;

int main(int argc,char *argv[])
{

    std::cout<<"***********************"<<std::endl;
    std::cout<<"run "<<argv[0]<<" with "<<argc-1<<" parameters ... \n"<<std::endl;


    try
    {
        int const Nx = 40;
        int const Ny = 25;

        image im(Nx,Ny);
        im.fill({1.0f,1.0f,1.0f});

        // Change two pixels 
        im(20,10) = color(1.0f,1.0f,0.0f);
        im(21,10) = color(1.0f,0.0f,0.0f);

        // create a line of pixels
        for(int k=0;k<20;++k)
            im(10+k,5) = color(k/20.0f,0.0f,1.0f-k/20.0f);

        // create a column of pixels
        for(int k=0;k<15;++k)
            im(5,5+k) = color(k/15.0f,k/15.0f,k/15.0f);


        im.save("mon_image.ppm");


    }
    catch(cpe::exception_cpe const& e)
    {


        std::cout<<"**********************************"<<std::endl;
        std::cout<<"**********************************"<<std::endl;
        std::cout<<"Exception found"<<std::endl;
        std::cout<<e.info()<<std::endl;
        std::cout<<"\nSaving backtrace in file backtrace_log.txt"<<std::endl;
        std::cout<<"**********************************"<<std::endl;
        std::cout<<"**********************************"<<std::endl;


        std::ofstream back_file("backtrace_log.txt");
        back_file<<e.info()<<std::endl;
        back_file<<e.info_backtrace();
        back_file.close();

        exit(1);
    }


    std::cout<<"Exit Main"<<std::endl;

    return 0;
}
