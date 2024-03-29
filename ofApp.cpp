﻿#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto width = 60;
	auto color_flag = true;
	auto param_start = ofGetFrameNum() * 0.5;

	for (auto len = 100; len < ofGetWidth(); len += width) {

		param_start += 10;
		for (auto param = param_start; param < param_start + 100; param += 20) {

			vector<glm::vec2> in;
			vector<glm::vec2> out;
			for (auto tmp_param = param; tmp_param <= param + 10; tmp_param++) {

				in.push_back(this->make_point(len, tmp_param));
				out.push_back(this->make_point(len + width, tmp_param));
			}

			reverse(out.begin(), out.end());

			ofFill();
			ofSetColor(color_flag ? 39 : 139);

			ofBeginShape();
			ofVertices(in);
			ofVertices(out);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(color_flag ? 139 : 39);

			ofBeginShape();
			ofVertices(in);
			ofVertices(out);
			ofEndShape(true);

			color_flag = !color_flag;
		}
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}