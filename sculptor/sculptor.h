#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <cmath>
#include <fstream>

//! Classe Sculptor
/*!
 * Classe que gera diferentes estruturas com o uso de Voxels, um struct que possui caracteristicas de cor, transparencia e inclusao.
    A classe usa diferentes métodos para inserir objetos, como um unico voxel, um retangulo, uma esfera e uma elipsoide.
*/

class Sculptor
{
private:
    Voxel*** v;
    int nx, ny, nz;
    float r, g, b, a;
public:
    //! Construtor
    /*!
      O construtor realiza o processo de alocacao dinamica de uma matriz 3D de Voxels com as dimensoes especificadas.
      \param _nx dimensao no eixo x
      \param _ny dimensao no eixo y
      \param _nz dimensao no eixo z
    */

    Sculptor(int _nx, int _ny, int _nz);

    //! Destrutor
    /*!
      O destrutor realiza o processo de desalocacao dinamica de uma matriz 3D de Voxels.
    */

    ~Sculptor();

    //! Metodo em que a cor do desenho e definida
    /*!
      O construtor realiza o processo de alocacao dinamica de uma matriz 3D de Voxels com as dimensoes especificadas.
      \param r valor da cor vermelha
      \param g valor da cor verde
      \param b valor da cor azul
      \param a transparencia
    */

    void setColor(float r, float g, float b, float a);

    //! Metodo utilizado para colocar um voxel no desenho, no ponto especificado por x, y e z.
    /*!
      \param x dimensao no eixo x
      \param y dimensao no eixo y
      \param z dimensao no eixo z
    */

    void putVoxel(int x, int y, int z);

    //! Metodo utilizado para retirar um voxel no desenho, no ponto especificado por x, y, z.
    /*!
      \param x dimensao no eixo x
      \param y dimensao no eixo y
      \param z dimensao no eixo z
      \sa putVoxel()
    */

    void cutVoxel(int x, int y, int z);

    //! Metodo utilizado para colocar um retangulo no desenho, nos intervalos determinados.
    /*!
      \param x0 comeco do intervalo no eixo x
      \param x1 fim do intervalo no eixo x
      \param y0 comeco do intervalo no eixo y
      \param y1 fim do intervalo no eixo y
      \param z0 comeco do intervalo no eixo z
      \param z1 fim do intervalo no eixo z
      \sa putVoxel()
    */

    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

    //! Metodo utilizado para retirar um retangulo no desenho, nos intervalos determinados.
    /*!
      \param x0 comeco do intervalo no eixo x
      \param x1 fim do intervalo no eixo x
      \param y0 comeco do intervalo no eixo y
      \param y1 fim do intervalo no eixo y
      \param z0 comeco do intervalo no eixo z
      \param z1 fim do intervalo no eixo z
      \sa putBox()
    */

    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    //! Metodo utilizado para colocar uma esfera no desenho, satisfazendo a equacao da esfera
    /*!
      \param xcenter coordenada x do centro
      \param ycenter coordenada y do centro
      \param zcenter coordenada z do centro
      \param radius raio da esfera
    */

    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    //! Metodo utilizado para retirar uma esfera no desenho, satisfazendo a equacao da esfera
    /*!
      \param xcenter coordenada x do centro
      \param ycenter coordenada y do centro
      \param zcenter coordenada z do centro
      \param radius raio da esfera
      \sa putSphere()
    */

    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    //! Metodo utilizado para colocar uma elipsoide no desenho, satisfazendo a sua equacao
    /*!
      \param xcenter coordenada x do centro
      \param ycenter coordenada y do centro
      \param zcenter coordenada z do centro
      \param rx parametro x que define os eixos maior e menor
      \param ry parametro y que define os eixos maior e menor
      \param rz parametro z que define os eixos maior e menor
    */

    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    //! Metodo utilizado para retirar uma elipsoide no desenho, satisfazendo a sua equacao
    /*!
      \param xcenter coordenada x do centro
      \param ycenter coordenada y do centro
      \param zcenter coordenada z do centro
      \param rx parametro x que define os eixos maior e menor
      \param ry parametro y que define os eixos maior e menor
      \param rz parametro z que define os eixos maior e menor
      \sa putEllipsoid()
    */

    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    //! Metodo utilizado para criar um arquivo .off e escrever nele a representacao do desenho
    /*!
      \param filename nome do arquivo
    */

    void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
