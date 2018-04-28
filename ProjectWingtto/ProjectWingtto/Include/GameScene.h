#pragma once

#include "../pch.h"
#include "./Scene.h"

//GameObject들의 기본 클래스 전방선언.
class Object;
class CPlayer;

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();


public:
	virtual bool Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render(float deltaTime, const HDC& hDC) override;
	
	
public:
	bool AddObject(const std::string& layerTag, Types::ObjectType);
	bool DetectCollsion();


private:
	//std::list<Object*>				m_lGameObject;
	//std::list<Object*>::iterator		m_lIt;
	//shared_ptr로 만들지는 나중에 생각(18.04.26)
	CPlayer*							m_pPlayer;



};
