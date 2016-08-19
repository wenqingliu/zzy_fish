//
//  ensSimpleClasses.cpp
//  HelloCpp
//
//  Created by yang chao (wantnon) on 13-12-4.
//
//

#include "ensSimpleClasses.h"
#include "ensMath.h"
namespace_ens_begin
Cpolygon transPolygonByM4(const Cpolygon&polygon,const Mat4&mat){
    Cpolygon newPolygon=polygon;
    for(int i=0;i<(int)newPolygon.m_pointList.size();i++){
        Vec2&p=newPolygon.m_pointList[i];
        p=M4TransV2(mat, p);
    }
    return newPolygon;
}
Cpolygon makeRegularPolygon(int r,int n){
    vector<Vec2> pointList;
    float A=0;
    float dA=360.0/n;
    for(int i=0;i<n;i++){
        float x=r*cosf(A*M_PI/180);
        float y=r*sinf(A*M_PI/180);
        Vec2 point(x,y);
        pointList.push_back(point);
        A+=dA;
    }
    Cpolygon polygon;
    polygon.m_pointList=pointList;
    return polygon;
}
Cpolygon makeRectPolygon(float rx,float ry){
    Vec2 LU=Vec2(-rx,ry);
    Vec2 LD=Vec2(-rx,-ry);
    Vec2 RU=Vec2(rx,ry);
    Vec2 RD=Vec2(rx,-ry);
    Cpolygon polygon;
    polygon.m_pointList.push_back(LU);
    polygon.m_pointList.push_back(LD);
    polygon.m_pointList.push_back(RD);
    polygon.m_pointList.push_back(RU);
    return polygon;
}
namespace_ens_end