#ifndef VOXEL_H
#define VOXEL_H

//! Struct Voxel
/*!
  Struct que contem as caracteristicas da estrutura Voxel.
*/

struct Voxel {
    //! Parametro de cor
    /*! Define o vermelho. */
    float r,
    //! Parametro de cor
    /*! Define o verde. */
    g,
    //! Parametro de cor
    /*! Define o azul. */
    b;
    //! Parametro de transparencia
    /*! Define o quao transparente e o desenho. */
    float a;
    //! Parametro de inclusao
    /*! Define se o voxel estara ou nao presente no desenho. */
    bool show;
};

#endif // VOXEL_H
