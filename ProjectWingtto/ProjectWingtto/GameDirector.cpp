#include "pch.h"
#include "GameDirector.h"
#include "./Include/SceneManager.h"
#include "./Include/Scene.h"


GameDirector::GameDirector()
{
	
}


GameDirector::~GameDirector()
{

	SceneManager::Destroy();

}

bool GameDirector::Init() {

	if ( !SceneManager::GetInstance()->Init() )
		return false;

	SceneManager::GetInstance()->CreateScene(Types::ST_GAME);

	return true;
}

void GameDirector::Run(HDC hDC) {

	//SceneManager::GetInstance()->CreateScene(Types::ST_TITLE);
	SceneManager::GetInstance()->Render(hDC);

}

void GameDirector::Render() {

	SceneManager::GetInstance()->Render();

}


void GameDirector::Update() {

	SceneManager::GetInstance()->Update();

}