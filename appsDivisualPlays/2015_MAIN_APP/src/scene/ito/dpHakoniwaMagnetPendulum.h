//
//  dpHakoniwaMagnetPendulum.h
//  example-ramMotionExtractor
//
//  Created by itotaka on 1/16/15.
//
//

#ifndef __example_ramMotionExtractor__dpHakoniwaMagnetPendulum__
#define __example_ramMotionExtractor__dpHakoniwaMagnetPendulum__

#define NMAGNETS 6

#include "ramMain.h"
#include "ramMotionExtractor.h"
#include "dpConstants.h"
#include "twistFinder.h"

class dpHakoniwaMagnetPendulum : public ramBaseScene {
public:
    
    string getName() const {return "dpHMagPendulum";};
    
    void setupControlPanel();
    void setup();
    void sendOsc();
    void update();
    void draw();
    void drawActor(const ramActor& actor);
    void example_drawDump();
    void guiEvent(ofxUIEventArgs &e);
    
    void drawGraph(vector<ofVec3f> & vec, ofColor & drawColor, int elementNum);
    void debugDraw();

    
private:
    
    //    ofPlanePrimitive mPlane;
    //    string mFrag;
    //    string mVert;
    //    ofShader mDisplace;
    
    
    float distanceThreshold;
    bool bOn[NMAGNETS];
    bool bInversed[NMAGNETS];
    bool bTestMode = true;
    int mode;
    bool bHideNodeView;
    
    vector <ofVec3f> vecRed;
    vector <ofVec3f> vecGreen;
    vector <ofVec3f> vecBlue;
    
    ramMotionExtractor	mMotionExtractor;
    ofxOscSender mSenderOnOff;
    ofxOscSender mSenderInverse;
    
    twistFinder twFinder;
    
    //    float mVelocitySpeedScale = 10.0;
};


#endif /* defined(__example_ramMotionExtractor__dpHakoniwaMagnetPendulum__) */
