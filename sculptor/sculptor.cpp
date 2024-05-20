#include "sculptor.h"
#include "voxel.h"
#include <iostream>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;

    if (nx > 0 || ny > 0 || nz > 0) {

        v = new Voxel**[nx];

        for(int i = 0; i < nx; i++) {
            v[i] = new Voxel*[ny];
            for (int j = 0; j < ny; j++) {
                v[i][j] = new Voxel[nz];
            }
        }
    }
}

Sculptor::~Sculptor()
{
    if (v!= nullptr) {
        for (int i = 0;  i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                delete[] v[i][j];
            }
            delete[] v[i];
        }
        delete [] v;
    }

}

void Sculptor::setColor(float r, float g, float b, float a)
{
    this->r = r; this->g = g; this->b = b; this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                v[i][j][k].show = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                v[i][j][k].show = false;
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float r = radius*radius, e1, e2, e3, soma;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                e1 = (i-xcenter);
                e2 = (j-ycenter);
                e3 = (k-zcenter);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= r) {
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float r = radius*radius, e1, e2, e3, soma;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                e1 = (i-xcenter);
                e2 = (j-ycenter);
                e3 = (k-zcenter);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= r) {
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float e1, e2, e3, soma;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                e1 = ((i-xcenter)/rx);
                e2 = ((j-ycenter)/ry);
                e3 = ((k-zcenter)/rz);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= 1.0) {
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float e1, e2, e3, soma;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                e1 = ((i-xcenter)/rx);
                e2 = ((j-ycenter)/ry);
                e3 = ((k-zcenter)/rz);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= 1.0) {
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    ofs << "OFF\n";

    int nVoxels = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    nVoxels++;
                }
            }
        }
    }

    int nVertices = nVoxels * 8;
    int nFaces = nVoxels * 6;
    ofs << nVertices << " " << nFaces << " 0\n";

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    float x = i - 0.5, y = j - 0.5, z = k - 0.5;
                    ofs << x << " " << y << " " << z << "\n";
                    ofs << x + 1 << " " << y << " " << z << "\n";
                    ofs << x + 1 << " " << y + 1 << " " << z << "\n";
                    ofs << x << " " << y + 1 << " " << z << "\n";
                    ofs << x << " " << y << " " << z + 1 << "\n";
                    ofs << x + 1 << " " << y << " " << z + 1 << "\n";
                    ofs << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
                    ofs << x << " " << y + 1 << " " << z + 1 << "\n";
                }
            }
        }
    }

    int voxelIndex = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    int baseIndex = voxelIndex * 8;
                    ofs << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex + 4 << " " << baseIndex + 5 << " " << baseIndex + 6 << " " << baseIndex + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 5 << " " << baseIndex + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex << " " << baseIndex + 4 << " " << baseIndex + 7 << " " << baseIndex + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex + 3 << " " << baseIndex + 7 << " " << baseIndex + 6 << " " << baseIndex + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 6 << " " << baseIndex + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    voxelIndex++;
                }
            }
        }
    }

    ofs.close();
}
