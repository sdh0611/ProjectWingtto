#pragma once

#include "../pch.h"
#include "./Scene.h"

//GameObject���� �⺻ Ŭ���� ���漱��.
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
	//shared_ptr�� �������� ���߿� ����(18.04.26)
	CPlayer*							m_pPlayer;



};
