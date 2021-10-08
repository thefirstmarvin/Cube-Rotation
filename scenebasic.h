#ifndef SCENEBASIC_H
#define SCENEBASIC_H

#include "scene.h"
#include "C:/glew-2.1.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
using glm::mat4;

class SceneBasic : public Scene
{
private:
    int width, height;
    GLuint vboHandles[2];
    GLuint vaoHandle;
    GLuint vaoHandleLine;
    GLuint vboHandlesLine[2];
    GLSLProgram prog;

    mat4 model;
    mat4 model2;
    mat4 view;
    mat4 projection;

    void SceneBasic::readData(const char* fname);

    void CreateVBO();
    void CreateVBO2();

    float positionData[108];
    float colorData[108];

    float positionDataForLine[6] = {0,0,0,1,0,0};
    float colorDataForLine[6] = {1,1,1,1,1,1};

public:
    SceneBasic();

    void setMatrices(string matrixType);
    void setLine(float b[], float u, float d[]);
    void setLineColor();
    void defaultPosition();
    void viewPosition(float[], float[]);
    void rotateView(float[], float, float[], float);

    void initScene();
    void render();
    void resize(int, int);
    void update();

    void printActiveUniforms(GLuint programHandle);
    void printActiveAttribs(GLuint programHandle);
};

#endif // SCENEBASIC_H
