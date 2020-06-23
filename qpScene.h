#ifndef QP_SCENE_H
#define QP_SCENE_H

#include <FastLED.h>
#include <qpLinkedList.h>
#include <qpLightStrand.h>
#include <qpLayer.h>

class qpScene {

  private:

    qpLightStrand *lightStrand;

    qpLinkedList <qpLayer> layers;

    qpLayer *lastReferencedLayer;

  public:

    qpScene(qpLightStrand *lightStrand);

    void attachToStrand(qpLightStrand *lightStrand);

    qpLayer &layer(int index);
    qpLayer &addLayer();
    qpLayer &sameLayer() { return *this->lastReferencedLayer; }

    qpPattern &addPattern(qpPattern *pattern);

    qpPattern &operator()(int layerIndex); // returns pattern 0 at the specified layer


    void draw(CRGB *targetLeds, int numLeds);
};

#endif
