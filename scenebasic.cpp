#include "scenebasic.h"

#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <fstream>
using std::ifstream;

#include <sstream>
using std::ostringstream;

#include "glutils.h"
#include "C:/glm/glm/gtc/matrix_transform.hpp"
#include "C:/glm/glm/gtx/transform2.hpp"

const float PI = 4.0*atan(1.0);

SceneBasic::SceneBasic()
{
    readData("shader/scenebasic2.dat");
}

void SceneBasic::readData(const char* fname)
{
    ifstream ifs(fname);

    if (!ifs) {
        std::cout << "data file not found\n";
        exit(1);
    } else {
        for (int i=0; i<108; i++) ifs >> positionData[i];
        for (int i=0; i<108; i++) ifs >> colorData[i];
    }
}


void SceneBasic::CreateVBO()
{
    // Creates VBO for the Cube

    // Create and populate the buffer objects
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);

    GLuint positionBufferHandle = vboHandles[0];
    GLuint colorBufferHandle = vboHandles[1];

    // bind positionBufferHandle to GL_ARRAY_BUFFER buffer object target
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    // creates and initializes GL_ARRAY_BUFFER buffer object's data store
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), positionData, GL_STATIC_DRAW);

     // bind colorBufferHandle to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), colorData, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    glGenVertexArrays( 1, &vaoHandle );
    // bind the vertex array object
    glBindVertexArray(vaoHandle);

    /* enables the generic vertex attribute array
       the values in the generic vertex attribute array will be accessed
       and used for rendering when calls are made to vertex array commands
       such as glDrawArrays */
    glEnableVertexAttribArray(0);  // Vertex position
    glEnableVertexAttribArray(1);  // Vertex color

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);

    /* define an array of generic vertex attribute data
       specifies the location and data format of the array of generic
       vertex attributes at index 0 to use when rendering */
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void SceneBasic::CreateVBO2()
{
    // Creates VBO for the line

    // Create and populate the buffer objects
    //vboHandlesLin[2];
    glGenBuffers(2, vboHandlesLine);

    GLuint positionBufferHandleLine = vboHandlesLine[0];
    GLuint colorBufferHandleLine = vboHandlesLine[1];

    // bind positionBufferHandle to GL_ARRAY_BUFFER buffer object target
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandleLine);
    // creates and initializes GL_ARRAY_BUFFER buffer object's data store
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positionDataForLine, GL_STATIC_DRAW);

     // bind colorBufferHandle to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandleLine);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), colorDataForLine, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    glGenVertexArrays( 1, &vaoHandleLine );
    // bind the vertex array object
    glBindVertexArray(vaoHandleLine);

    /* enables the generic vertex attribute array
       the values in the generic vertex attribute array will be accessed
       and used for rendering when calls are made to vertex array commands
       such as glDrawArrays */
    glEnableVertexAttribArray(0);  // Vertex position
    glEnableVertexAttribArray(1);  // Vertex color

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandleLine);

    /* define an array of generic vertex attribute data
       specifies the location and data format of the array of generic
       vertex attributes at index 0 to use when rendering */
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandleLine);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void SceneBasic::initScene()
{
    //////////////////////////////////////////////////////
    /////////// Vertex shader //////////////////////////
    //////////////////////////////////////////////////////

    /* The OpenGL Extension Wrangler Library (GLEW) is a cross-platform
     open-source C/C++ extension loading library. GLEW provides efficient
     run-time mechanisms for determining which OpenGL extensions are supported
     on the target platform.

     if you link with some function - it must exist on target platform,
     or your program wouldn't launch. GLEW handles that - you're not linking
     with GL functions directly, but instead getting function pointers after
     initialization phase. It allows you to check at runtime which extensions
     are present and which functions may be used.

     GLEW obtains information on the supported extensions from the graphics driver.
     Experimental or pre-release drivers, however, might not report every available
     extension through the standard mechanism, in which case GLEW will report
     it unsupported. To circumvent this situation, the glewExperimental global switch
     can be turned on by setting it to GL_TRUE before calling glewInit(), which ensures
     that all extensions with valid entry points will be exposed. */

    glewExperimental = GL_TRUE;
    glewInit();

	// Create the vertex shader object
    GLuint vertShader = prog.createShader(GL_VERTEX_SHADER);

    // Check status
    if( 0 == vertShader)
    {
		fprintf(stderr, "Error creating vertex shader.\n");
		exit(1);
    }

	// load the shader from the file
    prog.load_shader(vertShader,"shader/basic.vert");

	// compile the shader
    prog.compileShader(vertShader);

    // Check compilation status
    prog.checkCompileStatus(vertShader);

  
    //////////////////////////////////////////////////////
    /////////// Fragment shader //////////////////////////
    //////////////////////////////////////////////////////


   // Create the fragment shader object
    GLuint fragShader = prog.createShader(GL_FRAGMENT_SHADER);

    // Check status
    if( 0 == fragShader)
    {
		fprintf(stderr, "Error creating fragment shader.\n");
		exit(1);
    }

	// load the shader from the file
    prog.load_shader(fragShader,"shader/basic.frag");

	// compile the shader
    prog.compileShader(fragShader);

    // Check compilation status
    prog.checkCompileStatus(fragShader);

    // Create the program object
    if (!prog.createObject()) printf("error\n");

    // attach shaders to program object
    prog.attachShader(vertShader);
    prog.attachShader(fragShader);

    // Bind index 0 to the shader input variable "VertexPosition"
    prog.bindAttribLocation(0, "VertexPosition");
    // Bind index 1 to the shader input variable "VertexColor"
    prog.bindAttribLocation(1, "VertexColor");

    // link the program
    prog.link();

    // create and populate the vertex buffer opbject
    CreateVBO();
    CreateVBO2();

    prog.printActiveUniforms();

    model = mat4(1.0f);
    model2 = mat4(1.0f);

    view = glm::lookAt(vec3(0.0f,0.0f,2.0f), vec3(0.0f,0.0f,0.0f), vec3(0.0f,1.0f,0.0f));
    projection = mat4(1.0f);

    //setLine(,0,[1,1,1]);

    glClearColor( 0.3, 0.3, 0.3, 1.0 );
    glEnable(GL_DEPTH_TEST);
}


