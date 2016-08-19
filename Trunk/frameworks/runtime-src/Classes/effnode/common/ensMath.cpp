//
//  ensMath.cpp
//  HelloCpp
//
//  Created by yang chao (wantnon) on 14-6-14.
//
//

#include "ensMath.h"
namespace_ens_begin
Vec2 M4TransV2(const Mat4&mat,const Vec2&v){
    Vec3 v3=Vec3(v.x,v.y,1);
    mat.transformPoint(&v3);
    return Vec2(v3.x,v3.y);
}
float pow2(float x){
    return x*x;
}
float random01(){
    return rand()*1.0/RAND_MAX;
}
float randomInRange(float min,float max){
    return min+random01()*(max-min);
}
Vec2 rotateVector2(const Vec2&vec,float A){//A is degree
    Vec2 rs;
    float A_radian=A*M_PI/180;
    float cosA=cosf(A_radian);
    float sinA=sinf(A_radian);
    rs.x=vec.x*cosA-vec.y*sinA;
    rs.y=vec.x*sinA+vec.y*cosA;
    return rs;
}
Vec2 rotateVector2(const Vec2&vec,float cosA,float sinA){
    Vec2 rs;
    rs.x=vec.x*cosA-vec.y*sinA;
    rs.y=vec.x*sinA+vec.y*cosA;
    return rs;
}
bool catchProbability(float p)
//the probability of return true is p
{
    float r=random01();
    if(r<p)return true;
    else return false;

}
float calculateAngleFromCosAndSin(float cosA,float sinA){
    ////float angle=acosf(cosA)/M_PI*180;
     float angle=acosf(MAX(-1,MIN(1,cosA)))/M_PI*180;//issue: http://git.oschina.net/wantnon2/EffectNodes-for-Cocos2dx/issues/2
    if(sinA>0){
        return angle;
    }else{
        return 360-angle;
    }

}
bool isPointEqual(const Vec2&point1,const Vec2&point2,float eps){
    if(fabsf(point1.x-point2.x)<eps&&fabsf(point1.y-point2.y)<eps){
        return true;
    }else{
        return false;
    }
}
void __cross(const float v1[3],const float v2[3], float rs[3])
{
    rs[0] = v1[1]*v2[2] - v1[2]*v2[1];
    rs[1] = v1[2]*v2[0] - v1[0]*v2[2];
    rs[2] = v1[0]*v2[1] - v1[1]*v2[0];
}
Vec2 calculateCosASinAOfVec1ToVec2(const Vec2&vec1,const Vec2&vec2)
//return {cos(vec1,vec2),sin(vec1,vec2)}
{
    float cosA=ccpDot(vec1, vec2)/(ccpLength(vec1)*ccpLength(vec2));
    float signalOfSinA;
    {
        float _vec1[3]={vec1.x,vec1.y,0};
        float _vec2[3]={vec2.x,vec2.y,0};
        float _rs[3];
        __cross(_vec1, _vec2, _rs);
        if (_rs[2]==0) {
            signalOfSinA=0;
        }else if(_rs[2]>0){
            signalOfSinA=1;
        }else{
            signalOfSinA=-1;
        }
    }
    float sinA=signalOfSinA*sqrtf(MAX(0,1-cosA*cosA));
    return Vec2(cosA,sinA);
}
struct __node{
    __node*foe;
    bool value;
};
float nPow(float a,int n){
    assert(!(a==0&&n==0));//0^0 nonsense
    if(n==0&&a!=0)return 1;
    if(a==0&&n!=0)return 0;
    if(n==1)return a;
    if(a==1)return 1;
    __node*tail=NULL;
    while(n!=1){
        __node*node=new __node();
        node->value=n%2;
        node->foe=tail;
        tail=node;
        n=n>>1;
    }//got a chain use tail as tail pointer
    float rs=a;
    while(tail){
        if(tail->value){
            rs=rs*rs*a;
        }else{
            rs=rs*rs;
        }
        __node*temp=tail;
        tail=tail->foe;
        delete temp;
    }
    return rs;

}

