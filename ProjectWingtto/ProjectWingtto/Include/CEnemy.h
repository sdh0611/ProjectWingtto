#pragma once

#include "../pch.h"
#include "./MoveObject.h"


class CEnemy : public MoveObject{

public:
	CEnemy(Types::POINT point = { 400, 50 }, Types::SIZE size = { 100, 100 });
	virtual ~CEnemy();


public:
	virtual bool Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render(float deltaTime, const HDC& hDC) override;


private:
	bool						m_bIsDead;
	float						m_fHealth;
	RECT						m_WndSize;


private:
	class Physics*				m_pPhysics;




};