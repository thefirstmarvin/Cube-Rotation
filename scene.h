#ifndef SCENE_H
#define SCENE_H

#include "C:/glm/glm/glm.hpp"

class Scene
{
public:
    /**
      Load textures, initialize shaders, etc.
      */
    virtual void initScene() = 0;

    /**
      This is called prior to every frame.  Use this
      to update your animation.
      */
    virtual void update() = 0;

    /**
      Draw your scene.
      */
    virtual void render() = 0;

    /**
      Called when screen is resized
      */
    virtual void resize(int, int) = 0;

    /**
      Called to restore the view to the default position
      */
    virtual void defaultPosition() = 0;

    /**
      View a specific location
      */
    virtual void viewPosition(float[], float[]) = 0;

    /**
      Called when screen is resized
      */
    virtual void setLine (float[], float, float[]) = 0;

    /**
      Set the line color to white
      */
    virtual void setLineColor() = 0;

    /**
      Called to rotate the model view
      */
    virtual void rotateView(float[], float, float[], float) = 0;
};

#endif // SCENE_H
