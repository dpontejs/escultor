#include <iostream>
#include <fstream>
#include "voxel.h"
#include "sculptor.h"

int main()
{
    Sculptor box(50, 50, 50), sphere(50, 50, 50), ellipsoid(50, 50, 50);
    int in = 0;

    while(in != 3) {
        std::cout << "Escolha uma opcao: " << std::endl;
        std::cout << "1 - Botar estruturas" << std::endl;
        std::cout << "2 - Apagar estruturas" << std::endl;
        std::cout << "3 - Sair" << std::endl;
        std::cout << "-------------------------------" << std::endl;

        std::cin >> in;

        if(in != 1 && in != 2 && in != 3) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "Escolha uma opcao valida" << std::endl;
            std::cout << "-------------------------------" << std::endl;
        }

        else if(in == 1) {
            box.setColor(0.0, 255.0, 0.0, 1.0); // Verde
            box.putBox(2, 4, 2, 4, 2, 4);
            box.putVoxel(0, 0, 0);

            sphere.setColor(0.0, 0.0, 255.0, 1.0); // Azul
            sphere.putSphere(5, 5, 5, 3);

            ellipsoid.setColor(255.0, 255.0, 0.0, 1.0); // Amarelo
            ellipsoid.putEllipsoid(7, 7, 7, 2, 1, 3);

            box.writeOFF("box.off");
            sphere.writeOFF("sphere.off");
            ellipsoid.writeOFF("ellipsoid.off");

            std::cout << "-------------------------------" << std::endl;
            std::cout << "Estruturas colocadas" << std::endl;
            std::cout << "-------------------------------" << std::endl;
        }

        else if (in == 2) {
            box.cutBox(2, 4, 2, 4, 2, 4);
            box.cutVoxel(0, 0, 0);
            sphere.cutSphere(5, 5, 5, 3);
            ellipsoid.cutEllipsoid(7, 7, 7, 2, 1, 3);

            box.writeOFF("box.off");
            sphere.writeOFF("sphere.off");
            ellipsoid.writeOFF("ellipsoid.off");

            std::cout << "-------------------------------" << std::endl;
            std::cout << "Estruturas apagadas" << std::endl;
            std::cout << "-------------------------------" << std::endl;
        }
    };

    return 0;
}
