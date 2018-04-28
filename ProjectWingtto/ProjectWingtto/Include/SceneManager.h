#pragma once

#include "../pch.h"


class Sprite;
class Scene;

class SceneManager : public Singleton<SceneManager>{

	DECLARE_SINGLETON(SceneManager)
	
public:
	bool Init(Types::SceneType type, HDC& hDC);
	void Render(float deltaTime, const HDC& hDC);
	void Update(float deltaTime);
	void CheckSChangeScene();
	bool ChangeScene();
	void CreateScene(Types::SceneType type);
	void CreateNextScene(Types::SceneType type);


private:
	


private:
	bool						m_bIsChangeScene;
	Types::SceneType		m_SceneType;			//�ʿ�������� 
	Scene*					m_pScene;
	Scene*					m_pNextScene;

private:
	//ȭ�� ����� ���� DC��
	HDC  						m_hDC;

};