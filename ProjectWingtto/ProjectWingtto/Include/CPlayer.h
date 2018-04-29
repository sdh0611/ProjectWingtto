#pragma once

#include "../pch.h"
#include "./MoveObject.h"


class CPlayer : public MoveObject
{
public:
	CPlayer(Types::POINT point = { 0, 0 }, Types::SIZE size = { 100, 100 });
	//CPlayer( float health, Types::ObjectState state);
	virtual ~CPlayer();


public:
	//virtual bool Init(const HDC& hDC) override;
	virtual bool Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render(float deltaTime, const HDC& hDC) override;
	

public:




private:
	void Move(float deltaTime);
	//bool DectectCollsion(float deltaTime, const HDC& hDC);


private:
	bool						m_bIsDead;
	float						m_fHealth;
	RECT						m_WndSize;


//ÄÄÆ÷³ÍÆ®µé
private:
	class InputComponent* 	m_pInput;
	class Physics*				m_pPhysics;


};
