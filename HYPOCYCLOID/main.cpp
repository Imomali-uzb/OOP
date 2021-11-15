#include <iostream>

#include "cmake-build-debug/hypocycloid.cpp"
#include "cmake-build-debug/hypocycloid.h"

int main()
{
    Prog2::Hypocycloid initial(4, 1, -1);
    int answer = 1, flag;
    double R, r, d;
    double area;
    while(answer){
        std::cout << "The radius of circle that limiting hypocycloid : " << initial.limited_Radius() << std::endl;
        std::cout << "The curvature radius of hypocycloid : " << initial.curvature_Radius() << std::endl;
        std::cout << "Enter the distance from the center of the generative circle to the border of guide circle : " << std::endl;
        std::cin >> d;
        std::cout << "The type of hypocycloid : ";
        initial.check_Type(d);
        std::cout << "Enter angle in degrees for calculate coordinates and area :" << std::endl;
        int angle;
        Prog2::Point coord;
        std::cin >> angle;
        double angleRadian = 3.14 * angle / 180;
        try{
            coord = initial.Coordinates(angleRadian);
            area = initial.area(angleRadian);
            std::cout << "Coordinates : ";
            std::cout << "Coord_X = " << coord.x << " ; " << "Coord_Y = " << coord.y << std::endl;
            std::cout << "Area : " << area << std::endl;
        }
        catch(std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        std::cin.clear();
        std::cout << "Enter new R, r and sign to continue:" << std::endl;
        std::cin >> R >> r >> flag;
        if(std::cin.good()){
            try{
                initial.setR(R);
            }
            catch (std::exception &ex){
                std::cout << ex.what() << std::endl;
            }
            try{
                initial.setr(r);
            }
            catch (std::exception &ex){
                std::cout << ex.what() << std::endl;
            }
            try{
                initial.setH(flag);
            }
            catch (std::exception &ex){
                std::cout << ex.what() << std::endl;
            }
        }
        else
            answer = 0;
    }
    return 0;
}

