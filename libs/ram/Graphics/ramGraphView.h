#pragma once

#include "ofMain.h"

class ramGraphView
{
public:
	
	ramGraphView() : num_buffer(400), rect(100, 100, 300, 100) {}
	
	void setupRecord(const string& key, float min = 0, float max = 1)
	{
		records[key] = Record();
		records[key].buffer.resize(num_buffer);
		records[key].min = min;
		records[key].max = max;
	}

	bool hasRecord(const string& key)
	{
		return records.find(key) != records.end();
	}
	
	void setNumBuffer(size_t num_buffer)
	{
		assert(num_buffer > 1);
		
		this->num_buffer = num_buffer;
		
		MapType::iterator it = records.begin();
		while (it != records.end())
		{
			Record &v = it->second;
			v.buffer.resize(num_buffer);
			it++;
		}
	}
	
	void setColor(const string& key, ofColor color)
	{
		if (!hasRecord(key)) return;
		
		Record &o = records[key];
		o.has_color = true;
		o.color = color;
	}
	
	void setMinMax(const string& key, float min, float max)
	{
		if (!hasRecord(key)) return;
		
		Record &o = records[key];
		o.min = min;
		o.max = max;
	}
	
	void update(const string& key, float v)
	{
		if (!hasRecord(key)) return;
		
		Record &o = records[key];
		o.buffer.push_front(v);
		
		if (o.buffer.size() > num_buffer)
			o.buffer.pop_back();
	}
	
	void draw()
	{
		ofPushStyle();
		
		ofNoFill();
		
		ofSetColor(127, 127);
		ofRect(rect);
		
		ofPushMatrix();
		ofTranslate(rect.x, rect.y);
		
		float color_offset = 0;
		
		float x_offset = 0.0;
		
		MapType::iterator it = records.begin();
		while (it != records.end())
		{
			Record &o = it->second;
			BufferType &v = o.buffer;
			
			float c = fmod(color_offset, 1);
			
			ofColor color;
			
			if (o.has_color)
			{
				color = o.color;
			}
			else
			{
				color = ofColor::fromHsb(c * 255, 255, 255, 127);
			}
			
			ofSetColor(color, 127);
			
			{
				int index = 0;
				float xx = ofMap(index, 0, num_buffer, 0, rect.width) + rect.width * x_offset;
				float yy = ofMap(v[index], o.min, o.max, rect.height, 0);
				
				ofPushStyle();
				ofSetColor(color, 64);
				ofLine(0, yy, rect.width, yy);
				ofPopStyle();
				
				ofDrawBitmapString(it->first + ":" + ofToString(o.buffer[0]), xx, yy);
			}
			
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < v.size(); i++)
			{
				float x = ofMap(i, 0, num_buffer, 0, rect.width);
				float y = ofMap(v[i], o.min, o.max, rect.height, 0);
				glVertex2f(x, y);
			}
			glEnd();
			
			color_offset += 0.3;
			
			x_offset += 0.05;
			x_offset = fmod(x_offset, 1);
			
			it++;
		}
		ofPopMatrix();
		
		ofPopStyle();
	}
	
	void setRect(ofRectangle rect)
	{
		this->rect = rect;
	}
	
private:
	
	int num_buffer;
	
	ofRectangle rect;
	
	typedef deque<float> BufferType;
	
	struct Record
	{
		float min, max;
		BufferType buffer;
		
		bool has_color;
		ofColor color;
		
		Record() : min(0), max(1), has_color(false) {}
	};
	
	typedef map<string, Record> MapType;
	MapType records;
	
};