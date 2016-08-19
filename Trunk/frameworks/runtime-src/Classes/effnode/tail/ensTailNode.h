

#ifndef HelloWorld_ensTailNode_h
#define HelloWorld_ensTailNode_h


#include<iostream>
using namespace std;
#include "cocos2d.h"
using namespace cocos2d;
#include "ensCommon.h"
namespace_ens_begin
namespace tail{
    enum eTurnType{
        eTurnType_right=0,
        eTurnType_left,
        eTurnType_straightForward,
        eTurnType_straightBack,
        eTurnType_unKnown,
    };
    class Cquad{
    public:
        Vec2 m_posLU;
        Vec2 m_posLD;
        Vec2 m_posRU;
        Vec2 m_posRD;
        Vec2 m_texCoordLU;
        Vec2 m_texCoordLD;
        Vec2 m_texCoordRU;
        Vec2 m_texCoordRD;
        //
        float m_opacity;//left side opacity. once m_opacity of each quad got, we can easily calculate m_opacityLU,LD,RU,RD for each quad
        //
        float m_opacityLU;
        float m_opacityLD;
        float m_opacityRU;
        float m_opacityRD;
        //
        bool m_isTriangle;
        Cquad(){
            m_opacity=INFINITY;
            m_opacityLU=INFINITY;
            m_opacityLD=INFINITY;
            m_opacityRU=INFINITY;
            m_opacityRD=INFINITY;
            m_isTriangle=false;
        }
        
        
    };
    class CfootPrint{
    public:
        Vec2 m_pos;
        float m_opacity;
        CfootPrint(){
            initMembers();
        }
        CfootPrint(const Vec2&pos,float opacity){
            initMembers();
            m_pos=pos;
            m_opacity=opacity;
        }
    protected:
        void initMembers(){
            m_opacity=1.0;
        }
    };
}
class CtailSprite : public Sprite
{
public:
	CtailSprite() {
        m_dt=0.1;
        m_indexVBO=NULL;
        m_program=NULL;
        m_opacityDamping=0.95;
        m_initialOpacity=10;
        m_minDis=14;//10;
        m_isDrawDebug=false;
    }
	virtual ~CtailSprite(){
        if(m_indexVBO)m_indexVBO->release();
        if(m_program)m_program->release();
    };
	bool init(const string&texFileName) ;
    void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);
    void onDraw(const Mat4 &transform, uint32_t flags);
    void onDrawDebug(const Mat4 &transform, uint32_t flags);
    void update(float dt);
    void clear(){m_footPrintList.clear();};
    bool getIsEmpty(){return m_footPrintList.empty();}
    void setMinDis(float value){m_minDis=value;}
    float getMinDis()const{return m_minDis;}
    void setIsDrawDebug(bool value){m_isDrawDebug=value;}
    bool getIsDrawDebug()const{return m_isDrawDebug;}
protected:
    Cmesh* generateMesh(const vector<tail::CfootPrint>&footPrintList);
protected:
    float m_opacityDamping;
    float m_dt;//how long to generate a point
    float m_disappearLengthPerSecond;
    vector<tail::CfootPrint> m_footPrintList;
    CindexVBO *m_indexVBO;
    CGLProgramWithUnifos*m_program;
    float m_initialOpacity;
    float m_minDis;//all segment on the path is longer than minDis(except for last segment)
    bool m_isDrawDebug;
    vector<vector<tail::Cquad> > m_allQuadMat;
    
    CustomCommand _customCommand;
    CustomCommand _customCommand_debug;

};
namespace_ens_end
#endif /* defined(__HelloCpp__ensTailNode__) */
