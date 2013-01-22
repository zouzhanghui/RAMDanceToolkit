#include "testApp.h"


#include "ofxAutoControlPanel.h"
ofxAutoControlPanel gui;


#include "Future.h"
vector<ramSceneBase*> scenes;
Future future;


#pragma mark - oF methods
//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	
	// enable ramBaseApp::setup, update, draw, exit
	ramEnableAllEvents();
	oscReceiver.setup(10000);
	
	//
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	// gui
	ofxControlPanel::setTextColor(0xffffff);
	ofxControlPanel::setBackgroundColor(0x000000);
	gui.setup();
	

	/*!
	 scenes setup
	 */
	scenes.push_back( future.getPtr() );
	
	gui.addPanel("All Scenes");
	gui.addToggle("Draw Actor", true);
	for (int i=0; i<scenes.size(); i++)
	{
		string key = scenes.at(i)->getSceneKey();
		gui.addToggle(key, false);
	}
	for (int i=0; i<scenes.size(); i++)
	{
		scenes.at(i)->setup();
		scenes.at(i)->refreshControlPanel(gui);
	}
}

//--------------------------------------------------------------
void testApp::update()
{
	oscReceiver.update();
	future.update();
	
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofBackgroundGradient( ofColor( 240 ), ofColor( 60 ) );
	ramCameraBegin();
	future.draw();
	ramCameraEnd();
}

//--------------------------------------------------------------
void testApp::drawActor(ramActor &actor)
{
	ramBasicActor(actor);
}

//--------------------------------------------------------------
void testApp::drawRigid(ramRigidBody &rigid)
{
	
}


#pragma mark - ram methods
//--------------------------------------------------------------
void testApp::drawFloor()
{
//	ramBasicFloor(600., 50.);
}



#pragma mark - oF Events
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch (key)
	{
//		case 'f': ofToggleFullscreen(); break;
//		case 'a': bActor ^= true; break;
//		case 's': bGhost ^= true; break;
//		case 'd': bParticle ^= true; break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}