void SceneBasic::update()
{
    //updates the view
    render();
}

void SceneBasic::setLine(float b[], float u, float d[])
{
    // Defines the data for the line using b+ud
    positionDataForLine[0] = b[0] - u * d[0];
    positionDataForLine[1] = b[1] - u * d[1];
    positionDataForLine[2] = b[2] - u * d[2];
    positionDataForLine[3] = b[0] + u * d[0];
    positionDataForLine[4] = b[1] + u * d[1];
    positionDataForLine[5] = b[2] + u * d[2];
}

void SceneBasic::setLineColor()
{
    // Sets the colour of the line to white
    colorDataForLine[0] = 1;
    colorDataForLine[1] = 1;
    colorDataForLine[2] = 1;
    colorDataForLine[3] = 1;
    colorDataForLine[4] = 1;
    colorDataForLine[5] = 1;
}

void SceneBasic::setMatrices(string matrixType)
{
    // Sets the matrices depending on the type

    mat4 mv;

    // Cube Matrices
    if(matrixType == "cubeMatrix")
    {
        mv = view * model;
        glBindBuffer(GL_ARRAY_BUFFER, vboHandles[0]);
        glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), positionData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, vboHandles[1]);
        glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), colorData, GL_STATIC_DRAW);
        glBindVertexArray(vaoHandle);
    }
    else
    // Line Matrices
    {
        mv = view * model;
        glBindBuffer(GL_ARRAY_BUFFER, vboHandlesLine[0]);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positionDataForLine, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, vboHandlesLine[1]);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), colorDataForLine, GL_STATIC_DRAW);
        glBindVertexArray(vaoHandleLine);
    }

    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("MVP", projection * mv);
}
void SceneBasic::render()
{
    /* sets the bitplane area of the window to values previously
       selected by glClear. GL_COLOR_BUFFER_BIT indicates the buffers
       currently enabled for color writing. */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //CUBE RENDER
    setMatrices("cubeMatrix");
    glDrawArrays(GL_TRIANGLES, 0, 36 );

    //LINE RENDER
    //Set the Matrices for the line
    setMatrices("lineMatrix");
    glDrawArrays(GL_LINES, 0, 2);
}

void SceneBasic::resize(int w, int h)
{
    glViewport(0,0,w,h);
    width = w;
    height = h;
    projection = glm::perspective(2*PI/8.0f, (float)w/h, 0.3f, 10.0f);
}

void SceneBasic::defaultPosition()
{
    // Restores the cube to the default view of glm::lookAt(vec3(0.0f,0.0f,2.0f), vec3(0.0f,0.0f,0.0f), vec3(0.0f,1.0f,0.0f))
    view = glm::lookAt(vec3(0.0f,0.0f,2.0f), vec3(0.0f,0.0f,0.0f), vec3(0.0f,1.0f,0.0f));
    mat4 mv = view * model;
    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("MVP", projection * mv);
    model = mat4(1.0f);
}

void SceneBasic::viewPosition(float A[], float B[])
{
    // Changes the cube view to the spin box values provided
    view = glm::lookAt(glm::vec3(A[0], A[1], A[2]), glm::vec3(B[0], B[1], B[2]), vec3(0.0f,1.0f,0.0f));
}

void SceneBasic::rotateView(float b[], float u, float d[], float viewangle)
{
    // Rotates the view around line b+ud at an angle viewangle
    model *= glm::translate (mat4(1.0f), glm::vec3(b[0], b[1], b[2]));
    model *= glm::rotate (mat4(1.0f), viewangle*PI/180, glm::vec3(d[0], d[1], d[2]));
    model *= glm::translate (mat4(1.0f), -(glm::vec3(b[0], b[1],b[2])));
}

void SceneBasic::printActiveUniforms(GLuint programHandle)
{

    GLint nUniforms, size, location, maxLen;
    GLchar * name;
    GLsizei written;
    GLenum type;

    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORMS, &nUniforms);

    name = (GLchar *) malloc( maxLen );

    printf(" Location | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nUniforms; ++i ) {
        glGetActiveUniform( programHandle, i, maxLen, &written, &size, &type, name );
        location = glGetUniformLocation(programHandle, name);
        printf(" %-8d | %s\n",location, name);
    }

    free(name);
}

void SceneBasic::printActiveAttribs(GLuint programHandle)
{

    GLint written, size, location, maxLength, nAttribs;
    GLenum type;
    GLchar * name;

    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTES, &nAttribs);

    name = (GLchar *) malloc( maxLength );

    printf(" Index | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nAttribs; i++ ) {
        glGetActiveAttrib( programHandle, i, maxLength, &written, &size, &type, name );
        location = glGetAttribLocation(programHandle, name);
        printf(" %-5d | %s\n",location, name);
    }

    free(name);
}