float PNDisPointToLine(const Vec2&point,const Vec2&start,const Vec2&end){
    //if point at left side of line(start,end), the PNDis is positive
    //if point at right side of line(start,end), the PNDis is negative
    //
    // start ----------end
    //        \ | PNDis
    //         \|
    //        point
    //
    Vec2 sp=point-start;
    Vec2 se=end-start;
    Vec2 se_e=ccpNormalize(se);
    float PNDis=ccpCross(sp, se_e);
    //now if point at left side of line, PNDis will be negative
    PNDis=-PNDis;
    //now if point at left side of line, PNDis will be positive
    return PNDis;


}
bool isPointEqual(const Vec2&p1,const Vec2&p2){
    if(p1.x==p2.x&&p1.y==p2.y)return true;
    else return false;
}
Vec2 getIntersectPointOfTwoLine(const Vec2&p1,const Vec2&dir1, const Vec2&p2,const Vec2&dir2){
    float D=-dir1.x*dir2.y+dir2.x*dir1.y;
    if(D==0)return Vec2(INFINITY,INFINITY);
    float Py=(p1.x*dir1.y*dir2.y-p1.y*dir1.x*dir2.y-p2.x*dir2.y*dir1.y+p2.y*dir2.x*dir1.y)/D;
    float Px;
    if(fabsf(dir2.y)>fabsf(dir1.y)){
        Px=dir2.x*(Py-p2.y)/dir2.y+p2.x;
    }else{
        Px=dir1.x*(Py-p1.y)/dir1.y+p1.x;
    }
    return Vec2(Px,Py);
}
float calculateIncircleR2(const Vec2&v0,const Vec2&v1,const Vec2&v2)
//calculate the square of triangle v0v1v2's Incircle's radius
{
    float Len_v0v1=ccpDistance(v0, v1);
    float Len_v1v2=ccpDistance(v1, v2);
    float Len_v2v0=ccpDistance(v2, v0);
    float a=Len_v0v1;
    float b=Len_v1v2;
    float c=Len_v2v0;
    float temp=2*(a+b+c);
    float r2=((a+b+c)*(b+c-a)*(a+c-b)*(a+b-c))/(temp*temp);//square of triangle v0v1v2's Incircle's radius
    return MAX(0,r2);//r2 should be no negative
}
vector<Vec2> makeTriangleSmaller(Vec2 v0,Vec2 v1,Vec2 v2,float d)
//return a smaller triangle p0p1p2
//satisfy:
//distance between edge v0v1 and p0p1 is d
//distance between edge v1v2 and p1p2 is d
//distance between edge v2v0 and p2p0 is d
//if the p0p1p2 shrink to a point, the return vector just contain one element (the point),
//otherwise the return vector will contain three element (p0,p1,p2)
{
    float incircleR2=calculateIncircleR2(v0, v1, v2);
    bool shrinkToPoint=(d*d>=incircleR2);
    if(shrinkToPoint){//if shrink to a point, then use incircleR as d
        d=sqrtf(incircleR2);
    }
    //base on geometry, p0 should on the angular bisector of angle v1v0v2, and the length of v0p0 is d/sin(0.5*angle_v1v0v2)
    //simlar conclusion for v1 and v2
    vector<Vec2> plist;
    Vec2 vlist[3]={v0,v1,v2};
    for(int i=0;i<3;i++){
        //calculate p[i] (cur p)
        Vec2 v=vlist[i];//cur v
        Vec2 vn=vlist[(i+1)%3];//next v
        Vec2 vf=vlist[(i-1+3)%3];//foe v
        Vec2 dir_vvn=ccpNormalize(vn-v);
        Vec2 dir_vvf=ccpNormalize(vf-v);
        Vec2 dir_vp=ccpNormalize(dir_vvn+dir_vvf);//direction of vp
        float cos_vnvvf=ccpDot(dir_vvn, dir_vvf);
        float sin_halfvnvvf=sqrtf(MAX(0,0.5*(1-cos_vnvvf)));//sin(0.5*angle_vnvvf)
        float len_vp=d/sin_halfvnvvf;//length of vp
        Vec2 vp=ccpMult(dir_vp, len_vp);
        Vec2 p=v+vp;//got p
        plist.push_back(p);
        if(shrinkToPoint)break;//if shrink to a point, now we got the point, no need more calculation
    }
    return plist;
}
Vec2 getRightNormal(const Vec2&dir) {//right side normal or outer normal
    Vec2 normal(dir.y,-dir.x);
    return normal;
}

Vec2 getRightVector(const Vec2&p1,const Vec2&p2){//right side vector or outer vector, but not guarantee to be normalized
    Vec2 vec=p2-p1;
    Vec2 rightVec(vec.y,-vec.x);
    return rightVec;

}
float calculateTriangleArea(const Vec2&v0,const Vec2&v1,const Vec2&v2)
//calculate area of triangle v0v1v2
//ref to: http://zhidao.baidu.com/link?url=zQUSnOMZK_hGlSDVy5kWXDRraAbedjUoNtav83p1fdmoCJvaSADSc5bJ1Wr0kmzFFewuDevYQ2fFOqX1vIJaja
{
    const float x1=v0.x;
    const float y1=v0.y;
    const float x2=v1.x;
    const float y2=v1.y;
    const float x3=v2.x;
    const float y3=v2.y;
    float Area=0.5*fabsf(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
    return Area;
}
vector<Vec2> calculateTangentPointsOfPointToCircle(const Vec2 &center, float r,const Vec2 &point)
//the first return point is left tangent point
//the second return point is right tangent point
//if point in circle, then return empty vector
{
    Vec2 tangentPointLeft,tangentPointRight;
    Vec2 PC=center-point;
    float disPC=ccpLength(PC);
    if(disPC<r){//point in circle
        vector<Vec2> rs;
        return rs;
    }
    if(disPC==r){//point on circle
        vector<Vec2> rs;
        rs.push_back(point);
        rs.push_back(point);
        return rs;
    }
    if(disPC==0){
        vector<Vec2> rs;
        rs.push_back(tangentPointLeft);
        rs.push_back(tangentPointRight);
        return rs;
    }

    float sinA=r/disPC;
    float cosA=sqrtf(1-sinA*sinA);

    float disPT=disPC*cosA;

    Vec2 dirPC=Vec2(PC.x/disPC,PC.y/disPC);

    Vec2 dirPTLeft=rotateVector2(dirPC, cosA, sinA);
    Vec2 dirPTRight=rotateVector2(dirPC, cosA, -sinA);

    tangentPointLeft=point+ccpMult(dirPTLeft, disPT);

    tangentPointRight=point+ccpMult(dirPTRight, disPT);
    vector<Vec2> rs;
    rs.push_back(tangentPointLeft);
    rs.push_back(tangentPointRight);
    return rs;

}

namespace_ens_end
