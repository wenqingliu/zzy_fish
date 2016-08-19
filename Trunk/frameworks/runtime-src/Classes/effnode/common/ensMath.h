//
//  ensMath.h
//  HelloCpp
//
//  Created by yang chao (wantnon) on 14-6-14.
//
//

#ifndef __HelloCpp__ensMath__
#define __HelloCpp__ensMath__

#include <iostream>
using namespace std;
#include "cocos2d.h"
using namespace cocos2d;
#include "ensDefine.h"
#include "ensSimpleClasses.h"
namespace_ens_begin

float random01();
float randomInRange(float min,float max);
bool catchProbability(float p);
bool isPointEqual(const Vec2&point1,const Vec2&point2,float eps);
Vec2 rotateVector2(const Vec2&vec,float A);
Vec2 rotateVector2(const Vec2&vec,float cosA,float sinA);
float calculateAngleFromCosAndSin(float cosA,float sinA);
Vec2 calculateCosASinAOfVec1ToVec2(const Vec2&vec1,const Vec2&vec2);
float nPow(float a,int n);
float pow2(float x);
float PNDisPointToLine(const Vec2&point,const Vec2&start,const Vec2&end);
bool isPointEqual(const Vec2&p1,const Vec2&p2);
Vec2 getIntersectPointOfTwoLine(const Vec2&p1,const Vec2&dir1, const Vec2&p2,const Vec2&dir2);
float calculateIncircleR2(const Vec2&v0,const Vec2&v1,const Vec2&v2);
vector<Vec2> makeTriangleSmaller(Vec2 v0,Vec2 v1,Vec2 v2,float d);
Vec2 getRightNormal(const Vec2&dir);
Vec2 getRightVector(const Vec2&p1,const Vec2&p2);
float calculateTriangleArea(const Vec2&v0,const Vec2&v1,const Vec2&v2);
vector<Vec2> calculateTangentPointsOfPointToCircle(const Vec2 &center, float r,const Vec2 &point);
Vec2 M4TransV2(const Mat4&mat,const Vec2&v);
namespace_ens_end

#endif /* defined(__HelloCpp__ensMath__) */
