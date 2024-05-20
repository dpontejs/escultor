# Classe Sculptor

A classe Sculptor foi criada com o objetivo de desenhar estruturas pre-definidas usando uma matriz 3D de Voxels, um struct que tem propriedades de cor e inclusao.

O projeto foi passado com o struct Voxel definido e com os metodos pre-definidos, apenas com seus nomes e parametros.

A visualizacao das estruturas foi feita pelo software geoview, que consegue ler os arquivos .off gerados pelo metodo writeOFF().

Apos a conclusao, a classe foi documentada utilizando o software doxygen.

## Documentacao

Para visualizar sua documentacao, executar o doxygen dentro do repositorio, as configuracoes estao definidas na Doxyfile.

## Programa de testes

O main.cpp funciona com um menu, em que a primeira opcao e criar quatro estruturas difentes, um retangulo e um voxel no arquivo box.off, uma esfera no arquivo sphere.off e uma elipsoide no arquivo ellipsoid.off. Na segunda opcao, o programa ira apagar dos arquivos todas as estruturas, e na terceira opcao, a execucao sera encerrada. Assim, demonstrando o funcionamento de todos os metodos criados.